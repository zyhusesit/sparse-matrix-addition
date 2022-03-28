#include <iostream>
#include <iomanip>

#define N 30

using namespace std;

struct TripleTuple {
    int i, j, value;
};

struct MyMatrix {
    TripleTuple tuple[N];
    int row, col, sum;
};

void displayMatrix(MyMatrix *matrix);

void initialize(MyMatrix *A, MyMatrix *B);

MyMatrix *addition(MyMatrix *A, MyMatrix *B);

int main() {
    auto *A = new MyMatrix;
    auto *B = new MyMatrix;
    initialize(A, B);

    displayMatrix(A);
    displayMatrix(B);
    displayMatrix(addition(A, B));
}

MyMatrix *addition(MyMatrix *A, MyMatrix *B) {

    if (A->row != B->row || A->col != B->col) {
        cout << "Invalid operation, NOT matching scales!";
        exit(-1);
    } else {
        auto *C = new MyMatrix;
        C->row = A->row;
        C->col = A->col;
        C->sum = 0;
        int i_A = 0;
        int i_B = 0;

        while (i_A < A->sum && i_B < B->sum) {
            if (A->tuple[i_A].i < B->tuple[i_B].i) {
                C->tuple[C->sum] = A->tuple[i_A];
                i_A++;
            } else if (A->tuple[i_A].i > B->tuple[i_B].i) {
                C->tuple[C->sum] = B->tuple[i_B];
                i_B++;
            } else if (A->tuple[i_A].i == B->tuple[i_B].i && A->tuple[i_A].j < B->tuple[i_B].j) {
                C->tuple[C->sum] = A->tuple[i_A];
                i_A++;
            } else if (A->tuple[i_A].i == B->tuple[i_B].i && A->tuple[i_A].j > B->tuple[i_B].j) {
                C->tuple[C->sum] = B->tuple[i_B];
                i_B++;
            } else {
                C->tuple[C->sum].i = A->tuple[i_A].i;
                C->tuple[C->sum].j = A->tuple[i_A].j;
                C->tuple[C->sum].value = A->tuple[i_A].value + B->tuple[i_B].value;
                i_A++;
                i_B++;
            }
            C->sum++;
        }
        while (i_A < A->sum) {
            C->tuple[C->sum] = A->tuple[i_A];
            i_A++;
            C->sum++;

        }
        while (i_B < B->sum) {
            C->tuple[C->sum] = B->tuple[i_B];
            i_B++;
            C->sum++;

        }

        C->sum++;
        return C;
    }
}

void displayMatrix(MyMatrix *matrix) {
    int k = 0;
    for (int i = 1; i <= matrix->row; ++i) {
        for (int j = 1; j <= matrix->col; ++j) {
            if (matrix->tuple[k].i == i && matrix->tuple[k].j == j) {
                cout << setw(4) << matrix->tuple[k].value;
                ++k;
            } else
                cout << "   0";
        }
        cout << "\n";
    }
    cout << "\n";
}

void initialize(MyMatrix *A, MyMatrix *B) {
    A->row = 3;
    A->col = 4;
    A->sum = 4;
    A->tuple[0].i = 1;
    A->tuple[0].j = 2;
    A->tuple[0].value = 3;
    A->tuple[1].i = 2;
    A->tuple[1].j = 2;
    A->tuple[1].value = -1;
    A->tuple[2].i = 2;
    A->tuple[2].j = 4;
    A->tuple[2].value = 12;
    A->tuple[3].i = 3;
    A->tuple[3].j = 1;
    A->tuple[3].value = 9;

    B->row = 3;
    B->col = 4;
    B->sum = 5;
    B->tuple[0].i = 1;
    B->tuple[0].j = 4;
    B->tuple[0].value = 4;
    B->tuple[1].i = 2;
    B->tuple[1].j = 2;
    B->tuple[1].value = 1;
    B->tuple[2].i = 2;
    B->tuple[2].j = 3;
    B->tuple[2].value = 5;
    B->tuple[3].i = 3;
    B->tuple[3].j = 1;
    B->tuple[3].value = 2;
    B->tuple[4].i = 3;
    B->tuple[4].j = 2;
    B->tuple[4].value = -6;
}


