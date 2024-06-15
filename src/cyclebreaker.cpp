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

void Graph::unionSets(vector<int>& parent, vector<int>& rank, int x, int y) const {
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
void Graph::deleteEdge(int src, int dest) {
    auto& edges = adjList[src];
    edges.remove_if([dest](const pair<int, int>& edge) {
        return edge.first == dest;
    });
}
void Graph::deleteEdge2(int src, int dest) {
    auto& edges = adjList2[src];
    edges.remove_if([dest](const pair<int, int>& edge) {
        return edge.first == dest;
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
            unionSets(parent, rank, x, y);
        } else {
            deleteEdge(next_edge.src,next_edge.dest);
            DelelteEdge.push_back(next_edge);
            weights = weights + next_edge.weight;
        }
    }
    adjList2 = adjList;
    weights2 = weights;
    tempEdge = DelelteEdge;
}

void Graph::AddEdge() {

    sort(DelelteEdge.begin(), DelelteEdge.end(), compareEdgeDescending);

    for (auto it = DelelteEdge.begin(); it != DelelteEdge.end();) {
        if (it->weight > 0) {
            adjList[it->src].emplace_back(it->dest, it->weight);

            if (isCyclic()) {
                deleteEdge(it->src, it->dest);
                ++it;

            } else {
                weights -= it->weight;
                it = DelelteEdge.erase(it);
            }

        } else {
            ++it;
        }
    }
}
void Graph::AddEdge2() {

    sort(tempEdge.begin(), tempEdge.end(), [](const Edge& a, const Edge& b) {
        if (a.weight == b.weight) {
            if (a.src == b.src) {
                return a.dest > b.dest;
            }
            return a.src < b.src;
        }
        return a.weight > b.weight;
    });

    for (auto it = tempEdge.begin(); it != tempEdge.end();) {
        if (it->weight > 0) {
            adjList2[it->src].emplace_back(it->dest, it->weight);

            if (isCyclic2()) {
                deleteEdge2(it->src, it->dest);
                ++it;

            } else {
                weights2 -= it->weight;
                it = tempEdge.erase(it);
            }

        } else {
            ++it;
        }
    }
    if (weights2 < weights){
        DelelteEdge = tempEdge;
        weights = weights2;
    }
}
bool Graph::DFS2(int v,vector<Color>& colors) const {
    colors[v] = Color::GRAY;

    for (const auto& neighbor : adjList2[v]) {
        int neighborVertex = neighbor.first;
        if (colors[neighborVertex] == Color::GRAY) {
            return true;
        }
        if (colors[neighborVertex] == Color::WHITE && DFS2(neighborVertex, colors)) {
            return true;
        }
    }
    colors[v] = Color::BLACK;
    return false;
}

bool Graph::isCyclic2() const {
    vector<Color> colors(vertices, Color::WHITE);

    for (int i = 0; i < vertices; ++i) {
        if (colors[i] == Color::WHITE && DFS2(i, colors) ) {
            return true;
        }
    }
    return false;
}

bool Graph::DFS(int v,vector<Color>& colors) const {
    colors[v] = Color::GRAY;

    for (const auto& neighbor : adjList[v]) {
        int neighborVertex = neighbor.first;
        if (colors[neighborVertex] == Color::GRAY) {
            return true;
        }
        if (colors[neighborVertex] == Color::WHITE && DFS(neighborVertex, colors)) {
            return true;
        }
    }
    colors[v] = Color::BLACK;
    return false;
}

bool Graph::isCyclic() const {
    vector<Color> colors(vertices, Color::WHITE);

    for (int i = 0; i < vertices; ++i) {
        if (colors[i] == Color::WHITE && DFS(i, colors) ) {
            return true;
        }
    }
    return false;
}


void Graph::PrintEdge(const string &output) {
    ofstream fout(output);
    fout << weights << '\n';
    if(!DelelteEdge.empty()){
            for (const auto &edge: DelelteEdge) {
                fout << edge.src << " " << edge.dest << " " << edge.weight << " " << endl;
            }
    };

}
