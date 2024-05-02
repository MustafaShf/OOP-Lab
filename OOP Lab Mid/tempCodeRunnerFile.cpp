
        return semester;
    }
    void deleteObj(student*& objArr,int m,int &size)
    {
        int newSize=size-1;
       // student*temp=new student[size-1];
       
        for(int i=m;i<newSize;i++)
        {
            //temp;
            student temp(objArr[i]);
            objArr[i]=objArr[i+1];