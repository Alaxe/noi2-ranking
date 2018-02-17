#include<iostream>
using namespace std;
string Add_str(string a,string b){
    int d1,d2,i;
    char m='0';
    string c="";
    d1=a.size();
    d2=b.size();
    if(d1!=d2){
        if(d1>d2)
            while(d2!=d1){
                b=m+b;
                d2++;
            }
        else
            while(d1!=d2){
                a=m+a;
                d1++;
            }
    }
    int p=0;
    for(i=d1-1;i>=0;i--){
        int k,l;
        k=int(a[i])-'0';
        l=int(b[i])-'0';
        if(k+l+p>=10){
            c=char((k+l+p)%10+'0')+c;
            p=(k+l+p)/10;
        }
        else{
            c=char(k+l+p+'0')+c;
            p=0;
        }
    }
    if(p>0)c=char(p+'0')+c;
    return c;
}
int Compare_str(string a,string b){
    int d1,d2,i;
    d1=a.size();
    d2=b.size();
    if(d1>d2)return 1;
    if(d1<d2)return 2;
    for(i=0;i<d1;i++){
        if(a[i]>b[i])return 1;
        if(a[i]<b[i])return 2;
    }
    return 0;
}
int main(){
int i,br=0,s=0;
string a,b,c,d,e="";
cin>>a>>b;
c="2";
while(Compare_str(e,a)==2){
    e=Add_str(e,c);
    c=Add_str(c,"2");
}
while(Compare_str(e,b)==2||Compare_str(e,b)==0){
    e=Add_str(e,c);
    c=Add_str(c,"2");
    br++;
}
cout<<br<<endl;
return 0;
}
