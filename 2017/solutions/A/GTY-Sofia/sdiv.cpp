#include<iostream>
#include<cmath>
using namespace std;

int num(char a)
{
    return a-'0';
}

long long stoi(string a)
{
    //if(a=="")return -234123413241234134;
    long long res = 0;
    for(int i=0;i<a.size();i++)
    {
        res+=num(a[i])*pow(10,a.size()-i-1);
    }
    return a.size()==3 ? res+1 : res;
}
string in;
int res=0;
int n,m;
int rec(string a, int j)
{
    //cout<<stoi(a)<<" "<<a<<" "<<j<<endl;
    if(a!="")if(stoi(a)%n==0){//cout<<a<<" "<<j<<endl;
    res++;if(res>100000000000)res%=m;}
    for(int i=j;i<in.size();i++)
    {
        a+=in[i];
        rec(a,i+1);
        a.erase(a.size()-1,1);
    }
}


int main()
{
    cin>>in;
    cin>>n>>m;
    //f00or(int i=0;i<in.size();i++)
        rec("",0);
    cout<<res%m<<endl;
    return 0;
}

