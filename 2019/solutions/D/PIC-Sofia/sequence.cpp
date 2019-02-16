#include<iostream>
using namespace std;
int main(){
int n,k,times_met_n=0,current_num,in_line=0,M=1;
cin>>n>>k;
while(times_met_n<k)
    {
    for(int i=1;i<=M;i++)
        {
        //cout<<i;
        in_line++;
        if(i==n)
            {
            times_met_n++;
            if(times_met_n==k)
                {
                //cout<<endl<<"ANSWER: "<<in_line<<"     ";
                cout<<in_line;
                goto final_line;
                }
            }
        }

    for(int i=M-1;i>0;i--)
        {
        //cout<<i;
        in_line++;
        if(i==n)
            {
            times_met_n++;
            if(times_met_n==k)
                {
                //cout<<endl<<"ANSWER: "<<in_line<<"     ";
                cout<<in_line;
                goto final_line;
                }
            }
        }
    M++;
    }
final_line:
cout<<endl;

return 0;
}
