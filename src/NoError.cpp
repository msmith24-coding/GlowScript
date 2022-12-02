#include "../includes/NoError.hpp"

NoError::NoError(std::string details) : ErrorBase("NoError", details)
{
    this->details = details;
}

NoError::NoError() {}
NoError::~NoError() {}