#include <iostream>
#include <set>
#include <map>

#include "d_state.h"

int main(){
  map<string, string>  s;

/*
("MD", "Salisbury");
("NY", "New York City");
("CA", "LA");
("AZ", "Douglas");
("MI", "Deluth");


*/

  s["MD"] = "Salisbury";
  s["NY"] = "New York City";
  s["CA"] = "LA";
  s["AZ"] = "Douglas";
  s["MI"] = "Deluth";

  string state;

  std::cout << "Enter a state: " << std::endl;
  std::cin >> state;


  map<string, string>::iterator iter;

  iter = s.find(state);
  if(iter != s.end()){
      std::cout << iter->second << std::endl;
  }else{
      std::cout << "State not found" << std::endl;
  }

}
