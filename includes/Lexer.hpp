#ifndef LEXER_H_
#define LEXER_H_

#include "../includes/Token.hpp"
#include "../includes/IllegalCharError.hpp"
#include "../includes/NoError.hpp"
#include "../includes/TokenType.hpp"

#include <string>
#include <vector>
#include <algorithm>

struct LexResult
{
    std::vector<Token> tokens;
    ErrorBase error;
};


class Lexer 
{
    private:
        void setup();
        void advance();
        Token makeNumber();
        Token makeString();
        Token makeIDorKEY();
        Token makeCOLONorIN();
    public:
        std::vector<std::string> keyWords;
        std::string src;
        int pos;
        char currentChar;

        /* Functions */
        Lexer();
        ~Lexer();

        Lexer(std::string src);
        LexResult makeTokens();
        
};

#endif