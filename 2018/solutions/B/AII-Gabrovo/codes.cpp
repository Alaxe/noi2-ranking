# include<iostream>
# include<string>
# include<vector>
# include<algorithm>
using namespace std;

int n,k;
long long a,b;
vector<char> digits;
long long last=1;
int k1=1;
string gen(int pos)
{
    while(last*n<pos) {last*=n; k1++;}
    int k2=k1;
    long long last2=last;
    string s="";
    while(k2>0)
    {
        int c=(pos-1)/last2+1;
        s=s+digits[c-1];
        if(c%2==0) pos=last2*c-pos+1;
        else pos=pos-last2*(c-1);
        k2--;
        last2/=n;
    }
    return s;

}

string maxS(string u, string v)
{
    int us=u.size();
    int vs=v.size();
    if(us<vs) {u=digits[0]+u; us++;}
    for(int i=0; i<us; i++)
    {
        if((int)u[i]-'0'>(int)v[i]-'0') return u;
        if((int)u[i]-'0'<(int)v[i]-'0') return v;
    }
    return u;
}

int razl(string u, string v)
{
    int us=u.size();
    int vs=v.size();
    if(us>vs) {v=digits[0]+v; vs++;}

    int sumU=0;
    for(int i=0; i<us; i++)
        sumU=sumU+((int)u[i]-'0');

    int sumV=0;
    for(int i=0; i<vs; i++)
        sumV=sumV+((int)v[i]-'0');
    return abs(sumU-sumV);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>a>>b;
    for(int i=0; i<n; i++)
    {
        char x;
        cin>>x;
        digits.push_back(x);
    }
    string p=gen(a),q;
    string maxans=p;
    int ans=0;
    int mxsz=0;
    for(long long i=a+1; i<=b; i++)
    {
        q=p;
        p=gen(i);
        mxsz=max(mxsz,(int)q.size());
        maxans=maxS(maxans,q);
        ans=max(ans,razl(p,q));
    }
    maxans=maxS(maxans,p);
    ans=max(ans,razl(p,q));
    mxsz=max(mxsz,(int)p.size());
    for(int i=mxsz; i<k; i++) maxans=digits[0]+maxans;
    cout<<maxans<<" "<<ans<<endl;
}
/*
3 2 3 5
7 1 5

3 10 47 82
7 1 5

6 10000 1000 10001
8 6 4 1 4 2

100 10000 10 100001000
5 8 0 0 1 5 3 2 5 1 5 9 1 0 7 5 0 6 3 6 9 1 2 5 8 9 8 0 6 2 2 6 7 3 0 1 4 7 2 6 6 3 9 0 5 3 1 5 7 7 0 8 2 9 3 3 9 6 8 0 1 2 8 3 2 6 0 1 8 8 4 6 3 9 3 6 5 2 7 0 1 4 6 4 1 5 6 9 2 3 1 7 6 0 0 8 7 9 9 7
*/
