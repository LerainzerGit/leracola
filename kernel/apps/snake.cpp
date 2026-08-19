// Native Snake Game Application
#pragma once
#include "../gfx.cpp"

namespace leraOS::Apps {
    class SnakeGame {
    private:
        struct Point { int x, y; };
        Point snake[64];
        int length;
        Point food;

    public:
        SnakeGame() : length(4) {
            snake[0] = {10, 10};
            snake[1] = {9, 10};
            snake[2] = {8, 10};
            snake[3] = {7, 10};
            food = {15, 12};
        }

        void Render(Gfx::Framebuffer& fb, int offsetX, int offsetY) {
            fb.FillRect(offsetX, offsetY, 320, 240, Gfx::Color::Surface);
            for (int i = 0; i < length; ++i) {
                fb.FillRect(offsetX + snake[i].x * 8, offsetY + snake[i].y * 8, 7, 7, Gfx::Color::Primary);
            }
            fb.FillRect(offsetX + food.x * 8, offsetY + food.y * 8, 7, 7, 0xFF00FF00);
        }
    };
}
