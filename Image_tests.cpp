// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_init) {
  Image *img = new Image;
  int width = 3;
  int height = 5;

  Image_init(img, width, height);

  assert(Image_width(img) == 3);
  assert(Image_height(img) == 5);

  //Test 1x1
  width = 1;
  height = 1;

  Image_init(img, width, height);

  assert(Image_width(img) == 1);
  assert(Image_height(img) == 1);

  //Test max bounds
  width = MAX_MATRIX_WIDTH;
  height = MAX_MATRIX_HEIGHT;

  Image_init(img, width, height);

  assert(Image_width(img) == MAX_MATRIX_WIDTH);
  assert(Image_height(img) == MAX_MATRIX_HEIGHT);

  delete img;
}

TEST(test_init_istream) { //INCOMPLETE
  Image *img = new Image;
  ifstream file_data;

  file_data.open("dog.ppm");
  Image_init(img, file_data);
  
  //Test width and height
  assert(Image_width(img) == 5);
  assert(Image_height(img) == 5);

  //Test that a pixel is right
  Pixel pixel;
  pixel.r = 255;
  pixel.g = 255;
  pixel.b = 250;
  assert(Pixel_equal(Image_get_pixel(img, 0, 2), pixel));
  
  file_data.close();
  delete img;
}

TEST(test_width) {
  Image *img = new Image;
  int width = 3;
  int height = 5;

  Image_init(img, width, height);
  assert(Image_width(img) == 3);

  width = 1;
  height = 1;

  Image_init(img, width, height);
  assert(Image_width(img) == 1);

  width = MAX_MATRIX_WIDTH;
  height = MAX_MATRIX_HEIGHT;

  Image_init(img, width, height);
  assert(Image_width(img) == MAX_MATRIX_WIDTH);

  delete img;
}

TEST(test_height) {
  Image *img = new Image;
  int width = 3;
  int height = 5;

  Image_init(img, width, height);
  assert(Image_height(img) == 5);

  width = 1;
  height = 1;

  Image_init(img, width, height);
  assert(Image_height(img) == 1);

  width = MAX_MATRIX_WIDTH;
  height = MAX_MATRIX_HEIGHT;

  Image_init(img, width, height);
  assert(Image_height(img) == MAX_MATRIX_HEIGHT);

  delete img;
}

TEST(test_get_pixel) {
  Image *img = new Image;
  int width = 3;
  int height = 5;
  Pixel pixel;
  pixel.r = 0;
  pixel.g = 0;
  pixel.b = 0;

  Image_init(img, width, height);
  Image_set_pixel(img, 0, 0, pixel);

  //Test blank image
  assert(Pixel_equal(Image_get_pixel(img, 0, 0), pixel));

  pixel.r = 55;
  pixel.g = 100;
  pixel.b = 240;

  //Change color of last pixel and see if it changes
  Image_set_pixel(img, height - 1, width - 1, pixel);
  assert(Pixel_equal(Image_get_pixel(img, height - 1, width - 1), pixel));

  delete img;
}

TEST(test_set_pixel) {
  Image *img = new Image;
  int width = 3;
  int height = 5;
  Pixel pixel;
  pixel.r = 255;
  pixel.g = 255;
  pixel.b = 255;

  Image_init(img, width, height);

  //Test first pixel of image
  Image_set_pixel(img, 0, 0, pixel);
  assert(Pixel_equal(Image_get_pixel(img, 0, 0), pixel));

  pixel.r = 50;
  pixel.g = 50;
  pixel.b = 49;

  //Test last pixel of image
  Image_set_pixel(img, height - 1, width - 1, pixel);
  assert(Pixel_equal(Image_get_pixel(img, height - 1, width - 1), pixel));

  pixel.r = 0;
  pixel.g = 0;
  pixel.b = 0;

  //Test that the pixel is not equal to a black pixel
  assert(!Pixel_equal(Image_get_pixel(img, height - 1, width - 1), pixel));

  delete img;
}

TEST(test_fill) {
  Image *img = new Image;
  int width = 3;
  int height = 5;
  Pixel pixel;
  pixel.r = 255;
  pixel.g = 255;
  pixel.b = 255;

  Image_init(img, width, height);

  Image_fill(img, pixel);

  //Create a comparison image
  Image *img_compare = new Image;
  Image_init(img_compare, width, height);

  //Set each pixel to the color (white i think)
  for (int row = 0; row < height; row++) {
    for (int column = 0; column < width; column++) {
      Image_set_pixel(img_compare, row, column, pixel);
    }
  }
  //Assert they are the same
  assert(Image_equal(img, img_compare));

  pixel.r = 0;
  pixel.g = 0;
  pixel.b = 0;

  Image_fill(img, pixel);
 //Assert that the images are different
  assert(!Image_equal(img, img_compare));

  delete img;
  delete img_compare;

 //Test one column
  Image *img2 = new Image;
  width = 1;
  height = 10;
  Image_init(img2, width, height);

  Image *img_compare2 = new Image;
  Image_init(img_compare2, width, height);

  for (int row = 0; row < height; row++) {
    for (int column = 0; column < width; column++) {
      Image_set_pixel(img_compare2, row, column, pixel);
    }
  }

  Image_fill(img2, pixel);

  assert(Image_equal(img2, img_compare2));

  delete img2;
  delete img_compare2;
 
  //Test one row
  Image *img3 = new Image;
  width = 10;
  height = 1;
  Image_init(img3, width, height);
  Image_fill(img3, pixel);

  Image *img_compare3 = new Image;
  Image_init(img_compare3, width, height);

  for (int row = 0; row < height; row++) {
    for (int column = 0; column < width; column++) {
      Image_set_pixel(img_compare3, row, column, pixel);
    }
  }

  assert(Image_equal(img3, img_compare3));

  delete img3;
  delete img_compare3;
}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
