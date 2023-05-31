#include <bits/stdc++.h>

using namespace std;

class Cuboid {
private:
   int length, width, height;
public:
   string name;
   Cuboid() {
      length = 0;
      height = 0;
      width = 0;
   }

   Cuboid(string name,int length,int height,int width) {
      this->name = name;
      this->length = length;
      this->height = height;
      this->width = width;
   }
   int getVolume() {
      return length * height * width;
   }

   int getSurfaceArea() {
      int sa = 2*(length*width + width*height + height* length);
      return sa;
   }

   void printCub() {
      cout<<name<<" Volume "<<getVolume()<<" Surface area "<<getSurfaceArea()<<"\n";
   }
};

bool comp_vol(Cuboid a, Cuboid b)
{
   return a.getVolume() < b.getVolume();
}

bool comp_surf(Cuboid a, Cuboid b)
{
   return a.getSurfaceArea() > b.getSurfaceArea();
}

int main()
{
   vector<Cuboid>x;
   x.push_back(Cuboid("Cub 1", 5, 7, 2));
   x.push_back(Cuboid("Cub 2", 7, 4, 6));
   x.push_back(Cuboid("Cub 3", 2, 6, 4));
   x.push_back(Cuboid("Cub 4", 9, 3, 1));


   for(int i=0; i<4; i++)
      x[i].printCub();

   sort(x.begin(), x.end(), comp_vol);

   cout<<"\n\nAscending sorting by volume \n";
   for(int i=0; i<4; i++)
      x[i].printCub();

   sort(x.begin(), x.end(), comp_surf);

   cout<<"\n\nDescending sorting by surface area \n";
   for(int i=0; i<4; i++)
      x[i].printCub();

   return 0;
}
