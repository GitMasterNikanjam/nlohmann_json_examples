**nlohmann/json** is a popular C++ library that provides a simple and efficient way to work with JSON data. Created by **Niels Lohmann**, this library allows you to easily parse, generate, and manipulate JSON in your C++ programs.

### Key Features:
1. **Ease of Use**: The library is designed to be user-friendly with an API that closely resembles the structure and usage of JSON itself.
   
2. **STL-like Interface**: It provides an STL (Standard Template Library)-like interface, so if you're familiar with containers like `std::map`, `std::vector`, or `std::string`, using nlohmann/json feels very natural.
   
3. **Serialization and Deserialization**:
   - You can **parse** JSON data from strings, files, and streams into C++ objects.
   - You can also **serialize** (or dump) C++ objects back into JSON format.

4. **Type Safety**: The library automatically handles conversions between JSON data types and C++ types, such as integers, floating-point numbers, booleans, arrays, and objects.
   
5. **Template-based**: It’s a header-only library, so you don't need to compile any external binaries, which makes integration easier.
   
6. **Comprehensive Error Handling**: The library provides extensive error checking during parsing, with detailed exception messages to help you debug.

### Basic Example:
Here is a simple example of how you can use it:

```cpp
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Create a JSON object
    json j;
    j["name"] = "John";
    j["age"] = 30;
    j["is_student"] = false;
    j["skills"] = {"C++", "Python", "JavaScript"};

    // Serialize to string
    std::string jsonString = j.dump();
    std::cout << "Serialized JSON: " << jsonString << std::endl;

    // Deserialize from string
    json parsed = json::parse(jsonString);
    std::cout << "Name: " << parsed["name"] << std::endl;
    std::cout << "Age: " << parsed["age"] << std::endl;

    return 0;
}
```

### Key Functions:
- **`dump()`**: Serialize the JSON object to a string.
- **`parse()`**: Parse a string or stream into a JSON object.
- **`operator[]`**: Access or modify elements by key or index.
- **Type conversions**: Convert between native C++ types and JSON types (e.g., `int`, `double`, `std::string`, `std::vector`, etc.).

### Installation:
Since it's a header-only library, you can simply download and include the header file in your project:
```bash
# Using a package manager like vcpkg
vcpkg install nlohmann-json

# Or include via CMake
add_subdirectory(nlohmann_json)
target_link_libraries(your_target nlohmann_json::nlohmann_json)
```

This library is well-documented and widely used in C++ projects for handling JSON.    

----------------------------

For more Guidline see WiKi:  https://github.com/GitMasterNikanjam/nlohmann_json_examples/wiki   
