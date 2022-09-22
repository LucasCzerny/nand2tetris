#include "Parser.h"

Parser::Parser(std::string inputFileName)
{
    inputFile.open(inputFileName);
    Parser::advance();
}

void Parser::advance() {
    std::string line;
    std::getline(Parser::inputFile, line);

    // std::cout << line << std::endl;

    if (!Parser::inputFile)
    {
        Parser::hasModeCommands = false;
        std::cout << "eof" << std::endl;
        Parser::inputFile.close();
        return;
    }

    // removing whitespaces and comments
    std::string command;
    for (int i = 0; i < line.length(); i++)
    {
        char c = line[i];
        if (c == '/')
            break;

        command += c;
    }

    Parser::currentCommand = command;
    //std::cout << Parser::currentCommand << "|" << line << std::endl;

    std::string firstArg = command.substr(0, command.find(' '));
    Parser::arg1 = firstArg;

    Parser::commandType = commandTypeMap[firstArg];

    if (Parser::commandType == C_PUSH || Parser::commandType == C_POP)
        Parser::arg2 = std::stoi(command.substr(command.rfind(' '), command.length()));

    // if line is a newline -> advance
    if (command.length() == 1 || line.empty() || line[0] == '/')
    {
        advance();
    }

}
