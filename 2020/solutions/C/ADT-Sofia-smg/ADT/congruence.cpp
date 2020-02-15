#include <bits/stdc++.h>
using namespace std;

long long indPoGolemina[30];
string a;
long long br=0;

int main () {

cin>>a;

for(long long i=0 ; i<a.size() ; i++){
    for(long long j=0 ; j<a.size() ; j++){
        if(a[i]>a[j])indPoGolemina[i]++;
    }
}

for(long long i=0 ; i<a.size() ; i++){
    for(long long j=i+1 ; j<a.size() ; j++ ){
        if(indPoGolemina[i]==indPoGolemina[j]){
            br++;
            for(long long k=0 ; k<a.size() ; k++){
                if(indPoGolemina[i]<indPoGolemina[k]){
                    indPoGolemina[k]--;
                }
            }
        }
    }
}

for(long long i=0 ;i<a.size() ; i++){
    cout<<char(int('A')+indPoGolemina[i]);
}
cout<<endl;
for(long long i=0 ;i<a.size() ; i++){
    cout<<char(int('Z')-(a.size()-br-indPoGolemina[i]-1));
}
cout<<endl;
    return 0;
}
