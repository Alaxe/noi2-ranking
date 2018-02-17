#include<iostream>
#include<math.h>

using namespace std;

string s;
int n;
unsigned long long m;
unsigned long long gran = 0;

void check(string so){
    if(so.length() < 18){

        unsigned long long k = 0;
        double po = 0;

        for(int i=so.size()-1;i>=0;i--){
            int p = (so[i]-48);
            k += p * ceil(pow(10.0, po));
            po++;
        }

        if(k % n == 0){
            gran++;
        }

        return;
    }else if((so[so.size()-1] == '0' || so[so.size()-1] == '2' || so[so.size()-1] == '4' || so[so.size()-1] == '6' || so[so.size()-1] == '8') && (n%2!=0)){
        return;
    }else{
        gran++;
        return;
    }
}

void rec(int idx, string cur){

    if(idx >= s.size()){
        return;
    }

    cur += s[idx];
    check(cur);

    for(int i=1;idx+i<s.size();i++){
        rec(idx+i, cur);
    }
}

int main(){

    cin >> s;
    cin >> n >> m;

    for(int i=0;i<s.size();i++){
        rec(i, "");
    }

    cout << gran % m << endl;

    return 0;
}
