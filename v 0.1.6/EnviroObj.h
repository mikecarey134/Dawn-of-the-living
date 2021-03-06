
//   ______   ______   _________  __          
//  /_____/\ /_____/\ /________/\/_/\         
//  \:::_ \ \\:::_ \ \\__.::.__\/\:\ \        
//   \:\ \ \ \\:\ \ \ \  \::\ \   \:\ \       
//    \:\ \ \ \\:\ \ \ \  \::\ \   \:\ \____  
//     \:\/.:| |\:\_\ \ \  \::\ \   \:\/___/\ 
//      \____/_/ \_____\/   \__\/    \_____\/ 
//        by mac

#pragma once
#include"terrain.h"
#include <vector>
#include <algorithm>
#include <ctime>

/*
**************************************************************************
EnviroObj.h

environmental object class 
used to render billboarded objects such as trees, rocks, grass, and etc. 

programmed by Michael Carey

***************************************************************************
*/

class EnviroObj
{
	enum {MAX_CHARS = 100, DEFAULT_SIZE = 5};//max amount of chars for file location
											 //and the default size of the object
public:

	EnviroObj(Texture2D& enviroObj, const char* string);
	EnviroObj(void);
	~EnviroObj(void);

	void render(const worldCoord& pos)const;							  //render a billboarded object in a specified location
	
	//set functions
	void setSize     (float size)       { size_ = size; }				  //set size of the billboarded object
	void setLocations(worldCoord& index){ locations_.push_back(index); }  //add coordinates to the locations vector
	
	//get functions
	const std:: vector<worldCoord>& getVector      ();
	int                             getVectorSize  ()               {return locations_.size();}	
	const worldCoord&               getLocations   (int index)const {return locations_[index];}
	worldCoord                      getLocations   (int index)      {return locations_[index];}
	void                            clearLocations ()               { locations_.clear(); }      //free up space by clearing the vector

	//need to shuffle to make environment look natural for shuffling locations wont work because rand()
	//inline void shuffleLocations(){ srand(100) ; std::random_shuffle(locations_.begin(), locations_.end() ); }

private:

	float size_;							//size of environmental objects
	char* fileLocation_;					//char string for the location of the file ex "file.bmp" 
	lcgl::Texture2D  enviroObj_;			//current texture loaded 			
	std::vector<worldCoord> locations_;     //allows for storage of locations for each object 

};
