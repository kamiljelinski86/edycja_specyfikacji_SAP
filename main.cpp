#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "parametry.h"
#include <cstdlib>
#include <sstream>
#include <ctime>
#include<algorithm>

 
using namespace std;


// DATA PLIKU
//------------------------------------------------------------------------------
const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y.%m.%d  %X", &tstruct);

    return buf;
}


// GODZINA PLIKU
//------------------------------------------------------------------------------
const string currentDateTimeGodzina() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}


// DATA FOLDERU
//------------------------------------------------------------------------------
const string currentDateTimeFolder() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y.%m.%d", &tstruct);

    return buf;
}


// PAUZA: 1 + CZAS_PAUZY_1
//------------------------------------------------------------------------------
void pauza_1_1(int max_czynnosci) {
                 
int pauza = 1;

while( pauza <= max_czynnosci*2 )
{
    pauza++; 
	Sleep (CZAS_PAUZY_1);
}

}


// PAUZA: 1 + CZAS_PAUZY_1
//------------------------------------------------------------------------------
void pauza_2_1(int max_czynnosci) {
                 
int pauza = 1;

while( pauza <= max_czynnosci)
{
    pauza++; 
	Sleep (CZAS_PAUZY_1);
}

}


void SetNumLockState( bool bState )
{
    BYTE keysState[ 256 ];
   
    GetKeyboardState(( LPBYTE ) & keysState );
    if(( bState && !( keysState[ VK_NUMLOCK ] & 1 ) ) ||( !bState &&( keysState[ VK_NUMLOCK ] & 1 ) ) ) //
     //sprawdzenie czy stan klawisza nie odpowiada argumentowi bState, \
     //tj. czy np. nie chcemy wy³¹czyæ Caps Locka podczas gdy jest on ju¿ wy³¹czony.
    {
        keybd_event( VK_NUMLOCK, 0, KEYEVENTF_EXTENDEDKEY, 0 ); //symuluje naciœniêcie klawisza
        keybd_event( VK_NUMLOCK, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0 ); //symuluje zwolnienie klawisza
    }
}


