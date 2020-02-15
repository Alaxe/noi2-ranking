#include<iostream>
using namespace std;
int main()
{
    long long n,kopieNaI,duljinaNaChislo=0,brNamereni=0,naKakvoDelim=1;
    cin>>n;
    if(n<=9)
    {
        cout<<n;
        return 0;
    }
    else
    {
        for(long long i=1;i<=n;i++)
        {
            duljinaNaChislo=0;
            kopieNaI=i;
            while(kopieNaI>0)
            {
                duljinaNaChislo++;
                kopieNaI/=10;
            }
            naKakvoDelim=1;
            for(long long j=1;j<duljinaNaChislo;j++)
            {
                naKakvoDelim*=10;
                naKakvoDelim+=1;
            }
            if(i%naKakvoDelim==0)
            {
                brNamereni++;
            }
        }
        cout<<brNamereni;
    }
    return 0;
}
