#include <iostream>
using namespace std;

long long c[274]={0};

int main()
{
    int n, m;
    cin >>n >>m;

    for(int i = 1; i <= m; i++)
    {
        c[i]++;
        for(int j = i + 1; j <= n; j++)
            c[j] += c[j-i];
    }

    //for(int i = 1; i <= n; i++) cout<<c[i]<<" ";
    //cout<<endl;
    cout<<c[n]<<endl;
}
