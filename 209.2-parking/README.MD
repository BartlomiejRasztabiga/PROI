# Projekt parkingu samochodowego

## Lista proponowanych klas na lab3:

### Car:
klasa reprezentująca samochód

### CarPark:
Klasa ta obsługuje klasę CarParkContainer. Jest niejako jej fasadą.
Zawiera logikę biznesową parkingu:
- ilość wolnych miejsc
- ilość wszystkich miejsc
- zaparkuj samochód (automatyczne oraz na konkretnych współrzędnych)
- wyparkuj samochód
- serializacja i deserializacja parkingu do/z pliku tekstowego
- podanie drogi do wybranego miejsca

### CarParkContainer:
Klasa ta reprezentuje parking samochodowy w postaci macierzy struktur CarParkTile. Jeden element macierzy odpowiada jednej przestrzeni parkingu, która moża być samochodem, miejscem parkingowym pustym lub zajętym.

### CarParkGUI:
klasa reprezentująca parking w postaci graficznej

## Przypisanie osób do klas (zadanie 3 - laboratorium)
Car - Kuba Forczek

CarPark - Bartłomiej Rasztabiga

CarParkGui - Piotr Brzeziński

## Przykładowy plik wejściowy
```
0 2 1 2 0
0 0 0 0 0 
0 1 2 2 0
0 2 2 1 0
0 0 0 0 0 
0 2 1 2 0
```
0 - droga

1 - wolne miejsce parkingowe

2 - zajęte miejsce parkingowe

Bezpośrednia konwersja z typu wyliczeniowego `CarParkTile`

## Lista pozostałych klas do zaimplementowania w trakcie projektu: 

### ParkingSpot:
klasa reprezentująca miejsce parkingowe

### CarParkLogger:
klasa logująca (np. do pliku) operacje wykonywane w parkingu (ruchy samochodów, zmiana stanu miejsc, etc.)


### AbstractTile:
klasa abstrakcyjna reprezentująca "kratkę" na szachownicy parkingu (GUI)


### CarTile:
klasa reprezentująca miejsce samochodu na planszy parkingu, samochód może zajmować więcej niż jedną kratkę (max. 2)


### ParkingSpotTile:
klasa reprezentująca miejsce parkingowe na planszy, miejsce może zajmować więcej niż jedną kratkę


### CarParkRepository:
klasa umożliwiająca odczyt/zapis stanu parkingu np. z/do pliku

