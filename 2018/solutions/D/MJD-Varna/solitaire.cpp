#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int main()
{
    int n;
    char c1,c2;
    cin>>n;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            cin>>c1>>c2;
            if(c1=='A') a[i][j]=1;
            else if(c1=='2') a[i][j]=2;
            else if(c1=='3') a[i][j]=3;
            else if(c1=='4') a[i][j]=4;
            else if(c1=='5') a[i][j]=5;
            else if(c1=='6') a[i][j]=6;
            else if(c1=='7') a[i][j]=7;
            else if(c1=='8') a[i][j]=8;
            else if(c1=='9') a[i][j]=9;
            else if(c1=='T') a[i][j]=10;
            else if(c1=='J') a[i][j]=11;
            else if(c1=='Q') a[i][j]=12;
            else if(c1=='K') a[i][j]=13;
        }
    }

    int j=n-1;
    for(int i=0;;)
    {
        for(;;)
        {
            if(j==0 && i==n-1) goto ch;
            if(a[i][j-1]>a[i+1][j]) {a[i][j-1] = a[i][j-1]+a[i][j];j--;}
            else {a[i+1][j] = a[i][j]+a[i+1][j];i++;break;}
        }
    }

    ch:
    cout<<a[n-1][0];

}
