#include<iostream>
#include<vector>
using namespace std;   
vector<long long>res;
long long n,i,l,ch[1000];
bool found=false;
void rec(long long b,long long curr,bool io)
{
    if(b==n)
    {
        if(io==true){l=res.size();
        for(i=0;i<l;i++)if(res[i]==curr){found=true;break;}
        if(found==false)res.push_back(curr);
        found=false;}
        return;
    }
    else {rec(b+1,curr,io);rec(b+1,curr+ch[b],true);}
}
int main()
{
    cin>>n;
    for(i=0;i<n;i++)cin>>ch[i];
    rec(0,0,false);
    cout<<res.size()<<endl;
    return 0;
}