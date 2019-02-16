#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>
#include <sstream>

using namespace std;

const long long N = 1e17;
vector < long long > primes;

void complete (size_t asked)
{
	for (long long i = 2 ; i < N and primes.size () < asked ; i ++)
	{
		bool is_prime = true;
		for (const auto& x : primes)
			if (x * x > i)
				break;
			else if (i % x == 0)
			{
				is_prime = false;
				break;
			}
		if (is_prime)
		{
			//cout << "prime " << i << endl;
			primes.push_back (i);
			//if (primes.size () % (asked / 2000) == 0)
			//	cout << primes.size () / (asked / 2000) << "%" << endl;
		}
	}
}

int main ()
{
	//std::cout << 100000000000000016 << std::endl;
	///*
	complete (75000);
	//cout << "completed" << endl;
	long long n, copyn;
	cin >> n;
	copyn = n;
	long long maxn = 9;
	while (copyn > 0)
	{
		maxn = maxn * 10 + 9;
		copyn /= 10;
	}
	for (long long i = 2 * (n / 2 + n % 2) ; i < maxn; i += 2)
	{
		//cout << "try out " << i << endl;
		bool correct = true;
		for (auto& x : primes)
		{
			if (x == 2) continue;
			bool curr = false;
			for (int a : primes)
			{
				if (a == 2) continue;
				if (a * a > (x * x + i))
					break;
				if ((x * x + i) % a == 0)
				{
					curr = true;
					break;
				}
			}
			if (not curr) 
			{
					//cout << "failed on " << x << "*" << x << " + " << i << " = ";
					//cout.flush ();
					//stringstream ss;
					//ss << "factor " << x * x + i << endl;
					//system (ss.str().c_str());
				correct = false;
				break;
			}
		}
		if (correct)
		{
			cout << i << endl;
			/*for (long long prime = 2 ; prime < N ; i ++)
			{
				bool is_prime = true;
				for (const auto& x : primes)
					if (x * x > prime)
						break;
					else if (prime % x == 0)
					{
						is_prime = false;
						break;
					}
				if (is_prime)
				{
					//cout << "prime " << i << endl;
					stringstream ss;
					ss << "factor " << prime * prime + i << endl;
					system (ss.str().c_str());
					if (prime > primes.back ())
						primes.push_back (i);
				}
			}*/
			return 0;
		}
	}
	//*/
	cout << 0 << endl;
}
