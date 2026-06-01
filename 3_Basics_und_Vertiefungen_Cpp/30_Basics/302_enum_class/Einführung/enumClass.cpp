#include <iostream>

enum class Color
{
   red,
   yellow,
   green,
   blue
};

void printColor(Color color)
{
   switch(color)
   {
      case Color::red:
         std::cout << "Red";
         break;
      case Color::yellow:
         std::cout << "Yellow";
         break;
      case Color::green:
         std::cout << "Green";
         break;
      default:
         std::cout << "Blue";
   }
}


int main()
{
   Color myFavoriteColor = Color::blue; // Color::blue ist ein Element des Enumerations-Typs Color
    // Der Typ Color ist ein eigener Typ, kein verkappter Integer.
    // Die Werte spricht man scoped an (Color::blue), und im switch ebenso (case Color::red:).

   std::cout << static_cast<int>(myFavoriteColor) << std::endl;
   // Warum muss ich das static_cast überhaupt hinschreiben?
   // warum gibt cout nicht einfach die Zahl aus?
   // Antwort: Weil enum class eben kein Integer ist und sich nicht stillschweigend in einen verwandeln lässt

   printColor(myFavoriteColor);

   return 0;
}