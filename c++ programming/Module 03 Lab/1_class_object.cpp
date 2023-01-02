#include <bits/stdc++.h>

using namespace std;

class Student {
public:
   int ID;
   string name;
   int age;
   string fathers_name;
   string mothers_name;

   void print_info()
   {
      cout<<ID<<" "<<name<<" "<<age<<" "<<fathers_name<<" "<<mothers_name<<"\n";
   }

};
class Reactangle {
public:
   int width, height;
   int area;

   void calculate_area()
   {
      cout<<"Area "<<width*height<<"\n";
   }
   void calculate_perimeter()
   {
      cout<<"Perimeter "<<2*(width+height)<<"\n";
   }
};

int main()
{
   Student s1;
   s1.ID = 18207002;
   s1.name = "Arif";
   s1.age = 24;
   s1.fathers_name = "Sirajul Islam";
   s1.mothers_name = "Irun Nahar";

   s1.print_info();

   Reactangle rec1;
   rec1.width = 8;
   rec1.height = 4;

   rec1.calculate_area();
   rec1.calculate_perimeter();

   return 0;
}
