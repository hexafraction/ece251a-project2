/*
 * timerlib.h
 *
 *  Created on: Apr 7, 2017
 *      Author: hexafraction
 */

#ifndef TIMERLIB_H_
#define TIMERLIB_H_
#include <SI_EFM8BB3_Register_Enums.h>
#include <SI_EFM8BB3_Defs.h>

void setupSysClock();
void setupTimer();
long getElapsedMillis();
void tearDownTimer();
void resetTimer();
void stopTimer();
void startTimer();
void start();


#endif /* TIMERLIB_H_ */
