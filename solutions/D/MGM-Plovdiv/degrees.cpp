#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s, s1="2", k;
    unsigned long long otg=1, l=0, chislo=2, chcpy, i=0;
    cin>>s;
    while(l==0)
    {
        if(s==s1){l=1; cout<<otg<<endl;}
        else
        {
            chislo*=2;
            chcpy=chislo;
            while(chcpy>0)
            {
                k=char(chcpy%10+'0')+k;
                chcpy/=10;
            }
            s1=s1+k;
            otg++;
        }
        k="";
    }
   return 0;
}
