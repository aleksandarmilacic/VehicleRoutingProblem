# Vehicle Routing Project

This C++ project is a simple implementation of a greedy algorithm to solve a simplified version of the Vehicle Routing Problem (VRP).

## Problem Definition

Given a list of cities, each with a specific coordinate (x, y), the task is to find the shortest route that visits each city exactly once and returns to the origin city. This problem is a variant of the famous Traveling Salesman Problem (TSP).

## Solution Approach

The solution implemented here uses a simple greedy algorithm. The algorithm starts from the first city and it always visits the nearest unvisited city next. It's important to note that this algorithm doesn't guarantee an optimal solution due to its greedy nature.

## Visual Representation

The project provides a simple ASCII representation of the cities and the route. The cities are displayed on a grid where the 'C' character represents a city. When the route is calculated, the cities are marked with a number according to their order in the route. This map is printed to the console before and after the route calculation.

## Usage

To compile and run the program, use a C++ compiler that supports C++11 or later.
```
g++ -std=c++11 main.cpp -o vrp
./vrp
```
After running the program, you will see the map of cities and the calculated route displayed on the console.

## Future Improvements

This code is a basic implementation and serves as a starting point. There are many ways to improve and expand this project:

1. Implement a more sophisticated algorithm like a Genetic Algorithm or Simulated Annealing to find more optimal solutions.
2. Add support for additional constraints such as delivery time windows and vehicle capacities.
3. Improve the ASCII visualization or use a dedicated graphical library for better visual representation of the problem and solutions.
4. Implement input and output functionality to allow solving problems from text files and writing solutions to files.
5. Add unit tests and continuous integration to ensure code quality and correct behavior.

