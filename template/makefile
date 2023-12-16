APP		     :=	MSP430_app
CC		     :=	msp430-elf-gcc
CCFLAGS 	 := -Wall
MSP_HEADERS  := /home/$(USER)/msp430-tools/include
OUTPUT_DIR   := output
OUTPUT_FILE  := output.o

$(APP) : main.c
	mkdir $(OUTPUT_DIR) -p
	$(CC) main.c -mmcu=msp430g2553 $(CCFLAGS) -I $(MSP_HEADERS) -L $(MSP_HEADERS) -o ./$(OUTPUT_DIR)/$(OUTPUT_FILE)
	
flash:	
	mspdebug tilib "prog ./$(OUTPUT_DIR)/$(OUTPUT_FILE)"

clean:
	rm -r $(OUTPUT_DIR)