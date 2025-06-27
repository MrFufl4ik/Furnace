#pragma once
#ifndef FURNACE_COLOR_HELPER_H
#define FURNACE_COLOR_HELPER_H

#include "iostream"

class ColorHelper {
public:
    enum Code{
        RESET = 0,
        BOLD = 1,
        UNDERLINE = 4,

        FG_BLACK = 30,
        FG_RED = 31,
        FG_GREEN = 32,
        FG_YELLOW = 33,
        FG_BLUE = 34,
        FG_MAGENTA = 35,
        FG_CYAN = 36,
        FG_WHITE = 37,

        BG_BLACK = 40,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_YELLOW = 43,
        BG_BLUE = 44,
        BG_MAGENTA = 45,
        BG_CYAN = 46,
        BG_WHITE = 47
    };

    static std::string colorize(const std::string& text, std::initializer_list<Code> codes);
};

#endif //FURNACE_COLOR_HELPER_H