// PS/2 Keyboard Hardware Driver
#pragma once

using uint8_t = unsigned char;

namespace leraOS::Drivers {
    class PS2Keyboard {
    private:
        static inline uint8_t inb(unsigned short port) {
            uint8_t ret;
            asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
            return ret;
        }

    public:
        static bool HasData() {
            return (inb(0x64) & 0x01) != 0;
        }

        static uint8_t ReadScancode() {
            while (!HasData()) {
                asm volatile ("pause");
            }
            return inb(0x60);
        }

        static char ScancodeToAscii(uint8_t scancode) {
            static const char scancodeTable[128] = {
                0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
              '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
                 0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
                 0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
               '*',   0, ' '
            };
            if (scancode < 128) return scancodeTable[scancode];
            return 0;
        }
    };
}
