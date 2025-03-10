#include "dijkstras.h"


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distance(G.numVertices, INF);
    distance[source] = 0;

    previous.resize(n, -1); 

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(Node(source, 0));

    vector<bool> visited(n, false);

    while (!pq.empty()) {
        Node current = pq.top();
        int u = current.vertex;
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (const Edge& neighbor : G[u]) {
            int v = neighbor.dst;
            int weight = neighbor.weight;
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push(Node(v, distance[v]));
            }
        }
    }
    return distance;

}


vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    if (previous[destination] == -1)
        return path;
    for (int at = destination; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    cout << "Shortest distance to destination: " << distances[destination] << endl;
    return path;
}

void print_path(const vector<int>& v, int total) {
    for (int i=0; i < total; ++i) {
        cout << v[i] << " ";
    }
}