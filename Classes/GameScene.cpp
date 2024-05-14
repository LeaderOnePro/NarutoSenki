#include "GameScene.h"
using namespace CocosDenshion;

USING_NS_CC;


int adResult=0;


GameScene::GameScene(void)
{
	_menuLayer=NULL;
	pushMenu=NULL;
}
GameScene::~GameScene(void)
{
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCScene::init()); //对父类初始化

		if(!CCUserDefault::sharedUserDefault()->getBoolForKey("isHavingSave")){

			CCUserDefault::sharedUserDefault()->setBoolForKey("isHavingSave", true);
			CCUserDefault::sharedUserDefault()->setBoolForKey("isBGM", true);
			CCUserDefault::sharedUserDefault()->setBoolForKey("isVoice", true);

			CCUserDefault::sharedUserDefault()->flush();
		}


		introLayer=CCLayer::create();

		CCSprite* zakume=CCSprite::create("zakume.png");
		zakume->setPosition(ccp(winSize.width/2,winSize.height/2));
		CCActionInterval* fadein=CCFadeIn::create(1.5f);
		CCActionInterval* fadeout=CCFadeOut::create(1.5f);
		CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(GameScene::onLogo));
		CCAction* seq=CCSequence::create(fadein,fadeout,call,NULL);
		introLayer->addChild(zakume);
		zakume->runAction(seq);
		this->addChild(introLayer);


		//内部测试↓


		/*KTools* tool= KTools::create();
		tool->initTableInDB();


		tool->initColumeInDB();


		CCLayer* menuLayer=StartMenu::create();
		this->addChild(menuLayer);*/

	
		bRet=true;


	}while(0);

	return bRet;

}

void GameScene::onLogo(){
	
	CCMenuItem* logo_btn=CCMenuItemSprite::create(CCSprite::create("logo.png"),NULL,NULL,this,menu_selector(GameScene::onLogoClick));
	logo_btn->setAnchorPoint(ccp(0.5f,0.5f));
	
	logoMenu =CCMenu::create(logo_btn,NULL);
	logoMenu->setPosition(ccp(winSize.width/2,winSize.height-logo_btn->getContentSize().height/2));
	introLayer->addChild(logoMenu,3);


	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/intro.ogg");

	CCActionInterval* fade=CCFadeIn::create(1.5f);
	CCFiniteTimeAction *call1=CCCallFunc::create(this,callfunc_selector(GameScene::onPlayEffect2));
	CCFiniteTimeAction *call2=CCCallFunc::create(this,callfunc_selector(GameScene::onFinish));

	CCAction* seq=CCSequence::create(fade,
		call1,
		CCDelayTime::create(2.0f),
		call2,
		NULL
		);
    logo_btn->runAction(seq);

}

void GameScene::onLogoClick(CCObject* sender){
	Cheats+=1;
	if (Cheats==10){
		SimpleAudioEngine::sharedEngine()->stopAllEffects();
		logoMenu->removeFromParent();

		CCMenuItem* logo_btn=CCMenuItemSprite::create(CCSprite::create("logo2.png"),NULL,NULL,this,menu_selector(GameScene::onLogoClick));
		logo_btn->setAnchorPoint(ccp(0.5f,0.5f));
		
		logoMenu =CCMenu::create(logo_btn,NULL);
		logoMenu->setPosition(ccp(winSize.width/2,winSize.height-logo_btn->getContentSize().height/2));
		introLayer->addChild(logoMenu,3);

	}else if (Cheats>10){
		SimpleAudioEngine::sharedEngine()->stopAllEffects();
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/chang_btn.ogg");
		this->onFinish();
	}
}

void GameScene::onPlayEffect2(){

	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/intro2.ogg");
}


void GameScene::onFinish(){


	if(!pushMenu){
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/Music/intro_music.mp3",true);
		CCMenuItem* btm_btn=CCMenuItemSprite::create(CCSprite::create("push_start.png"),NULL,NULL,this,menu_selector(GameScene::onPush));
		pushMenu=CCMenu::create(btm_btn,NULL);


		pushMenu->setPosition(ccp(winSize.width/2,winSize.height/2-100));
		introLayer->addChild(pushMenu);
		CCActionInterval* fade=CCFadeOut::create(0.5f);
		CCActionInterval* seq=CCSequence::create(fade,fade->reverse(),NULL);
		btm_btn->runAction(CCRepeatForever::create(seq)) ;
	}
	

	


}

void GameScene::onPush(CCObject* sender){
	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/confirm.ogg");
	
	KTools* tool= KTools::create();
	
	tool->initTableInDB();

	tool->initColumeInDB();

	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();

	CCScene* menuScene =CCScene::create();
	CCLayer* menuLayer=StartMenu::create();
	menuScene->addChild(menuLayer);
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f,menuScene));
	
	
}



