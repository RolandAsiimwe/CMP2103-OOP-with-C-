#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle {
protected:
    string brand;
    int year;

public:
    void setVehicleDetails(string b, int y) {
        brand = b;
        year = y;
    }

    void displayVehicle() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class
class Car : public Vehicle {
protected:
    int numberOfDoors;

public:
    void setCarDetails(int doors) {
        numberOfDoors = doors;
    }

    void displayCar() {
        displayVehicle(); // Inherited member function
        cout << "Number of doors: " << numberOfDoors << endl;
    }
};

// Further derived class
class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    void setBatteryCapacity(int capacity) {
        batteryCapacity = capacity;
    }

    void displayElectricCar() {
        displayCar(); // Uses inherited function
        cout << "Battery capacity: "
             << batteryCapacity << " kWh" << endl;
    }
};

int main() {
    ElectricCar car1;

    car1.setVehicleDetails("Tesla", 2025);
    car1.setCarDetails(4);
    car1.setBatteryCapacity(75);

    cout << "ELECTRIC CAR DETAILS" << endl;
    cout << "--------------------" << endl;

    car1.displayElectricCar();

    return 0;
}