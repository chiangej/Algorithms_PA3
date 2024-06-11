//
// Created by 蔣 ‘sssssss on 2024/6/11.
//

#include "Graph.h"
#include "cyclebreaker.h"



Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjList.resize(vertices);
}

// 添加邊無向圖
void Graph::addEdge_u(int v, int w) {
    adjList[v].push_back(w); // 添加 w 到 v 的列表
    adjList[w].push_back(v); // 若是無向圖，則添加 v 到 w 的列表
}

void Graph::addEdge_d(int v, int w) {
    adjList[v].push_back(w); // 添加 w 到 v 的列表
}

// 打印圖

void Graph::printGraph() {
    for (int v = 0; v < vertices; ++v) {
        std::cout << "節點 " << v << " 的鄰接節點: ";
        for (auto x : adjList[v]) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}