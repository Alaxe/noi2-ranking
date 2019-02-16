#include <iostream>
using namespace std;
long long a[10000][10000], n;
void print()
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}

/*int down_right(int dw)
{
    //a[0][dw]=2; ///remove
    int i, j, cnt=0;
    for(i=0; i<n; i++)
    {
        if(a[i][dw]==1)
        {
            cnt++;
            cout<<"CNT=+"<<endl;
            for(j=dw; j<n; j++)
            {
                if(a[i][j]==0) { cout<<"DW="<<i<<' '<<j<<endl; dw=j; break; }
            }
        }
    }
    return cnt;
}*/

/*int down_left(int dw)
{
    a[0][dw]=2; ///remove
    int i, j, cnt=0;
}*/

int down(int dw)
{
    //a[0][dw]=2; ///remove
    int i, j, cnt=0;
    /*for(i=0; i<n; i++)
    {
        if(a[i][dw]==1&&(a[i][dw+1]==1||a[i][dw-1]==1)) { cnt++; cout<<"CNT="<<cnt<<endl; }
    }*/

    for(i=0; i<=n; i++)
    {
        if(a[i][dw]==1) cnt++;
    }
    return cnt-1;
}

void read()
{
    int x, y, d, t, ti, i, j;
    int t1, t2;

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x>>y>>d;
        for(j=1; j<=d; j++)
            a[n-y+1][x+j-1]=1;
    }

    //print();

    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>ti;
        cout<<down(ti)<<' ';
        /*t1=down_left(ti);
        cout<<"T1="<<t1<<endl;

        t2=down_right(ti);
        cout<<"T2="<<t2<<endl;

        cout<<max(t1, t2)<<endl;
        */
    }

    //print();
}

int main()
{
    read();
    return 0;
}

/**
5
1 2 1
1 3 1
1 3 2
1 4 1
1 5 1

13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
**/
