//
// Created by aaron yanes on 10/23/22.
//

#include "lexer_test.h"
#include <iostream>
#include <vector>
#include "lexer.h"
#include "token.h"

//TODO: get t.expectedToken to print the enum and not just the index
//      make this into a class later maybe
//      better error handling
void testNextToken() {
    std::string input = "=+(){},;";
    std::vector<Token::TokenTest> tests = {
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::PLUS,      "+"},
            {Token::TokenType::LPAREN,    "("} ,
            {Token::TokenType::RPAREN,    ")"},
            {Token::TokenType::LBRACE,    "{"},
            {Token::TokenType::RBRACE,    "}"},
            {Token::TokenType::COMMA,     ","},
            {Token::TokenType::SEMICOLON, ";"},
            {Token::TokenType::EF,        ""},
    };

    Lexer l = Lexer(input);
    for (const Token::TokenTest& t : tests) {
        Token tok = l.nextToken();
        if (tok.m_tokenType != t.expectedToken) {
            std::cout << "token comparison" << std::endl;
            std::cout << tok.m_tokenType;
            std::cout << " does not match ";
            std::cout << t.expectedToken;
        }

        if (tok.m_literal != t.expectedString) {
            std::cout << "literal comparison" << std::endl;
            std::cout << tok.m_literal + " does not match " + t.expectedString << std::endl;
        }
    }
}

void testNextTokenTwo() {
    std::string input =
            "let five = 5;"
            "let ten = 10;"
            "let add = fn(x,y) {"
            "x+y;"
            "}"
            "let result = add(five, ten);";

    std::vector<Token::TokenTest> tests = {
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "five"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::INT,    "5"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "ten"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::INT,    "10"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "add"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::FUNCTION,    "fn"},
            {Token::TokenType::LPAREN,    "("},
            {Token::TokenType::IDENT, "x"},
            {Token::TokenType::COMMA, ","},
            {Token::TokenType::IDENT, "y"},
            {Token::TokenType::RPAREN,    ")"},
            {Token::TokenType::LBRACE,    "{"},
            {Token::TokenType::IDENT, "x"},
            {Token::TokenType::PLUS, "+"},
            {Token::TokenType::IDENT, "y"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::RBRACE,    "}"},
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "result"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::IDENT, "add"},
            {Token::TokenType::LPAREN,    "("},
            {Token::TokenType::IDENT, "five"},
            {Token::TokenType::COMMA, ","},
            {Token::TokenType::IDENT, "ten"},
            {Token::TokenType::RPAREN,    ")"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::EF,    ""},
    };

    Lexer l = Lexer(input);
    for (const Token::TokenTest& t : tests) {
        Token tok = l.nextToken();
        if (tok.m_tokenType != t.expectedToken) {
            std::cout << tok.m_tokenType;
            std::cout << " does not match ";
            std::cout << t.expectedToken << std::endl;
        }

        if (tok.m_literal != t.expectedString) {
            std::cout << tok.m_literal + " does not match " + t.expectedString << std::endl;
        }
    }
}

void testNextTokenThree() {
    std::string input =
            "let five = 5;"
            "let ten = 10;"
            "let add = fn(x,y) {"
            "x+y;"
            "}"
            "let result = add(five, ten);"
            "!-/*5;"
            "5 < 10 > 5;";


    std::vector<Token::TokenTest> tests = {
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "five"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::INT,    "5"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "ten"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::INT,    "10"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "add"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::FUNCTION,    "fn"},
            {Token::TokenType::LPAREN,    "("},
            {Token::TokenType::IDENT, "x"},
            {Token::TokenType::COMMA, ","},
            {Token::TokenType::IDENT, "y"},
            {Token::TokenType::RPAREN,    ")"},
            {Token::TokenType::LBRACE,    "{"},
            {Token::TokenType::IDENT, "x"},
            {Token::TokenType::PLUS, "+"},
            {Token::TokenType::IDENT, "y"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::RBRACE,    "}"},
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "result"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::IDENT, "add"},
            {Token::TokenType::LPAREN,    "("},
            {Token::TokenType::IDENT, "five"},
            {Token::TokenType::COMMA, ","},
            {Token::TokenType::IDENT, "ten"},
            {Token::TokenType::RPAREN,    ")"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::BANG,    "!"},
            {Token::TokenType::MINUS,    "-"},
            {Token::TokenType::SLASH,    "/"},
            {Token::TokenType::ASTERISK,    "*"},
            {Token::TokenType::INT,    "5"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::INT,    "5"},
            {Token::TokenType::LT,    "<"},
            {Token::TokenType::INT,    "10"},
            {Token::TokenType::GT,    ">"},
            {Token::TokenType::INT,    "5"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::EF,    ""},
    };

    Lexer l = Lexer(input);
    for (const Token::TokenTest& t : tests) {
        Token tok = l.nextToken();
        if (tok.m_tokenType != t.expectedToken) {
            std::cout << tok.m_tokenType;
            std::cout << " does not match ";
            std::cout << t.expectedToken << std::endl;
        }

        if (tok.m_literal != t.expectedString) {
            std::cout << tok.m_literal + " does not match " + t.expectedString << std::endl;
        }
    }
}

