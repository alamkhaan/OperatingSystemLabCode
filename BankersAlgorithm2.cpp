#include<bits/stdc++.h>
using namespace std;
struct Resource
{
    int maximum;
    int allocated;
};

struct Process
{
    vector<Resource> r;
    Process(int m){
        r.resize(m+1);
    }

};
int main()
{
    int n,m,i,j;
    cout<<"Enter the no. of processes: ";
    cin>>n;
    cout<<"Enter the no. of resources: ";
    cin>>m;
    vector<Process> p;
    p.push_back(Process(m));
    for(i=1; i<=n; i++){
        p.push_back(Process(m));
        cout<<"Process "<<i<<endl;
        for(j=1; j<=m; j++){
            cout<<"Maximum value for resource "<<j<<": ";
            cin>>p[i].r[j].maximum;
        }
        for(j=1; j<=m; j++){
            cout<<"Allocated from resource "<<j<<": ";
            cin>>p[i].r[j].allocated;
        }
    }
    vector<int> totalValue;
    totalValue.resize(m+1);
    for(i=1; i<=m; i++){
        cout<<"Enter total value of resource "<<i<<": ";
        cin>>totalValue[i];
    }
    for( i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            totalValue[i]-= p[j].r[i].allocated;
    vector<bool> flag(n+1,0);
    queue<int> q;
    for(int cnt=1; cnt<=n; cnt++){
        for(i=1; i<=n; i++)
        {
            if(flag[i]==1)
                continue;
            bool f = 0;
            for(j=1; j<=m; j++){
                if(totalValue[j]<p[i].r[j].maximum-p[i].r[j].allocated){
                    f =1;
                    break;
                }
            }
            if(f)
                continue;
            flag[i]  =1;
            q.push(i);
            for(j=1; j<=m; j++){
                totalValue[j]+= p[i].r[j].allocated;
            }
            break;

        }
    }
    if(q.size()!=n){
        cout<<"The System is not in safe state"<<endl;
        return 0;
    }
    cout<<"The System is currently in safe state and < ";
    while(!q.empty()){
        cout<<"P"<<q.front()<<" ";
        q.pop();
    }
    cout<<" > is the safe sequence."<<endl;

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
