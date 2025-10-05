/**
 *
 * @file interrupts.cpp
 * @author Sasisekhar Govind
 *
 */

#include "interrupts.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;
    //vectors is a C++ std::vector of strings that contain the address of the ISR
    //delays  is a C++ std::vector of ints that contain the delays of each device
    //the index of these elemens is the device number, starting from 0
    auto [vectors, delays] = parse_args(argc, argv);
    std::ifstream input_file(argv[1]); //ifstream is used to read from files and it's part of the standard library

    std::string trace;      //!< string to store single line of trace file
    std::string execution;  //!< string to accumulate the execution output
    
    /******************ADD YOUR VARIABLES HERE*************************/
    int mode_bit = 1;       // when 1 = user mode, when 2 = kernel mode 
    int time_of_event = 0; 
   
    


    /******************************************************************/

    //parse each line of the input trace file
    while(std::getline(input_file, trace)) {
        execution = "";
        auto [activity, duration_intr] = parse_trace(trace); //parse_trace will return a tuple: ('CPU', 50)

        /******************ADD YOUR SIMULATION CODE HERE*************************/
        if (activity == "CPU") {
            if (mode_bit == 1)
            {
                mode_bit = 0;
            }
            execution += std::to_string(time_of_event) + ", " + std::to_string(duration_intr) + ", " + "CPU burst";
            
        }

        write_output(execution);
        /************************************************************************/

    }
    
    input_file.close();

    write_output(execution);

    return 0;
}
