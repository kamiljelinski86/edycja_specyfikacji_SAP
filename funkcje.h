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


using namespace std;


void pauza_1() {
          

int pauza;
int max_czynnosci;
          
pauza = 1;
max_czynnosci = 1;

while( pauza <= max_czynnosci )
{
    pauza++; 
	Sleep (CZAS_PAUZY_1);		
}


}
