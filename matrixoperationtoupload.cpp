#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int mat[10][10];

public:
    // Function to read matrix
    void read() {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;

        cout << "Enter matrix elements:\n";
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Function to print matrix
    void print() {
        cout << "Matrix:\n";
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Addition of matrices
    Matrix add(Matrix m2) {
        Matrix result;
        result.rows = rows;
        result.cols = cols;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + m2.mat[i][j];
            }
        }
        return result;
    }

    // Subtraction of matrices
    Matrix subtract(Matrix m2) {
        Matrix result;
        result.rows = rows;
        result.cols = cols;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] - m2.mat[i][j];
            }
        }
        return result;
    }

    // Multiplication of matrices
    Matrix multiply(Matrix m2) {
        Matrix result;
        result.rows = rows;
        result.cols = m2.cols;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < m2.cols; j++) {
                result.mat[i][j] = 0;
                for(int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m2.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix m1, m2, sum, diff, prod;

    cout << "Enter first matrix:\n";
    m1.read();

    cout << "Enter second matrix:\n";
    m2.read();

    // Display matrices
    m1.print();
    m2.print();

    // Addition
    sum = m1.add(m2);
    cout << "\nAddition:\n";
    sum.print();

    // Subtraction
    diff = m1.subtract(m2);
    cout << "\nSubtraction:\n";
    diff.print();

    // Multiplication
    prod = m1.multiply(m2);
    cout << "\nMultiplication:\n";
    prod.print();

    return 0;
}