#include<bits/stdc++.h>
using namespace std;
long long buk[35];
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string a;
getline(cin,a);
long long s=a.size();
for(long long i=0;i<s;i++){
    buk[a[i]-'a']++;

}
long long m=s/2;
long long broi=1;
long long t=0;
for(long long i=0;i<s;i++){

    if(a[i]==a[i+1]){
        broi++;
    }
    else{
        broi=1;
    }
    if(buk[a[i]-'a']>m && broi>3){
           broi=0;
           for(long long i2=t%26;i2<26;i2++){
                long long h=i2;;
            if(buk[h]<m && a[i+1]!=i+'a'){
                    buk[a[i]-'a']--;
                a[i]='a'+i2;
           buk[i2]++;
           t++;

           break;
            }
           }
    }

} t=0;
broi=1;
for(long long i=0;i<s;i++){

    if(a[i]==a[i+1]){
        broi++;
    }
    else{
        broi=1;
    }
    if(buk[a[i]-'a']>m or broi>3){
           broi=1;

           for(long long i2=t%26;i2<26;i2++){
                long long h=i2;;
            if(buk[h]<m && a[i+1]!=i+'a'){
                    buk[a[i]-'a']--;
                a[i]='a'+i2;
           buk[i2]++;

           t++;
           break;
            }
           }
    }

}
cout<<a;

return 0;
}
