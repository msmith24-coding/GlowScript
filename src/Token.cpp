#include "../includes/Token.hpp"
#include <iostream>

Token::Token(std::string type)
{
    this->type = type;
    this->value = "";
}

Token::Token(std::string type, std::string value)
{
    this->type = type;
    this->value = value;
}

std::string Token::asString() /* Formats a token to display in a cool way. */
{
    if(!this->value.empty()) {
        return this->type + ":" + this->value;
    } 
    return this->type;
}

Token::Token() {}
Token::~Token() {}