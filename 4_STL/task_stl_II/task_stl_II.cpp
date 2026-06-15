// Auch hier: nach jedem Schritt ausgeben.
// Erstellen Sie einen Liste.
// Fügen Sie die Integer 0, 1, 1, 14, 5, 2, 3 hinzu.
// Entfernen Sie das erste Element.
// Fügen Sie die 8 hinzu.
// Ersetzten Sie die 14 mit einer 13 (ohne zu wissen an welcher Stelle die 14 steht).
// Sortieren Sie die Liste aufsteigend.
// Sortieren Sie die Liste absteigend.
// Sortieren Sie die Liste nach geraden und ungeraden Zahlen.

#include <list>
#include <iostream>
#include <algorithm>

void printList(std::list<int> InputList)
{
   for (auto &item : InputList)
   {
        std::cout << item << " ";
   }
   std::cout << std::endl;
}

bool sortingA(const int itemA, const int itemB)
{
    return itemA > itemB;
}

bool sortingB(const int itemA, const int itemB)
{
    return (itemA % 2 == 0 && itemB % 2 != 0);
}

int main()
{
    std::list<int> myList = {0,1,1,14,5,2,3};
    printList(myList);

    myList.erase(myList.begin());
    printList(myList);

    myList.push_back(8);
    printList(myList);

    std::replace(myList.begin(), myList.end(), 14, 13);
    printList(myList);

    myList.sort();
    printList(myList);

    myList.sort(sortingA);
    printList(myList);

    myList.sort(sortingB);
    printList(myList);

    return 0;
}
