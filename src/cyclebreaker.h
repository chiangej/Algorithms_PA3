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

class Edge {
public:
    int src, dest, weight;
    bool count;
    Edge(int s, int d, int w,bool count) : src(s), dest(d), weight(w),count(count) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
public:
    Graph(int vertices, bool directed);
    void addEdge(int v, int w, int weight);
    vector<Edge> edges;
    void printGraph() const;
    void kruskalMST();
    vector<Edge> DelelteEdge;
    vector<string> outputLines;
    int weights = 0;
    void AddEdge();
    void PrintEdge(const string &output);


private:
    int vertices;
    bool directed;
    vector<list<pair<int, int>>> adjList;
    int find(vector<int>& parent, int i) const;
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) const;

    bool isCyclic() const;

    bool DFS(int v, vector<bool> &visited, vector<bool> &Gray) const;

    void PrintEdge();

    void deleteEdge(int v, int w);


};



#endif //SRC_CYCLEBREAKER_H
