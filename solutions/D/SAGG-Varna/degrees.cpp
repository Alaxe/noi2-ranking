#include <iostream>
using namespace std;
string lltostr(unsigned long long a)
{
    string str="";
    while (a)
    {
        char temp=(a%10+'0');
        str=temp+str;
        a/=10;
    }
    return str;
}
int main ()
{
    string in;
    cin>>in;
    unsigned long long a=2;
    int br=0;
    while(true)
    {
        if (in.find(lltostr(a))<20000000) br++;
        else break;
        a*=2;
    }
    cout<<br<<endl;
}
