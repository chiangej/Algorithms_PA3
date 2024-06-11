//
// Created by 蔣 ‘sssssss on 2024/6/11.
//

#include <queue>
#include "cyclebreaker.h"
using namespace std

#include "Graph.h"

// 構造函數
Graph::Graph(int vertices, bool directed) {
    this->vertices = vertices;
    this->directed = directed;
    adjList.resize(vertices);
}

// 添加邊
void Graph::addEdge(int v, int w, int weight) {
    adjList[v].emplace_back(w, weight);
    if (!directed) {
        adjList[w].emplace_back(v, weight);
    }
}

// 打印圖
void Graph::printGraph() const {
    for (int v = 0; v < vertices; ++v) {
        std::cout << "節點 " << v << " 的鄰接節點: ";
        for (const auto& x : adjList[v]) {
            std::cout << "(節點: " << x.first << ", 權重: " << x.second << ") ";
        }
        std::cout << std::endl;
    }
}

int Graph::find(std::vector<int>& parent, int i) const {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void Graph::unionSets(std::vector<int>& parent, std::vector<int>& rank, int x, int y) const {
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

void Graph::primMST() const {
    // 儲存每個頂點的最小邊權重
    vector<int> key(vertices, numeric_limits<int>::max());
    // 儲存節點是否包含在 MST 中
    vector<bool> inMST(vertices, false);
    // 儲存父節點
    vector<int> parent(vertices, -1);
    // 優先隊列： (鍵值, 頂點)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    // 儲存生成的 MST
    std::vector<std::pair<int, int>> mst;

    // 從頂點 0 開始
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto neighbor = adjList[u].begin(); neighbor != adjList[u].end(); ++neighbor) {
            int v = neighbor->first;
            int weight = neighbor->second;
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }

    }

    for (int i = 1; i < vertices; ++i) {
        mst.push_back({parent[i], i});
    }

    std::cout << "以下是 Prim 算法計算的 MST:" << std::endl;
    for (const auto& [u, v] : mst) {
        for (const auto& [adj, weight] : adjList[u]) {
            if (adj == v) {
                std::cout << u << " -- " << v << " == " << weight << std::endl;
                break;
            }
        }
    }
}
