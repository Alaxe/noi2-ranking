#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s;
    long long br=0,strl,i=1,a,b,br1=0;
    cin>>s;
    strl=s.size();
    do
    {
        i=i*2;
        a=i;
        do
        {
            a=a/10;
            br1++;
        }
        while(a!=0);
        strl=strl-br1;
        br1=0;
        br++;
    }
    while(strl>0);
    cout<<br<<endl;


    return 0;
}
