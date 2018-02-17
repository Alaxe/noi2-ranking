#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct myStruct{
    int sum;
    string number;
};

vector<string> _generate(vector<string> prev, vector<char> digits){
    vector<string> next;
    for(int i = 0; i < digits.size(); i++){
        if(i%2 == 0){
            for(int j = 0; j < prev.size(); j++){
                next.push_back(digits[i] + prev[j]);
            }
        }
        else{
            for(int j = prev.size() - 1; j >= 0; j--){
                next.push_back(digits[i] + prev[j]);
            }
        }
    }
    return next;
}

int main()
{
    int N, K, A, B;
    char digit;
    vector<char> digits;
    vector<string> prev;

    cin >>N >>K >>A >>B;
    for(int i = 0; i < N; i++){
        cin >> digit;
        digits.push_back(digit);
    }

    string d1;
    for(int i = 0; i < N; i++)
    {
        d1 = digits[i];
        prev.push_back(d1);
    }

    for(int i = 1; i < K; i++) prev = _generate(prev, digits);

    myStruct s[1002];
    int index = 0;
    string maxNum = "0";
    for(int i = A-1; i < B; i++)
    {
        for(int j = 0; j < prev[i].length(); j++)
        {
            s[index].sum += (prev[i][j] - '0');
            s[index].number = prev[i];
            if(maxNum.length() < prev[i].length()) maxNum = prev[i];
            else if(maxNum.length() == prev[i].length() && maxNum < prev[i]) maxNum = prev[i];
        }
        index++;
    }

    int raz, max_raz = 0;
    for(int i = 0; i < B-A; i++)
    {
        raz = abs(s[i].sum - s[i+1].sum);
        if(raz > max_raz) max_raz = raz;
    }

    cout<<maxNum<<" "<<max_raz<<endl;
}

/**

input:
3 2 3 5
7 1 5
output:
75 6

input:
3 3 10 16
7 1 5
output:
175 6

input:
20 100 30 45
5 8 2 3 2 1 4 5 2 3 5 6 1 2 4 3 4 8 9 2
output:
*/
