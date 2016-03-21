#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <vector>
#include "Point.h"


class ConvexHull
{
    public:
        ConvexHull();
        void dataInput();
        std::vector<Point> computeHull(std::vector<Point> p);
        std::vector<Point> mergeHull(std::vector<Point> a, std::vector<Point> b);
        void execute();
        virtual ~ConvexHull();
    protected:
    private:

        void dataSort();
        std::vector<Point> m_pointList;

};

#endif // CONVEXHULL_H
