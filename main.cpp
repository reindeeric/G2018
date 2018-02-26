/*
* Assignment #1
*
* Objective:
*   This program takes a combinational logicl circuit with
*   arbitrary levels of gates or components as input.
*   It can parse the connections and compute the outputs of
*   the combinational logic circuit.
*
* Student Info:
*   (name) , (ID) , (programme, e.g. 3E/EC/ET)
**************************************************************/
#include "OOP Assignment 1.h"
using namespace std;
void process_vector(string input, string params[]);

//Inheritance
class NAND : public Gate{
public:
    NAND(string name, int in_max, int out_max) : Gate("NAND", name, in_max, out_max) {
    }
};

class NOR : public Gate{
public:
    NOR(string name, int in_max, int out_max) : Gate("NAND", name, in_max, out_max) {
    }
};

class AND : public Gate{
public:
    AND(string name, int in_max, int out_max) : Gate("NAND", name, in_max, out_max) {
    }
};

class OR : public Gate{
public:
    OR(string name, int in_max, int out_max) : Gate("NAND", name, in_max, out_max) {
    }
};

class NOT : public Gate{
public:
    NOT(string name, int in_max, int out_max) : Gate("NAND", name, in_max, out_max) {
    }
};

class XOR : public Gate{
public:
    XOR(string name, int in_max, int out_max) : Gate("NAND", name, in_max, out_max) {
    }
};

void process_vector(string input, string params[]){
    
    string mines = " ,\n\r";
    string token;
    string::size_type head, tail = 0;
    int count = 0;
    
    for (;;){
        
        head = input.find_first_not_of(mines, tail);
        tail = input.find_first_of(mines, head);
        if(head == string::npos && tail == string::npos) break;
        params[count] = input.substr(head, tail-head);
        count++;

    }
}


void Gate :: init_gate(string params[]) {
   
    if (params[1] == "NAND"){
        NAND *g = new NAND(params[0], atoi(params[2].c_str()), atoi(params[3].c_str()));
        ListGate(g);
    }
    else
        if (params[1] == "NOR"){
            NOR *g = new NOR(params[0], atoi(params[2].c_str()), atoi(params[3].c_str()));
           ListGate(g);
           
        }
        else
            if (params[1] == "AND"){
                AND *g = new AND(params[0], atoi(params[2].c_str()), atoi(params[3].c_str()));
               ListGate(g);
            }
            else
                if (params[1] == "OR"){
                    OR *g = new OR(params[0], atoi(params[2].c_str()), atoi(params[3].c_str()));
                ListGate(g);
                }
                else
                    if (params[1] == "XOR"){
                        XOR *g = new XOR(params[0], atoi(params[2].c_str()), atoi(params[3].c_str()));
                    ListGate(g);
                    }
                else
                    if(params[1] == "NOT"){
                        NOT *g = new NOT(params[0], atoi(params[2].c_str()), atoi(params[3].c_str()));
                        ListGate(g);
                    }
                    else{
                        cout << "gate <" << params[1] << "> not supported" << endl;
                    }
   
}


int main(){
    
    string input;
    string params[SIZE];
    fstream fp1, fp2;
    Gate gate;
    int cnt = 0;
    fp1.open("gates.csv");
    
    if(fp1.is_open()){
            
        cout << "Main reading gates..." << endl;
        
        while (fp1.peek() != EOF) {
            
            getline(fp1, input);
            
            if (cnt > 0) {  // skip the header in the file
                
                process_vector(input, params);
                gate.init_gate(params);
                
            }
            cnt++;
        }
        
    }
   
}
