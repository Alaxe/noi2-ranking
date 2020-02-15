#include <bits/stdc++.h>
using namespace std;
bool checkBalance(string seq){
    int a = 0,b = 0,c = 0,d = 0;
    for(int i = 0;i < seq.length();i++){
        switch(seq[i]){
        case 'a':
            a++;
            break;
        case 'b':
            b++;
            break;
        case 'c':
            c++;
            break;
        case 'd':
            d++;
            break;
        }
    }
    if((a+b) == (c+d)){
        return true;
    }else{
        return false;
    }
}
int main(){
    int n;
    string balls;
    cin >> n >> balls;
    string cut = balls;
    while(cut.length() > 0){
        if(checkBalance(cut)){
            cout << cut.length();
            return 0;
        }
        string nw;
        for(int i = 0;i < cut.length()-1;i++){
            nw += cut[i];
        }
        cut = nw;
    }
    cout << 0;
    return 0;
}
