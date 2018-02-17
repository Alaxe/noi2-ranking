#include<bits/stdc++.h>
using namespace std;
long long int table[101][101], sum=0, p1=0,p2, maxch=0, p3, p4, flag=0, p5, p6,maxch2=0;
string table2[101][101], s;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>table2[i][j];
            s=table2[i][j];
            if(s[0]>='2' && s[0]<='9') table[i][j]=s[0]-'0';
            else {
                if(s[0]=='T') table[i][j]=10;
                else if(s[0]=='J') table[i][j]=11;
                else if(s[0]=='Q') table[i][j]=12;
                else if(s[0]=='K') table[i][j]=13;
                else if(s[0]=='A') table[i][j]=1;

            }
        }

        p1=n;p2=1;
        sum+=table[p1][p2];
        for(int j=0;j<n*2-2;j++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(table[p1-1][p2]>table[p1][p2+1]) {sum+=table[p1-1][p2]; p1-=1;}
                    else if(table[p1-1][p2]<table[p1][p2+1]) {sum+=table[p1][p2+1];p2+=1;}
                   /* else if(table[p1-1][p2]==table[p1][p2+1]){
                        p3=p1-1;
                        p4=p2;
                        p5=p1;
                        p6=p2+2;
                        while(n*n-2){
                            if(table[p3-1][p4]>table[p5-1][p6] && table[p3-1][p4]>table[p5][p6+1] && table[p3-1][p4]>table[p3][p4+1]) {p1=p3-1;p2=p4;break;}
                            else if(table[p3-1][p4]<table[p5-1][p6] && table[p3][p4+1]<table[p5-1][p6] && table[p5-1][p6]>table[p5][p6+1]) {p1=p5-1;p3=p6;break;}
                            else if(table[p3][p4+1]>table[p5-1][p6] && table[p3][p4+1]>table[p5][p6+1] && table[p3-1][p4]<table[p3][p4+1]) {p1=p3;p2=p4+1;break;}
                            else if(table[p3-1][p4]<table[p5][p6+1] && table[p3][p4+1]<table[p5][p6+1] && table[p5-1][p6]<table[p5][p6+1]) {p1=p5;p3=p6+1;break;}
                           /* else
                            {
                                p3-=1;
                                p4+=1;
                                p5-=1;
                                p6+=1;
                            }
                        }
                    }*/
                }
            }
        }
        cout<<sum<<endl;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
