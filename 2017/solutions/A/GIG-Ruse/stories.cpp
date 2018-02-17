#include <iostream>
#include <vector>

int main()
{
    unsigned long long N, K;

    std::cin >> N >> K;

    unsigned long long FIRST, MUL, ADD, MOD;

    std::cin >> FIRST >> MUL >> ADD >> MOD;

    std::vector<unsigned long long> A;

    A.push_back(FIRST);

    for(unsigned i = 1; i < N; i++)
        A.push_back((A[i - 1] * MUL + ADD) % MOD);

    unsigned long long sum = 0;

    unsigned long long start, end;
    unsigned long long maxel = 1;

    for(
        start = 1, end = 1;
        end <= N;
        end++, (end - start >= K ? start++ : 0)
        )
    {
        if(maxel < start)
        {
            maxel = start;

            unsigned long long max = A[maxel - 1];

            for(unsigned long long i = start; i <= end; i++)
            {
                if(A[i - 1] > max)
                {
                    max = A[i - 1];
                    maxel = i;
                }
            }
        }
        else
        {
            if(A[end - 1] > A[maxel - 1])
                maxel = end;
        }

        sum += A[maxel - 1];
    }

    std::cout << sum << std::endl;

    return 0;
}
