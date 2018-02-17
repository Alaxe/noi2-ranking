#include <iostream>
#include <cstring>
#define MAXN 100
using namespace std;
int main(){
    string s;
    cin>>s;
    int pal[MAXN][MAXN];
    int len = s.length();
    for(int i = 0; i < len; i++){
        pal[i][i] = 1;
        if(s[i] == s[i+1]){
            pal[i][i+1] = 3;
        } else{
            pal[i][i+1] = 2;
        }
    }
    for(int d = 2; d < len; d++){
        for(int i = 0; i< len-d; i++){
            if(s[i] == s[i+d]){
                pal[i][i+d] = pal[i+1][i+d] + pal[i][i+d-1] + 1;
            } else{
                pal[i][i+d] = pal[i+1][i+d] + pal[i][i+d-1] - pal[i+1][i+d-1];
            }
        }
    }

    cout<<pal[0][len-1]<<endl;
    return 0;
}
