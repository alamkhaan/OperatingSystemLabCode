#include<bits/stdc++.h>
using namespace std;

const int sz = 1009;
int a[sz],s[sz],b[sz],e[sz];
int ans[sz];
int wait[sz];
struct Process
{
    int arrivalTime;
    int cpuTime;
    int id;
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

int main()
{
    int i,n,t,k,j,x=0,y=0,m,q;
    cout<<"Enter the number of process :";
    cin>>n;
    cout<<"Enter the CPU times"<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]  =a[i];
    }

    cout<<"Enter the arrival times"<<endl;
    for(i=1;i<=n;i++)
        cin>>b[i];
    vector<Process> v;
    cout<<"Enter time Quantum: ";
    cin>>q;
    for(i=1;i<=n;i++)
    {
        v.push_back(Process(b[i],a[i],i));
    }

    sort(v.begin(),v.end(),cmp);
    queue<Process> pq;
    pq.push(v[0]);
    int cur  = v[0].arrivalTime;
    i  =1;
    cout<<endl<<"Gantt chart"<<endl;
    while(!pq.empty())
    {
        Process temp  =pq.front();
        pq.pop();
        ans[temp.id]+= cur-temp.arrivalTime;
        x =  min(q,temp.cpuTime);
        temp.cpuTime-= x;
        cout<<"Time "<<cur<<" to "<<cur+x<<" , Process "<<temp.id<<" running"<<endl;
        cur+= x;
        while(i<n && v[i].arrivalTime<=cur)
        {
            pq.push(v[i]);
            i++;

        }
        if(temp.cpuTime==0)
        {
            e[temp.id] =  cur;
        }
        else
        {
            temp.arrivalTime  = cur;
            pq.push(temp);
        }




    }
    cout<<endl;
    int w;
    w = t = 0;
    for(i=1;i<=n;i++)
    {
        cout<<"Process no "<<i<<" ends at "<<e[i]<<endl;
    }
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"Waiting time for process "<<i<<" = "<<ans[i]<<endl;
        w+= ans[i];
    }
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"Turnaround time for process "<<i<<" = "<<ans[i]+s[i]<<endl;
        t+= ans[i]+s[i];
    }
    cout<<endl;
    cout<<"Average Waiting time  = "<<fixed<<setprecision(5)<<(w*1.0)/(n*1.0)<<endl;
    cout<<"Average Turnaround time  = "<<fixed<<setprecision(5)<<(t*1.0)/(n*1.0)<<endl;

    return 0;
}

