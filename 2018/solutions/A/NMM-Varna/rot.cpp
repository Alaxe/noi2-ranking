#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int sma;
    cin>>sma;
    if(sma==10)
    {
        for(int i = 0; i < 4; i++)
        {
            long long m;
            cin>>m;
            if(m%9!=0)
            {
                cout<<0<<endl;
            }
            else
            {
                m/=9;
                int curr = 1;
                while(true)
                {
                    if(curr<=m)
                    {
                        curr*=10;
                        curr++;
                    }
                    else break;
                }
                curr/=10;
                for(int j = 1; j <= 9; j++ )
                {
                    if(m + curr*j <= curr*9)
                    {
                        cout<<j<<m + curr*j<<endl;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int q = 0; q < 4; q++)
        {
            string m;
            cin>>m;
            int mLen = m.length();
            unsigned long long mD = 0;
            for(int i = 0 ; i < mLen; i++)
            {
                mD *= sma;
                if(m[i] >= '0' && m[i]<= '9')
                {
                    mD += m[i] - '0';
                }
                else
                {
                    mD += m[i] - 'A' + 10;
                }
            }

            if(mD%(sma-1)!=0)
            {
                cout<<0<<endl;
            }
            else
            {
                mD/=(sma-1);
                int curr = 1, len = 1, maxn = 15;
                while(true)
                {
                    if(curr<=mD)
                    {
                        curr*=sma;
                        curr++;
                        len++;
                    }
                    else break;
                        maxn*=16;
                        maxn+=15;
                }
                curr/=sma;
                bool found = false;
                for(int j = 1; j < sma; j++ )
                {
                    if(mD + curr*j <= maxn && !found)
                    {
                        char s = 'A' + j-10;
                        long long res = mD+curr*j;

                        if(j<10)
                            cout<<j;
                        else
                            cout<<s;
                        string r = "";
                        while(true){
                            int q = res%sma;
                            if(q<10){
                                char p = q+'0';
                                r = p + r;
                            } else{
                                char p = q+'A'-10;
                                r = p + r;
                            }
                            res/=sma;
                            if(res==0)
                                break;
                        }
                            cout<<r<<endl;
                            found = true;
                    }
                }
            }
        }
    }
    return 0;
}
