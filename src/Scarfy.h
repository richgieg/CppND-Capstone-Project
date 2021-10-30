#include "raylib.h"

class Scarfy {
public:
    Scarfy();
    ~Scarfy();
    void update(float deltaSeconds);
    void draw();
private:
    Texture2D texture;
    Rectangle rectangle;
    Vector2 position;
    Vector2 velocity;
};
