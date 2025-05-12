# 🚦 Smart Traffic Management Simulation

Welcome to my traffic management simulator – a project I built as a capstone to my computer science degree at the University of Manitoba.

It’s simple on the surface: a C++ program that simulates traffic flow. But under the hood, it’s got logic, timing, and real-world insight baked into every line. This is where software meets the streets.

---

## 🎯 What's This About?

Imagine a system that can simulate how cars and trucks behave on a road with changing traffic lights. That's what this does.

It helps answer questions like:
- What happens when vehicles arrive more frequently?
- How do wait times change when we tweak light durations?
- How does road length or speed impact flow?

I built five different test cases to explore these questions. Each one shows how changes in traffic light cycles, arrival rates, and road properties affect the system.

---

## 🧩 How It Works (In Human Terms)

- **Vehicles arrive randomly** using an exponential distribution to mimic real traffic.
- **Cars and trucks** are alternated to simulate diversity in speed and behavior.
- **Traffic lights** cycle through red, yellow, and green with customizable timing.
- **Each vehicle** either moves forward or waits, depending on the light and their position.
- **Performance is measured** by tracking how long each vehicle had to wait.

At the end, the program prints results for all the test cases—like average wait times and total vehicles passed—wrapped in a nice clean console output.

---

## 🛠 Tech & Concepts

- **Language**: C++
- **OOP Design**: Vehicles (Cars, Trucks), Road, and TrafficLight are modular and well-isolated.
- **Custom Simulation Loop**: Time-step-based logic that mimics real-life passing time.
- **Test Cases**: Automated runs with different parameter sets to explore edge cases.

---

## 🚀 Try It Yourself

To build and run the simulation:

```bash
git clone https://github.com/AhmedZekoCodes/Smart-Traffic-Management-Simulation.git
cd Smart-Traffic-Management-Simulation
g++ main.cpp Simulation.cpp TrafficObjects.cpp -o TrafficSim
./TrafficSim
