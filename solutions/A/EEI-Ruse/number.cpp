#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
const long long BASE=1e9;
const long long POW=9;
struct Lnum
{
    vector<long long> dig;
    void init(const string& s)
    {
        long long curr=0;
        int pos=s.size()-POW;
        int cd=0;
        dig.resize(0);
        while (pos>0)
        {
            dig.push_back(0);
            for (int i=pos;i<pos+POW;++i)
            {
                dig[cd]*=10;
                dig[cd]+=s[i]-'0';
            }
            pos-=POW;
            ++cd;
        }
        dig.push_back(0);
        for (int i=0;i<pos+POW;++i)
        {
            dig[cd]*=10;
            dig[cd]+=s[i]-'0';
        }
        for (int i=dig.size()-1;i>=0;--i)
        {
            if (dig[i]==0) dig.resize(i);
            else break;
        }
    }
    void addll(const long long& num)
    {
        int i=0;
        long long carry=num;
        while (carry>0)
        {
            if (i<dig.size())
            {
                dig[i]+=carry;
                carry=dig[i]/BASE;
                dig[i]%=BASE;
            }
            else
            {
                dig.push_back(carry);
                carry=dig[i]/BASE;
                dig[i]%=BASE;
            }
            ++i;
        }
    }
    void add(const Lnum& num)
    {
        long long carry=0;
        for (int i=0;i<dig.size() || i<num.dig.size() || carry>0;++i)
        {
            if (i>=dig.size()) dig.push_back(0);
            if (i<num.dig.size()) dig[i]+=num.dig[i];
            dig[i]+=carry;
            carry=dig[i]/BASE;
            dig[i]%=BASE;
        }
    }
    void multll(const long long& num)
    {
        long long carry=0;
        for (int i=0;i<dig.size() || carry>0;++i)
        {
            if (i>=dig.size()) dig.push_back(0);
            dig[i]*=num;
            dig[i]+=carry;
            carry=dig[i]/BASE;
            dig[i]%=BASE;
        }
        for (int i=dig.size()-1;i>=0;--i)
        {
            if (dig[i]==0) dig.resize(i);
            else break;
        }
    }
    void mult(const Lnum& num)
    {
        int n=num.dig.size();
        Lnum curr_prod;
        Lnum curr=*this;
        dig.resize(0);
        for (int i=0;i<n;++i)
        {
            curr_prod=curr;
            curr_prod.multll(num.dig[i]);
            add(curr_prod);
            curr.multll(BASE);
        }
        for (int i=dig.size()-1;i>=0;--i)
        {
            if (dig[i]==0) dig.resize(i);
            else break;
        }
    }
    void subll(const long long& num)
    {
        long long take=num;
        for (int i=0;i<dig.size() && take>0;++i)
        {
            dig[i]-=take;
            if (dig[i]<0)
            {
                dig[i]+=BASE;
                take=1;
            }
            else take=0;
        }
        for (int i=dig.size()-1;i>=0;--i)
        {
            if (dig[i]==0) dig.resize(i);
            else break;
        }
    }
    void sub(const Lnum& num)
    {
        long long take=0;
        for (int i=0;i<dig.size() && (i<num.dig.size() || take>0);++i)
        {
            if (i<num.dig.size()) dig[i]-=num.dig[i];
            dig[i]-=take;
            if (dig[i]<0)
            {
                dig[i]+=BASE;
                take=1;
            }
            else take=0;
        }
        for (int i=dig.size()-1;i>=0;--i)
        {
            if (dig[i]==0) dig.resize(i);
            else break;
        }
    }
    bool cmp(const Lnum& num)
    {
        if (dig.size()<num.dig.size()) return 1;
        if (dig.size()>num.dig.size()) return 0;
        for (int i=dig.size()-1;i>=0;--i)
        {
            if (dig[i]<num.dig[i]) return 1;
            if (dig[i]>num.dig[i]) return 0;
        }
        return 0;
    }
    void div2()
    {
        long long rem=0;
        for (int i=dig.size()-1;i>=0;--i)
        {
            dig[i]+=rem*BASE;
            rem=dig[i]%2;
            dig[i]/=2;
        }
        for (int i=dig.size()-1;i>=0;--i)
        {
            if (dig[i]==0) dig.resize(i);
            else break;
        }
    }
    long long toll()
    {
        long long num=0;
        for (int i=dig.size()-1;i>=0;--i)
        {
            num*=BASE;
            num+=dig[i];
        }
        return num;
    }
    string tostr()
    {
        if (dig.size()==0) return "0";
        if (dig.size()==1 && dig[0]==0) return "0";
        string str;
        long long curr;
        for (int i=0;i<dig.size();++i)
        {
            curr=dig[i];
            if (i==dig.size()-1)
            {
                while (curr>0)
                {
                    str+='0'+(curr%10);
                    curr/=10;
                }
            }
            else
            {
                for (int i=0;i<POW;++i)
                {
                    str+='0'+(curr%10);
                    curr/=10;
                }
            }
        }
        string str2=str;
        for (int i=0;i<str.size();++i)
        {
            str2[str2.size()-1-i]=str[i];
        }
        return str2;
    }
};
string ms,ns;
string ans;
void input()
{
    cin>>ms>>ns;
}
void output()
{
    cout<<ans<<endl;
}
void outputlnum(Lnum num)
{
    for (int i=num.dig.size()-1;i>=0;--i)
    {
        cerr<<num.dig[i]<<" ";
    }
    cerr<<endl;
}
Lnum m,n;
void solve()
{
    m.init(ms);
    n.init(ns);
    Lnum first,last;
    first.init("0");
    last.init("0");
    Lnum l,r,mid,res;
    string rin;
    for (int i=0;i<=52;++i)
    {
        rin+='9';
    }
    l.init("0");
    r.init(rin);
    while (!r.cmp(l))
    {
        mid=l;
        mid.add(r);
        mid.div2();
        res=mid;
        res.addll(1);
        res.mult(mid);
        if (res.cmp(m))
        {
            l=mid;
            l.addll(1);
        }
        else
        {
            first=mid;
            r=mid;
            r.subll(1);
        }
    }
    
    l.init("0");
    r.init(rin);
    while (!r.cmp(l))
    {
        mid=l;
        mid.add(r);
        mid.div2();
        res=mid;
        res.addll(1);
        res.mult(mid);
        if (n.cmp(res))
        {
            r=mid;
            r.subll(1);
        }
        else
        {
            last=mid;
            l=mid;
            l.addll(1);
        }
    }
    //cerr<<last.tostr()<<endl;
    //cerr<<last.tostr().size()<<endl;
    if (last.cmp(first))
    {
        ans="0";
    }
    else
    {
        last.sub(first);
        last.addll(1);
        ans=last.tostr();
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    output();
    return 0;
}