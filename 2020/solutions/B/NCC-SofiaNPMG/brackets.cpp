#include <iostream>
#include <cstring>
using namespace std;

char bstring [200000], answ[200000];
long long brackets[50000][2];
long long N, bo, bc, n;
bool correct[50000];

int main(){
    cin >> bstring;
    N = strlen(bstring);

    for(int i = 0; i < N; i ++){

        if(bstring[i] == '('){
            brackets[bo][0] = i;
            bo ++;
            bc ++;
        }

        if(bstring[i] == ')'){
            brackets[bc - 1][1] = i;
            bc --;
        }
    }

    for(int i = 0; i < bo; i ++){
        correct[i] = false;

        if(bstring[brackets[i][0] - 1] == '*' or bstring[brackets[i][0] - 1] == '/' or bstring[brackets[i][1] + 1] == '*' or bstring[brackets[i][1] + 1] == '/' or bstring[brackets[i][0] - 1] == ')' or bstring[brackets[i][0] - 1] == '(' or bstring[brackets[i][1] + 1] == ')' or bstring[brackets[i][1] + 1] == '('){
            for (int j = brackets[i][0] + 1; j < brackets[i][1]; j++){
                if(bstring[j] == '('){
                    n ++;
                }

                if(bstring[j] == ')'){
                    n --;
                }

                if(n == 0){
                    if(bstring[j] == '+' or bstring[j] == '-'){
                        correct[i] = true;
                    }
                }
            }
        }
    }

    n = 0;

    for(int i = 0; i < N - bo*2; i ++){
        if(bstring[i + n] != ')' and bstring[i + n] != '('){
            answ[i] = bstring[i + n];
        }else{
            for(int j = 0; j < bo; j ++){
                if(brackets[j][0] or brackets[j][1] == i + n){
                    if(correct[j]){
                        n++;
                        i--;
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i ++){
        cout << answ[i];
    }

    cout << '\n';

    return 0;
}
