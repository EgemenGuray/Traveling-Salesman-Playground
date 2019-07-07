//
//  city.hpp
//  tsp
//
//  Created by Egemen Ihsan Guray on 12/17/18.
//  Copyright © 2018 Egemen Ihsan Guray. All rights reserved.
//

#ifndef city_hpp
#define city_hpp

#include <string>
#include <vector>
#include <iostream>
#include <math.h>

class City{
private:
    std::vector<std::pair<City *, double>> cities;
    double x_pos;
    double y_pos;
    bool visited;
    std::string name;
    
public:
    City(double x, double y, std::string name);
    
    double getXpos();
    
    double getYpos();
    
    std::string getName();
    
    double calcDistance(City *other);
    
    bool getVisited();
    
    void setVisited(bool visit = true);
    
    void add(City *other);
    
    void print_cities();
    
    std::pair <City*, double> getClosestUnvisited(); 
    
};

std::ostream& operator<<(std::ostream &out, City *c);

#endif /* city_hpp */
