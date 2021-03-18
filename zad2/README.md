# Bartłomiej Rasztabiga 304117

# Link do repozytorium:

[https://gitlab-stud.elka.pw.edu.pl/brasztab/proi-lab]()

# Zadanie

## Wariant B2

treść zadania

# Środowisko:

## Linux (Manjaro)

IDE: Jetbrains CLion 2020.3.2

Kompilator: gcc 10.2.0

# Testowanie

Uruchomienie testów:
```bash
cmake --build ./cmake-build-debug --target Doctest_tests_run
./cmake-build-debug/Doctest_tests/Doctest_tests_run
```

Uruchomienie programu:
```bash
cp dane.txt cmake-build-debug/
cmake --build ./cmake-build-debug --target Chart_run
./cmake-build-debug/Chart_run
```