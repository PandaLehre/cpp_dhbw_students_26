
// Erstellen Sie einen Vektor.
// Fügen Sie die Strings „Eier”, „Schmalz”, „Zucker”, „Salz” und „Milch“ und „Mehl” hinzu.
// Geben Sie ihn aus.
// Das dritte Element entfernen. Wieder ausgeben.
// „Schokolade“ hinzufügen, ausgeben.
// Das Letzte Element mit „Safran“ ersetzen, ausgeben.
// Nach „Schmalz“ suchen und es entferne. Wieder ausgeben.
// Sortieren Sie ihren Vector. Wieder ausgeben.

#include <vector>
#include <iostream>
#include <algorithm>

void printContainer(std::vector<std::string> myContainer)
{
    std::cout << std::endl;
    for (auto &word : myContainer)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

bool myWayToSort(std::string strA, std::string strB)
{
    return (strA.length() > strB.length());
}

void printMyString(std::string InputString)
{
    std::cout << "Ihre Eingabe: "<< InputString << std::endl;
}

int main()
{
    std::vector<std::string> myVec{"Eier", "Schmalz", "Zucker", "Salz", "Milch", "Mehl"};
    printContainer(myVec);

    myVec.erase(myVec.begin() + 2);
    printContainer(myVec);

    myVec.push_back("Schokolade");
    printContainer(myVec);

    myVec.back() = "Safran";
    printContainer(myVec);

    myVec.erase(find(myVec.begin(), myVec.end(), "Schmalz"));
    printContainer(myVec);

    std::sort(myVec.begin(), myVec.end(), myWayToSort);
    printContainer(myVec);

    // Bezogen auf std::cin Leerzeichen
    // Standard-Eingabestrom (cin) liest bis zum ersten Leerzeichen
    std::string myString;
    std::cout << "Wählen Sie zwei Produkte: ";
    std::getline(std::cin, myString);
    // std::cin >> myString;
    printMyString(myString);

    return 0;
}