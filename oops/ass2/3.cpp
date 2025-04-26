#include<iostream>
#include<stdexcept>
using namespace std;

class Result {
    private:
    int marks[6];

    public:
    void inputMarks(int studentIndex){
        cout<<"enter the marks of student "<<studentIndex +1<<endl;
        for(int i=0; i<6; i++){
            cout<<"subject"<<i+1<<": ";
            cin>>marks[i];

            if(marks[i] < 0 || marks[i]>100){
                throw out_of_range("marks should be in range of 0-100");
            }
        }
    }

    float average(){
        float sum = 0;
        int subjectCount = sizeof(marks)/sizeof(marks[0])==0;
        if(subjectCount){
            throw runtime_error("error dividing by zero in calculating average");
        }
        for(int i=0; i<subjectCount; i++){
            sum+=marks[i];
        }
        return sum;
    }
};

int main(){
    Result Students[60];
    for(int i = 0; i<60; i++){
        try
        {
            Students[i].inputMarks(i);
            cout<<"average of student"<<Students[i].average()<<endl<<endl;
        }
        catch(const out_of_range &e)
        {
            cout<<"error: "<<e.what()<<endl;
        } catch(const runtime_error &e){
            cout<<"error: "<<e.what()<<endl;
        }
        
    }
}