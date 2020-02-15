
///may work

#include<iostream>
#include<vector>
using namespace std;

string s;

int pr[200100], numbof;
vector<int> lastopen;
int lastseen;
int sp[200100];
int skip;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(pr, pr+200100, -1);

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            lastopen.push_back(numbof);
            if(i > 0 && (s[i-1] == '-' || s[i-1] == '*' || s[i-1] == '/')){
                sp[numbof] = 1;
            }
            if(i > 0 && s[i-1] == '/'){
                sp[numbof] = 2;
            }
            numbof++;
        }
        if(s[i] == ')'){
            lastseen = lastopen.back();
            lastopen.pop_back();
        }
        if(s[i] == '*' || s[i] == '/'){
            if(i > 0 && s[i-1] == ')'){
                sp[lastseen] = max(1, sp[lastseen]);
            }
        }
        if(!lastopen.empty() && (s[i] == '+' || s[i] == '-')){
            pr[lastopen.back()] = 0;
        }
    }

    for(int i = 0; i < numbof; i++){
        if(pr[i] >= 0 && sp[i] == 1){
            pr[i] = 1;
        }
        if(sp[i] == 2){
            pr[i] = 1;
        }
        //cout << sp[i] << " ";
    }
    //cout << endl;

    numbof = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            if(pr[numbof] == 0 && sp[numbof] == 0){
                for(int j = lastopen.size()-1; j >= 0; j--){
                    if(pr[lastopen[j]] == -1 && sp[lastopen[j]] >= 1){
                        sp[numbof] = 1;
                        break;
                    }
                }
            }
            if(pr[numbof] + sp[numbof] >= 1){
                cout << s[i];
            }
            lastopen.push_back(numbof);
            numbof++;
        }else if(s[i] == ')'){
            if(pr[lastopen.back()]+sp[lastopen.back()] >= 1){
                cout << s[i];
            }
            lastopen.pop_back();
        }else{
            cout << s[i];
        }

    }

    cout << endl;


return 0;
}
/*
((&+&)*&)/&
&+(&*(&-&)-(&-&))
&+((((&/&))))/&
&+((((&-&))))/&
*/
