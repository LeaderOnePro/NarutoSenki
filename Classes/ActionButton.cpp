#include "ActionButton.h"
#include "HudLayer.h"

ActionButton::ActionButton(void)
{
	_isDoubleSkill=false;
	_freezeAction=NULL;
	markSprite=NULL;
	_clickTime=0;
	_clickNum=0;
	cdLabel=NULL;
	_isMarkVisable=true;
	_timeCout=NULL;
	_isLock=false;
	_coldDown=NULL;
	_isColdChanged=false;
	_gearType=None;

	proressblinkSprite=NULL;
	proressmarkSprite=NULL;
	proressblinkSprite=NULL;
	progressPointSprite=NULL;
	proressblinkMask=NULL;
	gearSign =NULL;
}


ActionButton::~ActionButton(void)
{
	CC_SAFE_RELEASE(_timeCout);
	CC_SAFE_RELEASE(_coldDown);
}

bool ActionButton::init(const char *szImage){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCSprite::init());
		this->initWithSpriteFrameName(szImage);
		this->setAnchorPoint(ccp(0,0));

		bRet=true;

	}while(0);

	return bRet;

}

void ActionButton::onEnter(){
	CCSprite::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-50,true);
}
void ActionButton::onExit(){
	CCSprite::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

CCRect ActionButton::getRect(){
	CCSize size=this->getContentSize();
	return CCRect(0,0, size.width, size.height);

}
bool ActionButton::containsTouchLocation(CCTouch *touch){
	return getRect().containsPoint(convertTouchToNodeSpace(touch));
}

bool  ActionButton::ccTouchBegan(CCTouch* touch,CCEvent* event){
	
	// touch area 
	if (!this->containsTouchLocation(touch) || _delegate->_isAllButtonLocked){
		return false;
	}
	click();
	
	return true;

}
void ActionButton::ccTouchEnded(CCTouch* touch,CCEvent* event){
	if(_abType==NAttack)
	_delegate->attackButtonRelease();
}

void ActionButton::click(){
	if( (_delegate && this->isCanClick()) ){

		if(!_isDoubleSkill ){
			this->beganAnimation();
		}

		if(!_delegate->_isAllButtonLocked){
			if(_abType==GearItem ){
				_delegate->gearButtonClick(_gearType);
			}else{
				_delegate->attackButtonClick(_abType);
			}
			
		}
		
	}
};



bool ActionButton::isCanClick(){
	//recorde current time sec format;
	

	cc_timeval timeVal;
	CCTime::gettimeofdayCocos2d(&timeVal, 0);
	float curTime = timeVal.tv_sec * 1000 + timeVal.tv_usec / 1000;
	
	 if(this->_abType!=NAttack ){

		if(this->_isDoubleSkill){
			//double click solution
				if(_clickNum==0 && _delegate->getSkillFinish() && !_timeCout && !_delegate->ougisLayer ){
					return true;
				}else if(_clickNum==1 && _delegate->getSkillFinish() && !_delegate->ougisLayer ){
					return true;
				}

		 }else{
			 
	 // isSkillFinish consider the AttackAction is done or not to prevent the skill invalid release 
			 if(this->getABType()==Item1 ){
				
				 if(!_delegate->ougisLayer &&!_timeCout  && !_isLock &&_delegate->_delegate->currentPlayer->getActionState()!=ACTION_STATE_DEAD){
					 if(_delegate->offCoin(_cost)){
						 return true;
					 }
				 }
				
			 }else if(this->_abType==GearBtn){
				  if(!_isLock){
					  this->_delegate->_delegate->onGear();

				  }
				   return false;

			 }else if(this->_abType==GearItem ){

				 if(!_delegate->ougisLayer &&!_timeCout  && !_isLock){
					 if(this->_gearType== gear06  && _delegate->_delegate->currentPlayer->getActionState()!=ACTION_STATE_DEAD ){
						 return true;
					 }else if(this->_gearType== gear00 && _delegate->getSkillFinish()){
						 return true;
			
					 }else if( this->_gearType== gear03){
						 return true;
					 }
				 }


			 }
			 //ougis click solution
			 else if(this->_abType==OUGIS1){
				 if(_delegate->getSkillFinish() /*&& _delegate->getOugisEnable(false)  && !_isLock*/  && !_delegate->ougisLayer ){
					 _delegate->costCKR(15000,false);	
					 return true;
				 }
			 }else if(this->_abType==OUGIS2){

				 if(_delegate->getSkillFinish() /*&&_delegate->getOugisEnable(true)   && !_isLock  */&& !_delegate->ougisLayer){
					 _delegate->costCKR(25000,true);	
					 return true;
				 }
				
			 }else{
				 if( !_timeCout && _delegate->getSkillFinish() && !_isLock  && !_delegate->ougisLayer){
					 return true;
				 }
			 }
		 }

		 return false;
	 }else{
		return true;
	 }
};

void ActionButton::beganAnimation(bool isLock){
	//record the click time
	cc_timeval timeVal;
	CCTime::gettimeofdayCocos2d(&timeVal, 0);
	_clickTime = timeVal.tv_sec * 1000 + timeVal.tv_usec / 1000;

	if(markSprite && this->getABType()!=OUGIS1 && this->getABType()!=OUGIS2){
		if(!_freezeAction || _isColdChanged){
			if(_isColdChanged){
				_isColdChanged=false;
			}
			this->createFreezeAnimation();
		};

		
		this->setTimeCout(this->getCD());
		if(cdLabel){
			cdLabel->removeFromParent();
			this->unschedule(schedule_selector(ActionButton::updateCDLabel));
		}
		if(this->getABType()!=Item1){
			
			cdLabel=CCLabelBMFont::create(CCString::createWithFormat("%d",int(this->getCD()->intValue())/1000)->getCString(),"Fonts/1.fnt");
			cdLabel->setScale(0.4f);
			cdLabel->setPosition(ccp(this->getPositionX()+this->getContentSize().width/2,
				this->getPositionY()+this->getContentSize().height/2));
			this->_delegate->addChild(cdLabel,200);
			
		}
		this->schedule(schedule_selector(ActionButton::updateCDLabel),1.0f);

		markSprite->stopAllActions();

		markSprite->runAction(_freezeAction);
	
	}
	

};

void ActionButton::setGearType(int tmpGearType){

	CCSprite* gearIcon=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("gear_%02d.png",gearType(tmpGearType))->getCString());
	gearIcon->setAnchorPoint(ccp(0.5f,0.5f));
	gearIcon->setScale(0.85f);
	gearIcon->setPosition(ccp(18,18));
	this->addChild(gearIcon);
	this->_gearType=gearType(tmpGearType);
	
	if(this->gearSign){
		this->gearSign->removeFromParent();
		this->gearSign=NULL;
	}
}

