################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
svc_number.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
svc_number.list \

OBJCOPY_BIN += \
svc_number.bin \


# All Target
all: svc_number.elf secondary-outputs

# Tool invocations
svc_number.elf: $(OBJS) $(USER_OBJS) C:\Users\pepe_\STM32CubeIDE\Embedded\ Systems\ Programming\ on\ ARM\ Cortex-M3-M4\ Processor\svc_number\STM32L4P5ZGTX_FLASH.ld
	arm-none-eabi-gcc -o "svc_number.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\pepe_\STM32CubeIDE\Embedded Systems Programming on ARM Cortex-M3-M4 Processor\svc_number\STM32L4P5ZGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="svc_number.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

svc_number.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "svc_number.list"
	@echo 'Finished building: $@'
	@echo ' '

svc_number.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "svc_number.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
