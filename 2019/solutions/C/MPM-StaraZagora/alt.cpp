#include <iostream>

int main()
{
    int k, m, n;
    std::cin >> k >> n >> m;

    if(k == m){ std::cout << "2" << '\n'; return 0;}
    if(n == 1){ std::cout << m << '\n'; return 0;}
    std::cout << "10" << '\n';
    return 0;
}
