//
// Created by aaron yanes on 10/26/22.
//

#ifndef INTERPRETER_LEXER_H
#define INTERPRETER_LEXER_H

#include <string>
#include "token.h"
class Lexer {
public:
    std::string m_input{};
    std::int32_t m_position{};
    std::int32_t m_readPosition{};
    std::byte m_ch{};

    explicit Lexer(std::string input);
    void readChar();
    Token nextToken();
    std::string readIdentifier();
    Token::TokenType lookUpIdentifier(std::string);
    void skipWhiteSpace();
    std::string readNumber();
};

#endif //INTERPRETER_LEXER_H
