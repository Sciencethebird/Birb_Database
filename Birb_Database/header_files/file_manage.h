//
//  file_manage.h
//  Birb Database
//
//  Created by Sciencethebird on 2018/7/9.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#ifndef file_manage_h
#define file_manage_h
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/// Load data from txt file to vector
void load_database(vector<birb*> &database){
    ifstream file ("Birb_Data.txt");
    
    if(!file)
        std::cout << "No Data to Load!" << endl;
    
    string buffer;
    while(getline(file,buffer)){
        if(buffer[0] == '*')
            continue;
        if(buffer[0] == '-'){
            string data_type = buffer.substr(2, 4);
            if(data_type == "name" ){
                string name = buffer.substr(8);
                birb *New = new birb(name);
                database.push_back(New);
            }
        }
    }
    ///file.close();
    ///we don't need this cuz destructor will close the file automatically
}

/// Print database.txt on console
void show_txt(){
    string buffer;
    ifstream file ("Birb_data.txt");
    std::cout << "\n";
    while(getline(file , buffer))
        std::cout <<"\t"<< buffer << std::endl;
}

/// Save vector to database.txt
void save_all(vector<birb*> const s){
    ofstream file("Birb_Data.txt", ios::trunc);
    if(!file){
        cerr << "File Fails to Open!\n";
        exit(1);
    }
    size_t sz = s.size();
    file << "********** Birb Database **********\n";
    for(int i = 0; i < sz; i++){
        file << "- name:\t" << s[i]->getName();
        file << "\n***********************************\n";
    }
    
    for(int i = 0; i < sz; i++)
        delete s[i];
    
    std::cout << "Database Saved!"<< std::endl;
}

#endif /* file_manage_h */
