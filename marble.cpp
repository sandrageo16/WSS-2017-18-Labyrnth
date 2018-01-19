#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mraa.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "OLEDDisplay.h"

using std::chrono::steady_clock;
using namespace GFX;
using namespace std;
int display [128][128];
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
//				printf("%d,%d,%d\n",line[j]-'0',line[j],display[j][i]);
			}
		}
	myfile.close();
	}
	else cout<< "Ãœnable to open file \n";
	printf("test3 \n");
}
void lcd_display(OLEDDisplay &lcd){
	lcd.clearScreen();
	int k,l;
	for (l=0; l<128; l++){
		for (k=0; k<128; k++){
			if (display[l][k] >= '1')
			{
				lcd.drawPixel(l,k);
			}
		}
	}
			
	lcd.setCursor(36, 17);
	lcd.setTextColor(COLOR_WHITE);
	lcd.print("LABRYNTH");
/*	lcd.drawCircle(111, 119, 4);
	lcd.fillCircle(111, 119, 4);
	lcd.drawCircle(31, 106, 4);
	lcd.fillCircle(31, 106, 4);
	lcd.drawCircle(79, 87, 4);
	lcd.fillCircle(79, 87, 4);
*/
	lcd.drawCircle(119, 111, 4);
	lcd.fillCircle(119, 111, 4);	
	lcd.drawCircle(103, 31, 4);
	lcd.fillCircle(103, 31, 4);	
	lcd.drawCircle(87, 79, 4);
	lcd.fillCircle(87, 79, 4);

	lcd.drawCircle(7, 111, 4);
	lcd.fillCircle(7, 111, 4);	
	lcd.drawCircle(23, 31, 4);
	lcd.fillCircle(23, 31, 4);	
	lcd.drawCircle(39, 79, 4);
	lcd.fillCircle(39, 79, 4);
	
}

