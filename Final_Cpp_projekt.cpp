#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand (time(0));

    //PROMENNE POSTAVY
    string jmenoClassy = "";
    int maximalniZivoty = 0, aktualniZivoty = 0;
    int maximalniMana = 0, aktualniMana = 0;
    int zlato = 10, level = 1, zkusenosti = 0, hracUtok = 0;

    int volbaHrace = 0;
    bool potvrzeniClassy = false;

    //VOLBA POSTAVY
    while (potvrzeniClassy == false) {
        cout << "=== VITEJTE V TEXTOVEM RPG ===" << endl;
        cout << "Vyberte si svoji classu (tridu):" << endl;
        cout << "1) Paladin" << endl;
        cout << "2) Mag" << endl;
        cout << "3) Lovec" << endl;
        cout << "Vase volba: ";
        cin >> volbaHrace;

        if (volbaHrace == 1) {
            jmenoClassy = "Paladin"; maximalniZivoty = 20; maximalniMana = 10; hracUtok = 4;
        } else if (volbaHrace == 2) {
            jmenoClassy = "Mag"; maximalniZivoty = 12; maximalniMana = 25; hracUtok = 2;
        } else if (volbaHrace == 3) {
            jmenoClassy = "Lovec"; maximalniZivoty = 16; maximalniMana = 15; hracUtok = 5;
        }

        aktualniZivoty = maximalniZivoty;
        aktualniMana = maximalniMana;

        cout << "\nClass: " << jmenoClassy << endl;
        cout << "Statistiky:" << endl;
        cout << "  Zivot - " << aktualniZivoty << "/" << maximalniZivoty << endl;
        cout << "  Utok  - " << hracUtok << endl;
        cout << "  Mana  - " << aktualniMana << "/" << maximalniMana << endl;
        cout << "\nSchopnosti:" << endl;
        cout << "  1. Zakladni utok - Uder za " << hracUtok << " poskozeni" << endl;
        cout << "  2. Specialni uder - Poskozeni vsem (stoji 3 many)" << endl;
        cout << "  3. Odpocinek - Prida 5 HP (stoji 2 many)" << endl;

        cout << "\nChcete potvrdit vyber teto classy? (1-Ano / 0-Zvolit jinou): ";
        int potvrdit;
        cin >> potvrdit;
        if (potvrdit == 1) potvrzeniClassy = true;

        return 0;
    }
}
