#include<iostream>
using namespace std;
int main()
{
    int n,i,ogl=0;
    cin>>n;
    for(i=1; i<=n*n; i++)
    {
          while(i)
          {
                ogl=ogl*10+i%10;
                i=i/10;
                cout<<ogl<<endl;
          }
    }
    return 0;
}
