#include<bits/stdc++.h>
using namespace std;


bool check(vector<vector<int>> &all,vector<vector<int>> &maxi,vector<int> &total,int n,int m,vector<int> & ans)
{
    vector<bool> flag(n+1,0);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            total[i]-= all[j][i];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(flag[j]==1)
                continue;
            bool f = 0;
            for(int k=1;k<=m;k++)
            {
                if(total[k]<maxi[j][k]-all[j][k])
                {
                    f =1;
                    break;
                }
            }
            if(f)
                continue;
            flag[j]  =1;
            ans.push_back(j);
            for(int k=1;k<=m;k++)
            {
                total[k]+= all[j][k];
            }
            break;

        }
    }
    if(ans.size()==n)
        return 1;
    return 0;
}
int main()
{
    int n,m,i,j;
    cout<<"Enter the no. of processes: ";
    cin>>n;
    cout<<"Enter the no. of resources: ";
    cin>>m;
    vector<vector<int>> all(n+1,vector<int> (m+1,0));
    vector<vector<int>> maxi(n+1,vector<int> (m+1,0));
    vector<int> total(n+1,0);
    for(i=1;i<=n;i++)
    {
        cout<<"Process "<<i<<endl;
        for(j=1;j<=m;j++)
        {
            cout<<"Maximum value for resource "<<j<<": ";
            cin>>maxi[i][j];
        }
        for(j=1;j<=m;j++)
        {
            cout<<"Allocated from resource "<<j<<": ";
            cin>>all[i][j];
        }

    }
    for(i=1;i<=m;i++)
    {
        cout<<"Enter total value of resource "<<i<<": ";
        cin>>total[i];
    }
    vector<int> ans;
    if(check(all,maxi,total,n,m,ans))
    {
        cout<<"The System is currently in safe state and < ";
        for(i=0;i<ans.size();i++)
            cout<<"P"<<ans[i]<<" ";
        cout<<" > is the safe sequence."<<endl;
    }
    else
    {
        cout<<"The System is not in safe state"<<endl;
    }
    return 0;
}
/*
4
3
3
2
2
1
0
0
6
1
3
5
1
1
3
1
4
2
1
1
4
2
2
0
0
2
9
3
6
*/
