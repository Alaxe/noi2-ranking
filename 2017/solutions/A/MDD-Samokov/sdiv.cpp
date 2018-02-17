#include <iostream>
#include <string>

using namespace std;

string comb = "";

void combinations(string sequence, int k, int i)
{
    if(i == sequence.length() - 1)
    {
        cout << comb;

        return;
    }

    for(int j = 0; j < k; j++)
    {
        comb += sequence[j];

        combinations(sequence, k, j);

        comb = comb.substr(0, comb.length() - 2);
    }
}

int main()
{
    int n, m;
    string sequence = "";
    cin >> sequence;
    cin >> n >> m;

    for(int i = 1; i < sequence.length(); i++)
    {
        combinations(sequence, i, 0);
    }

    return 0;
}
