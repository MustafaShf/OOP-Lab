#include<iostream>
using namespace std;

class document
{
private:
    char **ptr;
public:
    document();
    void addSentence(int sizeOfArr,char arr[],int rowNo);
    void displaySentence(int rowNo);
    void DelSentence(int rowNo);
    
    ~document();
};

document::document()
{
    ptr=new char*[10];
}
void document::displaySentence(int rowNo){

     if (ptr[rowNo] != nullptr) { // Check if the sentence exists
        cout << ptr[rowNo] << endl;
    }
    else if (ptr[rowNo][0]=='\0')
    {
       cout<<"Sentence not present Might be possible you deleted it already\n";
    }
    
     else {
        cout << "No sentence found at " << rowNo << endl;
    }
}
void document::DelSentence(int rowNo)
{
   ptr[rowNo]=new char[1];
    ptr[rowNo][0]='\0';
}

void document::addSentence(int sizeOfArr,char arr[],int rowNo)
{
    ptr[rowNo]=new char[sizeOfArr+1];
    int i=0;
    for(;i<sizeOfArr;i++)
    {
        ptr[rowNo][i]=arr[i];
    }
    ptr[rowNo][i]='\0';
    cout<<"-->Sentence added Successfully\n";
}





document::~document()
{
    cout<<"Destructer Called\n";
    for(int i=0;i<10;i++)
    {
        delete[]ptr[i];
        ptr[i]=nullptr;
    }
    ptr=nullptr;
}
int arrSize(char arr[])
{   int n=0;
    for(int i=0;arr[i]!='\0';i++)
    {
        n++;
    }
    return n;
}


int main()
{
    cout<<"-->Enter How many doc you want to create\n";
    int totalDoc;
    cin>>totalDoc;
    cout<<"-->"<<totalDoc<<" Document created\n";
    document *ptr=new document[totalDoc];
    cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"-------->You Are only allowed addition because no sentence present<------------\n";
    cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
    for(int i=0;i<totalDoc;i++)
    {
        int totalSenPerDoc;
        totalSenPerDoc=0;
        cout<<"How many sentence you want to make for "<<i<<" Document\n";
        cin>>totalSenPerDoc;
        for(int j=0;j<totalSenPerDoc;j++)
        {
            cout<<"-->Enter Sentence\n";
            char arr[101]={'\0'};
            cin.ignore();
            cin.getline(arr,101);
            cout<<"-->this is arr size "<<arrSize(arr)<<"\n";
            cout<<"-->Adding sentence\n";
            ptr[i].addSentence(arrSize(arr),arr,j);
            
        }
    }
    int input;
    do
    {
        cout<<"-->press 1 to use display feature\n";
        cout<<"-->press 2 to use delete feature\n";
        cin>>input;
        if(input==1)
        {
                cout<<"Which sentence you want to see\n";
                cout<<"Enter Doc No\n";
                int doc;
                cin>>doc;
                cout<<"Enter Sentence No\n";
                int sentenceNo;
                cin>>sentenceNo;
                cout<<"-->displayinging sentence\n";
                ptr[doc].displaySentence(sentenceNo);

        }
        else if(input==2)
        {

                cout<<"Which sentence you want to Delete\n";
                cout<<"Enter Doc No\n";
                int doc;
                cin>>doc;
                cout<<"Enter Sentence No\n";
                int sentenceNo;
                cin>>sentenceNo;
                cout<<"-->Deleing sentence\n";
                ptr[doc].DelSentence(sentenceNo);
        }
        else{
            break;
        }
        

    } while (input!=-1);
    
   
 
    
    return 0;
}