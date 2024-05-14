#include "PauseLayer.h"
#include "GameLayer.h"
using namespace CocosDenshion;




PauseLayer::PauseLayer(void)
{
	
}


PauseLayer::~PauseLayer(void)
{
}

bool PauseLayer::init(CCRenderTexture* snapshoot){

	bool bRet=false;
	do{
		CC_BREAK_IF(!CCLayer::init());

		SimpleAudioEngine::sharedEngine()->stopAllEffects();
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();

		CCTexture2D* bgTexture=snapshoot->getSprite()->getTexture();
		CCSprite* bg=CCSprite::createWithTexture(bgTexture);
		bg->setAnchorPoint(ccp(0,0));
		bg->setFlipY(true);
		this->addChild(bg,0);

		CCLayer* blend=CCLayerColor::create(ccc4(0, 0, 0, 150),winSize.width,winSize.height);
		this->addChild(blend,1);

		//produce the menu_bar
		CCSprite* menu_bar_b = CCSprite::create("menu_bar2.png");
		menu_bar_b->setAnchorPoint(ccp(0,0));
		this->addChild(menu_bar_b,2);


		CCSprite* menu_bar_t = CCSprite::create("menu_bar3.png");
		menu_bar_t->setAnchorPoint(ccp(0,0));
		menu_bar_t->setPosition(ccp(0,winSize.height-menu_bar_t->getContentSize().height));
		this->addChild(menu_bar_t,2);

		CCSprite* pause_title=CCSprite::createWithSpriteFrameName("pause_title.png");
		pause_title->setAnchorPoint(ccp(0,0));
		pause_title->setPosition(ccp(2,winSize.height-pause_title->getContentSize().height-2));
		this->addChild(pause_title,3);

		CCMenuItem* resume_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("resume.png"),NULL,NULL,this,menu_selector(PauseLayer::onResume));
		CCMenuItem* btm_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("btm.png"),NULL,NULL,this,menu_selector(PauseLayer::onBackToMenu));
	
		pauseMenu =CCMenu::create(resume_btn,btm_btn,NULL);
		pauseMenu->alignItemsVerticallyWithPadding(26);
		pauseMenu->setPosition(ccp(winSize.width/2,winSize.height/2+30));
		this->addChild(pauseMenu,3);

		CCSprite* surrender_text=CCSprite::createWithSpriteFrameName("surrender_tips.png");
		surrender_text->setPosition(ccp(winSize.width/2,winSize.height/2-23));
		this->addChild(surrender_text,4);

		bgm_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("bgm_on.png"),CCSprite::createWithSpriteFrameName("bgm_off.png"),NULL,this,menu_selector(PauseLayer::onBGM));
		voice_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("voice_on.png"),CCSprite::createWithSpriteFrameName("voice_off.png"),NULL,this,menu_selector(PauseLayer::onVoice));
		soundMenu =CCMenu::create(bgm_btn,voice_btn,NULL);
		soundMenu->alignItemsHorizontallyWithPadding(25);
		soundMenu->setPosition(ccp(pauseMenu->getPositionX(),pauseMenu->getPositionY()-80));
		this->addChild(soundMenu,4);

		pre_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("preload_on.png"),CCSprite::createWithSpriteFrameName("preload_off.png"),NULL,this,menu_selector(PauseLayer::onPreload));
		preMenu =CCMenu::create(pre_btn,NULL);
		preMenu->alignItemsHorizontallyWithPadding(25);
		preMenu->setPosition(ccp(pauseMenu->getPositionX(),preMenu->getPositionY()-84));
		this->addChild(preMenu,4);

		if(CCUserDefault::sharedUserDefault()->getBoolForKey("isBGM")==false){
			bgm_btn->selected();
			
		}
		if(CCUserDefault::sharedUserDefault()->getBoolForKey("isVoice")==false){
			voice_btn->selected();
		}

		if(CCUserDefault::sharedUserDefault()->getBoolForKey("isPreload")==false){
			pre_btn->selected();
		}
	

		bRet=true;
	}while(0);

	return bRet;

}
void PauseLayer::onBGM(CCObject* sender){
	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isBGM")==true){
			CCUserDefault::sharedUserDefault()->setBoolForKey("isBGM", false);
			bgm_btn->selected();
	}else{
		CCUserDefault::sharedUserDefault()->setBoolForKey("isBGM", true);
		bgm_btn->unselected();
	}
}


void PauseLayer::onVoice(CCObject* sender){
	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isVoice")==true){
		CCUserDefault::sharedUserDefault()->setBoolForKey("isVoice", false);
		voice_btn->selected();
	}else{
		CCUserDefault::sharedUserDefault()->setBoolForKey("isVoice", true);
		voice_btn->unselected();
	}
}

void PauseLayer::onPreload(CCObject* sender){
	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isPreload")==true){
		CCUserDefault::sharedUserDefault()->setBoolForKey("isPreload", false);
		pre_btn->selected();
	}else{
		CCUserDefault::sharedUserDefault()->setBoolForKey("isPreload", true);
		pre_btn->unselected();
	}
}

void PauseLayer::onResume(CCObject* sender){
	
	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isBGM")!=false){
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	}
	
	CCDirector::sharedDirector()->popScene();
	
};

void PauseLayer::onBackToMenu(CCObject* sender){

	pauseMenu->setVisible(false);
	soundMenu->setVisible(false);
    SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/select.mp3");
	exitLayer=CCLayer::create();

	CCSprite* exit_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
	exit_bg->setPosition(ccp(winSize.width/2,winSize.height/2));

	CCSprite* comfirm_title=CCSprite::createWithSpriteFrameName("confirm_title.png");
	comfirm_title->setPosition(ccp(winSize.width/2,winSize.height/2+38));

	CCSprite* surrender_text=CCSprite::createWithSpriteFrameName("surrender_text.png");
	surrender_text->setPosition(ccp(winSize.width/2,winSize.height/2+8));

	CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("yes_btn1.png"),CCSprite::createWithSpriteFrameName("yes_btn2.png"),this,menu_selector(PauseLayer::onLeft));
    CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(PauseLayer::onCancel));

	CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
	confirm_menu->alignItemsHorizontallyWithPadding(24);
	confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-30));

	exitLayer->addChild(exit_bg,1);
	exitLayer->addChild(confirm_menu,2);
	exitLayer->addChild(comfirm_title,2);
	exitLayer->addChild(surrender_text,2);
	this->addChild(exitLayer,500);

};

void PauseLayer::onLeft(CCObject* sender){
	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/confirm.ogg");
	_delegate->_isSurrender=true;
	CCDirector::sharedDirector()->popScene();	
}

void PauseLayer::onCancel(CCObject* sender){

	pauseMenu->setVisible(true);
	soundMenu->setVisible(true);
	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/cancel.ogg");
	exitLayer->removeFromParent();

}


PauseLayer*  PauseLayer::create(CCRenderTexture* snapshoot){
	PauseLayer* pl=new  PauseLayer();
	if (pl && pl->init(snapshoot))
	{
		pl->autorelease();
		return pl;
	}
	else
	{
		delete pl;
		return NULL;
	}
}
