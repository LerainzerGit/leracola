# leraOS Cola Build System
CXX = clang++
LD = lld-link
FLAGS = -target x86_64-unknown-none-elf -ffreestanding -fno-exceptions -fno-rtti -c

BUILD_DIR = build
BOOT_OUT = $(BUILD_DIR)/BOOTX64.EFI

all: setup boot kernel

setup:
	mkdir -p $(BUILD_DIR)

boot: boot/main.cpp
	$(CXX) -target x86_64-unknown-windows-gnu -ffreestanding -fno-exceptions -fno-rtti -c boot/main.cpp -o $(BUILD_DIR)/boot.o
	$(LD) /subsystem:efi_application /entry:efi_main /out:$(BOOT_OUT) $(BUILD_DIR)/boot.o

kernel: kernel/kernel.cpp
	$(CXX) $(FLAGS) kernel/kernel.cpp -o $(BUILD_DIR)/kernel.o
	$(CXX) $(FLAGS) kernel/apps/doom.cpp -o $(BUILD_DIR)/doom.o

clean:
	rm -rf $(BUILD_DIR)
