#ifndef CLASS_H
#define CLASS_H

#include <string>

class Car {
private:
    std::string brand;
    int speed;
    void validateSpeed(); // Private function to ensure speed remains non-negative

public:
    Car(); // Default constructor
    Car(std::string carBrand, int carSpeed); // Custom constructor
    
    std::string getBrand() const; // Getter for brand
    void setBrand(std::string carBrand); // Setter for brand
    
    int getSpeed() const; // Getter for speed
    void setSpeed(int carSpeed); // Setter for speed
    
    void accelerate(int amount); // Public method to increase speed
    void brake(int amount); // Public method to decrease speed
};
#endif