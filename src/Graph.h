//
// Created by 蔣 ‘sssssss on 2024/6/11.
//

#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H
#include <cstring>
#include "cyclebreaker.h"
#include <vector>
#include <list>



class Graph {

    public:
        Graph(int vertices);
        void addEdge_d(int v, int w);
        void addEdge_u(int v, int w);
        void printGraph();

    private:
        int vertices; // 節點數量
        std::vector<std::list<int>> adjList; // 鄰接表
    };
};


#endif //SRC_GRAPH_H
