#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>

#include "OLEDDisplay.h"

using std::chrono::steady_clock;
using namespace GFX;
using namespace std;
int display [128][128];
void getInput();

void getInput(){
	int i,j;
	i=0;
	string line;
	ifstream myfile("Array.txt");
	if (myfile.is_open()){
		for (i=0; i<128; i++){
			getline (myfile, line);
			for (j=0; j<128; j++){
				display[j][i]= line[j];
			}
		}
	myfile.close();
	}
	else cout<< "Ünable to open file \n";
	printf("test3 \n");
}	
int main(void){
	OLEDDisplay lcd(128, 128);
	lcd.enable();
	lcd.setBgColor(COLOR_BLACK);
	lcd.setDrawColor(COLOR_WHITE);
	lcd.setTextColor(COLOR_WHITE);
	int k,l;
	getInput();
	while(1){
		lcd.clearScreen();
			for (l=0; l<128; l++){
				for (k=0; k<128; k++){
					if (display[l][k] =='1'){
						lcd.drawPixel(l,k);
					}
				}
			}
	lcd.flush();

	}
}
