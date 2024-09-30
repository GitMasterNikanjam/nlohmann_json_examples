// For compile: g++ -o json_test json_test.cpp 
// For run: ./json_test_2

// ###############################################
// Include libraries:

#include <iostream>             
#include <fstream>              // For file operations
#include "../json.hpp"          // nlohmann/json library.

using json = nlohmann::json;

using namespace std;

// ################################################
// Global variables

// Create a JSON object
string message = R"({"MOT":"M", "MOD":1, \
"VEL_D": 3, "TRQ_D": 10})";

// ################################################
// main:

int main() {

    json j = json::parse(message);
    // Serialize to string
    std::string serialized = j.dump();
    std::cout << "Serialized JSON: " << message << std::endl;
    std::cout << "Serialized JSON: " << serialized << std::endl;

    cout<<  j["MOT"]<< endl;

    auto items = j.items();
    if(j["MOT"] == "M")
    {
        if(j["RUN"] == "ON")
        {

        }
        int mode = j["MOD"];
        switch(mode)
        {
            case 1:
                cout<< "mode 1"<< endl;
            break;
            case 2:
                cout<< "mode 2"<< endl;
            break;
        }
    }

    return 0;
}

// ############################################################