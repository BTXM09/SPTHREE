#include "Strategy.h"
#include <iostream>

using namespace std;

CStrategy::CStrategy() : isAttacking(false), theDestination(0,0), theEnemyPosition(0,0), theEnemyPath(CPathing::CPathing()), CurrentState(IDLE)
{
}

CStrategy::~CStrategy()
{
}

void CStrategy::Update(CMap* map, Vector3& enemyTile, Vector3& heroTile, Vector3& enemyDir, vector<CGoodies*> goodyList, int &routeCounter, int &routeCounter2, bool heroInvis, bool &eneHit, vector<GameObject*> &goList, float &eneROF, double dt)
{
	cout << "void CStrategy::Update()" << endl;
}

int CStrategy::CalculateDistance()
{
	return ((theDestination.x - theEnemyPosition.x) * (theDestination.x - theEnemyPosition.x) +
			(theDestination.y - theEnemyPosition.y) * (theDestination.y - theEnemyPosition.y));
}
