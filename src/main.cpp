#include <exception>
#include "Controller.h"
#include <iostream>

int main()
{
	try {

		Controller game;
		game.run();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
