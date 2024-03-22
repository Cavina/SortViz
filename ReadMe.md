# SortViz

SortViz is a visualization tool designed to help users understand sorting algorithms through interactive visualizations. This project, implemented in C++ with SDL (Simple DirectMedia Layer), currently focuses on visualizing the bubble sort algorithm.

## Overview

Understanding sorting algorithms is fundamental to computer science and programming. SortViz aims to make this learning process more engaging and intuitive by providing real-time visualizations of sorting algorithms. With SortViz, users can witness the step-by-step process of sorting and observe how different algorithms rearrange elements to achieve a sorted sequence.

## Features

- Visualization of the bubble sort algorithm.
- Random data generation for sorting demonstrations.
- Interactive controls to initiate sorting, generate new data, and quit the application.

## Usage

1. Press `0` to generate a new set of random data.
2. Press `1` to visualize the bubble sort algorithm.
3. Press `q` to quit the application.

## Getting Started

### Prerequisites

- C++ compiler
- SDL library

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/your_username/SortViz.git
    Note, you will need to install SDL and create symlinks in the project to those locations
    ```

2. Compile the code:

    ```bash
    g++ Application.cpp -o SortViz -lSDL2
    ```

3. Run the executable:

    ```bash
    ./SortViz
    ```


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
