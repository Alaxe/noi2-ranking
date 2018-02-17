#include<bits/stdc++.h>
using namespace std;
int start,final;
int need;
int add1,add2;
int dp[2][1<<13];
const int inf=1<<30;
const int mod=1<<30;
const int hello_world=int(1<<30)-1;
int AnswerProblem;
int main()
{
    cin>>start>>final;
    //start=2000,final=10000;add1=2;add2=1;
    need=final-start;
    cin>>add1>>add2;
    add2=0-add2;
    dp[0][0]=1;
    int dangerous=need-add1;
    dangerous=max(dangerous,0);
    int sure=0;
    int add12=add1+add2;
    int moment10=need+10;
    for (int moment=0;moment<moment10;moment++)///count of add1
    {
        dangerous=max(dangerous,sure);
        bool moment_bool=moment&1;
        bool moment_1_bool=moment_bool^1;

        for (int i=sure;i<moment10;i++)
            dp[moment_1_bool][i]=0;
        for (int i=sure;i<dangerous;i++)
        {
            dp[moment_1_bool][i+add1]+=dp[moment_bool][i];
            dp[moment_1_bool][i+add1]&=hello_world;
            dp[moment_1_bool][i+add12]+=dp[moment_bool][i];
            dp[moment_1_bool][i+add12]&=hello_world;
        }
        for (int i=dangerous;i<need;i++)
        {
            AnswerProblem+=dp[moment_bool][i];
            AnswerProblem&=hello_world;
        }
        sure+=add12;
    }
    ///256MB 0.1sec 50KB my source
   /* for (int moment=0;moment<32;moment++)
    {
        for (int i=0;i<64;i++)
            cout<<dp[moment][i]<<" ";
        cout<<endl;
    }*/
    cout<<AnswerProblem<<endl;
    return 0;
}
