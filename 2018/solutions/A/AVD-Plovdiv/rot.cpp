#include<bits/stdc++.h>
using namespace std;
string ans[4];
string tek;
int b;
map<char,int>val;
map<int,char>obval;
string solve()
{
    int sum=0;
    for(int i=0;i<tek.size();i++)
        sum+=val[tek[i]];
    if(sum%(b-1)!=0)
        return "0";
    string tekdiv;
    int i=1,div=0;
    if(tek[0]==obval[b-1])
        tekdiv='1';
    else if(tek.size()==1)
    {
        return "0";
    }
    else
    {
        div=val[tek[0]]*b+val[tek[1]];
        tekdiv='0';
        tekdiv+=obval[div/(b-1)];
        div=div%(b-1);
        i=2;
    }
    for(;i<tek.size();i++)
    {
        div=div*b+val[tek[i]];
        tekdiv+=obval[div/(b-1)];
        div=div%(b-1);
    }
    string newnum=tekdiv;
    int naum=0;
    for(int i=newnum.size()-1;i>=0;i--)
    {
        int sum=val[tekdiv[i]]+1+naum;
        naum=0;
        if(sum>=b)
        {
            naum=1;
            newnum[i]=obval[sum%b];
        }
        else
            newnum[i]=obval[sum];
    }
    string thebiggernum=newnum.substr(1,newnum.size()-1)+newnum[0];
    return (thebiggernum>newnum)?(newnum):("1"+newnum);
}
int main()
{
    obval[0]='0';
    obval[1]='1';
    obval[2]='2';
    obval[3]='3';
    obval[4]='4';
    obval[5]='5';
    obval[6]='6';
    obval[7]='7';
    obval[8]='8';
    obval[9]='9';
    obval[10]='A';
    obval[11]='B';
    obval[12]='C';
    obval[13]='D';
    obval[14]='E';
    obval[15]='F';
    val['0']=0;
    val['1']=1;
    val['2']=2;
    val['3']=3;
    val['4']=4;
    val['5']=5;
    val['6']=6;
    val['7']=7;
    val['8']=8;
    val['9']=9;
    val['A']=10;
    val['B']=11;
    val['C']=12;
    val['D']=13;
    val['E']=14;
    val['F']=15;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>b;
    cin>>tek;
    ans[0]=solve();
    cin>>tek;
    ans[1]=solve();
    cin>>tek;
    ans[2]=solve();
    cin>>tek;
    ans[3]=solve();
    cout<<ans[0]<<endl<<ans[1]<<endl<<ans[2]<<endl<<ans[3]<<endl;
    return 0;
}
