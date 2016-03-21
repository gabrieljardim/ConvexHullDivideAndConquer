#include "convexhull.h"
#include <iostream>
#include <algorithm>

bool xAxisCompare(Point a, Point b)
{
    return (a.x < b.x);
}

ConvexHull::ConvexHull()
{
    //ctor
}

void ConvexHull::dataInput()
{
    int n;
    std::cout << "Entre com a quantidade de pontos" << std::endl;
    std::cin >> n;

    for(int i = 0; i < n; ++i)
    {
        Point p;
        std::cin >> p.x >> p.y;

        m_pointList.push_back(p);
    }

    std::cout << "O n de elementos do vetor eh: " << m_pointList.size() << std::endl;
    std::cout << std::endl;
    this->dataSort();

    for(unsigned int i = 0; i < m_pointList.size(); ++i)
        std::cout << "Ponto: " <<  m_pointList.at(i).x << " " << m_pointList.at(i).y << std::endl;

}



std::vector<Point> ConvexHull::computeHull(std::vector<Point> v)
{
    int vectorSize = v.size();

    if(vectorSize > 3)
    {
         int half = vectorSize / 2;

         std::vector<Point> a(v.begin(), v.begin() + half -1);
         std::vector<Point> b(v.begin() + half, v.end());

         return mergeHull(computeHull(a), computeHull(b));

    }

    else return v;
}

std::vector<Point> ConvexHull::mergeHull(std::vector<Point> a, std::vector<Point> b)
{

}

void ConvexHull::execute()
{
    this->computeHull(this->m_pointList);
}

ConvexHull::~ConvexHull()
{
    //dtor
}

void ConvexHull::dataSort()
{
    std::sort(this->m_pointList.begin(), this->m_pointList.end(), xAxisCompare);
}
