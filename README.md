# BluePill + FreeRTOS + libopencm3

I created this repository with the following two goals in mind:
1. Have a base project almost ready to immediately start a real project with FreeRTOS.
2. Really learn how to use and port FreeRTOS (and teach others).

I understand that these objectives may be conflicting, a least for the teaching part. The folder and files structure I needed for portability and clean architecture might not be a "hello world" friendly, but Im guessing that if you want to learn how to use FreeRTOS, you will be able to understand the structure and the code.

```Bash
git clone --recurse-submodules https://github.com/rescurib/BluePill_FreeRTOS_libopencm3_base.git
```
## Build libopencm3
```Bash
cd ./Lib/libopencm3
make TARGETS='stm32/f1'
```
## Build base project
```Bash
cd ./Projects/GCC
make
```

## Flash the firmware to the BluePill board
```Bash
make flash
```
