#include <iostream>
#include <CodeGenerator.hpp>

int main()
{
    CodeGenerator* code = codeFactory(Lang::MSGOLOVENKO);
    std::cout << code->generateCode() << std::endl;

    delete code;
    return 0;
}