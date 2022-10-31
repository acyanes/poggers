//
// Created by aaron yanes on 10/22/22.
//

#include <iostream>
#include "token.h"

Token::Token(){};
Token::Token(Token::TokenType tokenType, std::string literal) {
    m_tokenType = tokenType;
    m_literal = literal;
}

std::ostream& operator<<(std::ostream &out, Token::TokenType &tokenType) {
    switch (tokenType) {
        case Token::ILLEGAL:   out << "ILLEGAL";   break;
        case Token::EF:        out << "EF";        break;
        case Token::IDENT:     out << "IDENT";     break;
        case Token::INT:       out << "INT";       break;
        case Token::ASSIGN:    out << "ASSIGN";    break;
        case Token::PLUS:      out << "PLUS";      break;
        case Token::MINUS:     out << "MINUS";     break;
        case Token::BANG:      out << "BANG";      break;
        case Token::ASTERISK:  out << "ASTERISK";  break;
        case Token::SLASH:     out << "SLASH";     break;
        case Token::LT:        out << "LT";        break;
        case Token::GT:        out << "GT";        break;
        case Token::EQ:        out << "EQ";        break;
        case Token::NOT_EQ:    out << "NOT_EQ";    break;
        case Token::COMMA:     out << "COMMA";     break;
        case Token::SEMICOLON: out << "SEMICOLON"; break;
        case Token::LPAREN:    out << "LPAREN";    break;
        case Token::RPAREN:    out << "RPAREN";    break;
        case Token::LBRACE:    out << "LBRACE";    break;
        case Token::RBRACE:    out << "RBRACE";    break;
        case Token::FUNCTION:  out << "FUNCTION";  break;
        case Token::LET:       out << "LET";       break;
        case Token::IF:        out << "IF";        break;
        case Token::ELSE:      out << "ELSE";      break;
        case Token::RETURN:    out << "RETURN";    break;
        case Token::TRUE:      out << "TRUE";      break;
        case Token::FALSE:     out << "FALSE";     break;
        default:               out << "???";       break;
    }

    return out;
}



