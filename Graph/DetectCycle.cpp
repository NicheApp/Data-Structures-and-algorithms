#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
bool iscyclic(vector<vector<int>> &graph ,vector<bool> &visited,stack<int> &st,int parent)
{
int s= st.top();
visited[s]=true;

for(auto it: graph[s])
{
if(it!=parent)
{
if(visited[it])
{return true;}
else
{
    st.push(it);
    if(iscyclic(graph,visited,st,s))
    return true;
}

}
}
st.pop();
return false;

}
 
void createedge(vector<vector<int>> &graph , int u, int v)
{
graph[u].push_back(v);
graph[v].push_back(u);
 
}
void solve(){
int n,m;
cin>>n>>m;
//n++;
vector<vector<int>> graph(n);
vector<int> vt;
for(int i=0;i<m;i++)
{
int a, b;
cin>>a>>b;
 
createedge(graph,a,b);
 
}
vector<bool> visited(n,false);
int count=0;
for(int i=0;i<n;i++)
{
if(!visited[i])
{
   
    stack<int> st;
    st.push(i);
 
   if(iscyclic(graph,visited,st,i))
     {cout<<"CYCLIC\n"; return;}
 
}
}

cout<<"NOT CYCLIC";
 
return ;
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(NULL);
 
solve();
 
return 0;
}
