#include<iostream>
using namespace std;
int main()
{
    long long K,M,sum=0,ch,i=1,closest=10000000,closestind;
    cin>>M>>K;
    i=1;
    do
    {
        cin>>ch;
        if(M>ch)
        {
            if(M-ch<=closest) 
            {
                closestind=i;
                closest=M-ch;
            }
        }
        else if(ch-M<=closest)
        {
            closestind=i;
            closest=ch-M;
        }
        if(ch%2==0) sum+=ch;
        i++;
    }
    while(sum<K && ch!=200);
    cout<<closestind<<" "<<sum<<endl;
    return 0;
}