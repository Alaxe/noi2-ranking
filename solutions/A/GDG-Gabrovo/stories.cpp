#include<iostream>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;

string llToStr(ll a){
    string result;
    if(a==0)return "0";
    while (a!=0){
        result = char(a%10+'0') + result;
        a/=10;
    }
    return result;
}
string div(string a,ll b){
    long long current = 0ll;
    string result = "";
    for(int i = 0; i < a.size();i++){
        int d = (a[i] - '0');
        current = current * 10 + d;
        ll div = current / b;
        ll rem = current % b;
        if(div!=0){
            result = result + llToStr(div);
        }
        current = rem;
    }
    if(result=="")return "0";
    return result;
}
long long mod(string a, ll b){
    long long current = 0ll;
    for(int i = 0; i < a.size();i++){
        int d = (a[i] - '0');
        current = current * 10 + d;
        ll rem = current % b;
        current = rem;
    }
    return current;
}
string addLead(string a, string b){
    int n = a.size() - b.size();
    for(int i = 0 ; i < n; i++){
        b = '0' + b;
    }
    return b;
}
string add(string a, ll b){
    string result = "";
    int carry = 0;
    for(int i = a.size() - 1; i >= 0;i--){
        int a1 = a[i] - '0';
        int b1 = b % 10;
        int addi = a1+b1+carry;
        carry = addi/10;
        addi %= 10;
        result = char(addi + '0')+result;
        b/=10;
    }
    while(b!=0){
        int b1 = b % 10 + carry;
        carry = b1/10;
        b1%=10;
        result = char(b1 + '0')+result;

        b/=10;
    }
    if(carry != 0)result = char(carry + '0')+result;
    return result;
}
string add(string a, string b){
    string result = "";
    int carry = 0;
    if(a.size() < b.size())swap(a,b);
    b = addLead(a,b);\
    for(int i = b.size() - 1; i >= 0;i--){
        int addi = (a[i]-'0') + (b[i]-'0') + carry;
        carry = addi/10;
        addi%=10;
        result = char(addi + '0')+result;
    }
    if(carry != 0)result = char(carry + '0')+result;
    return result;
}
long long pow10(int a){
    long long result = 1;
    for(int i = 0; i < a; i++)result*=10;
    return result;
}
string mul (string a, ll b){
    string result = "0";
    int po = 0;
    for(int i = a.size() - 1; i >= 0; i--){
        int a1 = a[i] - '0';
        long long mult = a1 * b;
        mult*= pow10(po);
        po++;
        result = add(result,mult);
    }
    return result;
}
bool eq(string a, string b){
    if(a.size() != b.size())return false;
    for(int i = 0; i < a.size();i++){
        if(a[i] != b[i])return false;
    }
    return true;
}
bool more(string a, string b){
    if(a.size() > b.size())return true;
    if(a.size() < b.size())return false;
    for(int i = 0; i < a.size();i++){
        if(a[i] > b[i])return true;
        if(a[i] < b[i])return false;
    }
    return false; ///equal
}

string getMax(queue<string> q){
    string result = "0";
    while(!q.empty()){
        string a = q.front();
        if(more(a,result))result = a;
        q.pop();
    }
    return result;
}


int main()
{
    long long n,k;
    long long first,mult,addi,modu;

    queue<string> last;

    string sum = "0";

    cin>>n>>k;
    cin>>first>>mult>>addi>>modu;

    string cur,best;


    cur = llToStr(first);


    for(int i = 1; i <= n;i++){
        last.push(cur);


        if(last.size() == k + 1)last.pop();



        ///cur da e max ot last
        best = getMax(last);

        sum = add(sum,best);

        cur =  mul(cur,mult);
        //cout<<cur<<endl;
        cur = add(cur,addi);
        //cout<<cur<<endl;
        cur = llToStr(mod(cur,modu));
        //cout<<cur<<endl<<endl;
    }
    cout<<sum<<endl;
    return 0;
}

