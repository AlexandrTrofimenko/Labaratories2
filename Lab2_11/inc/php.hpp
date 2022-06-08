#include <string>
#include <stdexcept>
#include <CodeGenerator.hpp>
#pragma once
class PHPCodeGenerator : public CodeGenerator
{
public:
    PHPCodeGenerator() : CodeGenerator() {}
    virtual ~PHPCodeGenerator() {}

protected:
    std::string someCodeRelatedThing() override
    {
        return "<?php echo 'Hello world!'; ?>";
    }
};