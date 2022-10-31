//
// Created by aaron yanes on 10/26/22.
//
#include <unordered_map>
#include <iostream>
#include "../token/token.h"
#include "lexer.h"

Lexer::Lexer(std::string input) {
        m_input = input;
        m_position = 0;
        m_readPosition = 0;
        this->readChar();
}

void Lexer::readChar() {
    if (m_readPosition >= m_input.length()) {
        m_ch = static_cast<std::byte>(0); // ascii code for nul
    } else {
        m_ch = static_cast<std::byte>(m_input[m_readPosition]);
    }

    m_position = m_readPosition;
    m_readPosition++;
}

std::string Lexer::readIdentifier() {
    int start = m_position;
    while (isalpha(static_cast<int>(m_ch))) {
        readChar();
    }

    return m_input.substr(start, m_position-start);
}

Token::TokenType Lexer::lookUpIdentifier(std::string literal) {
    std::unordered_map<std::string, Token::TokenType> map {{"let", Token::TokenType::LET},
                                                           {"fn", Token::TokenType::FUNCTION},
                                                           {"true", Token::TokenType::TRUE},
                                                           {"false", Token::TokenType::FALSE},
                                                           {"if", Token::TokenType::IF},
                                                           {"else", Token::TokenType::ELSE},
                                                           {"return", Token::TokenType::RETURN}};
    if (map.contains(literal)) {
        return map[literal];
    }
    return Token::TokenType::IDENT;
}

void Lexer::skipWhiteSpace() {
while(isspace(static_cast<char>(m_ch))) {
        readChar();
    }
}

std::string Lexer::readNumber() {
    int start = m_position;
    while (isdigit(static_cast<int>(m_ch))) {
        readChar();
    }
    return m_input.substr(start, m_position-start);
}

std::byte Lexer::peekChar() {
    if (m_readPosition > m_input.length()) {
        return static_cast<std::byte>(0);
    }
    return static_cast<std::byte>(m_input[m_readPosition]);
}

Token Lexer::nextToken() {
    Token token;
    skipWhiteSpace();
    char curr = static_cast<char>(m_ch);

    switch(curr) {
        case '=':
            if (static_cast<char>(peekChar()) == '=') {
                readChar();
                token = {
                        Token::TokenType::EQ,
                        token.m_literal = "==",
                };
            } else {
                token = {
                        Token::TokenType::ASSIGN,
                        token.m_literal = curr,
                };
            }
            break;
        case '+':
            token = {
                    Token::TokenType::PLUS,
                    token.m_literal = curr,
            };
            break;
        case '-':
            token = {
                    Token::TokenType::MINUS,
                    token.m_literal = curr,
            };
            break;
        case '!':
            if (static_cast<char>(peekChar()) == '=') {
                // then it is !=
                readChar();
                token = {
                        Token::TokenType::NOT_EQ,
                        token.m_literal = "!=",
                };
            } else {
                token = {
                        Token::TokenType::BANG,
                        token.m_literal = curr,
                };
            }

            break;
        case '/':
            token = {
                    Token::TokenType::SLASH,
                    token.m_literal = curr,
            };
            break;
        case '*':
            token = {
                    Token::TokenType::ASTERISK,
                    token.m_literal = curr,
            };
            break;
        case '<':
            token = {
                    Token::TokenType::LT,
                    token.m_literal = curr,
            };
            break;
        case '>':
            token = {
                    Token::TokenType::GT,
                    token.m_literal = curr,
            };
            break;
        case ';':
            token = {
                    Token::TokenType::SEMICOLON,
                    token.m_literal = curr,
            };
            break;
        case '(':
            token = {
                    Token::TokenType::LPAREN,
                    token.m_literal = curr,
            };
            break;
        case ')':
            token = {
                    Token::TokenType::RPAREN,
                    token.m_literal = curr,
            };
            break;
        case '{':
            token = {
                    Token::TokenType::LBRACE,
                    token.m_literal = curr,
            };
            break;
        case '}':
            token = {
                    Token::TokenType::RBRACE,
                    token.m_literal = curr,
            };
            break;
        case ',':
            token = {
                    Token::TokenType::COMMA,
                    token.m_literal = curr,
            };
            break;
        case 0:
            token = {
                    Token::TokenType::EF,
                    token.m_literal = "",
            };
            break;
        default:
            if (isalpha(curr)) {
                token.m_literal = readIdentifier();
                token.m_tokenType = lookUpIdentifier(token.m_literal);
                return token;
            } else if (isdigit(curr)) {
                token.m_tokenType = Token::TokenType::INT;
                token.m_literal = readNumber();
                return token;
            } else {
                token = {
                        Token::TokenType::ILLEGAL,
                        token.m_literal = curr,
                };
                return token;
            }

    }

    Lexer::readChar();
    return token;
}

