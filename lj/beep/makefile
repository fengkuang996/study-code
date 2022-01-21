defulat:
	arm-none-linux-gnueabi-as start.S -o start.o
	arm-none-linux-gnueabi-gcc -c -o test.o test.c -nostdlib
	arm-none-linux-gnueabi-ld start.o test.o -otest.elf -Ttext 0x50000000
	arm-none-linux-gnueabi-objcopy -O binary test.elf test.bin
clean:
	rm -rf *.o *.elf *.bin
