#include <iostream>
#include <string>
using namespace std; 
  
struct Point 
{ 
    int x; 
    int y; 
    int z;
}; 


int main() {
    // An `int` with an initial value using different initialization methods
    int intVar1 = 10;               // Copy initialization
    int intVar2(20);                // Direct initialization
    int intVar3{30};                // Uniform initialization (C++11)
    int& ref_1 = intVar1;
    ref_1 = 20;
    // A `double` with an initial value using different initialization methods
    double doubleVar1 = 3.14;       // Copy initialization
    double doubleVar2(2.718);       // Direct initialization
    double doubleVar3{1.618};      // Uniform initialization (C++11)
    double& ref_2 = doubleVar1;
    ref_2 = 2.14;
    // A `std::string` with an initial value using different initialization methods
    std::string strVar1 = "Hello";  // Copy initialization
    std::string strVar2("World");   // Direct initialization
    std::string strVar3{"C++"};     // Uniform initialization (C++11)
    std::string& ref_3 = strVar1;
    ref_3 = "Bye"; 
    // A `bool` with an initial value using different initialization methods
    bool boolVar1 = true;           // Copy initialization
    bool boolVar2(false);           // Direct initialization
    bool boolVar3{true};            // Uniform initialization (C++11)

    // Output to check initialization
    std::cout << "intVar1: " << intVar1 << ", intVar2: " << intVar2 << ", intVar3: " << intVar3 << std::endl;
    std::cout << "doubleVar1: " << doubleVar1 << ", doubleVar2: " << doubleVar2 << ", doubleVar3: " << doubleVar3 << std::endl;
    std::cout << "strVar1: " << strVar1 << ", strVar2: " << strVar2 << ", strVar3: " << strVar3 << std::endl;
    std::cout << "boolVar1: " << boolVar1 << ", boolVar2: " << boolVar2 << ", boolVar3: " << boolVar3 << std::endl;

    //Output modified values
    std::cout<<"modified values" << std::endl;
    std::cout << "intVar1: " << intVar1 << " " << "doubleVar1: " << doubleVar1 << " " << "strVar1: "  << strVar1 << std::endl;
    
    Point point = { 1,2,3}; 
      
    // Structure binding 
    auto[ x_coord, y_coord, z_coord ] = point; 
    std::cout<<"structured binding" << std::endl;
    std::cout <<"x: " << x_coord << " " << "y: " << y_coord << " " << "z: " << z_coord << " " << std::endl;
    return 0;
}