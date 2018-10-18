//
//  main_functions.h
//  Birb Database
//
//  Created by Sciencethebird on 2018/7/9.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#ifndef main_functions_h
#define main_functions_h
#include <iostream>
#include <fstream>
#include <string>
#include "Birb_class.hpp"
using namespace std;

void list_commands(){
    string buffer;
    ifstream file("Command_List.txt");
    if(!file){
        cerr<< "Cammand_List.txt fails to open~\n";
    }
    while(getline(file, buffer)){
        std::cout << buffer << std::endl;
    }
}

ostream& operator<<(ostream & stream, const vector<birb*> &in){
    size_t sz = in.size();
    for(size_t i = 0; i< sz; i++){
        stream << "\t" << i+1 << ". " << in[i]->getName() << std::endl;
    }
    return stream;
}


#endif /* main_functions_h */
