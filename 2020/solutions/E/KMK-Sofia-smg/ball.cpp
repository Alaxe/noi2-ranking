#include<iostream>
using namespace std;
int main()
{
    long long brhodove,chasha;
    bool chetenHodLiSme;
    ///cin>>brhodove>>chasha;
    brhodove=1;
    chasha=1;
    for(long long i=brhodove;i>0;i--)
    {
    ///_______________________________
        if(i%2==0)
        {
            chetenHodLiSme=true;
        }
        else
        {
            chetenHodLiSme=false;
        }
    ///________________________________
        if(chasha==1 && chetenHodLiSme)
        {
            chasha++;
        }
        else
        {
           if(chasha==1 && !chetenHodLiSme)
            {
                chasha--;
            }
            else
            {
               if(chasha==0 && !chetenHodLiSme)
                {
                    chasha++;
                }
                else
                {
                    if(chasha==2 && chetenHodLiSme)
                    {
                        chasha--;
                    }
                }

            }

        }

    }
    cout<<chasha;
    return 0;
}
