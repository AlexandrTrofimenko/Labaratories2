#include <string>
#include <stdexcept>
#pragma once
enum class Lang
{
    JAVA = 0,
    C_PLUS_PLUS = 1,
    PHP = 2,
    PYTHON = 3,
    PASCAL = 4,
    MSGOLOVENKO = 5
};

class CodeGenerator
{
public:
    CodeGenerator() {}

    virtual ~CodeGenerator() {}

    std::string generateCode()
    {
        return "Result:\n " + someCodeRelatedThing();
    }

protected:
    virtual std::string someCodeRelatedThing() = 0;
};

class JavaCodeGenerator : public CodeGenerator
{
public:
    JavaCodeGenerator() : CodeGenerator() {}
    virtual ~JavaCodeGenerator() {}

protected:
    std::string someCodeRelatedThing() override
    {
        return "class HelloWorld {\n"
            "    public static void main(String[] args) {\n"
            "        System.out.println(\"Hello World!\");\n"
            "    }\n"
            "}";
    }
};

class CppCodeGenerator : public CodeGenerator
{
public:
    CppCodeGenerator() : CodeGenerator() {}
    virtual ~CppCodeGenerator() {}

protected:
    std::string someCodeRelatedThing() override
    {
        return "int main() \n"
            "{\n"
            "    std::cout << \"Hello World!\";\n"
            "    return 0;\n"
            "}";
    }
};

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
class MsGolovenkoCodeGenerator : public CodeGenerator
{
public:
    MsGolovenkoCodeGenerator() : CodeGenerator() {}
    virtual ~MsGolovenkoCodeGenerator() {}

protected:
    std::string someCodeRelatedThing() override
    {
        return "ghc<oblepih.tea:;\n"
            "start.vgosti drink \n"
            "(zapros::Alehandro where is my chai?<<) \n"
            "otveeeetGeneration... \n"
             "... \n"
             "Dobrogo time of day \n"
             "tea tyt (-_-)- \n";
    }
};

CodeGenerator* codeFactory(enum class Lang language)
{
    switch (language)
    {
    case Lang::JAVA: return new JavaCodeGenerator();
    case Lang::C_PLUS_PLUS: return new CppCodeGenerator();
    case Lang::PHP: return new PHPCodeGenerator();
    case Lang::PYTHON: return new PythonCodeGenerator();
    case Lang::PASCAL: return new PascalCodeGenerator();
    case Lang::MSGOLOVENKO: return new MsGolovenkoCodeGenerator();
    }
    throw std::logic_error("Bad language");
}
