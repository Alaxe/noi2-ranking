#include<bits/stdc++.h>
using namespace std;
double s,k;
int a,b,c,d,i,ss1,ss2,ss3,ss4;
double s1,s2,s3,s4;

string lupov2 (double s2)
{
    int i=0,s;
    string s1;
    s=s2*10000;
    if (s%10>=5) s=s+10;

    s=s/10;
    for (i=1;i<=3;i++)
    {
        s1=char(s%10+'0')+s1;
        s=s/10;
    }

    return s1;
}

string lupov1 (double s2)
{
    if (s2<1) return "0";

    int i=0,s;
    string s1;
    s=s2*10000;
    if (s%10>=5) s=s+10;

    s=s/10000;
    for (i=1;s>0;i++)
    {
        s1=char(s%10+'0')+s1;
        s=s/10;
    }

    return s1;
}

int main()
{
    cin>>s>>k;
    cin>>a>>b>>c>>d;
    for (i=1;i<=s;i++)
    {
        if (k>d*4) k=k-d*4;
        else break;
    }


    if (i%4==1)
    {
        swap (b,c);

        if (a<k) {s1=a;k=k-a;}
        else {s1=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (a<k) {s2=a;k=k-a;}
        else {s2=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if ((b-a)*2<k) {s1=b;s2=b;k=k-(b-a)*2;}
        else {s1=s1+k/2;s2=s2+k/2;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (c<k) {s3=c;k=k-c;}
        else {s3=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (c<k) {s4=c;k=k-c;}
        else {s4=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if ((b-c)*2<k) {s3=b;s4=b;k=k-(b-c)*2;}
        else {s3=s3+k/2;s4=s4+k/2;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        s1=s1+k/4;
        s2=s2+k/4;
        s3=s3+k/4;
        s4=s4+k/4;

        cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;
        return 0;
    }
    if (i%4==2)
    {
        swap (a,b);

        if (a<k) {s1=a;k=k-a;}
        else {s1=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (b<k) {s2=b;k=k-b;}
        else {s2=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (b<k) {s3=b;k=k-b;}
        else {s3=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if ((a-b)*2<k) {s2=a;s3=a;k=k-(a-b)*2;}
        else {s3=s3+k/2;s2=s2+k/2;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if ((c-a)*3<k) {s1=c;s2=c;s3=c;k=k-(c-a)*3;}
        else {s1=s1+k/3;s2=s2+k/3;s3=s3+k/3;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (c<k) {s4=c;k=k-c;}
        else {s4=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        s1=s1+k/4;
        s2=s2+k/4;
        s3=s3+k/4;
        s4=s4+k/4;

        cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;
        return 0;
    }
    if (i%4==3)
    {
        swap (a,b);
        swap (a,c);

        if (a<k) {s1=a;k=k-a;}
        else {s1=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (a<k) {s2=a;k=k-a;}
        else {s2=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if ((b-a)*2<k) {s1=b;s2=b;k=k-(b-a)*2;}
        else {s1=s1+k/2;s2=s2+k/2;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (c<k) {s3=c;k=k-c;}
        else {s3=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (c<k) {s4=c;k=k-c;}
        else {s4=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if ((b-c)*2<k) {s3=b;s4=b;k=k-(b-c)*2;}
        else {s3=s3+k/2;s4=s4+k/2;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        s1=s1+k/4;
        s2=s2+k/4;
        s3=s3+k/4;
        s4=s4+k/4;

        cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;
        return 0;
    }
    if (i%4==0)
    {
        swap (a,b);
        swap (b,c);

        if (a<k) {s1=a;k=k-a;}
        else {s1=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (b<k) {s2=b;k=k-b;}
        else {s2=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (b<k) {s3=b;k=k-b;}
        else {s3=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if ((c-b)*2<k) {s2=c;s3=c;k=k-(c-b)*2;}
        else {s3=s3+k/2;s2=s2+k/2;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if (c<k) {s4=c;k=k-c;}
        else {s4=k;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        if ((a-c)*3<k) {s2=a;s3=a;s4=a;k=k-(a-c)*3;}
        else {s2=s2+k/3;s3=s3+k/3;s4=s4+k/3;cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;return 0;}

        s1=s1+k/4;
        s2=s2+k/4;
        s3=s3+k/4;
        s4=s4+k/4;

        cout<<lupov1(s1)<<"."<<lupov2(s1)<<" "<<lupov1(s2)<<"."<<lupov2(s2)<<" "<<lupov1(s3)<<"."<<lupov2(s3)<<" "<<lupov1(s4)<<"."<<lupov2(s4)<<endl;
        return 0;
    }
}
