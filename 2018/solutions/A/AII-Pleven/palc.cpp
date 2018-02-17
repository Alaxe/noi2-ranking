#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define TRACE false

using namespace std;

const uint64_t MOD = 1000000007ULL;

struct border
{
    int left, right;
    size_t id;
    border(int left, int right, size_t id):left(left), right(right), id(id){}

    int size(){return right-left+1;}
};

bool by_left(int left, const border &b)
{return left<b.left;}

int n;
string s;

vector<border> borders;
vector<vector<border>> bordersBySize;
vector<int> validBorderSizes;


bool by_len(border x, border y)
{return x.size()<y.size();}

void find_borders()
{
    bordersBySize.resize(n+1);

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(s[i]==s[j])
            {
                border p{i, j, borders.size()};
                borders.push_back(p);
                bordersBySize[p.size()].push_back(p);
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        if(!bordersBySize[i].empty())validBorderSizes.push_back(i);
    }
}

void solve()
{
    find_borders();

#if TRACE
    for(int i=0;i<n;i++)
    {
        printf("%d:\n", i);
        for(auto x : bordersBySize[i])
        {
            printf("  %d %d\n", x.left, x.right);
        }
        printf("\n");
    }
#endif // TRACE

    uint64_t answer=0;
    vector<uint64_t> answersByBorder(borders.size());

    vector<vector<int>> bordersBySizeUpperBounds(n+1, vector<int>(n+1, n+1));
    for(int borderSize : validBorderSizes)
    {
        for(int i=0, currentL=0;i<bordersBySize[borderSize].size();currentL++)
        {
            while(i<bordersBySize[borderSize].size() && bordersBySize[borderSize][i].left<=currentL)i++;
            bordersBySizeUpperBounds[borderSize][currentL] = i;
        }
    }

    //for(int borderLen=1;borderLen<=n;borderLen++)
    for(int borderLen : validBorderSizes)
    {
        for(const border &border : bordersBySize[borderLen])
        {
            answersByBorder[border.id]+=1;
            //for(int subLen=1;subLen<borderLen;subLen++)
            for(int subLen : validBorderSizes)
            {
                if(subLen>=borderLen)break;

                //for(const struct border &sub : bordersBySize[subLen])
                for(
                    //int subI=0;
                    /*int subI=upper_bound(
                        bordersBySize[subLen].begin(),
                        bordersBySize[subLen].end(),
                        border.left,
                        by_left
                    ) - bordersBySize[subLen].begin();*/
                    int subI = bordersBySizeUpperBounds[subLen][border.left];
                    subI<bordersBySize[subLen].size();
                    subI++
                )
                {
                    const struct border &sub = bordersBySize[subLen][subI];
                    if(sub.left<=border.left)
                    {
                        cerr<<"This should never happen thanks to the might and glory of upper_bound.";
                        continue;
                    }
                    if(sub.right>=border.right)break;
                    answersByBorder[border.id]+=answersByBorder[sub.id];
                }
            }

            answersByBorder[border.id]%=MOD;
            answer+=answersByBorder[border.id];
            answer%=MOD;
        }
    }

    printf("%llu\n", answer%MOD);
}

int main()
{
    #if TRACE
    printf("%llu\n", MOD);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    //s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    n=s.size();
    solve();
}
/**
a
aaaa
aaaaaaaaaa

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
976371284

acbac
aba
ivan
gaden_mazen_krokodil

zdravko_s_pileshko
akam_bez_da_klqkam

a_a_b
**/
