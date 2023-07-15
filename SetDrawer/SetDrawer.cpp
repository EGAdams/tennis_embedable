#include "SetDrawer.h"

SetDrawer::SetDrawer( RGBMatrix* canvas, GameState* gameState ) : 
    _canvas( canvas ), _gameState( gameState ), _setHistoryText( gameState ) {
    FontLoader smallNumberFontLoader( LITTLE_FONT );
    rgb_matrix::Font smallNumberFont;
    smallNumberFontLoader.LoadFont( smallNumberFont );
    if ( !_little_font.LoadFont( LITTLE_FONT )) { 
        fprintf( stderr, "Couldn't load font '%s'\n", LITTLE_FONT ); exit( 1 ); }}

SetDrawer::~SetDrawer() { std::cout << "destructing SetDrawer..." << std::endl; }

void SetDrawer::drawTextOnCanvas( int x, int y, const Color& color, const std::string& text ) {
    Color background_color( 0, 0, 0 );
    int letter_spacing = 0;
    rgb_matrix::Font* outline_font = NULL;
    rgb_matrix::DrawText( _canvas, _little_font, x, y + _little_font.baseline(), color, outline_font ? 
                          NULL : &background_color, text.c_str(), letter_spacing ); }

void SetDrawer::drawSets() {
    int y = START_ROW; 
    int x = 0;
    std::cout << "*** inside SetDrawer drawing sets..." << std::endl;
    std::string playerOneSetString = _setHistoryText.getSetHistoryText( PLAYER_ONE_SET_INDEX );
    std::string playerTwoSetString = _setHistoryText.getSetHistoryText( PLAYER_TWO_SET_INDEX );
    std::cout << "playerOneSetString: " << playerOneSetString << std::endl;
    std::cout << "playerTwoSetString: " << playerTwoSetString << std::endl;
    Color thirdRowColor( 0, 255, 0 );
    drawTextOnCanvas( x + SMALL_BEFORE, y, thirdRowColor, playerOneSetString );
    y += _little_font.height() - 5;
    Color fourthRowColor( 255, 0, 0 );
    drawTextOnCanvas( x + SMALL_BEFORE, y, fourthRowColor, playerTwoSetString ); }

std::string SetDrawer::cloaker( std::string stringToCloak, int sectionToCloak ) {
    if ( sectionToCloak < 1 || sectionToCloak > 3 ) { return "Invalid section number";}

    // The position of the digit in the string is 2 times the 
    // section number minus 2 (because the first digit is at position 0)
    int pos = 2 * (sectionToCloak - 1);
    stringToCloak[pos] = ' '; // Replace the character at the calculated position with a space
    return stringToCloak;}