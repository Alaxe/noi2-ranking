#include<iostream>
#include<cmath>
using namespace std;

long long b[64];

void Init()
{
    b[0]=1;
    for(int i=1;i<64;i++)b[i]=b[i-1]<<1;
}

bool is2onP(long long a, int &i)
{
    for(i=0;i<64;i++)
     if(b[i]>=a)return true;
    return false;
}

bool isTrue(int z, long long s)
{
    while(s)
    {
        z-=!(s%2);
        if(z<0)return false;
        s/=2;
    }
    return z==0;
}

long long Sol1(long long s, long long t, int z)
{
    long long c=0;
    for(;s<=t;s++)
	 if(isTrue(z,s)){/*cout<<s<<' ';*/c++;}
    return c;
}

void reduceToPrimal(int n, int *q)
{
    switch(n)
    {
        case 4: q[2]+=2*q[4];q[4]=0;
        case 6: q[2]+=q[6];q[3]+=q[6];q[6]=0;
        case 8: q[2]+=3*q[8];q[8]=0;
        case 9: q[3]+=2*q[9];q[9]=0;
        case 10: q[2]+=q[10];q[5]+=q[10];q[10]=0;
        case 12: q[2]+=2*q[12];q[3]+=q[12];q[12]=0;
        case 14: q[2]+=q[14];q[7]+=q[14];q[14]=0;
        case 15: q[3]+=q[15];q[5]+=q[15];q[15]=0;
        case 16: q[2]+=4*q[16];q[16]=0;
        case 18: q[2]+=q[18];q[3]+=2*q[18];q[18]=0;
        case 20: q[2]+=2*q[20];q[5]+=q[20];q[20]=0;
        case 21: q[3]+=q[21];q[7]+=q[21];q[21]=0;
        case 22: q[2]+=q[22];q[11]+=q[22];q[22]=0;
        case 24: q[2]+=3*q[24];q[3]+=q[24];q[24]=0;
        case 25: q[5]+=2*q[25];q[25]=0;
        case 26: q[2]+=q[26];q[13]+=q[26];q[26]=0;
        case 27: q[3]+=3*q[27];q[27]=0;
        case 28: q[2]+=2*q[28];q[7]+=q[28];q[28]=0;
        case 30: q[2]+=q[30];q[3]+=q[30];q[5]+=q[30];q[30]=0;
        case 32: q[2]+=5*q[32];q[32]=0;
        case 33: q[3]+=q[33];q[11]+=q[33];q[33]=0;
        case 34: q[2]+=q[34];q[17]+=q[34];q[34]=0;
        case 35: q[5]+=q[35];q[7]+=q[35];q[35]=0;
        case 36: q[2]+=2*q[36];q[3]+=2*q[36];q[36]=0;
        case 38: q[2]+=2*q[38];q[19]+=q[38];q[38]=0;
        case 39: q[3]+=q[39];q[13]+=q[39];q[39]=0;
        case 40: q[2]+=3*q[40];q[5]+=q[40];q[40]=0;
        case 42: q[2]+=q[42];q[3]+=q[42];q[7]+=q[42];q[42]=0;
        case 44: q[2]+=2*q[44];q[11]+=q[44];q[44]=0;
        case 45: q[3]+=2*q[45];q[5]+=q[45];q[45]=0;
        case 46: q[2]+=q[46];q[23]+=q[46];q[46]=0;
        case 48: q[2]+=4*q[48];q[3]+=q[48];q[48]=0;
        case 49: q[7]+=2*q[49];q[49]=0;
        case 50: q[2]+=q[50];q[5]+=2*q[50];q[50]=0;
        case 51: q[3]+=q[51];q[17]+=q[51];q[51]=0;
        case 52: q[2]+=2*q[52];q[13]+=q[52];q[52]=0;
        case 54: q[2]+=q[54];q[3]+=3*q[54];q[54]=0;
        case 55: q[5]+=q[55];q[11]+=q[55];q[55]=0;
        case 56: q[2]+=3*q[56];q[7]+=q[56];q[56]=0;
        case 57: q[3]+=q[57];q[19]+=q[57];q[57]=0;
        case 58: q[2]+=q[58];q[29]+=q[58];q[58]=0;
        case 60: q[2]+=2*q[60];q[3]+=q[60];q[5]+=q[60];q[60]=0;
    }
}

void reduceToPrimals(int p, int *q)
{
    for(int i=4;i<p;i++)reduceToPrimal(i,q);
}

long long nk(int n, int k)
{
    if(n-1<k)return 0;
    long long c=1;
    int q[64];
    for(int i=0;i<64;i++)q[i]=0;
    for(int i=2;i<n;i++)q[i]=1;for(int i=2;i<n-k;i++)q[i]--;for(int i=2;i<k+1;i++)q[i]--;
    reduceToPrimals(n,q);
    for(int i=2;i<n;i++)c*=pow(i,q[i]);
    
    
    
    //cout<<'!'<<n-1<<"/(!"<<(n-k-1)<<"*!"<<k<<")\n";
    //return fact(n-1)/(fact(n-k-1)*fact(k));
    return c;
}

long long Sol3(long long s, long long t, int z)
{
    long long c=0;
    int a,b,A,B;
    is2onP(s,A);
    is2onP(t,B);if(::b[B]>t)B--;
    a=A;b=B;
    for(++a;a<=b;a++)c+=nk(a,z);
    c+=isTrue(z,::b[b]);
    a=A;b=B;
    c+=Sol1(s,::b[a]-1,z);
    c+=Sol1(::b[b]+1,t,z);
    return c;
}

int main()
{
    Init();
	long long t,s;
	int z;
	cin>>s>>t>>z;
	cout<<Sol3(s,t,z)<<endl;
}
/**
2097152
4194304
2

2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61
*/