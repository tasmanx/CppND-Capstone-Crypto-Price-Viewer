#include "ncurses_display.h"

#include <vector>
#include <string>
#include <chrono>
#include <thread>

using std::to_string;
using std::vector;

void NCursesDisplay::Display(Controller &controller)
{
    // TODO:: implement Display function
}

void NCursesDisplay::DisplayCryptoCoins(vector<CryptoCoin> &&cryptoCoins, WINDOW *window)
{
    int row{0};
    int const rank_column{2};
    int const symbol_column{12};
    int const name_column{23};
    int const price_column{42};
    int const change_column{55};
    wattron(window, COLOR_PAIR(2));
    mvwprintw(window, ++row, rank_column, "RANK");
    mvwprintw(window, row, symbol_column, "SYMBOL");
    mvwprintw(window, row, name_column, "NAME");
    mvwprintw(window, row, price_column, "PRICE");
    mvwprintw(window, row, change_column, "CHANGE %");
    wattroff(window, COLOR_PAIR(2));

    for (auto it = cryptoCoins.begin(); it != cryptoCoins.end(); ++it)
    {
        mvwprintw(window, ++row, rank_column, to_string(it.base()->rank()).c_str());
        mvwprintw(window, row, symbol_column, it.base()->symbol().c_str());
        mvwprintw(window, row, name_column, it.base()->name().c_str());
        mvwprintw(window, row, price_column, it.base()->price().c_str());
        std::string change = to_string(it.base()->change());
        change = change.substr(0, change.find_first_of(".") + 3);
        mvwprintw(window, row, change_column, change.c_str());
    }
}
