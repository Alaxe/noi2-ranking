#include<iostream>
using namespace std;
int main()
{
    long long N,brCHisla,d=0,kopie=N;
    cin>>N;
    if(N<10)
    {
        brCHisla=N;
        cout<<brCHisla;
    }

    {
        brCHisla=9;
        for(;N>=10;N--)
        {
          while(N%10==N/10)
            {
                brCHisla++;
            }
        }
            cout<<brCHisla;
    }
    return 0;
}
