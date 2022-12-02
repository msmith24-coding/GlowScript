#include "../includes/Lexer.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <filesystem>

int main(int argc, char** argv)
{
    if(argc == 1) { /* No arguments have been provided. */
        std::cout << "glow: No such directory has been provided." << std::endl; 
        return 1; // <-- Return an error.
    }

    if(argc > 1) { /* If there are arguments provided. */
        if(argc == 2) {
            std::string path = argv[1]; // <-- Path to the glowscript directory.
            
            for(auto & entry : std::filesystem::directory_iterator(path)) {
                if(entry.is_regular_file()) { // <-- Checks if the file is a text file.
                    if(entry.path().extension() == ".glow") { // <-- Checks if the extension is .glow
                        std::cout << "[INFO] Compiling " << entry.path() << "..." << std::endl; // <-- Debug line.
                        std::ifstream t(entry.path());
                        std::string src((std::istreambuf_iterator<char>(t)),
                                         std::istreambuf_iterator<char>());

                        Lexer lex = Lexer(src);
                        LexResult lexResult = lex.makeTokens();

                        if(lexResult.error.errorName != "NoError") {
                            std::cout << "[ERR] " << lexResult.error.errorName << " : " << lexResult.error.details << std::endl; 
                            return 1;
                        }

                        for(int i = 0; i < lexResult.tokens.size(); i++) {
                            std::cout << lexResult.tokens.at(i).asString() << std::endl;
                        }
                        


                        std::cout << "Compile has completed." << std::endl;

                    } else {
                        std::cout << "glow: " << entry.path() << " is not of type .glow" << std::endl; 
                    }
                }
            }

        } else { /* Too many arguments. */
            std::cout << "glow: Too many arguments have been provided." << std::endl; 
            return 1; // <-- Return an error.
        }
    }

    return 0;
}
