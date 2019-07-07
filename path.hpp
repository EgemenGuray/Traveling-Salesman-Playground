//
//  path.hpp
//  tsp
//
//  Created by Egemen Ihsan Guray on 12/17/18.
//  Copyright © 2018 Egemen Ihsan Guray. All rights reserved.
//

#ifndef path_hpp
#define path_hpp

#include "city.hpp"

class Path{
    std::vector <City *> all_cities;
    
public:
    Path();
    void add(City *);
    void add(double x_pos, double y_pos, std::string name);
    ~Path();
    
    void print_pahts();
    
    double enum_soln();
    
    double tsm_soln();
    
};

#endif /* path_hpp */
