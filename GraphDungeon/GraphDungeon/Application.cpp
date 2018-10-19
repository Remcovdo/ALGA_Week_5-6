#include "Application.h"

#include <time.h>
#include <iostream>
#include <string>
#include <sstream>

Application::Application() : dungeon{ nullptr }, player{ nullptr }, running{ true }
{
	srand(time(NULL));
}

Application::~Application()
{

}

void Application::start()
{
	while (running)
	{
		displayOptions();
		selectedOption = getUserInput("Optie: ", 1, 7);
		std::cout << std::endl;
		handleOption();
	}
}

void Application::displayOptions()
{
	std::cout << "Kies een van de volgende opties:" << std::endl;
	std::cout << "- 1: Nieuwe dungeon aanmaken" << std::endl;
	std::cout << "- 2: Dungeon weergeven (Cheat)" << std::endl;
	std::cout << "- 3: Talisman gebruiken" << std::endl;
	std::cout << "- 4: Granaat gooien" << std::endl;
	std::cout << "- 5: Kompas gebruiken" << std::endl;
	std::cout << "- 6: Tegenstanders sterker maken (Cheat)" << std::endl;
	std::cout << "- 7: Quit" << std::endl;
}

int Application::getUserInput(std::string message, int min, int max)
{
	std::cout << message;
	
	int input;
	while (true)
	{
		std::string userInput;
		getline(std::cin, userInput);
		std::stringstream myStream(userInput);
		if (myStream >> input && input >= min && input <= max)
			break;
		std::cout << "Geef een gelding nummer op (" << min << "-"<< max << "): ";
	}

	return input;
}

void Application::handleOption()
{
	switch (selectedOption)
	{
		case 1: createDungeon(); break;
		case 2: displayDungeon();  break;
		case 3: useTalisman(); break;
		case 4: useGrenade(); break;
		case 5: useCompass(); break;
		case 6: makeEnemiesStronger(); break;
		case 7: quit(); break;
	}
}

void Application::createDungeon()
{
	if (dungeon != nullptr)
		delete dungeon;
	if (player != nullptr)
		delete player;

	int width = getUserInput("Breedte: ", 2, 10);
	int height = getUserInput("Hoogte: ", 2, 10);

	dungeon = new Dungeon(width, height);
	player = new Player(dungeon);
	dungeon->addPlayer(player);

	std::cout << "Er is een nieuwe dungeon aangemaakt!" << std::endl;
	std::cout << std::endl;
}

void Application::displayDungeon()
{
	if (dungeon != nullptr)
		dungeon->displayDungeon();
	else
		displayWarning();
}

void Application::useTalisman()
{
	if (player != nullptr)
		player->useTalisman();
	else
		displayWarning();
}

void Application::useGrenade()
{
	if (player != nullptr)
		player->useGrenade();
	else
		displayWarning();
}

void Application::useCompass()
{
	if (player != nullptr)
		player->useCompass();
	else
		displayWarning();
}

void Application::makeEnemiesStronger()
{
	if (player != nullptr)
		player->makeEnemiesStronger();
	else
		displayWarning();
}

void Application::quit()
{
	if (dungeon != nullptr)
		delete dungeon;
	if (player != nullptr)
		delete player;

	running = false;
	std::cout << "Tot ziens!" << std::endl;
}

void Application::displayWarning()
{
	std::cout << "Maak eerst een nieuwe Dungeon aan!" << std::endl;
	std::cout << std::endl;
}
