led.bin : led.s
	arm-none-linux-gnueabi-gcc -g -c led.s -o led.o
	arm-none-linux-gnueabi-ld -Ttext 0x87800000 led.o -o led.elf
	arm-none-linux-gnueabi-objcopy -O binary -g -S led.elf led.bin
	arm-none-linux-gnueabi-objdump -D led.elf > led.dis
clean:
	rm -rf *.o led.bin led.elf led.dis
