led.bin: start.o led.o
	arm-none-linux-gnueabi-ld -Ttext 0x40008000 -o led.elf $^
	arm-none-linux-gnueabi-objcopy -O binary led.elf led.bin
	arm-none-linux-gnueabi-objdump -D led.elf > led_elf.dis


%.o : %.S
	arm-none-linux-gnueabi-gcc -o $@ $< -c -nostdlib

%.o : %.c
	arm-none-linux-gnueabi-gcc -o $@ $< -c -nostdlib

clean:
	rm *.o *.elf *.bin *.dis  -f
