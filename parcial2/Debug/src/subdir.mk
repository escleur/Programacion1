################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Instrumento.c \
../src/Musico.c \
../src/Orquesta.c \
../src/UI.c \
../src/informes.c \
../src/parcial2.c \
../src/utn.c 

OBJS += \
./src/Instrumento.o \
./src/Musico.o \
./src/Orquesta.o \
./src/UI.o \
./src/informes.o \
./src/parcial2.o \
./src/utn.o 

C_DEPS += \
./src/Instrumento.d \
./src/Musico.d \
./src/Orquesta.d \
./src/UI.d \
./src/informes.d \
./src/parcial2.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