void ActionButton::updateCDLabel(float dt){

	if( !_delegate->ougisLayer){

		if(atoi(this->getTimeCout()->getCString())>1000){
			int tempCout=atoi(this->getTimeCout()->getCString())-1000;
			this->setTimeCout(CCString::createWithFormat("%d",tempCout));
			if(cdLabel){
				cdLabel->setString(CCString::createWithFormat("%d",tempCout/1000)->getCString());
			}
			
		}else{
			this->unschedule(schedule_selector(ActionButton::updateCDLabel));
			this->setTimeCout(NULL);
			if(cdLabel){
			cdLabel->removeFromParent();
			cdLabel=NULL;
			}
		}
	};
};

void ActionButton::setMarkSprite(const char* mark){
	CCSprite* tmpSprite =CCSprite::createWithSpriteFrameName(mark);
	markSprite=CCProgressTimer::create(tmpSprite);
	markSprite->setType(kCCProgressTimerTypeRadial);
	
	markSprite->setReverseDirection(true);
	markSprite->setPosition(this->getPosition());
	markSprite->setAnchorPoint(ccp(0,0));
	this->_delegate->addChild(markSprite,500);

	if(this->getABType()==GearBtn){
		if(_delegate->_delegate->_isHardCoreGame){
			gearSign =CCSprite::createWithSpriteFrameName("gearsign.png");
			gearSign->setPosition(ccp(this->getPositionX()+17,this->getPositionY()+17));
			this->_delegate->addChild(gearSign,500);
		}
		

	}
};

void ActionButton::setOugisMark(){
	ougismarkSprite =CCSprite::createWithSpriteFrameName("skill_freeze.png");
	ougismarkSprite->setPosition(this->getPosition());
	ougismarkSprite->setAnchorPoint(ccp(0,0));
	this->_delegate->addChild(ougismarkSprite,500);
	if (this->getABType()== OUGIS1){
	lockLabel1=CCLabelBMFont::create("LV2","Fonts/1.fnt");
	}else{
	lockLabel1=CCLabelBMFont::create("LV4","Fonts/1.fnt");
	}
	lockLabel1->setScale(0.4f);
	lockLabel1->setPosition(ccp(this->getPositionX()+this->getContentSize().width/2,
		this->getPositionY()+this->getContentSize().height/2));
	this->_delegate->addChild(lockLabel1,200);
}

