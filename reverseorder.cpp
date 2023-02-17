#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cfloat>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2) {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << 
std::endl;
        exit(1); 
    }
    std::string line;
    std::getline(fin, line);
    std::string date; 
    double eastSt, eastEl, westSt, westEl;
    double west_array[365]; 
    std::string date_array[365]; 
    int counter = 0; 
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n');
        if(date >= date1 && date <= date2) {
            west_array[counter] = westEl;
            date_array[counter] = date;
            counter++;
        }
    }
    for(int i = counter-1; i >= 0; i--) {
        std::cout << date_array[i] << " " << west_array[i] << 
"\n";      
    }

    fin.close();
}
