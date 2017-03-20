#include<iostream>

using namespace std;

int main()
{
int n,max=0,br=1;
cin>>n;
int r1,r2,rp1,rp2;
cin>>rp1>>rp2;
for(int i=n-1;i>0;i--){
    cin>>r1>>r2;
    if(r1<=rp2&&r2<=rp1){
        
        br++;
    }
    else{
        if(br>max)max=br;
        br=1;
        
        
    }
}
if(r1<=rp2&&r2<=rp1){
        
        
    }
    else{
        if(br>max)max=br;
        br=1;
        
        
    }
cout<<max;
return 0;
}
