// Project UID af1f95f547e44c8ea88730dfb185559d

#include <iostream>
#include <fstream>
#include "Image.h"
#include "Matrix.h"
#include "processing.h"
using namespace std;

bool error_check(int width, int height, Image *img, Image *imgNew);

int main(int argc, char *argv[]) {
    string file_input;
    string file_output;
    int width;
    int height;
    ifstream infileStream;
    ofstream outfileStream;
    Image *img = new Image;
    Image *imgNew = new Image;

    //If the number of arguments is not right, end program
    if (argc < 4 || argc > 5) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
            << "WIDTH and HEIGHT must be less than or equal to original" << endl;
            delete imgNew;
            delete img;
            return 1;
    }

    file_input = argv[1];
    file_output = argv[2];
    width = atoi(argv[3]);

    //Make sure file can open
    infileStream.open(file_input);
    if (!infileStream.is_open()) { //Check that file opened
        cout << "Error opening file: " << file_input << endl;
        delete imgNew;
        delete img;
        return 1;
    }
    
    //Read in image
    Image_init(img, infileStream);
    infileStream.close();

    //Set height based on num of args in command line
    if (argc == 4) {
        height = Image_height(img);
    }
    else {
        height = atoi(argv[4]);
    }
    
    //If the desired width and height are not greater than zero 
    //or if they're bigger than the original, end the program
    if (error_check(width, height, img, imgNew)) {
        delete img;
        delete imgNew;
        return 1;
    }
    imgNew = img;

    //Carve and print image
    outfileStream.open(file_output);
    seam_carve(imgNew, width, height);
    Image_print(imgNew, outfileStream);
    outfileStream.close();
    delete imgNew;
}

bool error_check(int width, int height, Image *img, Image *imgNew) {
    bool crashCheck = false;
    if (width < 0 || width > Image_width(img) 
            || height < 0 || height > Image_height(img)) {
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                << "WIDTH and HEIGHT must be less than or equal to original" << endl;
                crashCheck = true;
        }
        return crashCheck;
}