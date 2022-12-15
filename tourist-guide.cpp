#include <bits/stdc++.h>

using namespace std;

int widest_path(vector<vector<pair<int, int> > >& Graph,
                        int src, int target)
{
    // To keep track of widest distance
    vector<int> widest(Graph.size(), INT_MIN);
 
    // To get the path at the end of the algorithm
    vector<int> parent(Graph.size(), 0);
 
    // Use of Minimum Priority Queue to keep track minimum
    // widest distance vertex so far in the algorithm
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > >
        container;
 
    container.push(make_pair(0, src));
 
    widest[src] = INT_MAX;
 
    while (container.empty() == false) {
        pair<int, int> temp = container.top();
 
        int current_src = temp.second;
 
        container.pop();
 
        for (auto vertex : Graph[current_src]) {
 
            // Finding the widest distance to the vertex
            // using current_source vertex's widest distance
            // and its widest distance so far
            int distance = max(widest[vertex.second],
                               min(widest[current_src], vertex.first));
 
            // Relaxation of edge and adding into Priority Queue
            if (distance > widest[vertex.second]) {
 
                // Updating bottle-neck distance
                widest[vertex.second] = distance;
 
                // To keep track of parent
                parent[vertex.second] = current_src;
 
                // Adding the relaxed edge in the priority queue
                container.push(make_pair(distance, vertex.second));
            }
        }
    }
 
    return widest[target];
}

void solve() {
    int src, dest, passengers;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n);
    for(int i=0; i<m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        graph[u].push_back({c,v});
        graph[v].push_back({c,u});
    }
    cin >> src >> dest >> passengers;
    --src; --dest;
    int cost = widest_path(graph, src, dest);
    cout << (passengers + cost - 1) / cost << " trips\n";
}

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
}