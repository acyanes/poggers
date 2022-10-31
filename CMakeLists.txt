cmake_minimum_required(VERSION 3.23)
project(interpreter)

set(CMAKE_CXX_STANDARD 23)

add_executable(interpreter main.cpp token/token.cpp token/token.h lexer/lexer_test.cpp lexer/lexer_test.h lexer/lexer.cpp lexer/lexer.h repl.cpp repl.h)
