//Nikolas Wieneke
//Lab 10
//Dr. Lu


#include "d_graph.h" 
#include "d_util.h"

#include <iostream>
#include <fstream>
#include <set>
#include <queue>

int main()
{
    graph<string> graphs;

    std::ifstream graphB;

    graphB.open("graphB.dat",ios::in);

    if(graphB.is_open())
    {
        
        int count;
        graphB>>count;
        
        string v1;
        string v2;
        
        int weight;

        while(count !=0)
        {
            graphB>>v1;    
            graphs.insertVertex(v1);
            count--;
        }
        graphB>>count;

        while(count !=0)
        {
            graphB>>v1>>v2>>weight;    
            graphs.insertEdge(v1,v2,weight);
            count--;
        }
    }
    graphB.close();

        string input;
        std::cout<<"Hello! What Vertext Do You Want To Search For? (A - F)";
        std::cin>>input;
        
        set<string> userBFS = bfs(graphs,input);
        writeContainer(userBFS.begin(),userBFS.end()," ");
        std::cout<<std::endl;

        list<string> userDFS;
        
        dfs(graphs,userDFS);
        writeContainer(userDFS.begin(), userDFS.end(), " ");
        std::cout<<std::endl;


}

