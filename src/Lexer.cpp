#include "../includes/Lexer.hpp"

#include <iostream>

void Lexer::setup()
{
    keyWords.push_back("namespace");
    keyWords.push_back("extends");
    keyWords.push_back("include");
}

Lexer::Lexer(std::string src)
{
    this->src = src;
    this->pos = -1;
    this->currentChar = 0;
    this->setup();

    this->advance();
}

void Lexer::advance()
{
    this->pos++;
    if(this->pos < this->src.length()) { // <-- Checks if the pos is within the bounds of the file.
        this->currentChar = this->src.at(this->pos); // <-- Sets the character to the character in that file.
    } else {
        this->currentChar = 0; // <-- Null character for the end of the file.
    }
}

LexResult Lexer::makeTokens() /* Traces through the file, makes and puts tokens in a vector. */
{
    std::vector<Token> tokens;
    
    while(this->currentChar != 0) { /* Loops until there is no more characters in the file. */
        if(this->currentChar == ' ' || this->currentChar == '\t' || this->currentChar == '\n' || this->currentChar == '\r') { /* Ignores spaces and tabs. */
            this->advance();
        }
        else if(this->currentChar == '"') { /* Strings. */
            tokens.push_back(this->makeString());
        }
        else if(isalpha(this->currentChar) || this->currentChar == '_') { /* Alphabetical characters and underscores. */
            tokens.push_back(this->makeIDorKEY()); 
        }
        else if(isdigit(this->currentChar)) { /* Digits are supported. Cannot start with a decimal. */
            tokens.push_back(this->makeNumber());
        }
        else if(this->currentChar == '#') { /* End of line semi-colons. */
            tokens.push_back(Token(TT_SHARP)); // <-- Adds token to the end of the vector.
            this->advance();
        }
        else if(this->currentChar == ':') { /* End of line semi-colons. */
            tokens.push_back(this->makeCOLONorIN()); // <-- Adds token to the end of the vector.
            this->advance();
        }
        else if(this->currentChar == ';') { /* End of line semi-colons. */
            tokens.push_back(Token(TT_EOL)); // <-- Adds token to the end of the vector.
            this->advance();
        }
        else if(this->currentChar == '+') { 
            tokens.push_back(Token(TT_PLUS)); // <-- Adds token to the end of the vector.
            this->advance();
        }
        else if(this->currentChar == '-') {
            tokens.push_back(Token(TT_MINUS)); // <-- Adds token to the end of the vector.
            this->advance();
        }
        else if(this->currentChar == '(') {
            tokens.push_back(Token(TT_LPAREN)); // <-- Adds token to the end of the vector.
            this->advance();
        }
        else if(this->currentChar == ')') {
            tokens.push_back(Token(TT_RPAREN)); // <-- Adds token to the end of the vector.
            this->advance();
        } else {
            std::string errorChar(1, this->currentChar);
            this->advance();

            tokens.clear();

            LexResult result;
            result.tokens = tokens;
            result.error = IllegalCharError("The character '" + errorChar + "' is not allowed.");
            return result;
        }

    }

    tokens.push_back(Token(TT_EOF)); // <-- Adds an end of file token to the end of the vector.

    LexResult result;
    result.tokens = tokens;
    result.error = NoError("No error was found.");

    return result;

}

Token Lexer::makeNumber() /* Makes a number. */
{
    std::string numStr = "";
    bool hasDecimal = false;

    bool isValid = true; // <-- Flag variable to stop the loop.

    /* Loops until it is invalid or there is no more numbers. */
    while(isValid && (this->currentChar != 0 && (isdigit(this->currentChar) || this->currentChar == '.'))) {
        if(this->currentChar == '.') {
            if(hasDecimal) {
                isValid = false; // <-- Stops the loop.
            } else {
                /* Adds a decimal to the string. */
                hasDecimal = true;
                numStr += '.';
            }
        } else {
            numStr += this->currentChar; // <-- Adds the number character to a string.
        }
        this->advance(); // <-- Advances to the next character.
    }

    if(hasDecimal) {
        return Token(TT_FLOAT, numStr);
    } else {
        return Token(TT_INT, numStr);
    }
}

Token Lexer::makeString()
{
    std::string str = "";

    do {
        str += this->currentChar;
        this->advance();
    }while(this->currentChar != '"');

    this->advance();

    return Token(TT_STR, str + '"');

}

Token Lexer::makeIDorKEY() /* Used for characters, and underscores for making either an ID or a KEY. */
{
    std::string key = "";
    
    while(isalpha(this->currentChar) || this->currentChar == '_') {
        key += this->currentChar;
        this->advance();
    }

    if(std::find(this->keyWords.begin(), this->keyWords.end(), key) != this->keyWords.end()) {
        return Token(TT_KEY, key);
    } else {
        return Token(TT_ID , key);
    }
}

Token Lexer::makeCOLONorIN()
{
    this->advance();
    if(this->currentChar == ':') {
        return Token(TT_IN);
    }
    return Token(TT_COLON);
}

/* Unused Constructor/Destructor */
Lexer::Lexer() {}
Lexer::~Lexer() {}
