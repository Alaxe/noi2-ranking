#include<iostream>
#include<string>
using namespace std;
string sum(string s1, string s2){
    int i;
    string n1="", n2="";
    for(i = s1.size() - 1; i>=0; i--){
        n1 += s1[i];
    }
   for(i = s2.size() - 1; i>=0; i--){
        n2 += s2[i];
    }
    int len = max(n1.size(), n2.size());
    for(i=n1.size(); i<len; i++){
        n1 += "0";
    }
    for(i=n2.size(); i<len; i++){
        n2 += "0";
    }
    string result="";
    int naum = 0;
    for(i=0; i<len; i++){
        int sbor = (n1[i] - '0') + (n2[i] - '0') + naum;
        result += sbor%10 + '0';
        naum = sbor/10;
    }
    if(naum == 1){
        result += "1";
    }
    for(i=0; 2*i < result.size() - 1; i++){
        char t = result[i];
        result[i] = result[result.size() - i - 1];
        result[result.size() - i - 1] = t;
    }
    return result;
}
string div2(string s){
    string result = "";
    int div = s[0]-'0', i=0;
    if(div == 1 && s.size() == 1){
        result = "0";
    }
    else{
        if(div == 1){
            div = 10 + (s[1] - '0');
            i=1;
        }
        for(; i < s.size(); i++){
            result += div/2 + '0';
            if(i < s.size() - 1){
                div = (div%2)*10 + (s[i+1] - '0');
            }
        }
    }
    return result;
}
string mult_int(string s, int n){
    string result="";
    int i, naum = 0;
    for(i=s.size() - 1; i>=0; i--){
        int m = (s[i]-'0')*n + naum;
        result += (m%10 + '0');
        naum = m/10;
    }
    if(naum > 0){
        result += (naum + '0');
    }
    for(i=0; 2*i < result.size() - 1; i++){
        char t = result[i];
        result[i] = result[result.size() - i - 1];
        result[result.size() - i - 1] = t;
    }
    return result;
}
string mult(string s1, string s2){
    string result = "0";
    int i, j;
    for(i=0; i<s2.size(); i++){
        string mul = mult_int(s1, int(s2[i] - '0'));
        for(j=i+1; j<s2.size(); j++){
            mul += "0";
        }
        result = sum(result, mul);
    }
    return result;
}
int cmp(string s1, string s2){
    if(s1.size() < s2.size()){
        return -1;
    }
    if(s1.size() > s2.size()){
        return 1;
    }
    if(s1 < s2){
        return -1;
    }
    if(s1 > s2){
        return 1;
    }
    return 0;
}
string diff(string s1, string s2){
    int i;
    string n1="", n2="";
    for(i = s1.size() - 1; i>=0; i--){
        n1 += s1[i];
    }
   for(i = s2.size() - 1; i>=0; i--){
        n2 += s2[i];
    }
    int len = max(n1.size(), n2.size());
    for(i=n1.size(); i<len; i++){
        n1 += "0";
    }
    for(i=n2.size(); i<len; i++){
        n2 += "0";
    }
    string d="";
    int naum = 0;
    for(i=0; i<len; i++){
        int c = (n1[i] - '0') - (n2[i] - '0') - naum;
        if(c<0){
            naum = 1;
        }
        else{
            naum = 0;
        }
        d += (naum*10 + c)  + '0';
    }
    string result="";
    for(i=d.size() - 1; i>0 && d[i]=='0'; i--){}
    for(; i>=0; i--){
        result +=d[i];
    }
    return result;
}
int main(){
    string m, n, brM, brN;
    cin >> m >> n;
    int i;
    string a="1", b="1";
    for(i=0; i<52; i++){
        b+="0";
    }
    bool sqrt = false;
    string p1 = sum("1", mult_int(m, 4));
    while(!sqrt){
        string mid = div2(sum(a, b));
        int c = cmp(mult(mid, mid), p1);
        if(c == 0 || a == mid){
            sqrt = true;
            brM = c==0 ? div2(mid) : div2(sum(a, "1"));
            if(m == "1"){
                brM = "0";
            }
            else{
                brM = diff(brM, "1");
            }
        }
        if(c == 1){
            b = mid;
        }
        else{
            a = mid;
        }
    }
    a="1";
    b="1";
    for(i=0; i<52; i++){
        b+="0";
    }
    sqrt = false;
    string p2 = sum("1", mult_int(n, 4));
    while(!sqrt){
        string mid = div2(sum(a, b));
        int c = cmp(mult(mid, mid), p2);
        if(c == 0 || a == mid){
            sqrt = true;
        }
        if(c == 1){
            b = mid;
        }
        else{
            a = mid;
        }
    }
    brN = div2(sum(a, "1"));
    if(n == "1"){
        brN = "0";
    }
    else{
        brN = diff(brN, "1");
    }
    cout << diff(brN, brM) << '\n';
    return 0;
}