int main ()
{
    
    
//WY£¥CZANIE - NUM LOCK
//-------------------------------------------------------------------------------- 
  
SetNumLockState( false ); //wy³¹czamy Caps Locka.        
         
    
setlocale( LC_ALL, "Polish" ); 
   
string x;   
int max_czynnosci;   
int a;
int b;
int c;
int os_x;
int os_y;
int max_bompos = 1;
int licznik;


string linia;
string linia_0;
string linia_1;

string data_start = currentDateTime();

string indeks_glowny;
string indeks_glowny_porownanie;
string indeks_glowny_nazwa;
string indeks_alternatywa;
string indeks_alternatywa_porownanie;
string rodzaj_indeksu;
string indeks_podrzedny_pozycja;
string indeks_podrzedny;
string indeks_podrzedny_nazwa;
string zaleznosc_pobierz;
string zaleznosc_sp_1;
string zaleznosc_sp_2;
string zaleznosc_sp_3;
string zaleznosc_sp_4;
string zaleznosc_sp_5;
string zaleznosc_sp_6;
string zaleznosc_sp_7;
string zaleznosc_sp_8;
string zaleznosc_sp_9;
string zaleznosc_sp_10;
string zaleznosc_ustaw;
string zaleznosc_wybierz;
string zaleznosc_zlovc;
string zaleznosc_warunek_1;
string zaleznosc_warunek_2;
string zaleznosc_warunek_3;
string zaleznosc_warunek_4;
string zaleznosc_warunek_5;
string zaleznosc_warunek_6;
string zaleznosc_warunek_7;
string zaleznosc_warunek_8;
string zaleznosc_warunek_9;
string zaleznosc_warunek_10;

int zaleznosc_licznik; 

string czynnosc;
string indeks_podrzedny_tp;
string indeks_podrzedny_typ;
string indeks_podrzedny_rdz;
string indeks_podrzedny_ilosc;
string indeks_podrzedny_dubel;

string enter;

string wyrazy[14];



int rozdzielczosc_ekranu;
string rozdzielczosc;
string skalowanie;

int height;
int width;

int height_virtual;
int width_virtual;

do {
          
          
//ROZPOZNAWANIE ROZDZIELCZOŒCI EKRANU
//==============================================================================          
do {

HDC hdc = GetDC(NULL); // get the desktop device context
HDC hDest = CreateCompatibleDC(hdc); // create a device context to use yourself

// get the height && width of the screen
height_virtual = GetSystemMetrics(SM_CYSCREEN); //(SM_CYVIRTUALSCREEN);
width_virtual = GetSystemMetrics(SM_CXSCREEN);  //(SM_CXVIRTUALSCREEN)

height = GetSystemMetrics(SM_CYSCREEN);
width = GetSystemMetrics(SM_CXSCREEN);


if (height_virtual == 864) {
 
skalowanie = "125%";     

height = height_virtual * 125 / 100;
width = width_virtual * 125 / 100;      
          
}

if (height_virtual == 1080) {
 
skalowanie = "100%";  

height = height_virtual * 100 / 100;
width = width_virtual * 125 / 100;          
          
}


} while (height_virtual == 0);
//==============================================================================  
//ROZPOZNAWANIE ROZDZIELCZOŒCI EKRANU


//SPRAWDZANIE PO£O¯ENIA OKNA SAP 
//==============================================================================  
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = PASEK_POLA_GLOWNEGO_OS_X;
os_y = PASEK_POLA_GLOWNEGO_OS_Y;


do {
          

    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
system( "cls" );

cout<<"ZMIANA ZALE¯NOŒCI W SPECYFIKACJACH: SPRAWDZANIE PO£O¯ENIA OKNA SAP"<<endl;
cout<<"==========================================================================="<<endl;   
cout << a <<" " << b << " " << c << endl;


Sleep (1000);
    

if (KOLOR_NIEBIESKI_4_RGB_2) {    
         
cout<<"==========================================================================="<<endl;
cout<<"PRAWID£OWO PO£O¯ENE OKNA SAP. POTWIERD (t): ";
cin>>enter;

}


}   while (KOLOR_NIEBIESKI_4_RGB_1); 
//==============================================================================
//SPRAWDZANIE PO£O¯ENIA OKNA SAP 


system( "cls" ); 


cout<<"ZMIANA ZALE¯NOŒCI W SPECYFIKACJACH: "<<width<<"x"<<height<<" - "<<width_virtual<<"x"<<height_virtual<<" - "<<skalowanie<<endl;
cout<<"==========================================================================="<<endl; 


// WPROWADZANIE DANYCH DO KONSOLI
//------------------------------------------------------------------------------

string dzialanie_programu;
cout<<"1. Tworzenie pliku PLIK.TXT: (t/n): ";
cin>>dzialanie_programu;

while (dzialanie_programu != "t" and dzialanie_programu != "n") {
cout<<"1. Niepoprawny znak. Wpisz ponownie: "; 
cin>>dzialanie_programu;
} 


string wejscia_do_indeksu;
cout<<"2. Wejœcie do INDEKS G£ÓWNY: (t/n): ";
cin>>wejscia_do_indeksu;

while (wejscia_do_indeksu != "t" and wejscia_do_indeksu != "n") {
cout<<"2. Niepoprawny znak. Wpisz ponownie: "; 
cin>>wejscia_do_indeksu;
}


cout<<"3. Czas przerwy miêdzy czynnoœciami (1 = 0,1 sek.- zalecane: 2 (1-9)): ";
cin>>max_czynnosci;


// OTWIERANIE PLIKU Z DANYMI
//------------------------------------------------------------------------------


if (dzialanie_programu == "t") {
          

cout<<"==========================================================================="<<endl;
          
          
// OTWIERANIE PLIKU Z DANYMI
//------------------------------------------------------------------------------
fstream przechwyt_indeks; //obiekt typu fstream (uchwyt do pliku)
przechwyt_indeks.open("indeksy.txt"); //otwieramy plik: plik.txt (plik - nazwa pliku, txt - rozszerzenie)       


fstream plik1; 

string plik1_caly = "plik.txt";
plik1.open(plik1_caly.c_str(), ios::out);


getline(przechwyt_indeks, linia_0);


licznik = 1;


//TWORZENIE PLIKU: PLIK.TXT
//==============================================================================
do {


getline(przechwyt_indeks, linia);


if (linia != "") {


int dlugosc_wiersza = 0;
int xx;
int licznik_znakow;
int licznik_znakow_tab;
string znak;

for( xx = 0; xx < linia.length(); xx++ )
{

dlugosc_wiersza++;

}

//cout<<"DLUGOSC WIERSZA: "<<dlugosc_wiersza<<endl;


//TWORZENIE ZMIENNEJ: INDEKS G£ÓWNY
//==============================================================================
znak = "a";

licznik_znakow = 0;

do {
          
znak = linia.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	");

 
//cout<<i<<endl;
  

string indeks_glowny_poczatek = linia;
indeks_glowny_poczatek.erase (licznik_znakow,dlugosc_wiersza);

indeks_glowny = indeks_glowny_poczatek;
  
//cout<<"INDEKS G£ÓWNY: "<<indeks_glowny<<endl;  
//==============================================================================


//SPRAWDZANIE POPRAWNOŒCI INDEKSU G£ÓWNEGO 
//==============================================================================

int indeks_glowny_dlugosc = 0;
int xxx;

for( xxx = 0; xxx < indeks_glowny.length(); xxx++ )
{

indeks_glowny_dlugosc++;

}

if (indeks_glowny_dlugosc != 18) {
 
cout<<"INDEKS GLOWNY - NIEPOPRAWNY. SprawdŸ w pliku indeksy.txt"<<endl;


system("pause");

}


//TWORZENIE ZMIENNEJ: INDEKS G£ÓWNY NAZWA
//==============================================================================
string indeks_glowny_nazwa_poczatek = linia;  

licznik_znakow_tab = licznik_znakow +1;

indeks_glowny_nazwa_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_glowny_nazwa_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_glowny_nazwa_koniec = indeks_glowny_nazwa_poczatek; 
indeks_glowny_nazwa_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_glowny_nazwa = indeks_glowny_nazwa_koniec;
  
//cout<<"INDEKS G£ÓWNY NAZWA: "<<indeks_glowny_nazwa<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: CZYNNOŒÆ
//==============================================================================
string czynnosc_poczatek = indeks_glowny_nazwa_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

czynnosc_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = czynnosc_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string czynnosc_koniec = czynnosc_poczatek; 
czynnosc_koniec.erase (licznik_znakow,dlugosc_wiersza);

czynnosc = czynnosc_koniec;
  
//cout<<"CZYNNOŒÆ: "<<czynnosc<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: INDEKS ALTERNATYWA
//==============================================================================
string indeks_alternatywa_poczatek = czynnosc_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

indeks_alternatywa_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_alternatywa_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_alternatywa_koniec = indeks_alternatywa_poczatek; 
indeks_alternatywa_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_alternatywa = indeks_alternatywa_koniec;
  
//cout<<"INDEKS ALTERNATYWA: "<<indeks_alternatywa<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: INDEKS PODRZEDNY - POZYCJA
//==============================================================================
string indeks_podrzedny_pozycja_poczatek = indeks_alternatywa_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

indeks_podrzedny_pozycja_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_podrzedny_pozycja_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_podrzedny_pozycja_koniec = indeks_podrzedny_pozycja_poczatek; 
indeks_podrzedny_pozycja_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_podrzedny_pozycja = indeks_podrzedny_pozycja_koniec;
  
//cout<<"INDEKS PODRZEDNY - POZYCJA: "<<indeks_podrzedny_pozycja<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: INDEKS PODRZEDNY - TP
//==============================================================================
string indeks_podrzedny_tp_poczatek = indeks_podrzedny_pozycja_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

indeks_podrzedny_tp_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_podrzedny_tp_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_podrzedny_tp_koniec = indeks_podrzedny_tp_poczatek; 
indeks_podrzedny_tp_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_podrzedny_tp = indeks_podrzedny_tp_koniec;
  
//cout<<"INDEKS PODRZEDNY - TP: "<<indeks_podrzedny_tp<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: INDEKS PODRZEDNY - TYP
//==============================================================================
string indeks_podrzedny_typ_poczatek = indeks_podrzedny_tp_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

indeks_podrzedny_typ_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_podrzedny_typ_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_podrzedny_typ_koniec = indeks_podrzedny_typ_poczatek; 
indeks_podrzedny_typ_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_podrzedny_typ = indeks_podrzedny_typ_koniec;
  
//cout<<"INDEKS PODRZEDNY - TYP: "<<indeks_podrzedny_typ<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: INDEKS PODRZEDNY - RDZ
//==============================================================================
string indeks_podrzedny_rdz_poczatek = indeks_podrzedny_typ_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

indeks_podrzedny_rdz_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_podrzedny_rdz_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_podrzedny_rdz_koniec = indeks_podrzedny_rdz_poczatek; 
indeks_podrzedny_rdz_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_podrzedny_rdz = indeks_podrzedny_rdz_koniec;
  
//cout<<"INDEKS PODRZEDNY - RDZ: "<<indeks_podrzedny_rdz<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: INDEKS PODRZÊDNY
//==============================================================================
string indeks_podrzedny_poczatek = indeks_podrzedny_rdz_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

indeks_podrzedny_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_podrzedny_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_podrzedny_koniec = indeks_podrzedny_poczatek; 
indeks_podrzedny_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_podrzedny = indeks_podrzedny_koniec;
  
//cout<<"INDEKS PODRZÊDNY: "<<indeks_podrzedny<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: RODZAJ INDKESU
//==============================================================================
rodzaj_indeksu = indeks_glowny;
rodzaj_indeksu.erase (2,16);
//cout<<"RODZAJ INDEKSU: "<<rodzaj_indeksu<<endl; 
//==============================================================================


//TWORZENIE ZMIENNEJ: INDEKS PODRZÊDNY NAZWA
//==============================================================================
string indeks_podrzedny_nazwa_poczatek = indeks_podrzedny_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

indeks_podrzedny_nazwa_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_podrzedny_nazwa_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_podrzedny_nazwa_koniec = indeks_podrzedny_nazwa_poczatek; 
indeks_podrzedny_nazwa_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_podrzedny_nazwa = indeks_podrzedny_nazwa_koniec;
  
//cout<<"INDEKS PODRZÊDNY: "<<indeks_podrzedny_nazwa<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: INDEKS PODRZÊDNY ILOŒÆ
//==============================================================================
string indeks_podrzedny_ilosc_poczatek = indeks_podrzedny_nazwa_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

indeks_podrzedny_ilosc_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_podrzedny_ilosc_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_podrzedny_ilosc_koniec = indeks_podrzedny_ilosc_poczatek; 
indeks_podrzedny_ilosc_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_podrzedny_ilosc = indeks_podrzedny_ilosc_koniec;
  
//cout<<"INDEKS PODRZÊDNY - ILOŒÆ: "<<indeks_podrzedny_ilosc<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: INDEKS PODRZÊDNY - DUBEL
//==============================================================================
string indeks_podrzedny_dubel_poczatek = indeks_podrzedny_ilosc_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

indeks_podrzedny_dubel_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_podrzedny_dubel_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_podrzedny_dubel_koniec = indeks_podrzedny_dubel_poczatek; 
indeks_podrzedny_dubel_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_podrzedny_dubel = indeks_podrzedny_dubel_koniec;
  
//cout<<"INDEKS PODRZÊDNY - DUBEL: "<<indeks_podrzedny_dubel<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ POBIERZ
//==============================================================================
string zaleznosc_pobierz_poczatek = indeks_podrzedny_dubel_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_pobierz_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_pobierz_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_pobierz_koniec = zaleznosc_pobierz_poczatek; 
zaleznosc_pobierz_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_pobierz = zaleznosc_pobierz_koniec;
  
//cout<<"ZALE¯NOŒÆ POBIERZ: "<<zaleznosc_pobierz<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ SP 1
//==============================================================================
string zaleznosc_sp_1_poczatek = zaleznosc_pobierz_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_sp_1_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_sp_1_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_sp_1_koniec = zaleznosc_sp_1_poczatek; 
zaleznosc_sp_1_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_sp_1 = zaleznosc_sp_1_koniec;
  
//cout<<"ZALE¯NOŒÆ SP 1: "<<zaleznosc_sp_1<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ SP 2
//==============================================================================
string zaleznosc_sp_2_poczatek = zaleznosc_sp_1_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_sp_2_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_sp_2_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_sp_2_koniec = zaleznosc_sp_2_poczatek; 
zaleznosc_sp_2_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_sp_2 = zaleznosc_sp_2_koniec;
  
//cout<<"ZALE¯NOŒÆ SP 2: "<<zaleznosc_sp_2<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ SP 3
//==============================================================================
string zaleznosc_sp_3_poczatek = zaleznosc_sp_2_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_sp_3_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_sp_3_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_sp_3_koniec = zaleznosc_sp_3_poczatek; 
zaleznosc_sp_3_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_sp_3 = zaleznosc_sp_3_koniec;
  
//cout<<"ZALE¯NOŒÆ SP 3: "<<zaleznosc_sp_3<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ SP 4
//==============================================================================
string zaleznosc_sp_4_poczatek = zaleznosc_sp_3_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_sp_4_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_sp_4_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_sp_4_koniec = zaleznosc_sp_4_poczatek; 
zaleznosc_sp_4_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_sp_4 = zaleznosc_sp_4_koniec;
  
//cout<<"ZALE¯NOŒÆ SP 4: "<<zaleznosc_sp_4<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ SP 5
//==============================================================================
string zaleznosc_sp_5_poczatek = zaleznosc_sp_4_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_sp_5_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_sp_5_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_sp_5_koniec = zaleznosc_sp_5_poczatek; 
zaleznosc_sp_5_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_sp_5 = zaleznosc_sp_5_koniec;
  
//cout<<"ZALE¯NOŒÆ SP 5: "<<zaleznosc_sp_5<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ SP 6
//==============================================================================
string zaleznosc_sp_6_poczatek = zaleznosc_sp_5_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_sp_6_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_sp_6_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_sp_6_koniec = zaleznosc_sp_6_poczatek; 
zaleznosc_sp_6_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_sp_6 = zaleznosc_sp_6_koniec;
  
//cout<<"ZALE¯NOŒÆ SP 6: "<<zaleznosc_sp_6<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ SP 7
//==============================================================================
string zaleznosc_sp_7_poczatek = zaleznosc_sp_6_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_sp_7_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_sp_7_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_sp_7_koniec = zaleznosc_sp_7_poczatek; 
zaleznosc_sp_7_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_sp_7 = zaleznosc_sp_7_koniec;
  
//cout<<"ZALE¯NOŒÆ SP 7: "<<zaleznosc_sp_7<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ SP 8
//==============================================================================
string zaleznosc_sp_8_poczatek = zaleznosc_sp_7_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_sp_8_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_sp_8_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_sp_8_koniec = zaleznosc_sp_8_poczatek; 
zaleznosc_sp_8_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_sp_8 = zaleznosc_sp_8_koniec;
  
//cout<<"ZALE¯NOŒÆ SP 8: "<<zaleznosc_sp_8<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ SP 9
//==============================================================================
string zaleznosc_sp_9_poczatek = zaleznosc_sp_8_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_sp_9_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_sp_9_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_sp_9_koniec = zaleznosc_sp_9_poczatek; 
zaleznosc_sp_9_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_sp_9 = zaleznosc_sp_9_koniec;
  
//cout<<"ZALE¯NOŒÆ SP 9: "<<zaleznosc_sp_9<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ SP 10
//==============================================================================
string zaleznosc_sp_10_poczatek = zaleznosc_sp_9_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_sp_10_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_sp_10_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_sp_10_koniec = zaleznosc_sp_10_poczatek; 
zaleznosc_sp_10_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_sp_10 = zaleznosc_sp_10_koniec;
  
//cout<<"ZALE¯NOŒÆ SP 10: "<<zaleznosc_sp_10<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ USTAW
//==============================================================================
string zaleznosc_ustaw_poczatek = zaleznosc_sp_10_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_ustaw_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_ustaw_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_ustaw_koniec = zaleznosc_ustaw_poczatek; 
zaleznosc_ustaw_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_ustaw = zaleznosc_ustaw_koniec;
  
//cout<<"ZALE¯NOŒÆ USTAW: "<<zaleznosc_ustaw<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WYBIERZ
//==============================================================================
string zaleznosc_wybierz_poczatek = zaleznosc_ustaw_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_wybierz_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_wybierz_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_wybierz_koniec = zaleznosc_wybierz_poczatek; 
zaleznosc_wybierz_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_wybierz = zaleznosc_wybierz_koniec;
  
//cout<<"ZALE¯NOŒÆ WYBIERZ: "<<zaleznosc_wybierz<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ ZLOVC
//==============================================================================
string zaleznosc_zlovc_poczatek = zaleznosc_wybierz_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_zlovc_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_zlovc_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_zlovc_koniec = zaleznosc_zlovc_poczatek; 
zaleznosc_zlovc_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_zlovc = zaleznosc_zlovc_koniec;
  
//cout<<"ZALE¯NOŒÆ ZLOVC: "<<zaleznosc_zlovc<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WARUNEK 1
//==============================================================================
string zaleznosc_warunek_1_poczatek = zaleznosc_zlovc_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_warunek_1_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_warunek_1_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_warunek_1_koniec = zaleznosc_warunek_1_poczatek; 
zaleznosc_warunek_1_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_warunek_1 = zaleznosc_warunek_1_koniec;
  
//cout<<"ZALE¯NOŒÆ WARUNEK 1: "<<zaleznosc_warunek_1<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WARUNEK 2
//==============================================================================
string zaleznosc_warunek_2_poczatek = zaleznosc_warunek_1_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_warunek_2_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_warunek_2_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_warunek_2_koniec = zaleznosc_warunek_2_poczatek; 
zaleznosc_warunek_2_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_warunek_2 = zaleznosc_warunek_2_koniec;
  
//cout<<"ZALE¯NOŒÆ WARUNEK 2: "<<zaleznosc_warunek_2<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WARUNEK 3
//==============================================================================
string zaleznosc_warunek_3_poczatek = zaleznosc_warunek_2_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_warunek_3_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_warunek_3_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_warunek_3_koniec = zaleznosc_warunek_3_poczatek; 
zaleznosc_warunek_3_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_warunek_3 = zaleznosc_warunek_3_koniec;
  
//cout<<"ZALE¯NOŒÆ WARUNEK 3: "<<zaleznosc_warunek_3<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WARUNEK 4
//==============================================================================
string zaleznosc_warunek_4_poczatek = zaleznosc_warunek_3_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_warunek_4_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_warunek_4_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_warunek_4_koniec = zaleznosc_warunek_4_poczatek; 
zaleznosc_warunek_4_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_warunek_4 = zaleznosc_warunek_4_koniec;
  
//cout<<"ZALE¯NOŒÆ WARUNEK 4: "<<zaleznosc_warunek_4<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WARUNEK 5
//==============================================================================
string zaleznosc_warunek_5_poczatek = zaleznosc_warunek_4_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_warunek_5_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_warunek_5_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_warunek_5_koniec = zaleznosc_warunek_5_poczatek; 
zaleznosc_warunek_5_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_warunek_5 = zaleznosc_warunek_5_koniec;
  
//cout<<"ZALE¯NOŒÆ WARUNEK 5: "<<zaleznosc_warunek_5<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WARUNEK 6
//==============================================================================
string zaleznosc_warunek_6_poczatek = zaleznosc_warunek_5_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_warunek_6_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_warunek_6_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_warunek_6_koniec = zaleznosc_warunek_6_poczatek; 
zaleznosc_warunek_6_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_warunek_6 = zaleznosc_warunek_6_koniec;
  
//cout<<"ZALE¯NOŒÆ WARUNEK 6: "<<zaleznosc_warunek_6<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WARUNEK 7
//==============================================================================
string zaleznosc_warunek_7_poczatek = zaleznosc_warunek_6_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_warunek_7_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_warunek_7_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_warunek_7_koniec = zaleznosc_warunek_7_poczatek; 
zaleznosc_warunek_7_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_warunek_7 = zaleznosc_warunek_7_koniec;
  
//cout<<"ZALE¯NOŒÆ WARUNEK 7: "<<zaleznosc_warunek_7<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WARUNEK 8
//==============================================================================
string zaleznosc_warunek_8_poczatek = zaleznosc_warunek_7_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_warunek_8_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_warunek_8_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_warunek_8_koniec = zaleznosc_warunek_8_poczatek; 
zaleznosc_warunek_8_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_warunek_8 = zaleznosc_warunek_8_koniec;
  
//cout<<"ZALE¯NOŒÆ WARUNEK 8: "<<zaleznosc_warunek_8<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WARUNEK 9
//==============================================================================
string zaleznosc_warunek_9_poczatek = zaleznosc_warunek_8_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_warunek_9_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_warunek_9_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_warunek_9_koniec = zaleznosc_warunek_9_poczatek; 
zaleznosc_warunek_9_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_warunek_9 = zaleznosc_warunek_9_koniec;
  
//cout<<"ZALE¯NOŒÆ WARUNEK 9: "<<zaleznosc_warunek_9<<endl;  
//==============================================================================


//TWORZENIE ZMIENNEJ: ZALE¯NOŒÆ WARUNEK 10
//==============================================================================
string zaleznosc_warunek_10_poczatek = zaleznosc_warunek_9_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

zaleznosc_warunek_10_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = zaleznosc_warunek_10_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string zaleznosc_warunek_10_koniec = zaleznosc_warunek_10_poczatek; 
zaleznosc_warunek_10_koniec.erase (licznik_znakow,dlugosc_wiersza);

zaleznosc_warunek_10 = zaleznosc_warunek_10_koniec;
  
//cout<<"ZALE¯NOŒÆ WARUNEK 10: "<<zaleznosc_warunek_10<<endl;  
//==============================================================================

plik1 <<"==========================================================================="<<endl;
plik1 <<"INDEKS GLOWNY: "<<indeks_glowny<<endl;
plik1 <<"INDEKS GLOWNY NAZWA: "<<indeks_glowny_nazwa<<endl;
plik1 <<"CZYNNOSC: "<<czynnosc<<endl;
plik1 <<"INDEKS ALTERNATYWA: "<<indeks_alternatywa<<endl;
plik1 <<"INDEKS PODRZEDNY - POZYCJA: "<<indeks_podrzedny_pozycja<<endl;
plik1 <<"INDEKS PODRZEDNY - TP: "<<indeks_podrzedny_tp<<endl;
plik1 <<"INDEKS PODRZEDNY - TYP: "<<indeks_podrzedny_typ<<endl;
plik1 <<"INDEKS PODRZEDNY - RDZ: "<<indeks_podrzedny_rdz<<endl;
plik1 <<"INDEKS PODRZEDNY: "<<indeks_podrzedny<<endl;
plik1 <<"INDEKS PODRZEDNY - NAZWA: "<<indeks_podrzedny_nazwa<<endl;
plik1 <<"INDEKS PODRZEDNY - ILOSC: "<<indeks_podrzedny_ilosc<<endl;
plik1 <<"INDEKS PODRZEDNY - DUBEL: "<<indeks_podrzedny_dubel<<endl;
plik1 <<"---------------------------------------------------------------------------"<<endl;
plik1 <<"ZALEZNOSC - POBIERZ: "<<zaleznosc_pobierz<<endl;
plik1 <<"---------------------------------------------------------------------------"<<endl;
plik1 <<"ZALEZNOSC - SP 1: "<<zaleznosc_sp_1<<endl;
plik1 <<"ZALEZNOSC - SP 2: "<<zaleznosc_sp_2<<endl;
plik1 <<"ZALEZNOSC - SP 3: "<<zaleznosc_sp_3<<endl;
plik1 <<"ZALEZNOSC - SP 4: "<<zaleznosc_sp_4<<endl;
plik1 <<"ZALEZNOSC - SP 5: "<<zaleznosc_sp_5<<endl;
plik1 <<"ZALEZNOSC - SP 6: "<<zaleznosc_sp_6<<endl;
plik1 <<"ZALEZNOSC - SP 7: "<<zaleznosc_sp_7<<endl;
plik1 <<"ZALEZNOSC - SP 8: "<<zaleznosc_sp_8<<endl;
plik1 <<"ZALEZNOSC - SP 9: "<<zaleznosc_sp_9<<endl;
plik1 <<"ZALEZNOSC - SP 10: "<<zaleznosc_sp_10<<endl;
plik1 <<"---------------------------------------------------------------------------"<<endl;
plik1 <<"ZALEZNOSC - USTAW: "<<zaleznosc_ustaw<<endl;
plik1 <<"ZALEZNOSC - WYBIERZ: "<<zaleznosc_wybierz<<endl;
plik1 <<"ZALEZNOSC - ZLOVC: "<<zaleznosc_zlovc<<endl;
plik1 <<"---------------------------------------------------------------------------"<<endl;
plik1 <<"ZALEZNOSC - WARUNEK 1: "<<zaleznosc_warunek_1<<endl;
plik1 <<"ZALEZNOSC - WARUNEK 2: "<<zaleznosc_warunek_2<<endl;
plik1 <<"ZALEZNOSC - WARUNEK 3: "<<zaleznosc_warunek_3<<endl;
plik1 <<"ZALEZNOSC - WARUNEK 4: "<<zaleznosc_warunek_4<<endl;
plik1 <<"ZALEZNOSC - WARUNEK 5: "<<zaleznosc_warunek_5<<endl;
plik1 <<"ZALEZNOSC - WARUNEK 6: "<<zaleznosc_warunek_6<<endl;
plik1 <<"ZALEZNOSC - WARUNEK 7: "<<zaleznosc_warunek_7<<endl;
plik1 <<"ZALEZNOSC - WARUNEK 8: "<<zaleznosc_warunek_8<<endl;
plik1 <<"ZALEZNOSC - WARUNEK 9: "<<zaleznosc_warunek_9<<endl;
plik1 <<"ZALEZNOSC - WARUNEK 10: "<<zaleznosc_warunek_10<<endl;


cout<<licznik++ << ". " <<indeks_glowny<< " - "<<indeks_podrzedny<< " - "<<indeks_podrzedny_nazwa<<endl;


}


}

while (linia != ""); //przerwij je¿eli linia bêdzie pusta (dane w pliku siê skoñcz¹) UWAGA: Pamiêtaj, ¿eby w pliku zostawiæ ostatni¹ linijkê pust¹
przechwyt_indeks.close(); //zamykamy plik


}


//plik1.close


// OTWIERANIE PLIKU Z DANYMI
//------------------------------------------------------------------------------
    fstream przechwyt; //obiekt typu fstream (uchwyt do pliku)
    przechwyt.open("plik.txt"); //otwieramy plik: plik.txt (plik - nazwa pliku, txt - rozszerzenie)   


//TWORZENIE FOLDERU
//------------------------------------------------------------------------------
string folder = currentDateTimeFolder();


if (CreateDirectory(folder.c_str(), NULL))
{
    // Directory created
}
else if (ERROR_ALREADY_EXISTS == GetLastError())
{
    // Directory already exists
}
else
{
    // Failed for some other reason
}


licznik--;


indeks_glowny_porownanie = "TEKST";

indeks_alternatywa_porownanie = "TEKST";


if (wejscia_do_indeksu == "t") {


//KLIKANIE W PUSTE POLE SAP
//------------------------------------------------------------------------------
SetCursorPos( PUSTE_POLE_SAP_1 );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//---------------------------------------------------------------------------
os_x = STRZALKA_POLA_GLOWNEGO_OS_X;
os_y = STRZALKA_POLA_GLOWNEGO_OS_Y;
        
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
  
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_2_RGB_1); 	
//---------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//KLIKANIE W OKNO POLECEÑ SAP
//---------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0xBF, 0, 0, 0); // /            
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0xBF, 0, KEYEVENTF_KEYUP, 0); // /
    
    
pauza_1_1(max_czynnosci);  


//WPISYWANIE - CS01
//---------------------------------------------------------------------------
keybd_event(0x43, 0, 0, 0); // C	       
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 
keybd_event(0x53, 0, 0, 0); // S	       
keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0); // S 
keybd_event(0x30, 0, 0, 0); // 0	       
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x32, 0, 0, 0); // 2	       
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2 
    
    
pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//---------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//---------------------------------------------------------------------------
os_x = STRZALKA_POLA_GLOWNEGO_OS_X;
os_y = STRZALKA_POLA_GLOWNEGO_OS_Y;
    
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
    
    a = rr;
    b = gg;
    c = bb;
  
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_2_RGB_2); 	
//---------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


}


