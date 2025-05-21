#include <iostream>
using namespace std;

// Class definition for Rectangle
class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width (optional)
    Rectangle() : length(0), width(0) {}

    // Function to set the length of the rectangle
    void setLength(double l) {
        if (l > 0) {
            length = l;
        } else {
            cout << "Length must be positive!" << endl;
        }
    }

    // Function to set the width of the rectangle
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        } else {
            cout << "Width must be positive!" << endl;
        }
    }

    // Function to calculate the area of the rectangle
    double calculateArea() const {
        return length * width;
    }

    // Function to display the dimensions of the rectangle
    void displayDimensions() const {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

int main() {
    // Create objects of the Rectangle class
    Rectangle rect1, rect2;

    // Set dimensions for the first rectangle
    rect1.setLength(10);
    rect1.setWidth(5);

    // Set dimensions for the second rectangle
    rect2.setLength(7);
    rect2.setWidth(3);

    // Display dimensions and calculate areas
    cout << "Rectangle 1:" << endl;
    rect1.displayDimensions();
    cout << "Area: " << rect1.calculateArea() << endl;

    cout << "Rectangle 2:" << endl;
    rect2.displayDimensions();
    cout << "Area: " << rect2.calculateArea() << endl;

    return 0;
}