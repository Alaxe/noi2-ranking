#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long int bigint;

vector<string> Generate(vector<string> prev, vector<char> digits)
{
    vector<string> next;
    for(int i=0;i<digits.size();i++)
    {
        if(i%2==0) for(int j = 0; j<prev.size();j++)next.push_back(digits[i]+prev[j]);
        else for(int j=prev.size()-1;j>=0;j--)next.push_back(digits[i]+prev[j]);
    }
    return next;
}
int GetNum(vector<string> ss,bigint a,bigint b)
{
    int Nmax =0;;
    for(int brr=a;brr<b;brr++)
    {
        int num=0,m=1;
    for(int br=ss[brr].size()-1;br>=0;br--)
    {
      num=(int)(num+ss[brr][br]-48)*m;
      m=m*10;
    }
    Nmax=max(Nmax,num);
    }
    return Nmax;
}

int getSum(string a)
{
    int sum=0;
    for(int br=0;br<a.size();br++)
    {
sum=sum+(int)(a[br]-48);
    }
    return sum;
}

int GetBig(vector<string> ss,bigint a,bigint b)
{
    int Nmax =0;;
    for(int brr=a+1;brr<b;brr++)
    {
        int num=0;
        num = abs(getSum(ss[brr-1])-getSum(ss[brr]));
        Nmax=max(Nmax,num);
    Nmax=max(Nmax,num);
    }
    return Nmax;
}
int main()
{
bigint a,b;
int n,k;
cin>>n>>k>>a>>b;
vector<char> d;
vector<string> f;
for(int br=0;br<n;br++)
{
    string a="";
    char c;
    cin>>c;
    d.push_back(c);
    a[0]=c;
    f.push_back(a);
}
vector<string> last=f;
for(int br=0;br<k;br++)
{
    last==Generate(last,d);
}
cout<<GetNum(last,a,b)<<" "<<GetBig(last,a,b)<<endl;
}
