#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <fstream>
#include <utility>
#include <vector>
using namespace std;

class DirectedGraph {
   public:
    DirectedGraph(fstream& f);
    void DFS(fstream& fout);
    void DFSVisit(int start, fstream& fout);
    void output(fstream& out);

   private:
    int vertex;
    int edge;
    int begin;
    int target;
    int time;
    vector<int>* adj;
    int* buffer;
};

#endif