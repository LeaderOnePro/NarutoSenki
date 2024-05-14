#include "Characters.h"
#include "HudLayer.h"
USING_NS_CC;


HeroElement::HeroElement(void)
{
	rebornSprite=NULL;
}


HeroElement::~HeroElement(void)
{
	CC_SAFE_RELEASE(callValue);	
	CC_SAFE_RELEASE(_nattackType);
	CC_SAFE_RELEASE(_sattackType1);
	CC_SAFE_RELEASE(_sattackType2);
	CC_SAFE_RELEASE(_sattackType3);
	CC_SAFE_RELEASE(_sattackType4);
	CC_SAFE_RELEASE(_sattackType5);
	CC_SAFE_RELEASE(_spcattackType1);
	CC_SAFE_RELEASE(_spcattackType2);
	CC_SAFE_RELEASE(_spcattackType3);
	CC_SAFE_RELEASE(_damageArray);
	CC_SAFE_RELEASE(_monsterArray);
	CC_SAFE_DELETE(skillSPC1Array);
	CC_SAFE_RELEASE(skillSPC2Array);
	CC_SAFE_RELEASE(skillSPC3Array);
	CC_SAFE_RELEASE(skillSPC4Array);
	CC_SAFE_RELEASE(skillSPC5Array);
	CC_SAFE_RELEASE(nattackArray);
	CC_SAFE_RELEASE(walkArray);
	CC_SAFE_RELEASE(knockDownArray);
	CC_SAFE_RELEASE(skill1Array);
	CC_SAFE_RELEASE(skill2Array);
	CC_SAFE_RELEASE(skill3Array);
	CC_SAFE_RELEASE(skill4Array);
	CC_SAFE_RELEASE(skill5Array);
	CC_SAFE_RELEASE(idleArray);

}

bool HeroElement::init(){
	bool bRet = false;
	do {

		CC_BREAK_IF(!ActionManager::init());
		this->setAnchorPoint(ccp(0.5,0));		
		this->scheduleUpdate();
		//this->schedule(schedule_selector(HeroElement::neicun),0.5f);
		bRet=true;
	}while(0);

	return bRet;

};

