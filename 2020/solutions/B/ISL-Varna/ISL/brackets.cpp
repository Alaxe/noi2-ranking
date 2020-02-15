#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define f first
#define s second
#define ll long long int
using namespace std;

string t;

pair<int, int> find_end_from(int idx){
    int tmp = 1;
    for(int i = idx + 1; i < t.size(); i ++){
        if(t[i] == '(')
            tmp ++;
        if(t[i] == ')')
            tmp --;
        if(tmp == 0){
            return {idx, i};
        }
    }
    return {0, 0};
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    cin >> t; t = '+' + t; t = t + '+';
    for(int i = 0; i < t.size(); i ++){
        if(t[i] == '('){
            pair<int, int> br = find_end_from(i);
            int val = 2;
            for(int i = br.f + 1; i <= br.s - 1; i ++){
                if(t[i] == '+' || t[i] == '-'){
                    val = 1;
                    break;
                }
                if(t[i] == '('){
                    int tmp = 1;
                    for(; i < t.size(); i ++){
                        if(t[i] == '(')
                            tmp ++;
                        if(t[i] == ')')
                            tmp --;
                        if(tmp == 0)
                            break;
                    }
                }
            }
            if(val == 1){
                if(t[br.f - 1] == '+' && (t[br.s + 1] == '+' || t[br.s + 1] == '-')){
                    t.erase(br.s, 1);
                    t.erase(br.f, 1);
                    i --;
                }
            }
            else if(val == 2){
                t.erase(br.s, 1);
                t.erase(br.f, 1);
                i --;
            }
            /// cout << "i = " << i << " val = " << val << " " << t << endl;
        }
    }
    t.erase(0, 1);
    t.erase(t.size() - 1, 1);
    cout << t << endl;
}
