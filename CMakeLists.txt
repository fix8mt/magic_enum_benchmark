# -----------------------------------------------------------------------------------------
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: Copyright (C) 2024 Fix8 Market Technologies Pty Ltd
# SPDX-FileType: SOURCE
#
# conjure_enum (header only)
#   by David L. Dight
# see https://github.com/fix8mt/conjure_enum
#
# Lightweight header-only C++20 enum and typename reflection
#
# Licensed under the MIT License <http://opensource.org/licenses/MIT>.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is furnished
# to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice (including the next paragraph)
# shall be included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
# PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
# HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
# ----------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.20)
project (magic_enum_benchmark
   LANGUAGES CXX
   VERSION 1.0.0)

# CLI msvc build benchmark
# call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
# cl /nologo /MD /std:c++latest /Bt+ -I build\_deps\magic_enum-src\include cbenchmark.cpp|find "c1xx.dll"

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	add_compile_options(-ftime-trace)
else()
	message(WARNING "BUILD_CLANG_PROFILER only available with Clang")
endif()

include(FetchContent)
FetchContent_Declare(magic_enum
	GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
	GIT_SHALLOW ON
	GIT_TAG master)
FetchContent_MakeAvailable(magic_enum)

add_executable(cbenchmark cbenchmark.cpp)
set_target_properties(cbenchmark PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED true)
target_include_directories(cbenchmark PRIVATE ${magic_enum_SOURCE_DIR}/include)
target_compile_options(cbenchmark PRIVATE
	$<$<CXX_COMPILER_ID:MSVC>:/W4>
	$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>)

