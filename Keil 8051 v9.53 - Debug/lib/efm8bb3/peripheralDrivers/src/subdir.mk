################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/peripheral_driver/src/spi_0.c 

OBJS += \
./lib/efm8bb3/peripheralDrivers/src/spi_0.OBJ 


# Each subdirectory must supply rules for building sources it contributes
lib/efm8bb3/peripheralDrivers/src/spi_0.OBJ: /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/peripheral_driver/src/spi_0.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	wine "/home/hexafraction/SimplicityStudio_v4/developer/toolchains/keil_8051/9.53/BIN/C51" "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

lib/efm8bb3/peripheralDrivers/src/spi_0.OBJ: /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Register_Enums.h /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/peripheral_driver/inc/spi_0.h /home/hexafraction/SimplicityStudio_v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Defs.h


