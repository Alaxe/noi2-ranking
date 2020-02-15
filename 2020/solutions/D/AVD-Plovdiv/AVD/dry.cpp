#include<iostream>
using namespace std;
int main()
{
    int n,u,v;
    cin>>n>>u>>v;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int i = 0, voda = 0;
    do
    {
        if(a[i] <= a[i+1])
        {
            voda += a[i]*u*v;
            i++;
        }
        if(a[i] > a[i+1])
        {
            int max=0,prmax=0,j=0,m=1;
            do
            {
                m=i;
                i++;
                if(a[i] > a[i+1])
                {
                    voda += a[i]*u*v;
                    j++;
                }
                if(a[i] > max)
                {
                    max = a[i];
                }

            }
            while(a[i] > a[i+1] && i != n-1);
            voda += a[i+1]*u*v;
            voda += (a[i+1]-max)*u*v;
        }
    }
    while(i != n-1);
    cout << voda << endl;
    return 0;
}
