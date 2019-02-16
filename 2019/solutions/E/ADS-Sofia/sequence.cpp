#include <iostream>
using namespace std;
int main()
{
    int n;
    int p=0;
    int m=0;
    cin>>n;
    p=2*(n-1);
    do{

    m=m+p;
    p=p-2;



    }while(p>=2);
    m=m+1;
    cout<<m;




    return 0;
}
