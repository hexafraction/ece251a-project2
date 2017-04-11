//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>                // SFR declarations
#include <SI_EFM8BB3_Defs.h>
#include "../src/timerlib.h"
#include "../src/timer_countdown.h"
#include "render.h"
#include "disp.h"
//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
//
// Note: the software watchdog timer is not disabled by default in this
// example, so a long-running program will reset periodically unless
// the timer is disabled or your program periodically writes to it.
//
// Review the "Watchdog Timer" section under the part family's datasheet
// for details. To find the datasheet, select your part in the
// Simplicity Launcher and click on "Data Sheet".
//
//-----------------------------------------------------------------------------
void init(void){

    uint8_t TMR3CN0_TR3_save;
	 // $[P0 - Port 0 Pin Latch]
	  // [P0 - Port 0 Pin Latch]$

	  // $[P0MDOUT - Port 0 Output Mode]
	  /*
	   // P0.0 output is open-drain
	   // P0.1 output is open-drain
	   // P0.2 output is open-drain
	   // P0.3 output is open-drain
	   // P0.4 output is open-drain
	   // P0.5 output is open-drain
	   // P0.6 output is push-pull
	   // P0.7 output is open-drain
	   */
	  P0MDOUT = P0MDOUT_B0__OPEN_DRAIN
	            | P0MDOUT_B1__OPEN_DRAIN
	            | P0MDOUT_B2__OPEN_DRAIN
	            | P0MDOUT_B3__OPEN_DRAIN
	            | P0MDOUT_B4__OPEN_DRAIN
	            | P0MDOUT_B5__OPEN_DRAIN
	            | P0MDOUT_B6__PUSH_PULL
	            | P0MDOUT_B7__OPEN_DRAIN;
	  // [P0MDOUT - Port 0 Output Mode]$

	  // $[P0MDIN - Port 0 Input Mode]
	  // [P0MDIN - Port 0 Input Mode]$

	  // $[P0SKIP - Port 0 Skip]
	  /*
	   // P0.0 pin is skipped by the crossbar
	   // P0.1 pin is skipped by the crossbar
	   // P0.2 pin is skipped by the crossbar
	   // P0.3 pin is skipped by the crossbar
	   // P0.4 pin is skipped by the crossbar
	   // P0.5 pin is skipped by the crossbar
	   // P0.6 pin is not skipped by the crossbar
	   // P0.7 pin is not skipped by the crossbar
	   */
	  P0SKIP = P0SKIP_B0__SKIPPED | P0SKIP_B1__SKIPPED | P0SKIP_B2__SKIPPED
	           | P0SKIP_B3__SKIPPED
	           | P0SKIP_B4__SKIPPED | P0SKIP_B5__SKIPPED
	           | P0SKIP_B6__NOT_SKIPPED
	           | P0SKIP_B7__NOT_SKIPPED;
	  // [P0SKIP - Port 0 Skip]$

	  // $[P0MASK - Port 0 Mask]
	  // [P0MASK - Port 0 Mask]$

	  // $[P0MAT - Port 0 Match]
	// [P0MAT - Port 0 Match]$
	  // $[P1 - Port 1 Pin Latch]
	   // [P1 - Port 1 Pin Latch]$

	   // $[P1MDOUT - Port 1 Output Mode]
	   /*
	    // P1.0 output is push-pull
	    // P1.1 output is open-drain
	    // P1.2 output is open-drain
	    // P1.3 output is open-drain
	    // P1.4 output is push-pull
	    // P1.5 output is push-pull
	    // P1.6 output is push-pull
	    // P1.7 output is open-drain
	    */
	   P1MDOUT = P1MDOUT_B0__PUSH_PULL
	             | P1MDOUT_B1__OPEN_DRAIN
	             | P1MDOUT_B2__OPEN_DRAIN
	             | P1MDOUT_B3__OPEN_DRAIN
	             | P1MDOUT_B4__PUSH_PULL
	             | P1MDOUT_B5__PUSH_PULL
	             | P1MDOUT_B6__PUSH_PULL
	             | P1MDOUT_B7__OPEN_DRAIN;
	   // [P1MDOUT - Port 1 Output Mode]$

	   // $[P1MDIN - Port 1 Input Mode]
	   /*
	    // P1.0 pin is configured for digital mode
	    // P1.1 pin is configured for digital mode
	    // P1.2 pin is configured for digital mode
	    // P1.3 pin is configured for analog mode
	    // P1.4 pin is configured for digital mode
	    // P1.5 pin is configured for digital mode
	    // P1.6 pin is configured for digital mode
	    // P1.7 pin is configured for analog mode
	    */
	   P1MDIN = P1MDIN_B0__DIGITAL | P1MDIN_B1__DIGITAL | P1MDIN_B2__DIGITAL
	            | P1MDIN_B3__ANALOG
	            | P1MDIN_B4__DIGITAL | P1MDIN_B5__DIGITAL
	            | P1MDIN_B6__DIGITAL
	            | P1MDIN_B7__ANALOG;
	   // [P1MDIN - Port 1 Input Mode]$

	   // $[P1SKIP - Port 1 Skip]
	   /*
	    // P1.0 pin is not skipped by the crossbar
	    // P1.1 pin is skipped by the crossbar
	    // P1.2 pin is skipped by the crossbar
	    // P1.3 pin is skipped by the crossbar
	    // P1.4 pin is not skipped by the crossbar
	    // P1.5 pin is not skipped by the crossbar
	    // P1.6 pin is not skipped by the crossbar
	    // P1.7 pin is skipped by the crossbar
	    */
	   P1SKIP = P1SKIP_B0__NOT_SKIPPED | P1SKIP_B1__SKIPPED | P1SKIP_B2__SKIPPED
	            | P1SKIP_B3__SKIPPED
	            | P1SKIP_B4__NOT_SKIPPED | P1SKIP_B5__NOT_SKIPPED
	            | P1SKIP_B6__NOT_SKIPPED
	            | P1SKIP_B7__SKIPPED;
	   // [P1SKIP - Port 1 Skip]$

	   // $[P1MASK - Port 1 Mask]
	   // [P1MASK - Port 1 Mask]$

	   // $[P1MAT - Port 1 Match]
	   // [P1MAT - Port 1 Match]$

	  // $[XBR2 - Port I/O Crossbar 2]

	   // $[P2 - Port 2 Pin Latch]
	   // [P2 - Port 2 Pin Latch]$

	   // $[P2MDOUT - Port 2 Output Mode]
	   /*
	    // P2.0 output is open-drain
	    // P2.1 output is open-drain
	    // P2.2 output is open-drain
	    // P2.3 output is push-pull
	    // P2.4 output is open-drain
	    // P2.5 output is open-drain
	    // P2.6 output is push-pull
	    */
	   P2MDOUT = P2MDOUT_B0__OPEN_DRAIN
	             | P2MDOUT_B1__OPEN_DRAIN
	             | P2MDOUT_B2__OPEN_DRAIN
	             | P2MDOUT_B3__PUSH_PULL
	             | P2MDOUT_B4__OPEN_DRAIN
	             | P2MDOUT_B5__OPEN_DRAIN
	             | P2MDOUT_B6__PUSH_PULL;
	   // [P2MDOUT - Port 2 Output Mode]$

	   // $[P2MDIN - Port 2 Input Mode]
	   // [P2MDIN - Port 2 Input Mode]$

	   // $[P2SKIP - Port 2 Skip]
	   /*
	    // P2.0 pin is not skipped by the crossbar
	    // P2.1 pin is not skipped by the crossbar
	    // P2.2 pin is not skipped by the crossbar
	    // P2.3 pin is skipped by the crossbar
	    */
	   SFRPAGE = 0x20;
	   P2SKIP = P2SKIP_B0__NOT_SKIPPED
	            | P2SKIP_B1__NOT_SKIPPED
	            | P2SKIP_B2__NOT_SKIPPED
	            | P2SKIP_B3__SKIPPED;
	   // [P2SKIP - Port 2 Skip]$

	   // $[P2MASK - Port 2 Mask]
	   // [P2MASK - Port 2 Mask]$

	   // $[P2MAT - Port 2 Match]
	 // [P2MAT - Port 2 Match]$

	   /*
	    // Weak Pullups enabled
	    // Crossbar enabled
	    // UART1 I/O unavailable at Port pin
	    // UART1 RTS1 unavailable at Port pin
	    // UART1 CTS1 unavailable at Port pin
	    */
	   SFRPAGE = 0x00;
	   XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED
	          | XBR2_XBARE__ENABLED
	          | XBR2_URT1E__DISABLED
	          | XBR2_URT1RTSE__DISABLED
	          | XBR2_URT1CTSE__DISABLED;
	   // [XBR2 - Port I/O Crossbar 2]$

	   // $[PRTDRV - Port Drive Strength]
	   // [PRTDRV - Port Drive Strength]$

	   // $[XBR0 - Port I/O Crossbar 0]
	   /*
	    // UART0 I/O unavailable at Port pin
	    // SPI I/O routed to Port pins. The SPI can be assigned either 3 or 4
	    //     GPIO pins
	    // SMBus 0 I/O unavailable at Port pins
	    // CP0 unavailable at Port pin
	    // Asynchronous CP0 unavailable at Port pin
	    // CP1 unavailable at Port pin
	    // Asynchronous CP1 unavailable at Port pin
	    // SYSCLK unavailable at Port pin
	    */
	   XBR0 = XBR0_URT0E__DISABLED | XBR0_SPI0E__ENABLED | XBR0_SMB0E__DISABLED
	          | XBR0_CP0E__DISABLED
	          | XBR0_CP0AE__DISABLED | XBR0_CP1E__DISABLED
	          | XBR0_CP1AE__DISABLED
	          | XBR0_SYSCKE__DISABLED;
	   // [XBR0 - Port I/O Crossbar 0]$

	   // $[XBR1 - Port I/O Crossbar 1]
	   /*
	    // CEX0, CEX1, CEX2 routed to Port pins
	    // ECI unavailable at Port pin
	    // T0 unavailable at Port pin
	    // T1 unavailable at Port pin
	    // T2 unavailable at Port pin
	    */
	   XBR1 = XBR1_PCA0ME__CEX0_TO_CEX2 | XBR1_ECIE__DISABLED | XBR1_T0E__DISABLED
	          | XBR1_T1E__DISABLED
	          | XBR1_T2E__DISABLED;
	   // [XBR1 - Port I/O Crossbar 1]$
	   // $[HFOSC1 Setup]
	    // [HFOSC1 Setup]$

	    // $[CLKSEL - Clock Select]
	    /*
	     // Clock derived from the Internal High Frequency Oscillator 0
	     // SYSCLK is equal to selected clock source divided by 1
	     */
	    CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_1;
	    while ((CLKSEL & CLKSEL_DIVRDY__BMASK) == CLKSEL_DIVRDY__NOT_READY){}
	      ;
	    // $[Timer Initialization]
	     // Save Timer Configuration
	     TMR3CN0_TR3_save = TMR3CN0 & TMR3CN0_TR3__BMASK;
	     // Stop Timer
	     TMR3CN0 &= ~(TMR3CN0_TR3__BMASK);
	     // [Timer Initialization]$

	     // $[TMR3CN1 - Timer 3 Control 1]
	     // [TMR3CN1 - Timer 3 Control 1]$

	     // $[TMR3CN0 - Timer 3 Control]
	     // [TMR3CN0 - Timer 3 Control]$

	     // $[TMR3H - Timer 3 High Byte]
	     /*
	      // Timer 3 High Byte = 0xF8
	      */
	     TMR3H = (0xF8 << TMR3H_TMR3H__SHIFT);
	     // [TMR3H - Timer 3 High Byte]$

	     // $[TMR3L - Timer 3 Low Byte]
	     /*
	      // Timer 3 Low Byte = 0x06
	      */
	     TMR3L = (0x06 << TMR3L_TMR3L__SHIFT);
	     // [TMR3L - Timer 3 Low Byte]$

	     // $[TMR3RLH - Timer 3 Reload High Byte]
	     /*
	      // Timer 3 Reload High Byte = 0xF8
	      */
	     TMR3RLH = (0xF8 << TMR3RLH_TMR3RLH__SHIFT);
	     // [TMR3RLH - Timer 3 Reload High Byte]$

	     // $[TMR3RLL - Timer 3 Reload Low Byte]
	     /*
	      // Timer 3 Reload Low Byte = 0x06
	      */
	     TMR3RLL = (0x06 << TMR3RLL_TMR3RLL__SHIFT);
	     // [TMR3RLL - Timer 3 Reload Low Byte]$

	     // $[TMR3CN0]
	     /*
	      // Start Timer 3 running
	      */
	     TMR3CN0 |= TMR3CN0_TR3__RUN;
	     // [TMR3CN0]$

	     // $[Timer Restoration]
	     // Restore Timer Configuration
	     TMR3CN0 |= TMR3CN0_TR3_save;
	     // [Timer Restoration]$

	  // [CLKSEL - Clock Select]$
	     // $[PCA Off]
	      PCA0CN0_CR = PCA0CN0_CR__STOP;
	      // [PCA Off]$

	      // $[PCA0MD - PCA Mode]
	      // [PCA0MD - PCA Mode]$

	      // $[PCA0CENT - PCA Center Alignment Enable]
	      // [PCA0CENT - PCA Center Alignment Enable]$

	      // $[PCA0CLR - PCA Comparator Clear Control]
	      // [PCA0CLR - PCA Comparator Clear Control]$

	      // $[PCA0L - PCA Counter/Timer Low Byte]
	      // [PCA0L - PCA Counter/Timer Low Byte]$

	      // $[PCA0H - PCA Counter/Timer High Byte]
	      // [PCA0H - PCA Counter/Timer High Byte]$

	      // $[PCA0POL - PCA Output Polarity]
	      // [PCA0POL - PCA Output Polarity]$

	      // $[PCA0PWM - PCA PWM Configuration]
	      // [PCA0PWM - PCA PWM Configuration]$

	      // $[PCA On]
	      PCA0CN0_CR = PCA0CN0_CR__RUN;
	    // [PCA On]$
	      // $[PCA0 Settings Save]
	      // Select Capture/Compare register)
	      PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
	      // [PCA0 Settings Save]$

	      // $[PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]
	      /*
	       // Disable negative edge capture
	       // Disable CCF0 interrupts
	       // Enable match function
	       // 8 to 11-bit PWM selected
	       // Disable positive edge capture
	       // Enable comparator function
	       // Enable PWM function
	       // Disable toggle function
	       */
	      PCA0CPM0 = PCA0CPM0_CAPN__DISABLED
	                 | PCA0CPM0_ECCF__DISABLED
	                 | PCA0CPM0_MAT__ENABLED
	                 | PCA0CPM0_PWM16__8_BIT
	                 | PCA0CPM0_CAPP__DISABLED
	                 | PCA0CPM0_ECOM__ENABLED
	                 | PCA0CPM0_PWM__ENABLED
	                 | PCA0CPM0_TOG__DISABLED;
	      // [PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]$

	      // $[PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]
	      // [PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]$

	      // $[PCA0CPH0 - PCA Channel 0 Capture Module High Byte]
	      // [PCA0CPH0 - PCA Channel 0 Capture Module High Byte]$

	      // $[Auto-reload]
	      // [Auto-reload]$

	      // $[PCA0 Settings Restore]
	    // [PCA0 Settings Restore]$

	      // $[SPI0CKR - SPI0 Clock Rate]
	       /*
	        // SPI0 Clock Rate = 0x0B
	        */
	       SPI0CKR = (0x0B << SPI0CKR_SPI0CKR__SHIFT);
	       // [SPI0CKR - SPI0 Clock Rate]$

	       // $[SPI0CFG - SPI0 Configuration]
	       /*
	        // Enable master mode. Operate as a master
	        */
	       SPI0CFG |= SPI0CFG_MSTEN__MASTER_ENABLED;
	       // [SPI0CFG - SPI0 Configuration]$

	       // $[SPI0PCF - SPI0 Pin Configuration]
	       // [SPI0PCF - SPI0 Pin Configuration]$

	       // $[SPI0CN0 - SPI0 Control]
	       /*
	        // Enable the SPI module
	        // 3-Wire Slave or 3-Wire Master Mode. NSS signal is not routed to a port
	        //     pin
	        */
	       SPI0CN0 &= ~SPI0CN0_NSSMD__FMASK;
	       SPI0CN0 |= SPI0CN0_SPIEN__ENABLED;
	       // [SPI0CN0 - SPI0 Control]$

	       // $[SPI0FCN0 - SPI0 FIFO Control 0]
	       // [SPI0FCN0 - SPI0 FIFO Control 0]$

	       // $[SPI0FCN1 - SPI0 FIFO Control 1]
	     // [SPI0FCN1 - SPI0 FIFO Control 1]$
	       // $[EIE1 - Extended Interrupt Enable 1]
	         /*
	          // Enable interrupt requests generated by the ADINT flag
	          // Disable ADC0 Window Comparison interrupt
	          // Disable CP0 interrupts
	          // Disable CP1 interrupts
	          // Disable all Port Match interrupts
	          // Disable all PCA0 interrupts
	          // Disable all SMB0 interrupts
	          // Enable interrupt requests generated by the TF3L or TF3H flags
	          */
	         EIE1 = EIE1_EADC0__ENABLED | EIE1_EWADC0__DISABLED | EIE1_ECP0__DISABLED
	                | EIE1_ECP1__DISABLED
	                | EIE1_EMAT__DISABLED | EIE1_EPCA0__DISABLED
	                | EIE1_ESMB0__DISABLED
	                | EIE1_ET3__ENABLED;
	         // [EIE1 - Extended Interrupt Enable 1]$

	         // $[EIE2 - Extended Interrupt Enable 2]
	         // [EIE2 - Extended Interrupt Enable 2]$

	         // $[EIP1H - Extended Interrupt Priority 1 High]
	         // [EIP1H - Extended Interrupt Priority 1 High]$

	         // $[EIP1 - Extended Interrupt Priority 1 Low]
	         /*
	          // ADC0 Conversion Complete interrupt priority LSB set to high
	          // ADC0 Window interrupt priority LSB set to high
	          // CP0 interrupt priority LSB set to low
	          // CP1 interrupt priority LSB set to low
	          // Port Match interrupt priority LSB set to low
	          // PCA0 interrupt priority LSB set to low
	          // SMB0 interrupt priority LSB set to low
	          // Timer 3 interrupt priority LSB set to low
	          */
	         SFRPAGE = 0x10;
	         EIP1 = EIP1_PADC0__HIGH | EIP1_PWADC0__HIGH | EIP1_PCP0__LOW | EIP1_PCP1__LOW
	                | EIP1_PMAT__LOW
	                | EIP1_PPCA0__LOW | EIP1_PSMB0__LOW | EIP1_PT3__LOW;
	         // [EIP1 - Extended Interrupt Priority 1 Low]$

	         // $[EIP2 - Extended Interrupt Priority 2]
	         // [EIP2 - Extended Interrupt Priority 2]$

	         // $[EIP2H - Extended Interrupt Priority 2 High]
	         // [EIP2H - Extended Interrupt Priority 2 High]$

	         // $[IE - Interrupt Enable]
	         /*
	          // Disable all interrupt sources
	          // Disable external interrupt 0
	          // Disable external interrupt 1
	          // Enable interrupt requests generated by SPI0
	          // Disable all Timer 0 interrupt
	          // Disable all Timer 1 interrupt
	          // Enable interrupt requests generated by the TF2L or TF2H flags
	          // Disable UART0 interrupt
	          */
	         SFRPAGE = 0x00;
	         IE = IE_EA__DISABLED | IE_EX0__DISABLED | IE_EX1__DISABLED | IE_ESPI0__ENABLED
	              | IE_ET0__DISABLED
	              | IE_ET1__DISABLED | IE_ET2__ENABLED | IE_ES0__DISABLED;
	         // [IE - Interrupt Enable]$

	         // $[IP - Interrupt Priority]
	         // [IP - Interrupt Priority]$

	         // $[IPH - Interrupt Priority High]
	       // [IPH - Interrupt Priority High]$
}



