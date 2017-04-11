################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
SRC_UPPER_SRCS += \
../src/timer_countdown.SRC \
../src/timerlib.SRC \
../src/wdt.SRC 

C_SRCS += \
../src/main.c \
../src/timerlib.c 

OBJS += \
./src/main.OBJ \
./src/timer_countdown.OBJ \
./src/timerlib.OBJ \
./src/wdt.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	wine "/home/hexafraction/SimplicityStudio_v4/developer/toolchains/keil_8051/9.53/BIN/C51" "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/main.OBJ: /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Register_Enums.h /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Defs.h /home/hexafraction/SimplicityStudio/v4_workspace/timerlib/src/timerlib.h /home/hexafraction/SimplicityStudio/v4_workspace/timerlib/src/timer_countdown.h /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/inc/render.h /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/inc/disp.h /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/inc/config/render_config.h

src/%.OBJ: ../src/%.SRC
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	wine "/home/hexafraction/SimplicityStudio_v4/developer/toolchains/keil_8051/9.53/BIN/AX51" "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/timerlib.OBJ: /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Register_Enums.h /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Defs.h


