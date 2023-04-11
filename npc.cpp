#include<iostream>
#include<cstdlib>
#include<ctime>
#include"npc.h"
using namespace std;

vector<string>NPCname = {"NPC_Hank", "NPC_Julia", "NPC_Alex", "NPC_Kelly"};
vector<string>script = {"What's in my bag?", "Find the boss and beat it!", "beat monsters and level up!"};


NPC::NPC(){}

NPC::NPC(string script,vector<Commodity>commodity,string name, int maxHealth, int currentHealth, int attack, int defense):GameCharacter(name,maxHealth,currentHealth,attack,defense){
    this->script = script;
    this->commodity = commodity;
}

ostream &operator<<(ostream &s,const Commodity &c){
    s<<"[ weapon:"<<c.weapon<<" , price:"<<c.price<<" ]"<<endl;
    return s;
}
                                                                                             
void NPC::showCommodity(){
    vector<Commodity>commodity = getCommodity();
    for(int i=0;i<commodity.size();i++){
        cout<<"("<<i+1<<") "<<commodity[i];
    }
}

int NPC::buyCommodity(int money){
    int idx;
    vector<Commodity>commodity = getCommodity();
    do{
        cout<<"Choose one weapon:"<<endl<<"(-1) refresh the commodities"<<endl<<"(0) buy nothing"<<endl;
        showCommodity();
        cout<<"=>";
        cin>>idx;
        if( idx>0 && idx<=commodity.size() ){
            if( money >= commodity[idx-1].getPrice() ){
                return idx-1;
            }else{
                cout<<"Your money is not enough"<<endl;
                return -1;
            }
        }else if(idx==0){
            return -1;
        }else if(idx==-1){
            string choice;
            do{
                cout<<"Want to spend 20 dollars to refresh the commodities? (A)Yes (B)No"<<endl<<"=>";
                cin>>choice;
                if(choice=="A"){
                    setCommodity(generateCommodities());
                    return -2;
                }else if(choice=="B"){
                    break;
                }else{
                    cout<<choice<<" is not a choice"<<endl;
                }
            }while(true);
        }else{
            cout<<idx<<" is not a choice"<<endl;
        }
   }while(true);
}

void NPC::setScript(string script){
    this->script = script;
}

void NPC::setCommodity(vector<Commodity>commodity){
    this->commodity = commodity;
}

string NPC::getScript(){
    return this->script;
}

vector<Commodity> NPC::getCommodity(){
    return this->commodity;
}

Commodity::Commodity(){}

Commodity::Commodity(int price,Weapon weapon){
    this->price = price;
    this->weapon = weapon;
}

void Commodity::setPrice(int price){
    this->price = price;
}

void Commodity::setWeapon(Weapon weapon){
    this->weapon = weapon;
}

int Commodity::getPrice(){
    return this->price;
}

Weapon Commodity::getWeapon(){
    return this->weapon;
}

int getRandomNumer3(int a,int b){
    
    return (rand()%(b-a+1)+a);
}

vector<Commodity> generateCommodities(){
    srand(time(NULL));
    vector<Commodity>ret;
    //all

    //spit
    Weapon spit = Weapon("spit","all",20,15);
    ret.push_back(Commodity(30,spit));
    //kick
    Weapon kick = Weapon("kick","all",15,20);
    ret.push_back(Commodity(30,kick));

    //Tank
    //helmet
    for(int i=1;i<=3;i++){
        string name = "helmet_"+to_string(i);
        Weapon sword = Weapon(name,"Tank",50-13*i,15+10*i);
        if(getRandomNumer3(0,1)==1){
            ret.push_back(Commodity(60+15*i,sword));
        } 
    }
    //chest
    for(int i=1;i<=3;i++){
        string name = "chest_"+to_string(i);
        Weapon sword = Weapon(name,"Tank",50-13*i,25+10*i);
        if(getRandomNumer3(0,1)==1){
            ret.push_back(Commodity(70+15*i,sword));
        } 
    }


    //Fighter
    //sword
    for(int i=1;i<=3;i++){
        string name = "sword_"+to_string(i);
        Weapon sword = Weapon(name,"Fighter",50-13*i,15+10*i);
        if(getRandomNumer3(0,1)==1){
            ret.push_back(Commodity(60+15*i,sword));
        } 
    }
    //arrow
    for(int i=1;i<=3;i++){
        string name = "arrow_"+to_string(i);
        Weapon sword = Weapon(name,"Fighter",50-13*i,25+10*i);
        if(getRandomNumer3(0,1)==1){
            ret.push_back(Commodity(70+15*i,sword));
        } 
    }

    //Magician
    //flame
    for(int i=1;i<=3;i++){
        string name = "flame_"+to_string(i);
        Weapon sword = Weapon(name,"Magician",50-13*i,15+10*i);
        if(getRandomNumer3(0,1)==1){
            ret.push_back(Commodity(60+15*i,sword));
        } 
    }
    //lightning
    for(int i=1;i<=3;i++){
        string name = "lightning_"+to_string(i);
        Weapon sword = Weapon(name,"Magician",50-13*i,25+10*i);
        if(getRandomNumer3(0,1)==1){
            ret.push_back(Commodity(70+15*i,sword));
        } 
    }

    return ret;
}