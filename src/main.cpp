//
// Created by 蔣 ‘sssssss on 2024/6/11.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include "cyclebreaker.h"
#include "cyclebreaker.cpp"
#include "Graph.h"
#include "Graph.cpp"
#include <vector>
#include <ctime>


#define ll long long
using namespace std;


void help_message()
{
    cout << "usage: ./mps <input_file> <output_file>" << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        help_message();
        return 0;
    }


    //////////// read the input file /////////////

    char type[200];

    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2], ios::out);
    int  VertexNum,EdgeNum;
    fin >> type;
    fin >> VertexNum;
    fin >> EdgeNum;
    cout<<type<<endl;
    int junk, num;
    Graph G(VertexNum, type);

    for (int i = 0; i<EdgeNum;i++){
        int v, w, weight;
        fin >> v >> w >> weight;
        G.addEdge(v, w, weight);

    }


//    //////////// the breaking part////////////////
//    maxPlanarSubset maxPlanarSubset;
//    maxPlanarSubset.initializeMatrix(stoi(buffer),stoi(buffer));
//    int number = maxPlanarSubset.maxPlanarSubsett(chord,data,buffer);
//    cout<< "#num:" << number << " " << endl;
//    fout << number << '\n';
//    maxPlanarSubset.M2.resize(stoi(buffer));
//    maxPlanarSubset.findChord(0,stoi(buffer)-1);
//
//    //////////// write the output file ///////////
//    for(int i = 0;i<stoi(buffer);i++){
//        if (maxPlanarSubset.M2[i])
//            fout << i << " " << maxPlanarSubset.bigdata[i] << '\n';
//    }
//
//    cout<<"file end"<<endl;
//    fin.close();
//    fout.close();
//    return 0;
}

