#include <iostream>
using namespace std;
int main(){
int brHoda,kudeSvurshva;
cin>>brHoda;
cin>>kudeSvurshva;
bool chashi[3]={0,0,0};
if(kudeSvurshva==0){
    chashi[0]=true;
}else{
    if(kudeSvurshva==1){
        chashi[1]=true;
    }else{
        chashi[2]=true;
    }
}
for(int i=brHoda;i>=0;i--){
    if(i%2==0){
        swap(chashi[1],chashi[2]);
    }else{
        swap(chashi[0],chashi[1]);
    }
}
if(chashi[0]==1){
    cout<<0<<endl;
}
if(chashi[1]==1){
    cout<<1<<endl;
}if(chashi[2]==1){
    cout<<2<<endl;
}
return 0;
}

