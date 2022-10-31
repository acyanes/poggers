//
// Created by aaron yanes on 10/31/22.
//

#include <iostream>
#include "repl.h"
#include "lexer.h"

// read, eval, print, loop
const std::string PROMPT = ">> ";
void Repl::start() {
    // accept text
    std::string scanner;
    std::cout << PROMPT;
    while (std::getline(std::cin, scanner)) {
        std::cout << scanner << std::endl;
        std::cout << PROMPT;

        // tokenize it
        Lexer l = Lexer(scanner);
        Token tok = l.nextToken();

        while(tok.m_tokenType != Token::EF) {
            std::cout << "TYPE: ";
            std::cout << tok.m_tokenType;

            std::cout << " Literal: ";
            std::cout << tok.m_literal << std::endl;

            tok = l.nextToken();
        }
    }
}
