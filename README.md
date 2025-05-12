# 🚦 Smart Traffic Management Simulation

This repository contains a simulation-based traffic management system, inspired by a simulation project I worked on during my third year computer science degree at University of Manitoba. The project showcases a practical application of object-oriented programming in C++ to model real-world traffic behavior and assess the efficiency of various traffic light control strategies.

---

## 📌 Project Description

The objective of this simulation is to model a single-lane road with vehicles arriving randomly over time, regulated by a traffic light with configurable signal durations. The system evaluates how different parameters—such as arrival rates, road lengths, signal timing, and vehicle speeds—impact overall traffic flow and waiting times.

The simulation includes five predefined scenarios that analyze configurations to explore edge cases and performance variations under different traffic conditions.

---

## ⚙️ Core Functionality

- **Vehicle Generation**: Vehicles (cars and trucks) arrive at random intervals following an exponential distribution.
- **Traffic Light Control**: Signals transition through green, yellow, and red phases using custom durations.
- **Vehicle Behavior**: Vehicles make decisions based on their position relative to the intersection and the current light state.
- **Performance Metrics**: The simulation measures key statistics such as total vehicles processed and average waiting time.

All results are output in a structured, human-readable format directly to the console.

---

## 🧠 Technical Overview

- **Language**: C++
- **Architecture**: Modular design using object-oriented principles
- **Core Components**:
  - `Vehicle`, `Car`, and `Truck` classes to represent different vehicle types
  - `TrafficLight` class to manage light transitions
  - `Road` class to track vehicle states
  - `Simulation` engine to coordinate the overall system behavior

---

## 🚀 Getting Started

To build and run the simulation, follow these steps:

```bash
git clone https://github.com/AhmedZekoCodes/Smart-Traffic-Management-Simulation.git
cd Smart-Traffic-Management-Simulation
g++ main.cpp Simulation.cpp TrafficObjects.cpp -o TrafficSim
./TrafficSim
```

Ensure a C++ compiler is installed on your system.

---

## 📂 File Structure

- `main.cpp`: Entry point with five test case executions
- `Simulation.cpp/.h`: Manages simulation state and logic
- `TrafficObjects.cpp/.h`: Contains all traffic-related classes and entities

---

## 📊 Simulation Scenarios

Each test case explores different combinations of parameters:

- **Test Case 1**: Baseline simulation
- **Test Case 2**: High arrival rate
- **Test Case 3**: Extended road with higher max speed
- **Test Case 4**: Longer signal durations
- **Test Case 5**: Shortened simulation time

---

## 🔭 Future Enhancements

Planned improvements include:

- Implementation of machine learning algorithms for adaptive signal control
- Real-time data input to simulate live traffic conditions
- Further improve code design, heirarchy, and implementation

---

## 👨‍💻 About the Developer

I am Ahmed Abdelgalil(Zeko), a software engineer and soon to be Computer Science graduate. This project reflects my strong foundation in theoretical programming concepts, my attention to detail, and my commitment to solving real-world problems through software development.

If you are a potential collaborator, I welcome the opportunity to discuss this project or others like it in further detail.

---

## 📬 Contact

Please feel free to connect if you have any questions or feedback regarding this project.
