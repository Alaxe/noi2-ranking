#include<bits/stdc++.h>
using namespace std;

int64_t s, k, a, b, c, d, type;
double A, B, C, D;
bool flag = false;

int main(){
    cout << fixed;
    cin >> s >> k;
    cin >> a >> b >> c >> d;
    if(k / (4 * d) < s){
        type = k / (d * 4) % 4;
        k = k % (d * 4);
        if(type == 0){
            swap(b, c);
        }
        else if(type == 1){
            swap(b, a);
        }
        else if(type == 2){
            swap(a, b);
            swap(b, c);
        }
        else if(type == 3){
            swap(a, c);
            swap(b, c);
        }
            if(k >= a){
                A = a;
                k -= A;
                if(k >= b){
                    B = b;
                    k -= B;
                    if(k >= c){
                        C = c;
                        k -= C;
                        if(k >= d){
                            D = d;
                            k -= D;
                        }
                        else{
                            D = k;
                        }
                        if(d > c && d > b && d > a && flag == false){
                            A = (A + B + C + D) / 4;
                            B = (A + B + C + D) / 4;
                            C = (A + B + C + D) / 4;
                            D = (A + B + C + D) / 4;
                            flag = true;
                        }
                        else if(d > c && d > b && d < a && flag == false){
                            B = (B + C + D) / 3;
                            C = (B + C + D) / 3;
                            D = (B + C + D) / 3;
                            flag = true;
                        }
                        else if(d > c && d < b && flag == false){
                            C = (D + C) / 2;
                            D = (D + C) / 2;
                            flag = true;
                        }
                    }
                    else{
                        C = k;
                    }
                    if(c > b && c > a && flag == false){
                        A = (A + B + C) / 3;
                        B = (A + B + C) / 3;
                        C = (A + B + C) / 3;
                        flag = true;
                    }
                    else if(c > b && c < a && flag == false){
                        B = (B + C) / 2;
                        C = (B + C) / 2;
                        flag = true;
                    }
                }
                else{
                    B = k;
                }
                if(b > a && flag == false){
                    A = (A + B) / 2;
                    B = (A + B) / 2;
                    flag = true;
                }
            }
            else{
                A = k;
            }
            cout << setprecision(3) << A << " " << B << " " << C << " " << D << endl;
        }
    else if(k / (4 * d) >= s){
        cout << setprecision(3) << (double)(k / s / 4) << " " << (double)(k / s / 4) << " " << (double)(k / s / 4) << " " << (double)(k / s / 4) << endl;
    }
}
