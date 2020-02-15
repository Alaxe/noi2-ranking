#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

enum xState
{
    None = 0,
    AddSubtr,
    MultplDivide,
    Combined
};

enum PostPreFix
{
    NoneFix = 0,
    Plus,
    Minus,
    Star,
    Slash
};

class Solution
{
private:
    std::string base;
    std::string result;
    bool done;
private:
    void Pair(int *firstBracket, int *secondBracket, int id, int *state, const std::string& str)
    {
        int found = 1;
        int f = -1;
        int s = -1;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i] == '(')
            {
                if(found == id)
                {
                    f = i;
                    break;
                }
                else
                {
                    found++;
                }
            }
        }
        *firstBracket = f;
        int brInBetween = 0;
        for(int i=(*firstBracket+1); i<str.length(); i++)
        {
            if(str[i] == '(') brInBetween++;
            if(str[i] == ')')
            {
                if(brInBetween==0)
                {
                    s = i;
                    break;
                }
                else
                {
                    brInBetween--;
                }
            }
        }

        *secondBracket = s;

        //state
        int brackets = 0;
        for(int i=(*firstBracket+1); i<(*secondBracket-1); i++)
        {
            if(str[i] == '(') brackets++;
            if(str[i] == ')') brackets--;

            if(brackets == 0)
            {
                if(str[i] == '+' || str[i] == '-')
                {
                    if(*state == xState::None) *state = xState::AddSubtr;
                    else if(*state == xState::MultplDivide) { *state = xState::Combined; return;}
                }
                if(str[i] == '*' || str[i] == '/')
                {
                    if(*state == xState::None) *state = xState::MultplDivide;
                    else if(*state == xState::AddSubtr) { *state = xState::Combined; return;}
                }
            }
        }
        return;
    }
    int GetBracketCount(const std::string& str)
    {
        int count = 0;
        for(int i=str.length()-1; i>=0; i--)
        {
            if(str[i] == ')') count++;
        }

        return count;
    }


    void ForRemoval(const std::string& str)
    {
        int bracketCount = GetBracketCount(base);
        int removedCount = 0;

        for(int i=1; i<=bracketCount; i++)
        {
            int first, second, state = 0;
            Pair(&first, &second, 1, &state, str);
            //prefix
            int prefix;
            if(base[first-1] == '+') prefix = PostPreFix::Plus;
            else if(base[first-1] == '-') prefix = PostPreFix::Minus;
            else if(base[first-1] == '*') prefix = PostPreFix::Star;
            else if(base[first-1] == '/') prefix = PostPreFix::Slash;
            else prefix = PostPreFix::NoneFix;

            //postfix
            int postfix;
            if(base[second+1] == '+') postfix = PostPreFix::Plus;
            else if(base[second+1] == '-') postfix = PostPreFix::Minus;
            else if(base[second+1] == '*') postfix = PostPreFix::Star;
            else if(base[second+1] == '/') postfix = PostPreFix::Slash;
            else postfix = PostPreFix::NoneFix;

            //decide if brackets are removable
            if(base[first + 1] == '(' && base[second - 1] == ')')
            {
                base = base.replace(first, 1, "");
                base = base.replace(second-1, 1, "");

                continue;
            }


            if( (prefix == PostPreFix::Star || prefix == PostPreFix::Slash || prefix == PostPreFix::NoneFix || prefix == PostPreFix::Plus || prefix == PostPreFix::Minus) &&
                (postfix == PostPreFix::Star || postfix == PostPreFix::Slash || postfix == PostPreFix::NoneFix) &&
                 state == xState::MultplDivide)
            {
                base = base.replace(first, 1, "");
                base = base.replace(second-1, 1, "");

                continue;
            }

             if( (prefix == PostPreFix::Star || prefix == PostPreFix::Slash || prefix == PostPreFix::NoneFix) &&
                (postfix == PostPreFix::Star || postfix == PostPreFix::Slash || postfix == PostPreFix::NoneFix || postfix == PostPreFix::Plus || postfix == PostPreFix::Minus) &&
                 state == xState::MultplDivide)
            {
                base = base.replace(first, 1, "");
                base = base.replace(second-1, 1, "");


                continue;
            }

            if( (prefix == PostPreFix::Plus || prefix == PostPreFix::NoneFix)&&
                (postfix == PostPreFix::Plus || postfix == PostPreFix::Minus || postfix == PostPreFix::NoneFix)
               )
            {
                base = base.replace(first, 1, "");
                base = base.replace(second-1, 1, "");

                continue;
            }



        }
    }
public:
    Solution(std::string Base)
        :base(Base), done (false), result(Base)
    {
        ForRemoval(base);
    }
    ~Solution() {}
    inline std::string GetResult() const { return base; }
};

int main()
{
    std::string input;
    std::getline(std::cin, input);
    Solution sln(input);

    std::cout << sln.GetResult() << std::endl;
    return 0;
}
