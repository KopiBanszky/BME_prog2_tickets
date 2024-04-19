# Házi feladat

### Programozás alapjai 2

### Bánszky Koppány - KK4UWP

# Vonatjegy

## Feladat

Tervezze meg egy vonatjegy eladó rendszer egyszerűsített objektummodelljét, majd valósítsa azt meg! A vonatjegy a feladatban mindig jegyet és helyjegyet jelent együtt. Így egy jegyen minimum a következőket kell feltüntetni:

- vonatszám, kocsiszám, hely  
- indulási állomás, indulási idő  
- érkezési állomás, érkezési idő

A rendszerrel minimum a következő műveleteket kívánjuk elvégezni:

- vonatok felvétele  
- jegy kiadása  

A rendszer később lehet bővebb funkcionalitású (pl. késések kezelése, vonat törlése, menetrend, stb.), ezért nagyon fontos, hogy jól határozza meg az objektumokat és azok felelősségét.
Valósítsa meg a jeggyel végezhető összes értelmes műveletet operátor átdefiniálással (overload), de nem kell ragaszkodni az összes operátor átdefiniálásához! A megoldáshoz ne használjon STL tárolót!

## Specifikáció

A program kiinduló pontja egy menü. Itt 3 opció közül lehet választani, a megfelelő billentyűk lenyomásával. Mind a 3 opció megjelenik a képernyőn:

- Jegyvásárlás (`j`)
- Vonat felvétele (`n`)
- Állomás felvétele (`s`)

### Jegyvásárlás

A jegyvásárlás menüponton belül az alábbi működés legyen érvényes:  

  1. Be kell írni egy, az indoló állomás nevét a keresőbe. A bemenetnek ne legyen karakter korlátja, illetve a továbbiakban se legyen szöveg bemenetnek karakterkorlátja. (Ezt nem fogom mindig kiemelnni)
  1. A kimenetre sorolja fel az összes olyan állomást, ami a bemenethez hasonló. Ha nincs semmilyen hasonlóság, jelezze a felhasználó felé és kérje újra a keresést. Balra, az állomásnév mellett legyen 1-n-ig sorszámozva a felsorolás.
  1. A megfelelő szám beírásával véglegesíthető a kiinduló állomás
  1. Ugyan ezt ismételje az érkezési állomáshoz.
  1. Miután mindkét állomás megnevezésre került, listázza a kimenetre az elérhető járatokat. Jelenjen meg a járatszám, indulási, érkezési idő, valamint ugyancsak bal oldalt 1-n ig számozás.
  1. Szintén a megfelelő szám beírásával lehet választani.
  1. Választás után a bemenetre kérjen egy teljes nevet, majd minden paraméterével mutassa meg a jegyet a kimenet. Helyet sorsol, viszont ha a vonat megtelt, jelzi azt a kimeneten.

### Vonat felvétele

A vonatok felvétele a következőképp zajlik:

1. A menüben meg kell adni egy vonat azonosítót, amely maximum 6 karaktert tartalmazhat.
1. Ezután meg kell adni hány kocsival fog közlekedni az adott járat. (Egy kocsi általánosítva 35 fővel bír.)
1. Minden állomás egy 1-n ig tartó számozással megjelenik a kimeneten. A számokat egymás után beírva lehet megadni, hogy a árat hol közlekedik. Minden szám beírása után meg kell adni az adott állomásról az indulás időpontját `18:50`-es formátumban.
1. A végállomás után -1 beírásával lehet menteni.

### Állomás felvétele

Az állomásfelvételekor csupán egy nevet kell megadni, amivel lehet az állomásra hivatkozni. Ha az adott név már létezik, jelezze a kimeneten és kérjen újat.

A bevitt adatokat a program hosszútávon tárolja, nem vesznek el a leállítást követően.


## Terv
