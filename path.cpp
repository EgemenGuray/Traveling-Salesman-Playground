//
//  path.cpp
//  tsp
//
//  Created by Egemen Ihsan Guray on 12/17/18.
//  Copyright © 2018 Egemen Ihsan Guray. All rights reserved.
//

#include "path.hpp"


Path::Path(){}

void Path::add(City * c){
    for(int i = 0; i < all_cities.size(); i++){
        // add other to new city
        c->add(all_cities.at(i));
    }
    
    for(int i = 0; i < all_cities.size(); i++){
        // add new city to others
        all_cities.at(i)->add(c);
    }
    //add new city to graph
    all_cities.emplace_back(c);
}


void Path::add(double x_pos, double y_pos, std::string name){
    City* c = new City{x_pos, y_pos, name}; 
    for(int i = 0; i < all_cities.size(); i++){
        // add other to new city
        c->add(all_cities.at(i));
    }
    
    for(int i = 0; i < all_cities.size(); i++){
        // add new city to others
        all_cities.at(i)->add(c);
    }
    //add new city to graph
    all_cities.emplace_back(c);
}

void Path::print_pahts(){
    for(int i = 0; i < all_cities.size(); i++){
        // print for all
        all_cities.at(i)->print_cities();
    }
}

Path::~Path(){
    while(!all_cities.empty()){
        City * temp = all_cities.at(all_cities.size()-1);
        all_cities.pop_back();
        delete temp;
    }
}

double Path::enum_soln(){
    return 0.0;
}

double Path::tsm_soln(){
    double total_dist = 0.0;
    int i = rand() % all_cities.size();
    City* cur_city = all_cities.at(i);
    cur_city->setVisited(true);
    std::cout << cur_city->getName();
    std::pair<City*, double> retval = cur_city->getClosestUnvisited();
    while(retval.first != nullptr){
        std::cout << "---" << retval.second << "---->" << retval.first->getName();
        total_dist += retval.second;
        retval = retval.first->getClosestUnvisited();
    }
    if(retval.first == nullptr){
        if(retval.second < 0){
            std::cout << "->DEAD END" << std::endl;
            return -1.0;
        }else{
            std::cout << " TRAVELED ALL TOTAL DISTANCE: " << total_dist <<  std::endl;
        }
        
    }
    return total_dist;
}
