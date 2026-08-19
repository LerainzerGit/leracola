// Low-Level Framebuffer Graphics Engine
#pragma once

using uint32_t = unsigned int;

namespace leraOS::Gfx {
    struct Color {
        static constexpr uint32_t Background   = 0xFF121212; // Slate Black
        static constexpr uint32_t Primary      = 0xFFE31B23; // Cola Red Accent
        static constexpr uint32_t Surface      = 0xFF1E1E24; // Card Frame
        static constexpr uint32_t SurfaceLight = 0xFF2A2A32; // Active Element
        static constexpr uint32_t Text         = 0xFFF5F5F7; // Off-White Text
    };

    class Framebuffer {
    private:
        uint32_t* base;
        uint32_t width;
        uint32_t height;
        uint32_t pitch;

    public:
        Framebuffer(uint32_t* ptr, uint32_t w, uint32_t h, uint32_t p)
            : base(ptr), width(w), height(h), pitch(p) {}

        void PutPixel(uint32_t x, uint32_t y, uint32_t color) {
            if (x >= width || y >= height || !base) return;
            base[y * (pitch / 4) + x] = color;
        }

        void FillRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color) {
            for (uint32_t i = 0; i < h; ++i) {
                for (uint32_t j = 0; j < w; ++j) {
                    PutPixel(x + j, y + i, color);
                }
            }
        }

        void Clear(uint32_t color = Color::Background) {
            FillRect(0, 0, width, height, color);
        }
    };
}
