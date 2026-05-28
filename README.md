# FINAL\_PROJECT\_Cpp

FINAL\_PROJECT\_Cpp



\#INCLUDE  – Knihovna pro vstup a výstup, zajišťuje výpis textu a načítání voleb od hráče.

\#INCLUDE  – Knihovna pro práci s textovými řetězci (např. ukládání jména třídy postavy).

\#INCLUDE  – Knihovna pro přístup k systémovému času, potřebná pro generování náhodných čísel.

\#INCLUDE  – Knihovna pro funkce rand() a srand(), které zajišťují náhodu ve hře.

UVODNIGRAFIKA() – Vytiskne úvodní logo hry a počká na Enter.

SECTI() – Sečte dvě čísla (používá se pro navyšování útoku a levelu).

HRADLAMONSTER() – Vybere a vypíše náhodný křik/hlášku pro monstrum v boji.

STATUS() – Vykreslí v souboji tabulku s aktuálními životy tvými i nestvůry.

MADOSTZLATA() – Zkontroluje, zda máš v peněžence dost peněz na nákup v obchodě.

ZKONTROLUJLEVEL() – Zjistí, zda máš 50 XP, a pokud ano, zvedne ti level a staty.

\&LVL, \&XP, \&MHP, \&AHP, \&U – Symbol \& (odkaz) zajišťuje, že se změna statistik z funkce trvale uloží i do mainu.

SRAND(TIME(0)) – Nastartuje generátor náhodných čísel podle času, aby hra nebyla pokaždé stejná.

SWITCH(V) a CASE – Rozcestník, který podle zadaného čísla (1, 2, 3) okamžitě skočí na vybranou akci.

DEFAULT – Pojistka ve switchi, která se spustí, když hráč zadá neplatné číslo (např. 9).

CONTINUE – Skočí okamžitě na začátek cyklu (využívá se při špatné volbě hrdiny).

BREAK – Zastaví switch nebo cyklus a vyskočí z něj ven, aby kód nepokračoval dál.

WHILE – Smyčka, která drží hru v obchodě nebo v souboji, dokud platí daná podmínka.

TO\_STRING() – Přepíše číslo na text, aby se dalo snadno vypsat v tabulce hyen.

K % 4 == 0 – Matematický zbytek po dělení (modulo). Zjišťuje, zda je kolo dělitelné čtyřmi (spouští explozi bosse).

