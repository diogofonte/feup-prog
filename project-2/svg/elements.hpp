//! @file elements.hpp
#ifndef __svg_elements_hpp__
#define __svg_elements_hpp__

#include <vector>
#include "shape.hpp"

namespace svg {
    //Ellipse
    class ellipse : public shape {
    protected:
        point center;
        point radius;
    public:
        ellipse(const svg::color &fill, const point &center, const point &radius);
        void draw(png_image &img) const final;
        void translate(const point &t) final;
        void scale(const point &origin, int v) final;
        void rotate(const point &origin, int v) final;
        shape *duplicate() const final;
    };

    //Circle
    class circle final : public ellipse{
    public:
        circle(const svg::color &fill, const point &center, const point &radius);
    };

    //Polyline
    class polyline : public shape {
    protected:
        std::vector<point> points;
    public:
        polyline(const color &stroke, const std::vector<point> &points);
        void draw(png_image &img) const final;
        void translate(const point &t) final;
        void scale(const point &origin, int v) final;
        void rotate(const point &origin, int v) final;
        shape *duplicate() const override;
    };

    //Line
    class line final : public polyline{
    public:
        line(const color &stroke, const point &one, const point &two);
    };

    //Polygon
    class polygon : public shape {
    protected:
        std::vector<point> points;
    public:
        polygon(const color &fill, const std::vector<point> &points);
        void draw(png_image &img) const final;
        void translate(const point &t) final;
        void scale(const point &origin, int v) final;
        void rotate(const point &origin, int v) final;
        shape *duplicate() const final;
    };

    //Rect
    class rect final : public polygon{
    private:
        int width;
        int height;
    public:
        rect(const color &fill, const point &upLeft, const int &width, const int &height);
    };

    //Group
    class group final : public shape{
    private:
        std::vector<shape*> shapes;
    public:
        group(const color &c, std::vector<shape *> ss);
        ~group() override;
        void draw(png_image &img) const final;
        void translate(const point &t) final;
        void scale(const point &origin, int v) final;
        void rotate(const point &origin, int v) final;
        shape *duplicate() const final;
    };
}
#endif
