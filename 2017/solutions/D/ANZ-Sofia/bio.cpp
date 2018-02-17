#include<iostream>
using namespace std;
int main (){
bool nameren=false, first=false, second=false, fiz=false, emo=false, inte=false, found=false;
char a[4];
long long fizikD, fizikM, emotionD, emotionM, intelD, intelM, d, m, iD=1, iM=1, fizR, emoR, intR, i=0, x, y, z, dni;
cin>>fizikD>>a[0]>>fizikM>>emotionD>>a[1]>>emotionM>>intelD>>a[2]>>intelM>>d>>a[3]>>m;
d--;
while(nameren==false){
    d++;
    i++;
    if(m%2==1){
        if(d==32){
            d=1;
            m++;
        }
    }else{
        if(m==2){
            if(d==29){
                d=1;
                m++;
            }
        }else{
            if(d==31){
                d=1;
                m++;
            }
        }
    }
    if(m==13){
        d=1;
        m=1;
    }
    //cout<<d;
    if(d==fizikD and m==fizikM and first==false){
        fizR=i;
        first=true;
        fiz=true;
    }
    if(d==emotionD and m==emotionM and first==false){
        emoR=i;
        first=true;
        emo=true;
    }
    if(d==intelD and m==intelM and first==false){
        intR=i;
        first=true;
        inte=true;
    }
    if(d==fizikD and m==fizikM and second==false and fiz==false){
        fizR=i;
        second=true;
        fiz=true;
    }
    if(d==emotionD and m==emotionM and second==false and emo==false){
        emoR=i;
        second=true;
        emo=true;
    }
    if(d==intelD and m==intelM and second==false and inte==false){
        intR=i;
        second=true;
        inte=true;
    }
    if(d==intelD and m==intelM and nameren==false and inte==false){
        intR=i;
        nameren=true;
        inte=true;
    }
    if(d==fizikD and m==fizikM and nameren==false and fiz==false){
        fizR=i;
        nameren=true;
    }
    if(d==emotionD and m==emotionM and nameren==false and emo==false){
        emoR=i;
        nameren=true;
    }
    inte=false;
    emo=false;
    fiz=false;
}
/*for(x=0;x<924 and found==false;x++){ ///33
    for(y=x;y<x+180;y++){ ///28
        for(z=x;z<x+288;z++){ ///23
            if(z*23-fizR==x*33-intR and z*23-fizR==y*28-emoR and y*28-emoR==x*33-intR and z*23-fizR!=0){
                dni=z*23-fizR;
                found=true;
            }
        }
    }
}*/
//cout<<fizR<<" "<<emoR<<" "<<intR<<" ";
for(dni=0;found==false;dni++){
    if(dni%23==fizR%23 and dni%28==emoR%28 and dni%33==intR%33 and dni!=1 and dni!=0){
        cout<<dni-1;2
        found=true;
    }
}
return 0;
}
