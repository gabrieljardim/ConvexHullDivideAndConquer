#include <iostream>
#include "DCLinkedList.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    DoubleCircularLinkedList<int> dcll;

    cout << dcll.isEmpty() << endl;

    dcll.pushKey(new int(2));
    dcll.pushKey(new int(8));
    dcll.pushKey(new int(9));
    dcll.pushKey(new int(12));
    dcll.pushKey(new int(14));
    dcll.pushKey(new int(29));

    int* current = dcll.getCurrentKey();
    cout << *(dcll.getCurrentKey()) << endl;
    dcll.next();
    while(current != dcll.getCurrentKey())
    {cout << *(dcll.getCurrentKey()) << endl;
    dcll.next();}

    cout << dcll.isEmpty() << endl;


    return 0;
}
