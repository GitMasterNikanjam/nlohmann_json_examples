// For compile and build:
// mkdir -p ./bin && g++ -o ./bin/json_test json_test.cpp 

// For run: 
// ./bin/json_test

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
json j ;

// ################################################
// main:

int main() {

    // j["param1"] = "John";
    // j["param2"] = 30;
    // j["param33"] = 12.123;
    // j["param4"] = true;
    // j["param5"] = {1, 2, "3", false};
    j = json::parse(R"({"param1":1, "param2":2})");

    // j = 
    // {
    //     {"TYP", "MOTM"},
    //     {"VALUE", {1,2,3,\
    //     4,5,6,"HELLO", "NIKE"}}
    // };
    
    char txBuffer[1024];
    std::string s = j.dump();
    sprintf(txBuffer,"#%d#%s",(int)s.size(), s.c_str());

    std::cout << txBuffer<< std::endl;

    // Serialize to string
    std::string serialized = j.dump();
    std::cout << "Serialized JSON: " << serialized << std::endl;

    // Write to a file
    std::ofstream ofs("data.json");
    ofs << j.dump(4); // Pretty print with 4 spaces of indentation
    ofs.close();

    json loaded_json;

    try
    {
        // Read from file
        std::ifstream ifs("data.json");
        
        ifs >> loaded_json;
        ifs.close();
        serialized = loaded_json.dump();
        std::cout << "Serialized JSON: " << serialized << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error reading JSON from file: " << e.what() << std::endl;
    }

    // Access data
    auto d = loaded_json["param5"];
    int i = d[1];
    std::cout << "Loaded JSON:" << std::endl;
    std::cout << "param5[1]: " << i << std::endl;

    return 0;
}

// ############################################################