#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const int MAXN = 105, MAXK = 1e4 + 5;
const long long inf = 1000000000000000005LL;

long long n, k;
long long A, B;
char digits[MAXN];

long long p[MAXK];
vector <string> numbers;

string maxNumber;

string genNumber(int index, int level)
{
    //cout << index << " " << level << '\n';

    int newIndex;
    string answer = "";

    if(level==1)
    {
        answer += digits[index];
        return answer;
    }

    if(p[level-1]==inf)
    {
        //cout << "OK" << '\n';

        answer = digits[0];
        newIndex = index;
    }
    else
    {
        answer = digits[ index/p[level-1] ];
        newIndex = index%p[level-1];

        if((index/p[level-1])%2!=0) newIndex = p[level-1] - 1- newIndex;
    }

    answer += genNumber(newIndex, level-1);
    return answer;
}

int s;
int sum(string a)
{
    s = 0;
    for(int i = 0;i<a.size();i++)
        s += a[i] - '0';

    return s;
}

bool isBigger(string a, string b)
{
    if(a.size()>b.size()) return true;
    if(a.size()<b.size()) return false;

    for(int i = 0;i<a.size();i++)
    {
        if(a[i]>b[i]) return true;
        else if(a[i]<b[i]) return false;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int index = 0;
    int maxDiff = 0;

    cin >> n >> k >> A >> B;
    for(int i = 0;i<n;i++)
        cin >> digits[i];

    p[0] = 1;
    for(int i = 1;i<=k;i++)
    {
        if(p[i-1]==inf || p[i-1]>=inf/n+1) p[i] = inf;
        else p[i] = p[i-1]*n;
    }

    for(int i = A-1;i<B;i++)
    {
        numbers.push_back(genNumber(i, k));
    }

    for(int i = 0;i<numbers.size();i++)
    {
        if(isBigger(numbers[i], maxNumber)==true)
            maxNumber = numbers[i];

        if(i!=numbers.size()-1)
            maxDiff = max(maxDiff, (int)abs( sum(numbers[i])  - sum(numbers[i+1]) ) );
    }

    cout << maxNumber << " " << maxDiff << '\n';
}
/*
3 2 3 5
7 1 5
*/
