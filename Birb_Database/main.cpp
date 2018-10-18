//
//  main.cpp
//  Birb Database
//
//  Created by Sciencethebird on 2018/7/8.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Birb_class.hpp"
#include "main_functions.h"
#include "file_manage.h"


int main() {
    
    std::vector <birb*> database;
    std::string command;
    
    load_database(database);  /// load .txt to vector
    
    std::cout << "Wellcome to Birb Database!" << std::endl;
    std::cout << ">> ";
    
    while(getline(cin,command)){
        
        if(command == "test"){
            std::cout << "Hello World!";
            goto next_in;
        }
        if(command == "sz"){    /// show number of data and vector capacity
            std::cout << database.size() << " birb data in database" << std::endl;
            std::cout << "vector capacity = " << database.capacity() << std::endl;
            goto next_in;
        }
        if(command == "nw"){    /// input a new data
            string buffer;
            
            std::cout << "\nEnter name: ";
            getline(std::cin, buffer);
            if(buffer.length()){
                birb *New = new birb(buffer);
                database.push_back(New);
            }
            goto next_in;
        }
        if(command == "dlt"){   /// delete a data by index
            
            int database_size = (int)database.size();
            
            if(database_size == 0){
                std::cout << "Nothing in Database!" << std::endl;
                goto next_in;
            }
            
            std::cout << "\n" <<database;
            
            /*int idx;
             std::cout << "\nEnter a index to delete: ";
             std::cin >>idx;*/
            
            std::string in; /// use string instead of int cuz if you accidentally type in bunch of characters the program won't end.
            std::cout << "\nEnter a index to delete: ";
            getline(std::cin,in);
            //std::cin.ignore();
            
            try{                                        /// exception handling.
                stoi(in);                               /// stoi fails when you enter non-number stuff.
            }catch(const std::invalid_argument& ia){    /// the stuff inside () is needed, 'cus
                /// invalid_argument throw a class out
                std::cout << "\nINVALID INPUT!\n";      /// do these when stoi fails
                std::cout << ia.what() << std::endl;
                goto next_in;
            }
            
            int idx = stoi(in);
            if(idx > 0 && idx <= database_size){
                delete database[idx - 1];
                database.erase(database.cbegin() + idx - 1);
            }else{
                std::cout << "\nINVALID INPUT\n";
            }
            
            goto next_in;
        }
        if(command == "ls"){    /// show database
            int sz = (int)database.size();
            if(sz == 0)
                std::cout << "Nothing in database!" << std:: endl;
            else{
                std::cout <<"\n"<< database;
            }
            goto next_in;
        }
        if(command == "st"){    /// show birb_data.txt
            show_txt();
            goto next_in;
        }
        if(command == "help"){  /// show all command
            list_commands();
            goto next_in;
        }
        if(command == "ext"){   /// exit database and save vector to txt file
            save_all(database);
            vector<birb*>().swap(database);   /// free vector memory
            break;
        }
        else{
            std::cout <<"command not found!"<< std::endl;
            goto next_in;
        }
    next_in:
        std::cout << "\n>> ";
    }
    return 0;
}

