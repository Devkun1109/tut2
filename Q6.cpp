#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

void readMatrix(Element elements[], int numElements) {
    cout << "Enter the elements (row, col, value):\n";
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i].row >> elements[i].col >> elements[i].val;
    }
}

void displayMatrix(const Element elements[], int numElements) {
    cout << "Sparse Matrix Representation:\n";
    for (int i = 0; i < numElements; i++) {
        cout << "(" << elements[i].row << ", " << elements[i].col << ") -> " << elements[i].val << endl;
    }
}

int transposeMatrix(const Element elements[], int numElements, Element result[], int rows, int cols) {
    int k = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < numElements; j++) {
            if (elements[j].col == i) {
                result[k++] = {elements[j].col, elements[j].row, elements[j].val};
            }
        }
    }
    return k;
}

int addMatrices(const Element mat1[], int numEl1, const Element mat2[], int numEl2, Element result[]) {
    int i = 0, j = 0, k = 0;
    while (i < numEl1 && j < numEl2) {
        if (mat1[i].row < mat2[j].row || 
            (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[k++] = mat1[i++];
        } else if (mat1[i].row > mat2[j].row || 
                   (mat1[i].row == mat2[j].row && mat1[i].col > mat2[j].col)) {
            result[k++] = mat2[j++];
        } else {
            result[k] = mat1[i];
            result[k++].val += mat2[j++].val;
            i++;
        }
    }
    while (i < numEl1) result[k++] = mat1[i++];
    while (j < numEl2) result[k++] = mat2[j++];
    return k;
}

int subtractMatrices(const Element mat1[], int numEl1, const Element mat2[], int numEl2, Element result[]) {
    int i = 0, j = 0, k = 0;
    while (i < numEl1 && j < numEl2) {
        if (mat1[i].row < mat2[j].row || 
            (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[k++] = mat1[i++];
        } else if (mat1[i].row > mat2[j].row || 
                   (mat1[i].row == mat2[j].row && mat1[i].col > mat2[j].col)) {
            result[k++] = mat2[j++];
        } else {
            result[k] = mat1[i];
            result[k++].val -= mat2[j++].val;
            i++;
        }
    }
    while (i < numEl1) result[k++] = mat1[i++];
    while (j < numEl2) result[k++] = mat2[j++];
    return k;
}

int multiplyMatrices(const Element mat1[], int numEl1, const Element mat2[], int numEl2, Element result[], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        cerr << "Matrices cannot be multiplied due to size mismatch.\n";
        exit(1);
    }

    Element mat2Transposed[numEl2];
    int numEl2Transposed = transposeMatrix(mat2, numEl2, mat2Transposed, rows2, cols2);

    int k = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            int sum = 0;
            for (int l = 0; l < cols1; l++) {
                int val1 = 0, val2 = 0;
                for (int m = 0; m < numEl1; m++) {
                    if (mat1[m].row == i && mat1[m].col == l) {
                        val1 = mat1[m].val;
                        break;
                    }
                }
                for (int n = 0; n < numEl2Transposed; n++) {
                    if (mat2Transposed[n].row == j && mat2Transposed[n].col == l) {
                        val2 = mat2Transposed[n].val;
                        break;
                    }
                }
                sum += val1 * val2;
            }
            if (sum != 0) {
                result[k++] = {i, j, sum};
            }
        }
    }
    return k;
}

int main() {
    int rows1, cols1, numEl1, rows2, cols2, numEl2;

    cout << "Enter the number of rows, columns, and non-zero elements for the first matrix: ";
    cin >> rows1 >> cols1 >> numEl1;
    Element mat1[numEl1];
    readMatrix(mat1, numEl1);

    cout << "Enter the number of rows, columns, and non-zero elements for the second matrix: ";
    cin >> rows2 >> cols2 >> numEl2;
    Element mat2[numEl2];
    readMatrix(mat2, numEl2);

    cout << "First Matrix:\n";
    displayMatrix(mat1, numEl1);
    cout << "Second Matrix:\n";
    displayMatrix(mat2, numEl2);

    Element sum[numEl1 + numEl2];
    int numElSum = addMatrices(mat1, numEl1, mat2, numEl2, sum);
    cout << "Sum of Matrices:\n";
    displayMatrix(sum, numElSum);

    Element diff[numEl1 + numEl2];
    int numElDiff = subtractMatrices(mat1, numEl1, mat2, numEl2, diff);
    cout << "Difference of Matrices:\n";
    displayMatrix(diff, numElDiff);

    if (cols1 == rows2) {
        Element product[rows1 * cols2];
        int numElProduct = multiplyMatrices(mat1, numEl1, mat2, numEl2, product, rows1, cols1, rows2, cols2);
        cout << "Product of Matrices:\n";
        displayMatrix(product, numElProduct);
    } else {
        cout << "Matrix multiplication cannot be performed due to size mismatch.\n";
    }

    Element transposed[numEl1];
    int numElTransposed = transposeMatrix(mat1, numEl1, transposed, rows1, cols1);
    cout << "Transpose of First Matrix:\n";
    displayMatrix(transposed, numElTransposed);

    return 0;
}
