#include<iostream>
using namespace std;
int main()
{
    int n,q;
    cin>>n;
    int a;
    cin>>a;
    int pr=a;
    cin>>q;
    for(int i=1;i<n;i++)
    {
        cin>>a;
       if(pr<a)
       {
           pr++;
           q=q*2;
       }
       if(pr>a)
       {
           a++;
           q=q*2;
       }
       pr=a;
    }
    cout<<q<<endl;
    return 0;
}
