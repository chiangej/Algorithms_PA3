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
    bool isCyclic() const;
    bool isCyclic2() const;
    int weights = 0;
    int weights2 ;
    Graph(int vertices, bool directed);
    void addEdge(int v, int w, int weight);
    vector<Edge> edges;
    vector<Edge> DelelteEdge;
    vector<Edge> tempEdge;
    vector<Edge> DelelteEdge2;
    void kruskalMST();
    vector<string> outputLines;
    void AddEdge();
    void PrintEdge(const string &output);
    void AddEdge2();
    void PrintEdge2(const string &output);


private:
    enum class Color {
        WHITE,
        GRAY,
        BLACK
    };
    int vertices;
    bool directed;
    vector<list<pair<int, int>>> adjList;
    vector<list<pair<int, int>>> adjList2;
    int find(vector<int>& parent, int i) const;
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) const;
    void deleteEdge(int v, int w);
    bool DFS(int v, vector<Color> &colors) const;
    bool DFS2(int v, vector<Color> &colors) const;


    void deleteEdge2(int src, int dest);
};



#endif //SRC_CYCLEBREAKER_H
