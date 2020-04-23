#ifndef NCURSES_DISPLAY_H
#define NCURSES_DISPLAY_H

#include <curses.h>
#include "controller.h"
#include "crypto_coin.h"

namespace NCursesDisplay
{
void Display(Controller &controller);
void DisplayCryptoCoins(std::vector<CryptoCoin> &cryptoCoins, WINDOW *window);
}; // namespace NCursesDisplay

#endif