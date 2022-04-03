
#include "menu.h"
#include "SerialPort.hpp"
#include "Deserialisation.h"


//SerialPort * arduino; //doit etre un objet global!
#include "json.hpp"
using json = nlohmann::json;
using namespace std;


int main() {
	Menu* thisMenu;
	//Serialisation Serie("com3");
	// pour commencer ca doit créer un nouveau menu //
	//Serialisation com("com3");
	uint8_t i = 0;
	json msg;

	while (false) // test com
	{
		i++;
		if (i > 99)
		{
			i = 0;
		}
		//com.SetSegement(i);
		//com.SetMoteur(!com.GetMoteur());
		//msg = com.SerialUpdate();
		cout << msg << endl;
		Sleep(500);
	}

	thisMenu = new Menu();
}