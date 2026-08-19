// DOOM Engine Adapter & PS/2 Input Integration
#pragma once
#include "../gfx.cpp"
#include "../drivers/keyboard.cpp"

using uint32_t = unsigned int;

extern "C" {
    extern uint32_t* DG_ScreenBuffer;
}

namespace leraOS::Apps {
    class DoomAdapter {
    private:
        static inline Gfx::Framebuffer* targetFb = nullptr;

    public:
        static void AttachFramebuffer(Gfx::Framebuffer* fb) {
            targetFb = fb;
        }

        static void Redraw() {
            if (!targetFb || !DG_ScreenBuffer) return;

            for (int y = 0; y < 200; ++y) {
                for (int x = 0; x < 320; ++x) {
                    uint32_t color = DG_ScreenBuffer[y * 320 + x];
                    targetFb->PutPixel(100 + x, 100 + y, color);
                }
            }
        }
    };
}

extern "C" {
    void DG_Init() {}
    void DG_DrawFrame() { leraOS::Apps::DoomAdapter::Redraw(); }
    void DG_SleepMs(uint32_t ms) { (void)ms; }
    uint32_t DG_GetTicksMs() { return 0; }

    int DG_GetKey(int* pressed, unsigned char* key) {
        if (leraOS::Drivers::PS2Keyboard::HasData()) {
            uint8_t scancode = leraOS::Drivers::PS2Keyboard::ReadScancode();
            *pressed = (scancode & 0x80) ? 0 : 1;
            *key = leraOS::Drivers::PS2Keyboard::ScancodeToAscii(scancode & 0x7F);
            return 1;
        }
        *pressed = 0;
        *key = 0;
        return 0;
    }

    void DG_SetWindowTitle(const char* title) { (void)title; }
}
