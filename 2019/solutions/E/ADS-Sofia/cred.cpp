#include <iostream>
using namespace std;
int main()
{
    int n;
    int m;
    int c=0;
    int br=0;
    int pc;
    int vc;
    int tc;
    int cc;
    cin>>n>>m;
    do{
        if(n/10>0)
        {
            if(n/100>0)
            {
                if(n/1000>0)
                {
                    pc=n/1000;
                    vc=(n/100)%10;
                    tc=(n/10)%10;
                    cc=n/10;
                    n=n+pc+vc+tc+cc;

                    br++;

                }
                else
                {
                   pc=n/100;
                   vc=(n/10)%10;
                   tc=n%10;
                   n=n+pc+vc+tc;

                   br++;

                }
            }
            else
            {
                pc=n/10;
                vc=n%10;
                n=n+pc+vc;

                br++;


            }
        }
        else
        {
            n=n+n;

            br++;

        }
    }while(n<m);
    cout<<br;



    return 0;
}
