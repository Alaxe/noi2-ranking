#include <iostream>
#include <cstring>
using namespace std;

string n;
bool propusni[200005];
long long i,j,br,br2;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    cin >> n;
    for(i=0;i<n.size();i++){
        if(n[i]=='+'){
            br=0;
            br2=0;
            for(j=i+1;n[j]=='(';j++){
                propusni[j]=true;
                br++;
            }
            for(;br!=0;j++){
                if(n[j]==')'){
                    if(br2==0){
                        propusni[j]=true;
                        br--;
                    }
                    br2--;
                }
                if(n[j]=='('){
                    br2++;
                }
            }
            br=0;
            br2=0;/*
            for(j=i-1;n[j]==')';j--){
                propusni[j]=true;
                br++;
            }
            for(;br!=0;j--){
                if(n[j]=='('){
                    if(br2==0){
                        propusni[j]=true;
                        br--;
                    }
                    br2--;
                }
                if(n[j]==')'){
                    br2++;
                }
            }*/
        }
    }
    for(i=0;i<n.size();i++){
        if(!propusni[i]){
            cout << n[i];
        }
    }
    cout << endl;
return 0;
}
