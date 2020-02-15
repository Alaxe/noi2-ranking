#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<vector<int>, int> avectors;
map<vector<int>, int> bvectors;

void generateSets(int n, int k, bool isFirstVariant, bool isFirstArray,int* arr)
{
        for(int i = 0; i< n + 1 - k; i++)
        {
            vector<int> samplevector;
            bool isFine = true;
            for(int j = i; j < i + k - 1; j++)
            {
                samplevector.push_back(arr[j]);
                if(arr[j] != arr[j+1] && !isFirstVariant || arr[j] >= arr[j + 1] && isFirstVariant)
                {
                    isFine = false;
                    break;
                }
            }

            if(isFine)
            {
                samplevector.push_back(arr[i + k - 1]);
                if(isFirstArray)
                {
                    if(avectors.count(samplevector))
                    {
                        avectors[samplevector]++;
                    }
                    else avectors.insert(pair<vector<int>, int>(samplevector, 1));
                }
                else
                {
                    if(bvectors.count(samplevector))
                    {
                        bvectors[samplevector]++;
                    }
                    else bvectors.insert(pair<vector<int>, int>(samplevector, 1));
                }
            }
        }
}

void printCoefficient()
{
    int coefficient = 0;
    for(auto it = avectors.begin(); it != avectors.end(); it++)
    {
        for(auto itr = bvectors.begin(); itr != bvectors.end(); itr++)
        {
            if(it -> first == itr -> first)
            {
                coefficient += it -> second * itr -> second;
            }
        }
    }

    cout << coefficient << endl;
}

int main()
{
    int variant, k;
    cin>>variant>>k;

    int n;
    cin>>n;
    int* aArr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> aArr[i];
    }

    int m;
    cin>>m;
    int* bArr = new int[m];

    for(int i = 0; i < m; i++)
    {
        cin >> bArr[i];
    }

    if(variant == 1)
    {
        generateSets(n, k, true, true, aArr);
        generateSets(m, k, true, false, bArr);
    }
    else
    {
        generateSets(n, k, false, true, aArr);
        generateSets(m, k, false, false, bArr);
    }

    printCoefficient();

    delete[] aArr, bArr;
    system("pause");
}
