#include<iostream>
#include<cstring>
using namespace std;
string str;
bool change=true, check;
int l, r, n;
void removeAt(int a){
    for(int i=a;i<n-1;i++){
        str[i]=str[i+1];
    }
    str[n-1]='\0';
    n--;
}
int main(){
    cin>>str;
    n=str.size();
    for(int k=0;k<10 && change;k++){
        change=false;
        for(int i=0;i<n;i++){
            if(str[i]=='('){
                l=i;
                for(int j=l+1, num=0;num!=1;j++){
                    if(str[j]=='(')num--;
                    else if(str[j]==')')num++;
                    r=j;
                }
                if(((l!=0 && (str[l-1]=='+' || str[l-1]=='(')) || l==0) && ((r+1!=n && (str[r+1]=='+' || str[r+1]=='-' || str[r+1]==')')) || r+1==n)){
                    removeAt(r);
                    removeAt(l);
                    change=true;
                }
                if(l!=0 && r+1!=n && str[l-1]=='(' && str[r+1]==')'){
                    removeAt(r);
                    removeAt(l);
                    change=true;
                }
                if((l!=0 && str[l-1]=='*') || (l!=0 && str[l-1]=='/') || (r+1!=n && str[r+1]=='*') || (r+1!=n && str[r+1]=='/')){
                    check=true;
                    for(int k=l+1, opened=0;k<r;k++){
                        if(str[k]=='(')opened++;
                        else if(str[k]==')')opened--;
                        if(opened==0 && (str[k]=='+' || str[k]=='-'))check=false;
                    }
                    if(check){
                        removeAt(r);
                        removeAt(l);
                        change=true;
                    }
                }
            }
        }
    }
    cout<<str<<endl;
    return 0;
}
/**
((&+&)*&)/&
&+(&*(&-&)-(&-&))
&+((((&/&))))/&
(&-&*(&*&))-(&-&+&-&+(&*&*&+(&+&)))+(&*&)*(&*&)
(&-&*(&*&))-(&-&+&-&+(&*&*&+(&+&)))+(&*&)*(&*&)/(&-&*&-(&*&*&/&)/&-&)*((&-&)/(&-&))
**/
