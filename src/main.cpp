#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char* argv[]) {
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2], ios::out);

    DirectedGraph DG(fin);
    DG.DFS(fout);
}