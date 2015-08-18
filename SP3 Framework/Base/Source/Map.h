#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Enemy.h"

using namespace std;

class CMap
{

public:
	CMap(void);
	~CMap(void);

	enum tileList
	{
		GROUND,
		WALL,
		JEWEL,
		DOOR = 10,
		ENEMY_1 = 50,
		TILE_TOTAL
	};

	void Init(const int theScreen_Height, const int theScreen_Width, const int theNumOfTiles_Height, const int theNumOfTiles_Width, const int theMap_Height, const int theMap_Width, const int theTileSize = 32);
	bool LoadMap(const string mapName);
	int GetNumOfTiles_Height(void);			//Get the number of tiles for the height of the screen
	int GetNumOfTiles_Width(void);			//Get the number of tiles for width of the screen
	int GetTileSize(void);

	int getNumOfTiles_MapHeight(void);		//Get the number of tiles for the height of the map
	int getNumOfTiles_MapWidth(void);		//Get the number of tiles for width of the map

	void InitMap();

	void InitScreenMap(vector<CEnemy*> &enemyList);

	//Codes for scrolling
	int mapOffset_x, mapOffset_y;
	int tileOffset_x, tileOffset_y;
	int mapFineOffset_x, mapFineOffset_y;

	//Number of ties in the map's width
	int theNumOfTiles_MapWidth;

	//Screen height
	int theScreen_Height;

	//Map Inits
	CMap *m_cMap;
	CMap *m_cScreenMap;

	vector<vector<int> > theScreenMap;
	bool scroll;

private:
	int theScreen_Width;				//Width of the screen
	int theNumOfTiles_Height;			//Number of tiles in the screen's height
	int theNumOfTiles_Width;			//Number of tiles in the screen's width
	int theTileSize;

	int theMap_Height;					//The map's height
	int theMap_Width;					//The map's width
	int theNumOfTiles_MapHeight;		//Number of tiles in the map's height

	bool LoadFile(const string mapName);
};
