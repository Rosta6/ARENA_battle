/*
FILE pro definici class
 */


#include "include.h"
/*
    // Functions() 
    void printname(){ 
       cout << "Jmeno bojovnika je: " << fighter_name; 
    } 

    void set_fighter(){
    cout << "Zadej jmeno sveho bojovnika:";
    cin >> fighter_name; 
    cout << "Zadej HP sveho bojovnika:";
    cin >> HP;
    cout << "Zadej utok sveho bojovnika:";
    cin >> attack;
    cout << "Zadej armor sveho bojovnika:";
    cin >> armor;
    cout << "Zadej uhyb sveho bojovnika:";
    cin >> dodge;
    cout << "Zadej rychlost sveho bojovnika:";
    cin >> speed;
    cout << "Zadej sanci na kriticky zasah sveho bojovnika:";
    cin >> critical_chance;
    }

    void stats(){
        cout << "### STATISTIKY BOJOVNIKA ###" << endl;
        cout << "Jmeno: " << fighter_name << endl;
        cout << "HP: " << HP << endl;
        cout << "Utok: " << attack << endl;
        cout << "Armor: " << armor << endl;
        cout << "Uhyb: " << dodge << endl;
        cout << "Rychlost: " << speed << endl;
        cout << "Sance na kriticky zasah: " << critical_chance << endl;
    }
}; 
*/
class fighter{
public:
    string fighter_name; 
    double HP;
    double attack;
    double armor;
    double dodge;
    int speed;
    double critical_chance;
};

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
        cout << "Zadej dodge: ";
        cin >>bojovnik-> dodge;
        cout << "Zadej speed: ";
        cin >>bojovnik-> speed;
        cout << "Zadej sanci na kriticky zasah: ";
        cin >>bojovnik-> critical_chance;
        fighters.push_back(bojovnik );
    }

    void makeNewRandomFighter(string name){
        shared_ptr<fighter> bojovnik = make_shared<fighter>();
        bojovnik->fighter_name = name;
        bojovnik-> HP = rand()% 100 + 1;
        bojovnik-> attack= rand()% 20 + 1;
        bojovnik-> armor= rand();
        bojovnik-> dodge= rand();
        bojovnik-> speed= rand()% 100 + 1;
        bojovnik-> critical_chance= rand();
        fighters.push_back(bojovnik );
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
        cout << "Uhyb: " << bojovnik->dodge << endl;
        cout << "Rychlost: " << bojovnik->speed << endl;
        cout << "Sance na kriticky zasah: " << bojovnik->critical_chance << endl;
    }

private:
    vector<shared_ptr<fighter>> fighters;
};