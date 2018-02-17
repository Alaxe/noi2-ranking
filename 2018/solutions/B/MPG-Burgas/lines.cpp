#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int A[n][2],Br[n],br=0,brm=0,max=0;
    double X[n][n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i][0]>>A[i][1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[j][0]!=A[i][0]||A[j][1]!=A[i][1])
            {
                if(A[j][1]-A[i][1]==0)
                {
                    X[i][j]=1000;
                }
                else
                {
                     X[i][j]=(A[j][0]-A[i][0])/(A[j][1]-A[i][1]);
                }
            }

        }
    }
    for(int i=0;i<n;i++)
    {
        brm=0;
        for(int j=0;j<n;j++)
        {
            for(int g=0;g<n;g++)
            {
                if(X[i][j]==X[i][g])
                {
                    br++;
                }
            }
            if(brm<br)
            {
                brm=br;
            }
            br=0;
        }
        Br[i]=brm;
    }
    for(int i=0;i<n;i++)
    {
        if(Br[i]>max)max=Br[i];
    }
    cout<<max+1<<endl;
    return 0;
}
