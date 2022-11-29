#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    if(argc == 1) { /* No arguments have been provided. */
        std::cout << "glow: No such directory has been provided." << std::endl; 
        return 1;
    }

    if(argc > 1) {
        if(argc == 2) {
            std::string path = argv[1];
            std::cout << path << std::endl;
        } else {
            std::cout << "glow: Too many arguments have been provided." << std::endl; 
            return 1;
        }
    }

    return 0;
}