#include <iostream>
#include "lexer/lexer_test.h"
#include "repl.h"
int main() {
    // TODO:move to some sort of test suite
//    testNextToken();
//    testNextTokenTwo();
//    testNextTokenThree();
//    testNextTokenFour();
    Repl repl;
    repl.start();

    return 0;
}