void HeroElement::setID(CCString* character,CCString* role,CCString* group){
	
	this->setCharacter(character);
	this->setRole(role);
	this->setGroup(group);

	CCArray* animationArray=CCArray::create();
	const char* filePath;
	
	KTools* tool= KTools::create();
	
	filePath=CCString::createWithFormat("Element/%s/%s.xml",this->getCharacter()->getCString(),this->getCharacter()->getCString())->getCString();
		
	std::string key =tool->getKeycode(filePath);
	int id=tool->checkMD5(filePath);
	
	if(strcmp(key.c_str(),_delegate->KeyList[id])!=0){
		//return;
	}
	
	
	

	


	tool->readXMLToArray(filePath,animationArray);	

	


	//init Attribute; & indleFrame

	CCArray* tmpAction=(CCArray*)(animationArray->objectAtIndex(0));
	CCArray* tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	idleArray=(CCArray*)(tmpAction->objectAtIndex(1));

	if(strcmp(this->getCharacter()->getCString(),"Kakashi")==0||
		strcmp(this->getCharacter()->getCString(),"Deidara")==0 ||
		strcmp(this->getCharacter()->getCString(),"Suigetsu")==0 ||
		strcmp(this->getCharacter()->getCString(),"Jugo")==0 ||
		strcmp(this->getCharacter()->getCString(),"Gaara")==0  || 
		strcmp(this->getCharacter()->getCString(),"Itachi")==0 ||
		strcmp(this->getCharacter()->getCString(),"ImmortalSasuke")==0 ||
		strcmp(this->getCharacter()->getCString(),"Sasuke")==0 ||
		strcmp(this->getCharacter()->getCString(),"Choji")==0 ||
		strcmp(this->getCharacter()->getCString(),"Tsunade")==0 ||
		strcmp(this->getCharacter()->getCString(),"Hidan")==0 ||
		strcmp(this->getCharacter()->getCString(),"Roshi")==0 ||
		strcmp(this->getCharacter()->getCString(),"Han")==0 ||
		strcmp(this->getCharacter()->getCString(),"Hiruzen")==0 ||
		strcmp(this->getCharacter()->getCString(),"Sai")==0||
		strcmp(this->getCharacter()->getCString(),"Kiba")==0 ||
		strcmp(this->getCharacter()->getCString(),"Akamaru")==0 ||
		strcmp(this->getCharacter()->getCString(),"Konan")==0 ||
		strcmp(this->getCharacter()->getCString(),"Naruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"SageNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"Kisame")==0
		){
		idleArray->retain();
	} 

	
	CCString* tmpName;
	CCString* tmpHpMax;
	int tmpWidth;
	int tmpHeight;
	unsigned int tmpSpeed;
	int tmpCombatPoint;
	this->readDate(tmpDate,tmpName,tmpHpMax,tmpWidth,tmpHeight,tmpSpeed,tmpCombatPoint);
	this->setMaxHP(CCString::createWithFormat("%d",atoi(tmpHpMax->getCString())));
	this->setHP(CCString::create(this->getMaxHP()->getCString()));
	
	this->setHeight(tmpHeight);
	this->setWalkSpeed(tmpSpeed);
	_originSpeed=tmpSpeed;

	//觉醒必备
	if(this->getKillNum()==NULL){
		this->setKillNum(CCString::createWithFormat("%d",0));
	}
	
	if(!this->getCKR() && !this->getCKR2()){
		this->setCKR(CCString::create("0"));
		this->setCKR2(CCString::create("0"));
	}

	
	//init WalkFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(1));
	walkArray=(CCArray*)(tmpAction->objectAtIndex(1));

	if(strcmp(this->getCharacter()->getCString(),"Konan")==0 ||
		strcmp(this->getCharacter()->getCString(),"Deidara")==0 ||
		strcmp(this->getCharacter()->getCString(),"Suigetsu")==0 ||
		strcmp(this->getCharacter()->getCString(),"Jugo")==0 ||
		strcmp(this->getCharacter()->getCString(),"Itachi")==0 ||
		strcmp(this->getCharacter()->getCString(),"ImmortalSasuke")==0 ||
		strcmp(this->getCharacter()->getCString(),"Sasuke")==0 ||
		strcmp(this->getCharacter()->getCString(),"Lee")==0 ||
		strcmp(this->getCharacter()->getCString(),"RockLee")==0 ||
		strcmp(this->getCharacter()->getCString(),"Choji")==0 ||
		strcmp(this->getCharacter()->getCString(),"Tsunade")==0 ||
		strcmp(this->getCharacter()->getCString(),"Hidan")==0 ||
		strcmp(this->getCharacter()->getCString(),"Shino")==0 ||		
		strcmp(this->getCharacter()->getCString(),"Roshi")==0 ||
		strcmp(this->getCharacter()->getCString(),"Han")==0||
		strcmp(this->getCharacter()->getCString(),"Hiruzen")==0 ||
		strcmp(this->getCharacter()->getCString(),"Sai")==0||
		strcmp(this->getCharacter()->getCString(),"Kiba")==0 ||
		strcmp(this->getCharacter()->getCString(),"Akamaru")==0 ||
		strcmp(this->getCharacter()->getCString(),"Gaara")==0  || 
		strcmp(this->getCharacter()->getCString(),"Naruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"SageNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"Tobi")==0||
		strcmp(this->getCharacter()->getCString(),"Parents")==0||
		strcmp(this->getCharacter()->getCString(),"Kisame")==0
		){
			walkArray->retain();
	} 
	 

	//init HurtFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(2));
	hurtArray=(CCArray*)(tmpAction->objectAtIndex(1));

	if(strcmp(this->getCharacter()->getCString(),"Sasuke")==0||
		strcmp(this->getCharacter()->getCString(),"ImmortalSasuke")==0 
		){
		hurtArray->retain();
	}
	

	//init AirHurtFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(3));
	airHurtArray=(CCArray*)(tmpAction->objectAtIndex(1));

	//init KnockDownFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(4));
	knockDownArray=(CCArray*)(tmpAction->objectAtIndex(1));

	if(strcmp(this->getCharacter()->getCString(),"Itachi")==0 ||
		strcmp(this->getCharacter()->getCString(),"Sasuke")==0 ||
		strcmp(this->getCharacter()->getCString(),"Naruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"SageNaruto")==0
		){
		knockDownArray->retain();
	}

	//init FloatFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(5));
	floatArray=(CCArray*)(tmpAction->objectAtIndex(1));

	//init DeadFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(6));
	deadArray=(CCArray*)(tmpAction->objectAtIndex(1));


	//init nAttack date & Frame Array
	tmpAction=(CCArray*)(animationArray->objectAtIndex(7));
	tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	CCString* tmpValue;
	unsigned int tmpCD;
	this->readDate(tmpDate,_nattackType,tmpValue,_nattackRangeX,_nattackRangeY,tmpCD,tmpCombatPoint);
	this->setnAttackValue(tmpValue);
	_nattackType->retain();

	nattackArray=(CCArray *)(tmpAction->objectAtIndex(1));

	if(strcmp(this->getCharacter()->getCString(),"Sai")==0||
		strcmp(this->getCharacter()->getCString(),"Tenten")==0||
		strcmp(this->getCharacter()->getCString(),"Suigetsu")==0 ||
		strcmp(this->getCharacter()->getCString(),"Jugo")==0 ||
		strcmp(this->getCharacter()->getCString(),"Choji")==0 ||
		strcmp(this->getCharacter()->getCString(),"Itachi")==0 ||
		strcmp(this->getCharacter()->getCString(),"Minato")==0 ||
		strcmp(this->getCharacter()->getCString(),"ImmortalSasuke")==0 ||
		strcmp(this->getCharacter()->getCString(),"Sasuke")==0 ||
		strcmp(this->getCharacter()->getCString(),"Choji")==0  ||
		strcmp(this->getCharacter()->getCString(),"Tsunade")==0 ||
		strcmp(this->getCharacter()->getCString(),"Hidan")==0 ||
		strcmp(this->getCharacter()->getCString(),"Shino")==0 ||
		strcmp(this->getCharacter()->getCString(),"Roshi")==0 ||
		strcmp(this->getCharacter()->getCString(),"Han")==0||
		strcmp(this->getCharacter()->getCString(),"Hiruzen")==0 ||
		strcmp(this->getCharacter()->getCString(),"Kiba")==0 ||
		strcmp(this->getCharacter()->getCString(),"Akamaru")==0 ||
		strcmp(this->getCharacter()->getCString(),"Naruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"SageNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"Deidara")==0 ||
		strcmp(this->getCharacter()->getCString(),"Gaara")==0  || 
		strcmp(this->getCharacter()->getCString(),"Sakura")==0 ||
		strcmp(this->getCharacter()->getCString(),"Parents")==0||
		strcmp(this->getCharacter()->getCString(),"Kisame")==0
		){

		nattackArray->retain();
	} 


	//init skill1 date & Frame Array
	tmpAction=(CCArray*)(animationArray->objectAtIndex(8));
	tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	
	this->readDate(tmpDate,_sattackType1,tmpValue,_sattackRangeX1,_sattackRangeY1,_sattackcoldDown1,_sattackCombatPoint1);	
	this->setsAttackValue1(tmpValue);
	_sattackType1->retain();

	skill1Array=(CCArray *)(tmpAction->objectAtIndex(1));



	//init skill2 date & Frame Array
	tmpAction=(CCArray*)(animationArray->objectAtIndex(9));
	tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	this->readDate(tmpDate,_sattackType2,tmpValue,_sattackRangeX2,_sattackRangeY2,_sattackcoldDown2,_sattackCombatPoint2);	
	_sattackType2->retain();
	this->setsAttackValue2(tmpValue);
	skill2Array=(CCArray *)(tmpAction->objectAtIndex(1));

	if(strcmp(this->getCharacter()->getCString(),"Kakashi")==0 ){
		skill1Array->retain();
		skill2Array->retain();
	}else if(strcmp(this->getCharacter()->getCString(),"Minato")==0 ){
		skill1Array->retain();
		skill2Array->retain();
		_sattack1isDouble=true;
	}



	//init skill3 date & Frame Array
	tmpAction=(CCArray*)(animationArray->objectAtIndex(10));
	tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	this->readDate(tmpDate,_sattackType3,tmpValue,_sattackRangeX3,_sattackRangeY3,_sattackcoldDown3,_sattackCombatPoint3);
	_sattackType3->retain();
	this->setsAttackValue3(tmpValue);
	skill3Array=(CCArray *)(tmpAction->objectAtIndex(1));
	

	//init skill4 date & Frame Array
	tmpAction=(CCArray*)(animationArray->objectAtIndex(11));
	tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	this->readDate(tmpDate,_sattackType4,tmpValue,_sattackRangeX4,_sattackRangeY4,_sattackcoldDown4,_sattackCombatPoint4);
	this->setsAttackValue4(tmpValue);
	_sattackType4->retain();
	skill4Array=(CCArray *)(tmpAction->objectAtIndex(1));

	//init skill5 date & Frame Array

	tmpAction=(CCArray*)(animationArray->objectAtIndex(12));
	tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	this->readDate(tmpDate,_sattackType5,tmpValue,_sattackRangeX5,_sattackRangeY5,_sattackcoldDown5,_sattackCombatPoint5);
	this->setsAttackValue5(tmpValue);
	_sattackType5->retain();
	skill5Array=(CCArray *)(tmpAction->objectAtIndex(1));
	

	//init specal Frame

	if(
		strcmp(this->getCharacter()->getCString(),"Tenten")==0 ||
		strcmp(this->getCharacter()->getCString(),"DevaPath")==0 ||
		strcmp(this->getCharacter()->getCString(),"Ino")==0 ||
		strcmp(this->getCharacter()->getCString(),"Sakura")==0 ||
		strcmp(this->getCharacter()->getCString(),"Tobi")==0 ||
		strcmp(this->getCharacter()->getCString(),"RockLee")==0 
		){
			tmpAction=(CCArray*)(animationArray->objectAtIndex(17));
			tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
			this->readDate(tmpDate,_spcattackType1,tmpValue,_spcattackRangeX1,_spcattackRangeY1,_spcattackcoldDown1,tmpCombatPoint);
			this->setspcAttackValue1(tmpValue);
			_spcattackType1->retain();
			skillSPC1Array=(CCArray *)(tmpAction->objectAtIndex(1));
			skillSPC1Array->retain();

	}else if(strcmp(this->getCharacter()->getCString(),"Sai")==0 ||
		strcmp(this->getCharacter()->getCString(),"Deidara")==0 ||
		strcmp(this->getCharacter()->getCString(),"SageNaruto")==0 ||
			strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"Suigetsu")==0 ||
		strcmp(this->getCharacter()->getCString(),"Jugo")==0 ||
		strcmp(this->getCharacter()->getCString(),"Kakashi")==0 ||
		strcmp(this->getCharacter()->getCString(),"Itachi")==0 ||
		strcmp(this->getCharacter()->getCString(),"Minato")==0 ||
		strcmp(this->getCharacter()->getCString(),"ImmortalSasuke")==0 ||
		strcmp(this->getCharacter()->getCString(),"Sasuke")==0		||
		strcmp(this->getCharacter()->getCString(),"Choji")==0 ||
		strcmp(this->getCharacter()->getCString(),"Tsunade")==0 ||
		strcmp(this->getCharacter()->getCString(),"Gaara")==0 ||
		strcmp(this->getCharacter()->getCString(),"Hidan")==0 ||
		strcmp(this->getCharacter()->getCString(),"Shino")==0 ||
		strcmp(this->getCharacter()->getCString(),"Roshi")==0 ||
		strcmp(this->getCharacter()->getCString(),"Han")==0||
		strcmp(this->getCharacter()->getCString(),"Hiruzen")==0 ||
		strcmp(this->getCharacter()->getCString(),"Kiba")==0 ||
		strcmp(this->getCharacter()->getCString(),"Akamaru")==0 ||
		strcmp(this->getCharacter()->getCString(),"Konan")==0 ||
		strcmp(this->getCharacter()->getCString(),"Naruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"Parents")==0||
		strcmp(this->getCharacter()->getCString(),"Kisame")==0
		){

		tmpAction=(CCArray*)(animationArray->objectAtIndex(17));
		tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
		this->readDate(tmpDate,_spcattackType1,tmpValue,_spcattackRangeX1,_spcattackRangeY1,_spcattackcoldDown1,tmpCombatPoint);
		this->setspcAttackValue1(tmpValue);
		_spcattackType1->retain();
		skillSPC1Array=(CCArray *)(tmpAction->objectAtIndex(1));
		skillSPC1Array->retain();

		tmpAction=(CCArray*)(animationArray->objectAtIndex(18));
		tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
		this->readDate(tmpDate,_spcattackType2,tmpValue,_spcattackRangeX2,_spcattackRangeY2,_spcattackcoldDown2,tmpCombatPoint);
		skillSPC2Array=(CCArray *)(tmpAction->objectAtIndex(1));
		this->setspcAttackValue2(tmpValue);
		_spcattackType2->retain();
		skillSPC2Array->retain();

		tmpAction=(CCArray*)(animationArray->objectAtIndex(19));
		tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
		this->readDate(tmpDate,_spcattackType3,tmpValue,_spcattackRangeX3,_spcattackRangeY3,_spcattackcoldDown3,tmpCombatPoint);
		skillSPC3Array=(CCArray *)(tmpAction->objectAtIndex(1));
		this->setspcAttackValue3(tmpValue);
		_spcattackType3->retain();
		skillSPC3Array->retain();

	}

	if(strcmp(this->getCharacter()->getCString(),"Itachi")==0 ||
		strcmp(this->getCharacter()->getCString(),"Choji")==0 ||
		strcmp(this->getCharacter()->getCString(),"Kiba")==0 ||
		strcmp(this->getCharacter()->getCString(),"Naruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"SageNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"Sasuke")==0||
		strcmp(this->getCharacter()->getCString(),"ImmortalSasuke")==0 
		){
		tmpAction=(CCArray*)(animationArray->objectAtIndex(16));
		skillSPC4Array=(CCArray *)(tmpAction->objectAtIndex(1));
		skillSPC4Array->retain();
	}

	if(strcmp(this->getCharacter()->getCString(),"Sasuke")==0 ||
		strcmp(this->getCharacter()->getCString(),"SageNaruto")==0 
		){
		tmpAction=(CCArray*)(animationArray->objectAtIndex(15));
		skillSPC5Array=(CCArray *)(tmpAction->objectAtIndex(1));
		skillSPC5Array->retain();
	}


	if(strcmp(this->getCharacter()->getCString(),"Kiba")==0){
		_isBati=true;
	}
	if(strcmp(this->getCharacter()->getCString(),"Kakuzu")==0){
		_heartEffect=CCSprite::createWithSpriteFrameName("Heart_Effect_00.png");
		_heartEffect->setPosition(ccp(this->getContentSize().width+40,70));
		this->addChild(_heartEffect);
	}


	_damageArray=CCArray::create();
	_damageArray->retain();

	if(this->getLV()==1 && !this->getCoin()){
		this->setGearArray(CCArray::create());
		this->setCoin(CCString::create("50"));
	}

	
	

	this->initAction();
	CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(ActionManager::acceptAttack), "acceptAttack", NULL);
	
};


