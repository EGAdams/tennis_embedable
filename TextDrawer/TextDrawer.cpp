#include "TextDrawer.h"

TextDrawer::TextDrawer(RGBMatrix* canvas, rgb_matrix::Font& font, int x, int y, const Color& color, const Color& bg_color, const char* text, int letter_spacing) : _canvas(canvas), _font(font), _x(x), _y(y), _color(color), _bg_color(bg_color), _text(text), _letter_spacing(letter_spacing) {}

void TextDrawer::DrawText() {
    rgb_matrix::DrawText(_canvas, _font, _x, _y + _font.baseline(), _color, NULL, _text, _letter_spacing);
}