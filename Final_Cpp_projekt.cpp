#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// funkce pro vykresleni uvodniho loga
void uvodniGrafika() {
    cout << "========================================================================" << endl;
    cout << "  __  __     ____    _____     ____    _   _    _____   _    _    _____ " << endl;
    cout << " |  \\/  |   / __ \\  |  __ \\   / __ \\  | \\ | |  |_   _| | |  | |  / ____|" << endl;
    cout << " | \\  / |  | |  | | | |__) | | |  | | |  \\| |    | |   | |  | | | |     " << endl;
    cout << " | |\\/| |  | |  | | |  _  /  | |  | | | . ` |    | |   | |  | | | |     " << endl;
    cout << " | |  | |  | |__| | | | \\ \\  | |__| | | |\\  |   _| |_  | |__| | | |____ " << endl;
    cout << " |_|  |_|   \\____/  |_|  \\_\\  \\____/  |_| \\_|  |_____|  \\____/   \\_____|" << endl;
    cout << "========================================================================" << endl;
    cout << "                   L E G E N D A   O   P Y R O C O I L O V I            " << endl;
    cout << "========================================================================" << endl;
    cout << endl;
    cout << "       Vitej v kralovstvi Ignis, hrdino! Tva dračí odysea zacina.       " << endl;
    cout << "       Dokazes porazit Pyrocoila, nebo skoncis v jeho plamenech?       " << endl;
    cout << endl;
    cout << "========================================================================" << endl;
    cout << "         >>> STISKNI ENTER PRO ZACATEK DOBRODRUZSTVI <<< " << endl;
    cout << "========================================================================" << endl;
    cin.get(); // Pocka na stisk klavesy
}

// FUNKCE PRO VYPOCET (RETURN)
int secti(int a, int b) {
    return a + b;
}

