#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>graph[100],vis(100,0),parent(100,-1);
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    stack<int>st;
    st.push(1);
    while(st.size())
    {
        int top=st.top();
        vis[top]=1;
        bool z=1;
        for(auto &x:graph[top])
        {
            if(vis[x]==0)
            {
                st.push(x);
                parent[x]=top;
                z=0;
                break;
            }
            else if(x!=parent[top] and top!=parent[x])
            {
                cout<<"The graph has a cycle"<<endl;
                return 0;
            }
        }
        if(z)
            st.pop();
    }
    cout<<"The graph has no cycle"<<endl;
}
