#include<bits/stdc++.h>
using namespace std;
const int sz = 1000;
int a[sz],b[sz];

struct Process
{
    int arrivalTime;
    int cpuTime;
    int id;
    int waitingTime;
    int turnaroundTime;
    Process()
    {
        ;
    }
    Process(int x,int y,int z)
    {
        arrivalTime = x;
        cpuTime = y;
        id = z;
    }
};
bool cmp(Process x,Process y)
{
    if(x.arrivalTime==y.arrivalTime)
        return x.id<y.id;
    return x.arrivalTime<y.arrivalTime;
}
bool cmp2(Process x,Process y)
{
    return x.id<y.id;

}
int main()
{
    int i,n,t,k,j,x=0,y=0,m;
    cout<<"Enter the number of process :";
    cin>>n;
    cout<<"Enter the CPU times"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the arrival times"<<endl;
    for(i=0;i<n;i++)
        cin>>b[i];
    vector<Process> v;
    for(i=0;i<n;i++)
    {
        v.push_back(Process(b[i],a[i],i+1));
    }
    int totalWaiting = 0;
    int totalTurnaround  =0;

    sort(v.begin(),v.end(),cmp);
    int prevCpu = 0;
    x = 0;
    cout<<endl<<"Gantt Chart:"<<endl;
    for(i=0;i<n;i++)
    {
        v[i].waitingTime  = max(prevCpu - v[i].arrivalTime,0);
        v[i].turnaroundTime =  v[i].waitingTime+ v[i].cpuTime;
        totalWaiting += v[i].waitingTime;
        totalTurnaround+= v[i].turnaroundTime;
        if(prevCpu<v[i].arrivalTime)
        {
            x = v[i].arrivalTime - prevCpu;
            cout<<"Time "<<v[i].arrivalTime<<" to "<<v[i].arrivalTime+v[i].cpuTime<<" , Process "<<v[i].id<<" running"<<endl;
        }
        else
        {
            x=  0;
            cout<<"Time "<<prevCpu<<" to "<<prevCpu+v[i].cpuTime<<" , Process "<<v[i].id<<" running"<<endl;
        }
        prevCpu += v[i].cpuTime+x;


    }

    sort(v.begin(),v.end(),cmp2);
    cout<<endl<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Process "<<v[i].id<<": Waiting Time: "<<v[i].waitingTime<<" Turnaround Time: "<<v[i].turnaroundTime<<endl;
    }
    cout<<endl<<endl;
    cout<<"Average Waiting time: "<<fixed<<setprecision(6)<<totalWaiting/(n*1.0)<<endl;
    cout<<"Average Turnaround time: "<<fixed<<setprecision(6)<<totalTurnaround/(n*1.0)<<endl;
    return 0;
}

