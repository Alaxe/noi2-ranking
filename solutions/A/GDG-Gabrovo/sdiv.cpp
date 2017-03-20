#include<iostream>
#include<queue>
#define ll long long

using namespace std;

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

long long n,m,l;
string cur = "";
string a;
string br = "0";

void checkCur(){
    //cout<<cur<<endl;
    if(mod(cur,n) == 0){
        br = add(br,1);
    }
}

void pickNum(int st){
    if(st > l){
        return;
    }
    for(int i = st; i < l;i++){
        cur = cur + a[i];
        checkCur();
        pickNum(i+1);
        cur.erase(cur.end() - 1);
    }
}

int main()
{
    cin>>a;
    l=a.size();
    cin>>n>>m;

    pickNum(0);

    cout<<mod(br,m)<<endl;

    return 0;
}