do {
          
zaleznosc_licznik = 0;
          

//POBIERANIE DANYCH Z PLIKU: PLIK.TXT
//------------------------------------------------------------------------------
//getline(przechwyt, indeks_nowy);
cout<<"==========================================================================="<<endl;
cout<<"ILOŒÆ INDEKSÓW DO KOÑCA: "<<licznik<<endl;
cout<<"==========================================================================="<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, linia_1);
getline(przechwyt, indeks_glowny);
indeks_glowny.erase (0,15);

if (indeks_glowny != "") {
cout<<"INDEKS GLOWNY: "<<indeks_glowny<<endl;
}
//------------------------------------------------------------------------------
rodzaj_indeksu = indeks_glowny;
rodzaj_indeksu.erase (2,16);

if (rodzaj_indeksu == "20" or rodzaj_indeksu == "30" or rodzaj_indeksu == "40"  or rodzaj_indeksu == "50") {


//------------------------------------------------------------------------------
getline(przechwyt, indeks_glowny_nazwa);
indeks_glowny_nazwa.erase (0,21);
cout<<"INDEKS GLOWNY - NAZWA: "<<indeks_glowny_nazwa<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, czynnosc);
czynnosc.erase (0,10);
cout<<"CZYNNOSC: "<<czynnosc<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, indeks_alternatywa);
indeks_alternatywa.erase (0,20);
cout<<"INDEKS ALTERNATYWA: "<<indeks_alternatywa<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, indeks_podrzedny_pozycja);
indeks_podrzedny_pozycja.erase (0,28);
cout<<"INDEKS PODRZEDNY - POZYCJA: "<<indeks_podrzedny_pozycja<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, indeks_podrzedny_tp);
indeks_podrzedny_tp.erase (0,23);
cout<<"INDEKS PODRZEDNY - TP: "<<indeks_podrzedny_tp<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, indeks_podrzedny_typ);
indeks_podrzedny_typ.erase (0,24);
cout<<"INDEKS PODRZEDNY - TYP: "<<indeks_podrzedny_typ<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, indeks_podrzedny_rdz);
indeks_podrzedny_rdz.erase (0,24);
cout<<"INDEKS PODRZEDNY - RDZ: "<<indeks_podrzedny_rdz<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, indeks_podrzedny);
indeks_podrzedny.erase (0,18);
cout<<"INDEKS PODRZEDNY: "<<indeks_podrzedny<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, indeks_podrzedny_nazwa);
indeks_podrzedny_nazwa.erase (0,26);
cout<<"INDEKS PODRZEDNY - NAZWA: "<<indeks_podrzedny_nazwa<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, indeks_podrzedny_ilosc);
indeks_podrzedny_ilosc.erase (0,26);
cout<<"INDEKS PODRZEDNY - ILOSC: "<<indeks_podrzedny_ilosc<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, indeks_podrzedny_dubel);
indeks_podrzedny_dubel.erase (0,26);
cout<<"INDEKS PODRZEDNY - DUBEL: "<<indeks_podrzedny_dubel<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, linia_1);
getline(przechwyt, zaleznosc_pobierz);
zaleznosc_pobierz.erase (0,21);
cout<<"ZALEZNOSC - POBIERZ: "<<zaleznosc_pobierz<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, linia_1);
getline(przechwyt, zaleznosc_sp_1);
zaleznosc_sp_1.erase (0,18);
cout<<"ZALEZNOSC - SP 1: "<<zaleznosc_sp_1<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_sp_2);
zaleznosc_sp_2.erase (0,18);
cout<<"ZALEZNOSC - SP 2: "<<zaleznosc_sp_2<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_sp_3);
zaleznosc_sp_3.erase (0,18);
cout<<"ZALEZNOSC - SP 3: "<<zaleznosc_sp_3<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_sp_4);
zaleznosc_sp_4.erase (0,18);
cout<<"ZALEZNOSC - SP 4: "<<zaleznosc_sp_4<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_sp_5);
zaleznosc_sp_5.erase (0,18);
cout<<"ZALEZNOSC - SP 5: "<<zaleznosc_sp_5<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_sp_6);
zaleznosc_sp_6.erase (0,18);
cout<<"ZALEZNOSC - SP 6: "<<zaleznosc_sp_6<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_sp_7);
zaleznosc_sp_7.erase (0,18);
cout<<"ZALEZNOSC - SP 7: "<<zaleznosc_sp_7<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_sp_8);
zaleznosc_sp_8.erase (0,18);
cout<<"ZALEZNOSC - SP 8: "<<zaleznosc_sp_8<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_sp_9);
zaleznosc_sp_9.erase (0,18);
cout<<"ZALEZNOSC - SP 9: "<<zaleznosc_sp_9<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_sp_10);
zaleznosc_sp_10.erase (0,19);
cout<<"ZALEZNOSC - SP 10: "<<zaleznosc_sp_10<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, linia_1);
getline(przechwyt, zaleznosc_ustaw);
zaleznosc_ustaw.erase (0,19);
cout<<"ZALEZNOSC - USTAW: "<<zaleznosc_ustaw<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_wybierz);
zaleznosc_wybierz.erase (0,21);
cout<<"ZALEZNOSC - WYBIERZ: "<<zaleznosc_wybierz<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_zlovc);
zaleznosc_zlovc.erase (0,19);
cout<<"ZALEZNOSC - ZLOVC: "<<zaleznosc_zlovc<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, linia_1);
getline(przechwyt, zaleznosc_warunek_1);
zaleznosc_warunek_1.erase (0,23);
cout<<"ZALEZNOSC - WARUNEK 1: "<<zaleznosc_warunek_1<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_warunek_2);
zaleznosc_warunek_2.erase (0,23);
cout<<"ZALEZNOSC - WARUNEK 2: "<<zaleznosc_warunek_2<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_warunek_3);
zaleznosc_warunek_3.erase (0,23);
cout<<"ZALEZNOSC - WARUNEK 3: "<<zaleznosc_warunek_3<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_warunek_4);
zaleznosc_warunek_4.erase (0,23);
cout<<"ZALEZNOSC - WARUNEK 4: "<<zaleznosc_warunek_4<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_warunek_5);
zaleznosc_warunek_5.erase (0,23);
cout<<"ZALEZNOSC - WARUNEK 5: "<<zaleznosc_warunek_5<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_warunek_6);
zaleznosc_warunek_6.erase (0,23);
cout<<"ZALEZNOSC - WARUNEK 6: "<<zaleznosc_warunek_6<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_warunek_7);
zaleznosc_warunek_7.erase (0,23);
cout<<"ZALEZNOSC - WARUNEK 7: "<<zaleznosc_warunek_7<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_warunek_8);
zaleznosc_warunek_8.erase (0,23);
cout<<"ZALEZNOSC - WARUNEK 8: "<<zaleznosc_warunek_8<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_warunek_9);
zaleznosc_warunek_9.erase (0,23);
cout<<"ZALEZNOSC - WARUNEK 9: "<<zaleznosc_warunek_9<<endl;
//------------------------------------------------------------------------------
getline(przechwyt, zaleznosc_warunek_10);
zaleznosc_warunek_10.erase (0,24);
cout<<"ZALEZNOSC - WARUNEK 10: "<<zaleznosc_warunek_10<<endl;
//------------------------------------------------------------------------------


