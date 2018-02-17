#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long s,t;
    int z;
    cin>>s>>t>>z;
    long long counter = 0;
    int oldZeros = 0;
    long long s1=s;
    while(s1)
    {
        oldZeros+=s1 & 1;
        s1>>=1;
    }
    oldZeros = log2(s) + 1 - oldZeros;
    for(long long otherS = s+1;otherS <= t;otherS++)
    {
        long long diff = otherS^(otherS-1);
        int zeros=oldZeros;
        s1 = otherS-1;
        while(diff && s1)
        {
            if(diff & 1)
            {
                if(s1 & 1)
                    zeros++;
                else
                    zeros--;
            }
            s1>>=1;
            diff>>=1;
        }
        if(zeros == z)
            counter++;
        oldZeros = zeros;
    }
    cout<<counter;
    return 0;
}
