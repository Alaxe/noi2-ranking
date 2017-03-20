#include <cstdio>
#include <vector>
#include <assert.h>
using namespace std;
struct Recrangle
{
    int childrenSum;
    int x, y, height, width, parent;
    vector<int> children;
    int Surface()
    {
        return height * width;
    }
    Recrangle()
    {
        x = y = height = width = parent = childrenSum = -1;
    }
    Recrangle(int _x, int _y, int _width, int _length)
    {
        childrenSum = -1;
        x = _x;
        y = _y;
        width = _width;
        height = _length;
    }
    bool isIn(int _x, int _y)
    {
        return ((_x > x && _x < x + width) &&
                    (_y > y && _y < y + height));
    }
    void operator=(const Recrangle &f)
    {
        x = f.x;
        y = f.y;
        width = f.width;
        height = f.height;
    }
    void print()
    {
        printf("%d %d %d %d\n", x, y, width, height);
    }
};
int n;
vector<Recrangle> r;

int getArea(int f)
{
    if (r[f].childrenSum == -1)
    {
        r[f].childrenSum = 0;
        for (int i = 0; i < r[f].children.size(); i++)
            r[f].childrenSum += r[r[f].children[i]].Surface();
    }
    return r[f].Surface() - r[f].childrenSum;
}
int findLeast(int x, int y)
{
    int parent = 0;
    for (int i = 1; i <= n; i++)
            if ((r[i].isIn(x, y)) && (r[i].Surface() < r[parent].Surface()))
                parent = i;
    return parent;
}
int main ()
{
    int allW, allH;
    scanf("%d%d", &allW, &allH);
    scanf("%d", &n);
    r.resize(n+1);
    r[0] = Recrangle(0, 0, allW, allH);
    for (int i = 1; i <= n; i++)
    {
        int x, y, width, length;
        scanf("%d%d%d%d", &x, &y, &width, &length);
        r[i] = Recrangle(x, y, width, length);
    }
    for(int i = 1; i <= n; i++)
    {
        int parent = findLeast(r[i].x, r[i].y);
        r[i].parent = parent;
        r[parent].children.push_back(i);
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int parent = findLeast(x, y);
        printf("%d\n", getArea(parent));
    }
    return 0;
}
