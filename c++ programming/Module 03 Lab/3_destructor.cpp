#include <bits/stdc++.h>

using namespace std;

class Person {
public:
   string name;
   Person *father, *mother;

   Person(){
      father= NULL;
      mother= NULL;
   }

   Person(string name, string f_name, string m_name)
   {
      this->name = name;
      father = new Person;
      father->name = f_name;
      mother = new Person;
      mother->name = m_name;
   }
   void print_info()
   {
      cout<<"Name = "<<name<<"\n";
      cout<<"Fathers name = "<<father->name<<"\n";
      cout<<"Mothers name = "<<mother->name<<"\n";

   }
   ~Person()
   {
      cout<<"Called\n";

      if (father != NULL) delete father;
      if (mother != NULL) delete mother;
   }

};

int main()
{
   Person p;
   p.father = new Person;
   p.mother = new Person;
   p.name = "A";
   p.father->name = "B";
   p.mother->name = "C";
   p.print_info();
   return 0;
}
