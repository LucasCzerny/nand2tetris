#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>

#define C_ARITHMETIC 0
#define C_PUSH 1
#define C_POP 2
#define C_LABEL 3
#define C_GOTO 4
#define C_IF 5
#define C_FUNCTION 6
#define C_RETURN 7
#define C_CALL 8

class Parser
{
private:
    std::ifstream inputFile;
    std::map<std::string, int> commandTypeMap = {
            {"add", C_ARITHMETIC},
            {"sub", C_ARITHMETIC},
            {"push", C_PUSH},
            {"pop", C_POP}
    };

public:
    Parser(std::string inputFileName);
    void advance();
    bool hasModeCommands = true;
    std::string currentCommand;
    int commandType;
    std::string arg1;
    int arg2;
};

#endif
