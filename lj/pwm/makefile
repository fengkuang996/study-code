CROSS_COMPLINER = arm-none-linux-gnueabi-
CC = $(CROSS_COMPLINER)gcc
LD = $(CROSS_COMPLINER)ld
OBJCOPY = $(CROSS_COMPLINER)objcopy
OBJDUMP = $(CROSS_COMPLINER)objdump
NM = $(CROSS_COMPLINER)nm

CFLAG = -c -g -O0
OBJS = start.o test.o pwm.o

all:$(OBJS)

	$(LD) $(OBJS) -o test.elf -Ttext 0x50000000

	$(OBJCOPY) -O binary test.elf test.bin

	$(OBJDUMP) -D test.elf > test.dis

	$(NM) test.elf > test.map

%.o:%.c
	$(CC) $(CFLAG) $^ -o $@ -nostdlib
%.o:%.S
	$(CC) $(CFLAG) $^ -o $@

clean:
	rm -rf *.o *.elf *.bin *.dis *.map
