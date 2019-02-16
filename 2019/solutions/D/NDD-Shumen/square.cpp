#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int a[10001];
int nod(int a,int b)
{
    if(a>b)
    {
        swap(a,b);
    }
    if(a==b)return a;
    if(b%a!=0)return 1;
    int p=a;
    b=p%b;
    return b;

}
int main()
{
    int n;
    cin>>n;
    cin>>a[0];
    int p=a[0];
    int s=a[0];
    vector<int>v;
    v.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        s*=a[i];
        p=nod(a[i],p);
        v.push_back(a[i]);
    }
    int nok=s/p;
    for(int i=1;i<=v.size();i++)
    {
        if(v[i-1]<v[i])swap(v[i-1],v[i]);
    }
    int maxch1=v[0];
    int maxch2=v[1];
    int i=1;
    int d=maxch1*maxch2;
    cout<<d<<endl;
return 0;
}
