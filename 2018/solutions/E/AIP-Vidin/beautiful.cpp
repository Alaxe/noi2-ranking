#include<iostream>
using namespace std;
int main()
{
    int n, count=0;
    long k;
    cin>>n;
    cin>>k;
    long begin=1;
    long end=9;
    for(int i=1;i<n;i++)
    {
        begin=begin*10+0;
        end=end*10+9;
    }
    long minch=100000000;
    for(int i=begin; i<=end;i++)
    {
        if(begin%k==0)
        {
            if(begin<minch) minch=begin;
            count++;
        }
        begin++;
    }
    if(count==0)
        cout<<"NO"<<endl;
    else
        cout<<minch<<endl;
    return 0;
}
