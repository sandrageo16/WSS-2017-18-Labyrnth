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

	float xmid = 63;
	float ymid = 63;

	float x0 = 4;
	float y0 = 125; 

	float xdiff,ydiff,xnew10,ynew10,xnew20,ynew20;;
	float xnew0 = 0;
	float ynew0 = 0;

	 
	float speedx = 0;
	float speedy = 0;

	float speedx1 = 0;
	float speedy1 = 0;
	float accx = 0;
	float accy = 0;
	
	float dt = 0.2;
	float friction = 0.98;

