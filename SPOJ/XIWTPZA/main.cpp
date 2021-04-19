#include <iostream>
#include <math.h>

using namespace std;

double countPythagoreanTheorem(const double CATHETUS1, const double CATHETUS2 );

int main() {
    double rectangleASide1, rectangleASide2, rectangleBSide1, rectangleBSide2;
    int iterations;
    cin >> iterations;

    for(int i =0; i<iterations; i++) {
        cin >> rectangleASide1 >> rectangleASide2 >> rectangleBSide1 >> rectangleBSide2;
        if(rectangleASide1 < rectangleASide2)
            swap(rectangleASide1, rectangleASide2);
        if(rectangleBSide1 < rectangleBSide2)
            swap(rectangleBSide1, rectangleBSide2);
        if(rectangleASide1 > rectangleBSide1 && rectangleASide2 > rectangleBSide2)
            cout << "TAK\n";
        else if(rectangleASide1 <= rectangleBSide1 && rectangleASide2 <= rectangleBSide2)
            cout << "NIE\n";
        else {
            double diagonalRectangle1, diagonalRectangle2;
            diagonalRectangle1 = countPythagoreanTheorem(rectangleASide1, rectangleASide2);
            diagonalRectangle2 = countPythagoreanTheorem(rectangleBSide1, rectangleBSide2);
            if(diagonalRectangle1 <= diagonalRectangle2) cout << "NIE\n";
            else {
                double cathetusA, cathetusB, hypotenuse;
                cathetusA = 0.5 * rectangleASide1 - sqrt(pow(0.5 * diagonalRectangle2, 2) - pow(0.5 * rectangleASide2, 2));
                cathetusB = 0.5 * rectangleASide2 - sqrt(pow(0.5 * diagonalRectangle2, 2) - pow(0.5 * rectangleASide1, 2));
                hypotenuse = countPythagoreanTheorem(cathetusA,cathetusB);
                if(hypotenuse > rectangleBSide2)
                    cout << "TAK\n";
                else
                    cout << "NIE\n";
            }
        }
    }
}
double countPythagoreanTheorem(const double CATHETUS1, const double CATHETUS2 ) {
    return sqrt(pow(CATHETUS1,2) + pow(CATHETUS2,2));
}
