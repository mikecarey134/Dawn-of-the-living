
//   ______   ______   _________  __          
//  /_____/\ /_____/\ /________/\/_/\         
//  \:::_ \ \\:::_ \ \\__.::.__\/\:\ \        
//   \:\ \ \ \\:\ \ \ \  \::\ \   \:\ \       
//    \:\ \ \ \\:\ \ \ \  \::\ \   \:\ \____  
//     \:\/.:| |\:\_\ \ \  \::\ \   \:\/___/\ 
//      \____/_/ \_____\/   \__\/    \_____\/ 
//        by mac


#ifndef __WORLD_H
#define __WORLD_H

/**********************************************************
	WORLD.H

  	The World class

	Description: The World class represents the game world
			   of the engine. All objects, the terrain,
			   audio system, ambient world music and sound,
			   and the camera are held here.
			   Adapted By DOTL Dev Team

***********************************************************/

#include <dmusicc.h>               
#include <dmusici.h>
#include <d3d8types.h>             // for D3DVECTOR
#include <cguid.h>                 // for GUID_NULL
#include <typeinfo.h>			// for RTTI

#include "gui.h"
#include "player.h"
#include "terrain.h"
#include "sound3d.h"
#include "listener.h"
#include "objectSet.h"
#include "lcglexception.h"
#include "modelmd2.h"
#include "skybox.h"
#include "SandStorm.h"
#include"EnviroObj.h"
#include "ms3dMonster.h"
#pragma once


#define MAX_ENEMIES 10

using namespace lcgl;

class Enemy;

class World: public ObjectSet
{
private:
	int numOgros, numSods, numDwarfs;
	int screenWidth, screenHeight;
	bool gameDone;
	float timeStart;
	float timeElapsed;

	Sound	_worldTrack;//worlds music track			
	Sound	_ambient;// the world ambient sound
	GUI		gui;
	Terrain	terrain;	
	bool _isDebug;//debug mac
	lcgl::Timer _timer;//debug 

	Skybox skybox_;					//skybox
	Sandstorm theSand_;				//particlesystem

	BillboardFont debug;			//display debug stuff

	

	Sound   _explosionSound;

	void SetScreen(int w, int h) { screenWidth = w;	screenHeight = h;}
	void distribute (Enemy* enemy);
	void loadExplosionTexture ();
	void LoadWorld();
	//void UnloadWorld();

	// counts the number of objects passed as classID in the hierarchy
	int CountObjectTypes (const type_info &classID) 
	{ 
		return ObjectSet::CountObjectTypes(classID); 
	}


protected:
	void OnAnimate(float deltaTime);
	void OnPrepare();

public:
	class CantBeCopied: public LCGLException {};

	ModelMD2 AcidModel;
	Texture2D _explosionTexture;

	Player	player;			


	ModelMD2 OgroModel, SodModel, cactus; //now private members of World mac 3/31/14

	ModelMS3D dwarfModel;
	
	HWND hwnd;

	World (int w, int h);
	World (const World& other);

	~World ();
	const World& operator= (const World& other);

	// do physics calculations for all objects in the world including collisions
	void Animate(float deltaTime);

	void AnimateParticles(float deltaTime);


	// render all objects in the world
	void Draw();
	void Prepare() { OnPrepare(); }

	void  FadeScreen  ();
	bool  isDebugging ()             { return _isDebug; }              //debugging functions for displaying debug info
	void  setDebugging(bool isDebug) {_isDebug = isDebug;}
	GUI&  getGui      ()             {return gui;}
	bool  IsGameDone  ()             {return gameDone; }
	void  QuitGame    ()             {gameDone = true; }


	const int&   GetOgros       ()         {return numOgros; }
	const int&   GetSods        ()         {return numSods;  }
	const int&   GetDwarfs      ()         {return numDwarfs;}
	const Sound& explosionSound () const   { return _explosionSound; }
};


#endif