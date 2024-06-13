//
// Created by 蔣 ‘sssssss on 2024/6/11.
//

#include <queue>
#include "cyclebreaker.h"
#include <algorithm>
using namespace std;

Graph::Graph(int vertices, bool directed) {
    this->vertices = vertices;
    this->directed = directed;
    adjList.resize(vertices);
}

void Graph::addEdge(int v, int w, int weight) {
    adjList[v].emplace_back(w, weight);
    if (!directed) {
        adjList[w].emplace_back(v, weight);
    }
    edges.emplace_back(v, w, weight, false);
}

int Graph::find(vector<int>& parent, int i) const {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void Graph::unionSets(vector<int>& parent, std::vector<int>& rank, int x, int y) const {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

bool compareEdgeDescending(const Edge& a, const Edge& b) {
    return a.weight > b.weight;
}
void Graph:: deleteEdge(int v, int w) {
    adjList[v].remove_if([w](const pair<int, int> &edge) {
        return edge.first == w;
    });
}

void Graph:: kruskalMST() {
    vector<Edge> result;
    sort(edges.begin(), edges.end(), compareEdgeDescending);

    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    for (int i = 0; i < vertices; ++i)
        parent[i] = i;

    int i = 0;
    while (i < edges.size()) {
        Edge next_edge = edges[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            unionSets(parent, rank, x, y);
        } else {
            deleteEdge(next_edge.src,next_edge.dest);
            DelelteEdge.push_back(next_edge);
            weights = weights + next_edge.weight;
        }
    }

}

void Graph::AddEdge(){
    sort(DelelteEdge.begin(), DelelteEdge.end(), compareEdgeDescending);
    for (auto node : DelelteEdge) {
        if (node.weight>0){
            adjList[node.src].emplace_back(node.dest, node.weight);
            weights -= node.weight;
            if ( isCyclic()){
                deleteEdge(node.src,node.dest);
                weights += node.weight;
            }
        }
    }
}

bool Graph::DFS(int v, vector<bool>& visited, vector<bool>& Gray) const {

    if (!visited[v]) {
        visited[v] = true;
        Gray[v] = true;

        for (auto neighbor : adjList[v]) {
            if (!visited[neighbor.first] && DFS(neighbor.first, visited, Gray)) {
                return true;
            } else if (Gray[neighbor.first]) {
                return true;
            }
        }
    }
    Gray[v] = false;
    return false;
}

bool Graph::isCyclic() const {
    vector<bool> visited(vertices, false);
    vector<bool> recStack(vertices, false);

    for (int i = 0; i < vertices; ++i) {
        if (DFS(i, visited, recStack)) {
            return true;
        }
    }
    return false;
}


void Graph::PrintEdge(const string &output) {
    ofstream fout(output + "k2");
    fout << weights << '\n';
    fout << isCyclic()<< '\n';
    if(!DelelteEdge.empty()){

            for (const auto &edge: DelelteEdge) {
                fout << edge.src << " " << edge.dest << " " << edge.weight << " " << endl;
            }

    }

}