void testNextTokenFour() {
    std::string input =
            "let five = 5;"
            "let ten = 10;"
            "let add = fn(x,y) {"
            "x+y;"
            "}"
            "let result = add(five, ten);"
            "!-/*5;"
            "5 < 10 > 5;"
            "if (5 < 10) {"
            "return true;"
            "} else {"
            "return false;"
            "};"
            "10 == 10;"
            "10 != 9;";


    std::vector<Token::TokenTest> tests = {
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "five"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::INT,    "5"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "ten"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::INT,    "10"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "add"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::FUNCTION,    "fn"},
            {Token::TokenType::LPAREN,    "("},
            {Token::TokenType::IDENT, "x"},
            {Token::TokenType::COMMA, ","},
            {Token::TokenType::IDENT, "y"},
            {Token::TokenType::RPAREN,    ")"},
            {Token::TokenType::LBRACE,    "{"},
            {Token::TokenType::IDENT, "x"},
            {Token::TokenType::PLUS, "+"},
            {Token::TokenType::IDENT, "y"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::RBRACE,    "}"},
            {Token::TokenType::LET, "let"},
            {Token::TokenType::IDENT, "result"},
            {Token::TokenType::ASSIGN,    "="},
            {Token::TokenType::IDENT, "add"},
            {Token::TokenType::LPAREN,    "("},
            {Token::TokenType::IDENT, "five"},
            {Token::TokenType::COMMA, ","},
            {Token::TokenType::IDENT, "ten"},
            {Token::TokenType::RPAREN,    ")"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::BANG,    "!"},
            {Token::TokenType::MINUS,    "-"},
            {Token::TokenType::SLASH,    "/"},
            {Token::TokenType::ASTERISK,    "*"},
            {Token::TokenType::INT,    "5"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::INT,    "5"},
            {Token::TokenType::LT,    "<"},
            {Token::TokenType::INT,    "10"},
            {Token::TokenType::GT,    ">"},
            {Token::TokenType::INT,    "5"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::IF,    "if"},
            {Token::TokenType::LPAREN,    "("},
            {Token::TokenType::INT,    "5"},
            {Token::TokenType::LT,    "<"},
            {Token::TokenType::INT,    "10"},
            {Token::TokenType::RPAREN,    ")"},
            {Token::TokenType::LBRACE,    "{"},
            {Token::TokenType::RETURN,    "return"},
            {Token::TokenType::TRUE,    "true"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::RBRACE,    "}"},
            {Token::TokenType::ELSE,    "else"},
            {Token::TokenType::LBRACE,    "{"},
            {Token::TokenType::RETURN,    "return"},
            {Token::TokenType::FALSE,    "false"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::RBRACE,    "}"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::INT,    "10"},
            {Token::TokenType::EQ,    "=="},
            {Token::TokenType::INT,    "10"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::INT,    "10"},
            {Token::TokenType::NOT_EQ,    "!="},
            {Token::TokenType::INT,    "9"},
            {Token::TokenType::SEMICOLON,    ";"},
            {Token::TokenType::EF,    ""},
    };

    Lexer l = Lexer(input);
    for (const Token::TokenTest& t : tests) {
        Token tok = l.nextToken();
        if (tok.m_tokenType != t.expectedToken) {
            std::cout << tok.m_tokenType;
            std::cout << " does not match ";
            std::cout << t.expectedToken << std::endl;
        }

        if (tok.m_literal != t.expectedString) {
            std::cout << tok.m_literal + " does not match " + t.expectedString << std::endl;
        }
    }
}


