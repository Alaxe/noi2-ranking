#include <iostream>
using namespace std;
int k,n,c,b,a[10000],pd[50],pdb=2,j;
int main()
{
    cin>>n,k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<51;i++)
        pd[i]=0;
    for(int i=max(a[1],a[2]);i<=a[1]*a[2];i++)
    {
        if(i%a[1]==0&&i%a[2]==0)
        {
            pd[1]=i;
            break;
        }
    }
    for(j=3;j<=n;j++)
    {
        for(int i=max(pd[pdb-1],a[j]);i<=pd[pdb-1]*a[j];i++)
        {
            if(i%pd[pdb-1]==0&&i%a[j]==0)
            {
                pd[pdb]=i;
                break;

            }
        }
        pdb++;
    }
    cout<<pd[pdb-1]<<endl;


}
