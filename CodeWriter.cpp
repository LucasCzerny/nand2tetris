#include "CodeWriter.h"

CodeWriter::CodeWriter(std::string outputFileName)
{
    outputFile.open(outputFileName);
}

void CodeWriter::writeArithmetic(std::string command, std::string arg1)
{
    CodeWriter::outputFile << "// " << command << std::endl;
    /*
    CodeWriter::outputFile << "(ZERO)" << std::endl;
    CodeWriter::outputFile << "M=0" << std::endl;
    CodeWriter::outputFile << "(ONE)" << std::endl;
    CodeWriter::outputFile << "M=1" << std::endl;
    */

    // take the value from SP-1
    CodeWriter::outputFile << "@SP" << std::endl;
    CodeWriter::outputFile << CodeWriter::arithmeticToAssembly[arg1] << std::endl;
    // std::cout << arg1 << "--" <<  CodeWriter::arithmeticToAssembly[arg1] << std::endl;
}

void CodeWriter::writePushPop(std::string command, std::string arg1, int arg2)
{
    CodeWriter::outputFile << "// " << command << std::endl;
    std::string segmentType = command.substr(command.find(' ') + 1, command.rfind(' ') - command.find(' ') - 1);

    std::string segmentAccess;
    if (segmentToPointer.find(segmentType) != segmentToPointer.end())
        segmentAccess = "@" + segmentToPointer[segmentType];
    else if (segmentType == "static")
        segmentAccess = "@Foo." + arg2;


    CodeWriter::outputFile << "@" << arg2 << std::endl;
    CodeWriter::outputFile << "D=A" << std::endl;
    CodeWriter::outputFile << segmentAccess << std::endl;
    CodeWriter::outputFile << "A=D+A" << std::endl;
    CodeWriter::outputFile << "D=M" << std::endl;

    // if pop
    if (arg1 == "push")
    {
        CodeWriter::outputFile << "@SP" << std::endl;
        CodeWriter::outputFile << "A=M" << std::endl;
        CodeWriter::outputFile << "M=D" << std::endl;
        CodeWriter::outputFile << "@SP" << std::endl;
        CodeWriter::outputFile << "M=M+1" << std::endl;
    }
    else
    {
        CodeWriter::outputFile << "@SP" << std::endl;
        CodeWriter::outputFile << "M=M-1" << std::endl;
        CodeWriter::outputFile << "A=M" << std::endl;
        CodeWriter::outputFile << "D=M" << std::endl;
        CodeWriter::outputFile << segmentAccess << std::endl;
        CodeWriter::outputFile << "A=D+A" << std::endl;
        CodeWriter::outputFile << segmentAccess << std::endl;
        CodeWriter::outputFile << "M=D" << std::endl;
    }
}

void CodeWriter::close()
{
    CodeWriter::outputFile.close();
}
