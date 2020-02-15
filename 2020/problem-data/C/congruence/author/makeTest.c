#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#define randomize() (srand(time(0)))
#define random(x) (rand() % x)
//input params: letter_count word_length random_seed
int main(int pcnt,const char **par)
{int cnt=1,n=0,rs=0,i,r;
 char b[26], a[26];
 if (pcnt>4) pcnt=4;
 switch (pcnt)
 {case 4:rs=atoi(par[3]);
  case 3:n=atoi(par[2]);
  case 2:cnt=atoi(par[1]);
 }
 if (cnt<=0) cnt=1;
 if (cnt>26) cnt=26;
 if (!rs) randomize();else srand(rs);
 if (n<cnt) n=cnt;
 for (i=0;i<26;i++) b[i]=0;
 for (i=0;i<cnt;i++)
 {do
   r=random(26);
  while (b[r]);
  b[r]=1;
  a[i]='A'+r;
 }
 for (i=0;i<n;i++) printf("%c",a[random(cnt)]);
 printf("\n");
 return 0;
}
