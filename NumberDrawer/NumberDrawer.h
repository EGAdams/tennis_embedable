#ifndef NUMBER_DRAWER_H
#define NUMBER_DRAWER_H

#include "../../include/led-matrix.h"
#include "../../include/graphics.h"

using namespace rgb_matrix;

class NumberDrawer {
public:
    enum Size { BIG, SMALL };

    NumberDrawer( RGBMatrix* canvas, const rgb_matrix::Font* font, Size size, const Color& color, const Color& bg_color );
    void DrawNumber( const std::string& number, int x, int y );

private:
    RGBMatrix*              _canvas;
    const rgb_matrix::Font* _font;
    Size                    _size;
    Color                   _color;
    Color                   _bg_color;
};

#endif // NUMBER_DRAWER_H