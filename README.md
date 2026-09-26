# BluePill + FreeRTOS + libopencm3

I created this repository with the following two goals in mind:
1. Have a base project almost ready to immediately start a minimal but real firmware application with FreeRTOS.
2. Really learn how to use and port FreeRTOS (and teach others).

I understand that these objectives may be conflicting, a least for the teaching part. At this point, I'm assuming you already shown how to port FreeRTOS manually. The folder and files structure is the following:

```text
.
|-- Application/
|   |-- inc/                    # Application and FreeRTOS configuration headers
|   `-- src/                    # Application source files
|-- Lib/
|   `-- libopencm3/             # libopencm3 submodule
|-- Middleware/
|   `-- FreeRTOS/               # FreeRTOS kernel submodule
`-- Projects/
	|-- Eclipse/                # Eclipse project files
	`-- GCC/
		|-- Makefile
		|-- generated.stm32f103c8t6.ld
		|-- bin/                # Build output
		`-- obj/                # Build output
```
## Clone the repository
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
