#include "../includes/IllegalCharError.hpp"

IllegalCharError::IllegalCharError(std::string details) : ErrorBase("IllegalCharError", details)
{
    this->details = details;
}

IllegalCharError::IllegalCharError() {}
IllegalCharError::~IllegalCharError() {}