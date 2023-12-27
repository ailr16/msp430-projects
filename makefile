PROJECT_NAME  := MSP430_app
CC		      := msp430-elf-gcc
CCFLAGS 	  := -Wall
CCFLAGS_DEBUG := -Wall -O0 -g3 -ggdb -gdwarf-2
PROJECT_DIR   := $(CURDIR)
BUILD_DIR     := $(PROJECT_DIR)/Build
INCLUDE_DIR   := $(PROJECT_DIR)/Inc
SOURCE_DIR    := $(PROJECT_DIR)/Src
LINKER_DIR    := $(PROJECT_DIR)/.Linker

SRCS          := main.c
SRCS          += $(wildcard $(SOURCE_DIR)/*.c)
INCS		  := $(wildcard $(INCLUDE_DIR)/*.h)
LINKER		  := $(wildcard $(LINKER_DIR)/*.ld)

DEBUG_PORT    := 2000

$(PROJECT_NAME) : $(SRCS)
	mkdir $(BUILD_DIR) -p
	$(CC) -o $(BUILD_DIR)/$@ $^  -mmcu=msp430g2553 $(CCFLAGS) -I $(INCLUDE_DIR) -L $(LINKER)
	
.PHONY: flash
flash:	
	mspdebug tilib "prog $(BUILD_DIR)/$(PROJECT_NAME)"

debug: $(SRCS)
	mkdir $(BUILD_DIR) -p
	$(CC) -o $(BUILD_DIR)/$@ $^ -mmcu=msp430g2553 $(CCFLAGS_DEBUG) -I $(INCLUDE_DIR) -L $(LINKER)
	mspdebug tilib "gdb"

.PHONY: open
open:
	msp430-elf-gdb -ex 'target remote localhost:$(DEBUG_PORT)' $(BUILD_DIR)/debug

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)