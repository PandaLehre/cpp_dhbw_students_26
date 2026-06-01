#include <iostream>

enum class Color // enum alleine nicht typsicher -> enum class typsicher
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
         std::cout << "\033[31mRed\033[0m"; // ANSI-Escape-Codes for colored output
         break;
      case Color::yellow:
         std::cout << "\033[33mYellow\033[0m";
         break;
      case Color::green:
         std::cout << "\033[32mGreen\033[0m";
         break;
      default:
         std::cout << "\033[34mBlue\033[0m";
   }
}


int main()
{
   Color myFavoriteColor = Color::blue;

   int test = static_cast<int>(myFavoriteColor) + static_cast<int>(Color::red);
   // Was passiert, wenn ich das übersetze?"
   // Die Intuition vieler ist: „blue ist 3, red ist 0, also test = 3."
   // Compiler-Fehler: enum class verbietet die Arithmetik und die implizite Umwandlung in int

   printColor(myFavoriteColor);

   return 0;
}