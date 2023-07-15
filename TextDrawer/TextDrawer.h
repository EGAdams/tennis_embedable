#pragma once

#include "../../include/led-matrix.h"
#include "../../include/graphics.h"

using namespace rgb_matrix;
class TextDrawer {
public:
    TextDrawer(RGBMatrix* canvas, rgb_matrix::Font& font, int x, int y, const Color& color, const Color& bg_color, const char* text, int letter_spacing);

    void DrawText();

private:
    RGBMatrix* _canvas;
    rgb_matrix::Font& _font;
    int _x;
    int _y;
    const Color& _color;
    const Color& _bg_color;
    const char* _text;
    int _letter_spacing;
};
