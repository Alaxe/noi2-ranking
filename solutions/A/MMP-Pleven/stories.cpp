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
string Multiply_str(string m,string n){
    string a="",b="";
    int d1,d2,p=0,d3,i,j,br=0;
    char c='0';
    d1=m.size();
    d2=n.size();
    for(i=d1-1;i>=0;i--){
        int k,l;
        k=int(m[i])-'0';
        for(j=d2-1;j>=0;j--){
            l=int(n[j])-'0';
            if(k*l+p>=10){
                a=char((k*l+p)%10+'0')+a;
                p=(k*l+p)/10;
            }
            else{
                a=char((k*l+p)+'0')+a;
                p=0;
            }
        }
        if(p>0)a=char(p+'0')+a;
        p=0;
        for(int q=1;q<=br;q++)a+=c;
        br++;
        if(b!="")b=Add_str(a,b);
        else b=a;
        a="";
    }
    return b;
}
string Remove_zero(string a){
    int d1=a.size(),i;
    string c;
    i=0;
    while(a[i]=='0')i++;
    for(int j=i;j<d1;j++)c+=a[j];
    return c;
}
string Minus_str(string a,string b){
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
    int p[11];
    for(i=0;i<=11;i++)p[i]=0;
    for(i=d1-1;i>=0;i--){
        int k,l;
        k=int(a[i])-'0';
        l=int(b[i])-'0';
        if(l==0&&(k!=0||p[i]!=0)){
            if(k==0&&p[i]!=0)c=char(10-p[i]+'0')+c;
            else c=char(k-p[i]+'0')+c;
        }
        else{
            if(k<l||k-p[i]<l){
                if(p[i]==0){
                    int s=i-1;
                    while(a[s]=='0'){
                        p[s]++;
                        s--;
                    }
                    p[s]++;
                }
                    k=10;
                c=char(k-l-p[i]+'0')+c;
            }
            else
                c=char(k-l-p[i]+'0')+c;
        }
    }
    c=Remove_zero(c);
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
string Divide_str(string a,string b){
    string k;
    k=a;
    int i=0;
    while(Compare_str(k,b)==1){
        k=Minus_str(k,b);
        i++;
    }
}
string Modulus_str(string a,string b){

}
int main(){
string s1,s2;
cin>>s1>>s2;
cout<<Add_str(s1,s2)<<endl;
cout<<Multiply_str(s1,s2)<<endl;
cout<<Minus_str(s1,s2)<<endl;
cout<<Compare_str(s1,s2)<<endl;
cout<<Divide_str(s1,s2)<<endl;
return 0;
}
