PROJECT_NAME :=	MSP430_app
CC		     :=	msp430-elf-gcc
CCFLAGS 	 := -Wall
PROJECT_DIR  := $(CURDIR)
BUILD_DIR    := $(PROJECT_DIR)/Build
INCLUDE_DIR  := $(PROJECT_DIR)/Inc
SOURCE_DIR   := $(PROJECT_DIR)/Src
LINKER_DIR   := $(PROJECT_DIR)/Linker

SRCS         := main.c
SRCS         += $(wildcard $(SOURCE_DIR)/*.c)
INCS		 := $(wildcard $(INCLUDE_DIR)/*.h)
LINKER		 := $(wildcard $(LINKER_DIR)/*.ld)

$(PROJECT_NAME) : $(SRCS)
	mkdir $(BUILD_DIR) -p
	$(CC) -o $(BUILD_DIR)/$@ $^  -mmcu=msp430g2553 $(CFLAGS) -I $(INCLUDE_DIR) -L $(LINKER)
	
.PHONY: flash
flash:	
	mspdebug tilib "prog $(BUILD_DIR)/$(PROJECT_NAME)"

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)