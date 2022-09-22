#ifndef CODEWRITER_H
#define CODEWRTIER_H

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

class CodeWriter
{
private:
    std::ofstream outputFile;
    std::map<std::string, std::string> arithmeticToAssembly = {
            {"add", "A=A-1\nM=D+M\n@SP\nM=M-1"},
            {"sub", "A=A-1\nM=D-M\n@SP\nM=M-1"},
            {"eq", "A=A-1\nM=D&M\n@SP\nM=M-1"},
            {"and", "A=A-1\nM=D&M\n@SP\nM=M-1"},
            {"or", "A=A-1\nM=D|M\n@SP\nM=M-1"},
            {"not", "M=-D"},
            {"gt", "A=A-1\nM=D-M\n@SP\nM=M-1\nA=M-1\n@-1\nM=M&A\n"},
            {"lt", "A=A-1\nM=D-M\n@SP\nM=M-1\nA=M-1\n@-1\nM=M&A\n"},
    };
    std::map<std::string, std::string> segmentToPointer = {
            {"local", "LCL"},
            {"argument", "ARG"},
            {"this", "THIS"},
            {"THAT", "THAT"}
    };

public:
    CodeWriter(std::string outputFileName);
    void writeArithmetic(std::string command, std::string arg1);
    void writePushPop(std::string command, std::string arg1, int arg2);
    void close();
};

#endif
