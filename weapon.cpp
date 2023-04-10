#include<iostream>
#include"weapon.h"
using namespace std;

Weapon::Weapon(){}

ostream& operator<<(ostream &s, const Weapon &w){
    s<<"["<<" name: "<<w.name<<" , "<<"level: "<<w.level<<" , "<<"durability: "<<w.durability<<" ]";
    return s;
}