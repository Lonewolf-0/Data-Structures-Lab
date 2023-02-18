#include <bits/stdc++.h>
using namespace std;

int main()
{
    

    int v,e,a,b;
    cout<<"\nHow many vertices are there in the graph ";
    cin>>v;
    cout<<"\nHow many edges are there in the graph ";
    cin>>e;
    vector<int> adjlist[v];
    for(int i=1;i<=e;i++)
    {
        cout<<"\nEnter the end points of edge "<<i;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<" : ";
        for(int j=0;j<adjlist[i].size();j++)
            cout<<adjlist[i][j]<<", ";
        cout<<endl;
    }

    

    return 0;
}