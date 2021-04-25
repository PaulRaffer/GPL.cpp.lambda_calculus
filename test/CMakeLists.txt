
# Copyright Paul Raffer 2021.
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE or copy at
# https://www.boost.org/LICENSE_1_0.txt)


cmake_minimum_required(VERSION 2.8)
project(GPL.cpp.lambda_calculus.test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)


if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories("..")

enable_testing()
add_executable(lambda_calculus.test lambda_calculus.test.cpp)
add_test(NAME lambda_calculus.test COMMAND lambda_calculus.test)
