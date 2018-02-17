#include<iostream>
using namespace std;
int main()
{
    int N=0,cif=1;
    cin>>N;
    int L;
    cin>>L;
    int a[2];
    cin>>a[2];
    while(N!=0)
    {
        if(cif%10==a[1] || cif%10==a[0] || cif%10==a[2]) cif+=5-0;
        cif+=1;
        N--;
    }
    cout<<cif+1<<endl;
    return 0;
}
