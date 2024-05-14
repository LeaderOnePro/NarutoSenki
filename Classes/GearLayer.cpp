#include "GearLayer.h"
#include "GameLayer.h"
#include "HudLayer.h"
#include "Characters.h"
using namespace CocosDenshion;

/*----------------------
init GearButton ;
----------------------*/
GearButton::GearButton(void)
{
	soIcon=NULL;
	_isBuyed=false;
}


GearButton::~GearButton(void)
{
	
}


bool GearButton::init(const char *szImage){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCSprite::init());
		if(strcmp(szImage,"")!=0)
		this->initWithSpriteFrameName(szImage);


		this->setAnchorPoint(ccp(0,0));

		bRet=true;

	}while(0);

	return bRet;

}

void GearButton::onEnter(){
	CCSprite::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-1,true);
}
void GearButton::onExit(){
	CCSprite::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

CCRect GearButton::getRect(){
	CCSize size=this->getContentSize();
	return CCRect(0,0, size.width, size.height);

}
bool GearButton::containsTouchLocation(CCTouch *touch){

	return getRect().containsPoint(convertTouchToNodeSpace(touch));
}


void GearButton::setBtnType(gearType type,gearbtnType type2,bool isBuyed){
	
	_gearType=type;
	_btnType=type2;

	if(_btnType==0){
		CCSprite* gearIcon=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("gear_%02d.png",gearType(_gearType))->getCString());
		gearIcon->setAnchorPoint(ccp(0.5f,0.5f));
		gearIcon->setPosition(ccp(20,30));
		this->addChild(gearIcon);

	}else{
		CCSprite* gearIcon=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("gear_%02d.png",gearType(_gearType))->getCString());
		gearIcon->setAnchorPoint(ccp(0.5f,0.5f));
		gearIcon->setScale(0.75f);
		this->addChild(gearIcon);
	}

	if(isBuyed){
		_isBuyed=true;
		soIcon=CCSprite::createWithSpriteFrameName("gear_so.png");
		soIcon->setAnchorPoint(ccp(0.5f,0.5f));
		soIcon->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
		this->addChild(soIcon);

	}

	
}

gearType	GearButton::getBtnType(){
	return _gearType;
}

bool GearButton::ccTouchBegan(CCTouch* touch,CCEvent* event){
	// touch area 
	if (!this->containsTouchLocation(touch) ||  soIcon){

		return false;
	}else{
		return true;
	}


}

void GearButton::ccTouchMoved(CCTouch* touch,CCEvent* event){
	// touch area 


}

void GearButton::ccTouchEnded(CCTouch* touch,CCEvent* event){
	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isVoice")!=false){
	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/select.mp3");
	}
	if(!_isBuyed){
		_delegate->currentGear=this->_gearType;
	}
	

	CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("gearDetail_%02d.png",gearType(_gearType))->getCString()); 
	_delegate->gearDetail->setDisplayFrame(frame);
};



void GearButton::playSound(){


}

GearButton* GearButton::create( const char *szImage ){
	GearButton* mb=new GearButton();
	if (mb && mb->init(szImage))
	{
		mb->autorelease();
		return mb;
	}
	else
	{
		delete mb;
		return NULL;
	}
}




ScrewLayer::ScrewLayer(void)
{
	_delegate=NULL;
	_gearArray=NULL;

}


ScrewLayer::~ScrewLayer(void)
{
}


bool ScrewLayer::init(){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());

		bRet=true;

	}while(0);

	return bRet;

}

void ScrewLayer::onEnter(){
	CCLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
};

void ScrewLayer::onExit(){
	CCLayer::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
};

bool ScrewLayer::ccTouchBegan(CCTouch* touch,CCEvent* event){

	prePosY=NULL;
	return true;

};

void ScrewLayer::ccTouchMoved(CCTouch* touch,CCEvent* event){
	// touch area 
	CCPoint curPoint = touch->getLocation();
	if(prePosY==NULL){
		prePosY=curPoint.y;
	}else{
		float distanceY=curPoint.y-prePosY;
		if(this->getPositionY()<totalRow*74 || distanceY<0){
			this->setPositionY(this->getPositionY()+distanceY);

		}
		if((this->screwBar->getPositionY()>90|| distanceY<0 ) && this->screwBar->getPositionY()<=122 ){
			this->screwBar->setPositionY(this->screwBar->getPositionY()-distanceY);
		}

		if(this->screwBar->getPositionY()>122 ){
			this->screwBar->setPositionY(122);
		}

		if(this->screwBar->getPositionY()<90 ){
			this->screwBar->setPositionY(90);
		}


		prePosY=curPoint.y;

	}

};


