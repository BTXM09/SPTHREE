#pragma once
#include <Vector2.h>
#include "Strategy.h"
#include "Node.h"
#include "Pathfinding.h"

class CMap;

class CStrategy_Kill : public CStrategy
{

public:
	CStrategy_Kill();
	~CStrategy_Kill();

	void Update(CMap* map, Vector3& enemyTile, Vector3& heroTile,Vector3& enemyDir, vector<CGoodies*> goodyList);
	void SetDestination(const float x, const float y);
	void SetEnemyPosition(const float x, const float y);
	void GetEnemyPosition(float& x, float& y);
	
	string pathFind(const int& xStart, const int& yStart, const int& xFinish, const int& yFinish, vector<CGoodies*> goodyList);

	bool detectionCheck(CMap* map, Vector3& enemyTile, Vector3& heroTile, Vector3& enemyDir);

private:
	string route, route2;
	int routeCounter, routeCounter2;
	Vector3 oldTile, currTile;
	bool checkMoved;
	bool isAttacking;
};

