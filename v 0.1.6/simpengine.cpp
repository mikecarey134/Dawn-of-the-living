//   ______   ______   _________  __          
//  /_____/\ /_____/\ /________/\/_/\         
//  \:::_ \ \\:::_ \ \\__.::.__\/\:\ \        
//   \:\ \ \ \\:\ \ \ \  \::\ \   \:\ \       
//    \:\ \ \ \\:\ \ \ \  \::\ \   \:\ \____  
//     \:\/.:| |\:\_\ \ \  \::\ \   \:\/___/\ 
//      \____/_/ \_____\/   \__\/    \_____\/ 
//        by mac && DNT


#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#include "simpengine.h"

/***************************************
	SIMPENGINE.CPP

	The SimpEngine implementation
	Adapted By DOTL DEV Team

****************************************/

using namespace lcgl;

void SimpleEngine::OnPrepare()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_SMOOTH);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
}

void SimpleEngine::OnMouseDownL(float x, float y)			// Left Click fires acid DNT
{
	if (!gameWorld_.IsGameDone())	gameWorld_.player.FireWeapon();
}

void SimpleEngine::OnKeyDown(int nVirtKey)					// module to control other keystokes DNT
{
	static const float MOUSE_SENSITIVITY_INCREMENT = 0.05f;
	static const float MOUSE_SENSITIVITY_MINIMUM   = 0.05f;
	static const float MOUSE_SENSITIVITY_MAXIMUM   = 2.00f;

	if (!gameWorld_.IsGameDone())
	{
		switch (nVirtKey)
		{
		case VK_F3:   

			if (gameWorld_.isDebugging()==false)
			{
				gameWorld_.setDebugging(true); 
			} 
			else if(gameWorld_.isDebugging()==true)
			{
				gameWorld_.setDebugging(false); 
			}
		
			break;
		
		case VK_UP:			gameWorld_.player.speedUp   ( 2.0f);	break;				// what W does DNT
		case VK_DOWN:		gameWorld_.player.speedUp   (-2.0f);	break;				// What S does DNT
		case VK_RIGHT:		gameWorld_.player.speedRight( 1.0f);	break;				// what A does DNT
		case VK_LEFT:		gameWorld_.player.speedRight(-1.0f);	break;				// What D does DNT
		case VK_ESCAPE:		PostQuitMessage(0);									break;	// ESC key DNT
		case VK_ADD:		mouseSensitivity_ += MOUSE_SENSITIVITY_INCREMENT;			// What the + does
							if (mouseSensitivity() > 2.0)
								mouseSensitivity_ = MOUSE_SENSITIVITY_MAXIMUM;
							break;
		case VK_SUBTRACT:	mouseSensitivity_ -= MOUSE_SENSITIVITY_INCREMENT;			// What the - does
							if (mouseSensitivity () < 0.05)	
								mouseSensitivity_ = MOUSE_SENSITIVITY_MINIMUM;
							break;
		}
	}
	else if ((nVirtKey) == VK_ESCAPE)	PostQuitMessage(0);
}

void SimpleEngine::OnMouseMove(int deltaX, int deltaY)								// moving the mouse moves screen DNT
{
	if (!gameWorld_.IsGameDone())
	{
		gameWorld_.player.setYaw  (gameWorld_.player.yaw()   +  deltaX*mouseSensitivity ());
		gameWorld_.player.setPitch(gameWorld_.player.pitch() -  deltaY*mouseSensitivity ());
	}
}

void SimpleEngine::OnMouseMove(int x, int y, int centerX, int centerY)
{
	static const float MOUSE_SENSITIVITY_FACTOR = 0.2f;		// 1.0f is too much to start with, it can be incremented by player
	static float oldX;
	static float oldY;

	float mX, mY;

	mX = (float)x;
	mY = (float)y;

	if (mX < centerX/2) gameWorld_.player.setYaw (gameWorld_.player.yaw()  - MOUSE_SENSITIVITY_FACTOR*mouseSensitivity ());
	if (mX > centerX/2)	gameWorld_.player.setYaw (gameWorld_.player.yaw()  + MOUSE_SENSITIVITY_FACTOR*mouseSensitivity ());

	if (mY < centerY/2)	gameWorld_.player.setPitch (gameWorld_.player.pitch()+  MOUSE_SENSITIVITY_FACTOR*mouseSensitivity ());
	if (mY > centerY/2)	gameWorld_.player.setPitch (gameWorld_.player.pitch()- MOUSE_SENSITIVITY_FACTOR*mouseSensitivity ());

	oldX = mX;
	oldY = mY;
}