void HeroElement::initAction(){

	this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
	this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
	this->setHurtAction(createAnimation(hurtArray,10.0f,false,false));

	this->setAirHurtAction(createAnimation(airHurtArray,10.0f,false,false));
	this->setKnockDownAction(createAnimation(knockDownArray,10.0f,false,true));
	this->setDeadAction(createAnimation(deadArray,10.0f,false,false));
	this->setFloatAction(createAnimation(floatArray,10.0f,false,false));


	this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
	this->setSkill1Action(createAnimation(skill1Array,10.0f,false,true));
	this->setSkill2Action(createAnimation(skill2Array,10.0f,false,true));
	this->setSkill3Action(createAnimation(skill3Array,10.0f,false,true));
	this->setSkill4Action(createAnimation(skill4Array,10.0f,false,true));
	this->setSkill5Action(createAnimation(skill5Array,10.0f,false,true));
	
	
};

void HeroElement::setShadows(){

	if(!_shadow){
		_shadow=CCSprite::createWithSpriteFrameName("shadows.png");
		_shadow->setAnchorPoint(ccp(0.5,0.5));
		_shadow->setPosition(this->getPosition());
		this->getDelegate()->shadowBatch->addChild(_shadow);
		
	}
}

void HeroElement::setHPbar(){

	

	if(strcmp(getGroup()->getCString(),_delegate->currentPlayer->getGroup()->getCString())!=0){
		_hpBar=HPBar::create("hp_bar_r.png");
	} else if((strcmp(getRole()->getCString(),"Com")==0 || 
		strcmp(getRole()->getCString(),"Clone")==0 || 
		strcmp(this->getRole()->getCString(),"Kuilei")==0 ||
		strcmp(this->getRole()->getCString(),"Summon")==0) 
		){
		_hpBar=HPBar::create("hp_bar_b.png");
	} else if(strcmp(getRole()->getCString(),"Player")==0){
		_hpBar=HPBar::create("hp_bar.png");
	}	
	_hpBar->setPositionY(this->getHeight());
	_hpBar->setDelegate(this);
	this->addChild(_hpBar);
	this->changeHPbar();
	
	
};

void HeroElement::changeHPbar(){
		
		if(_exp>=500 && _level==1){
			_level=2;
			float newValue=atof(this->getCKR()->getCString())+15001;
			this->setCKR(CCString::createWithFormat("%f",newValue));
			_isCanOugis1=true;
			if(strcmp(this->getRole()->getCString(),"Player")==0){
				
				this->getDelegate()->setCKRLose(false);
				this->getDelegate()->removeOugisMark(1);

				if(strcmp(this->getCharacter()->getCString(),"Kakuzu")==0 && this->hearts<1){
					if(_delegate->getHudLayer()->skill4Button){
						_delegate->getHudLayer()->skill4Button->setLock();
					}
				}
				if(strcmp(this->getCharacter()->getCString(),"Lee")==0 ){
						if(this->bamen<1){
							if(_delegate->getHudLayer()->skill4Button){
								_delegate->getHudLayer()->skill4Button->setLock();
							}
						}
					
				}

			}
			int tempMaxHP=atoi(this->getMaxHP()->getCString());
			tempMaxHP+=500;
			this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+9));
			_rebornTime+=1;
		}else if(_exp>=1000 && _level==2){
			_level=3;
			int tempMaxHP=atoi(this->getMaxHP()->getCString());
			tempMaxHP+=1000;
			this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+18));
			_rebornTime+=2;
		}else if(_exp>=1500 && _level==3){
			_level=4;
			float newValue=atof(this->getCKR2()->getCString())+25001;
			this->setCKR2(CCString::createWithFormat("%f",newValue));
			_isCanOugis2=true;
			if(strcmp(this->getRole()->getCString(),"Player")==0){
				
				this->getDelegate()->setCKRLose(true);
				this->getDelegate()->removeOugisMark(2);

				if(strcmp(this->getCharacter()->getCString(),"Kakuzu")==0){
					if(_delegate->getHudLayer()->skill5Button){
						_delegate->getHudLayer()->skill5Button->setLock();
					}
				}

				if(strcmp(this->getCharacter()->getCString(),"Lee")==0 ){
					if(this->bamen<3){
						if(_delegate->getHudLayer()->skill5Button){
							_delegate->getHudLayer()->skill5Button->setLock();
						}
					}
				}
			}
			int tempMaxHP=atoi(this->getMaxHP()->getCString());
			tempMaxHP+=2000;
			this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+27));
			_rebornTime+=3;

		}else if(_exp>=2000 && _level==4){
			_level=5;
			int tempMaxHP=atoi(this->getMaxHP()->getCString());
			tempMaxHP+=2500;
			this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));	
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+36));;
			_rebornTime+=4;
		}else if(_exp>=2500 && _level==5){
			_level=6;
			int tempMaxHP=atoi(this->getMaxHP()->getCString());
			tempMaxHP+=3000;
			this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));	
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+45));
			_rebornTime+=5;
		}

		if(_hpBar){	
			CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("hp_bottom%d.png",int(_level))->getCString());  
			_hpBar->getHPBottom()->setDisplayFrame(frame);
		}
	

}
void HeroElement::setAI(float dt){

}


void HeroElement::neicun(float dt){
	//CCLOG("%d",callValue->retainCount());
}


