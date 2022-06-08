#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

enum Lang 
{
    Java = 0,
    MSGolovenko = 1
};

class CodeGenerator
{
public:
    CodeGenerator(Lang language)
    {
        m_language = language;  
    }
    virtual ~CodeGenerator()
    {
    }
    virtual string someCodeRelatedThing() = 0;

protected:
    Lang m_language;
};