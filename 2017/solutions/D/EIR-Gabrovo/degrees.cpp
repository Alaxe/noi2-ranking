#include <iostream>
#include <cstring>
using namespace std;
string s;
string po2(string in){
    int c=0;
    for (int i=in.size()-1; i>=0; i--){
        in[i]=(char)((int)(in[i]-'0')*2)+'0';
        in[i]+=c;
        if (in[i]>'9'){
            in[i]-=10;
            c=1;
        }
        else c=0;
        if (c==1){
            if (i==0){
                in='1'+in;
            }
        }
    }
    return in;
}
string power(int n)
{
    string out="1";
    for (int i=1; i<=n; i++){
        out=po2(out);
    }
    return out;
}
bool check()
{
    for (int i=0; i<s.size(); i++){
        if (s[i]!='*') return true;
    }
    return false;
}
bool comp(string in)
{
    for (int i=0; i<min(in.size(), s.size()); i++){
        if (i>=s.size()) return false;
        if (in[i]!=s[i]) return true;
    }
    return false;
}
void star(int n)
{
    int i=0;
    while (s[i]=='*'){
        i++;
        n++;
    }
    for (int j=i; j<n; j++){
        s[j]='*';
    }
}
void findch(string in)
{
    int siz=in.size();
    // cout<<" "<<s<<endl;
    while (comp(in)){
        in='*'+in;
    }
    // cout<<" "<<in<<endl;
    star(siz);
    // cout<<"("<<s<<")"<<endl<<endl;
}
//--------------------MAIN--------------------
int main()
{
    int br=0;
    string neshto;
    getline(cin, s);
    while (check()){
        br++;
        neshto=power(br);
        findch(neshto);
    }
    cout<<br<<endl;

    return 0;
}
/**
2481632641282565121024204840968192163843276865536131072262144524288104857620971524194304 -- 22
*/

