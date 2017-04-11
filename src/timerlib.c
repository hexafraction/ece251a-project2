/*
 * timerlib.c
 *
 *  Created on: Apr 7, 2017
 *      Author: hexafraction
 */
#include <SI_EFM8BB3_Register_Enums.h>
#include <SI_EFM8BB3_Defs.h>
volatile bool timerEnabled = false;
volatile long millisElapsed = 0;
volatile int reset_low = 0;
volatile int reset_high = 0;

unsigned char TCON_SAVE;
unsigned char TMOD_SAVE;

// puts system into 24.5MHz/32 clock
void setupSysClock(){
	CLKSEL = 0x50; // 0b01010000, meaning reset divider ready flag, divide by 32, source is HFOSC0 (24.5MHz)
	// actual system clock ends up being 765.625kHz
	reset_low = 255-254; // 766%256
	reset_high = 255-3; // 766/256, trunc
}

// overwrites state of timer 0
#pragma disable // we probably don't want interrupts happening in the middle of all this
void setupTimer(){
	setupSysClock();
	TCON_SAVE = TCON;
	TMOD_SAVE = TMOD;
	TCON = (TMOD & 0xCC); // keep timer 1 setting, zero all timer 0 bits (disabling and clearing its interrupt flags)
	TMOD = (TMOD & 0xF0) | (0x01); // keep timer 1 mode setting, set timer 1 to disable gate, TIMER mode, and mode 1.
	millisElapsed = 0;
	timerEnabled = false;
	IE_ET0 = 0; // don't enable interrupts just yet
}

// disable interrupts since we don't know whether writing to a 32-bit volatile integer is atomic
#pragma disable
long getElapsedMillis(){
	return millisElapsed;
}

// disable the internal flag we use to track consistency, and restore the original TCON and TMOD registers.
void tearDownTimer(){
	timerEnabled = false;
	TCON = TCON_SAVE;
	TMOD = TMOD_SAVE;
}


void resetTimer(){
	bit ET0_SAVE = IE_ET0; // save interrupt control state...
	IE_ET0 = 0; // ... and stop the timer.
	TL0 = reset_low; // reset the timer's internal count
	TH0 = reset_high;
	IE_ET0 = ET0_SAVE; // and restart it if it was started.
	millisElapsed = 0; // and reset our count
}

// enable the run flag, and the interrupt.
void startTimer(){
	timerEnabled = true;
	IE_ET0 = 1;
	TCON_TR0 = 1;
}

// disable the run flag and the interrupt.
void stopTimer(){
	timerEnabled = false;
	IE_ET0 = 0;
	TCON_TR0 = 0;
}

// the ISR itself.
/*SI_INTERRUPT (TIMERLIB_TICK, TIMER0_IRQn) {
	if(!timerEnabled) return;
	else {
		millisElapsed = millisElapsed + 1;
		TH0 = reset_high;
		TL0 = reset_low;
	}
}
*/