void HeroElement::dealloc(){

	this->stopAllActions();
	_actionState=ACTION_STATE_DEAD;	
	

	//不删除 标记
	if(strcmp(this->getCharacter()->getCString(),"Minato")!=0){

		if(this->getMonsterArray() && getMonsterArray()->count()>0){
			CCObject* pObject;
			CCARRAY_FOREACH(this->getMonsterArray(),pObject){
				ActionManager* mo=(ActionManager*) pObject;

				//清除角色表的monter
				int index=_delegate->_CharacterArray->indexOfObject(mo);
				if(index>=0){
					_delegate->_CharacterArray->removeObjectAtIndex(index);
				}
				CCNotificationCenter::sharedNotificationCenter()->removeObserver(mo,"acceptAttack");
				mo->stopAllActions();
				mo->unscheduleAllSelectors();
				mo->setActionState(ACTION_STATE_DEAD);
				mo->removeFromParent();
				mo=NULL;

			};
			this->getMonsterArray()->removeAllObjects();
			_monsterArray=NULL;

		}

	}

	if(strcmp(this->getRole()->getCString(),"Clone")==0 || 
			strcmp(this->getRole()->getCString(),"Kuilei")==0 ||
			strcmp(this->getRole()->getCString(),"Summon")==0 
			){
			this->unschedule(schedule_selector(ActionManager::setAI));
			CCNotificationCenter::sharedNotificationCenter()->removeObserver(this,"acceptAttack");
				
			//移除出角色表
			int index=_delegate->_CharacterArray->indexOfObject(this);
			if(index>=0){
				_delegate->_CharacterArray->removeObjectAtIndex(index);
			}
			
			if(_master &&  this->_master->getMonsterArray()){
				int index=_master->getMonsterArray()->indexOfObject(this);
				if(index>=0){
					_master->getMonsterArray()->removeObjectAtIndex(index);
				}
			}
			

			if(strcmp(this->getCharacter()->getCString(),"DevaPath")==0){
							
				this->getMaster()->_skillChangeBuffValue=NULL;

				if(strcmp(this->getMaster()->getRole()->getCString(),"Player")==0){
					if(this->_delegate->getHudLayer()->skill5Button){
						this->_delegate->getHudLayer()->skill5Button->unLock();
					}

				}

			}else if(strcmp(this->getCharacter()->getCString(),"Akamaru")==0 ||
				strcmp(this->getCharacter()->getCString(),"Karasu")==0||
				strcmp(this->getCharacter()->getCString(),"Parents")==0
				){
				_master->setActionResume();

			}else if(strcmp(this->getCharacter()->getCString(),"Sanshouuo")==0){

				if(strcmp(this->getMaster()->getRole()->getCString(),"Player")==0){

					if(this->_delegate->getHudLayer()->skill4Button){
					this->_delegate->getHudLayer()->skill4Button->unLock();
					}

				}

			}else if(strcmp(this->getCharacter()->getCString(),"MaskFudon")==0 ||
				strcmp(this->getCharacter()->getCString(),"MaskRaidon")==0 ||
				strcmp(this->getCharacter()->getCString(),"MaskKadon")==0
				){
					
				if(_master->hearts>0){
					if(strcmp(_master->getRole()->getCString(),"Player")==0){
						if(_delegate->getHudLayer()->skill4Button){
							_delegate->getHudLayer()->skill4Button->unLock();
						}
					}
				}
			}else if(strcmp(this->getCharacter()->getCString(),"Saso")==0){

				if(strcmp(this->getMaster()->getRole()->getCString(),"Player")==0){

					if(this->_delegate->getHudLayer()->skill5Button){
						this->_delegate->getHudLayer()->skill5Button->unLock();
					}
					
				}
			}

			this->removeFromParentAndCleanup(true);

		}else{
			

			if(strcmp(this->getCharacter()->getCString(),"Kankuro")==0){


				if(strcmp(this->getRole()->getCString(),"Player")==0){

					if(this->_delegate->getHudLayer()->skill4Button){
						this->_delegate->getHudLayer()->skill4Button->unLock();
					}
					if(this->_delegate->getHudLayer()->skill5Button){
					this->_delegate->getHudLayer()->skill5Button->unLock();
					}
				}

			}else if(strcmp(this->getCharacter()->getCString(),"Shikamaru")==0 ||
				strcmp(this->getCharacter()->getCString(),"Choji")==0
				){

				CCObject* pObject;
				CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
					Hero* tempHero=(Hero*) pObject;
					if(tempHero->_isSticking){
						if(tempHero->getActionState()!=ACTION_STATE_DEAD){
							tempHero->removeLostBlood(0.1f);
							tempHero->idle();
						}
						
					}

				};
			}else if(strcmp(this->getCharacter()->getCString(),"Hidan")==0){

				if(strcmp(this->getRole()->getCString(),"Player")==0 ){
					this->_delegate->getHudLayer()->skill1Button->unLock();
				}
			}


			//不删除 标记
			if(strcmp(this->getCharacter()->getCString(),"Minato")!=0 ){

				if(this->getMonsterArray() && getMonsterArray()->count()>0){
					CCObject* pObject;
					CCARRAY_FOREACH(this->getMonsterArray(),pObject){
						ActionManager* mo=(ActionManager*) pObject;

						//清除角色表的monter
						int index=_delegate->_CharacterArray->indexOfObject(mo);
						if(index>=0){
							_delegate->_CharacterArray->removeObjectAtIndex(index);
						}
						CCNotificationCenter::sharedNotificationCenter()->removeObserver(mo,"acceptAttack");
						mo->stopAllActions();
						mo->unscheduleAllSelectors();
						mo->setActionState(ACTION_STATE_DEAD);
						mo->removeFromParent();
						
					};
					this->getMonsterArray()->removeAllObjects();
					_monsterArray=NULL;
					_monsterArray->release();
					
				
				}

				

			}
			
			if(strcmp(this->getCharacter()->getCString(),"Roshi")!=0 &&
				strcmp(this->getCharacter()->getCString(),"Han")!=0
				){
					if(rebornLabelTime==3){
						this->scheduleOnce(schedule_selector(HeroElement::reborn),3.0f);
					}else{
						rebornLabelTime=this->getRebornTime();
						this->scheduleOnce(schedule_selector(HeroElement::reborn),this->getRebornTime());
					}

				

					//复活倒计时
					if(!this->rebornSprite){

						rebornSprite=CCSprite::create();
						CCSprite* skullSpirte=CCSprite::createWithSpriteFrameName("skull.png");
						skullSpirte->setPosition(ccp(0,0));
						rebornSprite->addChild(skullSpirte);

						rebornLabel=CCLabelBMFont::create(CCString::createWithFormat("%d",rebornLabelTime)->getCString(),"Fonts/1.fnt");
						rebornLabel->setScale(0.3f);
						rebornLabel->setPosition(ccp(skullSpirte->getContentSize().width,0));
						rebornSprite->addChild(rebornLabel);

						rebornSprite->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
						this->addChild(rebornSprite);

					}
					this->schedule(schedule_selector(HeroElement::countDown),1);

			}
			
			

		}
		
}
void HeroElement::countDown(float dt){

		rebornLabelTime-=1;
		rebornLabel->setString(CCString::createWithFormat("%d",rebornLabelTime)->getCString());


}
void HeroElement::reborn(float dt){

	
	this->setPosition(this->getSpawnPoint());
	

	if(this->getPosition().equals(this->getSpawnPoint()))
	{
		CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(ActionManager::acceptAttack), "acceptAttack", NULL);
		this->setOpacity(255);
		this->setHP(CCString::create(this->getMaxHP()->getCString()));
		this->setHPbar();
		this->_actionState=ACTION_STATE_HURT;
	
	

	
		if(this->getLV()<4){
			if(strcmp(this->getGroup()->getCString(),"Konoha")==0){
				this->setEXP(this->getEXP()+this->getDelegate()->kEXPBound);
			}else{
				this->setEXP(this->getEXP()+this->getDelegate()->aEXPBound);
			}
			
			this->changeHPbar();

			if(strcmp(this->getRole()->getCString(),"Player")==0){
				_delegate->getHudLayer()->setEXPLose(NULL);
			}
			
		}

		this->idle();
		if(rebornSprite){
			this->unschedule(schedule_selector(HeroElement::countDown));
			rebornSprite->removeFromParent();
			rebornSprite=NULL;
		}
		if(strcmp(this->getRole()->getCString(),"Player")!=0){	
			bool ksan=true;
			bool asan=true;
			if(CError==1){
				if(_delegate->zhenying>0) {
					ksan=false;
				}else{
					asan=false;
				}
			}
			if(strcmp(this->getGroup()->getCString(),"Konoha")==0 && ksan){
				this->doAI();
			}else if(strcmp(this->getGroup()->getCString(),"Akatsuki")==0  && asan){
				this->doAI();
			}
			
		}else{
			if(this->_isAI){
				this->doAI();
			}
			_delegate->getHudLayer()->status_hpbar->setOpacity(255);
			_delegate->setHPLose(this->getHpPercent());
		}
		this->scheduleUpdate();
	}
	_delegate->reorderChild(this,-this->getPositionY());

}




