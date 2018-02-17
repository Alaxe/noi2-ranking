#include<iostream>
#include<utility>

using namespace std;

char elementi[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
int stoinosti[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

int main () {

    int n, sum = 0;
    int x, y, a = 0, b = 0;
    cin >> n;

    pair < char, char > str[n][n];

    bool flag1 = true, flag2 = true;

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            cin >> str[i][j].first >> str[i][j].second;
        }
    }

    x = n - 1;
    y = 0;

    while(flag1 || flag2){

        for(int k = 0 ; k < 13 ; k ++){

            if(str[x][y].first == elementi[k]){
                sum += stoinosti[k];
                cout << stoinosti[k]<<endl;
            }
            if(flag1){
                if(str[x - 1][y].first == elementi[k]){
                    a = k;

                }
            }

            if(flag2){
                if(str[x][y + 1].first == elementi[k]){
                    b = k;

                }
            }

        }

        if(stoinosti[a] > stoinosti[b]){
            x --;
        }else{
            y ++;
        }

        if(x == 0){
            a = -1;
            flag1 = false;
        }
        if(y == n - 1){
            b = -1;
            flag2 = false;
        }
    }

    for(int i = 0 ; i < 13 ; i ++){
        if(str[0][n - 1].first == elementi[i]){
            sum += stoinosti[i];
            break;
        }
    }

    cout << sum << "\n";

    return 0;
}
/**
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
**/
