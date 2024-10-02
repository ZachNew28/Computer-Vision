// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"
#include "assert.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  value = 0;
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  value = 1000000;
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

//Initializes a matrix with values 3x5 and checks
//that it actually did
TEST(test_init) {
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);

  assert(Matrix_width(mat) == 3);
  assert(Matrix_height(mat) == 5);

  delete mat;

  //Same thing but for 1x1
  Matrix *mat2 = new Matrix;

  const int width2 = 1;
  const int height2 = 1;
  Matrix_init(mat2, width2, height2);

  assert(Matrix_width(mat2) == 1);
  assert(Matrix_height(mat2) == 1);

  delete mat2;

  //Same thing but with max values
  Matrix *mat3 = new Matrix;

  const int width3 = MAX_MATRIX_WIDTH;
  const int height3 = MAX_MATRIX_HEIGHT;
  Matrix_init(mat3, width3, height3);

  assert(Matrix_width(mat3) == MAX_MATRIX_WIDTH);
  assert(Matrix_height(mat3) == MAX_MATRIX_HEIGHT);

  delete mat3;

  //Test single column
  Matrix *mat4 = new Matrix;
  const int width4 = 1;
  const int height4 = 10;
  Matrix_init(mat4, width4, height4);

  assert(Matrix_width(mat4) == 1);
  assert(Matrix_height(mat4) == 10);

  delete mat4;

  //Test single row
  Matrix *mat5 = new Matrix;
  const int width5 = 10;
  const int height5 = 1;
  Matrix_init(mat5, width5, height5);

  assert(Matrix_width(mat5) == 10);
  assert(Matrix_height(mat5) == 1);

  delete mat5;
}

TEST(test_print) {
  //Test that the function works with random values
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);

  Matrix_print(mat, cout);

  delete mat;

  //Test that it works with min values
  Matrix *mat2 = new Matrix;

  const int width2 = 1;
  const int height2 = 1;
  Matrix_init(mat2, width2, height2);

  Matrix_print(mat2, cout);

  delete mat2;

  //Test that it works for max values
  Matrix *mat3 = new Matrix;

  const int width3 = MAX_MATRIX_WIDTH;
  const int height3 = MAX_MATRIX_HEIGHT;
  Matrix_init(mat3, width3, height3);

  Matrix_print(mat3, cout);

  delete mat3;

  //Test single column
  Matrix *mat4 = new Matrix;
  const int width4 = 1;
  const int height4 = 10;
  Matrix_init(mat4, width4, height4);

  Matrix_print(mat4, cout);

  delete mat4;

  //Test single row
  Matrix *mat5 = new Matrix;
  const int width5 = 10;
  const int height5 = 1;
  Matrix_init(mat5, width5, height5);

  Matrix_print(mat5, cout);

  delete mat5;
}

TEST(test_width) {
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);

  assert(Matrix_width(mat) == width);

  delete mat;

  //Test min values
  Matrix *mat2 = new Matrix;

  const int width2 = 1;
  const int height2 = 1;
  Matrix_init(mat2, width2, height2);

  assert(Matrix_width(mat2) == width2);

  delete mat2;

  //Check max values
  Matrix *mat3 = new Matrix;

  const int width3 = MAX_MATRIX_WIDTH;
  const int height3 = MAX_MATRIX_HEIGHT;
  Matrix_init(mat3, width3, height3);
  
  assert(Matrix_width(mat3) == width3);

  delete mat3;

  //Test single column
  Matrix *mat4 = new Matrix;
  const int width4 = 1;
  const int height4 = 10;
  Matrix_init(mat4, width4, height4);

  assert(Matrix_width(mat4) == width4);

  delete mat4;

  //Test single row
  Matrix *mat5 = new Matrix;
  const int width5 = 10;
  const int height5 = 1;
  Matrix_init(mat5, width5, height5);

  assert(Matrix_width(mat5) == width5);

  delete mat5;
}

TEST(test_height) {
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);

  assert(Matrix_height(mat) == height);

  delete mat;

  //Test min values
  Matrix *mat2 = new Matrix;

  const int width2 = 1;
  const int height2 = 1;
  Matrix_init(mat2, width2, height2);

  assert(Matrix_height(mat2) == height2);

  delete mat2;

  //Check max values
  Matrix *mat3 = new Matrix;

  const int width3 = MAX_MATRIX_WIDTH;
  const int height3 = MAX_MATRIX_HEIGHT;
  Matrix_init(mat3, width3, height3);
  
  assert(Matrix_height(mat3) == height3);

  delete mat3;

  //Test single column
  Matrix *mat4 = new Matrix;
  const int width4 = 1;
  const int height4 = 10;
  Matrix_init(mat4, width4, height4);

  assert(Matrix_height(mat4) == height4);

  delete mat4;

  //Test single row
  Matrix *mat5 = new Matrix;
  const int width5 = 10;
  const int height5 = 1;
  Matrix_init(mat5, width5, height5);

  assert(Matrix_height(mat5) == height5);

  delete mat5;
}

