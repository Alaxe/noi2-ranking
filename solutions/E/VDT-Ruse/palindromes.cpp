#include<iostream>
using namespace std;
int main()
{
    long long fl=0,N,i,j,pr,first,second,third,fourth,fifth,sixth;
    cin>>N;
    for(i=N-1;i>0;i--)
    {
        for(j=N-1;j>0;j--)
        {
            pr=j*i;
            if(pr<1000000 && pr>99999)
            {
                first=pr/100000;
                second=(pr/10000)%10;
                third=(pr/1000)%10;
                fourth=(pr/100)%10;
                fifth=(pr/10)%10;
                sixth=pr%10;
                if(first==sixth && second==fifth && third==fourth)
                {
                    fl=1;
                    break;
                }
            }
            if(pr<100000 && pr>9999)
            {
                first=pr/10000;
                second=(pr/1000)%10;
                third=(pr/100)%10;
                fourth=(pr/10)%10;
                fifth=pr%10;
                
                if(first==fifth && second==fourth)
                {
                    fl=1;
                    break;
                }
            }
            if(pr<10000 && pr>999)
            {
                first=pr/1000;
                second=(pr/100)%10;
                third=(pr/10)%10;
                fourth=pr%10;
                if(first==fourth && second==third)
                {
                    fl=1;
                    break;
                }
            }
            if(pr<1000 && pr>99)
            {
                first=pr/100;
                second=(pr/10)%10;
                third=pr%10;
                if(first==third)
                {
                    fl=1;
                    break;
                }
            }
            if(pr<100 && pr>9)
            {
                first=pr/10;
                second=pr%10;
                if(first==second)
                {
                    fl=1;
                    break;
                }
            }
        }
        if(fl==1) break;
    }
    if(j<i)
    {
        cout<<j<<" "<<i<<endl;
    }
    else cout<<i<<" "<<j<<endl;
    cout<<pr<<endl;
    return 0;
}