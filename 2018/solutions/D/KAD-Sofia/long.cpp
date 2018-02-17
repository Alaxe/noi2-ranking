#include<iostream>
#include<cstring>
using namespace std;
int f(char s[]){
    int br=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0' and s[i]<='9'){
            br++;
        }else{
            break;
        }
    }
    return br;
}
int main(){
    long long n;
    char k[10],ch[1005];
    cin>>n>>k;
    long long br,n2=strlen(k),i,a,b,c,d,i2;
    br=n2;
    for(i=n2-1;i>=0;i--){
        ch[i]=k[i];
    }
    //cout<<ch<<endl;
    while(br<n){
        d=0;
        for(i=n2-1;i>=0;i--){
            a=ch[i]-'0';
            b=k[i]-'0';
            c=a+b;
            if(d>0){
                c+=d;
            }
            if(c>=10){
                d=c/10;
                c%=10;
            }
            //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" ";
            ch[i]=c+'0';
        }
        if(d>0){
            //cout<<ch<<" ";
            //ch[f(ch)]='0';
            for(i=f(ch);i>=1;i--){
                //cout<<i<<" "<<ch[i]<<" "<<ch[i-1]<<" ";
                ch[i]=ch[i-1];
                //cout<<ch[i]<<" "<<ch[i-1]<<" ";
            }
            ch[0]=d+'0';
        }
        br=f(ch);
        //cout<<br<<" "<<ch<<endl;
    }
    for(i=0;i<f(ch);i++){
        cout<<ch[i];
    }
    cout<<endl;
return 0;
}
