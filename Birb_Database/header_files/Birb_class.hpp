//
//  Birb_class.hpp
//  
//
//  Created by Sciencethebird on 2018/7/8.
//

#ifndef Birb_class_hpp
#define Birb_class_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class birb{

private:
    std::string name;
    std::string personality;
    float weight;
public:
    birb(){
    
    }
    birb(std::string nm){
        name = nm;
    }
    birb(const birb &lala)///copy constructor
    : name(lala.name)
    {
        std::cout<< lala.name <<" class copied" << std::endl;
    }
    ~birb(){
        std::cout << name << " data destroyed" << std::endl;
    }
    
    void writeName(std::string temp);
    void writePersonality(std::string temp);
    void writeWeight();
    std::string getName();
    std::string getPersonality();
    float getWeight();
};

void birb::writeName(std::string temp){
    name = temp;
}
void birb::writePersonality(std::string temp){
    personality = temp;
}
std::string birb::getName(){
    return name;
}
std::string birb::getPersonality(){
    return personality;
}
float birb::getWeight(){
    return weight;
}

#endif /* Test_hpp */
