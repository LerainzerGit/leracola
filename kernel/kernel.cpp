// Core Kernel Entry Point for leraOS Cola
#include "gfx.cpp"
#include "gui.cpp"
#include "appstore.cpp"
#include "drivers/keyboard.cpp"

extern "C" void kernel_main(unsigned long long fb_base, unsigned int width, unsigned int height, unsigned int pitch) {
    leraOS::Gfx::Framebuffer fb(reinterpret_cast<uint32_t*>(fb_base), width, height, pitch);
    fb.Clear(leraOS::Gfx::Color::Background);

    leraOS::Apps::AppStoreUI store;
    store.RenderStore(fb);

    while (true) {
        if (leraOS::Drivers::PS2Keyboard::HasData()) {
            uint8_t scancode = leraOS::Drivers::PS2Keyboard::ReadScancode();
            (void)scancode;
        }
        asm volatile("hlt");
    }
}
