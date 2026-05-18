#include <iostream>

// Base class
class Shape
{
public:
   Shape(double width, double height)
       : m_width(width), m_height(height)
   {
   }

   ~Shape()
   {
   }

   void setWidth(double width)
   {
      m_width = width;
   }

   void setHeight(double height)
   {
      m_height = height;
   }

   // Can be changed only by child classes (not by any other)
protected:
   double m_width;
   double m_height;
};

// Derived class
class Rectangle : public Shape
{
public:
   Rectangle(double width, double height)
       : Shape(width, height)
   {
   }

   double getArea()
   {
      return m_width * m_height;
   }

   void printArea()
   {
      std::cout << "Rectangle Area: " << getArea() << std::endl;
   }
};

// Derived class
class Triangle : public Shape
{
public:
   Triangle(double base, double height)
       : Shape(base, height)
   {
   }

   double getArea()
   {
      return m_width * m_height / 2.0;
   }

   void printArea()
   {
      std::cout << "Triangle Area: " << getArea() << std::endl;
   }
};

int main()
{
   Rectangle rect(10, 20);
   Triangle tri(10, 20);

   rect.printArea();
   tri.printArea();

   return 0;
}

