#include<iostream>
using namespace std;
char l[3];
int main(){
long long n,l,a;
cin>>n;
cin>>l;

for(i=1;i<=n;i++){
for(j=1;j<=n;j++) {
    while(j>0){
        a=j%10;
        if(a==l[0] or a==l[1] or a ==l[2]){
                cin>>>l[0]>>l[1]>>l[2];
        }
        j=j/10;
    }
}

}


    }
}
return 0;
}
