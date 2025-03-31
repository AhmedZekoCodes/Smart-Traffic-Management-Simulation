#include "Simulation.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Run a series of test cases with varying parameters.
    std::vector<std::string> simulationResults;
    
    // Test Case 1: Basic simulation.
    Simulation sim1(60, 0.1, 0.5, 100, 15, 20, 5, 25);
    simulationResults.push_back(sim1.runSimulation("Test Case 1: Basic Simulation"));
    
    // Test Case 2: High arrival rate.
    Simulation sim2(60, 0.1, 1.0, 100, 15, 20, 5, 25);
    simulationResults.push_back(sim2.runSimulation("Test Case 2: High Arrival Rate"));
    
    // Test Case 3: Extended road with higher speed.
    Simulation sim3(60, 0.1, 0.5, 200, 25, 20, 5, 25);
    simulationResults.push_back(sim3.runSimulation("Test Case 3: Extended Road, Higher Speed"));
    
    // Test Case 4: Slower traffic light cycle.
    Simulation sim4(60, 0.1, 0.5, 100, 15, 30, 10, 40);
    simulationResults.push_back(sim4.runSimulation("Test Case 4: Slower Traffic Light Cycle"));
    
    // Test Case 5: Short simulation time.
    Simulation sim5(30, 0.1, 0.5, 100, 15, 20, 5, 25);
    simulationResults.push_back(sim5.runSimulation("Test Case 5: Short Simulation Time"));
    
    // Aesthetic formatted output with ASCII borders.
    std::cout << "\n\n********** SMART TRAFFIC MANAGEMENT SIMULATION RESULTS **********\n";
    for (const auto &result : simulationResults) {
        std::cout << result;
    }
    std::cout << "*****************************************************************\n\n";
    
    return 0;
}
