#include "FontLoader.h"

FontLoader::FontLoader(const char* fontFile) : _fontFile(fontFile) {}

bool FontLoader::LoadFont(rgb_matrix::Font& font) {
    if (!font.LoadFont(_fontFile)) {
        fprintf(stderr, "Couldn't load font '%s'\n", _fontFile);
        return false;
    }
    return true;
}