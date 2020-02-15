#include<iostream>
#include<vector>
using namespace std;

const int N=100000;
int a[N+1],b[N+1],t[N];
int n;

int main()
{
    std::ios_base::sync_with_stdio (false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++) cin >> b[i];

    for (int i = 0; i < n; i++) t[i]=i+1;

    for (int i = 0; i < n; i++)
    {
       int c=0;
       for(int j=n-1;j>=0;j--)
       {
         if(t[j]>0) c++;
         if(c==b[i]+1) {a[i]=t[j]; t[j]=0; break;}
       }
    }

    cout << a[0];
    for (int i = 1; i < n; i++) cout << " " << a[i];
    cout << endl;
}

