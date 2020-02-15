#include<iostream>
#include<string>
using namespace std;
unsigned long long d,i,a[27],br=1,j,k,n,p;
string s;
int main()
{
cin>>s;
d=s.size();
for(i=0;i<d;i++){
    a[s[i]-'a'+1]++;
}
for(i=1;i<d;i++){
    if(s[i]==s[i-1]) br++;
    else br=1;
    if(br==3){
        for(j=0;j<26;j++){
            if(j+'a'!=s[i]){a[s[i]-'a'+1]--; a[j+1]++; s[i]=char(j+'a'); break;}
        }
    }
}
for(i=1;i<27;i++){
    if(a[i]>d/2){
        k=a[i]-d/2;
        while(k!=0){
            for(j=0;j<d;j++){
                for(p=0;p<26;p++){
                    if(p+'a'!=s[j] && p+'a'!=s[j+1] && p+'a'!=s[j-1]){a[s[j]-'a'+1]--; a[j+1]++; s[j]=char(p+'a'); k--; break;}
                }
                if(k==0) break;
            }
        }
    }
}
cout<<s;

return 0;
}
