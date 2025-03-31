#include "Simulation.h"
#include <sstream>
#include <cassert>
#include <random>
#include <algorithm>

// Static random generator and distribution (will be reinitialized per simulation).
static std::default_random_engine generator;
static std::exponential_distribution<double> expDistribution(1.0);

Simulation::Simulation(double simulationTime, double timeStep, double arrivalRate,
                       double roadLength, double maxSpeed,
                       double greenDuration, double yellowDuration, double redDuration)
    : simulationTime_(simulationTime), timeStep_(timeStep), arrivalRate_(arrivalRate),
      currentTime_(0.0), vehicleCounter_(0),
      road_(roadLength, maxSpeed),
      trafficLight_(greenDuration, yellowDuration, redDuration),
      nextArrivalTime_(0.0)
{
    assert(simulationTime > 0 && timeStep > 0 && arrivalRate > 0);
    expDistribution = std::exponential_distribution<double>(arrivalRate_);
    nextArrivalTime_ = generateInterarrivalTime();
}

double Simulation::generateInterarrivalTime() {
    return expDistribution(generator);
}

void Simulation::addVehicleIfNeeded() {
    if (currentTime_ >= nextArrivalTime_) {
        vehicleCounter_++;
        // Alternate between Car and Truck for diversity.
        std::shared_ptr<Vehicle> vehicle;
        if (vehicleCounter_ % 2 == 0)
            vehicle = std::make_shared<Car>(vehicleCounter_, 0.0, road_.getMaxSpeed());
        else
            vehicle = std::make_shared<Truck>(vehicleCounter_, 0.0, road_.getMaxSpeed() * 0.8); // Trucks run slightly slower
        road_.addVehicle(vehicle);
        nextArrivalTime_ = currentTime_ + generateInterarrivalTime();
    }
}

bool Simulation::canVehicleMove(std::shared_ptr<Vehicle> vehicle) {
    // Vehicles can move if the traffic light is GREEN or if they are far enough from the intersection.
    if (trafficLight_.getState() == LightState::GREEN || vehicle->getPosition() < road_.getLength() - 10)
        return true;
    return false;
}

std::string Simulation::runSimulation(const std::string& simulationName) {
    std::ostringstream oss;
    oss << "============================================\n";
    oss << "          " << simulationName << "\n";
    oss << "============================================\n";
    oss << "Simulation Time: " << simulationTime_ << " seconds\n";
    oss << "Time Step: " << timeStep_ << " seconds\n";
    oss << "Arrival Rate: " << arrivalRate_ << " per second\n";
    oss << "Road Length: " << road_.getLength() << " m, Max Speed: " << road_.getMaxSpeed() << " m/s\n";
    oss << "Traffic Light Cycle Durations (s):\n";
    oss << "   Green: " << trafficLight_.getGreenDuration() << "\n";
    oss << "   Yellow: " << trafficLight_.getYellowDuration() << "\n";
    oss << "   Red: " << trafficLight_.getRedDuration() << "\n";
    oss << "Initial Traffic Light State: " << trafficLight_.getStateString() << "\n";
    oss << "--------------------------------------------\n";
    
    // Main simulation loop.
    while (currentTime_ < simulationTime_) {
        addVehicleIfNeeded();
        // Update traffic light.
        trafficLight_.update(timeStep_);
        // Update each vehicle.
        for (auto& vehicle : road_.getVehicles()) {
            bool move = canVehicleMove(vehicle);
            vehicle->update(timeStep_, move);
            if (vehicle->getPosition() >= road_.getLength()) {
                vehicle->markPassed();
                waitingTimes_.push_back(vehicle->getWaitingTime());
            }
        }
        road_.removePassedVehicles();
        currentTime_ += timeStep_;
    }
    
    // Compute metrics.
    double totalWaiting = 0.0;
    for (double wt : waitingTimes_)
        totalWaiting += wt;
    double avgWaiting = waitingTimes_.empty() ? 0.0 : totalWaiting / waitingTimes_.size();
    
    oss << "Total Vehicles Passed: " << waitingTimes_.size() << "\n";
    oss << "Average Waiting Time: " << avgWaiting << " seconds\n";
    oss << "============================================\n\n";
    
    // Reset simulation state for subsequent runs.
    currentTime_ = 0.0;
    vehicleCounter_ = 0;
    waitingTimes_.clear();
    road_.getVehicles().clear();
    nextArrivalTime_ = generateInterarrivalTime();
    
    return oss.str();
}