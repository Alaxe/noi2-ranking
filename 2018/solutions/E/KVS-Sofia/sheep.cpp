#include<iostream>
using namespace std;
int main(){
    long long n,l,ch,brOtk=0,i,h;
    cin>>n>>l;
    int izg[l];
    for(i=0;i<l;i++){
        cin>>izg[i];
    }
    for(ch=1;3<5;ch++){
        h=ch;
        while(h>0){
            for(i=0;i<l;i++){
                if(h%10==izg[i]){
                    h=-1;
                }
            }
            if(h!=-1){h=h/10;}
        }
        if(h==0){
            brOtk++;
            if(brOtk==n){
                cout<<ch;
                return 0;
            }
        }
    }
return 0;
}
