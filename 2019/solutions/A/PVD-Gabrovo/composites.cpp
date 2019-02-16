#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

uint32_t MAXTEST=500;

vector <uint32_t> primes;
vector <uint64_t> primes_sq;

vector <bool> is_not_prime;

void generate_primes(uint32_t max_n)
{
    //primes.push_back(2);
    is_not_prime.resize(max_n+1);
    for(uint32_t i=4; i<=is_not_prime.size(); i+=2)
        is_not_prime[i]=true;
    is_not_prime[2]=false;
    for(uint32_t i=3; i<=max_n; i+=2)
    {
        if(is_not_prime[i]==false)
        {
            primes.push_back(i);
            for(uint32_t j=(i<<1); j<is_not_prime.size(); j+=i)
            {
                is_not_prime[j]=true;
            }
        }
    }

    primes_sq.resize(primes.size());

    for(uint32_t i=0; i<primes.size(); i++)
        primes_sq[i]=((uint64_t)primes[i]*(uint64_t)primes[i]);
}

bool is_prime (uint64_t a)
{
    //cout<<"ASDDSA:"<<' '<<a<<' '<<is_not_prime[a]<<endl;

    if(a<is_not_prime.size())
        return !is_not_prime[a];

    for(uint64_t i=0; i<primes.size() && primes[i]*primes[i]<=a; i++)
    {
        if(a%primes[i]==0)
            return false;
    }

    for(uint64_t i=primes.back(); i*i<a; i+=2)
    {
        if(a%i==0)
            return false;
    }

    return true;

    //cout<<a<<endl;
    //cout<<"ASDDFASasdffaak"<<endl;
    //exit(-1);
}

bool test_is_ans(uint64_t x)
{
    //assert(x<primes_sq.size());
    uint32_t i;
    for(i=0; i<MAXTEST; i++)
    {
        if(is_prime(primes_sq[i]+x))
        {
            //cout<<"asd: "<<is_prime(primes_sq[i]+x)<<endl;
            //cout<<x<<' '<<i<<endl;
            //cout<<primes_sq[i]<<' '<<primes_sq[i]+x<<endl;
            //exit(-1);
            break;
        }
    }
    if(i==MAXTEST)
        return true;

    return false;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    generate_primes(10000000);
}

int __main()
{
    generate_primes(10000000);

    cout<<is_prime(1000000007)<<endl;

    //cout<<primes_sq[0]<<endl;

    //for(uint32_t x=0; x<100; x++)
    //    cout<<x<<' '<<is_not_prime[x]<<endl;

    //exit(-1);
    //cout<<primes[0]<<' '<<primes[1]<<' '<<primes[2]<<' '<<primes[3]<<endl;

    //cout<<primes.size()<<endl;

    uint64_t br=0;

    //cout<<primes[8951]<<endl;

    //cout<<test_is_ans(0)<<endl;

    for(uint32_t x=0; x<100000000; x+=2)
    {

        if(test_is_ans(x))
        {
            //cout<<x<<endl;
            br++;
        }

    }

    cout<<br<<endl;

    return 0;
}

int main()
{
    init();

    uint64_t n;
    cin>>n;

    if((n&1)==0)
        n+=2;
    else
        n++;
    //n&=~(1);

    for(; true; n+=2)
    {
        if(test_is_ans(n))
        {
            cout<<n<<'\n';
            exit(0);
        }
    }

    return 0;
}
