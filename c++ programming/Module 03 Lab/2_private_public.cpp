#include <bits/stdc++.h>

// private class property can't use from outside.
// private class can access from inside of a specific class
// public class property can use from inside.
using namespace std;

class Student {
private:
   int ID;
   string name;
   int age;
   string fathers_name;
   string mothers_name;
public:
   void print_info()
   {
      cout<<ID<<" "<<name<<" "<<age<<" "<<fathers_name<<" "<<mothers_name<<"\n";
   }

   void set_info(string nam, int id, int ag)
   {
      name = nam;
      ID = id;
      age = ag;
   }
};

class User {
protected:
   string name;
   int age;
};

class Admin: User // extending by inheritance
{
private:
   string designation;
public:
   void set_AD(string s, int ag, string dg)
   {
      name = s;
      age = ag;
      designation = dg;
   }
   void print_AD()
   {
      cout<<name<<"\n";
      cout<<age<<"\n";
      cout<<designation<<"\n";
   }
};

int main()
{
//   Student s1;
//   s1.set_info("Totul", 18207002, 24);
//   s1.print_info();

   Admin ad1;
   ad1.set_AD("admin", 20, "AD");
   ad1.print_AD();
   return 0;
}
