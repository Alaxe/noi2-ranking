#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
private:
    unsigned int n, w1, w2;
    unsigned int *objects;
    unsigned int result;
    unsigned int partialSum;
    bool found;

    std::vector<unsigned int> usedNums;
private:
    void Combine(unsigned int arr[], unsigned int data[], unsigned int start, unsigned int end, unsigned int index, unsigned int r, unsigned int containerSize)
    {
        if(found) return;

        if(index == r)
        {
            unsigned int sum = 0;
            for(int i=0; i<r; i++)
            {
                sum += data[i];

            }

            if(sum == containerSize)
            {
                partialSum = sum;
                found = true;
                usedNums.clear();
                for(int i=0; i<r; i++)
                {
                    usedNums.push_back(data[i]);
                }
            }
            else if(sum <= containerSize && sum > partialSum)
            {
                partialSum = sum;
                usedNums.clear();
                for(int i=0; i<r; i++)
                {
                    usedNums.push_back(data[i]);
                }
            }

            return;
        }

        for(int i=start; i <= end && end - i + 1 > r- index; i++)
        {
            data[index] = arr[i];
            Combine(arr, data, i + 1, end, index + 1, r, containerSize);
        }
    }

    bool FindInVec(std::vector<unsigned int> vec, unsigned int num)
    {
        for(int i=0; i<vec.size(); i++)
        {
            if(vec[i] == num) return true;
        }
        return false;
    }
public:
    Solution(unsigned int N, unsigned int W1, unsigned int W2)
    :n(N), result(0), partialSum(0), found(false)
    {
        objects = new unsigned int[n];
        if(W1 > W2) { w1 = W1; w2 = W2;}
        else { w1 = W2; w2 = W1; }

        for(int i=0; i<n; i++)
        {
            std::cin>>objects[i];
        }

        for(int i=n; i>=1; i--)
        {
            if(found) break;
            Combine(objects, new unsigned int[n], 0, n, 0, i, w1);
        }
        result += partialSum;
        partialSum = 0;
        found = false;

        if(usedNums.size() != n)
        {
            unsigned int size = n-usedNums.size();
            unsigned int *objectsLeft = new unsigned int[size];
            unsigned int index = 0;

            for(int i=0; i<size; i++)
            {
                if(!FindInVec(usedNums, objects[i]))
                {
                    objectsLeft[index] = objects[i];
                    index++;
                }
            }

            usedNums.clear();
            for(int i=size; i>=1; i--)
            {
                if(found) break;
                Combine(objectsLeft, new unsigned int[size], 0, size, 0, i, w2);
            }

        }
        result += partialSum;
    }

    ~Solution()
    {
        delete objects;
    }
    inline unsigned int GetResult() const { return result; }

};


int main()
{
    unsigned int n, w1, w2;
    std::cin>>n>>w1>>w2;
    Solution sln(n, w1, w2);
    std::cout<<sln.GetResult()<<std::endl;

    return 0;
}
