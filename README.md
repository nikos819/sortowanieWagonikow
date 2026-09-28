# Sortowanie Wagoników

Program napisany w języku C++, służący do wczytywania, sortowania, wyświetlania oraz zapisywania liczb.

Projekt wykorzystuje **listę jednokierunkową** oraz **sortowanie bąbelkowe** z przepinaniem wskaźników.

## Działanie programu

Po uruchomieniu programu wyświetla się menu:

1 - wczytaj
2 - sortuj
3 - wypisz
4 - zapisz
0 - wyjście

Program pozwala wykonywać operacje wielokrotnie, aż użytkownik wybierze opcję `0`.

## Wczytywanie danych

Opcja `1` pozwala wczytać liczby z pliku `a.txt`.

Przykładowa zawartość pliku:

8 3 6 1 9 2 5

Po wczytaniu dane są przechowywane w postaci listy jednokierunkowej:

8 -> 3 -> 6 -> 1 -> 9 -> 2 -> 5 -> NULL

## Sortowanie

Opcja `2` uruchamia sortowanie bąbelkowe.

W przypadku znalezienia elementów w złej kolejności program przepina ich wskaźniki `next`.

### Przykład

Przed sortowaniem:

8 -> 3 -> 6 -> 1 -> 9

Po sortowaniu:

1 -> 3 -> 6 -> 8 -> 9

## Wyświetlanie danych

Opcja `3` wyświetla wszystkie liczby znajdujące się aktualnie w liście.

Przykład:

1 3 6 8 9

## Zapisywanie danych

Opcja `4` zapisuje aktualne dane do pliku `b.txt`.

Przykładowa zawartość pliku:

1 3 6 8 9

## Struktura danych

Każdy element listy jest przechowywany w strukturze:

struct _kolejka
{
    int a;
    struct _kolejka *next;
};

Pole `a` przechowuje liczbę, a `next` jest wskaźnikiem na następny element listy.

## Wykorzystane zagadnienia

- klasy
- struktury
- wskaźniki
- lista jednokierunkowa
- dynamiczna alokacja pamięci
- `new` i `delete`
- obsługa plików
- `ifstream` i `ofstream`
- pętle
- instrukcja `switch`
- sortowanie bąbelkowe
- konstruktor
- destruktor

## Pliki

### a.txt

Plik zawierający dane wejściowe programu.

### b.txt

Plik, do którego zapisywane są dane po wykonaniu operacji zapisu.

## Autor

**Nikodem Klatka**

Projekt wykonany w języku C++.
