#ifndef SIMULATION_H
#define SIMULATION_H

#include "TrafficObjects.h"
#include <string>
#include <vector>
#include <memory>

class Simulation {
public:
    Simulation(double simulationTime, double timeStep, double arrivalRate,
               double roadLength, double maxSpeed,
               double greenDuration, double yellowDuration, double redDuration);
    
    // Runs the simulation and returns a formatted result string.
    std::string runSimulation(const std::string& simulationName);

private:
    double simulationTime_;
    double timeStep_;
    double arrivalRate_;
    double currentTime_;
    int vehicleCounter_;
    Road road_;
    TrafficLight trafficLight_;
    std::vector<double> waitingTimes_;
    
    // Next arrival time for a new vehicle.
    double nextArrivalTime_;
    
    // Helper functions.
    double generateInterarrivalTime();
    void addVehicleIfNeeded();
    bool canVehicleMove(std::shared_ptr<Vehicle> vehicle);
};

#endif // SIMULATION_H