// FUNKCE PRO HLÁŠKY MONSTER (VOID)
// Tato funkce vybere náhodnou hlášku podle typu monstra
void hradlaMonster(string jmeno) {
    int r = rand() % 3; // náhodné číslo 0-2
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

    // --- ROZVINUTÁ VESNICE POMOCÍ SWITCH-CASE ---
    cout << "\n========================================================================" << endl;
    cout << "[V] OSADA POCATKU - Posledni bezpecne utociste na upati Ohnive hory." << endl;
    cout << "Kolem tebe chodi vystraseni vesnicane a mistni kovar kuje posledni zbrane." << endl;
    cout << "Mas s sebou nejake usetrene zlate mince. Vyuzij je moudre, nez odejdes!" << endl;
    cout << "========================================================================" << endl;

    bool shop = true;
    while (shop) {
        cout << "\n--- MISTNI TRH (Tvoje zlato: " << zlato << "g | Utok: " << utok << " | HP: " << aHP << "/" << mHP << ") ---" << endl;
        cout << "1) Elixir zivota (Plne vyleceni) ---------- [5g]\n";
        cout << "2) Nabrousit zbran / Novy ritualni amulet (+2 utok) -- [20g]\n";
        cout << "3) OPUSTIT VESNICI A VYKROCIT DO NEBEZPECI\n";
        cout << "Tva volba: ";
        cin >> v;

        switch (v) {
            case 1:
                if (maDostZlata(zlato, 5)) {
                    aHP = mHP;
                    zlato -= 5;
                    cout << "\n>>> Vypil jsi rudy elixir. Citis, jak se ti hoji vsechny rany!" << endl;
                }
                break;
            case 2:
                if (maDostZlata(zlato, 20)) {
                    utok = secti(utok, 2);
                    zlato -= 20;
                    cout << "\n>>> Tve zbrane nyni zari ostrosti a magickou moci!" << endl;
                }
                break;
            case 3:
                cout << "\nZabalil jsi sve veci, vesnicane ti pozehnali a brana osady se za tebou zavira..." << endl;
                shop = false;
                break;
            default:
                cout << "\n[!] Kovar ti nerozumi. Vyber si z nabidky 1, 2 nebo 3." << endl;
                break;
        }
    }

    cout << "\nStiskni Enter pro vstup do Temneho lesa...";

    // SOUBOJE

    // 2. MONSTRUM: VLK
    cout << "\n========================================================================" << endl;
    cout << "[!] Vstoupil jsi do hlubokeho Temneho lesa. Mlha se vali mezi stromy." << endl;
    cout << "Najednou ze kroví vyskoci obrovsky Vlk s rudyma ocima, nakrazeny Pyrocoilem!" << endl;
    cout << "========================================================================" << endl;

    int m1 = 20;
    while (m1 > 0 && aHP > 0) {
        status("Vlk v ruji", m1, aHP, aMana);
        hradlaMonster("Vlk");
        cout << "Tve moznosti: 1) Utok mecem/lukem, 2) Pouzit kouzlo (Stoji 5 many): ";
        cin >> v;

        if (v == 1) {
            m1 -= utok;
            cout << "Zasahol jsi Vlka za " << utok << " poskozeni!" << endl;
        }
        else if (v == 2 && aMana >= 5) {
            int kDMG = secti(utok, 10);
            m1 -= kDMG;
            aMana -= 5;
            cout << "Seslal jsi magicky vypad a popalil Vlka za " << kDMG << " poskozeni!" << endl;
        }
        else if (v == 2 && aMana < 5) {
            cout << "Chybi ti mana! Tvuj chaby pokus o magii selhal a ztratil jsi tah!" << endl;
        }

        if (m1 > 0) {
            aHP -= 6;
            cout << "Vlk vyrazil vpred a kousl te do nohy! Ztratil jsi 6 HP." << endl;
        }
    }

    // GAME OVER PRO VLKA
    if (aHP <= 0) {
        cout << "\n########################################################################" << endl;
        cout << " GAME OVER - TVOJE CESTA SKONCILA" << endl;
        cout << " Vlk te srazil k zemi a prokousl ti hrdlo. Tva krev zbarvila lesni mech." << endl;
        cout << " Pyrocoil stale zije a kralovstvi Ignis zustane navzdy v plamenech." << endl;
        cout << "########################################################################" << endl;
        return 0;
    }

    cout << "\n>>> Vlk pada mrtev k zemi! Ziskavas zkusenosti.";
    xp += 30;
    if (rand() % 2 == 0) {
        zlato += 15;
        cout << " V kozichu vlka jsi nasel odhozeny pytlik s 15 zlataky!";
    }
    cout << endl;
    zkontrolujLevel(lvl, xp, mHP, aHP, utok);

    cout << "\nStiskni Enter pro pokracovani hloubeji do prusmyku...";


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
    int mb1 = 50;
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

    // 5. FINAL BOSS: PYROCOIL
    // Sníženo HP bosse z 600 na 280
    int hb = 280;
    int k = 1;
    int horeni = 0;

    cout << "\n========================================================================" << endl;
    cout << "!!! [HB] OHNIVE DOUPĚ - FINALNI SOUBOJ ZE SMRTI !!!" << endl;
    cout << "Vstoupil jsi do obri jeskyne plne lavy. Ze stropu visi krystaly a na hromade" << endl;
    cout << "zlata odpociva pan ohne - obrovsky cerveny drak PYROCOIL." << endl;
    cout << "Kdyz te uvidia jeho zlute oci, jeskyni prořízne hruzny rev a vzduch zacne horet!" << endl;
    cout << "========================================================================" << endl;

    while (hb > 0 && aHP > 0) {
        cout << "\n========================================" << endl;
        cout << "KOLO BOJE: " << k;
        if (horeni > 0) cout << " | VÝSTRAHA: Horis jeste " << horeni << " kola!";
        cout << "\n========================================" << endl;

        // Pyrocoil utoci prvni (dračí rychlost)
        int dmgBosse = 12;
        if (horeni > 0) {
            dmgBosse += 3; // Pokud hráč hoří, dává drak o 3 dmg víc
            cout << "[Spalovani] Plameny na tvem tele se rozhořely víc!" << endl;
        }
        else {
            horeni = 2;
            dmgBosse += 1;
            cout << "[Zapaleni] Drak te zasahl ohnivym dechem a zapalil te na 2 kola!" << endl;
        }

        aHP -= dmgBosse;
        cout << "Pyrocoil utoci svymi pazoury a dechem za " << dmgBosse << " zraneni!" << endl;

        // Mechanika exploze kazde 4. kolo (Drak ublizi hraci, ale i sobe pretlakem many)
        if (k % 4 == 0) {
            cout << "\n[!!!] PYROCOIL PRETEKA MAGICKÝM OHNEM A EXPLOZUDE!" << endl;
            cout << "Tlakova vlna te odmrštila na skálu! Ztracis dalšich 12 HP." << endl;
            cout << "Exploze vsak poskodila i samotneho draka a ubylo mu 25 HP!" << endl;
            aHP -= 12;
            hb -= 25;
        }

        // Kontrola smrti hrace behem tahu bosse
        if (aHP <= 0) break;

        status("PYROCOIL - PAN LÁVY", hb, aHP, aMana);
        hradlaMonster("PYROCOIL");

        // Zvyseno leceni z 60 na 70 HP pro lepsi preziti hrace
        cout << "Tva akce proti drakovi: 1) Utok zbrani, 2) Mega Bozi Heal (Stoji 15 many, vyleci 70 HP): ";
        cin >> v;

        if (v == 1) {
            hb -= utok;
            cout << "Prosekal jsi se pres dračí šupiny a zpusobil mu " << utok << " poskozeni!" << endl;
        }
        else if (v == 2 && aMana >= 15) {
            aHP = secti(aHP, 70);
            if(aHP > mHP) aHP = mHP;
            aMana -= 15;
            cout << ">>> Svaté svetlo te obklopilo. Vyleceno masivnich 70 HP! Plameny zhasínají." << endl;
            horeni = 0; // Bozi heal uhasi horeni
        }
        else if (v == 2 && aMana < 15) {
            cout << "Nemas 15 many na Mega Heal! Tvuj krik zanikl v hromu jeskyne a neudelal jsi nic!" << endl;
        }

        // Odpocet horeni na konci kola
        if (horeni > 0) horeni--;
        k++;
    }

    // FINALNI GAME OVER NEBO VITEZSTVI
    if (aHP <= 0) {
        cout << "\n########################################################################" << endl;
        cout << " GAME OVER - SHOREL JSI V POPEL" << endl;
        cout << " Pyrocoil te spalil na prach svym nejvetsim ohnivym chřtánem. Tve brneni" << endl;
        cout << " se roztavilo a zbyly z tebe jen uhliky. Svet upadl do vecne temnoty draka." << endl;
        cout << "########################################################################" << endl;
    }
    else {
        cout << "\n========================================================================" << endl;
        cout << " !!! VITEZSTVI !!! " << endl;
        cout << " Pyrocoil s hroznym zarvem padl k zemi, lava v jeskyni ztuhla v kamen." << endl;
        cout << " Zachranil jsi kralovstvi Ignis a tve jmeno bude navzdy zapsano v kronikach" << endl;
        cout << " jako jmeno Nejvetsiho Hrdiny všech dob!" << endl;
        cout << "========================================================================" << endl;
    }

    cout << "\nDekujeme za odehrani hry Legenda o ohnivem drakovi. Stiskni Enter pro konec.";
    return 0;
}
