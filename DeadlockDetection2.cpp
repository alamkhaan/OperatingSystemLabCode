#include<bits/stdc++.h>
using namespace std;
int n,adj[1000][1000];
struct vertex
{
    int color;
    int par;
    string val;
};
vertex node[1000];

int c2=-1;
void answer(int c1)
{
    if(c1==c2)
        return;
    answer(node[c1].par);
    cout<<node[c1].val<<" ";
}
void dfs_visit(int u)
{
    node[u].color = 1;
    for(int i=1;i<=n;i++){
        if(adj[u][i]==1){
            if(node[i].color==0){
                node[i].color = 1;
                node[i].par = u;
                dfs_visit(i);
            }
            else if(node[i].color==1){
                c2  = i;
                cout<<"Deadlock Detected Among nodes: "<<node[i].val<<" ";
                answer(u);
                cout<<endl;
            }
        }
    }
    node[u].color = 2;
}

void dfs()
{
    for(int i=1;i<=n;i++){
        node[i].color = 0;
        node[i].par = -1;
    }
    for(int i=1;i<=n;i++){
        if(node[i].color==0)
            dfs_visit(i);
    }
    if(c2==-1)
        cout<<"No cycle"<<endl;

}
int main()
{
    int m,i,j,x,y;
    string p,q;
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"Node Names : ";
    map<string,int> data;
    for(int i=1;i<=n;i++){
        cin>>p;
        data[p]  = i;
        node[i].val = p;
    }
    cout<<"Enter no. of edges : ";
    cin>>m;
    cout<<"Enter Edges :"<<endl;
    while(m--){
        cin>>p>>q;
        adj[data[p]][data[q]] = 1;
    }
    dfs();
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
*/
