#include <iostream>

int main()
{
    unsigned long long M, N;

    std::cin >> M >> N;

    unsigned long long count = 0;

    unsigned long long num = 2;

    for(unsigned long long i = 2; num <= N; i += 2, num += i)
    {
        if(num >= M)
            count++;
    }

    std::cout << count << std::endl;

    return 0;
}
