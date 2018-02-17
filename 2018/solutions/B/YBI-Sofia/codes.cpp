#include<iostream>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
struct nnumber
{
    vector<int>dig;
    nnumber(long long a=-1,long long n=-1)
    {
        if(a==-1 and n==-1)
        {
            return;
        }
        stack<int> q;
        do
        {
            q.push(a%n);
            a/=n;
        }
        while(a!=0);
        while(!q.empty())
        {
            dig.push_back(q.top());
            //cout<<q.top();
            q.pop();
        }
    }
};
long long n,k,a,b;
vector<int> dig;
string make(nnumber nx)
{
    vector<int> r;
    for(int h=0; h<k-nx.dig.size(); h++)
    {
        r.push_back(0);
    }
    for(int h=0; h<nx.dig.size(); h++)
    {
        r.push_back(nx.dig[h]);
    }
    //cout<<"ll"<<endl;
    bool rev=0;
    string res;
    for(int i=0; i<r.size(); i++)
    {

        //cout<<"r["<<i<<"]="<<r[i]<<endl;
        //cout<<r.size()<<endl;
        if(!rev)
        {
            //cout<<"adding"<<char('0'+dig[r[i]])<<endl;
            res=res+char('0'+dig[r[i]]);
        }
        else
        {
            //cout<<"ad2ding"<<char('0'+dig[k-1-r[i]])<<endl;
            res=res+char('0'+dig[n-1-r[i]]);
        }
        if(r[i]%2==1)
        {
            rev=!rev;
        }

    }
    //cout<<"k";
    return res;
}
long long sums(string g)
{
    long long res=0;
    for(int i=0;i<g.size();i++)
    {
        res+=g[i]-'0';
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int curr;
    cin>>n>>k>>a>>b;
    int sa=a;
    a--;
    b--;
    nnumber na,nb;
    na=nnumber(a,n);
    nb=nnumber(b,n);
    for(int i=0; i<n; i++)
    {
        cin>>curr;
        dig.push_back(curr);
    }
    //cout<<"ok"<<endl;
    string maxx="0";
    long long lasts=0;
    long long maxres2=0;
    for(; a<=b; a++)
    {
        na=nnumber(a,n);
        string nn=make(na);
        long long summm=sums(nn);
        //cout<<nn<<" "<<summm<<endl;
        if(lasts!=0)
        {
            if(abs(summm-lasts)>maxres2)
            {
                maxres2=abs(summm-lasts);
            }
        }
        lasts=summm;
        if(nn>maxx)
        {
            maxx=nn;
        }
        //cout<<nn<<endl;
    }
    cout<<maxx<<" "<<maxres2<<endl;
    return 0;
}
