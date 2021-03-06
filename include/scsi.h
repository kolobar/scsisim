/*
 *  scsi.h
 *  SCSI-related definitions for the scsisim library.
 *  This is an internal interface file for the scsisim library.
 *
 *  Copyright (c) 2017, Chris Coffey <kpuc@sdf.org>
 *
 *  Permission to use, copy, modify, and/or distribute this software
 *  for any purpose with or without fee is hereby granted, provided
 *  that the above copyright notice and this permission notice appear
 *  in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL 
 *  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 *  AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 *  DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA
 *  OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 *  TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 *  PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __SCSISIM_SCSI_H__
#define __SCSISIM_SCSI_H__

#include <stdint.h>

/* This struct contains everything needed to 
 * send a READ or WRITE command to the device */
struct scsi_cmd {
	/* Input values */
	int direction;
	uint8_t cdb_len;
	uint8_t *cdb;
	unsigned int data_len;
	uint8_t *data;
	uint8_t sense_len;
	uint8_t *sense;
	/* Output values */
	unsigned int data_xfered;
	uint8_t sense_xfered;
};

int scsi_send_cdb(const struct scsisim_dev *device, struct scsi_cmd *my_cmd);

#endif  /* __SCSISIM_SCSI_H__ */

/* EOF */

