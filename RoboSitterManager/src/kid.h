#ifndef KID_H
#define KID_H

class Kid
{
public:
    Kid();

    void setX(int x);
    int getX();

    void setY(int y);
    int getY();

    void setWidth(int w);
    int getWidth();

    void setHeight(int h);
    int getHeight();

    void setArea(int area);
    int getArea();

    void setLost(bool l);
    bool getLost();

    void setLostable(bool l);
    bool getLostable();

    void setStartValues(int area,int width, int height,int sw,int sh);

    int getStart_area();
    int getStart_width();
    int getStart_height();
    int getScreen_width();
    int getScreen_height();



private:
    int x;
    int y;
    int area;
    int start_area;
    int start_height;
    int start_width;
    int width;
    int height;
    int screen_width;
    int screen_height;

    bool lost;
    bool lostable;

};

#endif // KID_H
