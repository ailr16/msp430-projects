APP		     :=	MSP430_app
CC		     :=	msp430-elf-gcc
CCFLAGS 	 := -Wall
OUTPUT_DIR   := output
OUTPUT_FILE  := output.o

$(APP) : main.c
	mkdir $(OUTPUT_DIR) -p
	$(CC) main.c -mmcu=msp430g2553 $(CCFLAGS) -o ./$(OUTPUT_DIR)/$(OUTPUT_FILE)
	
flash:	
	mspdebug tilib "prog ./$(OUTPUT_DIR)/$(OUTPUT_FILE)"

clean:
	rm -r $(OUTPUT_DIR)