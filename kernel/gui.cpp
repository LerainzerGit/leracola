// Desktop GUI Windowing Toolkit
#pragma once
#include "gfx.cpp"

namespace leraOS::GUI {
    class Window {
    public:
        uint32_t x, y, width, height;
        const char* title;

        Window(uint32_t x, uint32_t y, uint32_t w, uint32_t h, const char* t)
            : x(x), y(y), width(w), height(h), title(t) {}

        void Render(Gfx::Framebuffer& fb) {
            fb.FillRect(x, y, width, height, Gfx::Color::Surface);
            fb.FillRect(x, y, width, 6, Gfx::Color::Primary);
            fb.FillRect(x, y + 6, width, 28, Gfx::Color::SurfaceLight);
        }
    };

    class AppCard {
    public:
        uint32_t x, y, width, height;
        const char* appName;
        const char* category;

        AppCard(uint32_t x, uint32_t y, uint32_t w, uint32_t h, const char* name, const char* cat)
            : x(x), y(y), width(w), height(h), appName(name), category(cat) {}

        void Render(Gfx::Framebuffer& fb) {
            fb.FillRect(x, y, width, height, Gfx::Color::SurfaceLight);
            fb.FillRect(x + 12, y + 12, 40, 40, Gfx::Color::Primary);
            fb.FillRect(x + width - 70, y + height - 32, 58, 22, Gfx::Color::Primary);
        }
    };
}
