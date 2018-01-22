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
#include <iostream>
#include <random>


using boost :: asio :: ip :: address ;
using boost :: asio :: ip :: udp ;
using std::to_string;
using boost::asio::buffer;
using namespace GFX;
using namespace std;


void get_parameters()
{
	int temperature= vcgencmd measure_temp
	int random_no= rand() % 100 + 1
}

void testSender::Sender(udp::socket &socket, int temp, int random_no)
{
	
	get_parameters()
	
	udp::endpoint target(address::from_string("192.168.0.255"),7788);	
	boost::system::error_code err;	
	std::string str = std::to_string((long long) temperature) + ":" + std::to_string((long long) random_no+std::string str1 ("PiXX"));
	socket.send_to(buffer(str), target, 0, err);
	std::cout << " random_no and temp sent" << std::endl;
		
}



