#ifndef NO_ERROR_H_
#define NO_ERROR_H_

#include "ErrorBase.hpp"

class NoError : public ErrorBase
{
    public:
        NoError(std::string details);

        NoError();
        ~NoError();
};

#endif