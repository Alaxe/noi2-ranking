#include<iostream>
#include<set>
#include<algorithm>

using namespace std;
struct blq
{
    long long x1, x2,  y;
    blq(){}
    blq(long long a, long long b, long long c)
    {
        x1 = a;
        x2 = b;
        y = c;
    }
};

bool cmp1 (blq a, blq b)
{
    if(a.y == b.y)
    {
        if(a.x1 == b.x1)
        {
            return a.x2 < b.x2;
        }
        else
        {
            return a.x1 < b.x1;
        }
    }
    return a.y < b.y;
}
long long n;
blq A[100005];
long long otg[100005];
long long bsy(long long y)
{
    long long l = 0,  r = n;
    while(l+1<r)
    {
        long long m = (l+r)/2;
        if(A[m].y>=y)
            r= m;
        else l = m;
    }
    if(A[l].y>=y)
        return -1;
    return l;
}
long long bszalqv(long long l , long long r, long long kraj)
{
    while(l+1 <r)
    {
        long long m = (l+r)/2;
        if(A[m].x1 >= kraj)
            r = m;
        else
            l = m;
    }
    if(A[l].x1 >= kraj)
        return -1;
    return l;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(long long i=0; i<n; i++)
    {
        long long d;
        cin>>A[i].x1>>A[i].y>>d;
        A[i].x2 = A[i].x1+d;
    }
    //cout<<"----\n";

    sort(A,A+n, cmp1);
    for(long long i=0; i<n; i++)
    {
      //  cout<<"sa "<<A[i].x1<<" "<<A[i].y<<endl;
        long long lqv = -1,desen = -1;
        for(long long j=i-1; j>=0;j--)
        {
            if(A[j].y == A[i].y) continue;
           if(lqv>0 && desen >0 ) break;
           //cout<<"gl "<<A[j].x1<<" "<<A[j].y<<endl;
            if(lqv== -1 && A[j].x1 < A[i].x1 && A[j].x2 >= A[i].x1)
            {
                //cout<<"aaa\n";
                lqv = otg[j];
            }
            if(desen == -1 && A[j].x1<= A[i].x2 && A[j].x2>A[i].x2)
            {
                //cout<<"bbb\n";
                desen = otg[j];
            }
        }
       // cout<<"lqv "<<lqv<<" "<<desen<<endl;
        if(lqv == -1 or desen == -1)
            otg[i] = 1;
        else otg[i] = min(lqv, desen)+1;
    }
   /* for(long long i=0; i<n;i++)
    {
        cout<<A[i].x1<<" "<<A[i].x2<<" "<<otg[i]<<endl;
    }*/
    long long q;
    cin>>q;
    for(long long i=0; i<q; i++)
    {
        long long a;
        cin>>a;
        long long k =0;
        for(long long i=n-1; i>=0; i--)
        {

            if(A[i].x1<= a && A[i].x2 >a)
            {
                cout<<otg[i]<<" ";
                k =1;
                break;
            }
        }
        if(k==0) cout<<0<<endl;
    }
    cout<<endl;
    return 0;
}
