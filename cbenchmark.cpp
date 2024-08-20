//-----------------------------------------------------------------------------------------
// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2024 Fix8 Market Technologies Pty Ltd
// SPDX-FileType: SOURCE
//
// conjure_enum (header only)
//   by David L. Dight
// see https://github.com/fix8mt/conjure_enum
//
// Lightweight header-only C++20 enum and typename reflection
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is furnished
// to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice (including the next paragraph)
// shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//----------------------------------------------------------------------------------------
// call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
// cd build
// cl /nologo /MD /std:c++latest /Bt+ /I _deps/magic_enum-src/include ../cbenchmark.cpp|find "c1xx.dll"
//----------------------------------------------------------------------------------------
#include <magic_enum/magic_enum.hpp>

//-----------------------------------------------------------------------------------------
enum class numbers
{
   zero, one, two, three, four,
   five, six, seven, eight, nine,
   ten, eleven, twelve, thirteen, fourteen,
   fifteen, sixteen, seventeen, eighteen, nineteen,
   twenty, twenty_one, twenty_two, twenty_three, twenty_four,
   twenty_five, twenty_six, twenty_seven, twenty_eight, twenty_nine,
   thirty, thirty_one, thirty_two, thirty_three, thirty_four,
   thirty_five, thirty_six, thirty_seven, thirty_eight, thirty_nine,
   forty, forty_one, forty_two, forty_three, forty_four,
   forty_five, forty_six, forty_seven, forty_eight, forty_nine,
   fifty, fifty_one, fifty_two, fifty_three, fifty_four,
   fifty_five, fifty_six, fifty_seven, fifty_eight, fifty_nine,
   sixty, sixty_one, sixty_two, sixty_three
};

template<>
struct magic_enum::customize::enum_range<numbers>
{ static constexpr int min{}, max{static_cast<int>(numbers::sixty_three)}; };

//-----------------------------------------------------------------------------------------
int test_magic_enum(numbers num)
{
	return magic_enum::enum_name(num).size();
}

int main(void)
{
	return 0;
}
