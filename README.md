# C Repository

**Developer:**  
- Ryan Carlos Sarcinelli 

## Project Description

This repository contains a collection of exercises and projects developed in C, organized into two main folders: **homeworks** and **Assignments**. The **homeworks** folder contains basic C exercises, while the **Assignments** folder contains more elaborate projects.

## Project Structure

The structure of the project is organized as follows:

```bash
C-Repository/
├── homeworks/              # Basic C exercises
│   ├── Exercise1.c
│   ├── Exercise2.c
│   └── ...
└── Assignments/            # Projects
    ├── DataStructure1/     # Organization of Movie Titles
    │   ├── main.c
    │   └── ...
    ├── GraphTheory1/       # Storage of Graphs
    │   ├── main.c
    │   └── ...
    ├── GraphTheory2/       # Minimum Spanning Tree
    │   ├── main.c
    │   └── ...
    ├── NumericAlgorithms1/  # Resolution of Linear Systems
    │   ├── main.c
    │   └── ...
    └── NumericAlgorithms2/  # Curve Fitting
        ├── main.c
        └── ...
```

## Project Functionalities

### Data Structure 1st Assignment
This project organizes movie titles using lists in main memory. The functionalities include:

1. Insert a new movie
2. Modify the data of a movie
3. Remove a movie
4. Print the list of movies
5. Insert the sequence of a movie
6. Print the sequence of a movie
7. Remove the sequence of a movie
8. Print the movie that precedes another
9. Print the movie that succeeds another
10. Exit

### Graph Theory 1st Assignment
In this project, graphs are stored, including their edges and vertices. It checks whether the graph is connected and determines how many edges are needed to connect it. An example of the input file is:
```bash
3
2
1 3
2 3
```
Where 3 is the number of vertices, and 2 is the number of edges, followed by the connections of those edges.

### Graph Theory 2nd Assignment
This project finds the minimum spanning tree of a given graph. The input file follows the format:
```bash
4
1 1
5 1
1 5
5 5 4
```
Here, 4 is the number of vertices, followed by the coordinates of the vertices. The Boruvka algorithm is used to find the solution.

### Numeric Algorithms 1st Assignment
This work solves linear systems based on data provided via the command line. The input file must contain:

- The number of systems in the file
- The dimension (N) of matrix A
- Precision for iterative methods
- The N × N values of matrix A
- For each system, the 1 × N values of vector B
- Example of input file:
```bash
1 1 3 0. 0 0 1
5. 0 2. 0 1. 0
2. 0 -1.0 3. 0
0. 0 1. 0 -2.0
8. 0 9. 0 -6.0
```
The methods used include Gaussian elimination, LU factorization, Gauss-Jacobi, and Gauss-Seidel.

### Numeric Algorithms 2nd Assignment
This work covers curve fitting, where three fittings are calculated for the provided data. The coefficient of determination \( r^2 \) is used to determine which fitting is the best.

# License
This project is licensed under the MIT License.