TEST(test_row) {
  //Test first element
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  const int* ptr = Matrix_at(mat, 0, 0);

  assert(Matrix_row(mat, ptr) == 0);

  //Test random different element
  ptr = Matrix_at(mat, 1, 0);
  assert(Matrix_row(mat, ptr) == 1);


  //Test upperbound
  ptr = Matrix_at(mat, 4, 2);
  assert(Matrix_row(mat, ptr) == 4);

  delete mat;

  //Test with max bounds
  Matrix *mat2 = new Matrix;

  const int width2 = MAX_MATRIX_WIDTH;
  const int height2 = MAX_MATRIX_HEIGHT;
  Matrix_init(mat2, width2, height2);

  ptr = Matrix_at(mat2, 499, 499);
  assert(Matrix_row(mat2, ptr) == 499);

  ptr = Matrix_at(mat2, 0, 0);
  assert(Matrix_row(mat2, ptr) == 0);

  delete mat2;

  //Test single column
  Matrix *mat3 = new Matrix;
  const int width3 = 1;
  const int height3 = 10;
  Matrix_init(mat3, width3, height3);

  ptr = Matrix_at(mat3, 1, 0);
  assert(Matrix_row(mat3, ptr) == 1);

  delete mat3;

  //Test single row
  Matrix *mat4 = new Matrix;
  const int width4 = 10;
  const int height4 = 1;
  Matrix_init(mat4, width4, height4);

  ptr = Matrix_at(mat4, 0, 1);
  assert(Matrix_row(mat4, ptr) == 0);

  delete mat4;
}

TEST(test_column) {
  //Test first element
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  const int* ptr = Matrix_at(mat, 0, 0);

  assert(Matrix_column(mat, ptr) == 0);

  //Test random different element
  ptr = Matrix_at(mat, 1, 1);
  assert(Matrix_column(mat, ptr) == 1);


  //Test upperbound
  ptr = Matrix_at(mat, 4, 2);
  assert(Matrix_column(mat, ptr) == 2);

  delete mat;

  //Test with max bounds
  Matrix *mat2 = new Matrix;

  const int width2 = MAX_MATRIX_WIDTH;
  const int height2 = MAX_MATRIX_HEIGHT;
  Matrix_init(mat2, width2, height2);

  ptr = Matrix_at(mat2, 499, 499);
  assert(Matrix_column(mat2, ptr) == 499);

  ptr = Matrix_at(mat2, 0, 0);
  assert(Matrix_column(mat2, ptr) == 0);

  delete mat2;

  //Test single column
  Matrix *mat3 = new Matrix;
  const int width3 = 1;
  const int height3 = 10;
  Matrix_init(mat3, width3, height3);

  ptr = Matrix_at(mat3, 1, 0);
  assert(Matrix_column(mat3, ptr) == 0);
  ptr = Matrix_at(mat3, 8, 0);
  assert(Matrix_column(mat3, ptr) == 0);

  delete mat3;

  //Test single row
  Matrix *mat4 = new Matrix;
  const int width4 = 10;
  const int height4 = 1;
  Matrix_init(mat4, width4, height4);

  ptr = Matrix_at(mat4, 0, 1);
  assert(Matrix_column(mat4, ptr) == 1);

  delete mat4;
}

TEST(test_at) {
  //Test min value
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 0);
  *Matrix_at(mat, 0, 0) = 4;

  assert(*Matrix_at(mat, 0, 0) == 4);
  
  //Test random value
  assert(*Matrix_at(mat, 1, 1) == 0);;

  //Test upperbound
  assert(*Matrix_at(mat, 4, 2) == 0);

  delete mat;

  //Test max values
  Matrix *mat2 = new Matrix;

  const int width2 = MAX_MATRIX_WIDTH;
  const int height2 = MAX_MATRIX_HEIGHT;
  Matrix_init(mat2, width2, height2);
  Matrix_fill(mat2, 0);
  *Matrix_at(mat2, 0, 0) = 4;

  assert(*Matrix_at(mat2, 0, 0) == 4);
  assert(*Matrix_at(mat2, MAX_MATRIX_HEIGHT - 1, MAX_MATRIX_WIDTH - 1) == 0);

  delete mat2;
}

