#include<iostream>
#include<windows.h>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct color {
    int R;
    int G;
    int B;
};


class Circle {

private:
    COORD left_bottom;
    COORD right_top;
    color color_type;

public:
    Circle() {
        left_bottom = {};
        right_top = {};
        color_type = {};

    }
    void set_circle(COORD lb, COORD rb, color c) {
        left_bottom = lb;
        right_top = rb;
        color_type = c;
    }

    void draw_circle() {

        HWND hWindow = GetConsoleWindow();
        HDC hDeviceContext = GetDC(hWindow);
        HBRUSH hBrush = CreateSolidBrush(RGB(color_type.R, color_type.G, color_type.B));
        SelectObject(hDeviceContext, hBrush);
        Ellipse(hDeviceContext, left_bottom.X, left_bottom.Y, right_top.X, right_top.Y);

        DeleteObject(hBrush);
        ReleaseDC(hWindow, hDeviceContext);
    }
};

int main() {
    SetConsoleOutputCP(1251);
    Circle circle;
    
    srand(time(0));

    int count;


    cout << "¬ведите число шаров: ";
    cin >> count;
    system("cls");
    
    while (true) {

    for (int i = 0; i < count; i++)
    {
            short rand_num = rand() % 1921;
            short rand_num2 = rand() % 1921;
            circle.set_circle({ rand_num, rand_num2 }, { short(rand_num - 100),short(rand_num2 - 100) }, {0,255,255});
            circle.draw_circle();
            
        }
    Sleep(400);
    
    }
        

	return 0;
}