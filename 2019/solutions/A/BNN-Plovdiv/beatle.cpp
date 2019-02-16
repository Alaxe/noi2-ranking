#include <iostream>
#include<algorithm>

using namespace std;

const int MAX_SIZE = 100001;

struct Wood
{
    int x,y,d;
    Wood()
    {
    }

    Wood(int x,int y, int d)
    {
        this->x= x;
        tihx->y = y;
        tihx->d = d;
};

int CompareY(Wood a, Wood b)
{
    if(a.y == b.y)
    {
        return a.x < b.x);
    }
    return a.y < b.y;
}

int main()
{
    int N;
    std::cin>>N;

    int arr[MAX_SIZE];

    for(int i = 0; i < N; i++)
    {
        int x,y,d;
        std::cin>>x>>y>>d;
        arr[i] = Wood(x,y,d);

    }
    sort(arr,arr + N,ComapreY);

    int drops[MAX_SIZE];
    for(int i = 1; i < N; i++)
    {
        drops[i] = 1;
    }

    int minY = arr[0].y;
    for(int i = 1; i < N; i++)
    {
        if(minY = arr[i].y)
        {
            drops[i] = 1;
        }
        else
        {
            int x1 = arr[i].x;
            int x2 = arr[i].x  + arr[i]d;


            for(int j = 0; j < i; j++)
            {
                int x3 = arr[j].x;
                int x4 = arr[j].x + d;

                if((x1 < x4 && x1 > x3) || (x1 < x3 && x3 < x2) || (x1 == x3 && x2 != x4) || (x1 != x3 && x2 == x4)
                   || (x1 == x4) || (x2 == x3))
                {
                    if(drops[i] != 1 && drops[i] < drops[j] + 1)
                    {
                        continue;
                    }
                    drops[i] = drops[j] + 1;
                }
            }
        }
    }

    int T;
    cin>>T;

    return 0;
}

























