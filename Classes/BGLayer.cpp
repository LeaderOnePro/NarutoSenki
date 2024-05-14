#include "BGLayer.h"


BGLayer::BGLayer(void)
{
	texMap=NULL;
}



BGLayer::~BGLayer(void)
{
}


bool BGLayer::init(){
	bool bRet=false;
	do{

		CC_BREAK_IF(!CCLayer::init());

		bRet=true;

	}while(0);

	return bRet;

}

void BGLayer::initBg(){

	if(_delegate->randomMap==0){
		bgMap=CCSprite::create("Tiles/map_bg1.png");
	}else if(_delegate->randomMap==1){
		bgMap=CCSprite::create("Tiles/map_bg2.png");
	}else if(_delegate->randomMap==2){
		bgMap=CCSprite::create("Tiles/map_bg3.png");
	}else if(_delegate->randomMap==3){
		bgMap=CCSprite::create("Tiles/map_bg4.png");
	}else if(_delegate->randomMap==4){
		bgMap=CCSprite::create("Tiles/map_bg5.png");
	}

	

	bgMap->setAnchorPoint(ccp(0,0));
	bgMap->setPosition(ccp(0,192));

	this->addChild(bgMap);

}

void BGLayer::setDelegate(GameLayer* layer){
	_delegate=layer;
	this->initBg();
}
