#include <iostream>
#include <fstream>

using namespace std;


// Tworzymy strukturê jednego elementu kolejki/listy
struct _kolejka
{
    int a;                  // tutaj przechowujemy liczbe
    struct _kolejka *next; // wskaznik na nastepny element
};


class sortowanie
{
    int ile;                    // ilosc elementow w kolejce
    struct _kolejka *kolejka;  // wskaznik na pierwszy element kolejki

public:

    // Konstruktor, na poczatku kolejka jest pusta
    // i liczba elementow wynosi 0
    sortowanie():
        kolejka(NULL),
        ile(0)
    {};


    // Destruktor
    // Usuwamy wszystkie elementy kolejki z pamieci
    ~sortowanie()
    {
        // Dopoki kolejka nie jest pusta
        while (kolejka != NULL)
        {
            // Tworzymy pomocniczy wskaznik na pierwszy element
            _kolejka *temp = kolejka;

            // Przesuwamy poczatek kolejki na nastepny element
            kolejka = kolejka->next;

            // Usuwamy poprzedni element z pamieci
            delete temp;
        }
    }


    // Funkcja sortowania babelkowego
    void sort_bubble()
    {
        // Jezeli kolejka jest pusta albo ma tylko jeden element,
        // to nie ma czego sortowac
        if (kolejka == NULL || kolejka->next == NULL)
        {
            return;
        }

        // Ta zmienna sprawdza czy byla jakas zamiana
        bool zamiana;

        // Petla wykonuje sie dopoki byly zamiany
        do
        {
            // Na poczatku zakladamy, ze nie bylo zamiany
            zamiana = false;

            // Wskaznik na element poprzedni
            // Na poczatku nic nie jest przed pierwszym elementem
            _kolejka *poprzedni = NULL;

            // Wskaznik na aktualnie sprawdzany element
            _kolejka *aktualny = kolejka;


            // Sprawdzamy element aktualny i element po nim
            while (aktualny->next != NULL)
            {
                // Wskaznik na element znajdujacy sie za aktualnym
                _kolejka *nastepny = aktualny->next;


                // Jezeli aktualna liczba jest wieksza od nastepnej,
                // to trzeba zamienic ich kolejnosc
                if (aktualny->a > nastepny->a)
                {
                    // Aktualny wskazuje teraz na element za nastepnym
                    aktualny->next = nastepny->next;

                    // Nastepny element wskazuje teraz na aktualny
                    nastepny->next = aktualny;


                    // Jezeli zamieniamy pierwszy i drugi element
                    if (poprzedni == NULL)
                    {
                        // Nastepny staje sie pierwszym elementem kolejki
                        kolejka = nastepny;
                    }
                    else
                    {
                        // W innym przypadku poprzedni element
                        // wskazuje teraz na nastepny
                        poprzedni->next = nastepny;
                    }


                    // Zostala wykonana zamiana
                    zamiana = true;

                    // Przesuwamy poprzedni na nastepny element
                    poprzedni = nastepny;
                }
                else
                {
                    // Jezeli nie trzeba bylo zamieniac,
                    // przesuwamy wskazniki dalej
                    poprzedni = aktualny;
                    aktualny = aktualny->next;
                }
            }

        // Jezeli byla zamiana, robimy kolejna petle
        } while (zamiana);
    }


    // Funkcja wyswietlajaca wszystkie liczby z kolejki
    void wypisz()
    {
        // Tworzymy pomocniczy wskaznik na poczatek kolejki
        _kolejka *temp = kolejka;


        // Dopoki nie dojdziemy do konca kolejki
        while (temp != NULL)
        {
            // Wyswietlamy liczbe z aktualnego elementu
            cout << temp->a << " ";

            // Przechodzimy do nastepnego elementu
            temp = temp->next;
        }

        // Przechodzimy do nowej linii
        cout << endl;
    }


    // Funkcja wczytujaca liczby z pliku
    void wczytaj()
    {
        // Tworzymy plik do odczytu
        ifstream plik2;

        // Otwieramy plik
        plik2.open("E:\\4tp\\piasd\\sortowanieWagonikow\\a.txt");


        // Sprawdzamy czy plik zostal poprawnie otwarty
        if (plik2.good())
        {
            // Zmienna do przechowywania wczytanej liczby
            int liczba;


            // Wczytujemy liczby dopoki sa w pliku
            while (plik2 >> liczba)
            {
                // Tworzymy nowy element kolejki
                _kolejka *nowy = new _kolejka;

                // Wpisujemy wczytana liczbe do elementu
                nowy->a = liczba;

                // Nowy element na poczatku nie wskazuje na nic
                nowy->next = NULL;


                // Jezeli kolejka jest pusta
                if (kolejka == NULL)
                {
                    // Nowy element staje sie pierwszym elementem
                    kolejka = nowy;
                }
                else
                {
                    // Tworzymy pomocniczy wskaznik
                    _kolejka *temp = kolejka;


                    // Przechodzimy na sam koniec kolejki
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }


                    // Ostatni element wskazuje na nowy
                    temp->next = nowy;
                }


                // Zwiekszamy liczbe elementow
                ile++;
            }
        }


        // Zamykamy plik
        plik2.close();
    }


    // Funkcja zapisujaca kolejke do pliku
    void zapisz()
    {
        // Tworzymy plik do zapisu
        ofstream plik;

        // Otwieramy plik
        plik.open("E:\\4tp\\piasd\\sortowanieWagonikow\\b.txt");


        // Sprawdzamy czy plik zostal poprawnie otwarty
        if (!plik.good())
        {
            cout << "Nie udalo sie otworzyc pliku!" << endl;

            // Konczymy funkcje jezeli nie udalo sie otworzyc pliku
            return;
        }


        // Pomocniczy wskaznik na poczatek kolejki
        _kolejka *temp = kolejka;


        // Przechodzimy przez cala kolejke
        while (temp != NULL)
        {
            // Zapisujemy liczbe do pliku
            plik << temp->a << " ";

            // Przechodzimy do nastepnego elementu
            temp = temp->next;
        }


        // Zamykamy plik
        plik.close();
    }


    // Funkcja z menu programu
    void menu()
    {
        // Zmienna przechowujaca wybor uzytkownika
        int wybor;


        // Petla wykonuje menu dopoki uzytkownik nie wybierze 0
        do
        {
            cout << endl;

            cout << "1-wczytaj" << endl;
            cout << "2-sortuj" << endl;
            cout << "3-wypisz" << endl;
            cout << "4-zapisz" << endl;
            cout << "0-wyjscie" << endl;


            // Pobieramy wybor uzytkownika
            cin >> wybor;


            // Sprawdzamy co wybral uzytkownik
            switch(wybor)
            {
                case 1:

                    // Wczytujemy dane z pliku
                    wczytaj();

                    break;


                case 2:

                    // Sortujemy dane
                    sort_bubble();

                    break;


                case 3:

                    // Wyswietlamy dane
                    wypisz();

                    break;


                case 4:

                    // Zapisujemy dane do pliku
                    zapisz();

                    break;


                case 0:

                    // Koniec programu
                    cout << "Koniec programu." << endl;

                    break;


                default:

                    // Jezeli uzytkownik wpisal cos innego niz 0-4
                    cout << "Nieprawidlowy wybor!" << endl;
            }


        // Jezeli wybor jest inny niz 0, menu pojawi sie ponownie
        } while(wybor != 0);
    }

};


// Glowna funkcja programu
int main()
{
    // Tworzymy obiekt klasy sortowanie
    sortowanie s;


    // Uruchamiamy menu
    s.menu();


    // Konczymy program
    return 0;
}