// TWORZENIE PLIKU: LOG_*.TXT
//------------------------------------------------------------------------------
fstream plik;

string plik_start_tekst = "log_";
string plik_koniec_tekst = ".txt";
string plik_caly = folder + "/" + plik_start_tekst + indeks_glowny + "_" + indeks_podrzedny + "_" + indeks_podrzedny_nazwa + plik_koniec_tekst;
plik.open(plik_caly.c_str(), ios::out);
  

plik <<"<<<POCZ¥TEK>>"<< endl; 
plik <<" "<< endl; 
plik <<"Data rozpoczêcia: "<<currentDateTime()<<endl;
plik <<"==========================================================================="<<endl;
plik <<"INDEKS GLOWNY: "<<indeks_glowny<<endl;
plik <<"INDEKS GLOWNY - NAZWA: "<<indeks_glowny_nazwa<<endl;
plik <<"CZYNNOSC: "<<czynnosc<<endl;
plik <<"INDEKS ALTERNATYWA: "<<indeks_alternatywa<<endl;
plik <<"INDEKS PODRZEDNY - POZYCJA: "<<indeks_podrzedny_pozycja<<endl;
plik <<"INDEKS PODRZEDNY - TP: "<<indeks_podrzedny_tp<<endl;
plik <<"INDEKS PODRZEDNY - TYP: "<<indeks_podrzedny_typ<<endl;
plik <<"INDEKS PODRZEDNY - RDZ: "<<indeks_podrzedny_rdz<<endl;
plik <<"INDEKS PODRZEDNY: "<<indeks_podrzedny<<endl;
plik <<"INDEKS PODRZEDNY - NAZWA: "<<indeks_podrzedny_nazwa<<endl;
plik <<"INDEKS PODRZEDNY - ILOSC: "<<indeks_podrzedny_ilosc<<endl;
plik <<"INDEKS PODRZEDNY - DUBEL: "<<indeks_podrzedny_dubel<<endl;
plik <<"---------------------------------------------------------------------------"<<endl;
plik <<"ZALEZNOSC - POBIERZ: "<<zaleznosc_pobierz<<endl;
plik <<"---------------------------------------------------------------------------"<<endl;
plik <<"ZALEZNOSC - SP 1: "<<zaleznosc_sp_1<<endl;
plik <<"ZALEZNOSC - SP 2: "<<zaleznosc_sp_2<<endl;
plik <<"ZALEZNOSC - SP 3: "<<zaleznosc_sp_3<<endl;
plik <<"ZALEZNOSC - SP 4: "<<zaleznosc_sp_4<<endl;
plik <<"ZALEZNOSC - SP 5: "<<zaleznosc_sp_5<<endl;
plik <<"ZALEZNOSC - SP 6: "<<zaleznosc_sp_6<<endl;
plik <<"ZALEZNOSC - SP 7: "<<zaleznosc_sp_7<<endl;
plik <<"ZALEZNOSC - SP 8: "<<zaleznosc_sp_8<<endl;
plik <<"ZALEZNOSC - SP 9: "<<zaleznosc_sp_9<<endl;
plik <<"ZALEZNOSC - SP 10: "<<zaleznosc_sp_10<<endl;
plik <<"---------------------------------------------------------------------------"<<endl;
plik <<"ZALEZNOSC - USTAW: "<<zaleznosc_ustaw<<endl;
plik <<"ZALEZNOSC - WYBIERZ: "<<zaleznosc_wybierz<<endl;
plik <<"ZALEZNOSC - ZLOVC: "<<zaleznosc_zlovc<<endl;
plik <<"---------------------------------------------------------------------------"<<endl;
plik <<"ZALEZNOSC - WARUNEK 1: "<<zaleznosc_warunek_1<<endl;
plik <<"ZALEZNOSC - WARUNEK 2: "<<zaleznosc_warunek_2<<endl;
plik <<"ZALEZNOSC - WARUNEK 3: "<<zaleznosc_warunek_3<<endl;
plik <<"ZALEZNOSC - WARUNEK 4: "<<zaleznosc_warunek_4<<endl;
plik <<"ZALEZNOSC - WARUNEK 5: "<<zaleznosc_warunek_5<<endl;
plik <<"ZALEZNOSC - WARUNEK 6: "<<zaleznosc_warunek_6<<endl;
plik <<"ZALEZNOSC - WARUNEK 7: "<<zaleznosc_warunek_7<<endl;
plik <<"ZALEZNOSC - WARUNEK 8: "<<zaleznosc_warunek_8<<endl;
plik <<"ZALEZNOSC - WARUNEK 9: "<<zaleznosc_warunek_9<<endl;
plik <<"ZALEZNOSC - WARUNEK 10: "<<zaleznosc_warunek_10<<endl;
//------------------------------------------------------------------------------


