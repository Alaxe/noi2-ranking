#include<bits/stdc++.h>
using namespace std;
char IntToChar(int n)
{
    return 'A' + n - 1;
}
int CharToInt(char c)
{
    return c - 'A';
}
int main()
{
    int characterMatrix[26];
    memset(characterMatrix, 0, sizeof(characterMatrix));
    string input;
    char maxC = 'A' - 1;

    cin >> input;
    for(int i = 0; i < input.size(); i++)
    {
        characterMatrix[CharToInt(input[i])]++;
        if(maxC < input[i])
            maxC = input[i];
    }

    int k = 1;
    for(int i = 0; i < 26; i++)
    {
        if(characterMatrix[i]!=0)
        {
            characterMatrix[i] = k;
            k++;
        }
    }
    k = 27 - characterMatrix[CharToInt(maxC)];
    for(int i = 0; i < input.size(); i++)
    {
        input[i] = IntToChar(characterMatrix[CharToInt(input[i])]);
        cout << input[i];
        input[i] = CharToInt(k + IntToChar(input[i]));
    }
    cout << endl << input << endl;
    return 0;
}
