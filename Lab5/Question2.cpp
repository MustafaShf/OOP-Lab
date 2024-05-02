#include<iostream>
using namespace std;
class rectangle
{
    private:
    int length;
    int width;
    public:
    
    rectangle& setwidth(int width)
    {
        this->width=width;
        return *this;
    }
    rectangle& setLength(int length)
    {
        this->length=length;
        return *this;
    }
    int getwidth()
    {
        
       return width;
    }
    int getLength()
    {
        
       return length;
    }
    
};

int main()
{
    rectangle ob1;
    ob1.setLength(10).setwidth(8);
    cout<<"The length is = "<<ob1.getLength()<<"\n";
     cout<<"The width is = "<<ob1.getwidth()<<"\n";
    return 0;
}