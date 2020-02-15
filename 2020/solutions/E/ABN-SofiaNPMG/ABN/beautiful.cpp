#include <iostream>
using namespace std;
int main ()
{
    long long N,a=0,b=1,c=10;
    cin >> N;
    for(long long i=0; i<=N; i++)
    {
        if(i/1==b && i%10==1 || i/2==b && i%10==2 || i/3==b && i%10==3
                || i/4==b && i%10==4 || i/5==b && i%10==5 || i/6==b && i%10==6 ||
                i/7==b && i%10==7 || i/8==b && i%10==8 || i/9==b && i%10==9)
        {
            a++;
        }
        if(i==c)
        {
            c=c*10;
            b=b*10+1;
        }
    }
    cout << a ;
    cout << endl;
    return 0;
}
