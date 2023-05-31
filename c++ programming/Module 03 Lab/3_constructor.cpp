#include <bits/stdc++.h>

using namespace std;

class Student {
public:
   int ID;
   string name;
   int age;
   string fathers_name;
   string mothers_name;

   Student(string s, int id, int ag, string f_name, string m_name)
   {
      name = s;
      ID = id;
      age = ag;
      fathers_name = f_name;
      mothers_name = m_name;
   }
   Student(string s, int id, int ag)
   {
      name = s;
      ID = id;
      age = ag;
   }
   Student(){};
   void print_info()
   {
      cout<<ID<<" "<<name<<" "<<age<<" "<<fathers_name<<" "<<mothers_name<<"\n";
   }
};

int main()
{
   Student s1("Totul", 18207002, 24, "Sirajul Islam", "Irun Nahar");
   s1.print_info();

   Student s2("New", 5461, 2);
   s2.print_info();
   return 0;
}
