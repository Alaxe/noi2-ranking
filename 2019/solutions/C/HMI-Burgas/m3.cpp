#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int S, K;
    cin >> S >> K;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int typeA[3] = {a, c, b};
    int typeB[3] = {b, a, c};
    int typeC[3] = {b, c, a};
    int typeD[3] = {c, a ,b};

    double sizes[4] = {0, 0, 0 ,0};

    double sectorSize = d*4*1;
    int fullSectors = (K/sectorSize);
    double leftSize = (K - sectorSize*fullSectors);
    int sectorType = (fullSectors)%4 + 1;
    if (sectorType == 1)
    {
        if (leftSize > typeA[0])
        {
            if (leftSize > (double)(2*(typeA[1])))
            {
                sizes[0] = typeA[1];
                sizes[1] = typeA[1];
                leftSize -= typeA[1]*2;
                if (leftSize > typeA[2])
                {
                    leftSize -= typeA[2];
                    sizes[2] = typeA[2];
                    sizes[3] = leftSize;
                } else {
                    sizes[2] = leftSize;
                    leftSize = 0;
                }
            } else {
                sizes[0] = leftSize/2;
                sizes[1] = leftSize/2;
            }
        } else {
            sizes[0] = leftSize;
            leftSize = 0;
            }
    } else if (sectorType == 2)
    {
        if(3*typeB[2] > leftSize)
        {
            leftSize -= typeB[0];
            sizes[0] = typeB[0];
        }
        if (leftSize > typeB[1])
        {
            if ((double)(2*(typeB[2])) > leftSize)
            {
                sizes[1] = leftSize/2;
                sizes[2] = leftSize/2;
                leftSize = 0;
            } else {
                leftSize -= 3*typeB[2];
                sizes[0] = typeB[2];
                sizes[1] = typeB[2];
                sizes[2] = typeB[2];
                sizes[3] = leftSize;
            }
        } else {
            sizes[1] = leftSize;
            leftSize = 0;
        }
    } else if (sectorType == 3)
    {
        if (leftSize > typeC[0])
        {
            if (leftSize > typeC[1])
            {
                sizes[0] = typeC[1];
                sizes[1] = typeC[1];
                leftSize -= typeC[1]*2;
                if(leftSize > typeC[2])
                {
                    sizes[2] = leftSize/2;
                    sizes[3] = leftSize/2;
                } else {
                    sizes[2] = leftSize;
                    leftSize = 0;
                }
            } else {
                sizes[1] = leftSize;
                leftSize = 0;
            }
        } else {
            sizes[0] = leftSize;
            leftSize = 0;
        }
    } else if (sectorType == 4)
    {
        if (leftSize > typeD[0])
        {
            if (leftSize > typeD[1]) {
                if (leftSize> typeD[2])
                {
                    sizes[1] = typeD[2];
                    sizes[2] = typeD[2];
                    leftSize -= typeD[2]*2;
                    sizes[3] = leftSize;
                } else {
                    sizes[1] = leftSize/2;
                    sizes[2] = leftSize/2;
                }
            } else {
                sizes[1] = leftSize;
                leftSize = 0;
            }
        } else {
            sizes[0] = leftSize;
            leftSize = 0;
        }
    }

    if (leftSize == 0)
    {
        if (sizes[0] == 0 && sizes[1] == 0 && sizes[2] == 0 && sizes[3] == 0)
        {
        sizes[0] = d;
        sizes[1] = d;
        sizes[2] = d;
        sizes[3] = d;
        }
    }
    printf("%.3f %.3f %.3f %.3f", sizes[0], sizes[1], sizes[2], sizes[3]);
    //cout << sizes[0] << " " << sizes[1] << " " << sizes[2] << " " << sizes[3] << endl;
}