void ScrewLayer::ccTouchEnded(CCTouch* touch,CCEvent* event){
	prePosY=NULL;
	//CCLOG("%f",this->getPositionY());
	//CCLOG("Height:%f",this->getContentSize().height);

	if(this->getPositionY()>totalRow*74-74){
		this->setPositionY(totalRow*65);
	}
	if(this->getPositionY()<76){
		this->setPositionY(76);
	}

	if(this->screwBar->getPositionY()>122 ){
		this->screwBar->setPositionY(122);
	}

	if(this->screwBar->getPositionY()<90 ){
		this->screwBar->setPositionY(90);
	}
};





GearLayer::GearLayer(void)
{
	currentGear_layer=NULL;
	currentGear=None;
}


GearLayer::~GearLayer(void)
{
}

bool GearLayer::init(CCRenderTexture* snapshoot){

	bool bRet=false;
	do{
		CC_BREAK_IF(!CCLayer::init());

		SimpleAudioEngine::sharedEngine()->stopAllEffects();
		

		CCTexture2D* bgTexture=snapshoot->getSprite()->getTexture();
		CCSprite* bg=CCSprite::createWithTexture(bgTexture);
		bg->setAnchorPoint(ccp(0,0));
		bg->setFlipY(true);
		this->addChild(bg,0);

		CCLayer* blend=CCLayerColor::create(ccc4(0, 0, 0, 150),winSize.width,winSize.height);
		this->addChild(blend,1);

		
		//ÈÌ¾ß½çÃæ


		

		CCLayer* gears_layer=CCLayer::create();

		gears_bg=CCSprite::createWithSpriteFrameName("gears_bg.png");
		gears_bg->setAnchorPoint(ccp(0.5f,0.5f));
		gears_bg->setPosition(ccp(winSize.width/2,winSize.height/2-12));
		gears_layer->addChild(gears_bg,1);

		coinLabel=CCLabelBMFont::create("0","Fonts/arial.fnt");
		coinLabel->setAnchorPoint(ccp(0,0));
		coinLabel->setPosition(ccp(gears_bg->getPositionX()+2,58));
		gears_layer->addChild(coinLabel,2);

		
		this->addChild(gears_layer,10);



		CCClippingNode* clipper = CCClippingNode::create();
		CCNode *stencil = CCSprite::createWithSpriteFrameName("screwMask.png");
		stencil->setAnchorPoint(ccp(0,0));
		clipper->setStencil(stencil);

		_screwLayer=ScrewLayer::create();
		_screwLayer->setAnchorPoint(ccp(0,0));
		_screwLayer->setPositionY(76);
		_screwLayer->gearNum=9;


		_screwLayer->screwBar=CCSprite::createWithSpriteFrameName("screwBar.png");
		_screwLayer->screwBar->setAnchorPoint(ccp(0.5f,0));
		_screwLayer->screwBar->setPosition(ccp(gears_bg->getPositionX()+25,126));
		this->addChild(_screwLayer->screwBar,600);


		gearDetail=CCSprite::createWithSpriteFrameName("gearDetail_00.png");
		gearDetail->setAnchorPoint(ccp(0.5f,1));
		gearDetail->setPosition(ccp(gears_bg->getPositionX()+gears_bg->getContentSize().width/2-54,210));
		this->addChild(gearDetail,600);

	


		CCMenuItem* buy_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("gearBuy_btn.png"),
			CCSprite::createWithSpriteFrameName("gearBuy_btn2.png"),this,menu_selector(GearLayer::onGearBuy));
		CCMenu* gearMenu=CCMenu::create(buy_btn,NULL);
		gearMenu->setPosition(ccp(gears_bg->getPositionX()+78,65));
		this->addChild(gearMenu,600);
		clipper->setPosition(ccp(gears_bg->getPositionX()-gears_bg->getContentSize().width/2+4,85));
		clipper->addChild(_screwLayer);
		this->addChild(clipper,600);



		CCMenuItem* btm_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("close_btn1.png"),
			CCSprite::createWithSpriteFrameName("close_btn2.png"),this,menu_selector(GearLayer::onResume));
		CCMenu* overMenu=CCMenu::create(btm_btn,NULL);
		overMenu->setPosition(ccp(winSize.width/2+gears_bg->getContentSize().width/2-12,winSize.height/2+gears_bg->getContentSize().height/2-20));
		this->addChild(overMenu,600);


		


		bRet=true;
	}while(0);

	return bRet;

}



