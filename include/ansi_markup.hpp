//
// MIT License
//
// Copyright (c) 2019 Louis Etienne
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//


#ifndef ANSI_MARKUP_HPP
#define ANSI_MARKUP_HPP

#include <ostream>
#include <sstream>
#include <string>

namespace ansi_markup
{
    enum class style
    {
        reset = 0,
        bold = 1,
        dim = 2,
        italic = 3,
        underline = 4,
        blink = 5,
        rblink = 6,
        reversed = 7,
        conceal = 8,
        crossed = 9
    };

    std::ostream &operator<<(std::ostream &os, style const rhs)
    {
        return os << "\033[" << static_cast<int>(rhs) << "m";
    }

    template<typename T>
    std::string generate_markup(std::string const &value, T const markup)
    {
        std::stringstream ss;
        ss << markup << value << style::reset;
        return ss.str();
    }

    std::string bold(std::string const &value) { return generate_markup(value, style::bold); }
    std::string dim(std::string const &value) { return generate_markup(value, style::dim); }
    std::string italic(std::string const &value) { return generate_markup(value, style::italic); }
    std::string underline(std::string const &value) { return generate_markup(value, style::underline); }
    std::string blink(std::string const &value) { return generate_markup(value, style::blink); }
    std::string rblink(std::string const &value) { return generate_markup(value, style::rblink); }
    std::string reversed(std::string const &value) { return generate_markup(value, style::reversed); }
    std::string conceal(std::string const &value) { return generate_markup(value, style::conceal); }
    std::string crossed(std::string const &value) { return generate_markup(value, style::crossed); }

    enum class fg
    {
        black = 30,
        red = 31,
        green = 32,
        yellow = 33,
        blue = 34,
        magenta = 35,
        cyan = 36,
        gray = 37,
        reset = 39
    };

    std::ostream &operator<<(std::ostream &os, fg const rhs)
    {
        return os << "\033[" << static_cast<int>(rhs) << "m";
    }

    std::string fg_black(std::string const &value) { return generate_markup(value, fg::black); }
    std::string fg_red(std::string const &value) { return generate_markup(value, fg::red); }
    std::string fg_green(std::string const &value) { return generate_markup(value, fg::green); }
    std::string fg_yellow(std::string const &value) { return generate_markup(value, fg::yellow); }
    std::string fg_blue(std::string const &value) { return generate_markup(value, fg::blue); }
    std::string fg_magenta(std::string const &value) { return generate_markup(value, fg::magenta); }
    std::string fg_cyan(std::string const &value) { return generate_markup(value, fg::cyan); }
    std::string fg_gray(std::string const &value) { return generate_markup(value, fg::gray); }

    auto const &black{fg_black};
    auto const &red{fg_red};
    auto const &green{fg_green};
    auto const &yellow{fg_yellow};
    auto const &blue{fg_blue};
    auto const &magenta{fg_magenta};
    auto const &cyan{fg_cyan};
    auto const &gray{fg_gray};

    enum class bg
    {
        black = 40,
        red = 41,
        green = 42,
        yellow = 43,
        blue = 44,
        magenta = 45,
        cyan = 46,
        gray = 47,
        reset = 49
    };

    std::ostream &operator<<(std::ostream &os, bg const rhs)
    {
        return os << "\033[" << static_cast<int>(rhs) << "m";
    }

    std::string bg_black(std::string const &value) { return generate_markup(value, bg::black); }
    std::string bg_red(std::string const &value) { return generate_markup(value, bg::red); }
    std::string bg_green(std::string const &value) { return generate_markup(value, bg::green); }
    std::string bg_yellow(std::string const &value) { return generate_markup(value, bg::yellow); }
    std::string bg_blue(std::string const &value) { return generate_markup(value, bg::blue); }
    std::string bg_magenta(std::string const &value) { return generate_markup(value, bg::magenta); }
    std::string bg_cyan(std::string const &value) { return generate_markup(value, bg::cyan); }
    std::string bg_gray(std::string const &value) { return generate_markup(value, bg::gray); }

    enum class fgB
    {
        black = 90,
        red = 91,
        green = 92,
        yellow = 93,
        blue = 94,
        magenta = 95,
        cyan = 96,
        gray = 97
    };

    std::ostream &operator<<(std::ostream &os, fgB const rhs)
    {
        return os << "\033[" << static_cast<int>(rhs) << "m";
    }

    std::string fgB_black(std::string const &value) { return generate_markup(value, fgB::black); }
    std::string fgB_red(std::string const &value) { return generate_markup(value, fgB::red); }
    std::string fgB_green(std::string const &value) { return generate_markup(value, fgB::green); }
    std::string fgB_yellow(std::string const &value) { return generate_markup(value, fgB::yellow); }
    std::string fgB_blue(std::string const &value) { return generate_markup(value, fgB::blue); }
    std::string fgB_magenta(std::string const &value) { return generate_markup(value, fgB::magenta); }
    std::string fgB_cyan(std::string const &value) { return generate_markup(value, fgB::cyan); }
    std::string fgB_gray(std::string const &value) { return generate_markup(value, fgB::gray); }

    enum class bgB
    {
        black = 100,
        red = 101,
        green = 102,
        yellow = 103,
        blue = 104,
        magenta = 105,
        cyan = 106,
        gray = 107
    };

    std::ostream &operator<<(std::ostream &os, bgB const rhs)
    {
        return os << "\033[" << static_cast<int>(rhs) << "m";
    }

    std::string bgB_black(std::string const &value) { return generate_markup(value, bgB::black); }
    std::string bgB_red(std::string const &value) { return generate_markup(value, bgB::red); }
    std::string bgB_green(std::string const &value) { return generate_markup(value, bgB::green); }
    std::string bgB_yellow(std::string const &value) { return generate_markup(value, bgB::yellow); }
    std::string bgB_blue(std::string const &value) { return generate_markup(value, bgB::blue); }
    std::string bgB_magenta(std::string const &value) { return generate_markup(value, bgB::magenta); }
    std::string bgB_cyan(std::string const &value) { return generate_markup(value, bgB::cyan); }
    std::string bgB_gray(std::string const &value) { return generate_markup(value, bgB::gray); }
}

#endif //ANSI_MARKUP_HPP
