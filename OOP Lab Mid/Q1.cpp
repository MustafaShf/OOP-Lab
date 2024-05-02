#include<iostream>
#include<cstring>
using namespace std;

class item
{
    private:
    int id;
    char *name;
    int quantity;
    int price;
    public:
    item()
    {
        id=0;
        name=new char[20]{'\0'};
        quantity=0;
        price=0;
    }
    item(item&obj)
    {
        id=obj.id;
        name=new char[20]{'\0'};
        quantity=obj.quantity;
        price=obj.price;
        strcpy(this->name,obj.name);
    }
    item&operator=(const item&obj)
    {
        if(this!=&obj)
        {
            delete[]name;
            this->name=new char[20];
            strcpy(this->name,obj.name);
            this->id=obj.id;
            this->quantity=obj.quantity;
            this->price=obj.price;

        }
        return* this;

    }
    void add()
    {
       // char namee[20]={'\0'};
        cout<<"id\n";
        cin>>id;
        cin.ignore();
        cout<<"Enter name";
        cin.getline(name,20);
        strcpy(this->name,name);
        cout<<"Enter Quatity\n";
        cin>>quantity;
        cout<<"Enter Price\n";
        cin>>price;
    }
    void remove(item objarr[],int&size)
    {
       int idSearch;
       bool found;
        cout<<"Enter id you want to remove\n";
        cin>>idSearch;
        for(int i=0;i<size;i++)
        {
            found=0;
            if(idSearch==objarr[i].id)
            {
                found=1;
            for(int j=i;i<size-1;i++)
            {
               
                objarr[j]=objarr[j+1];
                
            }
             size--;
             break;

            }
             
        }
        
       
    }
    void display()
    {
        cout<<name<<" "<<quantity<<" "<<id<<" "<<price<<"\n";
    }
    ~item()
    {
        cout<<"Destructer called\n";
        delete[]name;
    }

};
int main()
{
    int size=3;
    item *obj=new item[size];
    for(int i=0;i<size;i++)
    {
        obj[i].add();
    }
     obj[0].remove(obj,size);
     for(int i=0;i<size;i++)
     {
        obj[i].display();
     }
     delete[]obj;
    return 0;
}