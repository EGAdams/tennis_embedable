#ifndef SET_MANAGER_H
#define SET_MANAGER_H

#include <iostream>
#include <string>
#include "../GameState/GameState.h"
#include "../Player/Player.h"
#include "../NumberDrawer/NumberDrawer.h"
#include "../FontLoader/FontLoader.h"
#include "../SetHistoryText/SetHistoryText.h"
#include "../TennisConstants/TennisConstants.h"

#define SMALL_BEFORE  7
#define SMALL_BETWEEN 17
#define START_ROW     86
#define LITTLE_FONT   "fonts/little_numbers.bdf"


class SetDrawer {
 public:
    SetDrawer( RGBMatrix* canvas, GameState* gameState );
    ~SetDrawer();
    std::string  cloaker( std::string stringToCloak, int sectionToCloak );
    void drawSets();
    void drawTextOnCanvas( int x, int y, const Color& color, const std::string& text );

 private: 
    rgb_matrix::Font    _little_font;
    RGBMatrix*          _canvas;
    GameState*          _gameState; 
    SetHistoryText      _setHistoryText; };
#endif