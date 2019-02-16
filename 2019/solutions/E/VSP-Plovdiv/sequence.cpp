#include<iostream>
using namespace std;
int main()
{
long long n,chislo=1,br=1,maximum=1,lipsva=0;
cin>>n;
while(chislo!=n||chislo!=maximum)
{
    chislo=1;
    while(chislo!=1)
    {
        br++;
        chislo--;
    }
    br=br+2;
    chislo++;
    maximum++;
    if(n>=3)
    {
        br=n*(n-1)+1;
        break;
    }
}
cout<<br<<endl;
}
