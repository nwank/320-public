#include <iostream>
#include "d_graph.h"
#include "d_util.h"
#include <fstream>
#include <string>
#include <set>

int main()
{
    //Create a graph
    graph<char> A;
    //hold the values of verts and edges
    int vertex, edge;
    

    //for opening file
    ifstream graphA;

    //openfile
    graphA.open("graphA.dat");

    //build the graph;
    graphA >> vertex;
    for(int i = 0; i < vertex; i++)
    {
        char temp;
        graphA >> temp;

        A.insertVertex(temp);
    }

    graphA >> edge;

    for(int i = 0; i < edge; i++)
    {
        char one, two;
        int w;
        graphA >> one >> two >> w;
        A.insertEdge(one, two, w);
    }

    //insert edges and vertex
    A.insertEdge('F', 'D', 1);
    A.eraseVertex('B');
    A.eraseEdge('A', 'D');

    //take a vertex from the user
    char usr;
    std::cout << "Please Insert a Vortex" << std::endl;
    std::cin >> usr;

    //create a set to hold the neighbors
    set<char> aVert;

    aVert = A.getNeighbors(usr);

    //Go through the set
    set<char>::iterator it = aVert.begin();
    
    
    std::cout << "Neighbors of " << usr << ": ";
    
    
    while(it != aVert.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    //insert edges and vertex G
    A.insertVertex('G');
    A.insertEdge('G', 'C', 1);
    A.insertEdge('G', 'F', 1);
    A.insertEdge('D', 'G', 1);

    //display graph
    std::cout << A;

    return 0;
}