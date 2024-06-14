//
// Created by 蔣 ‘sssssss on 2024/6/11.
//
#include <iostream>
#include <fstream>
#include "cyclebreaker.h"
#include <vector>
#include <ctime>


#define ll long long
using namespace std;


void help_message()
{
    cout << "usage: ./mps <input_file> <output_file>" << endl;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        help_message();
        return 0;
    }


    //////////// read the input file /////////////

    string type;
    fstream fin(argv[1]);

    int VertexNum, EdgeNum;
    fin >> type;
    fin >> VertexNum;
    fin >> EdgeNum;

    bool d;
    if (type == "u") {
        d = false;
    } else {
        d = true;
    }
    Graph G(VertexNum, d);

    for (int i = 0; i < EdgeNum; i++) {
        int v, w, weight;
        fin >> v >> w >> weight;
        G.addEdge(v, w, weight);
    }

    G.kruskalMST();
    if(type.find("d") != string::npos){
        G.AddEdge();
        G.PrintEdge2(argv[2]);
    }else{
        G.PrintEdge(argv[2]);
    }

    return 0;
}