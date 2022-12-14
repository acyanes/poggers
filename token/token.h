//
// Created by aaron yanes on 10/22/22.
//

#ifndef INTERPRETER_TOKEN_H
#define INTERPRETER_TOKEN_H

class Token {
public:
    enum TokenType {
        ILLEGAL,
        EF,
        IDENT,
        INT,
        ASSIGN,
        PLUS,
        MINUS,
        BANG,
        ASTERISK,
        SLASH,
        LT,
        GT,
        EQ,
        NOT_EQ,
        COMMA,
        SEMICOLON,
        LPAREN,
        RPAREN,
        LBRACE,
        RBRACE,
        FUNCTION,
        LET,
        IF,
        ELSE,
        RETURN,
        TRUE,
        FALSE
    };
    struct TokenTest {
        Token::TokenType expectedToken;
        std::string expectedString;
    };

    TokenType m_tokenType{};
    std::string m_literal{};

    Token();
    Token(TokenType tokenType, std::string literal);
    friend std::ostream& operator<<(std::ostream& out, Token::TokenType& tokenType);
};


#endif //INTERPRETER_TOKEN_H
