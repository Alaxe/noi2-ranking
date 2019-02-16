#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int tek=1;
int i,p;
int ind=0;
bool namerihli=false;
while(namerihli!=true){
    for(i=1;i<=tek;i++){
        if(n==i){namerihli=true;ind++;break;}
        if(namerihli==false){
        ind++;
        }
    }

    for(i=tek-1;i>=1;i--){
        if(i==n){namerihli=true;ind++;break;}
        if(namerihli==false){
        ind ++;
        }
    }
    tek++;
}
cout<<ind;
}
