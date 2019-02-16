#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define MaxHeight 100005

struct Shelf
{
    int leftEnd;
    int rightEnd;
    int minHops;
};

vector<Shelf> shelfs[MaxHeight];
int lastHeight;
int firstHeight;

void Input()
{
    int numberOfShelfs;
    scanf("%d", &numberOfShelfs);

    int x, y, d;
    firstHeight = MaxHeight;
    lastHeight = -1;
    for (int i = 0; i < numberOfShelfs; i++)
    {
        scanf("%d %d %d", &x, &y, &d);
        Shelf sh = {x, x + d, -1};
        shelfs[y].push_back(sh);
        firstHeight = min(firstHeight, y);
        lastHeight = max(lastHeight, y);
    }
}

void FindMinHops(int height, int index)
{
    if (height == firstHeight)
    {
        shelfs[height][index].minHops = 1;
        return;
    }

    shelfs[height][index].minHops = MaxHeight;
    int l = shelfs[height][index].leftEnd, r = shelfs[height][index].rightEnd;

    bool found = false;
    for (int i = height - 1; i >= firstHeight; i--)
    {
        for (int j = 0; j < shelfs[i].size(); j++)
        {
            if ((l > shelfs[i][j].leftEnd && l <= shelfs[i][j].rightEnd))
            {
                shelfs[height][index].minHops =
                    min(shelfs[height][index].minHops, shelfs[i][j].minHops + 1);
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (shelfs[height][index].minHops == MaxHeight)
    {
        shelfs[height][index].minHops = 1;
        return;
    }
    found = false;
    for (int i = height - 1; i >= firstHeight; i--)
    {
        for (int j = 0; j < shelfs[i].size(); j++)
        {
            if ((r >= shelfs[i][j].leftEnd && r < shelfs[i][j].rightEnd))
            {
                shelfs[height][index].minHops =
                    min(shelfs[height][index].minHops, shelfs[i][j].minHops + 1);
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (shelfs[height][index].minHops == MaxHeight) shelfs[height][index].minHops = 1;
}

void FindAllMinHops()
{
    for (int i = firstHeight; i <= lastHeight; i++)
    {
        for (int j = 0; j < shelfs[i].size(); j++)
        {
            FindMinHops(i, j);;
        }
    }
}

void Query(int x, bool last)
{
    for (int i = lastHeight; i >= firstHeight; i--)
    {
        for (int j = 0; j < shelfs[i].size(); j++)
        {
            if (x >= shelfs[i][j].leftEnd && x < shelfs[i][j].rightEnd)
            {
                printf("%d", shelfs[i][j].minHops);
                if (!last) printf(" ");
                return;
            }
        }
    }
}

int main()
{
    Input();
    FindAllMinHops();

    int numberOfQueries;
    scanf("%d", &numberOfQueries);
    for (int i = 0; i < numberOfQueries; i++)
    {
        int x;
        scanf("%d", &x);
        Query(x, (i == numberOfQueries - 1));
    }
    printf("\n");

    return 0;
}
