/*
 * time_to_shift.h
 *
 *  Created on: Nov 29, 2017
 *      Author: alxhoff
 */

#ifndef TIME_TO_SHIFT_H_
#define TIME_TO_SHIFT_H_

void ds3231_time_to_sn54hc595_shift(DS3231_device_t* RTC_dev,
		shift_array_t* SHIFT_dev, nixie_tube_array_t* NIXIE_dev);

#endif /* TIME_TO_SHIFT_H_ */
