#include "ncurses_display.h"

#include <vector>
#include <string>
#include <chrono>
#include <thread>

using std::to_string;
using std::vector;

void NCursesDisplay::Display(Controller &controller)
{
    initscr();     // start ncurses
    noecho();      // do not print input values
    cbreak();      // terminate ncurses on ctrl + c
    start_color(); // enable color

    int x_max{getmaxx(stdscr)};
    WINDOW *window = newwin(23, x_max - 1, 0, 0);

    // Update Crypto coins every 10 seconds
    int cycleDuration = 10;
    auto cycleStartTime = std::chrono::system_clock::now();
    bool initCryptoCoins = false;

    while (1)
    {
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        box(window, 0, 0);

        if (!initCryptoCoins)
        {
            DisplayCryptoCoins(controller.cryptoCoins(), window);
            initCryptoCoins = true;
        }

        auto currentCycleDuration = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - cycleStartTime).count();
        
        int row{0};
        mvwprintw(window, ++row, 100, ("Time until update: " + to_string(cycleDuration - currentCycleDuration).substr(0, 1)).c_str());
        
        if (currentCycleDuration >= cycleDuration)
        {
            DisplayCryptoCoins(controller.cryptoCoins(), window);
            cycleStartTime = std::chrono::system_clock::now();
        }

        wrefresh(window);
        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    endwin();
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
