#include <stdio.h>
#include <chrono>
#include "../OLEDDisplay.h"

int {X1=0;Y1=0;X2=0;Y2=0;X3=0;Y3=0;Xi=0;Yi=0}
char MasterAssignmentDone==0;

int main(void)

 {
	while(setMaster==1)
	
	{
	#checkCPUload+Temp
	
	P1=CPUloadin%+Temp
	send(P1)
	receive[other_pi_parameters]
	
	if(P1>P2 && P1>P3)
	{
	 #P1 is Master and Player 1
 	 master==1;
	
	 P2 is player 2	
	 P3 is player 3
	}
	if(P2>P1 && P2>P3)
	{
	 P2 is Master and Player 1
	
	master==2;
	 P1 is player 2	
	 P3 is player 3
	}

	if(P3>P1 && P3>P2)
	{
 	P3 is Master and Player 1
	
	master==3;
	 P1 is player 2	
	 P2 is player 3
	}


	while(master==1)

	{
	receive data {}							#receive={X1, Y1, X2, Y2, X3, Y3}
	
	#seperate string (mac id + XiYi)	
	
	mac_id=split(string)
	Xi=split(string)
	Yi=split(string)
		
	if mac id==1l:f3:3r:2e
	{ 
		X1=Xi
	  	Y1=Yi
	}
	if mac id==3l:f6:4s:2e
	{ 
		X2=Xi
	  	Y2=Yi
	}
	if mac id==wl:r6:k2:2d
	{ 
		X3=Xi
	  	Y3=Yi
	}

	disp.drawCircle(X1, Y1, 4);
	disp.fillCircle(X1, Y1, 4);

	disp.drawCircle(X2, Y2, 4);
	disp.fillCircle(X2, Y2, 4);

	
	disp.drawCircle(X3, Y3, 4);
	disp.fillCircle(X3, Y3, 4);

	}	

	if (master==True) {

		if (X1== [CenterPitCordinates] && Y1== [CenterPitCordinates]) 
		{
			send="STOP"
			display("Player_01 is a Winner")
		}
		if (X2== [CenterPitCordinates] && Y2== [CenterPitCordinates]) 
		{
			send="STOP"
			display("Player_02 is a Winner")
		}
		if (X3== [CenterPitCordinates] && Y3== [CenterPitCordinates]) 
		{
			send="STOP"
			display("Player_03 is a Winner")	

		}

 		}








