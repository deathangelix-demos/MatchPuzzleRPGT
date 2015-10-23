//
//  GameStageController.cpp
//  MatchPuzzleRPGT
//
//

#include "GameStageController.h"

GameStageController::GameStageController():
_jewelsGrid(nullptr),
_stageData(nullptr)
{
    
}

GameStageController::~GameStageController()
{
    
}

GameStageController* GameStageController::create(StageData *stageData)
{
    auto c = new GameStageController();
    
    if (c && c->initWithoutData()) {
        //m->autorelease();
        c->initWithData(stageData);
        return c;
    }
    
    CC_SAFE_DELETE(c);
    
    return nullptr;
}

bool GameStageController::initWithoutData()
{
    return true;
}

bool GameStageController::initWithData(StageData *stageData)
{
    _stageData = stageData;
    _mapController = new MapController(stageData);
    
    CC_ASSERT(_mapController->getMapLayer() != nullptr);
    
    //TODO: may grid size  here!_
    _jewelsGrid = JewelsGrid::create(6, 6);
    
    return true;
}

JewelsGrid* GameStageController::getJewelsGrid()
{
    return _jewelsGrid;
}

MapLayer* GameStageController::getMapLayer()
{
    return _mapController->getMapLayer();
}


bool GameStageController::tryMovePlayerUp()
{
    return _mapController->tryMovePlayerUp();
}

bool GameStageController::tryMovePlayerDown()
{
    return _mapController->tryMovePlayerDown();
}

bool GameStageController::tryMovePlayerLeft()
{
    return _mapController->tryMovePlayerLeft();
}

bool GameStageController::tryMovePlayerRight()
{
    return _mapController->tryMovePlayerRight();
}


