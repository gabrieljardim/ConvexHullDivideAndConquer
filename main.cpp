#include <iostream>
#include <vector>

#include "convexhull.h"
#include "DCLinkedList.h"
#include "Point.h"

using namespace std;

int main()
{
    //DoubleCircularLinkedList<Point> dcll;

    DoubleCircularLinkedList<int> dcll;
    ConvexHull chull;

   // chull.dataInput();
    //chull.execute();

    dcll.pushKey(new int(1));
    dcll.pushKey(new int(2));
    dcll.pushKey(new int(3));
    dcll.pushKey(new int(4));
    dcll.pushKey(new int(5));

    int* aux = dcll.getCurrentKey();

    do{
        std::cout << "Chave: " << *(dcll.getCurrentKey()) << std::endl;
        dcll.next();

    } while(aux != dcll.getCurrentKey());



    return 0;
}
