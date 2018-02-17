#include<iostream>

using namespace std;
int pal(int a){
int br=0;
int e=a;
while(e!=0){
    e/=10;
    br++;
}
int b=1,bcpy=1,chch,chch2;
for(int i=br-1;i>0;i--){
    
    
    bcpy*=10;
}
while(b<bcpy){
    chch=a/bcpy%10;
    chch2=a/b%10;
    if(chch!=chch2){
        return 1;
    }
    b*=10;
    bcpy/=10;
}
return 2;
}
int main()
{int n,ch;
cin>>n;
for(int i=n;i>0;i--){
    for(int j=n;j>0;j--){
            ch=j*i;
        if(pal(ch)==2){
            if(j>i)swap(j,i);
            cout<<j<<" "<<i<<endl<<ch<<endl;
            return 0;
        }
    }
}
return 0;
}
