
#include <iostream>
#include "d_pqueue.h"
#include "preqrec.h"
#include <stdlib.h>
#include <cstdlib> //for random numbers
#include <string>


int main()
{
    
   // srand(time(0));
    
    miniPQ<procReqRec> mpq;
    
    std::string process[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    
    procReqRec records[10];
    
    for(int i = 0; i < 10; i++)
    {
        std::string nm = "Priority " + process[i];
        records[i].setName(nm);
        records[i].setPriority(rand() % 40); //random integers in the range from 0 to 39.
    }
    
    for(int j = 0; j < 10; j++)
    {
        std::cout << mpq.top();
        mpq.pop(); //Output and delete records from the priority queue until it is empty.
    }

    return 0;
    
}