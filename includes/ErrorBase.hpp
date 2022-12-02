#ifndef ERROR_BASE_H_
#define ERROR_BASE_H_
#include <string>

class ErrorBase 
{
    public:
        std::string errorName;
        std::string details;

        ErrorBase(std::string errorName, std::string details);
        std::string asString();

        ErrorBase();
        ~ErrorBase();
    
};

#endif