// TWORZENIE PLIKU: WSZYSTKIE_INDEKSY.TXT
//------------------------------------------------------------------------------
ofstream wszystkie_indeksy;

string wszystkie_indeksy_tekst = "wszystkie_indeksy.txt";

string wszystkie_indeksy_caly = folder + "/" + wszystkie_indeksy_tekst;
wszystkie_indeksy.open(wszystkie_indeksy_caly.c_str(), ios::app);
  
  
wszystkie_indeksy <<indeks_glowny<<"	"<<indeks_podrzedny<<"	"<<indeks_podrzedny_nazwa<<"	"<<czynnosc<<endl; 
//------------------------------------------------------------------------------


const char* indeks_glowny_tekst = indeks_glowny.c_str();
const char* indeks_glowny_nazwa_tekst = indeks_glowny_nazwa.c_str();
const char* czynnosc_tekst = czynnosc.c_str();
const char* indeks_alternatywa_tekst = indeks_alternatywa.c_str();
const char* indeks_podrzedny_pozycja_tekst = indeks_podrzedny_pozycja.c_str();
const char* indeks_podrzedny_tp_tekst = indeks_podrzedny_tp.c_str();
const char* indeks_podrzedny_typ_tekst = indeks_podrzedny_typ.c_str();
const char* indeks_podrzedny_rdz_tekst = indeks_podrzedny_rdz.c_str();
const char* indeks_podrzedny_tekst = indeks_podrzedny.c_str();
const char* indeks_podrzedny_nazwa_tekst = indeks_podrzedny_nazwa.c_str();
const char* indeks_podrzedny_ilosc_tekst = indeks_podrzedny_ilosc.c_str();
const char* indeks_podrzedny_dubel_tekst = indeks_podrzedny_dubel.c_str();
const char* zaleznosc_pobierz_tekst = zaleznosc_pobierz.c_str();

const char* zaleznosc_sp_1_tekst = zaleznosc_sp_1.c_str();
const char* zaleznosc_sp_2_tekst = zaleznosc_sp_2.c_str();
const char* zaleznosc_sp_3_tekst = zaleznosc_sp_3.c_str();
const char* zaleznosc_sp_4_tekst = zaleznosc_sp_4.c_str();
const char* zaleznosc_sp_5_tekst = zaleznosc_sp_5.c_str();
const char* zaleznosc_sp_6_tekst = zaleznosc_sp_6.c_str();
const char* zaleznosc_sp_7_tekst = zaleznosc_sp_7.c_str();
const char* zaleznosc_sp_8_tekst = zaleznosc_sp_8.c_str();
const char* zaleznosc_sp_9_tekst = zaleznosc_sp_9.c_str();
const char* zaleznosc_sp_10_tekst = zaleznosc_sp_10.c_str();

const char* zaleznosc_ustaw_tekst = zaleznosc_ustaw.c_str();
const char* zaleznosc_wybierz_tekst = zaleznosc_wybierz.c_str();
const char* zaleznosc_zlovc_tekst = zaleznosc_zlovc.c_str();

const char* zaleznosc_warunek_1_tekst = zaleznosc_warunek_1.c_str();
const char* zaleznosc_warunek_2_tekst = zaleznosc_warunek_2.c_str();
const char* zaleznosc_warunek_3_tekst = zaleznosc_warunek_3.c_str();
const char* zaleznosc_warunek_4_tekst = zaleznosc_warunek_4.c_str();
const char* zaleznosc_warunek_5_tekst = zaleznosc_warunek_5.c_str();
const char* zaleznosc_warunek_6_tekst = zaleznosc_warunek_6.c_str();
const char* zaleznosc_warunek_7_tekst = zaleznosc_warunek_7.c_str();
const char* zaleznosc_warunek_8_tekst = zaleznosc_warunek_8.c_str();
const char* zaleznosc_warunek_9_tekst = zaleznosc_warunek_9.c_str();
const char* zaleznosc_warunek_10_tekst = zaleznosc_warunek_10.c_str();


//KLIKANIE W PUSTE POLE SAP
//------------------------------------------------------------------------------
SetCursorPos( PUSTE_POLE_SAP_1 );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);


// ZMIANA ZALE¯NOŒCI W SPECYFIKACJI MATERIA£OWEJ
//------------------------------------------------------------------------------
cout<<"---------------------------------------------------------------------------"<<endl;
cout<<"1. INDEKS G£ÓWNY: ";


if (wejscia_do_indeksu == "t") {
  
if (indeks_glowny_porownanie == indeks_glowny && indeks_alternatywa_porownanie == indeks_alternatywa) {       
cout<<"STARY"<<endl;
cout<<"---------------------------------------------------------------------------"<<endl;

}

else { 
          
cout<<"NOWY"<<endl;
cout<<"---------------------------------------------------------------------------"<<endl;
       
          
//WCISKANIE - CTRL+S (ZAPISANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	    
keybd_event(0x53, 0, 0, 0); // S	    
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0); // S  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = STRZALKA_POLA_GLOWNEGO_OS_X;
os_y = STRZALKA_POLA_GLOWNEGO_OS_Y;
    
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
    
    a = rr;
    b = gg;
    c = bb;
  
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_2_RGB_2); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_1_1(max_czynnosci);


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_glowny_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_glowny_tekst) + 1); //text size + \0 character
    memcpy(indeks_glowny_zmienna,indeks_glowny_tekst,strlen(indeks_glowny_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_glowny_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   

	
pauza_1_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_1_1(max_czynnosci);	


//WPISYWANIE - Y001
//------------------------------------------------------------------------------
	keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
    keybd_event(0x59, 0, 0, 0); // Y	       
	keybd_event(0x59, 0, KEYEVENTF_KEYUP, 0); // Y
	keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT  
	keybd_event(0x30, 0, 0, 0); // 0	       
	keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
	keybd_event(0x30, 0, 0, 0); // 0	       
	keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
	keybd_event(0x31, 0, 0, 0); // 1	       
	keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0); // 1 


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

	
pauza_1_1(max_czynnosci);
	

if (rodzaj_indeksu != "50") {

//WPISYWANIE - 1
//------------------------------------------------------------------------------	
keybd_event(0x31, 0, 0, 0); // 1	       
keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0); // 1 	

}

else {
          
//WPISYWANIE - 3
//------------------------------------------------------------------------------	
keybd_event(0x33, 0, 0, 0); // 3	       
keybd_event(0x33, 0, KEYEVENTF_KEYUP, 0); // 3           
          
}


pauza_1_1(max_czynnosci);


if (indeks_alternatywa != "BRAK") {

//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

	
pauza_1_1(max_czynnosci); 


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_alternatywa_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_alternatywa_tekst) + 1); //text size + \0 character
    memcpy(indeks_alternatywa_zmienna,indeks_alternatywa_tekst,strlen(indeks_alternatywa_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_alternatywa_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V    
   
 
pauza_1_1(max_czynnosci);  
    
}


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 
    

}


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_4_RGB_1); 	
//------------------------------------------------------------------------------


}


if (czynnosc == "USUN_INDEKS") {
    

//KLIKANIE W MATERIA£
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_ZAKLADKA_MATERIAL );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);  


pauza_1_1(max_czynnosci);
    
    
//WCISKANIE - CTRL+TAB (PRZECHODZENIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USTAWIENIE_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USTAWIENIE_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_pozycja_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_pozycja_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_pozycja_zmienna,indeks_podrzedny_pozycja_tekst,strlen(indeks_podrzedny_pozycja_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_pozycja_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_1_1(max_czynnosci);     
    
    
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER
  
    
pauza_1_1(max_czynnosci);


//ZAZNACZANIE WIERSZ
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_ZAZNACZANIE_WIERSZA ); 
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);


pauza_1_1(max_czynnosci); 


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAZNACZANIE_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAZNACZANIE_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_3_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci); 


//WCISKANIE - LEWY SHIFT+F2
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x71, 0, 0, 0); // F2       
keybd_event(0x71, 0, KEYEVENTF_KEYUP, 0); // F2
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT 


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = POMARANCZOWY_ZNACZEK_POLA_GLOWNEGO_OS_X;
os_y = POMARANCZOWY_ZNACZEK_POLA_GLOWNEGO_OS_Y;


