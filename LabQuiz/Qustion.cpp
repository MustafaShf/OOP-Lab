#include<iostream>
using namespace std;
class dataOfEmployes
{
    private:
    char*name;
    int salary;
    int uniqueId;
    public:
    dataOfEmployes ()
    {
        name=new char[101]{'\0'};
        salary=0;
        uniqueId=0;
    }
    void setSalary(int salary)
    {
        this->salary=salary;
    }
    void setId(int id)
    {
        uniqueId=id;
    }
    void setName(char name[])
    {
        this->name=name;
    }
    void Addition(char name[],int salary,int id)
    {
        setName(name);
        setSalary(salary);
        setId(id);
    }
    int getId()
    {
        return uniqueId;
    }
    void display()
    {
        cout<<"________________________\n";
        cout<<name<<"\n";
        cout<<salary<<"\n";
        cout<<uniqueId<<"\n";
    }
    void delobjdata(int i)
    {
        delete[]name;
        name=nullptr;
        salary=0;
        uniqueId=0;
    }
    ~dataOfEmployes()
    {
        cout<<"Destructor Called\n";
    }
};
int main()
{
    int value=0;
      int count=0;
    cout<<"We have zer0 employs\n";
    dataOfEmployes *empData=new dataOfEmployes[10];
    do{
        
        cout<<"Enter Operation or -1 to exit\n";
        cin>>value;
        if(value==1)
        {
            cout<<"Enter Name\n";
            cin.ignore();
        char name[101];
        cin.getline(name,101);
        cout<<"Enter Salary\n";
        int salary;
        cin>>salary;
        cout<<"Enter Unique id\n";
        int id;
        cin>>id;
      
        empData[count].Addition(name,salary,id);  
        ++count; 
        }
        else if(value==-1)
        break;
        }while(value!=-1);
        
        cout<<"Display data\n";
        int countNo=0;
        cout<<"Enter count no to see data\n";
        cin>>countNo;
        empData[countNo].display();
        xyz:
        cout<<"Do you want to search for unique id\n";
        char choice;
        cin>>choice;
        if(choice=='y')
        {
            cout<<"Enter unique id\n";
            int uniqueidtoSearch;
            cin>>uniqueidtoSearch;
            for(int i=0;i<count;i++)
            {
                if(uniqueidtoSearch==empData[i].getId())
                {
                     empData[i].display();
                     cout<<"Do you want to delete it\n";
                     char choicedel;
                     cin>>choicedel;
                     if(choicedel=='y')
                     {
                       empData[i].delobjdata(i);  
                       for(int j=i;j<count-1;j++)
                       {
                        empData[j]=empData[j+1];
                       }
                       goto xyz;
                     }
                }
            }

        }

    return 0;
}