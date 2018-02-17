#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
string s;
bool only_9(string s)
{
    for (int i=0;i<int(s.size());i++)
        if (s[i]!='9')
        return false;
    return true;
}
string add1(string s)
{
    if (only_9(s))
    {
        string answer;
        answer+='1';
        for (int i=0;i<int(s.size());i++)
            answer+='0';
        return answer;
    }
    int i=int(s.size())-1;
    while (i>=0&&s[i]=='9')
        i--;
    s[i]++;
    for (i++;i<int(s.size());i++)
        s[i]='0';
    return s;
}
string gen_possible_answer(string s)
{
     string first_middle;
    for (int i=0;i<int((s.size()+1)>>1);i++)
        first_middle+=s[i];
    string second_middle;
    for (int i=int((s.size())>>1)-1;i>=0;i--)
        second_middle+=first_middle[i];
    string answer;
    answer=first_middle+second_middle;
 //   cout<<"first_way"<<answer<<endl;
    if (answer>s)
        return answer;
   // cout<<"last"<<s<<"SIZE"<<s.size()<<endl;
    first_middle=add1(first_middle);
   // cout<<"next"<<s<<"SIZE"<<s.size()<<endl;
    second_middle="";
    for (int i=int((s.size())>>1)-1;i>=0;i--)
        second_middle+=first_middle[i];
    answer=first_middle+second_middle;
   // cout<<"second_way"<<answer<<endl;
    return answer;
}
string int_to_string(int number)
{
    string answer;
    while (number)
    {
        answer+=char((number%10)+('0'));
        number/=10;
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
int string_to_int(string s)
{
    int answer=0;
    for (int i=0;i<int(s.size());i++)
        answer=(answer*10)+(s[i]-'0');
    return answer;
}
bool is_palindrome(string s)
{
    int left=0,right=int(s.size())-1;
    while (left<right)
    {
        if (s[left]!=s[right])
            return false;
        left++,right--;
    }
    return true;
}
//bool PALINDROME[1<<21];
//int NEXT_PALINDROME[1<<21];
//string NEXT_PALINDROME_string[1<<21];
int main()
{
    cin>>s;
    if (only_9(s))
    {
        cout<<1;
        for (int i=0;i<int(s.size())-1;i++)
            cout<<0;
        cout<<1;
        cout<<endl;
        return 0;
    }
   /* string translate="1";
    int i;
    int cntBAD=0;
    for (int i=1;i<=2000000;i++)
    {
        string ii=int_to_string(i);
        PALINDROME[i]=is_palindrome(ii);
    }
    int smallest_ok=inf;
    for (int i=2000000;i>=1;i--)
    {
        NEXT_PALINDROME[i]=smallest_ok;
        NEXT_PALINDROME_string[i]=int_to_string(NEXT_PALINDROME[i]);
        if (PALINDROME[i])
            smallest_ok=i;
    }
    for (int i=1;i<=2000000;i++)
    {
        string ii=int_to_string(i);
        string ansFAST=gen_possible_answer(ii);
        string ansSLOW=NEXT_PALINDROME_string[i];
        /*if (i<=30)
            cout<<ansFAST<<" "<<ansSLOW<<endl;
        if (ansFAST!=ansSLOW)
            cout<<i<<" BAD"<<endl;
        //cout<<int_to_string(i)<<" "<<translate<<endl;
        translate=add1(translate);
    }
    cout<<cntBAD<<endl;*/
    cout<<gen_possible_answer(s)<<endl;
    return 0;
}
