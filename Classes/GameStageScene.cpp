//
//  GameStageScene.cpp
//  MatchPuzzleRPGT
//
//

#include "GameStageScene.h"

GameStageScene::GameStageScene():
_layout(nullptr),
_background(nullptr),
_homeButton(nullptr),
_exitButton(nullptr),
_selectStageButton(nullptr),
_stageID(0),
_currentStageData(nullptr),
_currentStageScore(nullptr),
_stageManager(nullptr)
{
    
}

GameStageScene::~GameStageScene()
{
    
}

bool GameStageScene::init()
{
    if (Layer::init()==false) {
        return false;
    }
    
    auto viewSize=Director::getInstance()->getVisibleSize();
    
    _layout = CSLoader::createNode("ui/GameStageScene.csb");
    _layout->setName("LAYOUT");
    
    // TODO: may create only once in SceneMediator?
    //_background = SceneMediator::getInstance()->getMainBackground();
    _background = MainBackground::create();
    _layout->getChildByName("ImageView_background")->addChild(_background);
    
    _homeButton = dynamic_cast<ui::Button*>(_layout->getChildByName("Button_backHome"));
    _exitButton = dynamic_cast<ui::Button*>(_layout->getChildByName("Button_exit"));
    _selectStageButton = dynamic_cast<ui::Button*>(_layout->getChildByName("Button_selectStage"));
    
    this->addChild(_layout);
    
    //initialize ui event listener
    _selectStageButton->addClickEventListener([](Ref* ref) {
        SceneMediator::getInstance()->gotoStageSelectScene();
    });
    _homeButton->addClickEventListener([](Ref* ref) {
        SceneMediator::getInstance()->gotoHomeScene();
    });
    
    _exitButton->addClickEventListener([](Ref* ref) {
        Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    });

    return true;
}



bool GameStageScene::initData(StageDataManager* stageManager, uint32_t stageID)
{
    _stageManager = stageManager;
    _currentStageScore = stageManager->getStageScoreRecord(stageID);
    
    // visualize map and puzzle here
    
    return true;
}


Scene* GameStageScene::createScene(StageDataManager* stageManager, uint32_t stageID)
{
    auto layer = GameStageScene::create();
    
    layer->initData(stageManager, stageID);
    
    auto scene = Scene::create();
    scene->addChild(layer);
    
    return scene;
}

