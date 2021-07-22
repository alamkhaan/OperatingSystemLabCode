/*
    Author: Alam Khan
    AUST CSE 40th Batch

*/

#include<bits/stdc++.h>
using namespace std;
#define pb     push_back
#define inf     2e9
#define low     -2e9

void FirstFit(vector<int> a,vector<int> b)
{
    int n  = a.size();
    int m  =b.size();
    int cnt =0;
    bool f =0;
    cout<<endl<<endl<<endl<<"First Fit"<<endl<<endl<<endl;
    for(int i=0;i<m;i++)
    {
        int k  =-1;
        for(int j=0;j<n;j++)
        {
            if(b[i]<=a[j])
            {
                k  =j;
                break;
            }
        }
        cout<<"Memory Request = "<<b[i]<<" - ";
        if(k==-1 || f)
        {
            cout<<"Not Possible"<<endl;
            f =1;
        }
        else
        {
            a[k]-= b[i];
            cnt++;
            for(int j=0;j<n;j++)
                cout<<a[j]<<" ";
            cout<<endl;
        }
    }
    if(cnt!=m)
    {
        cnt = 0;
        for(int i=0;i<n;i++)
            cnt+= a[i];
        cout<<"External Fragmentation  = "<<cnt<<endl;
    }
    else cout<<"No External Fragmentation"<<endl;
}


void WorstFit(vector<int> a,vector<int> b)
{
    int n  = a.size();
    int m  =b.size();
    int cnt =0;
    bool f =0;
    cout<<endl<<endl<<endl<<"Worst Fit"<<endl<<endl<<endl;
    for(int i=0;i<m;i++)
    {
        int k  =-1;
        int x = -1;
        for(int j=0;j<n;j++)
        {
            if(x<a[j])
            {
                x = a[j];
                k = j;
            }
        }
        cout<<"Memory Request = "<<b[i]<<" - ";
        if(b[i]>x || f)
        {
            cout<<"Not Possible"<<endl;
            f = 1;
        }
        else
        {
            a[k]-= b[i];
            cnt++;
            for(int j=0;j<n;j++)
                cout<<a[j]<<" ";
            cout<<endl;
        }
    }
    if(cnt!=m)
    {
        cnt = 0;
        for(int i=0;i<n;i++)
            cnt+= a[i];
        cout<<"External Fragmentation  = "<<cnt<<endl;
    }
    else cout<<"No External Fragmentation"<<endl;
}


void BestFit(vector<int> a,vector<int> b)
{
    int n  = a.size();
    int m  =b.size();
    int cnt =0;
    bool f =0;
    cout<<endl<<endl<<endl<<"Best Fit"<<endl<<endl<<endl;
    for(int i=0;i<m;i++)
    {
        int k  =-1;
        int x = inf;
        for(int j=0;j<n;j++)
        {
            if(a[j]>=b[i] && a[j]<x)
            {
                x = a[j];
                k = j;
            }
        }
        cout<<"Memory Request = "<<b[i]<<" - ";
        if(k==-1 || f)
        {
            cout<<"Not Possible"<<endl;
            f = 1;
        }
        else
        {
            a[k]-= b[i];
            cnt++;
            for(int j=0;j<n;j++)
                cout<<a[j]<<" ";
            cout<<endl;
        }
    }
    if(cnt!=m)
    {
        cnt = 0;
        for(int i=0;i<n;i++)
            cnt+= a[i];
        cout<<"External Fragmentation  = "<<cnt<<endl;
    }
    else cout<<"No External Fragmentation"<<endl;
}
int main()
{
    int i,n,t,k,j,x=0,y=0,m;
    cout<<"Enter Number of Memory Holes : ";
    cin>>n;
    cout<<"Memory Holes : ";
    vector<int> a(n);
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter Number of Memory Requests : ";
    cin>>m;
    cout<<"Memory Requests : ";
    vector<int> b(m);
    for(i=0;i<m;i++)
        cin>>b[i];

    FirstFit(a,b);
    BestFit(a,b);
    WorstFit(a,b);

    return 0;
}
/*
5
50 200 70 115 15
10
100 10 35 15 23 6 25 55 88 40


5
100 500 200 300 600
4
212 417 112 426
*/

