#include "Characters.h"
#include "HudLayer.h"
USING_NS_CC;




HPBar::HPBar(void)
{

	hpBar=NULL;
	hpBottom=NULL;
};


HPBar::~HPBar(void)
{

};


bool HPBar::init(const char *szImage){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCSprite::init());

		char fileName[3]="xx";
		strncpy(fileName,szImage,2);


		hpBar=CCSprite::createWithSpriteFrameName(szImage);
		hpBar->setAnchorPoint(ccp(0,0));		
		this->addChild(hpBar,1);

		if(strcmp(fileName,"hp")==0){
			hpBottom=CCSprite::createWithSpriteFrameName("hp_bottom.png");
			hpBar->setPosition(ccp(15,1));
		}else{ 
			hpBottom=CCSprite::createWithSpriteFrameName("flog_bar_buttom.png");
			hpBar->setPosition(ccp(1,1));
		}
		hpBottom->setAnchorPoint(ccp(0,0));
		this->addChild(hpBottom,-1);

		bRet=true;

	}while(0);

	return bRet;

}

void HPBar::changeBar(const char *szImage){
	CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(szImage); 
	hpBar->setDisplayFrame(frame);
}

void HPBar::loseHP(float percent){

	
	if(_delegate->getDelegate()->_isHardCoreGame){

		const char* gardTower;
		if(_delegate->getDelegate()->zhenying>0){
			gardTower="AkatsukiCenter";
		}else{
			gardTower="KonohaCenter";
		}
		
		if(strcmp(this->_delegate->getCharacter()->getCString(),gardTower)==0){
			if( !_delegate->getDelegate()->_isGuardian && percent<=0.8){
				_delegate->getDelegate()->initGard();
			}


		}

		if(_delegate->getDelegate()->_isGuardian){
			ActionManager* _slayer=(ActionManager*) _delegate->_slayer;
			if(_slayer){
				if(strcmp(this->_delegate->getCharacter()->getCString(),gardTower)==0){
					_slayer->isHurtingTower=true;
				}else{
					_slayer->isHurtingTower=false;
				}
			}

		}
		
	}



	if(percent<=0){

		ActionManager* _slayer=(ActionManager*) _delegate->_slayer;
		ActionManager* currentSlayer;


		//杀死青蛙
		if(strcmp(_delegate->getRole()->getCString(),"Flog")==0){

			if(_slayer->getSecMaster()  && strcmp(_slayer->getCharacter()->getCString(),"KageHand")!=0
				 && strcmp(_slayer->getCharacter()->getCString(),"KageHands")!=0
				){
				if(_slayer->getSecMaster()->getControler()){
					currentSlayer=_slayer->getSecMaster()->getControler();
				}else{
					currentSlayer=_slayer->getSecMaster();
				}
				
			}else if (_slayer->getMaster()){
				if(_slayer->getMaster()->getControler()){
					currentSlayer=_slayer->getMaster()->getControler();
				}else{
					currentSlayer=_slayer->getMaster();
				}
			}else{
				if(_slayer->getControler()){
					currentSlayer=_slayer->getControler();
				}else{
					currentSlayer=_slayer;
				}
			}

			//全额经验


			if(currentSlayer->getLV()!=6){

				if(strcmp(currentSlayer->getCharacter()->getCString(),"Naruto")==0||
					strcmp(currentSlayer->getCharacter()->getCString(),"SageNaruto")==0
					){
						currentSlayer->setEXP(currentSlayer->getEXP()+12);
						currentSlayer->changeHPbar();

				}else{
					currentSlayer->setEXP(currentSlayer->getEXP()+10);
					currentSlayer->changeHPbar();
				}
				
			}

			

			
			if(strcmp(currentSlayer->getRole()->getCString(),"Player")==0 
				){
					if(_delegate->getMaxHP()->intValue()==10000){
						_delegate->setCoinDisplay(30);
						_delegate->getDelegate()->setCoin("30");
						_delegate->getDelegate()->getHudLayer()->setEXPLose(NULL);
					}else if(_delegate->getMaxHP()->intValue()==5000){
						_delegate->setCoinDisplay(20);
						_delegate->getDelegate()->setCoin("20");
						_delegate->getDelegate()->getHudLayer()->setEXPLose(NULL);
					}else{
						_delegate->setCoinDisplay(10);
						_delegate->getDelegate()->setCoin("10");
						_delegate->getDelegate()->getHudLayer()->setEXPLose(NULL);
	
					}
					
			}



		currentSlayer->_flogNum+=1;
		if(_delegate->getMaxHP()->intValue()==10000){
			currentSlayer->addCoin(30);
		}else if(_delegate->getMaxHP()->intValue()==5000){
			currentSlayer->addCoin(20);
		}else{
			currentSlayer->addCoin(10);
		}

		}//拆塔
		else if(strcmp(_delegate->getRole()->getCString(),"Tower")==0){


			if(_slayer->getSecMaster()  
				&& strcmp(_slayer->getCharacter()->getCString(),"KageHand")!=0
				 && strcmp(_slayer->getCharacter()->getCString(),"KageHands")!=0
				&& strcmp(_slayer->getCharacter()->getCString(),"SmallSlug")!=0){
					if(_slayer->getSecMaster()->getControler()){
						currentSlayer=_slayer->getSecMaster()->getControler();
					}else{
						currentSlayer=_slayer->getSecMaster();
					}
			}else if (_slayer->getMaster()){
				if(_slayer->getMaster()->getControler()){
					currentSlayer=_slayer->getMaster()->getControler();
				}else{
					currentSlayer=_slayer->getMaster();
				}
			}else{
				if(_slayer->getControler()){
					currentSlayer=_slayer->getControler();
				}else{
					currentSlayer=_slayer;
				}
			}

			if((strcmp(currentSlayer->getRole()->getCString(),"Flog")!=0)){
				_delegate->getDelegate()->setReport(currentSlayer->getCharacter()->getCString(),"Tower",currentSlayer->getKillNum()) ;
			

				if(currentSlayer->getLV()!=6){
					if(strcmp(currentSlayer->getCharacter()->getCString(),"Naruto")==0||
						strcmp(currentSlayer->getCharacter()->getCString(),"SageNaruto")==0
						){
							currentSlayer->setEXP(currentSlayer->getEXP()+625);
							currentSlayer->changeHPbar();

					}else{
						currentSlayer->setEXP(currentSlayer->getEXP()+500);
						currentSlayer->changeHPbar();
					}

					
				}

			
				
				if(strcmp(currentSlayer->getRole()->getCString(),"Player")==0){
					 if(_delegate->getDelegate()->_isHardCoreGame){
						 if(atoi(this->_delegate->getMaxHP()->getCString()) >40000){
							 _delegate->getDelegate()->setCoin("1000");
							 _delegate->setCoinDisplay(1000);
						 }else{
							 _delegate->getDelegate()->setCoin("500");
							 _delegate->setCoinDisplay(500);
						 }
					
					 }else{
						 _delegate->getDelegate()->setCoin("300");
						 _delegate->setCoinDisplay(300);
					 }
				
					_delegate->getDelegate()->getHudLayer()->setEXPLose(NULL);
				}

				if(_delegate->getDelegate()->_isHardCoreGame){
					if(atoi(this->_delegate->getMaxHP()->getCString()) >40000){
						currentSlayer->addCoin(1000);
					}else{
						currentSlayer->addCoin(500);
					}
				}else{
					currentSlayer->addCoin(300);
				}

			}


			//同队分享
			CCObject* pObject;
			CCARRAY_FOREACH(_delegate->getDelegate()->_CharacterArray,pObject){
				Hero* otherSlayer=(Hero*) pObject;
				if(strcmp(currentSlayer->getGroup()->getCString(),otherSlayer->getGroup()->getCString())==0 &&
					strcmp(currentSlayer->getCharacter()->getCString(),otherSlayer->getCharacter()->getCString())!=0
					){

						
						if(otherSlayer->getLV()!=6){
							otherSlayer->setEXP(otherSlayer->getEXP()+250);
							otherSlayer->changeHPbar();
						}

						


						if (strcmp(otherSlayer->getRole()->getCString(),"Player")==0){

							if(_delegate->getDelegate()->_isHardCoreGame){
								if(atoi(this->_delegate->getMaxHP()->getCString()) >40000){
									_delegate->getDelegate()->setCoin("850");
									_delegate->setCoinDisplay(850);
								}else{
									_delegate->getDelegate()->setCoin("350");
									_delegate->setCoinDisplay(350);
									
								}
							}else{
								_delegate->getDelegate()->setCoin("150");
								_delegate->setCoinDisplay(150);
							}

							_delegate->getDelegate()->getHudLayer()->setEXPLose(NULL);
						}
							


						if(_delegate->getDelegate()->_isHardCoreGame){
							if(atoi(this->_delegate->getMaxHP()->getCString()) >40000){
								  otherSlayer->addCoin(850);
							}else{
								  otherSlayer->addCoin(350);
							}
						}else{
							  otherSlayer->addCoin(150);
						}

					  
						

				}
			}



		}
	
		else if((strcmp(_delegate->getRole()->getCString(),"Player")==0 || strcmp(_delegate->getRole()->getCString(),"Com")==0)){
				


			if(strcmp(_delegate->getCharacter()->getCString(),"Kakuzu")==0 && _delegate->getDelegate()->_isOugis2Game){
				
				bool reieveAble=false;
				if(atof(_delegate->getCKR2()->getCString())>=25000 && _delegate->hearts>0){
					if(strcmp(_delegate->getRole()->getCString(),"Player")==0){
						if(_delegate->getDelegate()->getHudLayer()->skill5Button){
							reieveAble=true;
						}
					}else if(strcmp(_delegate->getRole()->getCString(),"Com")==0){
						reieveAble=true;
					}

				}


				if(reieveAble && _delegate->getActionState()!=ACTION_STATE_O2ATTACK  && !_delegate->_isWudi && _delegate->getActionState()!=ACTION_STATE_DEAD){

					if(_delegate->_isSticking){
						_delegate->_isSticking=false;
					}
					if(_delegate->getActionState()==ACTION_STATE_FLOAT ||
						_delegate->getActionState()==ACTION_STATE_AIRHURT){
							this->setPositionY(_delegate->_originY);
							_delegate->_originY=NULL;
							_delegate->getDelegate()->reorderChild(_delegate,-_delegate->getPositionY());
					}

					
					if(strcmp(_delegate->getRole()->getCString(),"Player")==0){

						_delegate->getDelegate()->getHudLayer()->skill5Button->unLock();
						_delegate->setActionState(ACTION_STATE_IDLE);
						_delegate->getDelegate()->setSkillFinish(true);
						_delegate->getDelegate()->getHudLayer()->skill5Button->click();	
						_delegate->getDelegate()->getHudLayer()->skill5Button->setLock();

					}else{

						if(_delegate->_isCanOugis2){

							
							_delegate->setActionState(ACTION_STATE_IDLE);
							_delegate->attack(OUGIS2);
						}

					}
					_delegate->hearts-=1;

					if(_delegate->_heartEffect){
						CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("Heart_Effect_%02d.png",_delegate->hearts)->getCString()); 
						_delegate->_heartEffect->setDisplayFrame(frame);
					}

					if(_delegate->hearts<1){
						if(strcmp(_delegate->getRole()->getCString(),"Player")==0){
							if(_delegate->getDelegate()->getHudLayer()->skill4Button){
								_delegate->getDelegate()->getHudLayer()->skill4Button->setLock();
							}
						}
					}

					return;
				}

				if( _delegate->getActionState()==ACTION_STATE_O2ATTACK){
					return;
				}


				
			}


				if(_delegate->_isControled){
					_delegate->_isSuicide=true;
					currentSlayer=_delegate->getControler();
				}else if(_slayer->getSecMaster() 
					&& strcmp(_slayer->getCharacter()->getCString(),"KageHand")!=0
					 && strcmp(_slayer->getCharacter()->getCString(),"KageHands")!=0
					&& strcmp(_slayer->getCharacter()->getCString(),"SmallSlug")!=0
					&& strcmp(_slayer->getCharacter()->getCString(),"FakeItachi")!=0
					){
					if(_slayer->getSecMaster()->getControler()){
						currentSlayer=_slayer->getSecMaster()->getControler();
					}else{
						currentSlayer=_slayer->getSecMaster();
					}
				}else if (_slayer->getMaster()){
					if(_slayer->getMaster()->getControler()){
						currentSlayer=_slayer->getMaster()->getControler();
					}else{
						currentSlayer=_slayer->getMaster();
					}
				}else{
					if(_slayer->getControler()){
						currentSlayer=_slayer->getControler();
					}else{
						currentSlayer=_slayer;
					}
				}

				if(strcmp(currentSlayer->getCharacter()->getCString(),"Kakuzu")==0 ){
					if(currentSlayer->hearts<=4){
						currentSlayer->hearts+=1;	

						if(currentSlayer->_heartEffect){
							CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("Heart_Effect_%02d.png",currentSlayer->hearts)->getCString()); 
							currentSlayer->_heartEffect->setDisplayFrame(frame);
						}

						if(strcmp(currentSlayer->getRole()->getCString(),"Player")==0){
							if(currentSlayer->getMonsterArray() && currentSlayer->getMonsterArray()->count()<3 && currentSlayer->getLV()>=2){
								if(_delegate->getDelegate()->getHudLayer()->skill4Button){
									_delegate->getDelegate()->getHudLayer()->skill4Button->unLock();
								}
							}										
						}

					}

				}

				if(strcmp(currentSlayer->getRole()->getCString(),"Flog")!=0){

					int realKillNum=atoi(currentSlayer->getKillNum()->getCString())+1;
					currentSlayer->setKillNum(CCString::createWithFormat("%d",realKillNum));
					_delegate->getDelegate()->setReport(currentSlayer->getCharacter()->getCString(),_delegate->getCharacter()->getCString(),currentSlayer->getKillNum());
				
					
					//记分牌
					const char* currentTeam;
					if(_delegate->getDelegate()->zhenying>0){
						 currentTeam="Konoha";
					}else{
						 currentTeam="Akatsuki";
					}
					
					if(strcmp(currentSlayer->getGroup()->getCString(),currentTeam)==0){
						int teamKills=atoi(_delegate->getDelegate()->getHudLayer()->KonoLabel->getString())+1;
						_delegate->getDelegate()->getHudLayer()->KonoLabel->setString(CCString::createWithFormat("%d",teamKills)->getCString());
					}else{
						int teamKills=atoi(_delegate->getDelegate()->getHudLayer()->AkaLabel->getString())+1;
						_delegate->getDelegate()->getHudLayer()->AkaLabel->setString(CCString::createWithFormat("%d",teamKills)->getCString());
					}
					//
					if(strcmp(currentSlayer->getCharacter()->getCString(),"Han")!=0 &&
						strcmp(currentSlayer->getCharacter()->getCString(),"Roshi")!=0
						){
							int newValue=atoi(_delegate->getDelegate()->getTotalKills()->getCString())+1;
							_delegate->getDelegate()->setTotalKills(CCString::createWithFormat("%d",newValue));
					}

					

					
					if( currentSlayer->getLV()!=6){

						if(strcmp(currentSlayer->getCharacter()->getCString(),"Naruto")==0||
							strcmp(currentSlayer->getCharacter()->getCString(),"SageNaruto")==0
							){
								currentSlayer->setEXP(currentSlayer->getEXP()+125);
								currentSlayer->changeHPbar();

						}else{

							currentSlayer->setEXP(currentSlayer->getEXP()+100);
							currentSlayer->changeHPbar();
						}

					}
				
				

				
					if (strcmp(currentSlayer->getRole()->getCString(),"Player")==0){
						
						if(strcmp(_delegate->getCharacter()->getCString(),"Han")==0||
							strcmp(_delegate->getCharacter()->getCString(),"Roshi")==0
							){
								_delegate->getDelegate()->setCoin("1000");
								_delegate->setCoinDisplay(1000);
						}else{
							if(_delegate->getDelegate()->_isHardCoreGame){
								_delegate->getDelegate()->setCoin(CCString::createWithFormat("%d",50+(_delegate->getLV()-1)*10)->getCString());
								_delegate->setCoinDisplay(50+(_delegate->getLV()-1)*10);
							}else{
								_delegate->getDelegate()->setCoin(CCString::createWithFormat("%d",50)->getCString());
								_delegate->setCoinDisplay(50);
							}


						}

						_delegate->getDelegate()->getHudLayer()->setEXPLose(NULL);
						const char* kl=_delegate->getDelegate()->getHudLayer()->killLabel->getString();
						int kills=atoi(kl)+1;
						_delegate->getDelegate()->getHudLayer()->killLabel->setString(CCString::createWithFormat("%d",kills)->getCString());
					}



					if(strcmp(_delegate->getCharacter()->getCString(),"Han")==0||
					strcmp(_delegate->getCharacter()->getCString(),"Roshi")==0
					){
					currentSlayer->addCoin(1000);
					}else{
						if(_delegate->getDelegate()->_isHardCoreGame){
						currentSlayer->addCoin(50+(_delegate->getLV()-1)*10);
						}else{
						currentSlayer->addCoin(50);
						
						}
				
					}


					

				}

				//同队分享
				CCObject* pObject;
				CCARRAY_FOREACH(_delegate->getDelegate()->_CharacterArray,pObject){
					Hero* otherSlayer=(Hero*) pObject;
					if(strcmp(currentSlayer->getGroup()->getCString(),otherSlayer->getGroup()->getCString())==0 &&
						strcmp(currentSlayer->getCharacter()->getCString(),otherSlayer->getCharacter()->getCString())!=0
						){

						
						if(otherSlayer->getLV()!=6){
							otherSlayer->setEXP(otherSlayer->getEXP()+25);
							otherSlayer->changeHPbar();
						}

						
						if (strcmp(otherSlayer->getRole()->getCString(),"Player")==0){
							if(_delegate->getDelegate()->_isHardCoreGame){
								if(strcmp(_delegate->getCharacter()->getCString(),"Han")==0||
									strcmp(_delegate->getCharacter()->getCString(),"Roshi")==0
									){
										_delegate->getDelegate()->setCoin(CCString::createWithFormat("%d",850)->getCString());
										_delegate->setCoinDisplay(850);
								}else{
									_delegate->getDelegate()->setCoin(CCString::createWithFormat("%d",25+(_delegate->getLV()-1)*10)->getCString());
									_delegate->setCoinDisplay(25+(_delegate->getLV()-1)*10);
								}
							
							}else{
								_delegate->getDelegate()->setCoin(CCString::createWithFormat("%d",25)->getCString());
								_delegate->setCoinDisplay(25);
							}
							_delegate->getDelegate()->getHudLayer()->setEXPLose(NULL);
						}
						if(_delegate->getDelegate()->_isHardCoreGame){		
							if(strcmp(_delegate->getCharacter()->getCString(),"Han")==0||
								strcmp(_delegate->getCharacter()->getCString(),"Roshi")==0
								){
									otherSlayer->addCoin(850);
							}else{
								otherSlayer->addCoin(25+(_delegate->getLV()-1)*10);		
							}

						}else{
							otherSlayer->addCoin(25);
						}
						

					}
				}

				

		}

		_delegate->dead();

	}else{
		CCActionInterval* s=CCScaleTo::create(0.2f,percent,1);
		hpBar->runAction(s);
		if(strcmp(_delegate->getRole()->getCString(),"Player")==0){
			_delegate->getDelegate()->setHPLose(percent);
		}
	}

}


HPBar* HPBar::create( const char *szImage ){
	HPBar* hb=new HPBar();
	if (hb && hb->init(szImage))
	{
		hb->autorelease();
		return hb;
	}
	else
	{
		delete hb;
		return NULL;
	}
}
