#include<bits/stdc++.h>
using namespace std;
string datestart;
long long dash,sd,sm,sy,ed,em,ey;
long long n;
void calendar(){
if(sd==31 && (sm==4 || sm==6 || sm==9 || sm==11)){
    sm++;
    sd=1;
}
if(sd==29 && sm==2 && sy==2019){
sd=1;
sm++;
}
if(sd==30 && sm==2 && sy==2020){
sd=1;
sm++;
}
if(sd==32 && (sm==1 || sm==3 || sm==5 || sm==7 || sm==8 || sm==10 || sm==12)){
sd=1;
sm++;
}
if(sd==1 && sm==13){
sm=1;
sy++;
}
}
int main(){
cin>>datestart;
cin>>n;
long long pon=2;
for(long long i=0;i<datestart.size();i++){
    if(datestart[i]!='/' && dash==0){
        ed=ed*10+(datestart[i]-'0');
    }
    if(datestart[i]!='/' && dash==1){
        em=em*10+(datestart[i]-'0');
    }
    if(datestart[i]!='/' && dash==2){
        ey=ey*10+(datestart[i]-'0');
    }
    if(datestart[i]=='/')dash++;
}
///1.01.2019 vtornik
sd=1;
sm=1;
sy=2019;

while(sd!=ed || sm!=em || sy!=ey){
    sd++;
    calendar();
    pon++;
    if(pon==8)pon=1;
}
long long day=0;
if(pon!=6 && pon!=7) day=1;
do{
pon++;
if(pon==8)pon=1;
sd++;
calendar();
if(pon==6 || pon==7)continue;
else day++;
}
while(day<n+1);
if(sd<10)cout<<0<<sd<<".";
else cout<<sd<<".";
if(sm<10)cout<<0<<sm<<".";
else cout<<sm<<".";
cout<<sy<<endl;
return 0;
}


