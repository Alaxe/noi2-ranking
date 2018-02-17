#include <iostream>
using namespace std;

string s;

int n,p,sum,pp;

struct TEel{
    int st,sum,nom;
};

TEel a[101][101];

void Rec(int s,int r){
int i;
        if(r<n){
            if(a[s][r+1].sum<a[s][r].sum+a[s][r+1].st){
            a[s][r+1].sum=a[s][r].sum+a[s][r+1].st;
            a[s][r+1].nom=a[s][r].nom+1;
            if(a[s][r+1].nom<p)Rec(s,r+1);
            }
        }
        if(s>1){
            if(a[s-1][r].sum<a[s][r].sum+a[s-1][r].st){
            a[s-1][r].sum=a[s][r].sum+a[s-1][r].st;
            a[s-1][r].nom=a[s][r].nom+1;
            if(a[s-1][r].nom<p)Rec(s-1,r);
            }
        }
}

int main()
{
int i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>s;
            //cout<<s[0]<<endl;
            if(s[0]>='2' && s[0]<='9'){
                a[i][j].st=s[0]-'0';
            }
            else{
                if(s[0]=='A')a[i][j].st=1;
                else
                if(s[0]=='T')a[i][j].st=10;
                else
                if(s[0]=='J')a[i][j].st=11;
                else
                if(s[0]=='Q')a[i][j].st=12;
                else
                if(s[0]=='K')a[i][j].st=13;

            }
            //cout<<a[i][j]<<" ";
        }
       // cout<<endl;
    }
    p=2*n-2;
    pp=0;
    //cout<<p<<endl;
    a[n][1].sum=a[n][1].st;
    a[n][1].nom=0;
    Rec(n,1);
    int Max=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
           // cout<<a[i][j].sum<<" ";
            if(Max<a[i][j].sum)Max=a[i][j].sum;
        }
        //cout<<endl;
    }
    //cout<<endl;
    cout<<Max<<endl;

    return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
