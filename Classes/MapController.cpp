//
//  MapController.cpp
//  MatchPuzzleRPGT
//
//

#include "MapController.h"

MapController::MapController(StageData *stageData)
{
    _IDpool_mapItem = new IDPool();
    initMap(stageData);
}

MapController::~MapController()
{
    CC_SAFE_DELETE(_IDpool_mapItem);
    CC_SAFE_DELETE(_mapLayer);
}

bool MapController::initMap(StageData *stageData)
{
    if (stageData == nullptr) {
        return false;
    }
    
    
    _stageData = stageData;
    
    _mapLayer = createMapLayerFromData();
    
    //createEnemies();
    createEnemiesDebug();
    
    return true;
}

MapLayer* MapController::getMapLayer()
{
    return _mapLayer;
}


int MapController::getPlayerX()
{
    return _playerItem->getX();
}

int MapController::getPlayerY()
{
    return _playerItem->getY();
}


void MapController::movePlayerTo(int x, int y)
{
    _lastPlayerX = _playerItem->getX();
    _lastPlayerY = _playerItem->getY();
    
    _playerItem->setXY(x, y);
    // TODO: may update rendering
}


MapLayer* MapController::createMapLayerFromData()
{
    if (_stageData == nullptr ||
        _playerItem == nullptr) {
        return nullptr;
    }
    auto mapFilename = StageData::getMapTMXFilename(0); //TODO: get from _stageData
    //auto mapFilename = StageData::getMapTMXFilename(_stageData->_mapID); //TODO: get from _stageData
    auto playerFilename = "Player_on_map.png"; //TODO: get from _playerItem // remove
    
    auto layer = MapLayer::create(mapFilename, playerFilename);
    return layer;
}

bool MapController::removeMapItem(uint32_t id)
{
    bool ret = false;
    
    if (_IDpool_mapItem->exist(id)) {
        _mapItems.erase(id);
        _IDpool_mapItem->removeID(id);
        ret = true;
    }
    
    return ret;
}


bool MapController::removeMapItem(IMapItem* pItem)
{
    if (pItem == nullptr)
        return false;
    return removeMapItem(pItem->getID());
}



bool MapController::createPlayerItem(int x, int y, const std::string &imagePath)
{
    if (_mapLayer == nullptr || _playerItem == nullptr) {
        return false;
    }
    
    _playerItem = new MapItemPlayer(x, y, imagePath);
    auto id = _IDpool_mapItem->generateID();
    _playerItem->setID(id);
    auto sprite = Sprite::create(imagePath);
    //change this to pixel coordinate
    sprite->setPosition(_mapLayer->convertToPixelPos(Vec2(x,y)));
    _playerItem->setSprite(sprite);
    _mapLayer->initPlayer(sprite);
    
    return true;
}


uint32_t MapController::createEnemyItem(int x, int y, const std::string &imagePath)
{
    uint32_t id = 0;
    
    if (_mapLayer == nullptr) {
        return 0;
    }
    
    auto enemy = new MapItemEnemy(x,y,imagePath);
    id = _IDpool_mapItem->generateID();
    enemy->setID(id);
    auto sprite = Sprite::create(imagePath);
    //change this to pixel coordinate
    sprite->setPosition(_mapLayer->convertToPixelPos(Vec2(x,y)));
    enemy->setSprite(sprite);
    _enemyItems[id] = enemy;
    _mapLayer->addChild(sprite);
    
    return id;
}

// -- private --


//NOTE: not used
/*
std::map<uint32_t, MapItemEnemy*>::iterator MapController::findMapItem(uint32_t id)
{
    std::map<uint32_t, MapItemEnemy*>::iterator it;
    for (it = _mapItems.begin(); it != _mapItems.end(); it++) {
        if ((*it).second->getID() == id) {
            return it;
        }
    }
    return it;
}

std::map<uint32_t, MapItemEnemy*>::iterator MapController::findMapItem(IMapItem* ptr)
{
    return find(_mapItems.begin(), _mapItems.end(), ptr);
}
*/
void MapController::createEnemies()
{
    
}

void MapController::createEnemiesDebug()
{
    //TODO: should create every enemy from csv/json data later
    EnemyStatusData* data;
    data = new EnemyStatusData(0,    // enemyID,
                               "element_0.png",   //iconPath,
                               //std::string imagePath,
                               "EnemyName_0",     //enemyName,
                               ElementType::RED,  //type,
                               0,    //level,
                               10,   //hp,
                               1     //atk
                               );
    //_enemyItems.push_back(new MapItemEnemy(1,2,data));
    
    data = new EnemyStatusData(0,    // enemyID,
                               "element_0.png",   //iconPath,
                               //std::string imagePath,
                               "EnemyName_0",     //enemyName,
                               ElementType::RED,  //type,
                               0,    //level,
                               10,   //hp,
                               1     //atk
                               );
    //_enemyItems.push_back(new MapItemEnemy(2,0,data));
    
    data = new EnemyStatusData(0,    // enemyID,
                               "element_0.png",   //iconPath,
                               //std::string imagePath,
                               "EnemyName_0",     //enemyName,
                               ElementType::RED,  //type,
                               0,    //level,
                               10,   //hp,
                               1     //atk
                               );
    //_enemyItems.push_back(new MapItemEnemy(4,2,data));
}



