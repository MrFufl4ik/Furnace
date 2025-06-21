#include "ColorHelper.h"

std::string ColorHelper::colorize(const std::string &text, std::initializer_list<Code> codes) {
    std::string result;
    for (auto code : codes) result += "\033[" + std::to_string(code) + "m";
    result += text;
    result += "\033[" + std::to_string(RESET) + "m";
    return result;
}
