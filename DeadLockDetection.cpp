/*
    Author: Alam Khan
    AUST CSE 40th Batch

*/

#include<bits/stdc++.h>
using namespace std;
#define pb     push_back
int main()
{
    int i,n,t,k,j,x=0,y=0,m;
    cout<<"Enter number of nodes : ";
    cin>>n;
    vector<int> adj[n+2];
    int vis[n+2],arr[n+2];
    bool f = 0;
    string b[n+2],tmp1,tmp2;
    cout<<"Node Names : ";
    map<string,int> ma;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        ma[b[i]]  = i;
    }

    cout<<"Enter number of edges : ";
    cin>>m;
    cout<<"Enter Edges :"<<endl;
    for(i=1;i<=m;i++)
    {
        cin>>tmp1>>tmp2;
        adj[ma[tmp1]].pb(ma[tmp2]);
    }
    vector<vector<string> > ans;
    function<void (int)> traverse = [&](int c)
    {
        vis[c]  = 1;
        for (auto u : adj[c]) {
            if (vis[u]==0)
            {
                arr[u]  = c;
                traverse(u);
            }
            else if (vis[u]==1)
            {
                int ind = ans.size();
                ans.emplace_back();
                x = c;
                while(x!=u)
                {
                    ans[ind].pb(b[x]);
                    x = arr[x];
                }
                ans[ind].pb(b[u]);
                reverse(ans[ind].begin(),ans[ind].end());
            }
        }
        vis[c]  = 2;

    };
    memset(vis,0,sizeof vis);
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            arr[i]  = i;
            traverse(i);
        }
    }
    if(ans.size()==0)
    {
        cout<<"Congrats!!!No Cycle exist"<<endl;
    }
    else
    {
        cout<<"Total cycle = "<<ans.size()<<endl;
        for(i=0;i<ans.size();i++)
        {
            cout<<"Deadlock Detected Among nodes: ";
            for(j=0;j<ans[i].size();j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
/*
13
R A C S D T B E F U V W G
13
R A
A S
C S
W F
F S
D S
U D
G U
V G
E V
D T
B T
T E

3
A B C
4
A B
B A
B C
C A

7
A B C D E F G
8
A B
B D
D A
D E
E B
F C
C G
G F

9
1 2 3 4 5 6 7 8 9
11
1 2
1 4
2 3
6 2
3 6
4 5
5 1
5 8
7 4
8 7
8 9


4
1 2 3 4
5
1 2
2 4
4 3
2 3
3 1


*/
