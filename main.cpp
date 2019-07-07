//
//  main.cpp
//  tsp
//
//  Created by Egemen Ihsan Guray on 12/17/18.
//  Copyright © 2018 Egemen Ihsan Guray. All rights reserved.
//

#include <iostream>
#include "path.hpp"
#include <sstream>



int main(int argc, const char * argv[]) {
    Path *p = new Path;
    std::string name;
    double x_Pos;
    double y_Pos;
    std::string command;
    while(std::getline(std::cin, command )){
        if(command == "") break;
        std::stringstream ss(command);
        std::string name_s;
        std::string x_s;
        std::string y_s;
        ss >> name >> x_Pos >> y_Pos;
        p->add(x_Pos, y_Pos, name);
       //std::cout << name << " " << x_Pos << " " << y_Pos << std::endl;
        
        
    }
    
    /*
    City* A = new City{36266.67, 62550.00, "A"};
    City* B = new City{32383.34, 59666.67, "B"};
    City* C = new City{33783.34, 60600.00, "C"};
     p->add(A);
     p->add(B);
     p->add(C);
    */
    
    
    
    
    p->print_pahts();
    p->tsm_soln();
    p->print_pahts();
    p->tsm_soln();
    delete p;
    
}
