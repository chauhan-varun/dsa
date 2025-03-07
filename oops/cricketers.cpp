#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Cricketer {
    private:
    string name;
    int age;
    int testMatches;
    int avgRun;

    public:
    void setName(string name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    void setTestMatches(int testMatches){
        this->testMatches = testMatches;
    }
    void setAvgRun(int avgRun){
        this->avgRun = avgRun;
    }

    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    int getTestMatches(){
        return testMatches;
    }
    int getAvgRun(){
        return avgRun;
    }
};

int main(){

    Cricketer varun;
    varun.setName("varun");
    varun.setAvgRun(300);
    varun.setAge(19);
    varun.setTestMatches(13242);
    
    Cricketer ashish;
    ashish.setName("ashish");
    ashish.setAvgRun(30);
    ashish.setAge(19);
    ashish.setTestMatches(42);

    Cricketer prem;
    prem.setName("prem");
    prem.setAvgRun(120);
    prem.setAge(19);
    prem.setTestMatches(4232);
    
    Cricketer vicky;
    vicky.setName("vicky");
    vicky.setAvgRun(324);
    vicky.setAge(19);
    vicky.setTestMatches(33342);

    Cricketer cricketers[] = {varun, ashish, prem, vicky};
    cout<<cricketers[0].getName();
    

}