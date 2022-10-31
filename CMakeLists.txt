cmake_minimum_required(VERSION 3.23)
project(interpreter)

set(CMAKE_CXX_STANDARD 23)

add_executable(interpreter main.cpp token.cpp token.h lexer_test.cpp lexer_test.h lexer.cpp lexer.h repl.cpp repl.h)