/*---------------
init flog
---------------*/

Flog::Flog(void)
{
	_randomPosX=NULL;
	_randomPosY=NULL;
}


Flog::~Flog(void)
{
	CC_SAFE_RELEASE(callValue);	
	CC_SAFE_RELEASE(_nattackType);
	CC_SAFE_RELEASE(_damageArray);
}


bool Flog::init(){
	bool bRet = false;
	do {

		CC_BREAK_IF(!ActionManager::init());
		this->setAnchorPoint(ccp(0.5,0));		
		this->scheduleUpdate();
		bRet=true;
	}while(0);

	return bRet;

};

void Flog::setID(CCString* character,CCString* role,CCString* group){
	
	this->setCharacter(character);
	this->setRole(role);
	this->setGroup(group);

	CCArray* animationArray=CCArray::create();
	const char* filePath;


	filePath=CCString::createWithFormat("Element/Flog/%s.xml",this->getCharacter()->getCString(),this->getCharacter()->getCString())->getCString();


	KTools* tool= KTools::create();
	

	tool->readXMLToArray(filePath,animationArray);	

	//init Attribute; & indleFrame

	CCArray* tmpAction=(CCArray*)(animationArray->objectAtIndex(0));
	CCArray* tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	idleArray=(CCArray*)(tmpAction->objectAtIndex(1));

	CCString* tmpName;
	CCString* tmpHpMax;
	int tmpWidth;
	int tmpHeight;
	unsigned int tmpSpeed;
	int tmpCombatPoint;

	this->readDate(tmpDate,tmpName,tmpHpMax,tmpWidth,tmpHeight,tmpSpeed,tmpCombatPoint);
	this->setMaxHP(CCString::createWithFormat("%d",atoi(tmpHpMax->getCString())));
	this->setHP(CCString::create(this->getMaxHP()->getCString()));
	this->setHeight(tmpHeight);
	this->setWalkSpeed(tmpSpeed);
	
	this->setKillNum(CCString::createWithFormat("%d",0));
	


	if(!this->getCKR() && !this->getCKR2()){
		this->setCKR(CCString::create("0"));
		this->setCKR2(CCString::create("0"));
	}

	//init WalkFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(1));
	walkArray=(CCArray*)(tmpAction->objectAtIndex(1));


	//init HurtFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(2));
	hurtArray=(CCArray*)(tmpAction->objectAtIndex(1));

	//init AirHurtFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(3));
	airHurtArray=(CCArray*)(tmpAction->objectAtIndex(1));

	//init KnockDownFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(4));
	knockDownArray=(CCArray*)(tmpAction->objectAtIndex(1));

	//init FloatFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(5));
	floatArray=(CCArray*)(tmpAction->objectAtIndex(1));

	//init DeadFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(6));
	deadArray=(CCArray*)(tmpAction->objectAtIndex(1));


	//init nAttack date & Frame Array
	tmpAction=(CCArray*)(animationArray->objectAtIndex(7));
	tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	unsigned int tmpCD;
	CCString* tmpValue;
	this->readDate(tmpDate,_nattackType,tmpValue,_nattackRangeX,_nattackRangeY,tmpCD,tmpCombatPoint);
	this->setnAttackValue(tmpValue);
	_nattackType->retain();
	nattackArray=(CCArray *)(tmpAction->objectAtIndex(1));

	
	_damageArray=CCArray::create();
	_damageArray->retain();

	this->setCoin(CCString::create("50"));


	this->initAction();
	CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(ActionManager::acceptAttack), "acceptAttack", NULL);

};



void Flog::initAction(){

	this->setIdleAction(createAnimation(idleArray,5.0,true,false));
	this->setWalkAction(createAnimation(walkArray,10.0,true,false));
	this->setHurtAction(createAnimation(hurtArray,10.0,false,true));
	
	this->setAirHurtAction(createAnimation(airHurtArray,10.0f,false,false));
	this->setKnockDownAction(createAnimation(knockDownArray,10.0f,false,true));
	this->setDeadAction(createAnimation(deadArray,10.0f,false,false));

	this->setFloatAction(createAnimation(floatArray,10.0f,false,false));

	this->setNAttackAction(createAnimation(nattackArray,10.0,false,true));


};


void Flog::setHPbar(){
	if(strcmp(getGroup()->getCString(),_delegate->currentPlayer->getGroup()->getCString())!=0){
		_hpBar=HPBar::create("flog_bar_r.png");
	} else{
		_hpBar=HPBar::create("flog_bar.png");
	}
	_hpBar->setPositionY(this->getHeight());
	_hpBar->setDelegate(this);
	this->addChild(_hpBar);
};

void Flog::setAI(float dt){
	if(this->getActionState()==ACTION_STATE_IDLE || this->getActionState()==ACTION_STATE_WALK ||
		this->getActionState()==ACTION_STATE_ATTACK
		){

	
	if(!_randomPosY){	
		_randomPosY=rand()%8+4;
		_randomPosX=(rand()%32+20);
	}

	
	bool hasTarget=false;

	if(_mainTarget){
		if(_mainTarget->getActionState()!=ACTION_STATE_DEAD 			
			&& !_mainTarget->_isWudi && _mainTarget->_isVisable &&
			strcmp(_mainTarget->getGroup()->getCString(),this->getGroup()->getCString())!=0
			){

		hasTarget=true;
		}
	}


	if(!hasTarget){
			
			if(!this->findEnemy("Flog",NULL)){
				
				if(!this->findEnemy("Hero",64)){
					
					if(!this->findEnemy("Tower",NULL)){
						
						_mainTarget=NULL;
					};
				}
			}
	}

	
	CCPoint moveDirection;

	if(_mainTarget){
		CCPoint sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
			if(abs(sp.x)> _randomPosX || abs(sp.y)>_randomPosY){

				if(abs(sp.x)>64 && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 && strcmp(_mainTarget->getRole()->getCString(),"Tower")!=0 ){
					_mainTarget=NULL;
					return;
				}

				moveDirection =ccpNormalize(sp);
				this->walk(moveDirection);
			}else{
				if( this->getActionState()!=ACTION_STATE_ATTACK){
					this->changeSide(sp);
				    this->attack(NAttack);
				}
			}
			return;
	}

	// no target then step on


	if(abs(this->getPositionY()-this->_mainPosY)>8){
		if(strcmp(this->getGroup()->getCString(),"Konoha")==0){
			moveDirection =ccpNormalize(ccp(1,this->getPositionY()>this->_mainPosY?-1:1));
		}else{
			moveDirection =ccpNormalize(ccp(-1,this->getPositionY()>this->_mainPosY?-1:1));
		}
	}else{
		if(strcmp(this->getGroup()->getCString(),"Konoha")==0){
			 moveDirection =ccpNormalize(ccp(1,0));
		}else{
			moveDirection =ccpNormalize(ccp(-1,0));
		}
	}
	this->walk(moveDirection);

	}
}


void Flog::dealloc(){
	this->unschedule(schedule_selector(ActionManager::setAI));
	this->setActionState(ACTION_STATE_DEAD);
	this->stopAllActions();

	if(strcmp(this->getGroup()->getCString(),"Konoha")==0){
		int index=_delegate->_KonohaFlogArray->indexOfObject(this);
		_delegate->_KonohaFlogArray->removeObjectAtIndex(index);
	}else{
		int index=_delegate->_AkatsukiFlogArray->indexOfObject(this);
		_delegate->_AkatsukiFlogArray->removeObjectAtIndex(index);
	};
	this->removeFromParent();
	
}


