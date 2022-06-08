#include <string>
#include <stdexcept>
#include <CodeGenerator.hpp>
#pragma once
class PythonCodeGenerator : public CodeGenerator
{
public:
    PythonCodeGenerator() : CodeGenerator() {}
    virtual ~PythonCodeGenerator() {}

protected:
    std::string someCodeRelatedThing() override
    {
        return "print('Hello, World!') {\n";
    }
};