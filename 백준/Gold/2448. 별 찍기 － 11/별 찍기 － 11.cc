#include <iostream>

using namespace std;
int table[3072][6143];

int pow(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result <<= 1;
    }
    return result;
}

void draw(int r, int c) {
    table[r][c] = 1;
    table[r + 1][c - 1] = 1;
    table[r + 1][c + 1] = 1;
    for (int i = 0; i < 5; i++) {
        table[r + 2][c - 2 + i] = 1;
    }
}

void recur(int row, int col, int k) {
    draw(row, col);
    for(int i=0;i<k;i++){
        recur(row+3*pow(i),col-3*pow(i),i);
        recur(row+3*pow(i),col+3*pow(i),i);
    }
}

int main() {
    int N, k = 0;
    cin >> N;
    N /= 3;
    while (N != 1) {
        N /= 2;
        k++;
    }
    int row = 3 * pow(k), col = 6 * pow(k)-1;
    recur(0, col / 2, k);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            if (table[i][j] == 1)
                cout << "*";
            else
                cout << " ";
        cout << endl;
    }
}