#include <iostream>
using namespace std;
int main(){

long long n, i, j, x, t=0;
cin>>n;
long long ills[n][2];

for(i=0;i<n;i++){
    cin>>ills[i][0]>>ills[i][1];
}

cout<<endl;

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(ills[j][0]>ills[j+1][0]){
            swap(ills[j][0],ills[j+1][0]);
            swap(ills[j][1],ills[j+1][1]);
        }
    }
}

for(i=0;i<n;i++){
    if(ills[i][0]>t){t=ills[i][0]+ills[i][1];}
    else{t=t+ills[i][1];}
}

cout<<t-ills[i-1][0]<<endl<<endl;

return 0;
}
