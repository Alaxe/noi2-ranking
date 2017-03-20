#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <climits>
using namespace std;
typedef long long lld;

struct HugeNum
{
    vector<int> num; /// reversed

    HugeNum()
    {
        num.clear();
    }
    HugeNum(lld inum)
    {
        num.clear();
        do
        {
            num.push_back(inum%10);
            inum /= 10;
        }
        while (inum > 0);
    }

    HugeNum operator+(const HugeNum& other)const
    {
        HugeNum ret = HugeNum();
        ret.num.reserve( max(num.size(),other.num.size()) );

        int take = 0;

        for (int i=0; i<max(num.size(), other.num.size()); i++)
        {
            int n1 = (i<num.size()) ? num[i] : 0;
            int n2 = (i<other.num.size()) ? other.num[i] : 0;

            int res = n1+n2+take;
            ret.num.push_back(res%10);
            take = res/10;
        }

        while (take > 0)
        {
            ret.num.push_back(take%10);
            take /= 10;
        }

        return ret;
    }

    HugeNum operator-(const HugeNum& other)const
    {
        HugeNum ret = HugeNum();

        int take = 0;

        for (int i=0; i<max(num.size(), other.num.size()); i++)
        {
            int n1 = (i<num.size()) ? num[i] : 0;
            int n2 = (i<other.num.size()) ? other.num[i] : 0;

            int res = n1-n2-take;

            take = 0;
            while (res < 0)
            {
                res += 10;
                take ++;
            }

            ret.num.push_back(res);
        }

        while (ret.num.back() == 0) ret.num.pop_back();

        return ret;
    }

    HugeNum operator*(const lld& other)const
    {
        HugeNum ret = HugeNum();
        ret.num.reserve(num.size());

        int take = 0;

        for (int i=0; i<num.size(); i++)
        {
            int n1 = num[i];
            int n2 = other;

            int res = n1*n2+take;
            ret.num.push_back(res%10);
            take = res/10;
        }

        while (take > 0)
        {
            ret.num.push_back(take%10);
            take /= 10;
        }

        return ret;
    }

    void AddZeroes(int cnt)
    {
        reverse(num.begin(), num.end());
        for (int i=1; i<=cnt; i++) num.push_back(0);
        reverse(num.begin(), num.end());
    }

    HugeNum operator*(const HugeNum& other)const
    {
        HugeNum ret = HugeNum();

        ret.num.reserve(num.size()+other.num.size());

        for (int i=0; i<num.size(); i++)
        {
            HugeNum heh = other*num[i];
            heh.AddZeroes(i);

            ret = ret + heh;
        }

        return ret;
    }

    HugeNum operator/(const lld& other)const
    {
        vector<int> temp = vector<int>(num);
        reverse(temp.begin(), temp.end());

        HugeNum ret = HugeNum();
        lld cur = 0;

        for (int i=0; i<temp.size(); i++)
        {
            cur = cur*10 + temp[i];
            lld tow = cur / other;

            ret.num.push_back(tow);
            cur = cur%other;
        }

        reverse(ret.num.begin(), ret.num.end());
        while (ret.num.back() == 0) ret.num.pop_back();

        return ret;
    }

    bool operator<(const HugeNum& other)const
    {
        if (num.size() != other.num.size()) return (num.size() < other.num.size());
        for (int i=(int)num.size()-1; i>=0; i--)
        {
            if (num[i] == other.num[i]) continue;
            return (num[i] < other.num[i]);
        }

        return false;
    }
    bool operator==(const HugeNum& other)const
    {
        if (num.size() != other.num.size()) return false;
        for (int i=(int)num.size()-1; i>=0; i--)
        {
            if (num[i] == other.num[i]) continue;
            return false;
        }

        return true;
    }

    lld Get()
    {
        lld ret = 0;
        for (int i=(int)num.size()-1; i>=0; i--)
        {
            ret = ret*10 + num[i];
        }

        return ret;
    }
    void Print()
    {
        for (int i=(int)num.size()-1; i>=0; i--)
        {
            printf("%d", num[i]);
        }
    }
};

char n1[102], n2[102];
HugeNum L, R;

int main ()
{
    scanf("%s", n1);
    scanf("%s", n2);

    L.num.clear();
    R.num.clear();

    int sz;
    sz = strlen(n1);
    for (int i=sz-1; i>=0; i--)
    {
        L.num.push_back(n1[i]-'0');
    }

    sz = strlen(n2);
    for (int i=sz-1; i>=0; i--)
    {
        R.num.push_back(n2[i]-'0');
    }

    HugeNum bl, br, bmid, bres;
    HugeNum from, to;
    bool cool;


    bl = HugeNum(1);
    br = HugeNum(R);
    cool = false;

    while (bl < br || (bl == br))
    {
        bmid = (bl+br) / 2;
        HugeNum res = bmid * (bmid+1);

        if (res < L)
        {
            bl = bmid+1;
        }
        else
        {
            cool = true;
            bres = bmid;
            br = bmid-1;
        }
    }
    from = bres;

    if (!cool)
    {
        printf("0\n");
        return 0;
    }

    bl = HugeNum(1);
    br = HugeNum(R);
    cool = false;

    while (bl < br || (bl == br))
    {
        bmid = (bl+br) / 2;
        HugeNum res = bmid * (bmid+1);

        if (R < res)
        {
            br = bmid-1;
        }
        else
        {
            cool = true;
            bres = bmid;
            bl = bmid+1;
        }
    }
    to = bres;

    if (!cool || to < from)
    {
        printf("%d\n", 0);
        return 0;
    }

    HugeNum ans = to-from+1;

    ans.Print();
    printf("\n");
}
