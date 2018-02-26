//
//  OOP Assignment 1.h
//  OOP Assignment 1
//
//  Created by Eric Chua on 23/02/2018.
//  Copyright © 2018 Eric Chua. All rights reserved.
//

#ifndef OOP_Assignment_1_h
#define OOP_Assignment_1_h
#define SIZE 1000
#include <iostream>
#include <fstream>

using namespace std;

class Gate{
private:
    string Gname;
    string Gtype;
    int Ginput;
    int Goutput;
    
protected:
    int GateCount = 0;
    Gate *GateList[SIZE];
    
public:
    Gate(){
    
        
        
    }
    
    Gate(string type, string name, unsigned in_max, unsigned out_max){
        
        Gtype = type;
        Gname = name;
        Ginput = in_max;
        Goutput = out_max;
        
    }
    void init_gate(string params[]);
    int GateVolume(){
        return GateCount;
    }
    void ListGate(Gate *g){
        if(GateCount < SIZE){
            GateList[GateCount] = g;
            GateCount ++;
        }
            
        cout << GateList[GateCount] << endl;
        

    }
    
    
    
};

#endif /* OOP_Assignment_1_h */

