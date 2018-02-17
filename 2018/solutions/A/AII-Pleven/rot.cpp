#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>
#define TRACE false
using namespace std;

const int TEST_COUNT = 4;
int b;

int get_digit (char c)
{
    if(c>='0' && c<='9')return c-'0';
    if(c>='a' && c<='z')return c-'a' + 10;
    if(c>='A' && c<='Z')return c-'A' + 10;
}

char get_char (int digit)
{
    if(digit<10)return '0' + digit;
    else return 'A' + (digit - 10);
}

int guess_lower(int upper, int result, bool &outTaken)
{
    outTaken = (upper<result);

    if(!outTaken)return upper - result;
    else return b + upper - result;
}

deque<int> get_digits(const string &s)
{
    deque<int> digits;
    for(char x : s)digits.push_back(get_digit(x));
    return std::move(digits);
}

bool try_solve(int firstDigit, const deque<int> result, vector<int> &outSolution)
{
    const int UNKNOWN = -1;

    bool success = true;
    int n=result.size();

    vector<int> a(n, UNKNOWN), b(n, UNKNOWN);

    a.back()=firstDigit;
    b.front()=firstDigit;

    bool previouslyTaken = false;
    for(int i=n-1;i>=0;i--)
    {
        int upper=a[i];
        int resultDigit = result[i];
        if(previouslyTaken)resultDigit++;

        bool willTake;
        if(b[i]==UNKNOWN)
        {
            b[i] = guess_lower(upper, resultDigit, willTake);
            if(i!=0)a[i-1]=b[i];
        }
        else
        {
            success = success && (b[i]==guess_lower(upper, resultDigit, willTake));
        }

        previouslyTaken = willTake;
    }

    if(b[0] == 0)success = false;
    if(a.front()<b.front())success = false;
    if(b.front()!=guess_lower(a.front(), result.front(), previouslyTaken))success=false;

#if TRACE
    if(success)
    {
        for(int x : a)printf("%2d ", x); printf("\n");
        puts("-");
        for(int x : b)printf("%2d ", x); printf("\n");
        for(int x : a)printf("___"); printf("\n");
        for(int x : result)printf("%2d ", x); printf("\n");
        printf("valid: %d\n", (int)success);
    }
#endif // TRACE

    if(success)outSolution = std::move(b);
    return success;
}

void solve(string m)
{
    if(m=="0")
    {
        puts("1");
        return;
    }
    deque<int> digits  = get_digits(m);
    bool solved = false;

    for(int tz=0;tz<100 && !solved;tz++)
    {
        for(int i=0;i<b;i++)
        {
            vector<int> solution;
            if(try_solve(i, digits, solution))
            {
                solved=true;
                for(int x : solution)printf("%c", get_char(x));
                putchar('\n');
                break;
            }
        }
        if(!solved)digits.push_front(0);
    }
    if(!solved)puts("0");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>b;
    for(int i=0;i<TEST_COUNT;i++)
    {
        string m;
        cin>>m;
        solve(m);
    }
}
/**
10
216
1318
2349
44444

16 0

16
4edef
1419
6ebe
eba4ebebaba

5 123

3 2
**/
