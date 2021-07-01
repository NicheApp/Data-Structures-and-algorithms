    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    void addEdge(vector<vector<pair<int,int>>> &graph, int u , int v,int w){
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
    }

    void primsalgo(vector<vector<pair<int,int>>> &graph,int n,int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<int> key(n,INT_MAX);
    vector<int> setmst(n,false);
    vector<int> parent(n,-1);

    pq.push({0,src});
    while(!pq.empty())
    {
    int u =pq.top().second;
    pq.pop();
    if(setmst[u]==true)
    continue;
    setmst[u]=true;

    for(auto it: graph[u])
    {
    int v= it.first;
    int w= it.second;

    if(setmst[v]==false && key[v]>w)
    {

    key[v]=w;
    pq.push({key[v],v});
    parent[v]=u;

    }


    }

    }


    for(int i=0;i<n;i++){

    cout<<parent[i]<<" - "<<i<<endl;


    }



    }

    int main()
    {
    int n=9;
    vector<vector<pair<int,int>>> adj(n);

        addEdge(adj, 0, 1, 4);
        addEdge(adj, 0, 7, 8);
        addEdge(adj, 1, 2, 8);
        addEdge(adj, 1, 7, 11);
        addEdge(adj, 2, 3, 7);
        addEdge(adj, 2, 8, 2);
        addEdge(adj, 2, 5, 4);
        addEdge(adj, 3, 4, 9);
        addEdge(adj, 3, 5, 14);
        addEdge(adj, 4, 5, 10);
        addEdge(adj, 5, 6, 2);
        addEdge(adj, 6, 7, 1);
        addEdge(adj, 6, 8, 6);
        addEdge(adj, 7, 8, 7);


    primsalgo(adj,n,0);

    return 0;
    }
