#pragma once

#include "Dungeon.h"
#include "Player.h"

class Application
{
	public:
		Application();
		~Application();

	private:
		bool running;
		int selectedOption;
		Dungeon* dungeon;
		Player* player;

	public:
		void start();
		
		void displayOptions();
		int getUserInput(std::string message, int min, int max);
		void handleOption();

		void createDungeon();
		void displayDungeon();
		void useTalisman();
		void useGrenade();
		void useCompass();
		void makeEnemiesStronger();
		void newStartAndEndRoom();
		void quit();

		void displayWarning();
};

