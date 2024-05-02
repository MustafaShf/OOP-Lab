#include<iostream>
using namespace std;
class dynamicArr
{
private:
    
public:
int *ptr;
    dynamicArr();
    ~dynamicArr();
    void displayElement();
};

dynamicArr::dynamicArr()
{
    ptr=new int[10];
    for(int i=0;i<10;i++)
    {
        ptr[i]=i+1;
    }
}
void dynamicArr::displayElement()
{
    cout<<"Element of arr is \n";
    for(int i=0;i<10;i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}

dynamicArr::~dynamicArr()
{
    delete [] ptr;
    ptr=nullptr;
    cout<<"Destructor Called"<<"\n";
}

int main()
{
    dynamicArr ob1;
    ob1.displayElement();
    return 0;
}