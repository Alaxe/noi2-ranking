#include<iostream>
using namespace std;
int main()
{
    int Ai,Bi,n,i,Ai1,Bi1,s=1;
    cin>>n;
cin>>Ai1>>Bi1;
    for(i=1;i<n;i++)
    {
    cin>>Ai>>Bi;
    if(((Ai<=Ai1||Ai<=Bi1)&&(Bi<=Ai1||Bi<=Bi)))s+=1;
    else s=s+0;
    }
    cout<<s<<endl;
}
