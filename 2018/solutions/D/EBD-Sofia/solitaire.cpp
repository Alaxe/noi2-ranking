#include<iostream>
using namespace std;
int main()
{
     int N, red, kolona=0,sb[2]={0,0},sbor=0;
cin>>N;
int r=0;
red=N-1;
char karti [N] [N*2];
for(int i=0;i<N;i++)
{
     for( r=0;r<N*2;r++)
     {
          cin>>karti[i][r];
     }
}
if(karti [N-1] [0]=='2')
{
     sbor+=2;
}
else if(karti [red] [0]=='3')
{
     sbor+=3;
}
else if(karti [red] [0]=='4')
{
     sbor+=4;
}
else if(karti [red] [0]=='5')
{
     sbor+=5;
}
else if(karti [red] [0]=='6')
{
     sbor+=6;
}
else if(karti [red] [0]=='7')
{
     sbor+=7;
}
else if(karti [red] [0]=='8')
{
     sbor+=8;
}
else if(karti [red] [0]=='9')
{
     sbor+=9;
}
else if(karti [red] [0]=='A')
{
     sbor+=1;
}
else if(karti [red] [0]=='T')
{
     sbor+=10;
}
else if(karti [red] [0]=='J')
{
     sbor+=11;
}
else if(karti [red] [0]=='Q')
{
     sbor+=12;
}
else if(karti [red] [0]=='K')
{
     sbor+=13;
}

for(int dw=0;dw<=N*2-2;dw++)
{
     sb[0]=0;
sb[1]=0;
     for(int k=0;k<=1;k++)
{
     if(k==0 )
{
     red=red-1;
}
else if(kolona<N-1)
{red=red+1;
kolona=kolona+2;
}
 if(k==0 and red>=0 or k==1 and kolona<=N*2-1)
{if(karti [red] [kolona]=='2')
{
     sb[k]+=2;
}
else if(karti [red] [kolona]=='3')
{
     sb[k]+=3;
}
else if(karti [red] [kolona]=='4')
{
     sb[k]+=4;
}
else if(karti [red] [kolona]=='5')
{
     sb[k]+=5;
}
else if(karti [red] [kolona]=='6')
{
     sb[k]+=6;
}
else if(karti [red] [kolona]=='7')
{
     sb[k]+=7;
}
else if(karti [red] [kolona]=='8')
{
     sb[k]+=8;
}
else if(karti [red] [kolona]=='9')
{
     sb[k]+=9;
}
else if(karti [red] [kolona]=='A')
{
     sb[k]+=1;
}
else if(karti [red] [kolona]=='T')
{
     sb[k]+=10;
}
else if(karti [red] [kolona]=='J')
{
     sb[k]+=11;
}
else if(karti [red] [kolona]=='Q')
{
     sb[k]+=12;
}
else if(karti [red] [kolona]=='K')
{
     sb[k]=sb[k]+13;
}
}}
if(sb[0]>sb[1])
{
     sbor+=sb[0];
     kolona=kolona-2;
     red=red-1;
}
else
{
     sbor+=sb[1];
}
}

red=0;
kolona=2*N-2;
if(karti [red] [kolona]=='2')
{
     sbor+=2;
}
else if(karti [red] [kolona]=='3')
{
     sbor+=3;
}
else if(karti [red] [kolona]=='4')
{
     sbor+=4;
}
else if(karti [red] [kolona]=='5')
{
     sbor+=5;
}
else if(karti [red] [kolona]=='6')
{
     sbor+=6;
}
else if(karti [red] [kolona]=='7')
{
     sbor+=7;
}
else if(karti [red] [kolona]=='8')
{
     sbor+=8;
}
else if(karti [red] [kolona]=='9')
{
     sbor+=9;
}
else if(karti [red] [kolona]=='A')
{
     sbor+=1;
}
else if(karti [red] [kolona]=='T')
{
     sbor+=10;
}
else if(karti [red] [kolona]=='J')
{
     sbor+=11;
}
else if(karti [red] [kolona]=='Q')
{
     sbor+=12;
}
else if(karti [red] [kolona]=='K')
{
     sbor+=13;
}
cout<<sbor+9<<endl;
     return 0;
}