void end_game(OLEDDisplay &lcd){
	while(1){
		lcd_display(lcd);
		lcd.setCursor(36, 33);
		lcd.setTextColor(COLOR_WHITE);
		lcd.print("GAME OVER");
		lcd.flush();
	
}	
}
void testFPS() {
	OLEDDisplay lcd(128, 128);
	lcd.enable();
	lcd.setBgColor(COLOR_BLACK);
	lcd.setDrawColor(COLOR_WHITE);
	lcd.setTextColor(COLOR_WHITE);
	getInput();;

	steady_clock::time_point lastTime = steady_clock::now();
	uint32_t lastFC = lcd.getFrameCounter();

	const int radius = 2;
	const int minX = radius;
	const int maxX = lcd.getWidth() - radius;
	const int maxY = lcd.getHeight() - radius;


	mraa::I2c i2c(0);
	i2c.address(0x68);

	i2c.writeReg(0x6B, 0x80);
	usleep(100*1000);
	
	float x0 = 2;
	float x1 = x0;
	float y0 = 125;
	float y1 = y0;

	float xnew0 = 0;
	float xnew1 = 0;
	float ynew0 = 0;
	float ynew1 = 0;
	 
	float speedx = 0;
	float speedy = 0;

	float speedx1 = 0;
	float speedy1 = 0;
	float accx = 0;
	float accy = 0;
	
	float dt = 0.2;
	float friction = 0.98;
	
	usleep(100000);
	i2c.writeReg(0x6B, 0x00);
	while (true) {
		lcd.clearScreen();
		lcd_display(lcd);
//		lcd.flush();
		
//read raw accelerometer values
	uint8_t acc_raw[6];
	int len =i2c.readBytesReg(0x3B, acc_raw,6);
	if(len <0)
	{
		printf("Error!|n");
	}
	else{
		int16_t ax_raw = (int16_t) ((acc_raw[0]<<8) + acc_raw[1]);
		int16_t ay_raw = (int16_t) ((acc_raw[2]<<8) + acc_raw[3]);
		int16_t az_raw = (int16_t) ((acc_raw[4]<<8) + acc_raw[5]);
		
		accx = ax_raw / -16384.0f;
		accy = ay_raw / 16384.0f;
		float az = az_raw / 16384.0f;
	}
		speedx1 = (speedx + (accx*dt)) * friction;
		speedy1 = (speedy + (accy*dt)) * friction;

		xnew0 = xnew1 = x0 + (speedx1*dt);
		ynew0 = ynew1 = y0 + (speedy1*dt);

	//	lcd.clearScreen();
		if ((int(xnew0)== 111) & (int(ynew0)== 119)){ end_game(lcd);}
		if ((int(xnew0)== 31) & (int(ynew0)== 106)){ end_game(lcd);}
		if ((int(xnew0)== 79) & (int(ynew0)== 87)){ end_game(lcd);}

		int diff = 0;
		if((std::abs(xnew0 - x0)) > 1)
		{
		
		 	diff = xnew0 - x0;
			if( diff > 0)
				xnew0 = x0 + 1;
			else
				xnew0 = x0 - 1;
		}
		if((std::abs(ynew0 - y0)) > 1)
		{
			diff = ynew0 - y0;
			if (diff > 0)
				ynew0 = y0 + 1;
			else
				ynew0 = y0 - 1;
		}	

		if(display[int(xnew0)][int(ynew0)] == '3')
		{
			if(xnew0 < x0)
			{
				xnew0 = x0;
				speedx1 = 0;
			}
			ynew0 = y0;
			printf("slanting3\n");
		}

		if(display[int(xnew0)][int(ynew0)] == '4')
		{
			if(xnew0 > x0)
			{
				xnew0 = x0;
				speedx1 = 0;
			}
			ynew0 = y0;
			printf("slanting4\n");
		}
		if(display[int(xnew0)][int(ynew0)] == '5')
			{
				
					end_game(lcd);
			}

		if (display[int(xnew0)][int(ynew0)]=='1')
		{
			
		
			{
				xnew0 = x0;
				ynew0 = y0;
				printf("boundary\n");
			}

		/*	if((display[(int)(xnew0 + 1)][(int)(ynew0)] == '1')|| (display[(int)(xnew0 - 1)][(int) (ynew0)] == '1'))
			{
				speedy1 = 0;
//				speedx1 = 0;
				printf("Vertical\n");
			}
			
			if((display[int(xnew0)][int(ynew0 + 1)] == '1') || (display[int(xnew0)][int(ynew0 - 1)] == '1') )
			{
				speedx1 = 0;
//				speedy1 = 0;
				printf("Horizontal\n");
			}
*			if(((int)(xnew0) == (int)ynew0) ||( ((int)(xnew0) + (int)(ynew0)) == 127))
			{
				printf("slanting\n");
			}

*/		       		
		}
        if (xnew0 < 2) { xnew0=2; speedx1=0;}
        if (xnew0 > 125) { xnew0=125; speedx1=0;}
        if (ynew0 < 2) { ynew0=2; speedy1=0;}
        if (ynew0 > 125) { ynew0=125; speedy1=0;}

         
//		printf("in while, xnew0: %f, x0: %f,  ynew0: %f, y0: %f,speedx = %f,speedy = %f,accx = %f,accy = %f\n",xnew0,x0,ynew0,y0,speedx1,speedy1,accx,accy);
		lcd.drawCircle(xnew0,ynew0,radius);

		speedx = speedx1;
		speedy = speedy1;
		x0 = xnew0;
		y0 = ynew0;
	
		lcd.flush();
		
		steady_clock::time_point curTime = steady_clock::now();
		if (curTime - lastTime >= std::chrono::milliseconds(1000)) {
			uint32_t curFC = lcd.getFrameCounter();
			printf("fps: %d\n", curFC - lastFC);
			lastTime = curTime;
			lastFC = curFC;
		}
	}
}

int main(void) {
	printf("Starting\n");
	testFPS();
	return 0;
}
