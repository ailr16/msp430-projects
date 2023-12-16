APP		:=	game
CC		:=	msp430-elf-gcc
CCFLAGS := -Wall

$(APP) : main.c
	$(CC) main.c -mmcu=msp430g2553 -I /home/$(USER)/msp430-tools/include -L /home/$(USER)/msp430-tools/include
	