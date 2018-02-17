#include <iostream>
using namespace std;


int main()
{
    char k[4];
    cin>>k;
    int a,b,c,d,as=0;
    d= (int)k[3]-48;
    c= (int)k[2]-48;
    b= (int)k[1]-48;
    a= (int)k[0]-48;
    int asd[64];
    asd[0]=a;
    asd[1]=b;
    asd[2]=c;
    asd[3]=d;
    if(b>0)
    {
        asd[4]=a*10+b;
        asd[5]=a*10+c;
        asd[6]=a*10+d;
        asd[7]=b*10+a;
        asd[8]=b*10+c;
        asd[9]=b*10+d;
        asd[10]=c*10+a;
        asd[11]=c*10+b;
        asd[12]=c*10+d;
        asd[13]=d*10+a;
        asd[14]=d*10+b;
        asd[15]=d*10+c;
        if(c>0)
        {
            asd[16]=a*100+b*10+c;
            asd[17]=a*100+b*10+d;
            asd[18]=a*100+c*10+b;
            asd[19]=a*100+c*10+d;
            asd[20]=a*100+d*10+b;
            asd[21]=a*100+d*10+c;
            asd[22]=b*100+a*10+c;
            asd[23]=b*100+a*10+d;
            asd[24]=b*100+c*10+a;
            asd[25]=b*100+c*10+d;
            asd[26]=b*100+d*10+a;
            asd[27]=b*100+d*10+c;
            asd[28]=c*100+a*10+b;
            asd[28]=c*100+a*10+d;
            asd[29]=c*100+b*10+a;
            asd[30]=c*100+b*10+d;
            asd[31]=c*100+d*10+a;
            asd[32]=c*100+d*10+b;
            asd[33]=d*100+a*10+b;
            asd[34]=d*100+a*10+c;
            asd[35]=d*100+b*10+a;
            asd[36]=d*100+b*10+c;
            asd[37]=d*100+c*10+a;
            asd[38]=d*100+c*10+b;
            asd[39]=c*100+a*10+b;
            if(d>0)
            {
                asd[40]=a*1000+b*100+c*10+d;
                asd[41]=a*1000+b*100+d*10+c;
                asd[42]=a*1000+c*100+b*10+d;
                asd[43]=a*1000+c*100+d*10+b;
                asd[44]=a*1000+d*100+b*10+c;
                asd[45]=a*1000+d*100+c*10+b;
                asd[46]=b*1000+a*100+c*10+d;
                asd[47]=b*1000+a*100+d*10+c;
                asd[48]=b*1000+c*100+a*10+d;
                asd[49]=b*1000+c*100+d*10+a;
                asd[50]=b*1000+d*100+a*10+c;
                asd[51]=b*1000+d*100+c*10+a;
                asd[52]=c*1000+a*100+b*10+d;
                asd[53]=c*1000+a*100+d*10+b;
                asd[54]=c*1000+b*100+a*10+d;
                asd[55]=c*1000+b*100+d*10+a;
                asd[56]=c*1000+d*100+a*10+b;
                asd[57]=c*1000+d*100+b*10+a;
                asd[58]=d*1000+a*100+b*10+c;
                asd[59]=d*1000+a*100+c*10+b;
                asd[60]=d*1000+b*100+a*10+c;
                asd[61]=d*1000+b*100+c*10+a;
                asd[62]=d*1000+c*100+a*10+b;
                asd[63]=d*1000+c*100+b*10+a;

            }
            else as=40;
        }
        else as = 16;
    }
    else as=4;

    int n,m,br=0;

    cin>>n>>m;

    for(int i=0; i<as; i++)
    {
       // cout<<asd[i]<<endl;
        if(asd[i]%n==0&&asd[i]%m!=0)br++;
    }

    cout<<br<<endl;

    return 0;
}
