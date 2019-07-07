//
//  city.cpp
//  tsp
//
//  Created by Egemen Ihsan Guray on 12/17/18.
//  Copyright © 2018 Egemen Ihsan Guray. All rights reserved.
//

#include "city.hpp"

City::City(double x, double y, std::string name): x_pos{x}, y_pos{y}, name{name}, visited{false}{}

double City::getXpos(){
    return x_pos;
}

double City::getYpos(){
    return y_pos;
}

std::string City::getName(){
    return name;
}

double City::calcDistance(City *other){
    double delta_x = other->getXpos() - this->getXpos();
    double delta_y = other->getYpos() - this->getYpos();
    
    return sqrt(delta_x * delta_x + delta_y * delta_y);
}

bool City::getVisited(){
    return visited;
}

void City::setVisited(bool visit){
    visited = visit;
}

void City::add(City *other){
    if(this != other){
        double distance = calcDistance(other);
        
        if(cities.empty() || cities.at(cities.size()-1).second < distance){
            std::pair<City *, double> c_pair;
            c_pair.first = other;
            c_pair.second = distance;
            cities.emplace_back(c_pair);
        }else{
            for(int i = 0; i < cities.size(); i++){
                if(distance <= cities.at(i).second){
                    std::pair<City *, double> c_pair;
                    c_pair.first = other;
                    c_pair.second = distance;
                    cities.insert(cities.begin()+i, c_pair);
                    break;
                }
            }
        }
    }
    
    
}

std::pair<City*, double> City::getClosestUnvisited(){
    std::pair<City *, double> retval;
    
    retval.first = nullptr;
    retval.second = 0.0;
    
    if(!cities.empty()){
        for(int i = 0; i < cities.size(); i++){
            if(cities.at(i).first->getVisited() == false){
                retval.first = cities.at(i).first;
                retval.second = cities.at(i).second;
                // set visited
                cities.at(i).first->setVisited(true);
                return retval; 
            }
        }
    }else{
        // dead end
        retval.second = -1.0;
        return retval;
    }
    // all visited
    return retval;
    
}

void City::print_cities(){
    std::cout << this << std::endl;
    std::cout << "--------------------------------------------------" << std::endl << std::endl;
    
    for(int i = 0; i < cities.size(); i++){
        std::cout << cities.at(i).first << ", Distance: " << cities.at(i).second << std::endl;
    }
    std::cout << std::endl;
}


std::ostream& operator<<(std::ostream &out, City *c){
    out << "City Name: " << c->getName() << ", Loc: [X: " << c->getXpos() << ", Y: " << c->getYpos() << "], Visited: " << c->getVisited();
    return out;
}
