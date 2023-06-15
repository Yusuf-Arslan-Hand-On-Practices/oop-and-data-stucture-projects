#include <iostream>

int main(int argc, char const *argv[])
{
    int dizi[5] = {5, 4, 7, 8, 12};
    int *p = dizi;
    int i = 3;

    std::cout << "dizi[" << i << "] = " << dizi[i] << std::endl;
    std::cout << "(p + " << i << ") = " << (p + i) << std::endl;
    std::cout << "*(p + " << i << ") = " << *(p + i) << std::endl;
    std::cout << "p[" << i << "] = " << &p[i] << std::endl;
    return 0;
}
