# Sudokusol
# 🔢 Backtracking-Based Sudoku Solver

A C++ console application that solves a 9×9 Sudoku puzzle using the **Backtracking Algorithm**. The solver recursively fills empty cells while enforcing standard Sudoku rules across rows, columns, and 3×3 subgrids.

---

## 🚀 Features

- Solves any valid 9x9 Sudoku puzzle using **recursive backtracking**
- Enforces all standard Sudoku constraints:
  - Each number 1–9 appears exactly once per row
  - Each number 1–9 appears exactly once per column
  - Each number 1–9 appears exactly once per 3×3 subgrid
- Validates and solves puzzles entered through standard input
- Displays the completed board in the console

---

## 🧠 Algorithm Used

This project uses the **Backtracking** technique:
- Empty cells are filled one-by-one with possible candidates (1–9)
- If a cell leads to a dead end, the algorithm **backtracks**
- The process continues recursively until the entire puzzle is solved

---

## 📦 Sample Input Format

Enter the puzzle row-by-row using `0` for empty cells:

