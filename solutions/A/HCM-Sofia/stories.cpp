#include<iostream>
#include<set>
#include<list>

using namespace std;
typedef unsigned long long ull;

struct ltstr
{
  bool operator()( int s1,  int s2) const
  {
    return s1 > s2;
  }
};

int main(){

    short kon[100000];

    set<int, ltstr> fun;
    list<int> all;

    int k,n;
    cin >> n >> k;

    ull first, mul, add, mod;
    cin >> first >> mul >> add >> mod;

    int mas[n];
    int big = 100000;

    for(int i=0;i<n;i++){
        mas[i] = first;
        first = (first*mul + add)%mod;
    }

    //for(int i=0;i<n;i++)cout << mas[i] << " ";

    ull sum = 0;
    int flag = 0;

    for(int i=0;i<n;i++){
        ull cur = mas[i];

        fun.insert(cur);
        if(cur < big)kon[cur]++;
        //cout << cur << endl;

        if(i+1>k){
            if(mas[flag] < big){
                kon[mas[flag]]--;
            }

            if(mas[flag] < big){
                if(kon[mas[flag]] == 0) fun.erase(mas[flag]);
            }else{
                fun.erase(mas[flag]);
            }

            flag++;
        }

        ///cout << "opa: " << (*fun.begin()) << "\n";
        sum += (*fun.begin());
    }

    cout << sum << endl;

    return 0;
}
/*
7 3
5 3 2 23
*/
/*
133742 666
20 3 17 1000000007
*/
/*
7 3
5 3 2 12
*/
