#include <iostream>
#include <set>
#include <map>

#include "d_state.h"

int main(){
  set<stateCity>  s;

  stateCity salisbury("MD", "Salisbury");
  stateCity newyorkcity("NY", "New York City");
  stateCity la("CA", "LA");
  stateCity douglas("AZ", "Douglas");
  stateCity deluth("MI", "Deluth");

  s.insert(salisbury);
  s.insert(newyorkcity);
  s.insert(la);
  s.insert(douglas);
  s.insert(deluth);
  

  string state;

  std::cout << "Enter a state: " << std::endl;
  std::cin >> state;
  
  bool not_found = true;

  set<stateCity>::iterator iter;
  for(iter = s.begin(); iter != s.end(); ++iter){
    if(iter->stateName == state){
      std::cout << *iter << std::endl;
      not_found = false;
    }
  }

  if(not_found){
    std::cout << "City not found" << std::endl;
  }

}
