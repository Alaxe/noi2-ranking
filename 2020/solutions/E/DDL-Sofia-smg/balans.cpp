#include<iostream>
using namespace std;
int main(){
    int br,brab=0,brcd=0,i;
    cin>>br;
    char x[br];
    for(i=0;i<br;i++){
        cin>>x[i];
        if(x[i]=='a' || x[i]=='b')brab++;
        if(x[i]=='c' || x[i]=='d')brcd++;
    }

    for(i=1;brab!=brcd;i++){
        if(x[br-i]=='a' || x[br-i]=='b')brab--;
        if(x[br-i]=='c' || x[br-i]=='d')brcd--;
    }
    cout<<brab+brcd<<endl;
    return 0;
}
