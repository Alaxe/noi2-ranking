#include<iostream>
#include<cstring>
using namespace std;
char a[1302];
int i=0,b[1302]={0};
bool palr(char x[],int y[])
{int br=0;
for(int j=0;j<i;j++)
{if((x[j]-'0')>(y[j])) return 0;
if((x[j]-'0')<(y[j])) return 1;
if((x[j]-'0')==(y[j])) br++;}
if(br==i) return 0;}
bool palv(int x[])
{int br=0;
for(int j=0;j<i/2;j++)
{if(x[j]!=x[i-j-1]) return 0;
else br++;}
if(br==(i/2)) return 1;}
int main(){
    while(cin>>a[i])
    {i++;}
    for(int k=0;k<=9;k++)
    {for(int j=0;j<=i/2;j++)
    {b[j]=(a[j]-'0')+k;
    b[i-j-1]=(a[j]-'0')+k;
    if(palv(b)==1 && palr(a,b)==1) {for(int o=0;o<i;o++) {cout<<b[o];}cout<<endl; k=9+1; j=i/2+1;}
    if(( palr(a,b)!=1) && j==i/2){for(int g=i/2;g>=0;g--)
    {b[g]=(a[g]-'0')+1;
    b[i-g-1]=(a[g]-'0')+1;
    if(palv(b)==1 && palr(a,b)==1) {for(int o=0;o<i;o++) {cout<<b[o];}cout<<endl; k=9+1; j=i/2+1; g=0;}}}}}
    system("pause");
    return 0;
}
