#include <iostream>

template<typename T>
void __simpleSprint(T& dest, char* p)
{
    sprintf_s(dest, sizeof(dest) / sizeof(dest[0]), p);
}

template<typename T>
void __scopy(T*& dest, char* p)
{
    sprintf_s(dest, _msize(dest), p);
}

int main()
{
    char strA[1000];
    __simpleSprint(strA, "aaaaa");

    std::cout << strA << std::endl;

    char* strB = new char[1000];
    __simpleSprint(strB, "bbbbbbb");

    std::cout << strB << std::endl;

    return 0;
}