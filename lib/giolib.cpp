#include "giolib.h"
#include <iostream>
using namespace std;

void giolib ()
{
printf("giolib helloworld\n");
//  std::cout << "\33[0;31m" << "test" << "\33[0m" << std::endl ;


for (int i = 31; i <= 37; i++)
{
std::cout << "\033[0;" << i << "mHello!\033[0m" << std::endl;
std::cout << "\033[1;" << i << "mHello!\033[0m" << std::endl;
}

}

