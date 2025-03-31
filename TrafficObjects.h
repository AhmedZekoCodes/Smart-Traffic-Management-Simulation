#ifndef TRAFFICOBJECTS_H
#define TRAFFICOBJECTS_H

#include <string>
#include <vector>
#include <memory>
#include <cassert>

// Enumeration for the traffic light states.
enum class LightState { RED, YELLOW, GREEN };

//-------------------------------------------------------------------
// Class: TrafficLight
// Description: Controls an intersection's signal with configurable 
//              cycle durations.
//-------------------------------------------------------------------
class TrafficLight {
public:
    TrafficLight(double greenDuration, double yellowDuration, double redDuration);
    void update(double dt);
    LightState getState() const;
    std::string getStateString() const;
    double getGreenDuration() const;
    double getYellowDuration() const;
    double getRedDuration() const;
    
private:
    LightState state_;
    double timer_;
    double greenDuration_;
    double yellowDuration_;
    double redDuration_;
};

//-------------------------------------------------------------------
// Class: Vehicle (Base Class)
// Description: Abstract representation of a vehicle.
//-------------------------------------------------------------------
class Vehicle {
public:
    Vehicle(int id, double position = 0.0, double speed = 0.0);
    virtual ~Vehicle() = default;
    virtual void update(double dt, bool canMove);
    int getId() const;
    double getPosition() const;
    double getSpeed() const;
    double getWaitingTime() const;
    bool hasPassed() const;
    virtual std::string getType() const;
    void markPassed();
    void addWaitingTime(double dt);
    void move(double dt);
    
protected:
    int id_;
    double position_;
    double speed_;
    double waitingTime_;
    bool passed_;
};

//-------------------------------------------------------------------
// Class: Car (Derived from Vehicle)
//-------------------------------------------------------------------
class Car : public Vehicle {
public:
    Car(int id, double position = 0.0, double speed = 0.0);
    virtual std::string getType() const override;
};

//-------------------------------------------------------------------
// Class: Truck (Derived from Vehicle)
//-------------------------------------------------------------------
class Truck : public Vehicle {
public:
    Truck(int id, double position = 0.0, double speed = 0.0);
    virtual std::string getType() const override;
};

//-------------------------------------------------------------------
// Class: Road
// Description: Represents a road segment that holds vehicles.
//-------------------------------------------------------------------
class Road {
public:
    Road(double length, double maxSpeed);
    void addVehicle(std::shared_ptr<Vehicle> vehicle);
    std::vector<std::shared_ptr<Vehicle>>& getVehicles();
    double getLength() const;
    double getMaxSpeed() const;
    void removePassedVehicles();
    
private:
    double length_;
    double maxSpeed_;
    std::vector<std::shared_ptr<Vehicle>> vehicles_;
};

#endif // TRAFFICOBJECTS_H