//Task: palindrome
//Author: Kinka Kirilowa-Lupanowa

#include <iostream>
using namespace std;

string s,p;
void  palin(string &s) //превръщане на числото в палиндром
{int i,k;
 for (i=0; i< s.length()/2; i++)  
     s[s.length()-i-1]=s[i];
}

void inchalf(string &s) // увеличаване първата половина на числото с 1
{int k;
 k=(s.length()+1) / 2-1;
 while (k>=0) 
       {if (s[k]=='9' )
            {s[k]='0';
             k--;
            }
        else
            { s[k]++; 
              return ;
            }  
        }
   s='1'+s;   
}  
int main()
{ cin>>s;
  p=s;
  palin(p); // правим палиндром
  if (p<=s)  // новото число е по-малко или равно на изходното
       {inchalf(p); // увеличаваме с 1, започвайки от средата
        palin(p); // отново правим палиндром
       }
cout<<p<<endl;
return 0;
}
 
 
