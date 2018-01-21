#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mraa.hpp>
#include <fstream>
#include "OLEDDisplay.h"
#include <vector>
#include <stdio.h>
using boost :: asio :: ip :: address ;
using boost :: asio :: ip :: udp ;
using std::to_string;
using boost::asio::buffer;
using namespace GFX;
using namespace std;

class testReciever 
{
 
public :	
	

std::vector<std::string> split(std::string str, char delimiter) {
  std::vector<std::string> aux;
  std::stringstream ss(str); // Turn the string into a stream.
  std::string tok;
  
  while(getline(ss, tok, delimiter)) {
    aux.push_back(tok);
  }
  
  return aux;
}

void moveBall(OLEDDisplay &lcd, int x , int y)
{
	const int radius = 2;
	lcd.clearScreen();
	lcd.drawCircle(x,y,radius);
	lcd.flush();
}


void Reciever(udp::socket &socket, OLEDDisplay &lcd) 
{
	
	int x = -1;
	int y = -1;
	
	udp::endpoint sender;
	boost::array<char, 200> buf;	
	boost::system::error_code err;
	
	while (!err)
	{
		size_t len = socket.receive_from(buffer(buf), sender, 0, err);
		if (!err) {
			std::string message(buf.c_array(), len); 
			std::cout<< "Got:" << message << std::endl;		
			std::vector<std::string> parsed = split(message, ':');		
			x = std::stoi(parsed[0]);
			y = std::stoi(parsed[1]);
			moveBall(lcd, x, y);
		}
	}			

}
		


};


int main()

{ 
	//communicationInit();
	//communication.Sender();
	
	OLEDDisplay lcd(128, 128);
	lcd.enable();
	lcd.setBgColor(COLOR_BLACK);
	lcd.setDrawColor(COLOR_WHITE);
	lcd.setTextColor(COLOR_WHITE);
	
	
	//err = boost::asio::error::would_block;
	//size_t len = socket.receive_from(buffer(buf), sender, 0, err);
	boost::asio::io_service io_service;
	udp::socket socket(io_service);
	socket.open(udp::v4());
	socket.set_option(udp::socket::reuse_address(true));
	socket.set_option(udp::socket::broadcast(true));
	socket.bind(udp::endpoint(udp::v4(), 7788));
	socket.non_blocking(true);
	testReciever reciever;
		
	while(true)
	{
		reciever.Reciever(socket, lcd);	
	}
}