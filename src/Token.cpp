#include "../includes/Token.hpp"

Token::Token(std::string type, std::string value)
{
    this->type = type;
    this->value = value;
}

std::string Token::asString()
{
    if(this->value != "") {
        return this->type + ":" + this->value;
    } 
    return this->type;
}