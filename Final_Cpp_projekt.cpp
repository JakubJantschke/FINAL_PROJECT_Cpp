#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// funkce pro vykresleni uvodniho loga
void uvodniGrafika() {
    cout << "########################################################" << endl;
    cout << "#                                                      #" << endl;
    cout << "#    _______  __   __  ______    _______  _______      #" << endl;
    cout << "#   |       ||  | |  ||    _ |  |       ||       |     #" << endl;
    cout << "#   |    _  ||  |_|  ||   | ||  |   _   ||_     _|     #" << endl;
    cout << "#   |   |_| ||       ||   |_||_ |  | |  |  |   |       #" << endl;
    cout << "#   |    ___||_     _||    __  ||  |_|  |  |   |       #" << endl;
    cout << "#   |   |      |   |  |   |  | ||       |  |   |       #" << endl;
    cout << "#   |___|      |___|  |___|  |_||_______|  |___|       #" << endl;
    cout << "#                                                      #" << endl;
    cout << "#             LEGENDA O OHNIVEM DRAKOVI                #" << endl;
    cout << "#                                                      #" << endl;
    cout << "########################################################" << endl;
    cout << endl;
    cout << "Vitej, hrdino! Tva cesta za porazkou Pyrocoila zacina..." << endl;
    cout << "Stiskni ENTER pro vstup do sveta!" << endl;
    cin.get(); // Pocka na stisk klavesy
}

// FUNKCE PRO VYPOCET (RETURN)
int secti(int a, int b) {
    return a + b;
}

// FUNKCE PRO HLÁŠKY MONSTER (VOID)
// Tato funkce vybere náhodnou hlášku podle typu monstra
void hradlaMonster(string jmeno) {
    int r = rand() % 3; // náhodné èíslo 0-2
    cout << jmeno << " krici: ";

    if (jmeno == "Vlk" || jmeno == "Divoke prase") {
        if (r == 0) cout << "\"Vrrr... citim tvou krev!\"" << endl;
        else if (r == 1) cout << "\"Haf! Tohle bude snadna korist.\"" << endl;
        else cout << "*Hladove vrèí a cení zuby*" << endl;
    }
    else if (jmeno == "Skret" || jmeno == "Loupeznik") {
        if (r == 0) cout << "\"Dej sem zlato, nebo te rozsekam!\"" << endl;
        else if (r == 1) cout << "\"Hele kluci, dalsi hloupy dobrodruh!\"" << endl;
        else cout << "\"Tvoje boty se mi budou hodit!\"" << endl;
    }
    else if (jmeno == "Troll") {
        if (r == 0) cout << "\"Tamaten hnufak cufak chce nasejc zlato-sutry, majznu ho palici!\"" << endl;
        else if (r == 1) cout << "\"Uvarim si z tebe gulas!\"" << endl;
        else cout << "\"Krupni, krupni, tvoje kosti jsou jako susenky!\"" << endl;
    }
    else if (jmeno == "Kostlivec" || jmeno == "Duch") {
        if (r == 0) cout << "\"Pridáš se k nasi mrtve armade...\"" << endl;
        else if (r == 1) cout << "\"Citim teplo tveho zivota... chci ho!\"" << endl;
        else cout << "*Chrastí kostmi a kvílí*" << endl;
    }
    else if (jmeno == "Temny Mag") {
        if (r == 0) cout << "\"Tva duše bude ma!\"" << endl;
        else if (r == 1) cout << "\"Neznas skutecnou silu temnoty!\"" << endl;
        else cout << "\"Tvoje magie je proti me jen hracka.\"" << endl;
    }
    else if (jmeno == "PYROCOIL") {
        if (r == 0) cout << "\"VSECHNO SHORI V MEM PLAMENI!\"" << endl;
        else if (r == 1) cout << "\"Jsi jen prach pod mými paznehty!\"" << endl;
        else cout << "\"KONEC TVE CESTY JE TADY!\"" << endl;
    }
}

// FUNKCE PRO VYPIS STAVU (VOID)
void status(string jmeno, int hpM, int hpA, int mana) {
    cout << "\n------------------------------------------------" << endl;
    cout << " NEPØÍTEL: " << jmeno << " [HP: " << hpM << "]" << endl;
    cout << " HRÁÈ: [HP: " << hpA << " | MANA: " << mana << "]" << endl;
    cout << "------------------------------------------------" << endl;
}

// KONTROLA ZLATA (BOOL)
bool maDostZlata(int hracZlato, int cena) {
    if (hracZlato >= cena) return true;
    cout << "Nedostatek zlata! Chybi: " << cena - hracZlato << endl;
    return false;
}

// LEVEL UP (REFERENCE &)
void zkontrolujLevel(int &lvl, int &xp, int &mHP, int &aHP, int &u) {
    if (xp >= 50) {
        lvl = secti(lvl, 1);
        xp = 0;
        mHP = secti(mHP, 15);
        aHP = mHP;
        u = secti(u, 3);
        cout << "\n>>> LEVEL UP! Nyni uroven " << lvl << " <<<" << endl;
    }
}

// MAIN
int main() {
    srand(time(0));
    uvodniGrafika();

    string trida = "";
    int mHP, aHP, mMana, aMana, zlato = 40, lvl = 1, xp = 0, utok = 0, v;

    // VÝBĚR POSTAVY POMOCÍ SWITCH-CASE (Skočí zpět na začátek while)
    bool vybrano = false;
    while (!vybrano) {
        cout << "=== VÝBĚR HRDINY ===\n1) Rytir\n2) Mag\n3) Lovec\nVolba: ";
        cin >> v;

        switch (v) {
            case 1:
                trida = "Rytir"; mHP = 60; mMana = 10; utok = 7;
                break;
            case 2:
                trida = "Mag"; mHP = 30; mMana = 60; utok = 4;
                break;
            case 3:
                trida = "Lovec"; mHP = 45; mMana = 30; utok = 10;
                break;
            default:
                cout << "Neplatna volba, zkus to znovu." << endl;
                continue;
        }

        cout << "Zvolen " << trida << ". OK? (1-ano): ";
        cin >> v;
        if (v == 1) vybrano = true;
    }
    aHP = mHP; aMana = mMana;

    // VESNICE POMOCÍ SWITCH-CASE
    cout << "\n[V] OSADA POCATKU" << endl;
    bool shop = true;
    while (shop) {
        cout << "Gold: " << zlato << " | 1) Heal(5g), 2) Utok+2(20g), 3) Jít pryč: ";
        cin >> v;

        switch (v) {
            case 1:
                if (maDostZlata(zlato, 5)) { aHP = mHP; zlato -= 5; cout << "Vyleceno!" << endl; }
                break;
            case 2:
                if (maDostZlata(zlato, 20)) { utok = secti(utok, 2); zlato -= 20; cout << "Utok zvysen!" << endl; }
                break;
            case 3:
                shop = false;
                break;
            default:
                cout << "Neznamy prikaz." << endl;
                break;
        }
    }

    return 0;
}
