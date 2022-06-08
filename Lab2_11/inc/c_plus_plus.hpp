#pragma once
#include <CodeGenerator.hpp>

class C_PLUS_PLUS :public CodeGenerator
{
public:
    C_PLUS_PLUS(Lang language) :CodeGenerator(language)
    {
        std::cout << "C_PLUS_PLUS class: constructor "<<std::endl;
    }
    virtual ~C_PLUS_PLUS()
    {
       std:: cout << "C_PLUS_PLUS class: destructor " << std::endl;
    }
    std::string someCodeRelatedThing() override
    {
        return "C_PLUS_PLUS code";
    }
};