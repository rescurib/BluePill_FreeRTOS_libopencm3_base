PROJECT = BlinkTest
BUILD_DIR = bin

SHARED_DIR = ../my-common-code
INCLUDES += -I../../Application/inc
CFILES = ../../Application/src/main.c \
        ../../Middleware/FreeRTOS/list.c \
		../../Middleware/FreeRTOS/queue.c \
		../../Middleware/FreeRTOS/tasks.c \
		../../Middleware/FreeRTOS/timers.c \
		../../Middleware/FreeRTOS/portable/GCC/ARM_CM3/port.c \
		../../Middleware/FreeRTOS/portable/MemMang/heap_4.c

# Paths for FreeRTOS includes
FREERTOS_DIR = ../../Middleware/FreeRTOS
FREERTOS_PORT_DIR = $(FREERTOS_DIR)/portable/GCC/ARM_CM3
FREERTOS_INCLUDE_DIRS = $(FREERTOS_DIR)/include \
						$(FREERTOS_PORT_DIR) \
						$(FREERTOS_DIR)/portable/MemMang

# Add FreeRTOS includes to the INCLUDES variable
INCLUDES += $(patsubst %,-I%, $(FREERTOS_INCLUDE_DIRS))

# TODO - you will need to edit these two lines!
DEVICE=stm32f103c8
OOCD_FILE = board/stm32f1discovery.cfg

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../../Lib/libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ./rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
