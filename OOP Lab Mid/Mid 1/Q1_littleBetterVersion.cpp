#include <iostream>
#include <cstring>

//-------------------------


int sizeOfArr(char arr[])
{
    int count=0;
    for(int i=0;arr[i]!='\0';i++)
    {
        count++;
    }
    return count;
}

void strcopy(char arr1[],char arr2[])
{
    int length=sizeOfArr(arr2);
    for(int i=0;i<length;i++)
    {
        arr1[i]=arr2[i];
    }
    arr1[length]='\0';
}
//--------------------------------


using namespace std;

class document {
private:
    char **ptr;
    int capacity; 
    int size;

    void resize(); 

public:
    document();
    void addSentence(char arr[]);
    void displaySentence(int rowNo);
    void delSentence(int rowNo);
    ~document();
};

document::document() {
    capacity = 2; 
    size = 0; 
    ptr = new char*[capacity];
}

void document::resize() {
    int newCapacity = capacity * 2; // Double the capacity
    char **newPtr = new char*[newCapacity];

    for (int i = 0; i < size; ++i) {
        newPtr[i] = ptr[i];
    }

    delete[] ptr;
    ptr = newPtr;
    capacity = newCapacity;
}

void document::addSentence(char arr[]) {
    if (size == capacity) {
        resize(); // Resize array if it's full
    }

    int length = strlen(arr);
    ptr[size] = new char[length + 1];
    strcopy(ptr[size], arr); // Copy the sentence into the new element
    size++;

    cout << "--> Sentence added successfully\n";
}

void document::displaySentence(int rowNo) {
    if (rowNo < 0 || rowNo >= size || ptr[rowNo] == nullptr) {
        cout << "Sentence not found.\n";
        return;
    }
    cout << ptr[rowNo] << endl;
}

void document::delSentence(int rowNo) {
    if (rowNo < 0 || rowNo >= size || ptr[rowNo] == nullptr) {
        cout << "Sentence not found.\n";
        return;
    }
    
    delete[] ptr[rowNo];
    ptr[rowNo] = nullptr; 
    
}

document::~document() {
    for (int i = 0; i < size; ++i) {
        if (ptr[i] != nullptr) {
            delete[] ptr[i];
        }
    }
    delete[] ptr;
    cout << "Destructor called\n";
}

int main() {
    cout << "Enter how many documents you want to create: ";
    int totalDoc;
    cin >> totalDoc;
    document *docs = new document[totalDoc];
    cin.ignore(); 

    int action;
    do {
        cout << "\nChoose action: 1 to add, 2 to remove, 3 to display, -1 to quit: ";
        cin >> action;
        cin.ignore(); 

        if (action == 1) {
            int docNum;
            cout << "Enter document number for adding a sentence: ";
            cin >> docNum;
            cin.ignore(); 

            if (docNum < 0 || docNum >= totalDoc) {
                cout << "Invalid document number.\n";
                continue;
            }

            cout << "Enter the sentence: ";
            char sentence[1024];
            cin.getline(sentence, sizeof(sentence));
            docs[docNum].addSentence(sentence);
        } else if (action == 2) {
            int docNum, sentNum;
            cout << "Enter document number for removing a sentence: ";
            cin >> docNum;
            cout << "Enter sentence number to remove: ";
            cin >> sentNum;
            if (docNum >= 0 && docNum < totalDoc) {
                docs[docNum].delSentence(sentNum);
            } else {
                cout << "Invalid document or sentence number.\n";
            }
        } else if (action == 3) {
            int docNum, sentNum;
            cout << "Enter document number to display a sentence: ";
            cin >> docNum;
            cout << "Enter sentence number to display: ";
            cin >> sentNum;
            if (docNum >= 0 && docNum < totalDoc) {
                docs[docNum].displaySentence(sentNum);
            } else {
                cout << "Invalid document or sentence number.\n";
            }
        }
    } while (action != -1);

    delete[] docs; // Clean up allocated documents
}
