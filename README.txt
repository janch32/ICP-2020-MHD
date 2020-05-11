                                ================
                                 ICP 2020 - MHD
                                ================

Popis
=====
Projekt do předmětu Seminář C++ (ICP). Aplikace pro zobrazení linek hromadné
dopravy a simulace jejich pohybu na dané mapě.


Autoři
======
Jan Chaloupka (xchalo16)
Michal Krůl (xkrulm00)


Spuštění
========
Ve složce "examples" jsou ukázkové konfigurační soubory simulace. Po spuštění
aplikace jsou automaticky načteny. Z kontextové nabídky lze načíst jiné (nebo
stejné) soubory simulace.

Při načtení se vybírá celá složka, kde jsou soubory simulace uloženy. Soubory
musí mít pevně dané názvy:

 - streets.csv obsahuje definice ulic
 - lines.csv obsahuje definie linek
 - routes.csv obsahuje trasy linek
 - timetable.csv obsahuje jízdní řád všech linek

Pokud některý soubor bude chybět, nečtení nebude dokončeno. Lze také provést
rychlonačtení otevřené simulace opět přes kontextovou nabídku nebo stiskem
klávesy F5. Tíme se zároveň resetuje simulace na výchozí hodnotu.


Ovládání
========
Kolečkem myši lze mapu přibližovat nebo oddalovat. Kliknutím na spoj se zobrazí
jeho itinerář na pravé straně aplikace. Kliknutím na ulici lze měnit provoz na
této ulici. Provoz je indikován zbravením ulice (pokud není vybrána) - čím víc
je ulice zbarvená do červena, tím je provoz hustější.
