#include<iostream>
using namespace std;
int main()
{
    int n, br=0;
    long k;
    long begin=1;
    cin>>n;
    cin>>k;
    long end=9;
    for(int i=1;i<n;i++)
{
     begin=begin*10+0;
        end=end*10+9;
}

    long mina=begin;
    while(begin<=end)
    {
        if(begin%k==0)
        {
           if(begin<mina) mina=begin;
           br++;
        }
        begin++;
    }
    if(br==0)
        cout<<"NO"<<endl;
    else
        cout<<mina<<endl;

    return 0;



}
