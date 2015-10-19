//
//  SceneMediator.cpp
//  MatchPuzzleRPGT
//
//

#include "SceneMediator.h"

#include "HomeScene.h"
#include "StatusScene.h"

SceneMediator* SceneMediator::_instance = nullptr;

SceneMediator* SceneMediator::getInstance()
{
    if (_instance == nullptr) {
        _instance = new SceneMediator();
    }
    
    return _instance;
}

// TODO: not used now, MAY MAINTAIN ONE HERE
MainBackground* SceneMediator::getMainBackground()
{
    if (_mainBackground == nullptr) {
        _mainBackground = MainBackground::create();
    }
    return _mainBackground;
}

StatusDataManager* SceneMediator::getStatusDataManager()
{
    if (_statusDataManager == nullptr) {
        _statusDataManager = StatusDataManager::create();
        // TODO: fix here by replacing with initFromLocalData();
        //_statusDataManager->initWithDebugData();
        _statusDataManager->initFromLocalData("data/PlayerStatusData.csv", "data/UnitOfPlayerRecords.csv");
    }
    return _statusDataManager;
}


StageDataManager* SceneMediator::getStageDataManager()
{
    if (_stageDataManager == nullptr) {
        _stageDataManager = StageDataManager::create();
        // TODO: fix here by replacing with initFromLocalData();
        //_stageDataManager->initWithDebugData();
        _stageDataManager->initFromLocalData("data/StageData.csv", "data/StageScoreRecords.csv");
    }
    return _stageDataManager;
}

void SceneMediator::gotoHomeScene()
{
    auto scene = HomeScene::createScene();
    
    Director::getInstance()->replaceScene(TransitionFade::create(0.25, scene));
}

void SceneMediator::gotoStageSelectScene()
{
    
}

void SceneMediator::gotoGameStageScene()
{
    
}

void SceneMediator::gotoStageScoreScene()
{
    auto scene = StageScoreScene::createScene();
    
    Director::getInstance()->replaceScene(TransitionFade::create(0.25, scene));
}

void SceneMediator::gotoStatusScene()
{
    
    auto scene = StatusScene::createScene();
    
    Director::getInstance()->replaceScene(TransitionFade::create(0.25, scene));
}
