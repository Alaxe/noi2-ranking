#include <iostream>
#include <cmath>

struct Point
{
    int x;
    int y;
};

int main()
{
    int n;
    std::cin>>n;
    Point points[n];
    for(int i = 0; i < n; i++)
    {
        points[i] = Point();
        std::cin>>points[i].x>>points[i].y;
    }
    int lt = 2, mlt = 2;
    for(int i = 0; i < n; i++)
    {
        Point* pt1 = &points[i];
        for(int j = i + 1; j < n; j++)
        {
            int lineLen = 2;
            Point* pt2 = &points[j];
            float f = ((float)(pt2->x - pt1->x) / ((float)pt2->y - pt1->y));
            for(int k = j + 1; k < n; k++)
            {
                Point* pt3 = &points[k];

                float dy = (pt3->x - pt1->x) / f;
                int ay = pt3->y - pt1->y;

                if(dy == ay)
                {
                    lt++;
                }


            }
            if(mlt < lt)
            {
                mlt = lt;
            }
            lt = 2;
        }
    }

    std::cout<<mlt<<std::endl;

    return 0;
}
