#include<iostream>
using namespace std;
int main ()
{
    int brK,a=1,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s;
    long long N;
    cin >> N;
    for(int br=1; br<=N; br++)
    {
        int t=a%10;
        if(a>=1000000000000000000)
             b=a/1000000000000000000%10;
        else
            b=t;
        if(a>=100000000000000000)
             c=a/100000000000000000%10;
        else
            c=t;
        if(a>=1000000000000000)
            d=a/10000000000000000%10;
        else
            d=t;
        if(a>=100000000000000)
             e=a/1000000000000000%10;
        else
            e=t;
        if(a>=10000000000000)
             f=a/100000000000000%10;
        else
            f=t;
        if(a>=1000000000000)
            g=a/10000000000000%10;
        else
            g=t;
        if(a>=100000000000)
             h=a/1000000000000%10;
        else
            h=t;
        if(a>=10000000000)
            i=a/100000000000%10;
        else
            i=t;
        if(a>=1000000000)
             j=a/10000000000%10;
        else
            j=t;
        if(a>=100000000)
             k=a/1000000000%10;
        else
            k=t;
        if(a>=10000000)
             l=a/100000000%10;
        else
            l=t;
        if(a>=1000000)
             m=a/10000000%10;
        else
            m=t;
        if(a>=100000)
             n=a/1000000%10;
        else
            n=t;
        if(a>=10000)
             o=a/100000%10;
        else
            o=t;
        if(a>=1000)
             p=a/10000%10;
        else
            p=t;
        if(a>=100)
             q=a/1000%10;
        else
            q=t;
        if(a>=10)
            r=a/100%10;
        else
            r=t;
        if(a>=1)
             s=a/10%10;
        else
            s=t;


        if(a==b && b==c && c==d && d==h && h==i && i==j && j==k && k==l && l==m && m==n && n==o && o==p && p==q && q==r && r==s && s==t)
            brK++;

    }
    cout << brK+9 << endl;

        return 0;
}
