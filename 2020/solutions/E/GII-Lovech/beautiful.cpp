#include <iostream>
using namespace std;
int main()
{
    int N, bN, j, h;
    cin>>N;
    for(int i = 1; i <= N; i++)
    {
        int g=i/11;
        if(i<10)
        bN=9;
        else if(i>10&&i<100&&i/10==g&&i%11==0)
        {
            bN++;
        }
        else
        {
            j=i-i/100*100;
            h=i-i/100*100;
            h=h-j/10;
            if(i/100==j/10==h)
            {
                bN++;
            }
        }

    }

    cout<<bN<<endl;

    return 0;
}
