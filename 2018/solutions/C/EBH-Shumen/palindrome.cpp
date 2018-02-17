#include<iostream>
#include<string>
#include<cmath>
using namespace std;
long long int s,i;
string str="";
bool palin(long long int c)
{
    if(c>=1&&c<=9)return true;
    if(c==11)return true;
    if(c==2112)return true;
    while(c!=0)
    {
        str+=(c%10+'0');
        c/=10;
    }
    int sz=str.size(),a,b;
    char a1,b1;
    for(a=0;a<sz/2;a++)
    {
        a1=str[a];
        for(b=sz;b>sz/2;b--)
        {
            b1=str[b];
        }
        if(a1!=b1)return false;
    }
    return true;
    
}
int main()
{   
    cin>>s;
    for(i=s+1;i<=pow(10,1300);i++)
    {
        if(palin(i)==true)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    

return 0;
}