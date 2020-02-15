#include<iostream>
using namespace std;
int main (){
long long n,ab=0,cd=0,g=0,ng=0;
cin>>n;
char red[n];
for(int i=0;i<n;i++){
    cin>>red[i];
    if(red[i]=='a' or red[i]=='b'){
        ab++;
    }
    if(red[i]=='c' or red[i]=='d'){
        cd++;
    }
    if(ab==cd){
        if(ng==0){
           ng=i+1;
        }else{
            if(g==0){
                g=i+1;
            }else{
                if(i+1>g){
                    g=i+1;
                    if(g>ng){
                        swap(ng,g);
                    }
                }
            }
        }
    }else{
        ng=0;
    }
}
cout<<ng;
return 0;
}
