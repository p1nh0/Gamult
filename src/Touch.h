#ifndef TOUCH_H
#define TOUCH_H

#include "ofMain.h"
#include "Constants.h"
#include "ofApp.h"

class Touch {

    public:

        Touch(int x, int y);

        int getX() { return x; }
        int getY() { return y; }
        float getIncrement() { return increment; }

        void setXY(int x, int y) { this->x = x; this->y = y;}

        void update();
        void draw();

    private:

        int x;
        int y;
        float increment;

};

#endif
