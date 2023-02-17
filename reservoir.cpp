#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cfloat>
#include "reservoir.h"

double get_east_storage(std::string input_date) {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << 
std::endl;
        exit(1); 
    }
    std::string line;
    std::getline(fin, line);

    std::string date; 
    double eastSt,  eastEl,  westSt, westEl;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
    
        fin.ignore(INT_MAX, '\n');
        if (input_date == date) {
            return eastSt;
        }
    }
    fin.close();
    return -1;    
}

double get_min_east() {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << 
std::endl;
        exit(1); 
    }
    std::string line;
    std::getline(fin, line);
    std::string date; 
    double eastSt,  eastEl,  westSt, westEl;
    double min = 100000; 
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n');
        if(eastSt < min){
            min = eastSt; 
        }
    }
    return min; 
    fin.close();    
}

double get_max_east() {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << 
std::endl;
        exit(1); 
    }
    std::string line;
    std::getline(fin, line);
    std::string date; 
    double eastSt,  eastEl,  westSt, westEl;
    double max = -1000000000; 
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n');
        if(eastSt > max){
            max = eastSt; 
        }
    }
    return max; 
    fin.close();    
}

std::string compare_basins(std::string input_date) {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << 
std::endl;
        exit(1); 
    }
    std::string line;
    std::getline(fin, line);

    std::string date; 
    double eastSt, eastEl,  westSt, westEl, east_storage, 
west_storage;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n');
        if (input_date == date) {
            if(eastSt == westSt) {
                std::cout << input_date << " "; 
                return "Equal";
            }
            if(eastSt < westSt) {
                std::cout << input_date << " "; 
                return "West";
            } else {
                std::cout << input_date << " "; 
                return "East";                
            }
        }
    
    }
    fin.close();  
}
