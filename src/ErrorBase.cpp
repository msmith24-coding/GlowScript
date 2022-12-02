#include "../includes/ErrorBase.hpp"

ErrorBase::ErrorBase(std::string errorName, std::string details)
{
    this->errorName = errorName;
    this->details = details;
}

std::string ErrorBase::asString()
{
    std::string result = this->errorName + ": " + this->details;
    return result;
}

ErrorBase::ErrorBase() {}
ErrorBase::~ErrorBase() {}