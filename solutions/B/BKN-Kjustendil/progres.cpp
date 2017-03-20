#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main ()
{
    int Q[1000];
    int N, i, d, k;
    int prog=0;
    do {cin>>N;}
    while (N<1||N>1000);
    for(i=0; i<=N-1;i++) cin>>Q[i];
    for(i=0; i<=N-1;i++)
    {
        d=Q[0];
        for(k=1; k<=N-1; k++)
        {
            if(Q[k]==Q[1]+(k-1)*d) prog++;
        }
    }
    cout<<prog;
    return 0;

}
