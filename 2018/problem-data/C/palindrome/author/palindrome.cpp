//Task: palindrome
//Author: Kinka Kirilowa-Lupanowa

#include <iostream>
using namespace std;

string s,p;
void  palin(string &s) //���������� �� ������� � ���������
{int i,k;
 for (i=0; i< s.length()/2; i++)  
     s[s.length()-i-1]=s[i];
}

void inchalf(string &s) // ����������� ������� �������� �� ������� � 1
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
  palin(p); // ������ ���������
  if (p<=s)  // ������ ����� � ��-����� ��� ����� �� ���������
       {inchalf(p); // ����������� � 1, ���������� �� �������
        palin(p); // ������ ������ ���������
       }
cout<<p<<endl;
return 0;
}
 
 
