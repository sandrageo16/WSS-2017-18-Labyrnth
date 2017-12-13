#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../OLEDDisplay.h"

using std::chrono::steady_clock;
using namespace GFX;
int main(void){
OLEDDisplay lcd(128, 128);
lcd.enable();
lcd.setBgColor(COLOR_BLACK);
lcd.setDrawColor(COLOR_WHITE);
lcd.setTextColor(COLOR_WHITE);

while(1){
	lcd.clearScreen();
	lcd.drawRect(0,0, 127, 127);
// 1st section
	lcd.drawLine(0, 0, 127, 127);
	lcd.drawLine(0, 127, 127, 0);
	lcd.drawLine(15, 15, 79, 15);
	lcd.drawLine(95, 15, 111, 15);
	lcd.drawLine(31, 31, 47, 31);
	lcd.drawLine(63, 31, 95, 31);
	lcd.drawLine(47, 47, 55, 47);
	lcd.drawLine(71, 47, 79, 47);
// 2nd section
	lcd.drawLine(111, 15, 111, 79);
	lcd.drawLine(111, 95, 111, 111);
	lcd.drawLine(95, 31, 95, 47);
	lcd.drawLine(95, 63, 95, 95);
	lcd.drawLine(79, 47, 79, 55);
	lcd.drawLine(79, 71, 79, 79);
	
//3rd Section
	lcd.drawLine(15, 15, 15, 79);
	lcd.drawLine(15, 95, 15, 111);
	lcd.drawLine(31, 31, 31, 47);
	lcd.drawLine(21, 63, 31, 95);
	lcd.drawLine(47, 47, 47, 55);
	lcd.drawLine(47, 71, 47, 79);	
	
	lcd.drawCircle(111, 8, 8);
	lcd.fillCircle(111, 8, 8);
	
	lcd.flush();
}
}