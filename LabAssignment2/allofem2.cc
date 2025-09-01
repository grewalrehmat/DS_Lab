#include <iostream>
using namespace std;

class Matrix {
    int *A; 
    int n;  

public:
    Matrix(int size) {
        n = size;
        A = new int[n*n]; 
    }

    // (a) Diagonal Matrix
    void setDiagonal(int i, int j, int val) {
        if (i == j) A[i] = val;
    }
    int getDiagonal(int i, int j) {
        if (i == j) return A[i];
        else return 0;
    }

    // (b) Tri-diagonal Matrix
    void setTriDiagonal(int i, int j, int val) {
        if (i == j) A[i] = val;                  // main 
        else if (i == j+1) A[n+i] = val;         // lower 
        else if (j == i+1) A[2*n-1+i] = val;     // upper 
    }
    int getTriDiagonal(int i, int j) {
        if (i == j) return A[i];
        else if (i == j+1) return A[n+i];
        else if (j == i+1) return A[2*n-1+i];
        else return 0;
    }

    // (c) Lower Triangular Matrix
    void setLowerTri(int i, int j, int val) {
        if (i >= j) A[i*(i+1)/2 + j] = val;
    }
    int getLowerTri(int i, int j) {
        if (i >= j) return A[i*(i+1)/2 + j];
        else return 0;
    }

    // (d) Upper Triangular Matrix
    void setUpperTri(int i, int j, int val) {
        if (i <= j) A[j*(j+1)/2 + i] = val;
    }
    int getUpperTri(int i, int j) {
        if (i <= j) return A[j*(j+1)/2 + i];
        else return 0;
    }

    // (e) Symmetric Matrix 
    void setSymmetric(int i, int j, int val) {
        if (i >= j) A[i*(i+1)/2 + j] = val;
        else A[j*(j+1)/2 + i] = val; // since symmetric
    }
    int getSymmetric(int i, int j) {
        if (i >= j) return A[i*(i+1)/2 + j];
        else return A[j*(j+1)/2 + i];
    }

    ~Matrix() { delete[] A; }
};

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    Matrix m(n);

    cout << "\nEnter elements for Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        m.setDiagonal(i, i, val);
    }

    cout << "Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << m.getDiagonal(i, j) << " ";
        cout << "\n";
    }

    return 0;
}
