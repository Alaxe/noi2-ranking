#include<iostream>
using namespace std;

int main()
{
    long long nums, sum, m, k, num;
    cin>>m,k;
    nums=0;
    sum=0;
    num=0;
    for(;;)
    {
        if(num>k or sum>k or num==200)
        {
            cout<<sum;
            return 0;
        }
        cin>>num;
        nums++;

        if (num%2==0)
        {
            sum+=num;
        }
    }
    return 0;
}
