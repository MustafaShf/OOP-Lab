#include<iostream>
using namespace std;

class counter
{
private:
     static int count;
public:
   void setValue(int x)
   {
    count=x;
   }
   int getValue()
   {
    return count;
   }
   static void incrementcount ()
   {
    count++;
   
   }


};
int counter::count=0;

int main()
{
    counter ob1,ob2;
    counter::incrementcount();
    cout<<"Counter is = "<<ob1.getValue()<<"\n";
    counter::incrementcount();
    cout<<"Counter is = "<<ob2.getValue()<<"\n";


    return 0;
}