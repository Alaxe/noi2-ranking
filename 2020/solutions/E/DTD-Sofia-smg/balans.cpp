#include<iostream>
#include<cstring>
using namespace std;
int main(){
long long n,brNaaib=0,brNacid=0;
char a[1000000];
cin>>n;
for(int i=1; i<=n; i++){
    cin>>a[i];
    if(a[i]=='a' || a[i]=='b'){
        brNaaib++;
    }
    if(a[i]=='c' || a[i]=='d'){
        brNacid++;
    }

}
if(brNaaib==brNacid){
    cout<<n;
}


return 0;
}
