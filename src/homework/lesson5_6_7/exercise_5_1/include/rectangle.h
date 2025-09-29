#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct {
    int width;
    int height;
} Rectangle;

int area(Rectangle r);


void grow(Rectangle *r, int dw, int dh);

#endif
