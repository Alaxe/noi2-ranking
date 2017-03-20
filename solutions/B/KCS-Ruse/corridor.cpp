#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>
#include<vector>
#include<stdio.h>
using namespace std;

int n,w,h,i,x,y,x1,y1,y2,j=0,l,otg=0,minn=1100000001;
int key2=0,i2;
int m[100000][3];
int k[10000001];
int main() {
    //freopen("2.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>w>>h>>n;
    cin>>x>>y;
    x1=x;
    y1=y;
    y2=y;
    if(minn>x) minn=x;
    for(i=1; i<n; i++) {
        cin>>x>>y;
        if(minn>x) minn=x;
        if(x1==x) y2=y;
        else {
            m[j][0]=x1;
            if(y1>y2) {
                m[j][1]=y2;
                m[j][2]=y1;
            } else {
                m[j][1]=y1;
                m[j][2]=y2;
            }
            j++;
            x1=x;
            y1=y;
            y2=y;
        }
    }
    m[j][0]=x1;
    m[j][1]=y1;
    m[j][2]=y2;
    j++;
    /*for(i=0; i<j; i++) {
        cout<<m[i][0]<<" "<<m[i][1]<<" "<<m[i][2]<<endl;
    }
    cout<<endl;
    */
    for(i=1; i<j; i++) 
    {
        if(m[i-1][0]>m[i][0]) 
        {
        
            int key=0;
            
            while(key==0) 
            {
                //cout<<"i-1 e po-golyamo"<<endl;
                if(m[i-1][0]>m[i][0]) 
                {
                    if(m[i-1][1]<=m[i][1]) 
                    {
                        if(m[i-1][2]>=m[i][2]) 
                        {
                            m[i][0]=m[i-1][0];
                            m[i][1]=m[i-1][1];
                            m[i][2]=m[i-1][2];
                            m[i-1][0]=0;
                            m[i-1][1]=0;
                            m[i-1][2]=0;
                        } else {
                            key=1;
                            m[i][1]=m[i-1][2];
                        }
                    } else {
                        if(m[i-1][2]>=m[i][2]) {
                            key=1;
                            m[i][2]=m[i-1][2];
                        }
                    }
                    if(key==0) i++;
                } else key=1;
            }

        } else {
            if(m[i-1][0]<m[i][0]) 
            {
                
                key2=0;
                int key=0;
                i2=i;
                while(key==0) 
                {
                    if(m[i-1][0]<m[i][0] && i-1>=0) 
                    {
                        //cout<<"i e po-golyamo"<<endl;
                        if(m[i][1]<=m[i-1][1]) 
                        {
                            if(m[i][2]>=m[i-1][2]) 
                            {
                                /*cout<<m[i-1][0]<<" "<<m[i-1][1]<<" "<<m[i-1][2]<<endl;
                                cout<<m[i][0]<<" "<<m[i][1]<<" "<<m[i][2]<<endl;*/
                                m[i-1][0]=m[i][0];
                                m[i-1][1]=m[i][1];
                                m[i-1][2]=m[i][2];
                                key2=1;
                                /*m[i][0]=0;
                                m[i][1]=0;
                                m[i][2]=0;*/
                                /*cout<<"dominate"<<endl;
                                cout<<i<<endl;*/
                            } 
                            else 
                            {
                                key=1;
                                m[i-1][1]=m[i][2];
                            }
                        } 
                        else 
                        {
                            if(m[i][2]>=m[i-1][2]) 
                            {
                                m[i-1][2]=m[i][1];
                            }
                            key=1;
                        }
                    if(key==0) i--;
                    
                    }
                    else key=1;
                }
                if(key2==1)
                {
                    for(i=i;i<i2;i++)
                    {
                        m[i][0]=0;
                        m[i][1]=0;
                        m[i][2]=0;
                    }
                }
            }
            
        }
    }
    /*for(i=0; i<j; i++) {
        cout<<m[i][0]<<" "<<m[i][1]<<" "<<m[i][2]<<endl;
    }
    cout<<endl;
    */
    for(i=0; i<j; i++) {
        otg+=(w-m[i][0])*(m[i][2]-m[i][1]);
    }
    cout<<otg<<endl;
    return 0;
}
/*

6 0 2
11 2 6
8 4 6
9 4 5
10 3 5
6 3 7
12 7 8
9 8 10

*/
