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
        pq.pop();
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
    if (destination < 0 || destination >= static_cast<int>(distances.size())) {
        cerr << "Error: Destination index out of bounds." << endl;
        return path;
    }
    if (destination >= static_cast<int>(previous.size())) {
        cerr << "Error: Previous array does not contain the destination index." << endl;
        return path;
    }
     if (distances[destination] == INF) {
        cout << "Destination is unreachable." << endl;
        return path;
    }
    if (previous[destination] == -1 && destination != 0)
        return path;

    for (int at = destination; at != -1; at = previous[at]) {
        if (at >= static_cast<int>(previous.size())) {
            cerr << "Error: Out-of-bounds access in previous array!" << endl;
            return {}; 
        }
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    if (v.empty()) {
        cerr << "Error: Path is empty. No valid path to destination.\n";
        return;
    }
    if (total > static_cast<int>(v.size())) {
        cerr << "Error: Invalid total count. Adjusting to vector size.\n";
        total = v.size();
    }
    for (int i=0; i < static_cast<int>(v.size()); ++i) {
        cout << v[i] << " ";
    }
    cout << "\nTotal cost is " << total << endl;
}