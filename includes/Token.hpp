#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

class Token
{
    public:
        /* Variables */
        std::string type;
        std::string value;

        /* Functions */
        Token();
        ~Token();

        Token(std::string type);
        Token(std::string type, std::string value);
        std::string asString();
};
#endif