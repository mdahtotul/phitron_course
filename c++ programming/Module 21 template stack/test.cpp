#include <iostream>

using namespace std;
template <typename INT,typename FLOAT>
FLOAT Sum(INT p, FLOAT q)
{
    return p+q;
}
int main ()
{
    int x = 55;
    float result,y = 60.55;
    result = Sum<int,float>(x, y);
    cout << result << endl;
    return 0;
}
