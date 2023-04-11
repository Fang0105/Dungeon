#include"battle.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int getRandomNumer(int a,int b){
    return (rand()%(b-a+1)+a);
}


void battleSystem(Player *player,Monster *monster){
    cout<<"Meet monster "<<monster->getName()<<" !!!"<<endl;
    bool retreat = false;
    while( (player->checkIsDead()==false) && (monster->checkIsDead()==false) && (!retreat) ){
        do{
            cout<<player->getName()<<": "<<player->getCurrentHealth()<<"/"<<player->getMaxHealth()<<" , "<<monster->getName()<<": "<<monster->getCurrentHealth()<<"/"<<monster->getMaxHealth()<<endl;
            cout<<"Choose one Action: (A)Fight (B)retreat"<<endl<<"=>";
            string action;
            cin>>action;
            if(action=="A"){
                Weapon *weapon = player->chooseWeapon();
                player->attackMonster(monster,weapon);
                weapon->wear();
                player->deleteBrokenWeapons();
                if(monster->checkIsDead()==false){
                    monster->attackPlayer(player);
                }
                break;
            }else if(action=="B"){
                retreat = true;
                break;
            }else{
                cout<<action<<" is not an action choice"<<endl;
            }
        }while(true);
    }
    if(player->checkIsDead()){
        cout<<"You are dead..."<<endl;
    }else{
        player->heal();
    }
    if(monster->checkIsDead()){
        srand(time(NULL));
        cout<<"You win !!"<<endl;
        player->setMoney(player->getMoney() + monster->getDropMoney());
        player->setExp(player->getExp() + monster->getDropExp());
        player->levelUp();
        int temNumber = monster->number;
        monster->number++;
        monster->setDropExp(getRandomNumer(10,35));
        monster->setDropMoney(getRandomNumer(20,45));
        monster->setName(monsterName[getRandomNumer(0,2)]);
        monster->setMaxHealth(((temNumber%2==0)?500:800));
        monster->setCurrentHealth(((temNumber%2==0)?500:800));
        monster->setAttack(((temNumber%2==0)?120:80));
        monster->setDefense(25);
    }else{
        monster->heal();
    }
}