/*---------------
init Tower
---------------*/


Tower::Tower(void)
{

}


Tower::~Tower(void)
{

	
	
}


bool Tower::init(){
	bool bRet = false;
	do {

		CC_BREAK_IF(!ActionManager::init());
		this->setAnchorPoint(ccp(0.5,0.5));		
		this->scheduleUpdate();
		bRet=true;
	}while(0);

	return bRet;

};

void Tower::setID(CCString* character,CCString* role,CCString* group){

	this->setCharacter(character);
	this->setRole(role);
	this->setGroup(group);

	CCArray* animationArray=CCArray::create();
	const char* filePath;


	if(strcmp(this->getCharacter()->getCString(),"KonohaCenter")==0 || strcmp(this->getCharacter()->getCString(),"AkatsukiCenter")==0 ){
		filePath="Element/Tower/CenterDate.xml";

	}else{
		filePath="Element/Tower/TowerDate.xml";
	}
	
	KTools* tool= KTools::create();
	std::string key =tool->getKeycode(filePath);
	int id=tool->checkMD5(filePath);
	
	if(strcmp(key.c_str(),_delegate->KeyList[id])!=0){
		//return;
	}
	

	tool->readXMLToArray(filePath,animationArray);	


	//init Attribute; & indleFrame

	CCArray* tmpAction=(CCArray*)(animationArray->objectAtIndex(0));
	CCArray* tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	idleArray=(CCArray*)(tmpAction->objectAtIndex(1));

	CCString* tmpName;
	CCString* tmpHpMax;
	int tmpWidth;
	int tmpHeight;
	unsigned int tmpSpeed;
	int tmpCombatPoint;

	this->readDate(tmpDate,tmpName,tmpHpMax,tmpWidth,tmpHeight,tmpSpeed, tmpCombatPoint);
	this->setMaxHP(CCString::createWithFormat("%d",atoi(tmpHpMax->getCString())));
	this->setHP(CCString::create(this->getMaxHP()->getCString()));

	this->setHeight(tmpHeight);
	this->setWalkSpeed(tmpSpeed);


	if(!this->getCKR() && !this->getCKR2()){
		this->setCKR(CCString::create("0"));
		this->setCKR2(CCString::create("0"));
	}

	//init DeadFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(6));
	deadArray=(CCArray*)(tmpAction->objectAtIndex(1));

	this->setCoin(CCString::create("50"));

	this->initAction();

	CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(ActionManager::acceptAttack), "acceptAttack", NULL);

}

void Tower::initAction(){
	this->setDeadAction(createAnimation(deadArray,10.0f,false,false));
	this->setIdleAction(createAnimation(idleArray,5.0,true,false));

};


void Tower::setHPbar(){
	
	if(strcmp(getGroup()->getCString(),_delegate->currentPlayer->getGroup()->getCString())!=0){
		_hpBar=HPBar::create("hp_bar_r.png");
	}else{
		_hpBar=HPBar::create("hp_bar.png");
	}	
	_hpBar->getHPBAR()->setPosition(ccp(1,1));
	_hpBar->setPositionY(this->getHeight());
	_hpBar->setDelegate(this);
	this->addChild(_hpBar);
};


void Tower::dealloc(){
	this->unschedule(schedule_selector(ActionManager::setAI));
	this->setActionState(ACTION_STATE_DEAD);
	this->stopAllActions();

	CCObject* pObject;
	CCArray* list;
	for(int i=0;i<2;i++){
		if(i==0){
			list=_delegate->_KonohaFlogArray;
		}else if(i==1){
			list=_delegate->_AkatsukiFlogArray;
		}

		CCARRAY_FOREACH(list,pObject){
			ActionManager* tempFlog=(ActionManager*) pObject;
			if(tempFlog->_mainTarget){
				if(tempFlog->_mainTarget==(ActionManager*)this){
					tempFlog->_mainTarget=NULL;
				}
			}
		}

	}

	


	int index=_delegate->_TowerArray->indexOfObject(this);
	_delegate->_TowerArray->removeObjectAtIndex(index);
	_delegate->getHudLayer()->setTowerState(this->getCharNO());
	_delegate->checkTower();
	this->removeFromParentAndCleanup(true);
};

/*---------------
init Monster
---------------*/


Monster::Monster(void)
{

}


Monster::~Monster(void)
{
	CC_SAFE_RELEASE(callValue);	
	CC_SAFE_RELEASE(_nattackType);
	CC_SAFE_RELEASE(_damageArray);

}

bool Monster::init(){
	bool bRet = false;
	do {

		CC_BREAK_IF(!ActionManager::init());
		this->setAnchorPoint(ccp(0.5,0));		
		this->scheduleUpdate();
		bRet=true;
	}while(0);

	return bRet;

};

void Monster::setID(CCString* character,CCString* role,CCString* group){

	this->setCharacter(character);
	this->setRole(role);
	this->setGroup(group);

	CCArray* animationArray=CCArray::create();
	const char* filePath;


	filePath=CCString::createWithFormat("Element/Monster/%s.xml",this->getCharacter()->getCString(),this->getCharacter()->getCString())->getCString();


	KTools* tool= KTools::create();
	std::string key =tool->getKeycode(filePath);
	
	tool->readXMLToArray(filePath,animationArray);	

	//init Attribute; & indleFrame

	CCArray* tmpAction=(CCArray*)(animationArray->objectAtIndex(0));
	CCArray* tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	idleArray=(CCArray*)(tmpAction->objectAtIndex(1));

	CCString* tmpName;
	CCString* tmpHpMax;
	int tmpWidth;
	int tmpHeight;
	unsigned int tmpSpeed;
	int  tmpCombatPoint;

	this->readDate(tmpDate,tmpName,tmpHpMax,tmpWidth,tmpHeight,tmpSpeed, tmpCombatPoint);
	this->setMaxHP(CCString::createWithFormat("%d",atoi(tmpHpMax->getCString())));
	this->setHP(CCString::create(this->getMaxHP()->getCString()));

	this->setHeight(tmpHeight);
	this->setWalkSpeed(tmpSpeed);



	if(!this->getCKR() && !this->getCKR2()){
		this->setCKR(CCString::create("0"));
		this->setCKR2(CCString::create("0"));
	}

	//init WalkFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(1));
	walkArray=(CCArray*)(tmpAction->objectAtIndex(1));


	//init DeadFrame
	tmpAction=(CCArray*)(animationArray->objectAtIndex(6));
	deadArray=(CCArray*)(tmpAction->objectAtIndex(1));


	//init nAttack date & Frame Array
	tmpAction=(CCArray*)(animationArray->objectAtIndex(7));
	tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	unsigned int tmpCD;
	CCString* tmpValue;
	this->readDate(tmpDate,_nattackType,tmpValue,_nattackRangeX,_nattackRangeY,tmpCD,tmpCombatPoint);
	this->setnAttackValue(tmpValue);
	_nattackType->retain();
	nattackArray=(CCArray *)(tmpAction->objectAtIndex(1));

	this->setCoin(CCString::create("50"));

	this->initAction();

};



void Monster::initAction(){

	this->setIdleAction(createAnimation(idleArray,5.0,true,false));
	this->setWalkAction(createAnimation(walkArray,10.0,true,false));
	this->setDeadAction(createAnimation(deadArray,10.0f,false,false));
	if(strcmp(this->getCharacter()->getCString(),"Kage")==0||
		strcmp(this->getCharacter()->getCString(),"KageHand")==0 ||
		strcmp(this->getCharacter()->getCString(),"FudonSRK")==0 ||
		strcmp(this->getCharacter()->getCString(),"FudonSRK2")==0 || 
		strcmp(this->getCharacter()->getCString(),"Kubi")==0 
		){
	this->setNAttackAction(createAnimation(nattackArray,10.0,false,false));
	}else{
	this->setNAttackAction(createAnimation(nattackArray,10.0,false,true));
	}


};

void Monster::setHPbar(){

	if(strcmp(getGroup()->getCString(),_delegate->currentPlayer->getGroup()->getCString())!=0){
		_hpBar=HPBar::create("hp_bar_r.png");
	} else {
		_hpBar=HPBar::create("hp_bar_b.png");
	}

	_hpBar->setPositionY(this->getHeight());
	_hpBar->setDelegate(this);
	this->addChild(_hpBar);
	this->changeHPbar();
};

