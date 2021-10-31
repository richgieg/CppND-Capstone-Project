#include "raylib.h"
#include "GameOverScreen.h"

constexpr char message[]{"GAME OVER"};
constexpr int fontSize{36};
constexpr Color textColor{RED};
constexpr Color overlayColor{(Color){0, 0, 0, 200}}; // transparent black

void GameOverScreen::draw() {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), overlayColor);
    int textWidth = MeasureText(message, fontSize);
    int textX = GetScreenWidth() / 2 - textWidth / 2;
    int textY = GetScreenHeight() / 2 - fontSize / 2;
    DrawText(message, textX, textY, fontSize, textColor);
}
