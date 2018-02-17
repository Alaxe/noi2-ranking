#include<iostream>
using namespace std;
int main(){
long long kolkoZagubeniPechati,ovce,broqch,n=0,des,ed,e=1;
bool mahamLiSeOtCikala=true;
cin>>ovce>>kolkoZagubeniPechati;
long long zagubeniPechati[3],index;
for(index=0;index<kolkoZagubeniPechati;index++){
    cin>>zagubeniPechati[index];
}
for(index=kolkoZagubeniPechati;index<3;index++){
    zagubeniPechati[index]=0;
}
while(mahamLiSeOtCikala){
        mahamLiSeOtCikala=false;
for(broqch=e;n<ovce && !mahamLiSeOtCikala;n=n+1,broqch++){
    des=broqch/10;
    ed=broqch%10;
    if(des==zagubeniPechati[0] || des==zagubeniPechati[1] || des==zagubeniPechati[2] || ed==zagubeniPechati[0] || ed==zagubeniPechati[1] || ed==zagubeniPechati[2]){
       broqch=broqch+2;
      //  cout<<"vlizam";
        //mahamLiSeOtCikala=true;
         e=broqch;
    }
}
}
cout<<broqch-3;
return 0;
}
