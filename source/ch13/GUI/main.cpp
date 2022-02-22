/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    Lines x;
    Vector_ref<Rectangle> rect;
    
    bool grid[8][8] = {0};

    for (int i = 0; i<=800; i+=100) {
        x.add(Point(i,0), Point(i, 800));
        x.add(Point(0,i), Point(800, i));
        rect.push_back(new Rectangle(Point(i,i), Point(i+101, i+101)));
        rect[rect.size() -1].set_fill_color(Color::red);
        win.attach(rect[rect.size() -1]);
        grid[i/100][i/100] = true;
    }
    win.attach(x);

    Vector_ref<Image> images;
    for (int i = 0; i<300; i+=100) {
        images.push_back(new Image(Point(200 + i * 2,0 + i * 2), "art2.jpg"));
        images[images.size() -1].set_mask(Point(0,0), 200,200);
        win.attach(images[images.size() -1]);
        for(int j = 0; j<2; ++j)
            for (int k=0;k<2;++k)
                grid[i/50 + j][i/50 + 2 + k] = true;
    }

    unsigned int poz[] = {1,0};
    Image movingImg(Point(100, 0), "voltorb.jpg");
    //movingImg.set_mask(Point(150,150), 100,100);
    win.attach(movingImg);
    for (int i = 0; i<8;++i) {
        for (int j = 0; j<8;++j) {
            std::cout<<grid[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    while(true) {
        win.wait_for_button();
        int move[] = {0,0};
        int basePoz[] = {poz[0], poz[1]};
        do {
            poz[0] ++;
            move[0] += 100;
            if (poz[0]==8) {
                poz[0] = 0;
                move[0] = -basePoz[0] * 100;
                move[1] += 100;
                poz[1] ++;
            }
            if (poz[1]==8) {
                poz[1] = 0;
                move[1] = -basePoz[1] * 100;
            }
        } while(grid[poz[1]][poz[0]]);  
        movingImg.move(move[0], move[1]);
    }
}
