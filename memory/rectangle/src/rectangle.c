#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

Rectangle * createRectangle(void)
{
    Point pers;
    Rectangle *rec;

    pers.x = 0;
    pers.y = 0;
    
    rec = (struct Rectangle*)malloc(sizeof(Rectangle)); /*!!!*/

    rec->height = 0;
    rec->width = 0;
    rec->origin = pers;

    return rec;
}

Rectangle * createRectangle2(Point p)
{   
    Rectangle *rec;
    rec = (struct Rectangle*)malloc(sizeof(Rectangle)); /*!!!*/

    rec->height = 0;
    rec->width = 0;
    rec->origin = p;

    return rec;
}

Rectangle * createRectangle3(int w, int h)
{
    Point pers;
    Rectangle *rec;

    pers.x = 0;
    pers.y = 0;
    
    rec = (struct Rectangle*)malloc(sizeof(Rectangle)); /*!!!*/

    rec->height = h;
    rec->width = w;
    rec->origin = pers;

    return rec;
}

Rectangle * createRectangle4(Point p, int w, int h)
{
    Rectangle *rec;
    rec = (struct Rectangle*)malloc(sizeof(Rectangle)); /*!!!*/

    rec->height = h;
    rec->width = w;
    rec->origin = p;

    return rec;
}

void move(Rectangle *r, int x, int y)
{
    r->origin.x = x;
    r->origin.y = y;
}

int getArea(const Rectangle *r)
{
    return r->height * r->width;
}