#include<iostream>
#include<cstring>
using namespace std;
char A[101];
int i,zap,n,br=0,c[1000];
bool fl;
void com()
{

}
int main()
{   cin>>A;
    i=0;n=0;
    while(A[i]!='\0')
    {   n++;
        i++;
    }
    br=n;
    zap=n-1;
    fl=1;
    for(i=0;i<n;i++)if(A[i]!=A[zap--]){fl=0;break;}
    if(fl==1)br++;
    cout<<br;
    return 0;
}