int main (void)
{
	static SI_SEGMENT_VARIABLE(line[16], uint8_t, RENDER_LINE_SEG);
	int y;
	int q;
	init();

	// timer 2 16 bit mode, 2MHz clock

	setupSysClock();
	TMR2CN0 = 2;
  // TODO still needs work
	//char SFRPAGE_SAVE = SFRPAGE;
	//SFRPAGE = 0x20;
	//	P3MDOUT = P3MDOUT_B0__OPEN_DRAIN | P3MDOUT_B1__PUSH_PULL
	//			| P3MDOUT_B2__PUSH_PULL | P3MDOUT_B3__PUSH_PULL
	//			| P3MDOUT_B4__PUSH_PULL | P3MDOUT_B7__OPEN_DRAIN;
	//	SFRPAGE = SFRPAGE_SAVE;
	P1_B6 = 0;

	XBR2 |= 0x40;
	P3_B4 = 1;
	P2_B6 = 1;
	P1_B5 = 0;
	IE_EA = 1;
	DISP_Init();
	//DISP_ClearAll();

	//setupTimer();
	disableWdt();
	//performCountdown();
	//startTimer();
	// P1 B5 and P1 B6 as well
	for (y = 0; y < FONT_HEIGHT; y++)
	{

	   RENDER_StrLine(line, 3, y, "TEST");
	   DISP_WriteLine(4+y, line);
	}

	P1_B4 = 0;

	P1_B6 = 1;
	P1_B5 = 1;
	while (1) {
		for(q = 0; q < 5000; q++){

		} P1_B4 = 1;
		for(q = 0; q < 5000; q++){

		}
	P1_B4 = 0;
	// Spin forever
	}
}
