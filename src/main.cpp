#include <exception>
#include "Controller.h"

int main()
{
	try {

		Controller game;
		game.run();
	}
	catch (const std::exception& e)
	{

	}
}
