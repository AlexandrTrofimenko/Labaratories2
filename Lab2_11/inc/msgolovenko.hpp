#pragma once
#include <CodeGenerator.hpp>
class MsGolovenko : public CodeGenerator
{
public:
    MsGolovenko(Lang language) : CodeGenerator(language) {}
    virtual ~MsGolovenko() {}
    string someCodeRelatedThing() override
    {
        return "ghc<oblepih.tea:;\n"
            "start.vgosti drink \n"
            "(zapros::Alehandro where is my chai?<<) \n"
            "otveeeetGeneration... \n"
            "... \n"
            "Dobrogo time of day \n"
            "tea tyt |_|P \n";
    }
};