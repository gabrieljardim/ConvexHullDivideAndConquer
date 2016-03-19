#include <iostream>
#include "DCLinkedList.h"
#include "Point.h"

using namespace std;

int main()
{
    DoubleCircularLinkedList<Point> dcll;

    Point* p = new Point(1,2);

    dcll.pushKey(new Point(1,2));
    dcll.pushKey(new Point(2,3));
    cout << dcll.count() << endl;
    dcll.popKey();
    cout << dcll.count() << endl;
    dcll.popKey();
    cout << dcll.count() << endl;
    dcll.popKey();
    cout << dcll.count() << endl;

    return 0;
}
