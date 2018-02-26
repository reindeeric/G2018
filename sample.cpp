/**************************************************************
 * UEEN1043 Object-Oriented Concepts and Programming Techniques
 *
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
#include "sample.h"

using namespace std;

//-------------------------------------------
// definition of gates and components
//-------------------------------------------
class NAND : public Gate {
    public:
        NAND(string name, int in_max, int out_max) : Gate("NAND", name, in_max, out_max) {}

        void compute() {
            ... 
        }
};

...

void init_gate(string params[]) {

    if (params[1] == "NAND")
        g = new NAND(params[0], atoi(params[2].c_str()), atoi(params[3].c_str()));
    else
        ...
    else
        cout << "gate <" << params[1] << "> not supported" << endl;
}

void init_ext_input(string params[]) {
    ...
}

void init_connection(string params[]) {
    ...
}

//-------------------------------------------
// main function
//-------------------------------------------
int main()
{
    //
    // read definition of gates, external inputs, and connection set up
    //
    fp1.open("gates.csv", ios::in);

    if(fp1.is_open()) {
        cout << "Main reading gates..." << endl;
        cnt = 0;

        while (fp1.peek() != EOF) {
            getline(fp1, input);

            if (cnt > 0) {  // skip the header in the file
                n = process_vector(input);
                init_gate(list_gates, params);
            }
            cnt++;
        }
    }

    fp2.open("ext_inputs.csv", ios::in);

    if(fp2.is_open()) {
        cout << "Main reading ext_inputs..." << endl;
        cnt = 0;

        while (fp2.peek() != EOF) {
            getline(fp2, input);

            if (cnt > 0) {  // skip the header in the file
                n = process_vector(input);
                init_ext_input(list_gates, params);
            }
            cnt++;
        }
    }

    if(fp1.is_open()) {
        fp1.seekg(0, ios::beg);

        cout << "Main reading connections..." << endl;
        cnt = 0;

        while (fp1.peek() != EOF) {
            getline(fp1, input);

            if (cnt > 0) {  // skip the header in the file
                n = process_vector(input);
                init_connection(list_gates, params, n);
            }
            cnt++;
        }
    }

    cout << "Main processing computation..." << endl;
    
    ...

    return 0;
}