do {
          
          
Sleep (3000);


    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;


if (KOLOR_POMARANCZOWY_1_RGB_2) {    
         

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


}


}   while (KOLOR_POMARANCZOWY_1_RGB_2); 


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_INDKESU_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_INDKESU_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+STRZA£KA
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x25, 0, 0, 0); // STRZA£KA W LEWO           
keybd_event(0x25, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W LEWO
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER


}


if (czynnosc == "DODAJ_INDEKS" or czynnosc == "DODAJ_INDEKS/NOWE_ZALEZNOSCI") {
    
if (indeks_podrzedny_rdz == "BRAK") {
    
    
//KLIKANIE W MATERIA£
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_ZAKLADKA_MATERIAL );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);    
    
    
pauza_1_1(max_czynnosci);





//WCISKANIE - F5
//------------------------------------------------------------------------------
keybd_event(0x74, 0, 0, 0); // F5
keybd_event(0x74, 0, KEYEVENTF_KEYUP, 0); // F5 


pauza_1_1(max_czynnosci); 
 

//WCISKANIE - LEWY SHIFT+STRZA£KA W DÓ£
//------------------------------------------------------------------------------	
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x28, 0, 0, 0); // STRZA£KA W DÓ£           
keybd_event(0x28, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W DÓ£ 
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT 


pauza_1_1(max_czynnosci); 


/*
for (int i=0;i<1;i++) { 
cout << "DZIALA" << endl;
if (i == 1) {
Sleep(1000000000);
}
}
*/


//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_1_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            indeks_podrzedny_pozycja = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


pauza_1_1(max_czynnosci); 


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
 
 
pauza_1_1(max_czynnosci); 


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_tp_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_tp_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_tp_zmienna,indeks_podrzedny_tp_tekst,strlen(indeks_podrzedny_tp_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_tp_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
 
 
pauza_1_1(max_czynnosci); 


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_zmienna,indeks_podrzedny_tekst,strlen(indeks_podrzedny_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_1_1(max_czynnosci); 


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
 
 
pauza_1_1(max_czynnosci); 


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_ilosc_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_ilosc_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_ilosc_zmienna,indeks_podrzedny_ilosc_tekst,strlen(indeks_podrzedny_ilosc_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_ilosc_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci*2); 


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci*2);


//WCISKANIE - LEWY SHIFT+F9
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x78, 0, 0, 0); // F9       
keybd_event(0x78, 0, KEYEVENTF_KEYUP, 0); // F9
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT 


pauza_1_1(max_czynnosci);


//KLIKANIE W POZYCJE
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_ZAKLADKA_MATERIAL_POZYCJA );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0); 


}   


if (indeks_podrzedny_rdz != "BRAK") {
    
    
//KLIKANIE W MATERIA£
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_ZAKLADKA_KLASA );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);    
    
    
pauza_1_1(max_czynnosci);


//WCISKANIE - F5
//------------------------------------------------------------------------------
keybd_event(0x74, 0, 0, 0); // F5
keybd_event(0x74, 0, KEYEVENTF_KEYUP, 0); // F5 
 
 
pauza_1_1(max_czynnosci); 
 

//WCISKANIE - LEWY SHIFT+STRZA£KA W DÓ£
//------------------------------------------------------------------------------	
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x28, 0, 0, 0); // STRZA£KA W DÓ£           
keybd_event(0x28, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W DÓ£ 
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT 


pauza_1_1(max_czynnosci); 


//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_1_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            indeks_podrzedny_pozycja = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


pauza_1_1(max_czynnosci); 


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
 
 
pauza_1_1(max_czynnosci); 


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_tp_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_tp_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_tp_zmienna,indeks_podrzedny_tp_tekst,strlen(indeks_podrzedny_tp_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_tp_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
 
 
pauza_1_1(max_czynnosci); 


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_typ_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_typ_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_typ_zmienna,indeks_podrzedny_typ_tekst,strlen(indeks_podrzedny_typ_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_typ_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
 
 
pauza_1_1(max_czynnosci); 


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_rdz_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_rdz_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_rdz_zmienna,indeks_podrzedny_rdz_tekst,strlen(indeks_podrzedny_rdz_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_rdz_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_1_1(max_czynnosci); 


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
 
 
pauza_1_1(max_czynnosci); 


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_zmienna,indeks_podrzedny_tekst,strlen(indeks_podrzedny_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_1_1(max_czynnosci); 


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
 
 
pauza_1_1(max_czynnosci); 


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_ilosc_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_ilosc_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_ilosc_zmienna,indeks_podrzedny_ilosc_tekst,strlen(indeks_podrzedny_ilosc_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_ilosc_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_1_1(max_czynnosci); 


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci*2); 


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci*2); 


if (indeks_podrzedny_dubel == "DUBEL") {
    
//KLIKANIE W WSZYSTKIE DANE - DUBEL
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_WSZYSTKIE_DANE );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);     
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAKLADKA_STATUS_OPIS_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAKLADKA_STATUS_OPIS_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_BIALY_1_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


SetCursorPos( ZMIANA_MATERIALU_ZAKLADKA_STATUS_OPIS );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0); 


pauza_1_1(max_czynnosci);  


//WCISKANIE - DUBEL
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x44, 0, 0, 0); // D      
keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0); // D
keybd_event(0x55, 0, 0, 0); // U      
keybd_event(0x55, 0, KEYEVENTF_KEYUP, 0); // U
keybd_event(0x42, 0, 0, 0); // B      
keybd_event(0x42, 0, KEYEVENTF_KEYUP, 0); // B
keybd_event(0x45, 0, 0, 0); // E      
keybd_event(0x45, 0, KEYEVENTF_KEYUP, 0); // E
keybd_event(0x4C, 0, 0, 0); // L      
keybd_event(0x4C, 0, KEYEVENTF_KEYUP, 0); // L
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT 
  
  
pauza_1_1(max_czynnosci); 


//WCISKANIE - F3 (PRZEJŒCIE DO: POWRÓT)
//------------------------------------------------------------------------------
keybd_event(0x72, 0, 0, 0); // F3	 
keybd_event(0x72, 0, KEYEVENTF_KEYUP, 0); // F3


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAKLADKA_KLASA_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAKLADKA_KLASA_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_4_RGB_1); 	
//------------------------------------------------------------------------------ 
  
  
}

  
//WCISKANIE - LEWY SHIFT+F9
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x78, 0, 0, 0); // F9       
keybd_event(0x78, 0, KEYEVENTF_KEYUP, 0); // F9
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT 


pauza_1_1(max_czynnosci);


//KLIKANIE W POZYCJE
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_ZAKLADKA_KLASA_POZYCJA );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);     
 
    
}
    
}


// ZALE¯NOŒCI
//------------------------------------------------------------------------------
if (czynnosc == "NOWE_ZALEZNOSCI" or czynnosc == "EDYCJA_ZALEZNOSCI" or czynnosc == "DODAJ_INDEKS/NOWE_ZALEZNOSCI" or czynnosc == "DODAJ_INDEKS/EDYCJA_ZALEZNOSCI") {


//KLIKANIE W MATERIA£
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_ZAKLADKA_MATERIAL );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);   


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+TAB (PRZECHODZENIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USTAWIENIE_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USTAWIENIE_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------

/*
// WYJ¥TEK
//------------------------------------------------------------------------------ 

//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_zmienna,indeks_podrzedny_tekst,strlen(indeks_podrzedny_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


//------------------------------------------------------------------------------
// WYJ¥TEK

*/


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_podrzedny_pozycja_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_podrzedny_pozycja_tekst) + 1); //text size + \0 character
    memcpy(indeks_podrzedny_pozycja_zmienna,indeks_podrzedny_pozycja_tekst,strlen(indeks_podrzedny_pozycja_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_podrzedny_pozycja_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_1_1(max_czynnosci);     
    
    
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER
  
    
pauza_1_1(max_czynnosci*3);


//ZAZNACZANIE WIERSZ
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_ZAZNACZANIE_WIERSZA ); 
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);


pauza_1_1(max_czynnosci); 


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAZNACZANIE_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAZNACZANIE_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_3_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci); 


//WCISKANIE - CTRL+F1 (PRZECHODZENIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x70, 0, 0, 0); // F1	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x70, 0, KEYEVENTF_KEYUP, 0); // F1 


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZALEZNOSCI_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZALEZNOSCI_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_4_RGB_1); 	
//------------------------------------------------------------------------------


if (czynnosc == "EDYCJA_ZALEZNOSCI" or czynnosc == "DODAJ_INDEKS/EDYCJA_ZALEZNOSCI") {

//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 

if (KOLOR_NIEBIESKI_2_RGB_1) {

//WCISKANIE - LEWY SHIFT+STRZA£KA W DÓ£
//------------------------------------------------------------------------------	
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x28, 0, 0, 0); // STRZA£KA W DÓ£           
keybd_event(0x28, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W DÓ£ 
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT 

}

pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	


/*
//WCISKANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // F2	 
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // F2
*/

}

else {          
          

//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


//WCISKANIE - SHIFT+F2 (USUWANIE)
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x71, 0, 0, 0); // F2	 
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT 
keybd_event(0x71, 0, KEYEVENTF_KEYUP, 0); // F2


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------

}


pauza_2_1(max_czynnosci*3);


wyrazy[0] = zaleznosc_pobierz;
wyrazy[1] = zaleznosc_sp_1;
wyrazy[2] = zaleznosc_sp_2;
wyrazy[3] = zaleznosc_sp_3;
wyrazy[4] = zaleznosc_sp_4;
wyrazy[5] = zaleznosc_sp_5;
wyrazy[6] = zaleznosc_sp_6;
wyrazy[7] = zaleznosc_sp_7;
wyrazy[8] = zaleznosc_sp_8;
wyrazy[9] = zaleznosc_sp_9;
wyrazy[10] = zaleznosc_sp_10;
wyrazy[11] = zaleznosc_ustaw;
wyrazy[12] = zaleznosc_wybierz;
wyrazy[13] = zaleznosc_zlovc;

/*
wyrazy[14] = zaleznosc_warunek_1;
wyrazy[15] = zaleznosc_warunek_2;	
wyrazy[16] = zaleznosc_warunek_3;
wyrazy[17] = zaleznosc_warunek_4;
wyrazy[18] = zaleznosc_warunek_5;
wyrazy[19] = zaleznosc_warunek_6;
wyrazy[20] = zaleznosc_warunek_7;
wyrazy[21] = zaleznosc_warunek_8;
wyrazy[22] = zaleznosc_warunek_9;
wyrazy[23] = zaleznosc_warunek_10;
*/
	

