//
// Created by 蔣 ‘sssssss on 2024/6/11.
//

#ifndef SRC_CYCLEBREAKER_H
#define SRC_CYCLEBREAKER_H
#include <cstring>
#include <iostream>
#include <fstream>
#include "cyclebreaker.h"
#include <vector>
#include <list>

using namespace std;

class cyclebreaker {

};

class Graph {
public:
    Graph(int vertices, bool directed);
    void addEdge(int v, int w, int weight);
    void printGraph() const;
    void kruskalMST() const;
    void primMST() const;


private:
    int vertices;
    bool directed;
    std::vector<list<pair<int, int>>> adjList;
    int find(vector<int>& parent, int i) const;
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) const;

};



#endif //SRC_CYCLEBREAKER_H
