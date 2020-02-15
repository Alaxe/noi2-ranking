//Task: password
//Author: Kinka Kirilova-Lupanova
#include <vector>
#include <iostream>
using namespace std;

int main()
 {  string s;
    cin >> s;
    int i=0;
    vector<bool> has_char('z' + 1);
    
    for (char c='a'; c <= 'z'; ++c )
      for (i=0;i<s.size();i++)
        if (c==s[i]) has_char[c] = true;   
   
    char missing = 'a';
    for (char c = 'a'; c <= 'z'; ++c) 
        if (!has_char[c]) { missing = c;
                            break;
                          }
    for (int i = 2; i < s.length(); ++i)
        if (s[i - 2] == s[i] && s[i - 1] == s[i]) 
            s[i] = missing;
      
    vector<int> cnt('z' + 1);
    for (char c='a'; c <= 'z'; ++c)
     for (i=0;i<s.size();i++)
        if (c==s[i])  cnt[c]++;
    
    for (char c = 'a'; c <= 'z'; ++c) 
       {if (cnt[c] > s.length() / 2) 
          for (int i = 0, j = cnt[c]; i < s.length() && j > s.length() / 2; ++i)
              if (s[i] == c)
                  {char rarest = missing;
                   for (char ch = 'a'; ch <= 'z'; ++ch)
                     if (cnt[ch] < cnt[rarest]) rarest = ch;
                   s[i] = rarest;
                   --j;
                  }      
      }
   cout<<s<<endl;
    return 0;
}
