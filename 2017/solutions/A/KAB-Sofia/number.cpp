#include<iostream>
#include<math.h>
using namespace std;
char s[100];
int main()
{
    int M,N;
    cin>>M>>N;
    double kM=sqrt(M+0.25);
    double kN=sqrt(N+0.25);
    double s=(kM-0.5);
    double g=(kN-0.5);
    int x=s;
    int y=g;
    int k=y-x;
    if((x+0.5)*(x+0.5)==M+0.25) cout<<k+1<<endl;
    if((x+0.5)*(x+0.5)!=M+0.25) cout<<k<<endl;
    return 0;
}