void Monster::changeHPbar(){


	if(_exp>=500 && _level==1){
		_level=2;
		int tempMaxHP=atoi(this->getMaxHP()->getCString());
		tempMaxHP+=1000;
		this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+9));
	}else if(_exp>=1000 && _level==2){
		_level=3;
		int tempMaxHP=atoi(this->getMaxHP()->getCString());
		tempMaxHP+=1500;
		this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+18));

	}else if(_exp>=1500 && _level==3){
		_level=4;
		int tempMaxHP=atoi(this->getMaxHP()->getCString());
		tempMaxHP+=2000;
		this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+27));

	}else if(_exp>=2000 && _level==4){
		_level=5;
		int tempMaxHP=atoi(this->getMaxHP()->getCString());
		tempMaxHP+=2500;
		this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+36));

	}else if(_exp>=2500 && _level==5){
		_level=6;
		int tempMaxHP=atoi(this->getMaxHP()->getCString());
		tempMaxHP+=3000;
		this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+48));
	}

	if(_hpBar){	
		CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("hp_bottom%d.png",int(_level))->getCString());  
		_hpBar->getHPBottom()->setDisplayFrame(frame);
	}


}


void Monster::setAI(float dt){

	if(strcmp(getCharacter()->getCString(),"Kage")==0){

		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			Hero* tempHero=(Hero*) pObject;
			if(strcmp(this->getGroup()->getCString(),tempHero->getGroup()->getCString())!=0 &&
				tempHero->getActionState()!=ACTION_STATE_DEAD &&
				tempHero->getActionState()!=ACTION_STATE_O2ATTACK &&
				!tempHero->_isWudi &&
				!tempHero->_isBati &&
				tempHero->_isVisable 
				){

				CCPoint sp=ccpSub(tempHero->getPosition(),this->getPosition());
				float distanceY=tempHero->_originY?abs(this->getPositionY()-tempHero->_originY):abs(sp.y);
				float distanceX=_isFlipped?tempHero->getPositionX() - this->getPositionX() + this->getContentSize().width:tempHero->getPositionX() - this->getPositionX()-this->getContentSize().width;
				if( abs(distanceX)< 32 &&  distanceY< 48){
					if(!this->_monsterArray){
						CCDictionary* dic=CCDictionary::create();
						CCString* monterName=CCString::create("KageHand");
						dic->setObject(monterName,1);
						this->setMon(this,(void*) dic);
						this->unschedule(schedule_selector(ActionManager::setAI));
					}
				}

			}
		
		};
		return;
	}

	if(strcmp(getCharacter()->getCString(),"Mouse")==0
		){

		if(!this->findEnemy("Hero",NULL)){
			_mainTarget=NULL;
		}
	}else if(strcmp(getCharacter()->getCString(),"Spider")==0 ||
		strcmp(getCharacter()->getCString(),"ClayBird")==0
		){

		
			if(!this->findEnemy("Hero",NULL)){
				if(!this->findEnemy("Tower",NULL)){	
					_mainTarget=NULL;
				}				
			}

	}else if(strcmp(getCharacter()->getCString(),"FudonSRK2")==0||
		strcmp(getCharacter()->getCString(),"FudonSRK")==0){
		
	}else{

		if(!this->findEnemy("Hero",NULL)){
			if(!this->findEnemy("Flog",NULL)){
				_mainTarget=NULL;
			}
		}
	} 
	

	CCPoint moveDirection;

	if(_mainTarget){
		
		CCPoint sp;

		sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY?_mainTarget->_originY:_mainTarget->getPositionY()),
			ccp(this->getPositionX(),_originY?_originY:this->getPositionY()));


		if( strcmp(this->getCharacter()->getCString(),"FudonSRK2")==0 ||
			strcmp(this->getCharacter()->getCString(),"FudonSRK")==0 ){
				if(abs(sp.x)> 48 || abs(sp.y)> 32){
					this->setActionState(ACTION_STATE_WALK);
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(strcmp(_mainTarget->getRole()->getCString(),"Player")==0 || 
					strcmp(_mainTarget->getRole()->getCString(),"Com")==0 ){
						this->stopAllActions();
						this->dealloc();
				}
				
		}else if (strcmp(this->getCharacter()->getCString(),"Traps")==0 ){
			if(abs(sp.x)>32 || abs(sp.y)> 32 ){

			}else{
				this->attack(NAttack);
			}

		}else if(abs(sp.x)> 32 || abs(sp.y)> 16){

			if(strcmp(this->getCharacter()->getCString(),"Dogs")!=0 &&
				strcmp(this->getCharacter()->getCString(),"Mine")!=0 &&	
				strcmp(this->getCharacter()->getCString(),"Traps")!=0 &&
				strcmp(this->getCharacter()->getCString(),"Yominuma")!=0 &&
				strcmp(this->getCharacter()->getCString(),"Tsukuyomi")!=0  
				){
					moveDirection =ccpNormalize(sp);
					
					this->walk(moveDirection);
			}
		
		}else{

			if(strcmp(this->getCharacter()->getCString(),"Mine") ==0){

				if(strcmp(_mainTarget->getRole()->getCString(),"Player")==0 || 
					strcmp(_mainTarget->getRole()->getCString(),"Com")==0 ){
					this->attack(NAttack);
					this->unschedule(schedule_selector(ActionManager::setAI));
				}

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

				if(strcmp(getCharacter()->getCString(),"SmallSlug")!=0){
						this->unschedule(schedule_selector(ActionManager::setAI));
				}

			}
				
			
		}
		
		
		
	}else{
		if(strcmp(getCharacter()->getCString(),"Rocket")==0 ||
			strcmp(getCharacter()->getCString(),"Spider")==0 ||
			strcmp(getCharacter()->getCString(),"ClayBird")==0
			){
			this->stepOn();
		}else{
			this->idle();
		}
	}

}


void Monster::dealloc(){

	this->unschedule(schedule_selector(ActionManager::setAI));
	this->setActionState(ACTION_STATE_DEAD);
	this->stopAllActions();

	if(strcmp(this->getCharacter()->getCString(),"FudonSRK")==0||
		strcmp(this->getCharacter()->getCString(),"FudonSRK2")==0
		){

			CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(Monster::dealloc2));
			CCArray* seqArray=CCArray::create();
			seqArray->addObject(this->getDeadAction());
			seqArray->addObject(call);
			CCAction* seq=CCSequence::create(seqArray);
			this->runAction(seq);
			return;

	}

	//飞雷神标记
	if(strcmp(this->getCharacter()->getCString(),"HiraishinMark")==0){

		_master->_isCanSkill1=false;
		_master->setActionResume();
		_master->scheduleOnce(schedule_selector(ActionManager::enableSkill1),_sattackcoldDown1);

		if(strcmp(_master->getRole()->getCString(),"Player")==0){
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Minato_skill1.png"); 
			_delegate->getHudLayer()->skill1Button->setDisplayFrame(frame);
			_delegate->getHudLayer()->skill1Button->_clickNum++;
			_delegate->clearDoubleClick();
		}

		CCObject* pObject;
		CCARRAY_FOREACH(_master->getMonsterArray(),pObject){
			Monster* mo=(Monster*) pObject;

			if(strcmp(mo->getCharacter()->getCString(),"HiraishinMark")==0){
				int index=_master->getMonsterArray()->indexOfObject(mo);
				_master->getMonsterArray()->removeObjectAtIndex(index);
				mo->removeFromParentAndCleanup(true);
			}
			
		};

		return;

	}
	
	if(strcmp(this->getCharacter()->getCString(),"SmallSlug")==0){
		if(_secmaster && _secmaster->getMonsterArray()){
			int index=_secmaster->getMonsterArray()->indexOfObject(this);
			if(index>=0){
				_secmaster->getMonsterArray()->removeObjectAtIndex(index);
			}

		}

	}else {

		if(_master &&  _master->getMonsterArray()){
			int index=_master->getMonsterArray()->indexOfObject(this);
			if(index>=0){
				_master->getMonsterArray()->removeObjectAtIndex(index);
			}

		}

	}
	
	if(strcmp(this->getCharacter()->getCString(),"KageHand")==0 ||
		strcmp(this->getCharacter()->getCString(),"Kage")==0
		){

		CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(Monster::dealloc2));

		
		CCArray* seqArray=CCArray::create();
		seqArray->addObject(this->getDeadAction());
		seqArray->addObject(call);
		
		CCFiniteTimeAction *call2=CCCallFunc::create(this,callfunc_selector(Monster::setResume));
		seqArray->addObject(call2);
	
		CCAction* seq=CCSequence::create(seqArray);
		this->runAction(seq);
		

	}else{
		
		this->removeFromParentAndCleanup(true);

	}



}


