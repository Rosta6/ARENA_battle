/*
FILE pro definici class
 */


#include "include.h"
class fighter{
public:
    string fighter_name; 
    double HP;
    double attack;
    double armor;

};

void sleep()
{
   int i = 0;
   while (i < 5e8)  { i++; }
}

class people{
public:
    void makeNewFighterByHand(string name){
        shared_ptr<fighter> bojovnik = make_shared<fighter>();
        bojovnik->fighter_name = name;
        cout << "Zadej HP: ";
        cin >>bojovnik-> HP;
        cout << "Zadej utok: ";
        cin >>bojovnik-> attack;
        cout << "Zadej armor: ";
        cin >>bojovnik-> armor;
        fighters.push_back(bojovnik );
    }

    void makeNewRandomFighter(string name){
        shared_ptr<fighter> bojovnik = make_shared<fighter>();
        bojovnik->fighter_name = name;
        bojovnik-> HP = 2000 + rand()% 2000 + 1;         //pocet 2000 - 4000
        bojovnik-> attack= 300 + rand()% 100 + 1;        //pocet 200 - 300               
        bojovnik-> armor= 100 + rand()%200 + 1;          //pocet 100 - 300
        fighters.push_back(bojovnik);                  
    }

    void showFighters(){
        int i = 0;
        cout << "Bojovnici:" << endl;
        for( auto it : fighters)  {
            cout << i << " " <<it->fighter_name << endl;
            i++;
        }
    }
   void stats(int temp){
        shared_ptr<fighter> bojovnik = fighters[temp];
        cout << "### STATISTIKY BOJOVNIKA ###" << endl;
        cout << "Jmeno: " << bojovnik->fighter_name << endl;
        cout << "HP: " << bojovnik->HP << endl;
        cout << "Utok: " << bojovnik->attack << endl;
        cout << "Armor: " << bojovnik->armor << endl;
    }
    void souboj(int temp1, int temp2){
        int hp1, hp2,pocet_kol = 0;
        shared_ptr<fighter> bojovnik1 = fighters[temp1];
        shared_ptr<fighter> bojovnik2 = fighters[temp2];
        hp1 = bojovnik1->HP;
        hp2 = bojovnik2->HP;
        bool temp = true;
        while(temp){
        hp1 = zraneni(hp1, temp1, temp2);
        pocet_kol++;
        hp2 = zraneni(hp2, temp2, temp1);
        pocet_kol++;
        if (hp1 <= 0){
            temp = false;
            cout << "Souboj vyhral bojovnik " << bojovnik2->fighter_name << " po " << pocet_kol << "kolech!"<< endl;
        }else if(hp2 <= 0){
            temp = false;
            cout << "Souboj vyhral bojovnik " << bojovnik1->fighter_name << " po " << pocet_kol << "kolech!"<< endl;
        }
    }}
    int zraneni(int hp, int temp1, int temp2){
        shared_ptr<fighter> bojovnik1 = fighters[temp1];
        shared_ptr<fighter> bojovnik2 = fighters[temp2];
        double zraneni;
        zraneni = (bojovnik1->attack - bojovnik2->armor);
        hp = hp - zraneni;
        cout << "Bojovnik " << bojovnik1->fighter_name << " utoci na bojovnika " << bojovnik2->fighter_name << endl;
        sleep();
        cout << "Bojovnik " << bojovnik1->fighter_name << " zranuje bojovnika " << bojovnik2->fighter_name << " za " << zraneni << " zivotu." << endl;
        sleep();
        cout << "Bojovnik " << bojovnik2->fighter_name << " ma nyni " << hp << " zivotu." << endl;
        sleep();
        return hp;
    }
private:
    vector<shared_ptr<fighter>> fighters;
};