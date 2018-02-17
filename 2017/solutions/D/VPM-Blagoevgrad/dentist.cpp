 #include<bits/stdc++.h>
 using namespace std ;
 struct pacient
 {
     int s,v,e;
 };
 bool cmp(pacient a, pacient b)
 {
     if(a.s>b.s)return 0;
     return 1;
 }
 int main(){
     ios_base::sync_with_stdio(0);
     pacient a[722];
     int i=0;
     while(cin>>a[i].s>>a[i].v)
     {
         i++;
     }
     cin.clear();
     sort(a,a+i,cmp);

    a[0].e=a[0].s+a[0].v;
    for(int j=1;j<i;j++)
    {
       if(a[j-1].e>a[j].s)
       {
           a[j].e=a[j-1].e+a[j].v;
       }
       else
       {
         a[j].e=a[j].s+a[j].v;
       }
    }
cout<<a[i-1].e - a[i-1].s<<endl;
     return 0;
 }
/*
0 30
720 10
715 20
714 25
*/
/*
55 15
185 22
130 10
*/



