#include "JoyStick.h"
#include "HudLayer.h"

JoyStick::JoyStick(void)
{
	_delegate=NULL;
	
}


JoyStick::~JoyStick(void)
{
}


bool JoyStick::init(){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCSprite::init());
		//CC_BREAK_IF(!CCSprite:initWithSpriteFrameName("JoyStickBg.png"));
		this->initWithSpriteFrameName("JoyStickBg.png");
		this->setAnchorPoint(ccp(0,0));
		

		_joyStickControl=CCSprite::createWithSpriteFrameName("JoyStick.png");
	    _joyStickControl->setAnchorPoint(ccp(0,0));

		_defaultPotion=ccp(this->getContentSize().width/2-_joyStickControl->getContentSize().width/2,
			this->getContentSize().height/2-_joyStickControl->getContentSize().height/2);

		_joyStickControl->setPosition(_defaultPotion);
		this->addChild(_joyStickControl);

		bRet=true;

	}while(0);

	return bRet;

}

void JoyStick::onEnter(){
	CCSprite::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
};

void JoyStick::onExit(){
	CCSprite::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
};

bool JoyStick::ccTouchBegan(CCTouch* touch,CCEvent* event){
	CCPoint curPoint = touch->getLocation();
	if (curPoint.x > winSize.width / 2 || curPoint.y > winSize.height / 2){
		return false;
	}
	
	return true;


};

void JoyStick::ccTouchMoved(CCTouch* touch,CCEvent* event){
	if(!_delegate->_isAllButtonLocked){
		this->updateDirectionForTouchLocation(touch);
	}
	

};


void JoyStick::ccTouchEnded(CCTouch* touch,CCEvent* event){
	if(!_delegate->_isAllButtonLocked){
	_joyStickControl->setPosition(_defaultPotion);
	_delegate->JoyStickRelease();
	}
	
};

void JoyStick::updateDirectionForTouchLocation(CCTouch* touch){

	CCPoint startPoint=ccp(32+this->getContentSize().width/2,
		32+this->getContentSize().height/2);
	CCPoint curPoint = touch->getLocation();
	//向量
	CCPoint sp=ccpSub(curPoint,startPoint);
	//弧度
	float radians = ccpToAngle(sp);
	//角度
	float degrees = -1 * CC_RADIANS_TO_DEGREES(radians);
	float distance = ccpDistance(curPoint,startPoint);

	if (degrees <= 22.5 && degrees >= -22.5){
		//right
		_direction = ccp(1.0, 0.0);}
	else if (degrees > 22.5 && degrees < 67.5){
		//bottom right
		_direction = ccp(1.0, -1.0);}
	else if (degrees >= 67.5 && degrees <= 112.5){
		//bottom
		_direction = ccp(0.0, -1.0);}
	else if (degrees > 112.5 && degrees < 157.5){
		//bottom left
		_direction = ccp(-1.0, -1.0);}
	else if (degrees >= 157.5 || degrees <= -157.5){
		//left
		_direction = ccp(-1.0, 0.0);}
	else if (degrees < -22.5 && degrees > -67.5){
		//top right
		_direction = ccp(1.0, 1.0);}
	else if (degrees <= -67.5 && degrees >= -112.5){
		//top
		_direction = ccp(0.0, 1.0);}
	else if (degrees < -112.5 && degrees > -157.5){
		//top left
		_direction = ccp(-1.0, 1.0);};

		this->updateJoyStick(distance,_direction);
		_delegate->JoyStickUpdate(_direction);
}

void JoyStick::updateJoyStick(float distance,CCPoint direction){
	if (distance < 27.5) {
		_joyStickControl->setPosition(ccpAdd(_defaultPotion, (ccpMult(direction,distance))));
	} /*else if (distance > 96) {
		_joyStickControl->setPosition(ccpAdd(_defaultPotion,ccpMult(direction,53)));
	} */else {
		_joyStickControl->setPosition(ccpAdd(_defaultPotion , (ccpMult(direction,26.5))));

	}

};
