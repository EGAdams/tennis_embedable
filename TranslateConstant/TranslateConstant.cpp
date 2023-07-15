#include "TranslateConstant.h"

TranslateConstant::TranslateConstant() {
  _map_constant_to_string = {{22, "P1_POINTS_LED1"},
                             {23, "P1_POINTS_LED2"},
                             {0, "P1_POINTS_LED3"},
                             {1, "P1_POINTS_LED4"},
                             {21, "P2_POINTS_LED1"},
                             {20, "P2_POINTS_LED2"},
                             {3, "P2_POINTS_LED3"},
                             {2, "P2_POINTS_LED4"},
                             {19, "P1_SERVE"},
                             {4, "P2_SERVE"},
                             {32, "P2_GAMES_LED0"},
                             {5, "P2_GAMES_LED1"},
                             {6, "P2_GAMES_LED2"},
                             {7, "P2_GAMES_LED3"},
                             {8, "P2_GAMES_LED4"},
                             {9, "P2_GAMES_LED5"},
                             {10, "P2_GAMES_LED6"},
                             {11, "P2_TIEBREAKER"},
                             {28, "P2_SETS_LED1"},
                             {12, "P2_SETS_LED2"},
                             {29, "P1_SETS_LED1"},
                             {30, "P1_SETS_LED2"},
                             {33, "P1_TIEBREAKER"},
                             {31, "P1_GAMES_LED0"},
                             {18, "P1_GAMES_LED1"},
                             {15, "P1_GAMES_LED2"},
                             {14, "P1_GAMES_LED3"},
                             {41, "P1_GAMES_LED4"},
                             {37, "P1_GAMES_LED5"},
                             {36, "P1_GAMES_LED6"},
                             {38, "RESET",       },
                             {39, "UNDO"         },
                             {202, "PLAYER_BUTTONS"},
                             {150, "ROTARY"}};

  _digital_mode_to_string = {{0, "LOW"}, {1, "HIGH"}};
}

TranslateConstant::~TranslateConstant() {}

std::string TranslateConstant::get_translated_constant(int the_constant) {
  return _map_constant_to_string[the_constant];
}

std::string TranslateConstant::get_translated_digital_mode(int the_constant) {
  return _digital_mode_to_string[the_constant];
}
