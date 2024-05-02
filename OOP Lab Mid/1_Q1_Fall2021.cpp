#include<iostream>
#include<cstring>
using namespace std;

class student
{
    char* rollNo;
    int semester;
    char* name;
    float cgpa;
    public:
    student()
    {
        
    }
    student(const student&other)
    {
        this->name=new char[strlen(other.name)+1];
        this->rollNo=new char[strlen(other.rollNo)+1];
        strcpy(name,other.name);
        strcpy(rollNo,other.rollNo);
        this->semester=other.semester;
        this->cgpa=other.cgpa;
    }
    void input()
    {
        rollNo=new char;
        name=new char;
        cout<<"Enter roll 23L_3095\n";
        cin>>rollNo;
        cout<<"Enter Semester\n";
        cin>>semester;
        cout<<"Enter name\n";
        cin>>name;
        cout<<"Enter cgpa\n";
        cin>>cgpa;
    }
    void output()
    {
        
        cout<<name<<" "<<rollNo<<" "<<cgpa<<" "<<semester<<"\n";
    }
    float getGpa()
    {
        return cgpa;
    }
    int getSem()
    {
        return semester;
    }
    void deleteObj(student*& objArr,int m,int &size)
    {
    //     int newSize=size-1;
    //    // student*temp=new student[size-1];
       
    //     for(int i=m;i<newSize;i++)
    //     {
    //         //temp;
    //         student temp(objArr[i]);
    //         objArr[i]=objArr[i+1];
    //         objArr[i+1]=temp;
    //     }
    //     size--;
    delete[]objArr[i];

    }
    ~student()
    {
        cout<<"Destructor\n";
        delete[]name;
        //name=nullptr;
    }
   

};

void bubbleSort(student*ptr,int size)
{
     for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (ptr[j].getGpa() < ptr[j + 1].getGpa()) { // Sort in descending order
                // Swap the students
                student temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}



int main()
{
   cout<<"Tell how many student data you want to store\n";
   int size;
   cin>>size;
   student*ptr=new student[size];
   for(int i=0;i<size;i++)
   {
      ptr[i].input();
   } 
   for(int i=0;i<size;i++)
   {
      ptr[i].output();
   }

   cout<<"Sorting\n";
   bubbleSort(ptr,size);
//     for(int i=0;i<size;i++)
//    {
//       ptr[i].output();
//    }
   //udpate functionality----------------------
   //search name
   int semesterId;
  cout<<"Delete feature\n";
  cout<<"Enter semesterId\n";
  int input=0;
  cin>>input;
  for(int i=0;i<size;i++)
  {
    if(input==ptr[i].getSem())
    {
        ptr[i].deleteObj(ptr,i,size);
    }
  }
   
for(int i=0;i<size;i++)
   {
      ptr[i].output();
   }


}