void ActionButton::setProgressMark(){

	clipper = CCClippingNode::create();
	CCNode *stencil = CCSprite::createWithSpriteFrameName("icon_bg1.png");
	stencil->setAnchorPoint(ccp(0,0));
	clipper->setStencil(stencil);

	proressmarkSprite=CCSprite::createWithSpriteFrameName("icon_bg2.png");

	clipper->setPosition(this->getPosition());
	clipper->addChild(proressmarkSprite);

	proressmarkSprite->setAnchorPoint(ccp(0.5f,0.5f));
	proressmarkSprite->setPosition(ccp(proressmarkSprite->getContentSize().width/2,proressmarkSprite->getContentSize().height/2));
	//50,120,180
	
	this->_delegate->addChild(clipper,-50);
	

	proressblinkSprite =CCSprite::createWithSpriteFrameName("icon_bg3.png");
	proressblinkSprite->setPosition(this->getPosition());
	proressblinkSprite->setAnchorPoint(ccp(0.5f,0.5f));
	proressblinkSprite->setPosition(ccp(proressmarkSprite->getContentSize().width/2,proressmarkSprite->getContentSize().height/2));
	

	CCFadeOut* fd=CCFadeOut::create(0.2f);
	proressblinkSprite->runAction(CCRepeatForever::create(fd));
	clipper->addChild(proressblinkSprite,50);
	

	if (this->getABType()== OUGIS1){
	progressPointSprite=CCSprite::createWithSpriteFrameName("icon_bg4.png");
	proressmarkSprite->setRotation(-50);
	proressblinkSprite->setRotation(-50);
	progressPointSprite->setPosition(this->getPosition());
	}else{
	progressPointSprite=CCSprite::createWithSpriteFrameName("icon_bg5.png");
	proressmarkSprite->setRotation(-85);
	proressblinkSprite->setRotation(-85);
	progressPointSprite->setPosition(ccp(this->getPositionX()+1,this->getPositionY()));
	}

	
	progressPointSprite->setAnchorPoint(ccp(0,0));
	this->_delegate->addChild(progressPointSprite,-25);

	CCFadeOut* fd2=CCFadeOut::create(0.5f);
	proressblinkMask=CCSprite::createWithSpriteFrameName("icon_bg6.png");
	proressblinkMask->setPosition(this->getPosition());
	proressblinkMask->setAnchorPoint(ccp(0,0));
	proressblinkMask->runAction(CCRepeatForever::create(fd2));


	this->_delegate->addChild(proressblinkMask,200);

	if(this->getABType()==OUGIS2){

		if(_delegate->skill4Button){
			if(_delegate->skill4Button->proressblinkMask && !_delegate->skill4Button->_isLock){
				_delegate->skill4Button->proressblinkMask->stopAllActions();
				CCFadeOut* fd2=CCFadeOut::create(0.5f);
				_delegate->skill4Button->proressblinkMask->runAction(CCRepeatForever::create(fd2));
			}

		}
	}

}

