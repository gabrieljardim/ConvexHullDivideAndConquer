#include <iostream>
#include <vector>

#include "convexhull.h"
#include "DCLinkedList.h"
#include "Point.h"

using namespace std;

int main()
{
    DoubleCircularLinkedList<Point> dcll;
    ConvexHull chull;

    chull.dataInput();
    chull.execute();


    return 0;
}
