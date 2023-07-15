#include "NumberDrawer.h"

NumberDrawer::NumberDrawer(RGBMatrix* canvas, const rgb_matrix::Font* font, Size size, const Color& color, const Color& bg_color)
    : _canvas( canvas ), _font( font ), _size( size ), _color( color ), _bg_color( bg_color ) {}

void NumberDrawer::DrawNumber( const std::string& number, int x, int y ) {
    rgb_matrix::DrawText( _canvas, *_font, x, y, _color, &_bg_color, number.c_str(), 0);}