void ActionButton::updateProgressMark(){
	float ckr=atof(_delegate->_delegate->currentPlayer->getCKR()->getCString());
	float ckr2=atof(_delegate->_delegate->currentPlayer->getCKR2()->getCString());
	if (this->getABType()== OUGIS1){
		if(ckr<15000){
			if(proressblinkSprite){
				proressblinkSprite->setRotation(0);
			}
			if(proressmarkSprite){
			proressmarkSprite->setRotation(-1*((ckr/15000)*50));
			}
			if(proressblinkMask){
				proressblinkMask->setVisible(false);
			}
			
		}else if(ckr<30000){
			if(proressblinkSprite){
			proressblinkSprite->setRotation(-50);
			}
			if(proressmarkSprite){
			proressmarkSprite->setRotation(-1*(((ckr-15000)/15000)*70+50));
			}
			if(proressblinkMask && !_isLock){
			
				proressblinkMask->setVisible(true);
				proressblinkMask->stopAllActions();
				CCFadeOut* fd2=CCFadeOut::create(0.5f);
				proressblinkMask->runAction(CCRepeatForever::create(fd2));

				if(_delegate->skill5Button){
					if(_delegate->skill5Button->proressblinkMask && !_delegate->skill5Button->_isLock){
						_delegate->skill5Button->proressblinkMask->stopAllActions();
						CCFadeOut* fd2=CCFadeOut::create(0.5f);
						_delegate->skill5Button->proressblinkMask->runAction(CCRepeatForever::create(fd2));
					}

				}

			}

			


		}else if(ckr<45000) {
			if(proressblinkSprite){
			proressblinkSprite->setRotation(-120);
			}
			if(proressmarkSprite){
			proressmarkSprite->setRotation(-1*(((ckr-30000)/15000)*60+120));
			}
		}else{
			if(proressblinkSprite){
			proressmarkSprite->setRotation(-180);
			}
			if(proressblinkSprite){
				proressblinkSprite->setRotation(-180);
			}
			
		}
	}else{
		if(ckr2<25000){
			if(proressblinkSprite){
			proressblinkSprite->setRotation(0);
			}
			if(proressmarkSprite){
				proressmarkSprite->setRotation(-1*((ckr2/25000)*85));
			}
			if(proressblinkMask){
				proressblinkMask->setVisible(false);
			}
		}else if(ckr2<50000){
			if(proressblinkSprite){
			proressblinkSprite->setRotation(-85);
			}
			if(proressmarkSprite){
				proressmarkSprite->setRotation(-1*(((ckr2-25000)/25000)*90+90));
			}
			
			if(proressblinkMask && !_isLock){
				
				proressblinkMask->setVisible(true);
				proressblinkMask->stopAllActions();
				CCFadeOut* fd2=CCFadeOut::create(0.5f);
				proressblinkMask->runAction(CCRepeatForever::create(fd2));

				if(_delegate->skill4Button){
					if(_delegate->skill4Button->proressblinkMask && !_delegate->skill4Button->_isLock){
						_delegate->skill4Button->proressblinkMask->stopAllActions();
						CCFadeOut* fd2=CCFadeOut::create(0.5f);
						_delegate->skill4Button->proressblinkMask->runAction(CCRepeatForever::create(fd2));
					}

				}
			}

			

		}else{
			if(proressmarkSprite){
				proressmarkSprite->setRotation(-180);
			}
			
			if(proressblinkSprite){
			proressblinkSprite->setRotation(-180);
			}
		}
	}


}

void ActionButton::setLock(){

	if(markSprite){
		markSprite->stopAllActions();
		markSprite->setPercentage(100);
	}else{
		this->setMarkSprite("skill_freeze.png");
	}

	if(proressblinkMask){
		proressblinkMask->setVisible(false);
	}
	_isLock=true;
}

void ActionButton::unLock(){
	if(markSprite){
		markSprite->stopAllActions();
		markSprite->setPercentage(0);
	}

	float ckr=atof(_delegate->_delegate->currentPlayer->getCKR()->getCString());
	float ckr2=atof(_delegate->_delegate->currentPlayer->getCKR2()->getCString());

	if (this->getABType()== OUGIS1){
		if(ckr>=15000){
			if(proressblinkMask){
				proressblinkMask->setVisible(true);
			}
		}
	}else if(this->getABType()== OUGIS2) {
		if(ckr2>=25000){
			if(proressblinkMask){
			proressblinkMask->setVisible(false);
			}
		}
	}
	
	_isLock=false;
}

void ActionButton::createFreezeAnimation(){

	CCFiniteTimeAction *to = CCProgressTo::create(0, 99.999f);
	
	
	int delay=_coldDown->intValue()/1000;
	
	CCFiniteTimeAction *to1 = CCProgressTo::create(delay, 0);

	CCAction* freezeAction;
	if(_isDoubleSkill){
		CCFiniteTimeAction *callback = CCCallFunc::create(this, callfunc_selector(ActionButton::clearClick));
		freezeAction= CCSequence::create(to, to1, callback,NULL);
	} else{
		freezeAction= CCSequence::create(to, to1, NULL);
	}
	
	this->setFreezeAction(freezeAction);

};

void ActionButton::clearClick(){
	_clickNum=0;
}

void ActionButton::clearOugisMark(){
	if(this->ougismarkSprite){
		this->ougismarkSprite->removeAllChildrenWithCleanup(true);
	}
	
	if(this->clipper){
		this->clipper->removeFromParentAndCleanup(true);
	}
	if(this->progressPointSprite){
		this->progressPointSprite->removeFromParent();
	}
	if(this->proressblinkMask){
		this->proressblinkMask->removeFromParent();
	}
	

}


ActionButton*  ActionButton::create( const char *szImage ){
	 ActionButton* ab=new  ActionButton();
	if (ab && ab->init(szImage))
	{
		ab->autorelease();
		return ab;
	}
	else
	{
		delete ab;
		return NULL;
	}
}