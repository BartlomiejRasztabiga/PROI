# Bartłomiej Rasztabiga 304117

# Link do repozytorium:

[https://gitlab-stud.elka.pw.edu.pl/brasztab/proi-lab]()

# Zadanie

## Wariant B2

B - obliczający średnią cenę sprzedanych pojazdów (z zaokrągleniem do całkowitych liczb) oraz odchylenie dla poszczególnych "Marka Wersja".

2 - narysować wykres słupkowy (w trybie tekstowym) sumy sprzedanych pojazdów w funkcji miesięcy.

# Środowisko:

## Linux (Manjaro)

IDE: Jetbrains CLion 2020.3.2

Kompilator: gcc 10.2.0

# Testowanie

Do napisania i wykonania testów użyłem biblioteki DocTest w formie załączonego jednego pliku nagłówkowego: `Doctest_tests/doctest.h`

Uruchomienie testów:

```bash
cmake --build ./cmake-build-debug --target Doctest_tests_run
./cmake-build-debug/Doctest_tests/Doctest_tests_run
```

Uruchomienie programu:

```bash
cp dane.txt cmake-build-debug/
cmake --build ./cmake-build-debug --target Chart_run
./cmake-build-debug/Chart_run dane.txt
```

# Przeciążenie operatorów `<<` i `>>`
## `<<`
Operator ten przeciążyłem aby przesyłać na podany strumień dane, które powinny być wyliczone zgodnie z wariantem zadania (B2), czyli:
- średnia cena sprzedanych pojazdów
- lista pojazdów (skrótów) z odchyleniem ceny od średniej

## `>>`
Ten operator został przeciążony aby pobierać dane pojazdów w formie podanej w pliku (dane.txt). Program oczekuje co najmniej jednego pełnego pojazdu.