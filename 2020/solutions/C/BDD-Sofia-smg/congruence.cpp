#include<iostream>
using namespace std;
    bool used[26];
    char changed[26];
int main (){
    string duma;
    long long i,h=0,d,br=0,k=0;
    cin>>duma;
    for(i=0;;i++){
        if(duma[i]>='A' && duma[i]<='Z'){}else{
            break;
        }
        if(used[duma[i]-'A']==false){
            used[duma[i]-'A']=true;
            br++;
        }
        if(br==26){
            break;
        }
    }
    d=i;
    if(br==26){
        cout<<duma<<"\n"<<duma<<"\n";
    }else{
        for(i=0;i<26;i++){
            if(used[i]==true){
                changed[i]='A'+k;
                k++;
            }
        }
        for(i=0;duma[i]>='A' && duma[i]<='Z';i++){
            if(used[duma[i]-'A']==true){
                cout<<changed[duma[i]-'A'];
            }
        }
        for(i=0;i<26;i++){
            if(used[i]==true){
                changed[i]='Z'-br+h+1;
                h++;
            }
        }
        cout<<"\n";
        for(i=0;duma[i]>='A' && duma[i]<='Z';i++){
            if(used[duma[i]-'A']==true){
                cout<<changed[duma[i]-'A'];
            }
        }
    }
return 0;
}
