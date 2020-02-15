#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,i=0;
    cin>>N;
    for(int br=N; br!=0; br--)
    {
        if(br>=10&&br<1000)
        {
            if(br<100)
            {
                if(br%10==br/10)
                {
                    i++;
                }
            }
            if(br>100&br<1000)
            {
                if(br%10==(br&100)/10==br/100)
                    i++;
            }

        }

    }
    if(N>100&N<1000)
    {
        i++;
    }
    i+=9;
    if(N<10)
    {
        i=N;
    }
    cout<<i<<endl;
    return 0;
}
