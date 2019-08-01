/*
MAIN file
 */
#include "header.h"
#include "include.h"
bool run = true;
string name_of_fighter;
int test;
int temp_number;;

void menu(){
    cout << "(1) Zacni souboj s nahodnym protivnikem.\n";
    cout << "(2) Statistiky meho bojovnika.\n";
    cout << "(3) Statistiky konkretniho bojovnika.\n";
    cout << "(4) Vygeneruj nahodneho soupere.\n";
    cout << "(5) Vypis bojovniky.\n";
    cout << "(6) Konec.\n";
}


int main (){
    people bojovnici;
    cout << "Vitejte v simulatoru Battle Areny! Nejprve si vytvorte sveho bojovnika.\n";
    cout << "Pojmenuj bojovnika: ";
    cin >> name_of_fighter;
    bojovnici.makeNewFighterByHand(name_of_fighter);
     while(run){
         menu();
         cin >> test;
        switch (test)
        {
        case 1:
            break;
        case 2:
            bojovnici.stats(0);
            break;
        case 3:
            bojovnici.showFighters();
            cout << "Kolikaty bojovnik by to mel byt?\n";
            cin >> temp_number;
            bojovnici.stats(temp_number);
            break;
        case 4:
            cout << "Pojmenuj bojovnika: ";
            cin >> name_of_fighter;
            bojovnici.makeNewRandomFighter(name_of_fighter);
            break;
        case 5:
            bojovnici.showFighters();
            break;
        case 6:
            run = false;
            break;
        
        default:
            break;
        }
    }


    return 0;
}