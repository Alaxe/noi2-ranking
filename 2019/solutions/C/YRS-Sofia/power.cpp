#include <iostream>
#include <map>
#include <set>
using namespace std;
map<long long, long long> fact;
set<long long> s;
void factoriz(long long num)
{
    for(long long i = 2; i <= num; ++i){
        while(num % i == 0){
            num /= i;
            if(fact.find(i) != fact.end()) ++fact[i];
            else fact.insert(make_pair(i, 1));
        }
        if(num == 1) break;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long br, k;
    cin >> br >> k;
    for(long long i = 0; i < br; ++i){
        long long num;
        cin >> num;
        if(s.find(num) != s.end()) continue;
        s.insert(num);
        factoriz(num);
    }
    long long multi = 1;
    for(map<long long, long long>::iterator iter = fact.begin(); iter != fact.end(); ++iter){
        long long element = iter->first, counter = iter->second;
        if(counter % k == 0){
            for(long long i = 0; i < counter / k; ++i) multi *= element;
        }
        else{
            for(long long i = 0; i <= (counter / k); ++i) multi *= element;
        }
    }
    cout << multi << '\n';
    return 0;
}
