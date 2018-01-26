#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <stdio.h>

char P1,P2,P3

bool decideMaster
int Pi01,Pi02,Pi03

int main(void)

 {
while(decideMaster==1)
	{
	receive(data)
	#split_the_string
		
	K=std::split.str(data,0,0)
	num=std::split.str(data,7,8) 				#First letter from string (K=1 then it is a parameter string)
	
	
	if(K==1)
	{    
		 if(num==01)
		 {	 
			P1= std::split.str(data,1,3)
			P2= std::split.str(data,4,6)
			P01= std::to_string((long long) P1)+std::to_string((long long) P2)      
		 }
		
		if(num==02)
		 {	 
			P1= std::split.str(data,1,3)
			P2= std::split.str(data,4,6)
			P02= std::to_string((long long) P1)+std::to_string((long long) P2)      
		 }
		
		if(num==03)
		 {	 
			P1= std::split.str(data,1,3)
			P2= std::split.str(data,4,6)
			P03= std::to_string((long long) P1)+std::to_string((long long) P2)      
		 }
		
		
	}
		
	if(P01>P02>P03)
	{
 	 Pi01==1;		    #P1 is Master
	 Pi02==2;			#P3 is Player 2
	 Pi03==3;			#P3 is Player 3
		
	send ("0000123");
		
	}
		
	if(P01>P03>P02)
	{
 	 Pi01==1;		  	#P1 is Master
	 Pi02==3;			#P2 is Player 3
	 Pi03==2;			#P3 is Player 2
	 send ("0000132");
	}
	if(P02>P01>P03)
	{
 	 Pi01==2;		    #P1 is Player 2
	 Pi02==1;			#P2 is Master
	 Pi03==3;			#P3 is Player 3
		
	send ("0000213");
		
	}
		
	if(P02>P03>P01)
	{
 	 Pi01==3;		  	#P1 is Player 3
	 Pi02==1;			#P2 is Master
	 Pi03==2;			#P3 is Player 2
	 send ("0000231");
	}
	if(P03>P01>P02)
	{
 	 Pi01==2;		    #P3 is Player 1
	 Pi02==3;			#P3 is Player 2
	 Pi03==1;			#P1 is Master
		
	send ("0000312");
		
	}
		
	if(P03>P02>P01)
	{
 	 Pi01==3;		  	#P1 is Player 3
	 Pi02==2;			#P2 is Player 2
	 Pi03==1;			#P3 is Master
	 send ("0000321");
	}
	  decideMaster=0 ;     #Master Pi has been set
	}

	if()
	
while(Pi01==1)
	
    {
		
	#RUN MASTER TASK FOR Pi01 
		
	  {
		receive(buff),
		if (buff != 0000000)
		
		{
			if (X1 >= 60 && X1 <= 70 && Y1 >= 60 && Y1 <= 70 ) 
			{
				send="000000000" 				#Acts as a Master Interupt will stop the Game
				send("Player_01 is a Winner")
				send("Player_02 and Player_03 have lost the Game")
			}
			if (X2 >= 60 && X2 <= 70 && Y2 >= 60 && Y2 <= 70 ) 
			{
				send="000000000" 				#Acts as a Master Interupt will stop the Game
				send("Player_02 is a Winner")
				send("Player_01 and Player_02 have lost the Game")
			}
			if (X3 >= 60 && X3 <= 70 && Y3 >= 60 && Y3 <= 70 )  
			{
				send="000000000" 				#Acts as a Master Interupt will stop the Game
				send("Player_03 is a Winner")
				send("Player_01 and Player_02 have lost the Game")	
			}
		
		marble.cpp()
		
		else 
		{
		break;
		
		}
 	    
		}
		
	}
	
	
	
	
	
	
	
	
	
		while(Pi01==2)                                       # Do nothing just play the game as player 2 and wait for master command(slave mode)
	
		{
		marble.cpp()
		
		}
	
	
		while(Pi01==3)                                       # Do nothing just play the game as player 3 and wait for master command(slave mode)
	
		{
		marble.cpp()    
		
		}
	
	
	
	
	
	
	
	
	
	
	
	
	









