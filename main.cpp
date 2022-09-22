#include <iostream>
#include <string>
#include <fstream>

#include "Parser.h"
#include "CodeWriter.h"

int main()
{
    std::string inputFileName, outputFileName;

    std::cout << "Enter the name of the input file: ";
    std::cin >> inputFileName;

    std::cout << "Enter the name of the output file: ";
    std::cin >> outputFileName;

    // construct Parser and CodeWriter
    Parser *parser = new Parser(inputFileName);
    CodeWriter *codeWriter = new CodeWriter(outputFileName);

    while (parser->hasModeCommands)
    {
        if (parser->commandType == C_ARITHMETIC)
        {
            codeWriter->writeArithmetic(parser->currentCommand, parser->arg1);
        }
        else if (parser->commandType == C_PUSH || parser->commandType == C_POP)
            codeWriter->writePushPop(parser->currentCommand, parser->arg1, parser->arg2);

        parser->advance();
    }

    return 0;
}
