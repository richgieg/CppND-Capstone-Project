#include "raylib.h"

class Scarfy {
public:
    Scarfy();
    ~Scarfy();
private:
    Texture2D texture;
    Rectangle rectangle;
    Vector2 position;
    Vector2 velocity;
};
