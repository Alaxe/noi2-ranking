#include<iostream>
using namespace std;

long long endOn1Ex[300][300];
long long endOn1[300][300];
long long endOn11Ex[300][300];
long long endOn11[300][300];
long long otherEx[300][300];
long long other[300][300];
long long total[300];

int n,m;

void generate(int n)
{
    endOn1Ex[1][1]=1;
    for (int i=1;i<=n;i++) endOn1[1][i]=1;

    endOn11Ex[2][1]=1;
    for (int i=1;i<=n;i++) endOn11[2][i]=1;
    otherEx[2][2]=1;
    for (int i=2;i<=n;i++) other[2][i]=1;

    endOn1Ex[3][2]=1;
    for (int i=2;i<=n;i++) endOn1[3][i]=1;
    endOn11Ex[3][1]=1;
    for (int i=1;i<=n;i++) endOn11[3][i]=1;
    otherEx[3][3]=1;
    for (int i=3;i<=n;i++) other[3][i]=1;

    total[1] = 1;
    total[2] = 2;
    total[3] = 3;

//    for (int i=1;i<=3;i++)
//    {
//        cout<<i<<" -> "<<endl;
//        for (int j=1;j<=i;j++) cout<<endOn1Ex[i][j]<<" ";
//        cout<<endl;
//        for (int j=1;j<=i;j++) cout<<endOn1[i][j]<<" ";
//        cout<<endl;
//        for (int j=1;j<=i;j++) cout<<endOn11Ex[i][j]<<" ";
//        cout<<endl;
//        for (int j=1;j<=i;j++) cout<<endOn11[i][j]<<" ";
//        cout<<endl;
//        for (int j=1;j<=i;j++) cout<<otherEx[i][j]<<" ";
//        cout<<endl;
//        for (int j=1;j<=i;j++) cout<<other[i][j]<<" ";
//        cout<<endl;
//    }


    for (int i=4; i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            endOn1Ex[i][j] = otherEx[i-1][j];
            endOn1[i][j] = other[i-1][j];
        }

        for (int j=1;j<=i;j++)
        {
            endOn11Ex[i][j] = endOn11Ex[i-1][j] + endOn1Ex[i-1][j];
        }

        long long curr=0;

        for (int j=1;j<=n;j++)
        {
            endOn11[i][j] = endOn11Ex[i][j]+curr;
            curr = endOn11[i][j];
        }


        for (int j=2;j<=n-1;j++)
        {
            otherEx[i][j] = other[i-j][j];
        }
        otherEx[i][i]=1;
        curr=0;
        for (int j=2;j<=n;j++)
        {
            other[i][j] = otherEx[i][j]+curr;
            curr = other[i][j];
        }

//        cout<<i<<" -> "<<endl;
//        for (int j=1;j<=i;j++) cout<<endOn1Ex[i][j]<<" ";
//        cout<<endl;
//        for (int j=1;j<=i;j++) cout<<endOn1[i][j]<<" ";
//        cout<<endl;
//        for (int j=1;j<=i;j++) cout<<endOn11Ex[i][j]<<" ";
//        cout<<endl;
//        for (int j=1;j<=i;j++) cout<<endOn11[i][j]<<" ";
//        cout<<endl;
//        for (int j=1;j<=i;j++) cout<<otherEx[i][j]<<" ";
//        cout<<endl;
//        for (int j=1;j<=i;j++) cout<<other[i][j]<<" ";
//        cout<<endl;

        total[i] = endOn1[i][i] + endOn11[i][i] + other[i][i];
    }

}

int main ()
{
    cin>>n>>m;

    generate(n);

    long long ans=total[n];

    for (int i=m+1;i<=n;i++)
    {
        ans-= (endOn1Ex[n][i] + endOn11Ex[n][i] + otherEx[n][i]);
    }
    //for (int i=1;i<=n;i++) cout<<i<<" -> "<<total[i]<<endl;

    cout<<ans<<endl;
}
