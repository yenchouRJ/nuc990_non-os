/*
 * FreeRTOS Kernel V10.0.0
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software. If you wish to use our Amazon
 * FreeRTOS name, please do so in a fair use way that does not cause confusion.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* A UDP echo client which is implemented with LwIP under FreeRTOS.
   The client send to 192.168.1.2:80, IP address is configured
   statically to 192.168.1.3. */

#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

/* Demo application includes. */
#include "partest.h"
#include "flash.h"
#include "flop.h"
#include "integer.h"
#include "PollQ.h"
#include "semtest.h"
#include "dynamic.h"
#include "BlockQ.h"
#include "blocktim.h"
#include "countsem.h"
#include "GenQTest.h"
#include "QueueSet.h"
#include "recmutex.h"
#include "death.h"

/* Hardware and starter kit includes. */
#include "NuMicro.h"

#include "lwip/netifapi.h"
#include "lwip/tcpip.h"
#include "netif/ethernetif.h"
#include "udp_echoclient-netconn.h"

/* Priorities for the demo application tasks. */
#define mainCHECK_TASK_PRIORITY            ( tskIDLE_PRIORITY + 3UL )

#define mainCHECK_TASK_STACK_SIZE            ( configMINIMAL_STACK_SIZE )

/* The time between cycles of the 'check' task. */
#define mainCHECK_DELAY                        ( ( portTickType ) 5000 / portTICK_RATE_MS )

/* The LED used by the check timer. */
#define mainCHECK_LED                         ( 3UL )

/* A block time of zero simply means "don't block". */
#define mainDONT_BLOCK                        ( 0UL )

/* The period after which the check timer will expire, in ms, provided no errors
have been reported by any of the standard demo tasks.  ms are converted to the
equivalent in ticks using the portTICK_RATE_MS constant. */
#define mainCHECK_TIMER_PERIOD_MS            ( 3000UL / portTICK_RATE_MS )

/* The period at which the check timer will expire, in ms, if an error has been
reported in one of the standard demo tasks.  ms are converted to the equivalent
in ticks using the portTICK_RATE_MS constant. */
#define mainERROR_CHECK_TIMER_PERIOD_MS     ( 200UL / portTICK_RATE_MS )

/* Set mainCREATE_SIMPLE_LED_FLASHER_DEMO_ONLY to 1 to create a simple demo.
Set mainCREATE_SIMPLE_LED_FLASHER_DEMO_ONLY to 0 to create a much more
comprehensive test application.  See the comments at the top of this file, and
the documentation page on the http://www.FreeRTOS.org web site for more
information. */
#define mainCREATE_SIMPLE_LED_FLASHER_DEMO_ONLY        0

#define ETHINTF    0

#if (LWIP_DHCP == 1)
#include "lwip/dhcp.h"
#endif
/*-----------------------------------------------------------*/

/*
 * Set up the hardware ready to run this demo.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/

unsigned char my_mac_addr0[6] = {0x00, 0x00, 0x00, 0x55, 0x66, 0x77};
unsigned char my_mac_addr1[6] = {0x00, 0x00, 0x00, 0xAA, 0xBB, 0xCC};
struct netif netif0;
struct netif netif1;
static void vUdpTask( void *pvParameters );
extern void vPortYieldProcessor(void);
extern void ETH0_TX_IRQHandler(void);
extern void ETH0_RX_IRQHandler(void);
/*-----------------------------------------------------------*/

int main(void)
{
    sysInstallExceptionHandler(SYS_SWI, vPortYieldProcessor);
    /* Configure the hardware ready to run the test. */
    prvSetupHardware();

    xTaskCreate( vUdpTask, "UdpTask", TCPIP_THREAD_STACKSIZE, NULL, mainCHECK_TASK_PRIORITY, NULL );

    printf("FreeRTOS is starting ...\n");

    /* Start the scheduler. */
    vTaskStartScheduler();

    /* If all is well, the scheduler will now be running, and the following line
    will never be reached.  If the following line does execute, then there was
    insufficient FreeRTOS heap memory available for the idle and/or timer tasks
    to be created.  See the memory management section on the FreeRTOS web site
    for more details. */
    for( ;; );
}
/*-----------------------------------------------------------*/

static void prvSetupHardware( void )
{
    SYS_UnlockReg();
    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);

    CLK_SetModuleClock(UART0_MODULE, CLK_DIV4_UART0SEL_HXT, CLK_DIV4_UART0(1));

    sysResetModule(UART0_RST);
    UART_Open(UART0, 115200);
    UART0->BAUD = 0x3000000E;  /* for palladium */

    /* GPF11, GPF12 */
    SET_UART0_RXD_PF11();
    SET_UART0_TXD_PF12();

    sysSetLocalInterrupt(ENABLE_IRQ);
}
/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
    /* vApplicationMallocFailedHook() will only be called if
    configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
    function that will get called if a call to pvPortMalloc() fails.
    pvPortMalloc() is called internally by the kernel whenever a task, queue,
    timer or semaphore is created.  It is also called by various parts of the
    demo application.  If heap_1.c or heap_2.c are used, then the size of the
    heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
    FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
    to query the size of free heap space that remains (although it does not
    provide information on how the remaining heap might be fragmented). */
    taskDISABLE_INTERRUPTS();
    for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
    /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
    to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
    task.  It is essential that code added to this hook function never attempts
    to block in any way (for example, call xQueueReceive() with a block time
    specified, or call vTaskDelay()).  If the application makes use of the
    vTaskDelete() API function (as this demo application does) then it is also
    important that vApplicationIdleHook() is permitted to return to its calling
    function, because it is the responsibility of the idle task to clean up
    memory allocated by the kernel to any task that has since been deleted. */
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle pxTask, signed char *pcTaskName )
{
    ( void ) pcTaskName;
    ( void ) pxTask;

    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected. */
    taskDISABLE_INTERRUPTS();
    for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
    /* This function will be called by each tick interrupt if
    configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
    added here, but the tick hook is called from an interrupt context, so
    code must not attempt to block, and only the interrupt safe FreeRTOS API
    functions can be used (those that end in FromISR()).  */
}

static void vUdpTask( void *pvParameters )
{
    ip_addr_t ipaddr;
    ip_addr_t netmask;
    ip_addr_t gw;
#if (ETHINTF == 0)
    struct netif *netif = &netif0;
    netif_init_fn ethernetif_init = ethernetif_init0;
#else
    struct netif *netif = &netif1;
    netif_init_fn ethernetif_init = ethernetif_init1;
#endif

    IP4_ADDR(&gw, 192,168,1,1);
    IP4_ADDR(&ipaddr, 192,168,1,3);
    IP4_ADDR(&netmask, 255,255,255,0);

    tcpip_init(NULL, NULL);

    netif_add(netif, &ipaddr, &netmask, &gw, NULL, ethernetif_init, tcpip_input);

    netif_set_default(netif);
    netif_set_up(netif);

    printf("[ UDP client ] \n");
    printf("IP address:      %s\n", ip4addr_ntoa(&(*netif).ip_addr));
    printf("Subnet mask:     %s\n", ip4addr_ntoa(&(*netif).netmask));
    printf("Default gateway: %s\n", ip4addr_ntoa(&(*netif).gw));
        
    udp_echoclient_netconn_init();

    vTaskSuspend( NULL );
}
