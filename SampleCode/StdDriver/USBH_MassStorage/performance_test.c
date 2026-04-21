
#include <stdio.h>
#include <string.h>

#include "NuMicro.h"
#include "sys.h"
#include "usbh_lib.h"
#include "ff.h"
#include "diskio.h"


#define TEST_BLOCK_LEN       (64*1024)

#define RAW_SECTOR_START     (0x800000)     /* start from 4 GB */
#define RAW_SECTOR_END       (0x900000)     /* end at 4.5 GB */
#define SECTOR_CNT           (TEST_BLOCK_LEN/512)

static __align(32) uint8_t  g_buff_pool[TEST_BLOCK_LEN];
static uint8_t  *g_buff;

FRESULT usbh_umass_performance()
{
	int        t0, sector_no, file_pos;
	uint32_t   xfer_cnt;
	FIL        file1;
	UINT       cnt;
	FRESULT    res;

	g_buff = (uint8_t *)((uint32_t)g_buff_pool | 0x80000000);

	/*-------------------------------------------------------------------*/
	/*  Raw read test                                                    */
	/*-------------------------------------------------------------------*/
	printf("Raw read test...\n");
	t0 = get_ticks();
	xfer_cnt = 0;
	for (sector_no = RAW_SECTOR_START; ; sector_no+= SECTOR_CNT)
	{
		if (sector_no > RAW_SECTOR_END)
			sector_no = RAW_SECTOR_START;

		res = (FRESULT)disk_read(3, g_buff, sector_no, SECTOR_CNT);
		if (res)
		{
			printf("read failed at %d, rc=%d\n", sector_no, (WORD)res);
			return res;
		}

		xfer_cnt += SECTOR_CNT/2;

		if (get_ticks() - t0 >= 500)
			break;
	}
	xfer_cnt /= 5;
	printf("Raw read speed: %d.%02d MB/s\n",  xfer_cnt/1024, ((xfer_cnt%1024)*100)/1024);

	/*-------------------------------------------------------------------*/
	/*  Raw write test                                                   */
	/*-------------------------------------------------------------------*/
	printf("Raw write test...\n");
	t0 = get_ticks();
	xfer_cnt = 0;
	for (sector_no = RAW_SECTOR_START; ; sector_no+= SECTOR_CNT)
	{
		if (sector_no > RAW_SECTOR_END)
			sector_no = RAW_SECTOR_START;

		res = (FRESULT)disk_write(3, g_buff, sector_no, SECTOR_CNT);
		if (res)
		{
			printf("read failed at %d, rc=%d\n", sector_no, (WORD)res);
			return res;
		}

		xfer_cnt += SECTOR_CNT/2;

		if (get_ticks() - t0 >= 500)
			break;
	}
	xfer_cnt /= 5;
	printf("Raw write speed: %d.%02d MB/s\n",     xfer_cnt/1024, ((xfer_cnt%1024)*100)/1024);


	/*-------------------------------------------------------------------*/
	/*  File write test                                                  */
	/*-------------------------------------------------------------------*/
	printf("File write test...\n");
	res = f_open(&file1, "3:\\tfile1", FA_CREATE_ALWAYS | FA_WRITE);
	if (res)
	{
		printf("Open write error! %d\n", res);
		return res;
	}

	t0 = get_ticks();
	xfer_cnt = 0;
	while (1)
	{
		for (file_pos = 0; file_pos < 0x400000; file_pos += TEST_BLOCK_LEN)
		{
			res = f_write(&file1, g_buff, TEST_BLOCK_LEN, &cnt);
			if (res || (cnt != TEST_BLOCK_LEN))
			{
				printf("File write error!! %d\n", res);
				return res;
			}

			xfer_cnt += TEST_BLOCK_LEN/1024;

			if (get_ticks() - t0 >= 500)
				break;
		}

		if (get_ticks() - t0 >= 500)
			break;

		f_rewind(&file1);
	}

	f_close(&file1);

	xfer_cnt /= 5;
	printf("File write speed: %d.%02d MB/s\n", xfer_cnt/1024, ((xfer_cnt%1024)*100)/1024);


	/*-------------------------------------------------------------------*/
	/*  File read test                                                   */
	/*-------------------------------------------------------------------*/
	printf("File read test...\n");
	res = f_open(&file1, "3:\\tfile1", FA_READ);
	if (res)
	{
		printf("Open read error! %d\n", res);
		return res;
	}

	t0 = get_ticks();
	xfer_cnt = 0;
	while (1)
	{
		for (file_pos = 0; file_pos < 0x100000; file_pos += TEST_BLOCK_LEN)
		{
			res = f_read(&file1, g_buff, TEST_BLOCK_LEN, &cnt);
			if (res || (cnt != TEST_BLOCK_LEN))
			{
				printf("File read error!! %d, %d\n", res, cnt);
				printf("xfer_cnt = %d\n", xfer_cnt);
				return res;
			}

			xfer_cnt += TEST_BLOCK_LEN/1024;

			if (get_ticks() - t0 >= 500)
				break;
		}

		if (get_ticks() - t0 >= 500)
			break;

		f_rewind(&file1);
	}

	f_close(&file1);

	xfer_cnt /= 5;
	printf("File read speed: %d.%02d MB/s\n", xfer_cnt/1024, ((xfer_cnt%1024)*100)/1024);

	return FR_OK;
}


