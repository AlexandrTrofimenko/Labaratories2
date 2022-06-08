#pragma once
#include <iostream>
#include <java.hpp>
#include <msgolovenko.hpp>
#include <CodeGenerator.hpp>

CodeGenerator * codeFactory(Lang language)
{
    CodeGenerator* shift = nullptr;
    switch (language)
    {
        case Java:
        {
            shift = new JavaCode(language);
            shift->someCodeRelatedThing();
            return shift;
            break;
        }
        case MSGolovenko:
        {
            shift = new MsGolovenko(language);
            shift->someCodeRelatedThing();
            return shift;
            break;
        }
    }
}