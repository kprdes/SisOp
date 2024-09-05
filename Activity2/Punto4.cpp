#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Base class Shape
class Shape {
protected:
    string color;
    int area;
    int perimeter;
public:
    Shape(const string& color) : color(color), area(0), perimeter(0) {}
    virtual void calculateArea() = 0;  // Método virtual puro
    virtual void calculatePerimeter() = 0;  // Método virtual puro
    virtual void display() const = 0;  // Método virtual puro
};

// Rectangle class
class Rectangle : public Shape {
protected:
    int width, height;
public:
    Rectangle(int width, int height, const string& c) : Shape(c), width(width), height(height) {}

    void calculateArea() override {
        this->area = this->width * this->height;
    }

    void calculatePerimeter() override {
        this->perimeter = 2 * (width + height);
    }

    void display() const override {
        cout << "Rectangle width= " << this->width << ", height= " << this->height
             << ", color= " << this->color << "\nArea= " << this->area << ", perimeter= " << this->perimeter << endl;
    }
};

// Square class
class Square : public Rectangle {
public:
    Square(int side, const string& c) : Rectangle(side, side, c) {}

    void display() const override {
        cout << "Square side= " << this->width << ", color= " << this->color
             << "\nArea= " << this->area << ", perimeter= " << this->perimeter << endl;
    }
};

// Triangle class
class Triangle : public Shape {
private:
    int side1, side2, side3;

public:
    Triangle(int s1, int s2, int s3, const string& c) 
        : Shape(c), side1(s1), side2(s2), side3(s3) {}

    void calculatePerimeter() override {
        this->perimeter = side1 + side2 + side3;
    }

    void calculateArea() override {
        double s = static_cast<double>(this->perimeter) / 2;
        double area_triangle = sqrt(s * (s - side1) * (s - side2) * (s - side3));
        this->area = static_cast<int>(area_triangle);
    }

    void display() const override {
        cout << "Triangle sides= " << side1 << ", " << side2 << ", " << side3
             << ", color= " << color << "\nArea= " << this->area << ", perimeter= " << this->perimeter << endl;
    }
};

// Main program
int main() {
    vector<Shape*> Figures;
    bool exit = false;
    int choice, choice2, choice3;
    
    while (!exit) {
        cout << "Figures program\n-------------------------------" << endl;
        cout << "1. Create a new figure" << endl;
        cout << "2. See information of all figures" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "What do you want to create?\n1. Rectangle\n2. Triangle\n3. Square\n4. Exit\n";
                cin >> choice2;
                switch (choice2) {
                    case 1: {
                        int width, height;
                        string color;
                        cout << "Enter the width: ";
                        cin >> width;
                        cout << "\nEnter the height: ";
                        cin >> height;
                        cout << "\nEnter the color: ";
                        cin >> color;
                        
                        Shape* tmp = new Rectangle(width, height, color);
                        Figures.push_back(tmp);
                        break;
                    }
                    case 2: {
                        int side1, side2, side3;
                        string color;
                        cout << "Enter the side1: ";
                        cin >> side1;
                        cout << "\nEnter the side2: ";
                        cin >> side2;
                        cout << "\nEnter the side3: ";
                        cin >> side3;
                        cout << "\nEnter the color: ";
                        cin >> color;
                        Shape*tmp = new Triangle(side1, side2, side3, color);
                        Figures.push_back(tmp);
                        break;
                    }
                    case 3: {
                        int side;
                        string color;
                        cout << "Enter the side: ";
                        cin >> side;
                        cout << "\nEnter the color: ";
                        cin >> color;
                        Shape*tmp = new Square(side, color);
                        Figures.push_back(tmp);
                        break;
                    }
                    case 4:
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                }
                break;
            case 2:
                for (auto* fig : Figures) {
                    fig->calculateArea();
                    fig->calculatePerimeter();
                    fig->display();
                }
                break;
            case 3:
                exit = true;
                break;
            default:
                cout << "Invalid input" << endl;
        }
    }

    // Liberar memoria de las figuras
    for (auto* fig : Figures) {
        delete fig;
    }

    return 0;
}
