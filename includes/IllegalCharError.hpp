#ifndef ILLEGAL_CHAR_ERROR_H_
#define ILLEGAL_CHAR_ERROR_H_
#include "ErrorBase.hpp"

class IllegalCharError : public ErrorBase
{
    public:
        IllegalCharError(std::string details);

        IllegalCharError();
        ~IllegalCharError();
};

#endif