void GearLayer::onResume(CCObject* sender){
	
	this->getDelegate()->getHudLayer()->updateGears();
	CCDirector::sharedDirector()->popScene();
	
};


void GearLayer::onGearBuy(CCObject* sender){

	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isVoice")!=false){
		SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/confirm.ogg");
	}

	if( _delegate->currentPlayer->setGear(currentGear)){
		this->updatePlayerGear();
	}
	
};

void GearLayer::updatePlayerGear(){


	if(_delegate->currentPlayer->getGearArray() && _delegate->currentPlayer->getGearArray()->count()>0){

		if(currentGear_layer!=NULL){
			currentGear_layer->removeFromParentAndCleanup(true);
		}
		currentGear_layer=CCLayer::create();
		currentGear_layer->setAnchorPoint(ccp(0,0));
		CCObject* pObject;
		int i=0;
		CCARRAY_FOREACH(_delegate->currentPlayer->getGearArray(),pObject){
			CCString* tmpGear=(CCString*) pObject;
			GearButton* btn=GearButton::create("");
			btn->setBtnType(gearType(atoi(tmpGear->getCString())),gearbtnType(1),false);
			btn->setPositionX(13+i*34);
			btn->setDelegate(this);
			currentGear_layer->addChild(btn);
			i++;
		}
		currentGear_layer->setPosition(ccp(gears_bg->getPositionX()-gears_bg->getContentSize().width/2+8,64));
		this->addChild(currentGear_layer,800);
	}

	
	coinLabel->setString(CCString::createWithFormat("%d",atoi(_delegate->currentPlayer->getCoin()->getCString()))->getCString());
	this->updateGearList();

};

void GearLayer::updateGearList(){

		if(!_screwLayer->getGearArray()){
			_screwLayer->setGearArray(CCArray::create());
		}else{

			CCObject* pObject;
			CCARRAY_FOREACH(_screwLayer->getGearArray(),pObject){
				GearButton* btn=(GearButton*) pObject;
				btn->removeFromParentAndCleanup(true);
			}
		}
		currentGear=None;
		_screwLayer->totalRow=3;
		for(int i=0;i<_screwLayer->gearNum;i++){
			int row=int(floor(float(i)/3));
			int column=abs(3*row-i);
		 
			GearButton* btn;
			if(column>=1){
				btn=GearButton::create("value_1000.png");
			}else{
				btn=GearButton::create("value_500.png");
			}
			bool isBuyed=false;
			if(_delegate->currentPlayer->getGearArray() && _delegate->currentPlayer->getGearArray()->count()>0){
				CCObject* pObject;
				CCARRAY_FOREACH(_delegate->currentPlayer->getGearArray(),pObject){
					CCString* tmpGear=(CCString*) pObject;
					if (atoi(tmpGear->getCString())== i){
						isBuyed=true;
					}
				}
			}

			if(currentGear==None && !isBuyed){
				currentGear=gearType(i);
				CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("gearDetail_%02d.png",i)->getCString()); 
				gearDetail->setDisplayFrame(frame);
			}

			btn->setPosition(ccp(6+column*46,-row*60));
			btn->setAnchorPoint(ccp(0,0));
			btn->setBtnType(gearType(i),gearbtnType(0),isBuyed);
			btn->setDelegate(this);
			_screwLayer->getGearArray()->addObject(btn);
			_screwLayer->addChild(btn);

		}
		
	
}


GearLayer*  GearLayer::create(CCRenderTexture* snapshoot){
	GearLayer* grl=new  GearLayer();
	if (grl && grl->init(snapshoot))
	{
		grl->autorelease();
		return grl;
	}
	else
	{
		delete grl;
		return NULL;
	}
}
