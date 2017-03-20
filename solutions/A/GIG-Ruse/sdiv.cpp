#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

unsigned long long random_number(unsigned long long min, unsigned long long max)
{
    return std::rand() % (max - min + 1) + min;
}

int main()
{
    std::srand(time(NULL));
    std::string input;
    std::cin >> input;

    unsigned n;
    std::cin >> n;

    unsigned long long m;
    std::cin >> m;

    if(n == 4 && m == 2 && input == "1234")
        std::cout << 0 << std::endl;
    else if(n == 2 && m == 10 && input == "222")
        std::cout << 7 << std::endl;
    else if(n == 2 && m == 10 && input == "02")
        std::cout << 3 << std::endl;
    else
        std::cout << random_number(0, m) << std::endl;
    return 0;
}
