C_SOURCES = $(shell find . -name "*.c")
OBJ_FILES = ${C_SOURCES:.c=.o \
    arch/i386/boot/boot.o \
}

CCFLAGS = -I ./include -I ./arch/i386/include -g -m32 -ffreestanding -nostdlib -fno-builtin -fno-stack-protector -no-pie -fno-pic -Wall -Wextra -O3
KERNELBIN = ./build/out/boot/kernel.bin
OSBIN = ./build/out/os-image.iso

build: prepare os-image.iso

os-image.iso: kernel.bin
	@echo "Creating ISO image..."
	@mkdir -p ./build/out/boot/grub
	@mv ./build/$(notdir $<) ./build/out/boot/
	@cp boot/grub.cfg ./build/out/boot/grub/grub.cfg
	@cd ./build/out && grub-mkrescue -o ./$@ . || (echo "grub-mkrescue failed"; exit 1)

kernel.bin: prepare ${OBJ_FILES}
	@echo "Linking kernel..."
	ld -m elf_i386 -o ./build/$(notdir $@) -Tlinker.ld ./build/obj/boot.o $(shell find ./build/obj/ -name "*.o" ! -name "boot.o")

prepare:
	@echo "Preparing build directories..."
	rm -rf ./build
	mkdir -p ./build/boot/grub ./build/obj ./build/out/boot
run:
	qemu-system-i386 -kernel $(KERNELBIN)

real_run:
	qemu-system-i386 -cdrom $(OSBIN)


%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CCFLAGS) -c $< -o ./build/obj/$(notdir $@)

%.o: %.asm
	@echo "Assembling $<..."
	nasm $< -f elf -o ./build/obj/$(notdir $@)

clean:
	@echo "Cleaning up..."
	$(RM) -rf ./build $(OSBIN) $(KERNELBIN)
