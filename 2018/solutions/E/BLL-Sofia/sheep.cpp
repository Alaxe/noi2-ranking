#include<iostream>
using namespace std;
int main(){
long long broiOvce,broiZagubeniPechatcheta,broiLipstvashtiCifri=0,broiNamereniChisla=0;
long long probvanoChislo=1,a,b,c,d,e,f,NbroiLipstvashtiCifri;
cin>>broiOvce>>broiZagubeniPechatcheta;
a=probvanoChislo;
broiLipstvashtiCifri=broiZagubeniPechatcheta;
long long LipstvashtiCifri[broiZagubeniPechatcheta];
NbroiLipstvashtiCifri=broiLipstvashtiCifri;
for( ;broiZagubeniPechatcheta>0;broiZagubeniPechatcheta=broiZagubeniPechatcheta-1){
    cin>>LipstvashtiCifri[broiZagubeniPechatcheta];
}
for( ;broiLipstvashtiCifri>0;broiLipstvashtiCifri--){
for( ;broiNamereniChisla!=broiOvce;probvanoChislo++){
if(NbroiLipstvashtiCifri==1){
    if((probvanoChislo>0 and probvanoChislo<10) and
       (probvanoChislo!=LipstvashtiCifri[broiLipstvashtiCifri])){
        broiNamereniChisla=broiNamereniChisla+1;
    }
    if(probvanoChislo>=10 and probvanoChislo<100){
        a=probvanoChislo%10;
        b=probvanoChislo/10;
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=100 and probvanoChislo<1000){
        a=probvanoChislo%10;
        c=probvanoChislo/100;
        b=probvanoChislo/10-c*10;
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=1000 and probvanoChislo<10000){
        a=probvanoChislo%10;
        d=probvanoChislo/1000;
        c=probvanoChislo/100-d*10;
        b=probvanoChislo/10-(d*100+c*10);
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=10000 and probvanoChislo<100000){
        a=probvanoChislo%10;
        e=probvanoChislo/10000;
        d=probvanoChislo/1000-e*10;
        c=probvanoChislo/100-(e*100+d*10);
        b=probvanoChislo/10-(e*1000+d*100+c*10);
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
        if(probvanoChislo>=100000 and probvanoChislo<1000000){
        a=probvanoChislo%10;
        f=probvanoChislo/100000;
        e=probvanoChislo/10000-f*10;
        d=probvanoChislo/1000-(f*100+e*10);
        c=probvanoChislo/100-(f*1000+e*100+d*10);
        b=probvanoChislo/10-(f*10000+e*1000+d*100+c*10);
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri]
               and f!=LipstvashtiCifri[broiLipstvashtiCifri]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
}
if(NbroiLipstvashtiCifri==2){
    if((probvanoChislo>0 and probvanoChislo<10) and
       (probvanoChislo!=LipstvashtiCifri[broiLipstvashtiCifri]
        and probvanoChislo!=LipstvashtiCifri[broiLipstvashtiCifri-1])){
        broiNamereniChisla=broiNamereniChisla+1;
    }
    if(probvanoChislo>=10 and probvanoChislo<100){
        a=probvanoChislo%10;
        b=probvanoChislo/10;
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-1]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=100 and probvanoChislo<1000){
        a=probvanoChislo%10;
        c=probvanoChislo/100;
        b=probvanoChislo/10-c*10;
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-1]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=1000 and probvanoChislo<10000){
        a=probvanoChislo%10;
        d=probvanoChislo/1000;
        c=probvanoChislo/100-d*10;
        b=probvanoChislo/10-(d*100+c*10);
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri-1]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=10000 and probvanoChislo<100000){
        a=probvanoChislo%10;
        e=probvanoChislo/10000;
        d=probvanoChislo/1000-e*10;
        c=probvanoChislo/100-(e*100+d*10);
        b=probvanoChislo/10-(e*1000+d*100+c*10);
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               ){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=100000 and probvanoChislo<1000000){
        a=probvanoChislo%10;
        f=probvanoChislo/100000;
        e=probvanoChislo/10000-f*10;
        d=probvanoChislo/1000-(f*100+e*10);
        c=probvanoChislo/100-(f*1000+e*100+d*10);
        b=probvanoChislo/10-(f*10000+e*1000+d*100+c*10);
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri]
               and f!=LipstvashtiCifri[broiLipstvashtiCifri]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and f!=LipstvashtiCifri[broiLipstvashtiCifri-1]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
}
if(NbroiLipstvashtiCifri==3){
    if((probvanoChislo>0 and probvanoChislo<10) and
       (probvanoChislo!=LipstvashtiCifri[broiLipstvashtiCifri]
        and probvanoChislo!=LipstvashtiCifri[broiLipstvashtiCifri-1]
        and probvanoChislo!=LipstvashtiCifri[broiLipstvashtiCifri-2])){
        broiNamereniChisla=broiNamereniChisla+1;
    }
    if(probvanoChislo>=10 and probvanoChislo<100){
        a=probvanoChislo%10;
        b=probvanoChislo/10;
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-2]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=100 and probvanoChislo<1000){
        a=probvanoChislo%10;
        c=probvanoChislo/100;
        b=probvanoChislo/10-c*10;
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-2]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=1000 and probvanoChislo<10000){
        a=probvanoChislo%10;
        d=probvanoChislo/1000;
        c=probvanoChislo/100-d*10;
        b=probvanoChislo/10-(d*100+c*10);
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri-2]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=10000 and probvanoChislo<100000){
        a=probvanoChislo%10;
        e=probvanoChislo/10000;
        d=probvanoChislo/1000-e*10;
        c=probvanoChislo/100-(e*100+d*10);
        b=probvanoChislo/10-(e*1000+d*100+c*10);
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri-2]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
    if(probvanoChislo>=100000 and probvanoChislo<1000000){
        a=probvanoChislo%10;
        f=probvanoChislo/100000;
        e=probvanoChislo/10000-f*10;
        d=probvanoChislo/1000-(f*100+e*10);
        c=probvanoChislo/100-(f*1000+e*100+d*10);
        b=probvanoChislo/10-(f*10000+e*1000+d*100+c*10);
            if(a!=LipstvashtiCifri[broiLipstvashtiCifri]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri]
               and f!=LipstvashtiCifri[broiLipstvashtiCifri]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and f!=LipstvashtiCifri[broiLipstvashtiCifri-1]
               and a!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and b!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and c!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and d!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and e!=LipstvashtiCifri[broiLipstvashtiCifri-2]
               and f!=LipstvashtiCifri[broiLipstvashtiCifri-2]){
               broiNamereniChisla=broiNamereniChisla+1;
               }
    }
}
}
}
probvanoChislo--;
cout<<probvanoChislo;
return 0;
}
