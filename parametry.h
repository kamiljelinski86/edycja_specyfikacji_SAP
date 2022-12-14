/* parametry.h */ 



//PRZERWY CZASOWE 
#define CZAS_PAUZY_1		150
#define CZAS_PAUZY_2		1000
#define CZAS_PAUZY_3		2000


//pozycje kursora
//------------------------------------------------------------------------------

//PUSTE POLE SAP 1
#define PUSTE_POLE_SAP_1		1400, 200

//ZMIANA MATERIAŁU - ZAZNACZANIE WIERSZA
#define ZMIANA_MATERIALU_ZAZNACZANIE_WIERSZA		790, 330

//ZMIANA MATERIAŁU - ZAKŁADKA MATERIAŁ
#define ZMIANA_MATERIALU_ZAKLADKA_MATERIAL		815, 255

//ZMIANA MATERIAŁU - ZAKŁADKA MATERIAŁ POZYCJA
#define ZMIANA_MATERIALU_ZAKLADKA_MATERIAL_POZYCJA		818, 331

//ZMIANA MATERIAŁU - ZAKŁADKA KLASA
#define ZMIANA_MATERIALU_ZAKLADKA_KLASA		950, 255

//ZMIANA MATERIAŁU - ZAKŁADKA KLASA POZYCJA
#define ZMIANA_MATERIALU_ZAKLADKA_KLASA_POZYCJA		818, 312

//ZMIANA MATERIAŁU - WSZYSTKIE DANE
#define ZMIANA_MATERIALU_WSZYSTKIE_DANE		1379, 312

//ZMIANA MATERIAŁU - ZAKŁADKA STATUS/OPIS
#define ZMIANA_MATERIALU_ZAKLADKA_STATUS_OPIS		909, 254


//rozpoznawanie koloru
//------------------------------------------------------------------------------

//PASEK POLA GŁOWNEGO
#define PASEK_POLA_GLOWNEGO_OS_X		960
#define PASEK_POLA_GLOWNEGO_OS_Y		0

//SZARA STRZAŁKA POLA GŁOWNEGO
#define STRZALKA_POLA_GLOWNEGO_OS_X		1285
#define STRZALKA_POLA_GLOWNEGO_OS_Y		150

//ZIELONY ZNACZEK POLA GŁOWNEGO  
#define ZIELONY_ZNACZEK_POLA_GLOWNEGO_OS_X      975
#define ZIELONY_ZNACZEK_POLA_GLOWNEGO_OS_Y      1003

//POMARAŃCZOWY ZNACZEK POLA GŁOWNEGO  
#define POMARANCZOWY_ZNACZEK_POLA_GLOWNEGO_OS_X      974
#define POMARANCZOWY_ZNACZEK_POLA_GLOWNEGO_OS_Y      1006	

//------------------------------------------------------------------------------

//ZMIANA SPECYFIKACJI MATERIAŁOWEJ
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_OS_X		1500
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_OS_Y		390	

//ZMIANA SPECYFIKACJI MATERIAŁOWEJ ZAKŁADKA KLASA
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAKLADKA_KLASA_OS_X		1450
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAKLADKA_KLASA_OS_Y		365	

//ZMIANA SPECYFIKACJI MATERIAŁOWEJ - USTAWIENIE
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USTAWIENIE_OS_X		1600
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USTAWIENIE_OS_Y		540

//ZMIANA SPECYFIKACJI MATERIAŁOWEJ - ZAZNACZANIE
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAZNACZANIE_OS_X		985
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAZNACZANIE_OS_Y		415

//ZMIANA SPECYFIKACJI MATERIAŁOWEJ - ZALEŻNOŚCI
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZALEZNOSCI_OS_X		1500
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZALEZNOSCI_OS_Y		310

//ZMIANA SPECYFIKACJI MATERIAŁOWEJ - USUWANIE ZALEŻNOŚCI - NOWE
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_X		1330
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_ZALEZNOSCI_OS_Y		340

//ZMIANA SPECYFIKACJI MATERIAŁOWEJ - USUWANIE INDKESU - NOWE
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_INDKESU_OS_X		1450
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_USUWANIE_INDKESU_OS_Y		320

//ZMIANA SPECYFIKACJI MATERIAŁOWEJ - ZAKŁADKA STATUS/OPIS
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAKLADKA_STATUS_OPIS_OS_X		1706
#define ZMIANA_SPECYFIKACJI_MATERIALOWEJ_ZAKLADKA_STATUS_OPIS_OS_Y		733

//------------------------------------------------------------------------------


// kolory do rozpoznania
//------------------------------------------------------------------------------

//SZARY 1
#define KOLOR_SZARY_1_RGB_1		a != 234 and b != 237 and c != 240

//SZARY 2 - PRZYCISK STRZAŁKI
#define KOLOR_SZARY_2_RGB_1		a != 102 and b != 102 and c != 102
#define KOLOR_SZARY_2_RGB_2		a == 102 and b == 102 and c == 102

//SZARY 3
#define KOLOR_SZARY_3_RGB_1		a != 247 and b != 247 and c != 247

//SZARY 4
#define KOLOR_SZARY_4_RGB_1		a != 229 and b != 229 and c != 229

//SZARY 5
#define KOLOR_SZARY_5_RGB_1		a != 249 and b != 249 and c != 249

//SZARY 6
#define KOLOR_SZARY_6_RGB_1		a != 236 and b != 236 and c != 236

//SZARY 7
#define KOLOR_SZARY_7_RGB_1		a != 234 and b != 237 and c != 240

//ZIELONY - IKONA
#define KOLOR_ZIELONY_1_RGB_1		a != 0 and b != 139 and c != 0

//NIEBIESKI
#define KOLOR_NIEBIESKI_1_RGB_1		a != 0 and b != 157 and c != 224

//NIEBIESKI
#define KOLOR_NIEBIESKI_1_RGB_2		a == 0 and b == 157 and c == 224

//NIEBIESKI
#define KOLOR_NIEBIESKI_2_RGB_1		a != 229 and b != 242 and c != 249

//NIEBIESKI
#define KOLOR_NIEBIESKI_3_RGB_1		a != 0 and b != 104 and c != 158

//NIEBIESKI
#define KOLOR_NIEBIESKI_4_RGB_1	a != 188 and b != 226 and c != 247

//NIEBIESKI
#define KOLOR_NIEBIESKI_4_RGB_2	a == 188 and b == 226 and c == 247

//BIAŁY
#define KOLOR_BIALY_1_RGB_1		a != 255 and b != 255 and c != 255

//CZERWONY
#define KOLOR_CZERWONY_1_RGB_2		a == 249 and b == 0 and c == 0

//POMARAŃCZOWY
#define KOLOR_POMARANCZOWY_1_RGB_1	a != 255 and b != 187 and c != 51

//POMARAŃCZOWY
#define KOLOR_POMARANCZOWY_1_RGB_2	a == 255 and b == 187 and c == 51
