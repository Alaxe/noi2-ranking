#include <iostream>
using namespace std;
int tab[10000][10000];
int main()
{
    int n;
    cin>>n;
    int x[n],y[n],d[n],mx=0,my=0;
    for(int i=0; i<n; i++)
    {
        cin>>y[i]>>x[i]>>d[i];
        if(mx<x[i])
            mx=x[i];
        if(my<y[i]+d[i])
            my=y[i]+d[i];
    }
    mx++;
    my++;
    //t[1][6]=8;
    for(int i=0; i<n; i++)
    {
        for(int a=d[i]; a; a--)
            tab[2*(mx-x[i])][y[i]+a-1]=1;
        /*for(int l=0;l<2*mx;l++)
        {
            for(int j=0;j<my;j++)
                cout<<t[l][j];
            cout<<"\n";
        }
        cout<<"\n";*/
    }
    int T;
    cin>>T;
    int t[T];
    int ans[T];
    for(int q=0; q<T; q++)
        cin>>t[q];
    ///**********************

    cout<<"\n"<<mx<<" "<<my<<"\n";
    for(int l=0; l<2*mx; l++)
    {
        for(int j=0; j<my; j++)
            cout<<tab[l][j];
        cout<<"\n";
    }
    cout<<"\n";
    ///**********************

    int L[T],R[T];

    for(int q=0; q<T; q++)
    {
        /// LEFT
        int duski=0;
        int i=0,j=t[q];
        for(i=0; i<mx; i++)
        {
            tab[i][j]=2;
            if(tab[i][j]==1)
            {
                duski++;
                for(; tab[i][j]!=0; j--)
                {
                    tab[i][j]=2;
                    if(j==0)
                    {
                        i=mx;
                        break;
                    }
                }
            }
        }
        for(int l=0; l<2*mx; l++)
        {
            for(int j=0; j<my; j++)
                cout<<tab[l][j];
            cout<<"\n";
        }
        cout<<"\n";
        L[q]=duski;
///---------------------------------------------///
        /// RIGHT
        duski=0;
        i=0;
        j=t[q];
        for(i=0; i<mx; i++)
        {
            if(tab[i][j]==1)
            {
                duski++;
                for(; tab[i][j]!=0; j++)
                {
                    if(j==my-1)
                    {
                        i=mx;
                        break;
                    }
                }
            }
        }
        R[q]=duski;
        ans[q]=min(L[q],R[q]);
    }
    for(int q=0; q<T; q++)
        cout<<ans[q];
    return 0;
}

