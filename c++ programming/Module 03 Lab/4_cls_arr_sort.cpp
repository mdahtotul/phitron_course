#include <bits/stdc++.h>

using namespace std;

class Student {
public:
   int ID;
   string name;
   int age;
   string fathers_name;
   string mothers_name;

   Student(string name, int id, int age, string f_name, string m_name)
   {
      this->name = name;
      ID = id;
      this->age = age;
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
   // operator overloading
   bool operator < (Student a)
   {
      return ID < a.ID;
   }
};
// custom compare  function for sorting
//bool comp(Student a, Student b)
//{
//   return a.ID < b.ID;
//}

int main()
{
   vector<Student>a;

   for(int i=0; i<10; i++)
      a.push_back(Student("A", 20-i, 20));

   for(int i=0; i<10; i++)
      a[i].print_info();

   cout<<"After sorting"<<"\n";
   // one way to add custom compare function
   //sort(a.begin(), a.end(), comp);
   // another way to use operator overloading
   sort(a.begin(), a.end());

   for(int i=0; i<10; i++)
      a[i].print_info();
   return 0;
}
