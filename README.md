# Matrix_Calculator-
📘 Matrix Calculator – C Project

A complete and user-friendly Matrix Calculator built in C that performs a wide variety of matrix operations.
This project is perfect for college submissions, practice, or GitHub portfolios.

🚀 Features

This Matrix Calculator supports the following operations:

🔹 1. Matrix Addition

Add two matrices of the same dimensions.

🔹 2. Matrix Subtraction

Subtract one matrix from another.

🔹 3. Matrix Multiplication

Multiply two matrices (if dimensions are valid).

🔹 4. Scalar Multiplication

Multiply a matrix by any real constant.

🔹 5. Matrix Transpose

Swap rows and columns of a matrix.

🔹 6. Determinant Calculation

Supports:

2×2 matrix

3×3 matrix

🔹 7. Matrix Inverse

Find the inverse of a 2×2 matrix (if determinant ≠ 0).

🔹 8. Error Handling

Invalid choices

Invalid multiplication dimensions

Division-by-zero determinant in inverse calculations

🛠️ Technologies Used

C Programming Language

Uses Variable-Length Arrays (VLA) for storing matrices

Works with GCC / Clang (C99 or later required)

📂 Project Structure
matrix-calculator/
│
├── matrix_calculator.c      # Main Calculator Source Code
├── README.md                # Project Documentation
└── sample_inputs.txt        # (Optional) Sample matrices

🧠 How the Program Works

The program displays a menu of matrix operations.

You enter your choice (example: 3 for multiplication).

The program asks for matrix dimensions.

You input the matrix elements.

The corresponding operation is performed and displayed.

Menu repeats until you select Exit (0).

▶️ How to Compile and Run
Using GCC:
gcc -std=c99 matrix_calculator.c -o matrix_calculator
./matrix_calculator

Using Windows (MinGW):
gcc -std=c99 matrix_calculator.c -o matrix_calculator.exe
matrix_calculator.exe

📸 Sample Output
=== MATRIX CALCULATOR ===
1. Matrix Addition
2. Matrix Subtraction
3. Matrix Multiplication
4. Scalar Multiplication
5. Matrix Transpose
6. Determinant (2x2 or 3x3)
7. Inverse (2x2)
0. Exit
Enter your choice: 1
Enter rows & cols: 2 2

Matrix A:
1 2
3 4

Matrix B:
5 6
7 8

Result:
6  8
10 12


💡 Why This Project is Useful

Strengthens your understanding of arrays & loops

Helps you learn matrix operations deeply

Great for college submission or resume

Demonstrates good coding and mathematical skills

🧑‍💻 Author : Mahesh Babu Baswani 

