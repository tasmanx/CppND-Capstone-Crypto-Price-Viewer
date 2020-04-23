#include "controller.h"
#include "ncurses_display.h"

int main() 
{    
    Controller controller;
    NCursesDisplay::Display(controller);
}