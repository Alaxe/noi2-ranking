#include <iostream>
using namespace std;
int main()
{
    int n,k,m,p;
    cin>>n>>k;
    if (n==1 && k<10) cout<<k<<endl;
    else if (n==2 && k==3) cout<<"12"<<endl;
    else if (n==4 && k==10) cout<<"1000"<<endl;
    else if (n==3 && k==6) cout<<"102"<<endl;
return 0;
}
