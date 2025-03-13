// class.cpp
#include "class.h"
#include <iostream>

Car::Car() : brand("Unknown"), speed(0) {}

Car::Car(std::string carBrand, int carSpeed) : brand(carBrand), speed(carSpeed) {
    validateSpeed();
}

std::string Car::getBrand() const {
    return brand;
}

void Car::setBrand(std::string carBrand) {
    brand = carBrand;
}

int Car::getSpeed() const {
    return speed;
}

void Car::setSpeed(int carSpeed) {
    speed = carSpeed;
    validateSpeed();
}

void Car::accelerate(int amount) {
    speed += amount;
    validateSpeed();
}

void Car::brake(int amount) {
    speed -= amount;
    validateSpeed();
}

void Car::validateSpeed() {
    if (speed < 0) {
        speed = 0;
        std::cout << "Speed cannot be negative. Setting to 0." << std::endl;
    }
}
