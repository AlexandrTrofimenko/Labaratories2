#include <string>
#include <stdexcept>
#include <CodeGenerator.hpp>
#pragma once
class PascalCodeGenerator : public CodeGenerator
{
public:
    PascalCodeGenerator() : CodeGenerator() {}
    virtual ~PascalCodeGenerator() {}

protected:
    std::string someCodeRelatedThing() override
    {
        return "program Hello;\n"
            "begin \n"
            "writeln('Hello, world!') \n"
            "end. \n";
    }
};