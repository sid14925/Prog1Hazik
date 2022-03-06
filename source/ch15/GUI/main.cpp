/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

// -----------------------------------------------------------------------------

int main()
{
    int xmax = 600;
    int ymax = 600;
    int axisLength = 400;
    int notches = 400 / 20;
    int yorigin = ymax / 2;
    int xorigin = xmax / 2;
    Point center(300, 300);

    Simple_window win{ Point{100,100}, xmax, ymax, "Function Graphs" };
    
    Axis xaxis(Axis::x, Point(100, yorigin), axisLength, notches, "x 1== 20 pixels");
    xaxis.set_color(Color::red);
    win.attach(xaxis);
    Axis yaxis(Axis::y, Point(xorigin, axisLength + 100), axisLength, notches, "y 1 == 20 pixels");
    yaxis.set_color(Color::red);
    win.attach(yaxis);

    win.wait_for_button();
}
