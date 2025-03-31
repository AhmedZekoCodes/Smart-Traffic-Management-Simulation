#include "TrafficObjects.h"
#include <iostream>
#include <sstream>
#include <algorithm>

//================== TrafficLight Implementation ==================
TrafficLight::TrafficLight(double greenDuration, double yellowDuration, double redDuration)
    : state_(LightState::RED), timer_(0.0),
      greenDuration_(greenDuration), yellowDuration_(yellowDuration), redDuration_(redDuration) {
    assert(greenDuration > 0 && yellowDuration > 0 && redDuration > 0);
}

void TrafficLight::update(double dt) {
    timer_ += dt;
    if (state_ == LightState::RED && timer_ >= redDuration_) {
        state_ = LightState::GREEN;
        timer_ = 0;
    }
    else if (state_ == LightState::GREEN && timer_ >= greenDuration_) {
        state_ = LightState::YELLOW;
        timer_ = 0;
    }
    else if (state_ == LightState::YELLOW && timer_ >= yellowDuration_) {
        state_ = LightState::RED;
        timer_ = 0;
    }
}

LightState TrafficLight::getState() const { return state_; }

std::string TrafficLight::getStateString() const {
    switch (state_) {
        case LightState::RED: return "RED";
        case LightState::YELLOW: return "YELLOW";
        case LightState::GREEN: return "GREEN";
        default: return "UNKNOWN";
    }
}

double TrafficLight::getGreenDuration() const { return greenDuration_; }
double TrafficLight::getYellowDuration() const { return yellowDuration_; }
double TrafficLight::getRedDuration() const { return redDuration_; }

//================== Vehicle Implementation ==================
Vehicle::Vehicle(int id, double position, double speed)
    : id_(id), position_(position), speed_(speed), waitingTime_(0.0), passed_(false) {}

void Vehicle::update(double dt, bool canMove) {
    if (canMove)
        move(dt);
    else
        addWaitingTime(dt);
}

int Vehicle::getId() const { return id_; }
double Vehicle::getPosition() const { return position_; }
double Vehicle::getSpeed() const { return speed_; }
double Vehicle::getWaitingTime() const { return waitingTime_; }
bool Vehicle::hasPassed() const { return passed_; }
std::string Vehicle::getType() const { return "Vehicle"; }

void Vehicle::markPassed() { passed_ = true; }
void Vehicle::addWaitingTime(double dt) { waitingTime_ += dt; }
void Vehicle::move(double dt) { position_ += speed_ * dt; }

//================== Car Implementation ==================
Car::Car(int id, double position, double speed)
    : Vehicle(id, position, speed) {}

std::string Car::getType() const { return "Car"; }

//================== Truck Implementation ==================
Truck::Truck(int id, double position, double speed)
    : Vehicle(id, position, speed) {}

std::string Truck::getType() const { return "Truck"; }

//================== Road Implementation ==================
Road::Road(double length, double maxSpeed)
    : length_(length), maxSpeed_(maxSpeed) {
    assert(length > 0 && maxSpeed > 0);
}

void Road::addVehicle(std::shared_ptr<Vehicle> vehicle) {
    assert(vehicle != nullptr);
    vehicles_.push_back(vehicle);
}

std::vector<std::shared_ptr<Vehicle>>& Road::getVehicles() { return vehicles_; }

double Road::getLength() const { return length_; }
double Road::getMaxSpeed() const { return maxSpeed_; }

void Road::removePassedVehicles() {
    vehicles_.erase(
        std::remove_if(vehicles_.begin(), vehicles_.end(),
                       [](std::shared_ptr<Vehicle> v) { return v->hasPassed(); }),
        vehicles_.end());
}