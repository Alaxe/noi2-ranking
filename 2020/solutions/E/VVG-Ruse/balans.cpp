#include<iostream>
using namespace std;
int main ()
{
    long long ab=0,cd=0,br=0,maxbal=0,n;
    char a;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        if(a=='a'||a=='b') ab++;
        if(a=='c'||a=='d') cd++;
        br++;
        if(ab==cd&&br>maxbal) maxbal=br;
    }
    cout<<maxbal<<endl;
    return 0;
}