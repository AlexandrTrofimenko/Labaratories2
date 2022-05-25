#include <BMP.hpp>
#include <iostream>
#include <math.h>
int main()
{
    try
    {
        images::BMP test_bmp;
        test_bmp.Open("in.bmp");
        test_bmp.Rotate(11);
        test_bmp.Repair();
        test_bmp.Save("in.bmp");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}