void Monster::setDirectMove(unsigned int length,float delay,bool isReverse){

	CCPoint direction=ccp(this->_isFlipped?this->getPosition().x-length:this->getPosition().x+length,
		this->getPositionY());
	CCPoint direction2=this->getPosition();
	CCActionInterval* mv=CCMoveTo::create(delay,direction);
	CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Monster::dealloc));
	CCAction* seq;
	if (!isReverse) {
		seq=CCSequence::create(mv,call,NULL);
	}else{
		CCActionInterval* mv2=CCMoveTo::create(delay,direction2);
		seq=CCSequence::create(mv,mv2,call,NULL);
	}

	this->runAction(seq);


}
void Monster::setEaseIn(unsigned int length,float delay){

	CCPoint direction=ccp(this->_isFlipped?this->getPosition().x-length:this->getPosition().x+length,
		this->getPositionY());
	CCActionInterval* mv=CCMoveTo::create(1.0f,direction);
	CCActionInterval* eo=CCEaseIn::create(mv,delay);
	
	CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Monster::dealloc));
	CCAction* seq=CCSequence::create(eo,call,NULL);
	this->runAction(seq) ;
}

void Monster::setDirectMoveBy(unsigned int length,float delay){

	CCPoint direction=ccp(this->_isFlipped?this->getPosition().x-length:this->getPosition().x+length,
		this->getPositionY());

	if(_mainTarget ){
		
		CCActionInterval* mv=CCMoveBy::create(0.1f,ccp(_mainTarget->getPositionX()>this->getPositionX()?16:-16,_mainTarget->getPositionY()>this->getPositionY()?16:-16));

		this->runAction(CCRepeatForever::create(mv));
	_mainTarget =NULL;
	_master->_mainTarget=NULL;
	}else{
		CCActionInterval* mv=CCMoveBy::create(0.1f,ccp(this->_isFlipped?-16:16,0));

		this->runAction(CCRepeatForever::create(mv));
	}

	CCDelayTime* dl=CCDelayTime::create(delay);
	CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Monster::dealloc));
	CCAction* seq=CCSequence::create(dl,call,NULL);
	this->runAction(seq) ;
	
}



void Monster::setResume(){

	if(this->getSecMaster()){
		this->getSecMaster()->dealloc();
	}else{

		if(this->getMaster() && strcmp(this->getMaster()->getCharacter()->getCString(),"Shikamaru")==0){
			this->getMaster()->idle();
		}
		
	}
}
void Monster::dealloc2(){
	this->removeFromParentAndCleanup(true);
}

/*---------------
init Bullet
---------------*/


Bullet::Bullet(void)
{

}


Bullet::~Bullet(void)
{


}

bool Bullet::init(){
	bool bRet = false;
	do {

		//CC_BREAK_IF(!ActionManager::initWithSpriteFrameName("coin.png"));
		CC_BREAK_IF(!ActionManager::init());
		this->scheduleUpdate();
		bRet=true;
	}while(0);

	return bRet;

};

void Bullet::setID(CCString* character,CCString* role,CCString* group){

	

	this->setCharacter(character);
	this->setRole(role);
	this->setGroup(group);

	CCArray* animationArray=CCArray::create();
	const char* filePath;


	filePath=CCString::createWithFormat("Element/Bullet/%s.xml",this->getCharacter()->getCString(),this->getCharacter()->getCString())->getCString();


	KTools* tool= KTools::create();
	std::string key =tool->getKeycode(filePath);
	int id=tool->checkMD5(filePath);
	
	if(strcmp(key.c_str(),_delegate->KeyList[id])!=0){
		//return;
	}
	

	tool->readXMLToArray(filePath,animationArray);	

	//init Attribute; & idleFrame

	CCArray* tmpAction=(CCArray*)(animationArray->objectAtIndex(0));
	CCArray* tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	idleArray=(CCArray*)(tmpAction->objectAtIndex(1));

	//init nAttack date & Frame Array
	tmpAction=(CCArray*)(animationArray->objectAtIndex(7));
	tmpDate=(CCArray *)(tmpAction->objectAtIndex(0));
	unsigned int tmpCD;
	int tmpCombatPoint;
	CCString* tmpValue;

	this->readDate(tmpDate,_nattackType,tmpValue,_nattackRangeX,_nattackRangeY,tmpCD,tmpCombatPoint);
	this->setnAttackValue(tmpValue);
	_nattackType->retain();
	nattackArray=(CCArray *)(tmpAction->objectAtIndex(1));

	if(strcmp(this->getCharacter()->getCString(),"Amaterasu")==0 ){
		//init DeadFrame
		tmpAction=(CCArray*)(animationArray->objectAtIndex(6));
		deadArray=(CCArray*)(tmpAction->objectAtIndex(1));
	}

	this->setCoin(CCString::create("50"));

	this->initAction();

};



void Bullet::initAction(){

	this->setIdleAction(createAnimation(idleArray,5.0,true,false));
	this->setNAttackAction(createAnimation(nattackArray,10.0,true,false));
	if(strcmp(this->getCharacter()->getCString(),"Amaterasu")==0 ||
		strcmp(this->getCharacter()->getCString(),"SusanoTama")==0 
		){
		this->setDeadAction(createAnimation(deadArray,10.0f,false,false));
	}

};


void Bullet::dealloc(){

	this->stopAllActions();
	

	if(strcmp(this->getCharacter()->getCString(),"Amaterasu")==0 
		){
		
		CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(Bullet::dealloc2));
		CCArray* seqArray=CCArray::create();
		seqArray->addObject(this->getDeadAction());
		seqArray->addObject(call);
		CCAction* seq=CCSequence::create(seqArray);
		this->runAction(seq);


	}else{

		if(strcmp(this->getCharacter()->getCString(),"HiraishinKunai")==0){

			if(_master->getActionState()==ACTION_STATE_SATTACK){
					_master->setActionState(ACTION_STATE_ATTACK);
					_master->_markPoint=ccp(this->getPositionX(),this->_originY);
					_master->changeAction2();	
					_master->_isCanSkill2=true;
					_master->sAttack(SKILL2);
					
			}
		}	

		if(_master &&  _master->getMonsterArray()){
			int index=_master->getMonsterArray()->indexOfObject(this);
			if(index>=0){
				_master->getMonsterArray()->removeObjectAtIndex(index);
			}
		}
		this->removeFromParentAndCleanup(true);
	}
	
}

void Bullet::dealloc2(){

	this->removeFromParentAndCleanup(true);

}

void Bullet::setMove(unsigned int length,float delay,bool isReverse){
	CCPoint direction=ccp(this->_isFlipped?this->getPosition().x-length:this->getPosition().x+length,
		this->getPositionY());
	CCPoint direction2=this->getPosition();
	CCActionInterval* mv=CCMoveTo::create(delay,direction);
	CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Bullet::dealloc));
	CCAction* seq;
	if (!isReverse) {
	
		seq=CCSequence::create(mv,call,NULL);
	}else{
		CCActionInterval* mv2=CCMoveTo::create(delay,direction2);
		seq=CCSequence::create(mv,mv2,call,NULL);
	}
	
	this->runAction(seq);
}

void Bullet::setEaseIn(unsigned int length,float delay){

	CCPoint direction=ccp(this->_isFlipped?this->getPosition().x-length:this->getPosition().x+length,
		this->getPositionY());
	CCActionInterval* mv=CCMoveTo::create(1.0f,direction);
	CCActionInterval* eo=CCEaseIn::create(mv,delay);

    CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Bullet::dealloc));
	CCAction* seq=CCSequence::create(eo,call,NULL);
	this->runAction(seq) ;
}

void Bullet::setAttack(float dt){
	this->attack(NAttack);
}