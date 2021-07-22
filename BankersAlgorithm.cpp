/*
    Author: Alam Khan
    AUST CSE 40th Batch

*/
#include<bits/stdc++.h>
using namespace std;
#define pb     push_back

const int sz = 109;
int a[sz][sz],b[sz][sz],c[sz];
string str,str2;
int main()
{
    int i,n,t,k,j,x=0,y=0,m;
    cout<<"Enter the no. of processes: ";
    cin>>n;
    cout<<"Enter the no. of resources: ";
    cin>>m;
    for(i=0; i<n; i++){
        cout<<"Process "<<i+1<<endl;
        for(j=0; j<m; j++){
            cout<<"Maximum value for resource "<<j+1<<": ";
            cin>>a[i][j];
        }
        for(j=0; j<m; j++){
            cout<<"Aintocated from resource "<<j+1<<": ";
            cin>>b[i][j];
            c[j]+= b[i][j];
        }
    }
    for(i=0; i<m; i++){
        cout<<"Enter total value of resource "<<i+1<<": ";
        cin>>x;
        c[i]  =x-c[i];
    }

    function<bool (int)> newa_jabe = [&](int i){
        for(j=0;j<m;j++){
            if(c[j]<a[i][j]-b[i][j])
                return 0;
        }
        return 1;
    };

    function <void (int)> add_kori  =[&] (int i){
        for(j=0;j<m;j++){
            c[j]+= b[i][j];
        }
    };
    set<int> s;
    vector<int> val;
    while(1){
        bool f =0;
        for(i=0;i<m;i++)
            cout<<i<<" =  "<<c[i]<<endl;
        for(i=0; i<n; i++){
            if(s.find(i)!=s.end())
                continue;
            if(newa_jabe(i)){
                add_kori(i);
                f = 1;
                s.insert(i);
                val.pb(i+1);
                break;
            }
        }
        if(!f){

            if(val.size()!=n)
                cout<<"The System is not in safe state"<<endl;
            else{
                cout<<"The System is currently in safe state and < ";
                for(i=0; i<val.size(); i++)
                    cout<<"P"<<val[i]<<" ";
                cout<<" > is the safe sequence."<<endl;
            }
            return  0;
        }
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


/*

7
3
7
5
6
1
1
1
5
8
5
2
3
3
9
2
8
3
0
5
8
8
6
2
2
0
14
4
5
3
1
0
4
6
3
1
2
1
2
9
2
1
1
1
20
19
16

*/
