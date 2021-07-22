#include<bits/stdc++.h>
using namespace std;
struct Process
{
    int id,rem,arr;
    Process()
    {
        ;
    }
    Process(int x,int y,int z)
    {
        id  = x;
        rem = y;
        arr = z;
    }
};
int brust[1000];
int wait[1000],res[1000],ar[1000];
bool cmp(Process x,Process y)
{
    if(x.rem==y.rem)
    {
        if(x.arr==y.arr)
            return x.id<y.id;
        return x.arr<y.arr;
    }
    return x.rem<y.rem;
}
bool cmp2(Process x,Process y)
{
    if(x.arr==y.arr)
    {
        return x.rem<y.rem;
    }
    return x.arr<y.arr;
}
int main()
{
    int n,m,i;
    cout<<"Enter the number of Process: ";
    cin>>n;
    cout<<"Enter the arrival times: ";
    for(i=0;i<n;i++)
        cin>>ar[i];
    cout<<"Enter the brust times: ";
    for(i=0;i<n;i++)
        cin>>brust[i];
    vector<Process> p(n);
    for(i=0;i<n;i++)
    {
        res[i+1]  = -1;
        p[i].id = i+1;
        p[i].rem  = brust[i];
        p[i].arr = ar[i];
    }
    sort(p.begin(),p.end(),cmp2);
    int cur = 0,t = 0;
    int lagbe=INT_MAX;
    i = 0;
    vector<Process> s;
    cout<<"Gantt Chart"<<endl;
    while(1)
    {
        while(i<n && t==p[i].arr)
        {
            s.push_back(p[i]);
            i++;
        }
        sort(s.begin(),s.end(),cmp);
        if(cur==0 && s.size()!=0)
        {
            cur = s[0].id;
            lagbe = s[0].rem;
            wait[cur]+= t-s[0].arr;
            s.erase(s.begin());
            if(res[cur]==-1)
            {
                res[cur]  = t-ar[cur-1];
            }

            cout<<"|"<<t<<"| P"<<cur<<" ";

        }
        if(cur!=0)
        {
            if(s.size()!=0)
            {
                if(s[0].rem<lagbe)
                {
                    s.push_back(Process(cur,lagbe,t));
                    cout<<"|"<<t<<"|";
                    cur  = s[0].id;
                    lagbe  =s[0].rem;
                    wait[cur]+= t-s[0].arr;
                    s.erase(s.begin());
                    if(res[cur]==-1)
                    {
                        res[cur]  = t-ar[cur-1];
                    }
                    cout<<"|"<<t<<"| P"<<cur<<" ";
                }
            }
        }
        if(cur!=0)
        {
            lagbe--;
            t++;
            if(lagbe==0)
            {
                cout<<"|"<<t<<"|";
                cur = 0;
                if(i==n)
                {
                    if(s.empty())
                        break;
                    else
                    {
                        cur  = s[0].id;
                        lagbe = s[0].rem;
                        wait[cur]+= t-s[0].arr;
                        s.erase(s.begin());
                        if(res[cur]==-1)
                        {
                            res[cur]  = t-ar[cur-1];
                        }
                        cout<<"|"<<t<<"| P"<<cur<<" ";
                    }
                }

            }
            continue;
        }


        t++;

    }
    cout<<endl;
    double x  =0.0;
    for(i=1;i<=n;i++)
    {
        x+= res[i];
    }
    cout<<"Average Response Time "<<fixed<<setprecision(2)<<x/(n*1.0)<<endl;
    x = 0.0;
    for(i=1;i<=n;i++)
    {
        x+= wait[i];
    }
    cout<<"Average Waiting Time "<<fixed<<setprecision(2)<<x/(n*1.0)<<endl;
    x = 0.0;
    for(i=1;i<=n;i++)
    {
        x+= wait[i]+brust[i-1];
    }
    cout<<"Average TurnAround Time "<<fixed<<setprecision(2)<<x/(n*1.0)<<endl;

}

