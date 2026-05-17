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
        else cout << "*Hladovi vlci a ceni zuby*" << endl;
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
        if (r == 0) cout << "\"Pridas se k nasi mrtve armade...\"" << endl;
        else if (r == 1) cout << "\"Citim teplo tveho zivota... chci ho!\"" << endl;
        else cout << "*Chrasti kostmi a kvili*" << endl;
    }
    else if (jmeno == "Temny Mag") {
        if (r == 0) cout << "\"Tva duse bude ma!\"" << endl;
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
    cout << " NEPRITEL: " << jmeno << " [HP: " << hpM << "]" << endl;
    cout << " HRAC: [HP: " << hpA << " | MANA: " << mana << "]" << endl;
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
        cout << "=== VYBER HRDINY ===\n1) Rytir\n2) Mag\n3) Lovec\nVolba: ";
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

    // SOUBOJE

    // 2. MONSTRUM (50% šance na zlato)
    int m1 = 20;
    while (m1 > 0 && aHP > 0) {
        status("Vlk", m1, aHP, aMana);
        hradlaMonster("Vlk");
        cout << "1) Utok, 2) Kouzlo(5m): "; cin >> v;
        if (v == 1) m1 -= utok;
        else if (v == 2 && aMana >= 5) { m1 -= secti(utok, 10); aMana -= 5; }
        if (m1 > 0) aHP -= 6;
    }
    if (aHP <= 0) return 0;
    xp += 30; if (rand() % 2 == 0) zlato += 15;
    zkontrolujLevel(lvl, xp, mHP, aHP, utok);

    // 3. SOUBOJ SE 3 MONSTRY
    int h1 = 15, h2 = 15, h3 = 15;
    cout << "\n[3xM] SMECKA HYEN" << endl;
    while ((h1 > 0 || h2 > 0 || h3 > 0) && aHP > 0) {
        cout << "H1: " << h1 << " | H2: " << h2 << " | H3: " << h3 << " | HP: " << aHP << endl;
        cout << "1) H1, 2) H2, 3) H3, 4) Plosne(10m): "; cin >> v;
        if (v == 1 && h1 > 0) h1 -= utok;
        else if (v == 2 && h2 > 0) h2 -= utok;
        else if (v == 3 && h3 > 0) h3 -= utok;
        else if (v == 4 && aMana >= 10) { h1 -= 12; h2 -= 12; h3 -= 12; aMana -= 10; }
        if (h1 > 0) aHP -= 2; if (h2 > 0) aHP -= 2; if (h3 > 0) aHP -= 2;
    }
    if (aHP <= 0) return 0;
    xp += 50; if (rand() % 2 == 0) zlato += 20;
    zkontrolujLevel(lvl, xp, mHP, aHP, utok);

    // 4. MINI BOSS
    int mb1 = 100;
    cout << "\n[MB] STRAZCE MOSTU" << endl;
    while (mb1 > 0 && aHP > 0) {
        aHP -= 10; cout << "Troll te prastil palici jako prvni!" << endl;
        if (aHP <= 0) break;
        status("Troll", mb1, aHP, aMana);
        hradlaMonster("Troll");
        cout << "1) Utok, 2) Heal(8m): "; cin >> v;
        if (v == 1) mb1 -= utok;
        else if (v == 2 && aMana >= 8) { aHP = secti(aHP, 25); if(aHP > mHP) aHP = mHP; aMana -= 8; }
    }
    if (aHP <= 0) return 0;
    xp += 100; zlato += 100;
    zkontrolujLevel(lvl, xp, mHP, aHP, utok);

    return 0;
}
