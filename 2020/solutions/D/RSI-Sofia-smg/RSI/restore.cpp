#include<iostream>
using namespace std;
int main (){

bool r=false;
int n,a[100000],br=0;

cin>>n;

for(int i=0;i<n;i++){
    cin>>a[i];
}

for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[j]>a[i]){
            br++;
        }
    }
    a[i]=br;
    br=0;
}

for(int i=0;i<n;i++){
    if(r){
        cout<<" "<<a[i];
    }else{
        cout<<a[i];
        r=true;
    }
}


return 0;
}