sort(wyrazy, wyrazy+14);
	
//	cout<<"Elementy posortowane:\n";
for(int i=0; i<14; i++)
	
if (wyrazy[i] != "BRAK") {

//cout<<wyrazy[i]<<endl;


if (wyrazy[i] == zaleznosc_pobierz) {
     

zaleznosc_licznik++;  

cout << endl;      
cout << "---------------------------------------------------------------------------" << endl;
cout << "" << zaleznosc_licznik << ". ";     
cout<<zaleznosc_pobierz<<endl;


string porownanie = "TEST";    



          
          
while (zaleznosc_pobierz != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);   
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_pobierz_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_pobierz_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_pobierz_zmienna,zaleznosc_pobierz_tekst,strlen(zaleznosc_pobierz_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_pobierz_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

}




  
          
if (wyrazy[i] == zaleznosc_sp_1) {
    

zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
          
          
cout<<"ZALEZNOSC - SP 1: 0020 - "<<zaleznosc_sp_1<<endl;


string porownanie = "TEST";  

         
while (zaleznosc_sp_1 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE    


pauza_2_1(max_czynnosci);            
          
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_sp_1_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_sp_1_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_sp_1_zmienna,zaleznosc_sp_1_tekst,strlen(zaleznosc_sp_1_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_sp_1_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

}          
          

if (wyrazy[i] == zaleznosc_sp_2) {


zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
         
          
cout<<"ZALEZNOSC - SP 2: 0020 - "<<zaleznosc_sp_2<<endl;


string porownanie = "TEST";          

           
while (zaleznosc_sp_2 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE    


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_sp_2_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_sp_2_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_sp_2_zmienna,zaleznosc_sp_2_tekst,strlen(zaleznosc_sp_2_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_sp_2_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

}          
     

if (wyrazy[i] == zaleznosc_sp_3) {
    
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
          

cout<<"ZALEZNOSC - SP 3: 0020 - "<<zaleznosc_sp_3<<endl;


string porownanie = "TEST";  

        
while (zaleznosc_sp_3 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_sp_3_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_sp_3_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_sp_3_zmienna,zaleznosc_sp_3_tekst,strlen(zaleznosc_sp_3_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_sp_3_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_1_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

}    


if (wyrazy[i] == zaleznosc_sp_4) {

zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";


cout<<"ZALEZNOSC - SP 4: 0020 - "<<zaleznosc_sp_4<<endl;


string porownanie = "TEST";          

         
while (zaleznosc_sp_4 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_sp_4_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_sp_4_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_sp_4_zmienna,zaleznosc_sp_4_tekst,strlen(zaleznosc_sp_4_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_sp_4_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

}    



if (wyrazy[i] == zaleznosc_sp_5) {
    
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";

          
cout<<"ZALEZNOSC - SP 5: 0020 - "<<zaleznosc_sp_5<<endl;


string porownanie = "TEST";          

         
while (zaleznosc_sp_5 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_sp_5_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_sp_5_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_sp_5_zmienna,zaleznosc_sp_5_tekst,strlen(zaleznosc_sp_5_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_sp_5_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

}   


if (wyrazy[i] == zaleznosc_sp_6) {

zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
          
          
cout<<"ZALEZNOSC - SP 6: 0020 - "<<zaleznosc_sp_6<<endl;


string porownanie = "TEST";          

           
while (zaleznosc_sp_6 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE    


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_sp_6_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_sp_6_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_sp_6_zmienna,zaleznosc_sp_6_tekst,strlen(zaleznosc_sp_6_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_sp_6_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (wyrazy[i] == zaleznosc_sp_7) {
 
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
        
          
cout<<"ZALEZNOSC - SP 7: 0020 - "<<zaleznosc_sp_7<<endl;


string porownanie = "TEST";          


while (zaleznosc_sp_7 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_sp_7_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_sp_7_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_sp_7_zmienna,zaleznosc_sp_7_tekst,strlen(zaleznosc_sp_7_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_sp_7_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (wyrazy[i] == zaleznosc_sp_8) {
 
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
         
          
cout<<"ZALEZNOSC - SP 8: 0020 - "<<zaleznosc_sp_8<<endl;


string porownanie = "TEST";          

          
while (zaleznosc_sp_8 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_sp_8_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_sp_8_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_sp_8_zmienna,zaleznosc_sp_8_tekst,strlen(zaleznosc_sp_8_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_sp_8_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (wyrazy[i] == zaleznosc_sp_9) {

zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
          
          
cout<<"ZALEZNOSC - SP 9: 0020 - "<<zaleznosc_sp_9<<endl;          


string porownanie = "TEST";          

        
while (zaleznosc_sp_9 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_sp_9_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_sp_9_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_sp_9_zmienna,zaleznosc_sp_9_tekst,strlen(zaleznosc_sp_9_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_sp_9_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (wyrazy[i] == zaleznosc_sp_10) {

zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
          
          
cout<<"ZALEZNOSC - SP 10: 0020 - "<<zaleznosc_sp_10<<endl;          


string porownanie = "TEST";          

           
while (zaleznosc_sp_10 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE    


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_sp_10_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_sp_10_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_sp_10_zmienna,zaleznosc_sp_10_tekst,strlen(zaleznosc_sp_10_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_sp_10_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (wyrazy[i] == zaleznosc_ustaw) {

zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
          

cout<<"ZALEZNOSC - USTAW: 0010 - "<<zaleznosc_ustaw<<endl;


string porownanie = "TEST";          


while (zaleznosc_ustaw != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_ustaw_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_ustaw_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_ustaw_zmienna,zaleznosc_ustaw_tekst,strlen(zaleznosc_ustaw_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_ustaw_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (wyrazy[i] == zaleznosc_wybierz) {

zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
    
          
cout<<"ZALEZNOSC - WYBIERZ: 0100 - "<<zaleznosc_wybierz<<endl;


string porownanie = "TEST";          


while (zaleznosc_wybierz != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE      


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_wybierz_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_wybierz_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_wybierz_zmienna,zaleznosc_wybierz_tekst,strlen(zaleznosc_wybierz_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_wybierz_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (wyrazy[i] == zaleznosc_zlovc) {

zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
          
          
cout<<"ZALEZNOSC - ZLOVC: 0101 - "<<zaleznosc_zlovc<<endl;


string porownanie = "TEST";          

          
while (zaleznosc_zlovc != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE    


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_zlovc_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_zlovc_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_zlovc_zmienna,zaleznosc_zlovc_tekst,strlen(zaleznosc_zlovc_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_zlovc_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 
				
		
}



//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci);

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_SZARY_7_RGB_1); 	
//------------------------------------------------------------------------------
*/

pauza_2_1(max_czynnosci);


if (zaleznosc_pobierz != "BRAK" or zaleznosc_sp_1 != "BRAK" or zaleznosc_sp_2 != "BRAK" or zaleznosc_sp_3 != "BRAK" or 
    zaleznosc_sp_4 != "BRAK" or zaleznosc_sp_5 != "BRAK" or zaleznosc_sp_6 != "BRAK" and zaleznosc_sp_7 != "BRAK" or 
    zaleznosc_sp_8 != "BRAK" or zaleznosc_sp_9 != "BRAK" or zaleznosc_sp_10 != "BRAK" and zaleznosc_ustaw != "BRAK" or
    zaleznosc_wybierz != "BRAK" or zaleznosc_zlovc != "BRAK") {


pauza_2_1(max_czynnosci);


//WCISKANIE - PAGE UP
//------------------------------------------------------------------------------
keybd_event(0x21, 0, 0, 0); // F2	 
keybd_event(0x21, 0, KEYEVENTF_KEYUP, 0); // F2


pauza_2_1(max_czynnosci);


if (czynnosc == "NOWE_ZALEZNOSCI" or czynnosc == "DODAJ_INDEKS/NOWE_ZALEZNOSCI") {


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+STRZ£KA W LEWO - PRZESKAKIWANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x25, 0, 0, 0); // STRZA£KA W LEWO           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x25, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W LEWO 

}

else {
    
    
pauza_2_1(max_czynnosci);
    
 
//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 	 


pauza_2_1(max_czynnosci);


//WCISKANIE - STRZA£KA W GÓRÊ
//------------------------------------------------------------------------------
keybd_event(0x26, 0, 0, 0); // STRZA£KA W GÓRÊ           
keybd_event(0x26, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W GÓRÊ 
keybd_event(0x26, 0, 0, 0); // STRZA£KA W GÓRÊ           
keybd_event(0x26, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W GÓRÊ 
keybd_event(0x26, 0, 0, 0); // STRZA£KA W GÓRÊ           
keybd_event(0x26, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W GÓRÊ 

}

}


pauza_1_1(max_czynnosci * 2);


for(int i=0; i<14; i++)
	
if (wyrazy[i] != "BRAK") {

//cout<<wyrazy[i]<<endl;




if (wyrazy[i] == zaleznosc_pobierz) {
          
//WCISKANIE - 0010
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x39, 0, 0, 0); // 9          
keybd_event(0x39, 0, KEYEVENTF_KEYUP, 0); // 9  
keybd_event(0x39, 0, 0, 0); // 9          
keybd_event(0x39, 0, KEYEVENTF_KEYUP, 0); // 9  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_sp_1) {

//WCISKANIE - 0020
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x32, 0, 0, 0); // 2          
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_sp_2) {

//WCISKANIE - 0020
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x32, 0, 0, 0); // 2          
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_sp_3) {

//WCISKANIE - 0020
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x32, 0, 0, 0); // 2          
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_sp_4) {

//WCISKANIE - 0020
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x32, 0, 0, 0); // 2          
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_sp_5) {

//WCISKANIE - 0020
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x32, 0, 0, 0); // 2          
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_sp_6) {

//WCISKANIE - 0020
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x32, 0, 0, 0); // 2          
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}



if (wyrazy[i] == zaleznosc_sp_7) {

//WCISKANIE - 0020
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x32, 0, 0, 0); // 2          
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_sp_8) {

//WCISKANIE - 0020
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x32, 0, 0, 0); // 2          
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_sp_9) {

//WCISKANIE - 0020
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x32, 0, 0, 0); // 2          
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}



if (wyrazy[i] == zaleznosc_sp_10) {

//WCISKANIE - 0020
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x32, 0, 0, 0); // 2          
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_ustaw) {

//WCISKANIE - 0010
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x31, 0, 0, 0); // 1          
keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0); // 1  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_wybierz) {

//WCISKANIE - 0100
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x31, 0, 0, 0); // 1          
keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0); // 1  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  


pauza_2_1(max_czynnosci);


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_2_1(max_czynnosci);

}


if (wyrazy[i] == zaleznosc_zlovc) {

//WCISKANIE - 0101
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x31, 0, 0, 0); // 1          
keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0); // 1  
keybd_event(0x30, 0, 0, 0); // 0          
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0  
keybd_event(0x31, 0, 0, 0); // 1          
keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0); // 1 


pauza_2_1(max_czynnosci);


if (czynnosc == "EDYCJA_ZALEZNOSCI") {

//WCISKANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // F2	 
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // F2

}

else {
          
//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

}


pauza_2_1(max_czynnosci*3);

}

						
}


if (zaleznosc_licznik == 12) {
          

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci*3);
 

//WPISYWANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN       
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN
     
            
}


if (zaleznosc_warunek_1 != "BRAK") {
    
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
          
          
cout<<"ZALEZNOSC - WARUNEK 1: "<<zaleznosc_warunek_1<<endl;


string porownanie = "TEST";          

             
while (zaleznosc_warunek_1 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE    


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_warunek_1_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_warunek_1_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_warunek_1_zmienna,zaleznosc_warunek_1_tekst,strlen(zaleznosc_warunek_1_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_warunek_1_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (zaleznosc_licznik == 12) {
          

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci*3);
 

//WPISYWANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN       
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN     
          
          
}


if (zaleznosc_warunek_2 != "BRAK") {
    
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";
          

cout<<"ZALEZNOSC - WARUNEK 2: "<<zaleznosc_warunek_2<<endl;


string porownanie = "TEST";          

           
while (zaleznosc_warunek_2 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_warunek_2_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_warunek_2_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_warunek_2_zmienna,zaleznosc_warunek_2_tekst,strlen(zaleznosc_warunek_2_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_warunek_2_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (zaleznosc_licznik == 12) {
          

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci*3);
 

//WPISYWANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN       
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN      
          
           
}


if (zaleznosc_warunek_3 != "BRAK") {
    
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";


cout<<"ZALEZNOSC - WARUNEK 3: "<<zaleznosc_warunek_3<<endl;


string porownanie = "TEST";          

          
while (zaleznosc_warunek_3 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE    


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_warunek_3_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_warunek_3_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_warunek_3_zmienna,zaleznosc_warunek_3_tekst,strlen(zaleznosc_warunek_3_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_warunek_3_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (zaleznosc_licznik == 12) {
          

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci*3);
 

//WPISYWANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN       
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN    
          
           
}


if (zaleznosc_warunek_4 != "BRAK") {
    
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";


cout<<"ZALEZNOSC - WARUNEK 4: "<<zaleznosc_warunek_4<<endl;


string porownanie = "TEST";          

       
while (zaleznosc_warunek_4 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE      


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_warunek_4_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_warunek_4_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_warunek_4_zmienna,zaleznosc_warunek_4_tekst,strlen(zaleznosc_warunek_4_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_warunek_4_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (zaleznosc_licznik == 12) {
          

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci*3);
 

//WPISYWANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN       
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN     
          
            
}


if (zaleznosc_warunek_5 != "BRAK") {

zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";


cout<<"ZALEZNOSC - WARUNEK 5: "<<zaleznosc_warunek_5<<endl;


string porownanie = "TEST";          

          
while (zaleznosc_warunek_5 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_warunek_5_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_warunek_5_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_warunek_5_zmienna,zaleznosc_warunek_5_tekst,strlen(zaleznosc_warunek_5_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_warunek_5_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (zaleznosc_licznik == 12) {
          

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci*3);
 

//WPISYWANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN       
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN    
          
         
}


if (zaleznosc_warunek_6 != "BRAK") {

zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";


cout<<"ZALEZNOSC - WARUNEK 6: "<<zaleznosc_warunek_6<<endl;


string porownanie = "TEST";          

        
while (zaleznosc_warunek_6 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE    


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_warunek_6_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_warunek_6_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_warunek_6_zmienna,zaleznosc_warunek_6_tekst,strlen(zaleznosc_warunek_6_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_warunek_6_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (zaleznosc_licznik == 12) {
          

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci*3);
 

//WPISYWANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN       
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN  
          
          
}


if (zaleznosc_warunek_7 != "BRAK") {
    
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";


cout<<"ZALEZNOSC - WARUNEK 7: "<<zaleznosc_warunek_7<<endl;


string porownanie = "TEST";          

          
while (zaleznosc_warunek_7 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE      


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_warunek_7_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_warunek_7_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_warunek_7_zmienna,zaleznosc_warunek_7_tekst,strlen(zaleznosc_warunek_7_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_warunek_7_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (zaleznosc_licznik == 12) {
          

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci*3);
 

//WPISYWANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN       
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN    
          
        
}



if (zaleznosc_warunek_8 != "BRAK") {
    
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";


cout<<"ZALEZNOSC - WARUNEK 8: "<<zaleznosc_warunek_8<<endl;


string porownanie = "TEST";          

       
while (zaleznosc_warunek_8 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_warunek_8_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_warunek_8_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_warunek_8_zmienna,zaleznosc_warunek_8_tekst,strlen(zaleznosc_warunek_8_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_warunek_8_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (zaleznosc_licznik == 12) {
          

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci*3);
 

//WPISYWANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN       
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN    
          
        
}


if (zaleznosc_warunek_9 != "BRAK") {
    
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";


cout<<"ZALEZNOSC - WARUNEK 9: "<<zaleznosc_warunek_9<<endl;


string porownanie = "TEST";          

         
while (zaleznosc_warunek_9 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE     


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_warunek_9_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_warunek_9_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_warunek_9_zmienna,zaleznosc_warunek_9_tekst,strlen(zaleznosc_warunek_9_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_warunek_9_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


          //WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


//WCISKANIE - TAB
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

/*
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X;
os_y = os_y+24;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_2_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_2_RGB_1); 	
//------------------------------------------------------------------------------
*/

} 


if (zaleznosc_licznik == 12) {
          

//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_2_1(max_czynnosci*3);
 

//WPISYWANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN       
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN    
          
        
}


if (zaleznosc_warunek_10 != "BRAK") {
    
zaleznosc_licznik++;

cout << "" << zaleznosc_licznik << ". ";


cout<<"ZALEZNOSC - WARUNEK 10: "<<zaleznosc_warunek_10<<endl;


string porownanie = "TEST";          

       
while (zaleznosc_warunek_10 != porownanie) {
          
          
//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WCISKANIE - DELETE
//------------------------------------------------------------------------------
keybd_event(0x2E, 0, 0, 0); // DELETE           
keybd_event(0x2E, 0, KEYEVENTF_KEYUP, 0); // DELETE      


pauza_2_1(max_czynnosci);  
          

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL zaleznosc_warunek_10_zmienna = GlobalAlloc(GMEM_FIXED,strlen(zaleznosc_warunek_10_tekst) + 1); //text size + \0 character
    memcpy(zaleznosc_warunek_10_zmienna,zaleznosc_warunek_10_tekst,strlen(zaleznosc_warunek_10_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,zaleznosc_warunek_10_zmienna);
        CloseClipboard();
    }
}


pauza_2_1(max_czynnosci); 


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   


pauza_2_1(max_czynnosci);


//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_2_1(max_czynnosci);


//WPISYWANIE - SHIFT+F11
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x7A, 0, 0, 0); // F11       
keybd_event(0x7A, 0, KEYEVENTF_KEYUP, 0); // F11
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT  


pauza_2_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


}


} 


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_1_1(max_czynnosci);


//WCISKANIE - PGUP - PAGE UP
//------------------------------------------------------------------------------
keybd_event(0x21, 0, 0, 0); // PAGE UP	
keybd_event(0x21, 0, KEYEVENTF_KEYUP, 0); // PAGE UP
keybd_event(0x21, 0, 0, 0); // PAGE UP	
keybd_event(0x21, 0, KEYEVENTF_KEYUP, 0); // PAGE UP



pauza_1_1(max_czynnosci*4);


//WCISKANIE - F3 (PRZEJŒCIE DO: POWRÓT)
//------------------------------------------------------------------------------
keybd_event(0x72, 0, 0, 0); // F3	 
keybd_event(0x72, 0, KEYEVENTF_KEYUP, 0); // F3


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_OS_Y;
     
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
 
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_4_RGB_1); 	
//------------------------------------------------------------------------------


}
// ZALE¯NOŒCI
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


indeks_glowny_porownanie = indeks_glowny;
indeks_alternatywa_porownanie = indeks_alternatywa;



// TWORZENIE PLIKU: LOG_*.TXT I ZAPISYWANIE
//------------------------------------------------------------------------------
string data_koniec = currentDateTime();	

plik <<"==========================================================================="<<endl;
plik << "Data zakoñczenia: "<< currentDateTime() <<endl;   
plik << " " <<endl;
plik << "<<<KONIEC>>>";
plik.close();
//------------------------------------------------------------------------------


licznik--;


//cout<<"TAK"<<endl;

}


else {
    
cout<<"==========================================================================="<<endl;
cout<<"BRAK DANYCH"<<endl;   
cout<<"==========================================================================="<<endl; 
  
}

if (linia_1 == "") {


if (wejscia_do_indeksu == "t") {


//WCISKANIE - CTRL+S (ZAPISANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	    
keybd_event(0x53, 0, 0, 0); // S	    
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0); // S  


}
    
            
}


}


while (linia_1 != ""); //przerwij je¿eli linia bêdzie pusta (dane w pliku siê skoñcz¹) UWAGA: Pamiêtaj, ¿eby w pliku zostawiæ ostatni¹ linijkê pust¹
przechwyt.close(); //zamykamy plik


pauza_1_1(max_czynnosci); 


//WCISKANIE - F3 (PRZEJŒCIE DO: POWRÓT)
//------------------------------------------------------------------------------
keybd_event(0x72, 0, 0, 0); // F3	 
keybd_event(0x72, 0, KEYEVENTF_KEYUP, 0); // F3


pauza_1_1(max_czynnosci);
	
	
cout<<" "<<endl;
cout<<"Powtórzyæ program (t/n): ";
cin>>x;


while (x != "t" and x != "n") {
cout<<"Niepoprawny znak. Wpisz ponownie: "; 
cin>>x;
} 


}
 
       
while( x == "t" );
    

if( x != "t" )
{
        
Sleep (CZAS_PAUZY_3);
cout<<" "<<endl;
cout<<"Koniec programu"<<endl;
       
}


fstream wszystkie_indeksy;
wszystkie_indeksy.close();


Sleep(100000);	
 
 
cin.get();
return 0;


}
