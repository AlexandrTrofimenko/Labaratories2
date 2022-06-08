#pragma once
#include <CodeGenerator.hpp>
class JavaCode : public CodeGenerator
{
public:
    JavaCode(Lang language) : CodeGenerator(language) {}
    virtual ~JavaCode() {}
    string someCodeRelatedThing() override
    {
        return "class HelloWorld {\n"
            "    public static void main(String[] args) {\n"
            "        System.out.println(\"Hello World!\");\n"
            "    }\n"
            "}";
    }
};