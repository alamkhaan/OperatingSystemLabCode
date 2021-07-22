/*
    Author: Alam Khan
    AUST CSE 40th Batch

*/

#include<bits/stdc++.h>
using namespace std;
#define pb     push_back
#define inf     2e9
#define low     -2e9
const int sz = 3e5+9;
int a[sz],b[sz],c[sz],d[sz],res[sz],wait[sz];
string str,str2;
int main()
{
    int i,n,t,k,j,x=0,y=0,m;

    cout<<"Enter the no. of process: ";
    cin>>n;
    cout<<"Enter the arrival times: ";
    for(i=1;i<=n;i++){
        cin>>a[i];
        d[i] = a[i];
    }
    cout<<"Enter the cpu times: ";
    for(i=1;i<=n;i++){
        cin>>b[i];
        c[i] = b[i];
    }
    k =  0;
    c[0]  = inf;
    cout<<endl<<endl<<"Gantt Chart: ";
    bool khali  = 1;
    memset(res,-1,sizeof res);
    for(t=0;;){
        bool f = 0;
        int last  = k;
        for(i=1;i<=n;i++){
            if(c[i]!=0)
                f =  1;
        }
        if(!f)
            break;
        for(i=1;i<=n;i++){
            if(c[i]>0 && t>=a[i] && c[k]>c[i])
                k =  i;
        }

        if(k==0){
            khali  = 1;
            t++;
            continue;
        }
        if(khali){
            cout<<"<"<<t<<">";
            khali = 0;
        }
        if(k!=last && last!=0){
            cout<<" P"<<last<<" <"<<t<<">";
        }
        if(res[k]==-1)
            res[k] =  t-a[k];
        t++;
        c[k]--;
        wait[k]+= t-d[k]-1;
        d[k] =  t;
        if(c[k]==0){
            cout<<" P"<<k<<" <"<<t<<">";
            k  = 0;
        }
    }
    cout<<endl<<endl;
    double p =0,q=  0,r = 0;
    for(i=1;i<=n;i++){
        p+= res[i];
        q+= wait[i];
        r+= wait[i]+b[i];
    }
    cout<<"Average Response Time "<<fixed<<setprecision(5)<<p/(n*1.0)<<endl;
    cout<<"Average Waiting Time "<<fixed<<setprecision(5)<<q/(n*1.0)<<endl;
    cout<<"Average TurnAround Time "<<fixed<<setprecision(5)<<r/(n*1.0)<<endl;

    return 0;
}
/*
6
9 3 0 2 7 8
2 1 6 3 2 4
3
0 4 5
3 5 4
5
3 0 5 4 7
6 5 8 3 1
4
0 1 2 3
8 4 9 5
4
0 1 3 4
7 4 9 5
*/

