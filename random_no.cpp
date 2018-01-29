#include <iostream>	
#include <string>	
#include <cstdlib> 
#include <ctime> 
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

int main(void) {
	srand ((unsigned) time (0));
	int K1 = rand ();
	int K2 = rand ();
	K1 = K1 / 100000;
	K2 = K2 / 100000;
	
	cout << "First Random no " << endl;
	std::string K_1 =std::to_string (K1);
	std::cout << K_1 << '\n';

	cout << "Second Random no " << endl;
	std::string K_2 =std::to_string (K2);
	std::cout << K_2 << '\n';


        cout << "String packet to be sent " << endl;
	std::string string_packet =std::to_string (1) + std::to_string (K1) + std::to_string (K2);
	std::cout << string_packet << '\n';

	return 0;


         	}




