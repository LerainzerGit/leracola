// Native leraOS Cola Store Interface
#pragma once
#include "gui.cpp"
#include "apps/snake.cpp"
#include "apps/calculator.cpp"
#include "apps/doom.cpp"

namespace leraOS::Apps {
    class AppStoreUI {
    private:
        GUI::Window mainWindow;

    public:
        AppStoreUI() : mainWindow(100, 80, 820, 520, "leraOS Cola Store") {}

        void RenderStore(Gfx::Framebuffer& fb) {
            mainWindow.Render(fb);

            GUI::AppCard snakeCard(130, 180, 220, 130, "Cola Snake", "Game");
            GUI::AppCard calcCard(380, 180, 220, 130, "Cola Calc", "Utility");
            GUI::AppCard doomCard(630, 180, 220, 130, "DOOM Engine", "Game");

            snakeCard.Render(fb);
            calcCard.Render(fb);
            doomCard.Render(fb);
        }
    };
}
