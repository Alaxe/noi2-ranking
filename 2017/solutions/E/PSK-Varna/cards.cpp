#include <iostream>
using namespace std;
int main ()
{
    int N,sh[100000],d[100000],br=1,a=0;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>sh[i]>>d[i];
    }
    for(int i=0; i<N; i++)
    {
        if(d[i]>=d[i+1]&&d[i]>=sh[i+1]&&sh[i]>=d[i+1]&&sh[i]>=sh[i+1])
        {
            br++;
        }
    }
    cout<<br<<endl;
    return 0;
}
