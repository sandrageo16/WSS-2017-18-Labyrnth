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
#include "testSender.hpp"
using boost :: asio :: ip :: address ;
using boost :: asio :: ip :: udp ;
using std::to_string;
using boost::asio::buffer;
using namespace GFX;
using namespace std;
	
void testSender::Sender(udp::socket &socket, int x, int y)
{
	udp::endpoint target(address::from_string("192.168.0.255"),7788);	
	boost::system::error_code err;	
	std::string str = std::to_string((long long) x ) + ":" + std::to_string((long long) y);
	socket.send_to(buffer(str), target, 0, err);
	std::cout << "Position sent" << std::endl;
		
}



