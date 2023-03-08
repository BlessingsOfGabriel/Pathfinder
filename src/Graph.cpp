#include "Graph.h"
#include <iostream>

using namespace std;

DirectedGraph::DirectedGraph(fstream& f) {
    f >> vertex >> edge;
    f >> begin >> target;
    adj = new vector<int>[vertex];
    buffer = new int[target + 1];
    buffer[0] = begin;
    for (int i = 0; i < edge; i++) {
        int u, v;
        f >> u >> v;
        adj[u].push_back(v);
    }
    time = 0;
}

void DirectedGraph::DFS(fstream& fout) {
    DFSVisit(begin, fout);
}

void DirectedGraph::DFSVisit(int start, fstream& fout) {
    time = time + 1;
    if (time == target) {
        for (int i = 0; i < adj[start].size(); i++) {
            if (adj[start][i] == begin) {
                buffer[time] = begin;
                output(fout);
            }
        }
    } else if (time < target) {
        for (int i = adj[start].size() - 1; i >= 0; i--) {
            buffer[time] = adj[start][i];
            DFSVisit(adj[start][i], fout);
            time = time - 1;
        }
    }
}

void DirectedGraph::output(fstream& fout) {
    for (int i = 0; i <= target; i++) {
        fout << buffer[i] << ' ';
    }
    fout << endl;
}