#include <iostream>
using namespace std;
int main (){
long long broiCvetq,broiChisla=0;
cin>>broiCvetq;
long long visochinaNaCvete[broiCvetq],a,broiKapkiVodaZaCvete;
for(a=0;a<broiCvetq;a=a+1){
    cin>>visochinaNaCvete[a];
}
cin>>broiKapkiVodaZaCvete;
for(a=1;a<broiCvetq;a=a+1){
    while(visochinaNaCvete[a-1]!=visochinaNaCvete[a]){
        if(visochinaNaCvete[a-1]<visochinaNaCvete[a]){
            broiChisla=broiChisla+broiKapkiVodaZaCvete;
            visochinaNaCvete[a-1]=visochinaNaCvete[a-1]+1;
        }else{
        if(visochinaNaCvete[a-1]>visochinaNaCvete[a]){
            broiChisla=broiChisla+25;
            visochinaNaCvete[a]=visochinaNaCvete[a]+1;
        }
        }
        if(visochinaNaCvete[a-1]==visochinaNaCvete[a]){
           visochinaNaCvete[a-1]=visochinaNaCvete[a];
        }
    }
}
cout<<broiChisla<<"\n";
return 0;
}
