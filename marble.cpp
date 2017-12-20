#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mraa.hpp>
#include "OLEDDisplay.h"

using std::chrono::steady_clock;
using namespace GFX;

void testBasicCommon(OLEDDisplay &lcd, color_t bg, color_t fg) {
	lcd.setBgColor(bg);
	lcd.setDrawColor(fg);
	lcd.clearScreen();
	lcd.enable();

	lcd.drawRect(1,1, 1, 1);

	lcd.flush();
	std::this_thread::sleep_for(std::chrono::seconds(5));
}

void testBasic1() {
	OLEDDisplay lcd(128, 128);
	testBasicCommon(lcd, COLOR_WHITE, COLOR_BLACK);
}

void testBasic2() {
	OLEDDisplay lcd(128, 128);
	testBasicCommon(lcd, COLOR_BLACK, COLOR_WHITE);
}

void testFPS() {
	OLEDDisplay lcd(128, 128);
	lcd.enable();

	lcd.setBgColor(COLOR_WHITE);
	lcd.setDrawColor(COLOR_BLACK);

	steady_clock::time_point lastTime = steady_clock::now();
	uint32_t lastFC = lcd.getFrameCounter();

	const int radius = 4;
	const int minX = radius;
	const int maxX = lcd.getWidth() - radius;
	const int maxY = lcd.getHeight() - radius;
/*
	float posx0 = 0;
	float posy0 = 0;
	float posy1= 5;
	float posx1 = 5;
	float speedx = 0.5;
	float speedy = 0.5;
	float accely = 0.11;
*/


mraa::I2c i2c(0);
i2c.address(0x68);

i2c.writeReg(0x6B, 0x80);
usleep(100*1000);


	float x0 = 64;
	float x1 = x0;
	float y0 = 64;
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
	
	float dt = 0.5;
	float friction = 0.98;

	//	while(1);

	lcd.drawLine(100,0,100,100);
	lcd.drawRect(10,10,10,10);
	
	usleep(100000);
	i2c.writeReg(0x6B, 0x00);
	while (true) 
	{
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
/*		
		printf("X: %f\n", ax);
		printf("Y: %f\n", ay);
		printf("Z: %f\n", az);
*/	}
	


		speedx1 = (speedx + (accx*dt)) * friction;
		speedy1 = (speedy + (accy*dt)) * friction;

		xnew0 = xnew1 = x0 + (speedx1*dt);
		ynew0 = ynew1 = y0 + (speedy1*dt);

		//usleep(1000000);
		lcd.clearScreen();
		
	/*
	lcd.drawLine(100,0,100,100);	
		if((xnew1 >= 100) && (ynew1>= 0 || ynew1 <= 100))
		{
			printf("\nINside if\n");
			xnew1 = 98;

			lcd.drawCircle(xnew1,ynew0,2);
		printf("in while, x0: %f, x1: %f, y0: %f, y1: %f,speedx = %f,speedy = %f,accx = %f,accy = %f\n",x0,xnew1,ynew0,y1,speedx1,speedy1,accx,accy);


		}
		else
		{
					lcd.drawCircle(xnew1,ynew1,2);
		printf("in while, x0: %f, x1: %f, y0: %f, y1: %f,speedx = %f,speedy = %f,accx = %f,accy = %f\n",xnew0,xnew1,ynew0,ynew1,speedx1,speedy1,accx,accy);

		
		}
         */
         
         if (xnew0 < 2) { xnew0=2; speedx1=0;}
         if (xnew0 > 125) { xnew0=125; speedx1=0;}
         if (ynew0 < 2) { ynew0=2; speedy1=0;}
         if (ynew0 > 125) { ynew0=125; speedy1=0;}
         
		printf("in while, x0: %f, x1: %f, y0: %f, y1: %f,speedx = %f,speedy = %f,accx = %f,accy = %f\n",xnew0,xnew1,ynew0,ynew1,speedx1,speedy1,accx,accy);
			lcd.drawCircle(xnew0,ynew0,2);

		speedx = speedx1;
		speedy = speedy1;
		x0 = xnew0;
		y0 = ynew0;
	
		lcd.flush();

		
		steady_clock::time_point curTime = steady_clock::now();
		if (curTime - lastTime >= std::chrono::seconds(1)) {
			uint32_t curFC = lcd.getFrameCounter();
			printf("fps: %d\n", curFC - lastFC);
			lastTime = curTime;
			lastFC = curFC;
		}
	}
}

int main(void) {
	printf("Starting\n");
//	testBasic1();
//	testBasic2();
	testFPS();
	return 0;
}
