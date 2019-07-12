#include "GameLoop.h"
#include <time.h>
#include <iostream>

int main()
{
	GameLoop loop;
	float deltatime = 0;
	bool quit = false;

	//Output to console for demo purposes
	//TODO: create a log system
	std::cout << "Starting the application...\n";

	while (!quit)
	{
		time_t start = time(0);
		quit = loop.Update(deltatime);
		deltatime = float(difftime(time(0), start));
	}

	std::cout << "Application finished execution\n";

	//Pause the application flow so user can read the output before quitting
	std::cin.get();
	return 0;
}