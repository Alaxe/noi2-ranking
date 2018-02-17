#include<iostream>
using namespace std;
long long otg=0, n, A[1024],minn=1024, maxx=-1;;
int rec(int curr, int d)
{
   // cout<<A[curr]<<endl;
    for(int i=curr+1;i<n;i++)
    {
        if(A[i]==A[curr]+d)
        {
       //     cout<<"otg "<<otg<<endl;
            otg++;
            rec(i, d);
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        minn=min(minn, A[i]);
        maxx=max(maxx, A[i]);
    }
    for(int i=1;i<=maxx-minn;i++)
    {
        for(int j=0;j<n;j++)
        {
           rec(j,i);
          // cout<<i<< " "<< j<<" "<<otg<<endl;
        }
    }
    cout<<otg<<endl;

return 0;
}
