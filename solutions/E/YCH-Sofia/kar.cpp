#include<iostream>
using namespace std;
int main(){
long long s,t;
cin>>s;
t=s*2;
long long x[t],z[s],a=0,b=1,broi=0,broi1=0,p=0,r1;
for(int q=0;q<t;q++){
    cin>>x[q];
}
for(int w=0;w<s;w++){
    z[w]=x[a]*x[b];
    a=a+2;
    b=b+2;
    //cout<<z[w]<<endl;
}
for(int e=0;e<s;e++){
    p=e;
    //cout<<p<<endl;
   for(int r=0;r<s;r++){
        r1=r+1;
        if(z[r]<=z[p-1]){
            broi1++;
            //cout<<broi1<<endl;
        }
        p=p+1;
}
    if(broi1>broi){
            broi=broi1;
            //cout<<broi<<endl;
    }
    broi1=-4;
}
cout<<broi;
return 0;
}
//6 3 4 5 3 3 3 2 3 3 2 7 7
