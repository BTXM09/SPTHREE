#pragma once
#include <Vector2.h>
#include "Strategy.h"
#include "Node.h"
#include "Pathfinding.h"

class CStrategy_Kill
	: public CStrategy
{

public:
	CStrategy_Kill();
	~CStrategy_Kill();

	void Update(CMap* map, Vector3& enemyTile, Vector3& heroTile);
	void SetDestination(const float x, const float y);
	void SetEnemyPosition(const float x, const float y);
	void GetEnemyPosition(float& x, float& y);

	//The AI states of the enemy
	enum CURRENT_STATE
	{
		PATROL,
		REPEL,
		ATTACK,
		NUM_ENEMY_STATE,
	};

	void SetState(CStrategy_Kill::CURRENT_STATE);
	CStrategy_Kill::CURRENT_STATE GetState();
	
	string pathFind (const int& xStart, const int& yStart, const int& xFinish, const int& yFinish);
private:
	//Enemy AI State
	CStrategy_Kill::CURRENT_STATE CurrentState;

	string route;
	int routeCounter;

	Vector3 oldTile, currTile;
	
	bool checkMoved;
};

