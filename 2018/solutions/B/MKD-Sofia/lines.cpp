#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    int n,m=0,a,b;
    cin>>n;
    int x[n],y[n];
    map <int,int> l[n];
    map <int,int> r;
    map <int,int> c;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        c[x[i]]++;
        m=max(m,c[x[i]]);
        r[y[i]]++;
        m=max(m,r[y[i]]);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            a=y[i]-y[j];
            b=x[i]-x[j];
            if(a==0 or b==0) continue;
            int d=__gcd(max(a,-a),max(b,-b));
            a/=d;
            b/=d;
            if(b<0)
            {
                a=-a;
                b=-b;
            }
            if(l[j][200*a+b]==0) l[j][200*a+b]++;
            l[i][200*a+b]=l[j][200*a+b]+1;
            if(l[i][200*a+b]>m) m=l[i][200*a+b];
        }
    }
    cout<<m;
    return 0;
}