TEST(test_fill_border) {
  Matrix *mat_compare = new Matrix;
  int* ptr;

  const int width = 3;
  const int height = 5;
  Matrix_init(mat_compare, width, height);

//Create a bordered matrix to compare it to
  ptr = Matrix_at(mat_compare, 0, 0);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 0, 1);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 0, 2);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 1, 0);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 1, 2);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 2, 0);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 2, 2);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 3, 0);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 3, 2);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 4, 0);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 4, 1);
  *ptr = 1;
  ptr = Matrix_at(mat_compare, 4, 2);
  *ptr = 1;

  Matrix *mat = new Matrix;
  Matrix_init(mat, width, height);
  Matrix_fill_border(mat, 1);
  Matrix_equal(mat_compare, mat);

  delete mat;
  delete mat_compare;

  //Test single column
  Matrix *mat_compare2 = new Matrix;
  const int width2 = 1;
  const int height2 = 10;
  Matrix_init(mat_compare2, width2, height2);

  //Initialize comparison matrix
  for (int i = 0; i < height2; i++) {
    ptr = Matrix_at(mat_compare2, i, 0);
    *ptr = 6;
  }

  Matrix *mat2 = new Matrix;
  Matrix_init(mat2, width2, height2);
  Matrix_fill_border(mat2, 6);
  Matrix_equal(mat_compare2, mat2);

  delete mat2;
  delete mat_compare2;

  //Test single row
  Matrix *mat_compare3 = new Matrix;
  const int width3 = 10;
  const int height3 = 1;
  Matrix_init(mat_compare3, width3, height3);

  //Initialize comparison matrix
  for (int i = 0; i < width3; i++) {
    ptr = Matrix_at(mat_compare3, 0, i);
    *ptr = 6;
  }

  Matrix *mat3 = new Matrix;
  Matrix_init(mat3, width3, height3);
  Matrix_fill_border(mat3, 6);
  Matrix_equal(mat_compare3, mat3);

  delete mat3;
  delete mat_compare3;
}

TEST(test_max) {
  //Test simple array and with one changed value
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  int *ptr;

  Matrix_fill(mat, 3);
  
  assert(Matrix_max(mat) == 3);

  ptr = Matrix_at(mat, 0, 0);
  *ptr = 4;

  assert(Matrix_max(mat) == 4);

  //Change a few more values
  ptr = Matrix_at(mat, 0, 1);
  *ptr = 2;
  ptr = Matrix_at(mat, 1, 0);
  *ptr = 8;

  assert(Matrix_max(mat) == 8);

  //Test last element
  Matrix_fill(mat, 3);
  ptr = Matrix_at(mat, 4, 2);
  *ptr = 10;

  assert(Matrix_max(mat) == 10);

  delete mat;
}

TEST(test_column_of_min_value_in_row) {
  Matrix *mat = new Matrix;
  const int width = 3;
  const int height = 5;
  int *ptr;
  Matrix_init(mat, width, height);

  Matrix_fill(mat, 5);
  ptr = Matrix_at(mat, 0, 0);
  *ptr = 3;

  //Test first element
  assert(Matrix_column_of_min_value_in_row(mat, 0, 0, 3) == 0);

  ptr = Matrix_at(mat, 0, 2);
  *ptr = 2;

  //Test random element
  assert(Matrix_column_of_min_value_in_row(mat, 0, 0, 3) == 2);

  ptr = Matrix_at(mat, 4, 2);
  *ptr = 1;

    //Test last element
  assert(Matrix_column_of_min_value_in_row(mat, 4, 0, 3) == 2);
  assert(Matrix_column_of_min_value_in_row(mat, 4, 2, 3) == 2);

  delete mat;
}

TEST(test_min_value_in_row) {
  Matrix *mat = new Matrix;
  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);

  Matrix_fill(mat, 5);
  //Test blank row of 5s
  assert(Matrix_min_value_in_row(mat, 0, 0, 3) == 5);

  int *ptr = Matrix_at(mat, 0, 2);
  *ptr = 4;
  
  //test last element of first row
  assert(Matrix_min_value_in_row(mat, 0, 0, 3) == 4);

  ptr = Matrix_at(mat, 4, 2);
  *ptr = 3;

  //Test last element of matrix
  assert(Matrix_min_value_in_row(mat, 4, 0, 3) == 3);
  assert(Matrix_min_value_in_row(mat, 4, 2, 3) == 3);

  delete mat;
}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
