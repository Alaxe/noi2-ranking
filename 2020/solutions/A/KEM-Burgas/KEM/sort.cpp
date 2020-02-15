#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int A[n],B[n-1];
    for(int i=0; i<=n-1; i++)
        cin>>A[i];
    int S=0;
    for(int i=0; i<n-1; i++)
        B[i]=A[i+1]-A[i];
    for(int i=0; i<n-1; i++)
    {
        while(B[i]<0)
        {

            int RightEnd=n-1-i;
            int LeftEnd=i+1;
            int RightPos=i;
            int LeftPos=i;
            do
            {
                RightPos++;
            }
            while(B[RightPos]<=0&&RightPos<=n-2);

            do
            {
                LeftPos--;
            }
            while(LeftPos>=0&&B[LeftPos]<=0);

            if(RightEnd>LeftEnd)
            {
                if(LeftPos>-1&&RightPos<n-1)
                {
                    if(LeftPos+RightPos<2*i)
                    {
                        B[RightPos]--;
                        S+=RightPos-i;
                    }
                    if(LeftPos+RightPos>2*i)
                    {
                        B[LeftPos]--;
                        S+=i-LeftPos;
                    }
                    if(LeftPos+RightPos==2*i)
                    {
                        B[LeftPos]--;
                        S+=i-LeftPos;
                    }
                }
                if(LeftPos==-1&&RightPos<n-1)
                {
                    if(LeftPos+RightPos<2*i)
                    {
                        B[RightPos]--;
                        S+=RightPos-i;
                    }
                    if(LeftPos+RightPos>2*i)
                    {

                        S+=i-LeftPos;
                    }
                    if(LeftPos+RightPos==2*i)
                    {

                        S+=i-LeftPos;
                    }
                }
                if(LeftPos>-1&&RightPos==n-1)
                {
                    if(LeftPos+RightPos<2*i)
                    {
                        S+=RightPos-i;
                    }
                    if(LeftPos+RightPos>2*i)
                    {
                        B[LeftPos]--;
                        S+=i-LeftPos;
                    }
                    if(LeftPos+RightPos==2*i)
                    {
                        B[LeftPos]--;
                        S+=i-LeftPos;
                    }
                }
                if(LeftPos==-1&&RightPos==n-1)
                {
                    S+=i+1;
                }
            }
            if(RightEnd<LeftEnd)
            {
                if(LeftPos>-1&&RightPos<n-1)
                {

                    if(LeftPos+RightPos<2*i)
                    {
                        B[RightPos]--;
                        S+=RightPos-i;
                    }
                    if(LeftPos+RightPos>2*i)
                    {
                        B[LeftPos]--;
                        S+=i-LeftPos;
                    }
                    if(LeftPos+RightPos==2*i)
                    {
                        /*cout<<"X="<<i<<endl;
                        cout<<"LE="<<LeftEnd<<endl;
                        cout<<"LP="<<LeftPos<<endl;
                        cout<<"RE="<<RightEnd<<endl;
                        cout<<"RP="<<RightPos<<endl;*/
                        B[RightPos]--;
                        S+=RightPos-i;
                    }
                }
                if(LeftPos==-1&&RightPos<n-1)
                {
                    if(LeftPos+RightPos<2*i)
                    {
                        B[RightPos]--;
                        S+=RightPos-i;
                    }
                    if(LeftPos+RightPos>2*i)
                    {
                        S+=i-LeftPos;
                    }
                    if(LeftPos+RightPos==2*i)
                    {
                        B[RightPos]--;
                        S+=RightPos-i;
                    }
                }
                if(LeftPos>-1&&RightPos==n-1)
                {
                    if(LeftPos+RightPos<2*i)
                    {

                        S+=RightPos-i;
                    }
                    if(LeftPos+RightPos>2*i)
                    {
                        B[LeftPos]--;
                        S+=i-LeftPos;
                    }
                    if(LeftPos+RightPos==2*i)
                    {
                        S+=RightPos-i;
                    }
                }
                if(LeftPos==-1&&RightPos==n-1)
                {
                    S+=n-1-i;
                }
            }
            if(RightEnd==LeftEnd)
            {
                if(LeftPos>-1&&RightPos<n-1)
                {
                    if(LeftPos+RightPos<2*i)
                    {
                        B[RightPos]--;
                        S+=RightPos-i;
                    }
                    if(LeftPos+RightPos>2*i)
                    {
                        B[LeftPos]--;
                        S+=i-LeftPos;
                    }
                    if(LeftPos+RightPos==2*i)
                    {
                        B[LeftPos]--;
                        S+=i-LeftPos;
                    }
                }
                if(LeftPos==-1&&RightPos<n-1)
                {
                    if(LeftPos+RightPos<2*i)
                    {
                        B[RightPos]--;
                        S+=RightPos-i;
                    }
                    if(LeftPos+RightPos>2*i)
                    {
                        S+=i-LeftPos;
                    }
                    if(LeftPos+RightPos==2*i)
                    {
                        S+=i-LeftPos;
                    }
                }
                if(LeftPos>-1&&RightPos==n-1)
                {
                    if(LeftPos+RightPos<2*i)
                    {
                        S+=RightPos-i;
                    }
                    if(LeftPos+RightPos>2*i)
                    {
                        B[LeftPos]--;
                        S+=i-LeftPos;
                    }
                    if(LeftPos+RightPos==2*i)
                    {
                        B[LeftPos]--;
                        S+=i-LeftPos;
                    }
                }
                if(LeftPos==-1&&RightPos==n-1)
                {
                    S+=i+1;
                }
            }
            B[i]++;
        }
    }
    cout<<S<<endl;
    return 0;
}



























