#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <vector>
#include "Point.h"
#include "DCLinkedList.h"



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
        void fillLinkedList(const std::vector<Point> v, DoubleCircularLinkedList<Point>* dcll);
        int isLeft(Point v0, Point v1, Point p );
        std::vector<Point> m_pointList;

};

#endif // CONVEXHULL_H
