#include<iostream>
using namespace std;

class Gun {
    public:
    int bullets;
    int reloadTime;
    bool isAtomatic;
};

class Player {
    private:
    class Helmet {
        private:
        int hp;
        int level;

        public:
        void setHp(int hp){
            this->hp = hp;
        }
        void setLevel(int level){
            this->level = level;
        }
        int getHp(){
            return hp;
        }
        int getLevel(){
            return level; 
        }
    };

    int age;
    int score;
    int health;
    bool alive;
    Helmet helmet;
    Gun gun; 
    
    public:

    void setAge(int age){
        this->age = age;
    }
    void setScore(int score){
        this->score = score;
    }
    void setHealth(int health){
        this->health = health;
    }
    void setAlive(bool alive){
        this->alive = alive;
    }
    void setGun(Gun gun){
        this->gun = gun;
    }
    void setHelmet(int level){
        Helmet *helmet = new Helmet;  //dynamic allocation (heap memory)
        helmet->setLevel(level);
        int hp=0;
        if(level==1) hp=50;
        else if(level==2) hp=100;
        else if(level==3) hp=150;
        else cout<<"invalid hp"<<endl; 
        helmet->setHp(hp);
        this->helmet = *helmet;
    }

    
    int getAge(){
        return age;
    }
    int getScore(){
        return score;
    }
    int getHealth(){
        return health;
    }
    bool getAlive(){
        return alive;
    }
    Gun getGun(){
        return gun;
    }
    void getHelmet(){
        cout<<helmet.getHp()<<endl;
        cout<<helmet.getLevel()<<endl;
    }
};


Player getMaxScorePlayer(Player a, Player b){
    if(a.getScore()>b.getScore()) return a;
    else return b;
}

int main(){

    Gun awm;
    awm.bullets = 12;
    awm.reloadTime = 30;
    awm.isAtomatic = false;

    Player varun;   //object creation statically
    varun.setAge(18);
    varun.setAlive(true);
    varun.setHealth(100);
    varun.setScore(1000);
    varun.setGun(awm);
    varun.setHelmet(3);

    Gun test = varun.getGun();
    cout<<test.bullets<<endl;
    cout<<test.reloadTime<<endl;
    cout<<test.isAtomatic<<endl;
    varun.getHelmet();


    Gun pistol;
    pistol.bullets = 4;
    pistol.reloadTime = 100;
    pistol.isAtomatic = false;

    Player ashish;                                  //compile time, static allocation (stack memory)
    ashish.setAge(19);
    ashish.setAlive(false);
    ashish.setScore(300);
    ashish.setHealth(0);
    ashish.setGun(pistol);
    ashish.setHealth(1);

    Player winner = getMaxScorePlayer(varun, ashish);
    cout<<winner.getScore()<<endl;

    Player players[3] = {varun, ashish, winner};
    cout<<players[1].getAge();

}