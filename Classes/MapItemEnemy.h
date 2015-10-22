//
//  MapItemEnemy.h
//  MatchPuzzleRPGT
//
//

#pragma once

#include "cocos2d.h"

#include "MapItemBase.h"
#include "EnemyStatusData.h"

USING_NS_CC;

class MapItemEnemy : public MapItemBase
{
private:
    EnemyStatusData* _statusData;
public:
    MapItemEnemy(int x, int y, const std::string &imagePath);
    MapItemEnemy(int x, int y, bool movable, const std::string &imagePath);
    MapItemEnemy(int x, int y, const std::string &imagePath, EnemyStatusData* statusData);
    MapItemEnemy();
    
    void setStatusData(EnemyStatusData* statusData);
};
