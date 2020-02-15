#include<bits/stdc++.h>
using namespace std;

long long r=1,p=0,i,b[257];
string a;
char k,nel='?';

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin>>a;
k=a[0];
b[a[0]]++;
for(i=1;i<a.size();i++){
    if(nel!=a[i]){
        if(a[i]!=k){
            k=a[i];
            r=1;
        }else{
            r++;
            if(r==3){
                a[i]='a'+p;
                p++;
                r=0;
            }
        }
        b[a[i]]++;
        if(b[a[i]]>=(a.size()-a.size()%2)/2){
            nel=a[i];
        }
    }else{
        a[i]='a'+p;
        p++;
        r=0;
    }
}
cout<<a<<endl;
return 0;
}
