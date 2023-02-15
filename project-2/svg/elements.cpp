#include <list>
#include "elements.hpp"

namespace svg {
    //Elipse
    ellipse::ellipse(const svg::color &fill,
                     const point &center,
                     const point &radius) :
            shape(fill), center(center), radius(radius) {

    }
    void ellipse::draw(png_image &img) const {
        img.draw_ellipse(center, radius, get_color());
    }
    void ellipse::translate(const point &t) {
        center = center.translate(t);
    }
    void ellipse::scale(const point &origin, int v) {
        radius.x *= v;
        radius.y *= v;
        center = center.scale(origin,v);
    }

    void ellipse::rotate(const point &origin, int degrees) {
        center = center.rotate(origin, degrees);
    }
    shape *ellipse::duplicate() const {
        return new ellipse(get_color(), center, radius);
    }

    //Circle
    circle::circle(const color &fill, const point &center, const point &radius) : ellipse(fill, center, radius){}

    //Polyline
    polyline::polyline(const color &c, const std::vector<point> &points) : shape(c), points(points){}
    void polyline::draw(png_image &img) const {
        point a = points.at(0);
        point b;
        for(auto itr = points.begin()+1 ; itr != points.end() ; itr++){
            b = *itr;
            img.draw_line(a,b, get_color());
            a = b;
        }
    }
    void polyline::translate(const point &t) {
        for(point& p : points){
            p = p.translate(t);
        }
    }
    void polyline::scale(const point &origin, int v) {
        for(point& p : points){
            p = p.scale(origin,v);
        }
    }

    void polyline::rotate(const point &origin, int degrees) {
        for(point& p : points){
            p = p.rotate(origin, degrees);
        }
    }
    shape *polyline::duplicate() const {
        return new polyline(get_color(), points);
    }

    //Line
    line::line(const color &stroke, const point &one, const point &two) : polyline(stroke,{one,two}){}

    //Polygon
    polygon::polygon(const color &fill, const std::vector<point> &points) :
            shape(fill), points(points){}
    void polygon::draw(png_image &img) const {
        img.draw_polygon(points,get_color());
    }
    void polygon::translate(const point &t) {
        for(point& p : points){
            p = p.translate(t);
        }
    }
    void polygon::scale(const point &origin, int v) {
        for(point& p : points){
            p = p.scale(origin,v);
        }
    }
    void polygon::rotate(const point &origin, int degrees) {
        for(point& p : points){
            p = p.rotate(origin,degrees);
        }
    }
    shape *polygon::duplicate() const {
        return new polygon(get_color(),points);
    }

    //Rect
    rect::rect(const color &fill,
               const point &upLeft,
               const int &width,
               const int &height) :
               polygon(fill,{upLeft,{upLeft.x+width-1,upLeft.y},
                             {upLeft.x+width-1,upLeft.y+height-1},
                             {upLeft.x,upLeft.y+height-1}}),
               width(width),
               height(height){
    }

    //Group
    group::group(const color &c, std::vector<shape *> ss) : shape(c), shapes(ss){}

    group::~group() {
        for(auto &s : shapes) {
            delete s;
        }
    }

    void group::draw(png_image &img) const {
        for(auto &s : shapes){
            s->draw(img);
        }
    }

    void group::translate(const point &t) {
        for(auto &s : shapes){
            s->translate(t);
        }
    }

    void group::scale(const point &origin, int v) {
        for(auto &s : shapes){
            s->scale(origin,v);
        }
    }

    void group::rotate(const point &origin, int v) {
        for(auto &s : shapes){
            s->rotate(origin,v);
        }
    }

    shape *group::duplicate() const {
        return new group(get_color(),shapes);
    }
}

