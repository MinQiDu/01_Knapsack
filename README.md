# Implement Tabu Search Algorithm to Solve 0/1 Knapsack Problem

## ( I ) Introduction
- **Language**: C++
- **Metaheuristic Algorithm**: Tabu Search
- **Problem**: 0/1 Knapsack Problem

## ( II ) Main Functionality
- `void tabu_ks(int item, int capacity, int profit[], int weight[], int tabu_size, int tweak_c, queue<string> &L, set<string> &L_set, int itr)`  
  *Uses Tabu Search to find the optimal solution while avoiding local optima.*

- `void initial(int item, int capacity, int weight[], queue<string> &L, set<string> &L_set)`  
  *Generates a random feasible solution that does not exceed the knapsack capacity.*

- `string tweak(int item, string S, int capacity, int weight[], int tweak_c)`  
  *Applies minor modifications to create a distinct, valid solution within capacity.*

- `int p_count(int item, string sol, int profit[])`  
  *Calculates the total profit of the solution `sol`.*

## ( III ) Input
- **Number of items**: `item = 10`
- **Knapsack capacity**: `capacity = 165`
- **Item profits**: `profit = {92, 57, 49, 68, 60, 43, 67, 84, 87, 72}`
- **Item weights**: `weight = {23, 31, 29, 44, 53, 38, 63, 85, 89, 82}`
- **Tabu list size**: `tabu_size = 10`
- **Number of tweaks per iteration**: `tweak_c = 20`
- **Number of iterations**: `itr = 1000`


## ( V ) Output
- **Max profit**: `309`
- **Solution**: `1111010000`
*(Execution results are included in the attached `.zip` file.)*


## ( VI ) How to Compile and Run


### Compile
#### VSCode
1. Open PowerShell or Windows CMD
2. Navigate to the correct folder
3. Compile with:
```bash
g++ tabu_01knapsack.cpp -o tabu_01knapsack.exe
```
### Run
1. Open PowerShell or Windows CMD
2. Navigate to the correct folder
3. Run the program with:
```bash
.\tabu_01knapsack.exe
```

## ( VII ) File Structure

```
01knapsack/
│
├── tabu_01knapsack.cpp
└── README.md           ← this file
```

## ( VIII ) Observations
- The use of a Tabu List significantly improves the performance of the Tabu Search algorithm.

## ( IX ) Key Features
- Object-oriented design in C++
- strategy: `Tabu List` to escape local optima

## ( X ) Skills Demonstrated
- Modular C++ programming
- Metaheuristic algorithm implementation
- Benchmarking and convergence analysis
- Parameter sensitivity study
