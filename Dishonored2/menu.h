#pragma once
#include <iostream>

void drawMenu(int menu);

struct toogle {
	bool health = false,
		mana = false,
		choke = false,
		ammo = false,
		oxygen = false,
		fly = false;
};