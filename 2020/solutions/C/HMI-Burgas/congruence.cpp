#include <iostream>
#include <stdlib.h>
using namespace std;

std::string words[2];

int returnVal(char x)
{
    return (int)x - 97;
}

bool checkExists(int val, int arr[])
{
    int arrSize = arr[0] / (int)sizeof(arr);
    for(int i = 0; i < arrSize; i++)
        if(arr[i] == val)
            return true;
    return false;
}

char returnChar(int val)
{
    return (char)(val + 97);
}

int findLetter(std::string word, bool biggest = false)
{
    int letter = returnVal(word[0]);
    for (int i = 0; i < (int)word.size(); i++){
        if (biggest)
        {
            if (letter < returnVal(word[i]))
                {
                    letter = returnVal(word[i]);
                }
        }
        else
        {
            if (letter > returnVal(word[i]))
            {
                letter = returnVal(word[i]);
            }
        }
    }

    return letter;
}

void generateWord(std::string word, int shift, bool bigShift = false)
{

    std::string tempWord = "";
    for(int i = 0; i < (int)word.size(); i++)
    {
        int letterVal = returnVal(word[i]);
        int newLetterVal = letterVal - shift;
        if(bigShift)
        {
            newLetterVal = 25 - (shift - letterVal);
        }
        char newLetter = returnChar(newLetterVal);
        tempWord += newLetter;
    }
    words[bigShift] = tempWord;
}

void shrink4(std::string word)
{
    int wordSize = (int)word.size();
    int values[wordSize];
    for(int i = 0; i < wordSize; i++)
        values[i] = returnVal(word[i]);
    int minNum = values[0];
    int oldValues[wordSize];
    int edited[wordSize];
    int fixed = 0;
    int nextMin = -1;
    while(!(std::equal(values, values + sizeof values / sizeof *values, oldValues)))
    {
        cout << "iteration" << endl;
        for(int i = 0; i < wordSize; i++)
        {
            oldValues[i] = values[i];
        }
        for(int i = 1; i < wordSize; i++)
        {
            if(minNum > values[i])
                minNum = values[i];
        }
        for(int i = 0; i < wordSize; i++)
        {
            if(values[i] > minNum)
            {
                if(nextMin == -1)
                {
                    nextMin = values[i];
                }
                if(fixed == 0)
               {
                    if (nextMin > values[i] && edited[i] == 0)
                    {
                        nextMin = values[i];
                    }
               } else {
                   if (nextMin < values[i] && edited[i] == 0)
                    {
                        nextMin = values[i];
                    }
               }
            }
        }

        cout << "min " <<minNum<< " next " << nextMin << endl;
        for(int i = 0; i < wordSize; i++)
        {
            if(values[i] == nextMin)
            {
                for(int a = minNum+1; a < 26; a++)
                {
                    if(!checkExists(a, values))
                    {
                        edited[i] = 1;
                        fixed ++;
                        values[i] = a;
                        break;
                    }
                }
            }
        }
    }
        for(int i = 0; i < wordSize; i++)
            cout << values[i] << " ";
}

void shrink3(std::string word)
{
    int wordSize = (int)word.size();
    int values[wordSize];
    for(int i = 0; i < wordSize; i++)
        values[i] = returnVal(word[i]);

    for(int j = 0; j < wordSize; j++)
    {
        int minNumPos = j;
        int minNum = values[j];
        for(int i = j; i < wordSize; i++)
        {
            if(minNum > values[i] && values[i] > 0)
                minNumPos = i;
        }
        minNum = values[minNumPos];
        if(minNum == 0)
            continue;
        cout << minNum << endl;
        for(int a = 1; a < 26; a++)
        {
            bool exists = false;
            for(int i = 0; i < wordSize; i++)
                if(values[i] == a && values[minNumPos] != a)
                    exists = true;
            if(!exists)
            {
                values[minNumPos] = a;
                break;
            }
        }
    }
        for(int i = 0; i < wordSize; i++)
            cout << values[i] << " ";
}

void shrinkWord(std::string word)
{
    int wordSize = (int)word.size();
    int values[wordSize];
    for(int i = 0; i < wordSize; i++)
        values[i] = returnVal(word[i]);
    int oldValues[wordSize];
    int oldMinNum = 0;
    while(!(std::equal(values, values + sizeof values / sizeof *values, oldValues)))
    {
        cout << "iteration" << endl;
          for(int i = 0; i < wordSize; i++)
            {
                oldValues[i] = values[i];
            }

        int minNum = values[0]-1;
        if(oldMinNum != 0)
            minNum = oldMinNum;
        for(int i = 1; i < wordSize; i++)
            if(values[i]-1 < minNum && values[i]-1 > oldMinNum)
                minNum = values[i]-1;

        for(int i = 0; i < wordSize; i++)
            if(values[i] > minNum)
                values[i] -= minNum;
        oldMinNum = minNum;
    }

        for(int i = 0; i < wordSize; i++)
            cout << values[i] << " ";
}

int main()
{
    std::string word;
    cin >> word;

    int let = findLetter(word, false);
    int lowShift = let;
    generateWord(word, lowShift, false);

    int letBig = findLetter(words[0], true);
    int bigShift = letBig;
    generateWord(words[0], bigShift, true);

    //shrink4(words[0]);

    cout << words[0] << endl;
    cout << words[1] << endl;
    return 0;
}
