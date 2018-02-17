#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <pair <long long, long long> > v;

void input()
{
    pair <long long, long long> p;

    while(cin >> p.first >> p.second)
    {
        v.push_back(p);
    }
}

int main()
{
    input();
    long long counter = 0, l;

    sort(v.begin(), v.end());

    counter = v[0].first + v[0].second;

    l = v.size();

    for(int i = 1; i < l; i++)
    {
        if(counter > v[i].first)counter = counter + v[i].second;
        else counter = v[i].first + v[i].second;
    }

    cout << counter - v[l - 1].first << endl;

    return 0;

}
