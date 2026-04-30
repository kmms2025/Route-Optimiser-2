# 🚗 Smart Route Optimizer

Smart Route Optimizer is a C-based project designed to solve the Traveling Salesman Problem (TSP) using both Greedy Algorithm and Dynamic Programming. This project helps users find the best possible route between multiple cities while comparing a fast approximate solution with the most optimal one.

---

## 📌 Project Description

The program allows users to:
- Enter city names
- Provide distances between cities
- Generate a route using Greedy Approach
- Find the optimal route using Dynamic Programming
- Compare route efficiency and total travel cost

This project is useful for understanding route optimization, pathfinding, and algorithm comparison in real-world logistics and transportation systems.

---

## ✨ Features

- Supports up to 10 cities
- Custom city name input
- Distance matrix support
- Greedy route optimization
- Dynamic Programming optimal route
- Route path display
- Cost comparison

---

## 🛠️ Technologies Used

- C Programming
- Dynamic Programming
- Greedy Algorithm
- Bitmasking
- Data Structures

---

## 📂 How It Works

1. User enters the number of cities
2. User inputs city names
3. User provides distance matrix
4. Greedy algorithm calculates approximate route
5. DP algorithm calculates shortest route
6. Program displays both routes and costs

---

## ▶️ Example Input

Enter number of cities: 4  
Enter city names: A B C D  

Distance Matrix:  
0 10 15 20  
10 0 35 25  
15 35 0 30  
20 25 30 0  

---

## 📤 Example Output

Greedy Route:  
A -> B -> D -> C -> A  
Cost: 80  

Optimal Route (DP):  
A -> B -> D -> C -> A  
Optimal Cost: 80  

---

## 📊 Time Complexity

- Greedy Algorithm: O(n²)
- Dynamic Programming: O(n² × 2ⁿ)

---

## 🎯 Applications

- Delivery Route Planning
- Logistics Optimization
- Cab Booking Systems
- Travel Planning
- Supply Chain Management

---

## 🚀 Future Enhancements

- Real-time traffic integration
- Map visualization
- GPS connectivity
- Larger city datasets
- GUI-based interface

---

## 👨‍💻 Conclusion

Smart Route Optimizer demonstrates how different algorithms can be used to solve complex routing problems. While Greedy offers speed, Dynamic Programming ensures accuracy, making this project an excellent educational tool for learning optimization techniques.

---
**Developed for academic and learning purposes using C Programming.**