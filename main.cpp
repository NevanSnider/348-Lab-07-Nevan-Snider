
#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin();

  void fileRead(ifstream& file);

  // 2. Display a matrix
  void display() const;

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const;

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const;

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const;

  // 6. Swap matrix rows
  void swapRows(int row1, int row2);
};

// reads from user given input (space seperated numbers)
  void Matrix::readFromStdin(){
    for (int i = 0; i < SIZE; ++i){
      for (int j = 0; j < SIZE; ++j){
        cin >> data[i][j];
      }
    }
  }

// reads from a given file
  void Matrix::fileRead(ifstream& file){
    for (int i = 0; i < SIZE; ++i){
      for (int j = 0; j < SIZE; ++j){
        file >> data[i][j];
      }
    }
    
  }

// displays a given matrix
  void Matrix::display()const{
    for (int i = 0; i < SIZE; ++i){
      for (int j = 0; j < SIZE; ++j){
        cout << data[i][j] << " ";
      }
      cout << "\n";
    }
  }

//operator overloading for +
  Matrix Matrix::operator+(const Matrix& other)const{  
    Matrix final;
    for (int i = 0; i < SIZE; ++i){
      for (int j = 0; j < SIZE; ++j){
        final.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    return final;
  }

//operator overloading for *
  Matrix Matrix::operator*(const Matrix& other)const{
    Matrix final;
    for (int i = 0; i < SIZE; ++i){
      for (int j = 0; j < SIZE; ++j){
        final.data[i][j] = 0;
        for (int k = 0; k < SIZE; ++k){
          final.data[i][j] = final.data[i][j] + data[i][k] * other.data[k][j];
        }
      }
    }
    return final;
  }

//Sum of the diagonal numbers in a matrix
  int Matrix::sumOfDiagonals()const{
    int sum = 0;
    for (int i = 0; i < SIZE; ++i){
      sum += data[i][i];
      sum += data[i][SIZE - i - 1];
    }
    if (SIZE % 2 == 1){
      sum = sum - data[SIZE/2][SIZE/2];
    }
    return sum;
  }

//swaps two rows in a matrix
  void Matrix::swapRows(int firstRow, int secondRow){
    for (int i = 0; i < SIZE; ++i){
      int tempRow = data[firstRow][i];
      data[firstRow][i] = data[secondRow][i];
      data[secondRow][i] = tempRow;
    }
  }


int main() {

  // Example usage:
  Matrix mat1;
  Matrix mat2;

  int userAnswer = 0;

  cout << "Type 1 to read matrices from a file, type 2, to manually input the matrices." << endl;
  cin >> userAnswer;

// scenario if user reads from a file
  if (userAnswer == 1){
    string userFile;
    cout << "Enter the file name containing the matrices" << endl;
    cin >> userFile;
    ifstream file(userFile);

    mat1.fileRead(file);
    mat2.fileRead(file);

    file.close();
  }
  //Scenario if user enters values manually
  else if (userAnswer == 2){
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
  }

//displays matrix 1
  cout << "\nMatrix 1:" << endl;
  mat1.display();

//takes user input for matrix 2
  if (userAnswer == 2){
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
  }

//displays matrix 2
  cout << "\nMatrix 2:" << endl;
  mat2.display();

//sums two matrices and displays it
  Matrix sum = mat1 + mat2;
  cout << "\nSum of matrices:" << endl;
  sum.display();

//multiplies two matrices and displays it
  Matrix product = mat1 * mat2;
  cout << "\nProduct of matrices:" << endl;
  product.display();

//prints the sum of the diagonals
  cout << "\nSum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

//swaps rows in a matrix
  mat1.swapRows(0, 2);
  cout << "\nMatrix 1 after swapping rows:" << endl;
  mat1.display();

//allows exit of the program
  printf("Press enter to exit"); 
  getchar();
  getchar();
  return 0;
}
