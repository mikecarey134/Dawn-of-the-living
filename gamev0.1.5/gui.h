#ifndef __GUI_H
#define __GUI_H

#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

/***********************************************
	
	GUI.H
	The GUI class interface 
	Description: Display the HUD Mac 4/5 14
	adapted By: Mike Carey && L_wood


************************************************/

#include <windows.h>
#include "billboardfont.h"
#include "player.h"
#include <timer.h>


using namespace lcgl;

class GUI
{
private:
	int minutesLeft, secondsLeft, millisecondsLeft;
	int enemiesLeft;
	float x, y, z;

	BillboardFont font, endText, fps,healthIcon,health;
	Player player_;
	Timer timer_;
	float _health;

	Texture2D crosshair_, _icon;

public:
	GUI(Player& player);
	GUI (const GUI&);
	void operator= (const GUI&);

	void SetCurrentTime	(float timeLeft);
	void SetEnemiesLeft	(int eLeft)			{	enemiesLeft = eLeft;	}
	void Draw			();
	void Animate		(float deltaTime);
	void updateHeath    (float damage)     {_health-=damage;}//show player damage

	void DrawWinner		();
	void DrawLoser		();
	void drawCrosshair  ()const;//draw the player's crosshair mac 4/7/14
	void drawAcidIcon   ()const;//draw the icon for acid spit mac 4/7/14
	
};


#endif