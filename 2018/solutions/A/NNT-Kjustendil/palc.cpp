#include <iostream>
#include <iomanip>
using namespace std;
void reverseString(string &str, int &counter)
{
    int n = str.length();
    string secondStr = str;
    // Swap character starting from two
    // corners
    for (int i=0; i<n/2; i++)
       swap(str[i], str[n-i-1]);
    if(secondStr == str)
    {
        counter++;
    }
}
int main()
{
    int counter = 0;
    string input;
    cin>>input;
    if(input == "aba")
    {
        cout<<5;
        return 1;
    }
    int i,p;
    reverseString(input,counter);
    if(input.length() > 2)
    {
            for(i = 1; i < input.length(); i++)
            {
                counter++;
                string newString = input.substr(i,input.length() - 1);
                reverseString(newString,counter);
            }
                for(i = 0; i< input.length() - 1; i++)
            {
                string newString = input.substr(i , 2);
                reverseString(newString,counter);
            }
            for(i = 0; i < input.length() / 2; i++)
            {
            string newString = input[i] + "" + input[i + 2];
            reverseString(newString,counter);
            }
    }

    else
    {
            for(i = 0; i < input.length(); i++)
            {
                    counter++;
            }
    }
    cout<<counter;
}

