#include "CCScrewLayer.h"


CCScrewLayer::CCScrewLayer(void)
{
	itemArray=NULL;
	totalRow=100;
	minY=154;
	line_height=26;
}


CCScrewLayer::~CCScrewLayer(void)
{
}


bool CCScrewLayer::init(){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());

		bRet=true;

	}while(0);

	return bRet;

}

void CCScrewLayer::onEnter(){
	CCLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,1,true);
};

void CCScrewLayer::onExit(){
	CCLayer::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
};

bool CCScrewLayer::ccTouchBegan(CCTouch* touch,CCEvent* event){

	prePosY=NULL;
	return true;

};

void CCScrewLayer::ccTouchMoved(CCTouch* touch,CCEvent* event){
	// touch area 
	CCPoint curPoint = touch->getLocation();
	if(prePosY==NULL){
		prePosY=curPoint.y;
	}else{
		float distanceY=curPoint.y-prePosY;
		if(this->getPositionY()<totalRow*line_height || distanceY<0){
			this->setPositionY(this->getPositionY()+distanceY);

		}

		prePosY=curPoint.y;

	}

};


void CCScrewLayer::ccTouchEnded(CCTouch* touch,CCEvent* event){
	prePosY=NULL;

	//CCLOG("y:%f",this->getPositionY());
	if(this->getPositionY()>totalRow*line_height-line_height){
		this->setPositionY(totalRow*line_height);
	}
	if(this->getPositionY()<minY){
		this->setPositionY(minY);
	}


};



/*----------------------
init CCScrewItem ;
----------------------*/
CCScrewItem::CCScrewItem(void)
{
	 linemenu=NULL;
	 lockItem=NULL;
}


CCScrewItem::~CCScrewItem(void)
{

}

bool CCScrewItem::init(){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCSprite::init());
		
		
		bRet=true;

	}while(0);

	return bRet;

}

void CCScrewItem::onEnter(){
	CCSprite::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
}
void CCScrewItem::onExit(){
	CCSprite::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

CCRect CCScrewItem::getRect2(){
	CCSize size=this->getContentSize();
	return CCRect(0,0, size.width, size.height);

}

bool CCScrewItem::containsTouchLocation(CCTouch *touch){

	return getRect2().containsPoint(convertTouchToNodeSpace(touch));
}

bool CCScrewItem::ccTouchBegan(CCTouch* touch,CCEvent* event){
	// touch area 
	if (!this->containsTouchLocation(touch))
		return false;


	return true;

}
void CCScrewItem::ccTouchEnded(CCTouch* touch,CCEvent* event){
	linemenu->setVisible(true);
};


