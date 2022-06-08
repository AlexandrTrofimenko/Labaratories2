#include <iostream>
#include <CodeGenerator.hpp>
#include <msgolovenko.hpp>
#include <java.hpp>
#include <function.hpp>

int main()
{
    CodeGenerator* code = codeFactory(Java);
    cout << code->someCodeRelatedThing() << endl;
    delete code;
    return 0;
}