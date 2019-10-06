################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Generic.c \
../src/UI.c \
../src/fantasma.c \
../src/utn.c 

OBJS += \
./src/Generic.o \
./src/UI.o \
./src/fantasma.o \
./src/utn.o 

C_DEPS += \
./src/Generic.d \
./src/UI.d \
./src/fantasma.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


