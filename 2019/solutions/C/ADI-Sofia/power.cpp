#include<bits/stdc++.h>

using namespace std;

vector < int > prosti = {2, 3, 5, 7, 11, 17, 19, 23, 29, 31, 37, 41, 43};

int chislo = 1;

int main () {

    //cin.stdio_with_...(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for(int i = 0 ; i < n ; i ++){

        int a;
        cin >> a;

        int br = 0;

        for(int j = 0 ; j < prosti.size() ; j ++){

            br = 0;

            if(prosti[j] > a) break;

            while(a % prosti[j] == 0){

                br ++;
                a /= prosti[j];

            }

            if(br < k && br != 0){

                if(chislo % prosti[j] != 0){

                    chislo *= prosti[j];

                }

            }else{

                int abc = 1, dksd = 1;

                for(int l = 0 ; l < br % k + br / k ; l ++){

                    abc *= prosti[j];

                    if(a % abc == 0){

                        dksd = abc;

                    }

                }

                chislo *= (abc / dksd);

            }

        }

    }

    cout << chislo << endl;

    return 0;
}
