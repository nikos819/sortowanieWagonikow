Sortowanie Wagoników
Program w języku C++ służący do wczytywania, sortowania, wyświetlania oraz zapisywania liczb.

Projekt wykorzystuje listę jednokierunkową oraz sortowanie bąbelkowe z zamianą elementów poprzez przepinanie wskaźników.

Działanie programu
Po uruchomieniu pojawia się menu:

1 - wczytaj
2 - sortuj
3 - wypisz
4 - zapisz
0 - wyjście

Użytkownik może wykonywać poszczególne operacje w dowolnej kolejności.

Wczytywanie
Opcja 1 wczytuje liczby z pliku:

a.txt

Każda liczba jest zapisywana w osobnym elemencie listy.

Przykładowe dane:

8 3 6 1 9 2 5

Lista w pamięci wygląda wtedy następująco:

8 -> 3 -> 6 -> 1 -> 9 -> 2 -> 5 -> NULL

Sortowanie
Opcja 2 uruchamia sortowanie bąbelkowe.

Elementy są porównywane ze sobą, a jeżeli znajdują się w złej kolejności, przepinane są ich wskaźniki.

Przykład:

Przed:
8 -> 3 -> 6 -> 1 -> 9

Po:
1 -> 3 -> 6 -> 8 -> 9

Wyświetlanie
Opcja 3 wyświetla wszystkie elementy znajdujące się aktualnie w liście.

Przykład:

1 3 6 8 9

Zapisywanie
Opcja 4 zapisuje aktualną zawartość listy do pliku:

b.txt

Struktura danych
Każdy element listy jest przechowywany w strukturze:

struct _kolejka
{
    int a;
    struct _kolejka *next;
};

a przechowuje liczbę, a next wskazuje na następny element listy.

Wykorzystane zagadnienia
W projekcie zostały wykorzystane:

klasy,

struktury,

wskaźniki,

lista jednokierunkowa,

dynamiczna alokacja pamięci,

new i delete,

odczyt i zapis do plików,

instrukcja switch,

pętle,

sortowanie bąbelkowe,

konstruktor i destruktor.

Pliki
a.txt - dane wejściowe
b.txt - dane wyjściowe

Autor
Nikodem Klatka

Projekt wykonany w języku C++.
