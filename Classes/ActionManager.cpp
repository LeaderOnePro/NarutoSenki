#include "ActionManager.h"
#include "Characters.h"
#include "HudLayer.h"
#include "MyUtils/CCShake.h"


using namespace CocosDenshion;

ActionManager::ActionManager(void)
{
	
	_actionState=ACTION_STATE_WALK;

	_idleAction = NULL;
	_nattackAction = NULL;
	_walkAction = NULL;
	_hurtAction = NULL;
	_airHurtAction=NULL;
	_knockDownAction = NULL;
	_floatAction=NULL;
	_deadAction=NULL;
	_skill1Action=NULL;
	_skill2Action=NULL;
	_skill3Action=NULL;
	_skill4Action=NULL;
	_skill5Action=NULL;
	
	gearCKRValue=0;
	gearRecoverValue=0;
	isAttackGainCKR=false;
	isGearCD=false;
	isPofang=false;
	isHujia=false;
	battleCondiction=0;
	hearts=0;
	isHurtingTower=false;
	damageEffectCount=0;
	bamen=0;

	_isSuicide=false;

	_charNO=0;
	_backY=NULL;
	_DiretionY=NULL;

	_isAllAttackLocked=false;
	_isOnlySkillLocked=false;
	_sattack1isDouble=false;
	_sattack2isDouble=false;
	_sattack3isDouble=false;
	_sattack4isDouble=false;

	_moveAction=NULL;
	_jumpUPAction=NULL;
	_floatUPAction=NULL;
	
	_hurtFromLeft=false;
	_hurtFromRight=false;
	_isFlipped=false;
	_isHitOne=false;
	_isCatchOne=false;
	_isHealling=false;
	_isVisable=true;
	_isSticking=false;
	_isControled=false;


	_isCanSkill1=true;
	_isCanSkill2=true;
	_isCanSkill3=true;
	_isCanItem1=true;
	_isCanOugis1=false;
	_isCanOugis2=false;

	_isCanGear00=false;
	_isCanGear03=false;
	_isCanGear06=false;


	enemyCombatPoint=0;
	//totalCombatPoint=0;
	friendCombatPoint=0;

	isBaseDanger=false;

	_sattackCombatPoint1=0;
	_sattackCombatPoint2=0;
	_sattackCombatPoint3=0;
	_sattackCombatPoint4=0;
	_sattackCombatPoint5=0;

	_role=NULL;
	_group=NULL;
	_character=NULL;
	_killNum=NULL;
	_coin=NULL;

	_master=NULL;
	_controler=NULL;
	_secmaster=NULL;
	_slayer=NULL;
	_sticker=NULL;

	_mainTarget=NULL;

	_deadNum=0;
	_flogNum=0;
	
	_knockLength=NULL;
	_knockDiretion=NULL;

	_effectType=NULL;

	_damageArray=NULL;
	_monsterArray=NULL;

	_originY=NULL;
	
	_nattackValue=NULL;
	_sattackValue1=NULL;
	_sattackValue2=NULL;
	_sattackValue3=NULL;
	_sattackValue4=NULL;
	_sattackValue5=NULL;
	_spcattackValue1=NULL;
	_spcattackValue2=NULL;
	_spcattackValue3=NULL;
	_tempAttackValue1=NULL;
	

	_healBuffEffect=NULL;
	_powerBuffEffect=NULL;
	_skillBuffEffect=NULL;
	_healItemEffect=NULL;
	_speedItemEffect=NULL;
	_dehealBuffEffect=NULL;

	_buffStartTime=NULL;
	_debuffStartTime=NULL;
	_heartEffect=NULL;

	_shadow=NULL;

	_healBuffValue=NULL;
	_skillUPBuffValue=NULL;
	_skillChangeBuffValue=NULL;
	_dehealBuffValue=NULL;
	_powerUPBuffValue=NULL;
	_hpBar=NULL;
	_maxHP=NULL;
	_hp=NULL;
	_ckr=NULL;
	_ckr2=NULL;


	_gardValue=0;
	_exp=0;
	_level=1;

	_isWudi=false;
	_isTaunt=false;
	_isBati=false;

	_rebornTime=5;
	

	_markPoint=ccp(0,0);
	_startPoint=ccp(0,0);

	rebornLabelTime=0;

	_isAI=false;

	cpLabel=NULL;

	_gearArray=NULL;

}


ActionManager::~ActionManager(void)
{
	
}


void ActionManager::setID(CCString* character,CCString* role,CCString* group){}

void ActionManager::setHPbar(){}
void ActionManager::setShadows(){}
void ActionManager::changeHPbar(){}


void ActionManager::readDate(CCArray* tmpDate,CCString* &attackType,CCString* &attackValue,int &attackRangeX,int &attackRangeY,unsigned int &coldDown,int &combatPoint){
	
	CCDictionary* tmpDict;
	
	for(unsigned int i=0;i<tmpDate->count();++i){
		tmpDict=(CCDictionary * )(tmpDate->objectAtIndex(i));
		switch(i){
		case 0:
			attackType=CCString::create(tmpDict->valueForKey("attackType")->getCString());
			break;
		case 1:
			attackValue=CCString::create(tmpDict->valueForKey("attackValue")->getCString());
				//tmpDict->valueForKey("attackValue")->intValue();
			break;
		case 2:
			attackRangeX=tmpDict->valueForKey("attackRangeX")->intValue();
			break;
		case 3:
			attackRangeY=tmpDict->valueForKey("attackRangeY")->intValue();
			break;
		case 4:
			coldDown=tmpDict->valueForKey("coldDown")->intValue();
		case 5:
			combatPoint=tmpDict->valueForKey("combatPoint")->intValue();
		};

	};

};

void ActionManager::onEnter(){
	CCSprite::onEnter();
	
}

void ActionManager::onExit(){
	CCSprite::onExit();
	
};



void ActionManager::update(float dt){

	if(_healBuffEffect){
		_healBuffEffect->setPositionX(this->getContentSize().width/2+(_isFlipped?2:-2));
	} 
	if(_powerBuffEffect){
		_powerBuffEffect->setPositionX(this->getContentSize().width/2+(_isFlipped?2:-2));
	} 
	if(_skillBuffEffect){
		_skillBuffEffect->setPositionX(this->getContentSize().width/2);
	}

	if(_heartEffect){
		_heartEffect->setPositionX(this->getContentSize().width/2+(_isFlipped?22:-22));
	}

	/*if(_healItemEffect){
	_healItemEffect->setPosition(ccp(_isFlipped?this->getContentSize().width/2+16:this->getContentSize().width/2-16,
	this->_height));
	}

	if(_speedItemEffect){
	_speedItemEffect->setPosition(ccp(_isFlipped?this->getContentSize().width/2+16:this->getContentSize().width/2-16,
	this->_height));
	}*/

	
	/*if(_kaguraEffect){
		_kaguraEffect->setPosition(ccp(this->getPositionX(),this->getPositionY()+this->getContentSize().height/2));
	}*/

	if(_dehealBuffEffect){		
		_dehealBuffEffect->setPositionX(this->getContentSize().width/2);
	}


	if(_hpBar){
		_hpBar->setPositionX(this->getContentSize().width/2-this->_hpBar->getHPBottom()->getContentSize().width/2);
	};

	if(_shadow){
		_shadow->setPosition(ccp(this->getPositionX(),_originY?_originY:this->getPositionY()));
	}

	
	
	
	
	if(!_isControled && _actionState!=ACTION_STATE_DEAD){
		if(strcmp(this->_role->getCString(),"Player")==0 || strcmp(this->_role->getCString(),"Com")==0){

			if(strcmp(this->_character->getCString(),"Roshi")!=0 &&
				strcmp(this->_character->getCString(),"Han")!=0){


					if(strcmp(this->_group->getCString(),"Konoha")==0 && this->getPositionX()<=11*32){
					    _isHealling=true;
						if(this->getHpPercent()<1.0f){
							this->scheduleOnce(schedule_selector(ActionManager::setRestore),1.0f);							
						}
					}else if(strcmp(this->_group->getCString(),"Akatsuki")==0 && this->getPositionX()>=85*32){
						_isHealling=true;
						if ( this->getHpPercent()<1.0f){	
							this->scheduleOnce(schedule_selector(ActionManager::setRestore),1.0f);						
						}
					}else{
						_isHealling=false;
					}
			}
		}
	}
	
	

	if(_actionState == ACTION_STATE_WALK){
		
		_desiredPosition=ccpAdd(this->getPosition(), ccpMult(_velocity,dt));

		

			if(strcmp(this->_role->getCString(),"Player")==0  && !_isAI && !_isWudi && !_isBati){
				
				//save the stop Area
				CCObject* pObject;
				CCARRAY_FOREACH(this->_delegate->_TowerArray,pObject){
	
					Tower* tower=(Tower*) pObject;
					if(tower){
						int metaWidth=96;
						int metaHeight=128;
						int metaX=tower->getPositionX()-metaWidth/2;
						int metaY=tower->getPositionY()-metaHeight/2;
						CCRect rect=CCRectMake(metaX,metaY+32,metaWidth,metaHeight-64);

						if (rect.containsPoint(_desiredPosition)){
							float anchorYpoint=metaY+metaHeight/2;
							if(this->getPositionY()>anchorYpoint){
								_velocity =ccp(0,1 * this->_walkSpeed*winSize.width/1280);
							}else{
								_velocity =ccp(0,-1 * this->_walkSpeed*winSize.width/1280);
							}
							_desiredPosition=ccpAdd(this->getPosition(), ccpMult(_velocity,dt));
						};

					}
					
				};
			
			};
	
		float posX= MIN(_delegate->currentMap->getMapSize().width*_delegate->currentMap->getTileSize().width,
			MAX(0,_desiredPosition.x));

		float poxY=MIN(_delegate->currentMap->getTileSize().height*5.5,MAX(0,_desiredPosition.y));
		
		this->setPosition(ccp(posX,poxY));
		_delegate->reorderChild(this,-this->getPositionY());
		//更新minimap
		if(strcmp(this->getRole()->getCString(),"Player")==0 || strcmp(this->getRole()->getCString(),"Com")==0){
			CCNotificationCenter::sharedNotificationCenter()->postNotification("updateMap", this);
		}

	};


};


void ActionManager::acceptAttack(CCObject* object){

	if(strcmp(this->getCharacter()->getCString(),"Tobi")==0){

		ActionManager* currentSlayer=NULL;
		if(this->_slayer){
			currentSlayer=(ActionManager*) this->_slayer;
		}	
		if(_skillChangeBuffValue &&(
			this->getActionState()==ACTION_STATE_IDLE ||
			this->getActionState()==ACTION_STATE_WALK ||
			this->getActionState()==ACTION_STATE_ATTACK
			)){
				if (this->getOpacity()==255){
					this->scheduleOnce(schedule_selector(ActionManager::disableBuff),0.2f);
				}
				this->setOpacity(150);
				return;			
		}	
	}
	ActionManager* Attacker=(ActionManager *) object;
	bool isBizhong=false;
	if(strcmp(Attacker->getCharacter()->getCString(),"Hiruzen")==0 && Attacker->getActionState()==ACTION_STATE_O2ATTACK){
		isBizhong=true;
	}

	if(strcmp(this->_group->getCString(),Attacker->_group->getCString())!=0 		
		&&_isVisable
		&& (!_isWudi || isBizhong)	
		&& this->getActionState()!=ACTION_STATE_DEAD
		){
		
		// Tower 
		if(strcmp(this->_role->getCString(),"Tower")==0){

			

			bool isHit=false;
			if(strcmp(Attacker->_attackType->getCString(),"nAttack")==0 && 
				strcmp(Attacker->_effectType->getCString(),"f_hit")!=0  
				&& strcmp(Attacker->_effectType->getCString(),"c_hit")!=0
				&& strcmp(Attacker->_effectType->getCString(),"o_hit")!=0
				&& strcmp(Attacker->_effectType->getCString(),"b_hit")!=0
				&& strcmp(Attacker->_effectType->getCString(),"bc_hit")!=0
				){

			
				if(this->setHitBox().intersectsRect(Attacker->setHalfBox())) {
				isHit=true;
				}

			}else if(strcmp(Attacker->_effectType->getCString(),"n_hit")==0){
				
				bool isHitX=false;
				float distanceX=ccpSub(Attacker->getPosition(),this->getPosition()).x;

				float tempRange1=Attacker->_attackRangeX+Attacker->getContentSize().width/2
					+this->getContentSize().width/2;

					
				if(!Attacker->_isFlipped && distanceX<0 && -distanceX<tempRange1){
					_hurtFromLeft=true;
					isHitX=true;
				}else if(Attacker->_isFlipped && distanceX>0 && distanceX<tempRange1){
					_hurtFromRight=true;
					isHitX=true;
				};
					
				if(isHitX){
					if(abs(this->getPositionY()-Attacker->getPositionY())<=Attacker->_attackRangeY){
						isHit=true;
					}
				}

			}

			if(isHit){
					
				_slayer=Attacker;
				this->setDamage(Attacker->_effectType,Attacker->_attackValue,Attacker->_isFlipped);
				if(_hpBar){
					_hpBar->loseHP(this->getHpPercent());
				}
					
				if(!this->_isHitOne){
					this->_isHitOne=true;
					CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(ActionManager::disableShack));
					CCDelayTime* delay=CCDelayTime::create(0.5f);
					CCArray* list=CCArray::create();
					list->addObject(CCShake::createWithStrength(0.1f,2,0));
					list->addObject(delay);
					list->addObject(call);
					this->runAction(CCSequence::create(list));
				}
					
			}
				
		
			return;
			
		//bullet 
		}else if(strcmp(Attacker->_role->getCString(),"Bullet")==0){

			if(this->setHitBox().intersectsRect(Attacker->setHitBox())) {

				if(strcmp(this->getCharacter()->getCString(),"Hidan")==0 && this->_skillChangeBuffValue){

					bool _isCounter=false;
					if(_monsterArray && _monsterArray->count()>0){
						CCObject* pObject;
						CCARRAY_FOREACH(this->_monsterArray,pObject){
							ActionManager* tempMonster=(ActionManager*) pObject;
							float distanceX=ccpSub(tempMonster->getPosition(),this->getPosition()).x;
							float distanceY=ccpSub(tempMonster->getPosition(),this->getPosition()).y;
							if(abs(distanceX)<40 && abs(distanceY)<15){
								_isCounter=true;
							}
						}
					}

					if(_isCounter){
						if(Attacker->_master && Attacker->_master->_actionState!=ACTION_STATE_DEAD){

							Attacker->_master->_slayer=this;

							Attacker->_master->setDamage(Attacker->_effectType,Attacker->_attackValue,Attacker->_isFlipped);
							if(Attacker->_master->_hpBar){
								Attacker->_master->_hpBar->loseHP(Attacker->_master->getHpPercent());
							}

						}

						CCObject* pObject;
						CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
							Hero* tempHero=(Hero*) pObject;
							if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
								&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
								&& tempHero->_actionState!=ACTION_STATE_DEAD
								){
									tempHero->_slayer=this;
									tempHero->setDamage(Attacker->_effectType,Attacker->_attackValue/2,Attacker->_isFlipped);
									if(tempHero->_hpBar){
										tempHero->_hpBar->loseHP(tempHero->getHpPercent());
									}
							}
						}

						return;
					
					}
				
				}

				_slayer=Attacker;
				this->setDamage(Attacker->_effectType,Attacker->_attackValue,Attacker->_isFlipped);
				if(_hpBar){
					_hpBar->loseHP(this->getHpPercent());
				}

				//飞雷神销毁
				if(strcmp(Attacker->_character->getCString(),"HiraishinKunai")==0 ||
					strcmp(Attacker->_character->getCString(),"Shintenshin")==0
					){
						if((strcmp(this->_role->getCString(),"Player")==0 || strcmp(this->_role->getCString(),"Com")==0)
							&& strcmp(this->_character->getCString(),"Roshi")!=0
							&& strcmp(this->_character->getCString(),"Han")!=0
							&& this->_actionState!=ACTION_STATE_DEAD
							){
							
							Attacker->stopAllActions();
							Attacker->dealloc();

							if(strcmp(Attacker->_character->getCString(),"Shintenshin")==0 && !Attacker->_isCatchOne){
								Attacker->_isCatchOne=true;
								if(Attacker->_master){
									this->_isControled=true;
									this->_controler=Attacker->_master;

									if(Attacker->_master->getActionState()==ACTION_STATE_O2ATTACK){
										Attacker->_master->stopAllActions();
										Attacker->_master->runAction(createAnimation(Attacker->_master->skillSPC1Array,10.0f,false,false));
										Attacker->_master->scheduleOnce(schedule_selector(ActionManager::resumeAction),15);
										Attacker->_master->_isBati=true;
										Attacker->_master->_isWudi=false;
									}

									if(strcmp(_controler->getRole()->getCString(),"Player")==0){
										this->_delegate->controlChar=this;
									}

									if(strcmp(this->getRole()->getCString(),"Player")==0){
										this->doAI();
										this->_delegate->getHudLayer()->_isAllButtonLocked=true;	
									}
									this->changeGroup();
									
								}

							}
						}

				}
	
			}

			return;


		}else{
			
			bool isHitX=false;


			float distanceX=ccpSub(Attacker->getPosition(),this->getPosition()).x;

			float tempRange1=Attacker->_attackRangeX+Attacker->getContentSize().width/2
				+this->getContentSize().width/2;

			if(strcmp(Attacker->_attackType->getCString(),"aAttack")==0 ){
				if(abs(distanceX)<=tempRange1){
					isHitX=true;
				}
			}else{
				
				if(!Attacker->_isFlipped && distanceX<0 && -distanceX<tempRange1){
					_hurtFromLeft=true;
					isHitX=true;

				}else if(Attacker->_isFlipped && distanceX>0 && distanceX<tempRange1){
					_hurtFromRight=true;
					isHitX=true;
				};
			}

			if(isHitX){



				float attackerPosY;
				float currentPosY;
		
				//y轴矫正
				if(Attacker->_actionState==ACTION_STATE_JUMP){
					attackerPosY=Attacker->_originY;
				}else{
					attackerPosY=Attacker->getPositionY();
				};

				if(this->_actionState==ACTION_STATE_FLOAT || this->_actionState==ACTION_STATE_JUMP ||  this->_actionState==ACTION_STATE_AIRHURT){
					currentPosY=_originY;
				}else{
					currentPosY=this->getPositionY();
				};

				
				if(abs(currentPosY-attackerPosY)<=Attacker->_attackRangeY){
					
					const char* hitType=Attacker->_effectType->getCString();

					//hit or not !
					Attacker->_isHitOne=true;
					
					//record the slayer
					_slayer=Attacker;

					//flog hurt 
					if (strcmp(this->_role->getCString(),"Flog")==0){
						if(strcmp(hitType,"o_hit")==0){
							this->setKnockLength(48);
							this->setKnockDiretion(Attacker->_isFlipped);
							this->hurt();
						}else if(strcmp(hitType,"ac_hit")==0){
							this->airHurt();
						}else if(strcmp(hitType,"f_hit")==0  || strcmp(hitType,"bf_hit")==0){
							if(_isFlipped==Attacker->_isFlipped){
								if(_isFlipped){
									this->setFlipX(false);
									_isFlipped=false;
								}else{
									this->setFlipX(true);
									_isFlipped=true;
								}
							}
							this->floatUP(64,true);
						}else if(strcmp(hitType,"f2_hit")==0 ){
							if(_isFlipped==Attacker->_isFlipped){
								if(_isFlipped){
									this->setFlipX(false);
									_isFlipped=false;
								}else{
									this->setFlipX(true);
									_isFlipped=true;
								}
							}
							this->floatUP(128,true);
						}
						else if(strcmp(hitType,"b_hit")==0){
							if(_isFlipped==Attacker->_isFlipped){
								if(_isFlipped){
									this->setFlipX(false);
									_isFlipped=false;
								}else{
									this->setFlipX(true);
									_isFlipped=true;
								}
							}
							this->floatUP(16,false);

						}else if(strcmp(hitType,"ab_hit")==0 ){
							this->absorb(Attacker->getPosition(),true);
						}else if(strcmp(hitType,"s_hit")==0 ){
							this->absorb(Attacker->getPosition(),false);
						}
						
					}// hero hurt
					else if(strcmp(this->_role->getCString(),"Player")==0
						||strcmp(this->_role->getCString(),"Com")==0
						||strcmp(this->_role->getCString(),"Clone")==0
						){
						
						if(strcmp(hitType,"l_hit")==0){
							if(!this->_isBati){
							this->setKnockLength(32);	
							}
							this->hurt();
						}else if(strcmp(hitType,"c_hit")==0 ||
							strcmp(hitType,"bc_hit")==0){
							if(!this->_isBati){
							this->setKnockLength(1);	
							}

							if(strcmp(Attacker->getCharacter()->getCString(),"Kakuzu")==0 && this->_sticker){
								ActionManager* stHero=(ActionManager *) _sticker;
								if(strcmp(stHero->getCharacter()->getCString(),"Kakuzu")==0 && stHero->hearts<=4){
									
									Attacker->hearts+=1;	

									if(Attacker->_heartEffect){
										CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("Heart_Effect_%02d.png",Attacker->hearts)->getCString()); 
										Attacker->_heartEffect->setDisplayFrame(frame);
									}																	
	
								}

								if(strcmp(Attacker->getRole()->getCString(),"Player")==0 && Attacker->hearts>0 ){
									CCObject* pObject;
									int countMON=0;
									CCARRAY_FOREACH(Attacker->getMonsterArray(),pObject){
										Monster* mo=(Monster*) pObject;
										if(strcmp(mo->getCharacter()->getCString(),"Traps")!=0){
											countMON++;
										}

									};
									if(countMON<3 && Attacker->getLV()>=2){
										if(_delegate->getHudLayer()->skill4Button){
											_delegate->getHudLayer()->skill4Button->unLock();
										}
									}										
								}

							}
							this->hurt();
						}else if(strcmp(hitType,"ts_hit")==0){
							if(!this->_isBati){
								this->setKnockLength(1);
							}	
							if(this->hurt() && 
								(!Attacker->_isCatchOne  || strcmp(Attacker->getCharacter()->getCString(),"FakeMinato")==0)
								){
							  Attacker->_isCatchOne=true;
							  if(Attacker->getMaster()){
								  if( strcmp(Attacker->getCharacter()->getCString(),"FakeMinato")==0){
									  this->setPosition(ccp(Attacker->getMaster()->_isFlipped?Attacker->getMaster()->getPositionX()-64:Attacker->getMaster()->getPositionX()+64,
										  Attacker->getMaster()->getPositionY()+2));
								  }else{
									  this->setPosition(ccp(Attacker->getMaster()->_isFlipped?Attacker->getMaster()->getPositionX()-48:Attacker->getMaster()->getPositionX()+48,
										  Attacker->getMaster()->getPositionY()));
								  }

								 
								  CCNotificationCenter::sharedNotificationCenter()->postNotification("updateMap", this);
								  _delegate->reorderChild(this,-this->getPositionY());
							  }
							}
								
								
						}else if(strcmp(hitType,"sl_hit")==0){
							if(!this->_isBati){
								this->setKnockLength(1);
							}	
							this->hurt();
							if(this->getWalkSpeed()==224){
							this->setWalkSpeed(112);
							this->schedule(schedule_selector(ActionManager::disableDebuff),3);
							}						

						}else if(strcmp(hitType,"ac_hit")==0){
							if(this->_actionState==ACTION_STATE_FLOAT || this->_actionState==ACTION_STATE_AIRHURT){
								this->airHurt();
							}else{
								if(!this->_isBati){
								this->setKnockLength(1);
								}
								this->hurt();
							}
						}else if(strcmp(hitType,"o_hit")==0){
							if(this->_actionState!=ACTION_STATE_OATTACK || 
								(this->_actionState==ACTION_STATE_OATTACK && 
								(Attacker->_actionState==ACTION_STATE_O2ATTACK || 
								Attacker->_actionState==ACTION_STATE_OATTACK))
								){
								if(!this->_isBati){
								this->setKnockLength(48);
								}
								this->setKnockDiretion(Attacker->_isFlipped);
								this->hardHurt(500,true,false,false,false);
							}
							
						}else if(strcmp(hitType,"o2_hit")==0){
							if(!this->_isBati){
							this->setKnockLength(1);
							}
							this->setKnockDiretion(Attacker->_isFlipped);
							this->hardHurt(1000,true,false,false,true);

						}else if(strcmp(hitType,"ob_hit")==0){
							if(!this->_isBati){
								this->setKnockLength(1);
							}
							this->setKnockDiretion(Attacker->_isFlipped);
							this->hardHurt(2000,true,false,false,true);

							if	(this->_dehealBuffEffect){
								this->_dehealBuffValue+=1000;
							}else {
								this->_dehealBuffValue=1000;
								this->setBuffEffect("dhBuff");
								this->schedule(schedule_selector(ActionManager::dehealBuff),1);
							}
							this->scheduleOnce(schedule_selector(ActionManager::disableBuff),5);

						}
						else if(strcmp(hitType,"ct_hit")==0){
						
							if(this->_actionState!=ACTION_STATE_OATTACK || 
								(this->_actionState==ACTION_STATE_OATTACK && 
								(Attacker->_actionState==ACTION_STATE_O2ATTACK || 
								Attacker->_actionState==ACTION_STATE_OATTACK))
								){
									if (Attacker->_isCatchOne == false || 
										strcmp(Attacker->getCharacter()->getCString(),"Shenwei")==0 
									){

										
											if(Attacker->getMaster()){

												if(strcmp(Attacker->getCharacter()->getCString(),"Kuroari")==0||
													strcmp(Attacker->getCharacter()->getCString(),"Shenwei")==0 ||
													strcmp(Attacker->getCharacter()->getCString(),"Sabaku")==0 ||
													strcmp(Attacker->getCharacter()->getCString(),"Shenwei2")==0){
														if(this->hardHurt(3000,false,true,false,false)){
																Attacker->_isCatchOne=true;
															this->scheduleOnce(schedule_selector(ActionManager::reCatched),2.9f);
														}

												}else if(strcmp(Attacker->getCharacter()->getCString(),"SandBall")==0){
													if(this->hardHurt(1000,false,true,false,false)){
																Attacker->_isCatchOne=true;
															this->scheduleOnce(schedule_selector(ActionManager::reCatched),0.9f);
														}
												}else if(strcmp(Attacker->getMaster()->getCharacter()->getCString(),"Shikamaru")==0){
													bool pianyi=false;
													if(strcmp(Attacker->getCharacter()->getCString(),"KageHand")==0){
														if(pianyi=this->hardHurt(6000,false,false,true,false)){
															
															Attacker->stopAllActions();
															Attacker->schedule(schedule_selector(ActionManager::getSticker),0.1f);
															this->schedule(schedule_selector(ActionManager::lostBlood),1.0f);
															this->lostBloodValue=400;
															this->scheduleOnce(schedule_selector(ActionManager::removeLostBlood),6.0f);
														}
													
													}else if(strcmp(Attacker->getCharacter()->getCString(),"QuanRen")==0||
														strcmp(Attacker->getCharacter()->getCString(),"KageBom")==0 ){
														pianyi=this->hardHurt(3000,false,false,true,false);
													}

													
													
													if(pianyi){
														Attacker->_isCatchOne=true;
														this->setPosition(CCPointMake(Attacker->getPositionX()
															,Attacker->getPositionY()+1));
														_delegate->reorderChild(this,-this->getPositionY());

													}
													
													
												}else if(strcmp(Attacker->getMaster()->getCharacter()->getCString(),"Itachi")==0  ||
													strcmp(Attacker->getMaster()->getCharacter()->getCString(),"Chiyo")==0 
													) {
			
														
														bool pianyi=false;

														if(strcmp(Attacker->getMaster()->getCharacter()->getCString(),"Chiyo")==0 ){
															pianyi=this->hardHurt(2000,false,false,true,false);
														}else{
															pianyi=this->hardHurt(3000,false,false,true,false);
														}
														if(pianyi){
															Attacker->_isCatchOne=true;
															this->setPosition(CCPointMake(Attacker->getPositionX()+2
																,Attacker->getPositionY()-2));
															_delegate->reorderChild(this,-this->getPositionY());


														}						
												}
											}else {

												if(strcmp(Attacker->getCharacter()->getCString(),"Lee")==0 ||
													strcmp(Attacker->getCharacter()->getCString(),"RockLee")==0
													){
													
												
													if(this->hardHurt(1000,false,true,false,false)){
														Attacker->_isCatchOne=true;
														this->scheduleOnce(schedule_selector(ActionManager::reCatched),1.1f);
													}
													
													
												}else if(strcmp(Attacker->getCharacter()->getCString(),"Kakuzu")==0){
													bool pianyi=false;
													
													if(!this->_isBati){
														this->setKnockLength(1);
													}
													pianyi=this->hardHurt(1500,false,false,true,true);

													if(pianyi){
														Attacker->_isCatchOne=true;
														this->setPosition(CCPointMake(Attacker->getPositionX()+(Attacker->_isFlipped?-28:28)
															,Attacker->getPositionY()-1));
														this->setFlipX(Attacker->_isFlipped?false:true);
														_delegate->reorderChild(this,-this->getPositionY());

													}
												}else if(strcmp(Attacker->getCharacter()->getCString(),"Tobi")==0){
													if(!this->_isBati){
														this->setKnockLength(1);
													}
													this->hardHurt(1000,true,false,false,false);
												}
											}

							}
							

							}
						}else if(strcmp(hitType,"f_hit")==0  || strcmp(hitType,"bf_hit")==0){
							if(_isFlipped==Attacker->_isFlipped){
								if(_isFlipped){
									this->setFlipX(false);
									_isFlipped=false;
								}else{
									this->setFlipX(true);
									_isFlipped=true;
								}

							}
							if(this->_actionState!=ACTION_STATE_OATTACK || 
								(this->_actionState==ACTION_STATE_OATTACK && 
								(Attacker->_actionState==ACTION_STATE_O2ATTACK || 
								Attacker->_actionState==ACTION_STATE_OATTACK))
							){
							this->floatUP(64,true);
							}

						}else if(strcmp(hitType,"f2_hit")==0 ){

							if(_isFlipped==Attacker->_isFlipped){
								if(_isFlipped){
									this->setFlipX(false);
									_isFlipped=false;
								}else{
									this->setFlipX(true);
									_isFlipped=true;
								}
							}
							if(this->_actionState!=ACTION_STATE_OATTACK || 
								(this->_actionState==ACTION_STATE_OATTACK && 
								(Attacker->_actionState==ACTION_STATE_O2ATTACK || 
								Attacker->_actionState==ACTION_STATE_OATTACK))
								){
							this->floatUP(128,true);
							}
						}else if(strcmp(hitType,"b_hit")==0){

							if(_isFlipped==Attacker->_isFlipped){
								if(_isFlipped){
									this->setFlipX(false);
									_isFlipped=false;
								}else{
									this->setFlipX(true);
									_isFlipped=true;
								}
							}

							if(this->_actionState!=ACTION_STATE_OATTACK || 
								(this->_actionState==ACTION_STATE_OATTACK && 
								(Attacker->_actionState==ACTION_STATE_O2ATTACK || 
								Attacker->_actionState==ACTION_STATE_OATTACK))
							){
							this->floatUP(16,false);
							}
						}else if(strcmp(hitType,"ab_hit")==0 ){

							this->absorb(Attacker->getPosition(),true);

						}else if(strcmp(hitType,"s_hit")==0 ){
							this->absorb(Attacker->getPosition(),false);
						}

					}
					
					if(strcmp(this->getCharacter()->getCString(),"Hidan")==0 && this->_skillChangeBuffValue){
						
						bool _isCounter=false;
						if(_monsterArray && _monsterArray->count()>0){
							CCObject* pObject;
							CCARRAY_FOREACH(this->_monsterArray,pObject){
								ActionManager* tempMonster=(ActionManager*) pObject;
								float distanceX=ccpSub(tempMonster->getPosition(),this->getPosition()).x;
								float distanceY=ccpSub(tempMonster->getPosition(),this->getPosition()).y;
								if(abs(distanceX)<40 && abs(distanceY)<15){
									_isCounter=true;
								}
							}
						}

						if(_isCounter &&  
							strcmp(Attacker->_character->getCString(),"Roshi")!=0 &&
							strcmp(Attacker->_character->getCString(),"Han")!=0 ){
							if(Attacker->_master && Attacker->_master->_actionState!=ACTION_STATE_DEAD){
								
								Attacker->_master->_slayer=this;
								
								Attacker->_master->setDamage(Attacker->_effectType,Attacker->_attackValue,Attacker->_isFlipped);
								if(Attacker->_master->_hpBar){
									Attacker->_master->_hpBar->loseHP(Attacker->_master->getHpPercent());
								}
							}else if(!Attacker->_master){

								if(Attacker->_actionState!=ACTION_STATE_DEAD){

									Attacker->_slayer=this;
									
									Attacker->setDamage(Attacker->_effectType,Attacker->_attackValue,Attacker->_isFlipped);
									if(Attacker->_hpBar){
										Attacker->_hpBar->loseHP(Attacker->getHpPercent());
									}
								}

							}


							CCObject* pObject;
							CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
								Hero* tempHero=(Hero*) pObject;
								if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
									&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
									&& tempHero->_actionState!=ACTION_STATE_DEAD
									){
										tempHero->_slayer=this;
										tempHero->setDamage(Attacker->_effectType,Attacker->_attackValue/2,Attacker->_isFlipped);
										if(tempHero->_hpBar){
											tempHero->_hpBar->loseHP(tempHero->getHpPercent());
										}
								}
							}

							return;

						}
						
					
					}

					if(strcmp(this->getCharacter()->getCString(),"Kakuzu")==0 && this->_skillChangeBuffValue){
						
						if(!Attacker->_master){

							if(Attacker->_actionState!=ACTION_STATE_DEAD){

								Attacker->_slayer=this;

								Attacker->setDamage(Attacker->_effectType,Attacker->_attackValue/2,Attacker->_isFlipped);
								if(Attacker->_hpBar){
									Attacker->_hpBar->loseHP(Attacker->getHpPercent());
								}
							}

						}

					}

					this->setDamage(Attacker->_effectType,Attacker->_attackValue,Attacker->_isFlipped);
					//lose the hp
					if(_hpBar){
						_hpBar->loseHP(this->getHpPercent());
					}

				}
			}


		}

	};


};


CCAction* ActionManager::createAnimation(CCArray* ationArray,float fps,bool isRepeat,bool isReturn){


	CCObject* tObject;
	CCArray* animeFrames=CCArray::create();
	CCArray* seqArray=CCArray::create();
	CCAnimation* tempAnimation;
	CCAction* tempAction;
	CCAction* seq;


	CCARRAY_FOREACH(ationArray,tObject){
		CCDictionary* dic=(CCDictionary *)tObject;
		CCDictElement* ele=NULL;


		CCDICT_FOREACH(dic,ele){
			const char* key=CCString::create(ele->getStrKey())->getCString();
			const char* keyValue=dic->valueForKey(key)->getCString();
			if(strcmp(key,"frameName")==0){

				CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(keyValue);
				animeFrames->addObject(frame);

			}else{
				tempAnimation=CCAnimation::createWithSpriteFrames(animeFrames, float(1.0 / fps));
				tempAction=CCAnimate::create(tempAnimation);
			
				seqArray->addObject(tempAction);
				if(strcmp(key,"setAttackBox")==0){
					callValue = CCDictionary::create(); 
					callValue->retain();
					callValue->setObject(CCString::create(keyValue), 1);
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setAttackBox),(void*)callValue);
					seqArray->addObject(call);
				}else if(strcmp(key,"setSound")==0){
					callValue = CCDictionary::create(); 
					callValue->retain();
					callValue->setObject(CCString::create(keyValue), 1);
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setSound),(void*)callValue);
					seqArray->addObject(call);
				}else if(strcmp(key,"setDSound")==0){
					callValue = CCDictionary::create(); 
					callValue->retain();
					callValue->setObject(CCString::create(keyValue), 1);
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setDSound),(void*)callValue);
					seqArray->addObject(call);
				}else if(strcmp(key,"setDelay")==0){
					float delayTime=dic->valueForKey(key)->intValue();
					CCAction* delay=CCDelayTime::create(delayTime/100);
					seqArray->addObject(delay);
				}else if(strcmp(key,"setMove")==0){
					int moveLength=dic->valueForKey(key)->intValue();
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setMove),(void*)moveLength);
					seqArray->addObject(call);
				}else if(strcmp(key,"setSkillEffect")==0){
					callValue = CCDictionary::create(); 
					callValue->retain();
					callValue->setObject(CCString::create(keyValue), 1);
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setSkillEffect),(void*)callValue);
					seqArray->addObject(call);
				}else if(strcmp(key,"setJump")==0){
					bool jumpDirection=dic->valueForKey(key)->boolValue();
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setJump),(void*)jumpDirection);
					seqArray->addObject(call);
				}
				else if(strcmp(key,"setCharge")==0){
					CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(ActionManager::getCollider));
					seqArray->addObject(call);
					int moveLength=dic->valueForKey(key)->intValue();
					call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setCharge),(void*)moveLength);
					seqArray->addObject(call);
				}else if(strcmp(key,"setChargeB")==0){
					int moveLength=dic->valueForKey(key)->intValue();
					CCFiniteTimeAction* call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setChargeB),(void*)moveLength);
					seqArray->addObject(call);
				}else if(strcmp(key,"setClone")==0){
					int cloneTime=dic->valueForKey(key)->intValue();
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setClone),(void*)cloneTime);
					seqArray->addObject(call);
				}else if(strcmp(key,"setMon")==0){
					callValue = CCDictionary::create(); 
					callValue->retain();
					callValue->setObject(CCString::create(keyValue), 1);
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setMon),(void*)callValue);
					seqArray->addObject(call);
				}else if(strcmp(key,"setFont")==0){
					callValue = CCDictionary::create(); 
					callValue->retain();
					const char * split = ",";
					char * p; 
					char* str = new char[20];
					strcpy(str,keyValue);
					p = strtok (str,split); 
					int i=1;
					while(p!=NULL) { 
						callValue->setObject(CCString::create(p), i);
						i++;
						p = strtok(NULL,split); 
					} 

					//CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setFontEffect),(void*)callValue);
					//seqArray->addObject(call);

				}else if(strcmp(key,"setBuff")==0){
					int buffValue=dic->valueForKey(key)->intValue();
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setBuff),(void*)buffValue);
					seqArray->addObject(call);
				}else if(strcmp(key,"setCommand")==0){
					callValue = CCDictionary::create(); 
					callValue->retain();
					callValue->setObject(CCString::create(keyValue), 1);
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setCommand),(void*)callValue);
					seqArray->addObject(call);

				}else if(strcmp(key,"setDetonation")==0){
					CCFiniteTimeAction *call = CCCallFunc::create(this,callfunc_selector(ActionManager::dealloc));
					seqArray->addObject(call);

				}else if(strcmp(key,"setBullet")==0){
					callValue = CCDictionary::create(); 
					callValue->retain();
					callValue->setObject(CCString::create(keyValue), 1);
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setBullet),(void*)callValue);
					seqArray->addObject(call);
				}else if(strcmp(key,"setMonAttack")==0){
					int skillNum=dic->valueForKey(key)->intValue();
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setMonAttack),(void*)skillNum);
					seqArray->addObject(call);
				}else if(strcmp(key,"setTrap")==0){
					callValue = CCDictionary::create(); 
					callValue->retain();
					callValue->setObject(CCString::create(keyValue), 1);
				CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setTrap),(void*)callValue);
					seqArray->addObject(call);
				}else if(strcmp(key,"setActionResume")==0){
					CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(ActionManager::setActionResume));
					seqArray->addObject(call);
				}
				else if(strcmp(key,"setActionResume2")==0){
					CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(ActionManager::setActionResume2));
					seqArray->addObject(call);
				}else if(strcmp(key,"setShadow")==0){
					callValue = CCDictionary::create(); 
					callValue->retain();
					callValue->setObject(animeFrames->objectAtIndex(int(animeFrames->count()-1)),1);
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setShadow),(void*)callValue);
					seqArray->addObject(call);
				}
				else if(strcmp(key,"setTransform")==0){
					CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(ActionManager::setTransform));
					seqArray->addObject(call);
				}
				else if(strcmp(key,"setOugis")==0){
					CCFiniteTimeAction *call= CCCallFuncN::create(this,callfuncN_selector(ActionManager::setOugis));
					seqArray->addObject(call);
				}else if (strcmp(key,"stopJump")==0){
					int stopTime=dic->valueForKey(key)->intValue();
					CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::stopJump),(void*)stopTime);
					seqArray->addObject(call);
				}else if (strcmp(key,"setFlipped")==0){
					CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(ActionManager::setCharFlip));
					seqArray->addObject(call);
				}

				animeFrames->removeAllObjects();		
			}

		}
	};
	if(animeFrames->count()>0){
		tempAnimation= CCAnimation::createWithSpriteFrames(animeFrames, float(1.0 / fps));
		tempAction=CCAnimate::create(tempAnimation);
		seqArray->addObject(tempAction);
	};

	if(isRepeat){
		seq=CCRepeatForever::create(CCSequence::create(seqArray));

	}else{
		if(isReturn){
			CCFiniteTimeAction *call = CCCallFunc::create(this,callfunc_selector(ActionManager::idle));
			seqArray->addObject(call);
		}
	
		seq=CCSequence::create(seqArray);
	}

	return seq;


}

void ActionManager::setCharFlip(){

	if (_isFlipped){
		this->setFlipX(false);
		_isFlipped=false;
	}else{
		this->setFlipX(true);
		_isFlipped=true;

	}
}

void ActionManager::setShadow(CCNode* sender,void* date){

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCDictionary* file=(CCDictionary*) date;
	CCSpriteFrame *frame  = (CCSpriteFrame *)(file->objectForKey(1));
	CCSprite* charN=CCSprite::createWithSpriteFrame(frame);
	charN->setVisible(false);
	if(strcmp(this->_group->getCString(),"Konoha")==0){
		charN->setColor(ccGREEN);
	}else{
		charN->setColor(ccRED);
	}
	
	charN->setOpacity(180);
	charN->setAnchorPoint(ccp(0.5,0));
	charN->setFlipX(_isFlipped);
	charN->setPosition(this->getPosition());
	CCDelayTime* delay=CCDelayTime::create(0.1f);
	CCFiniteTimeAction *call = CCCallFuncN::create(charN,callfuncN_selector(ActionManager::enableShadow));
	charN->runAction(CCSequence::createWithTwoActions(delay,call));
	_delegate->addChild(charN,-this->getPositionY()-1);
}

void ActionManager::enableShadow(CCNode* sender){

	CCSprite* charN=(CCSprite *) sender;
	charN->setVisible(true);
	CCDelayTime* delay=CCDelayTime::create(0.1f);
	CCFiniteTimeAction *call = CCCallFuncN::create(charN,callfuncN_selector(ActionManager::disableShadow));
	charN->runAction(CCSequence::createWithTwoActions(delay,call));

}

void ActionManager::disableShadow(CCNode* sender){

	CCSprite* charN=(CCSprite *) sender;
	charN->stopAllActions();
	charN->removeFromParentAndCleanup(true);

}


void ActionManager::setOugis(CCNode* sender){
		_delegate->setOugis(this);
}

CCRect ActionManager::setHalfBox(){
	CCRect halfbox =CCRectMake(_isFlipped?this->getPositionX()- this->getContentSize().width/2:this->getPositionX(),
		this->getPositionY()+this->getContentSize().height/2,
		this->getContentSize().width/2,
		this->getContentSize().height/2);
	return  halfbox;
};

CCRect ActionManager::setHitBox(){
	CCRect hitbox=this->boundingBox();
	return hitbox;
};

void ActionManager::disableHpBar(float dt){
	if(_hpBar){
		_hpBar->setVisible(false);
	}
	
}

void ActionManager::setDamage(CCString* effectType,unsigned int attackValue,bool isFlipped){
	
	if(strcmp(_role->getCString(),"Tower")==0){
		if(_hpBar){
		_hpBar->setVisible(true);
		}
		
		this->unschedule(schedule_selector(ActionManager::disableHpBar));
		this->scheduleOnce(schedule_selector(ActionManager::disableHpBar),2.0f);
	};

	

	
	int criticalValue;
	unsigned int realValue;


	ActionManager* attacker=(ActionManager*) _slayer;
	ActionManager* currentAttacker;
	if(attacker->getMaster()){
		currentAttacker=attacker->getMaster();
	}else{
		currentAttacker=attacker;
	}

	if(attacker->isGearCD || (attacker->_master && attacker->_master->isGearCD )){
		criticalValue=rand()%60+10;
	}else{
		criticalValue=rand()%50;
	}

	//飞段自残
	if(strcmp(attacker->getCharacter()->getCString(),"Hidan")==0 && attacker->_skillChangeBuffValue){
		realValue=attackValue+criticalValue;
	}else{

		bool isBizhong=false;
		if(strcmp(attacker->getCharacter()->getCString(),"Hiruzen")==0 && attacker->getActionState()==ACTION_STATE_O2ATTACK){
			isBizhong=true;
		}

		if(isBizhong){
			realValue=attackValue+criticalValue;
		}else if((attacker->getMaster() ||
			attacker->getActionState()==ACTION_STATE_ATTACK)
			&& attacker->isPofang){
			realValue=attackValue+criticalValue;
		}else{
			if(attackValue-_gardValue<=0){
				realValue=criticalValue;
			}else{
				
				realValue=attackValue-_gardValue+criticalValue;
				float jianshang=0;
				if(isHujia){
					jianshang+=0.25; 
				}

				if(strcmp(this->getCharacter()->getCString(),"Kakuzu")==0 && _skillChangeBuffValue){
					jianshang+=0.25; 
				}

				if(strcmp(this->_character->getCString(),"Chiyo")==0){
					CCObject* pObject;
					CCARRAY_FOREACH(this->getMonsterArray(),pObject){
						Monster* mo=(Monster*) pObject;
						if(strcmp(mo->getCharacter()->getCString(),"Parents")==0 && !mo->_skillChangeBuffValue && mo->getActionState()!=ACTION_STATE_SATTACK){
							CCPoint	sp=ccpSub(mo->getPosition(),this->getPosition());
							if(sp.x<=48){
								jianshang+=0.25;
							}
						}
					}

				}

				if(realValue-realValue*jianshang<0){
					realValue=0;
				}else{
					realValue-=realValue*jianshang;
				}
				
			}

		}
		
	}

	if (atoi(_hp->getCString())-realValue<0){
		this->setHP(CCString::createWithFormat("%d",0));
	}else{
		this->setHP(CCString::createWithFormat("%d",atoi(this->getHP()->getCString())-realValue));
	}
	
	if(strcmp(this->getRole()->getCString(),"Clone")==0){

		
		int boundValue=0;
		if(strcmp(this->getCharacter()->getCString(),"Naruto")==0){
			boundValue=realValue*15/100;
		}else if(strcmp(this->getCharacter()->getCString(),"SageNaruto")==0){
			boundValue=realValue*25/100;
		}else if(strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0){
			boundValue=realValue*35/100;
		}
		
		//4v4
		if(Cheats>10){
			boundValue=boundValue/2;
		}
		
		if(currentAttacker->isAttackGainCKR){
			if(boundValue-boundValue*25/100>0){
				boundValue=boundValue-boundValue*25/100;
			}else{
				boundValue=0;
			}
		}

		if(_master){

			if(_master->getLV()>=2 && !_master->_isControled){
				if(45000-atof(_master->getCKR()->getCString())>=boundValue){
					float newValue=atof(_master->getCKR()->getCString())+boundValue;
					_master->setCKR(CCString::createWithFormat("%f",newValue));
				}else{
					_master->setCKR(CCString::create("45000"));
				}	

				if(atof(_master->getCKR()->getCString())>=15000){
					_master->_isCanOugis1=true;
					
				}

				if(strcmp(_master->getRole()->getCString(),"Player")==0){
					_delegate->setCKRLose(false);
				}
			}

			if(_master->getLV()>=4 && !_master->_isControled){

					if(50000-atof(_master->getCKR2()->getCString())>=boundValue){
						float newValue=atof(_master->getCKR2()->getCString())+boundValue;
						_master->setCKR2(CCString::createWithFormat("%f",newValue));
					}else{
						
						_master->setCKR2(CCString::create("50000"));
					}	

					if(atof(_master->getCKR2()->getCString())>=25000){
						_master->_isCanOugis2=true;
						
					}

					if(strcmp(_master->getRole()->getCString(),"Player")==0){
						_delegate->setCKRLose(true);
					}

			}

		}
		


	}else{
		int boundValue;
		
		if(_level==5){	
			boundValue=realValue+realValue*5/100;
		}else if(_level==6){
			boundValue=realValue+realValue*10/100;
		}else {
			boundValue=realValue;
		}
		
		boundValue+=realValue*gearCKRValue/100;

		//4v4
		if(Cheats>10){
			boundValue=boundValue/2;
		}

		if(currentAttacker->isAttackGainCKR){
			if(boundValue-boundValue*25/100>0){
				boundValue=boundValue-boundValue*25/100;
			}else{
				boundValue=0;
			}
		}
		
		bool isGainable=true;
		if(strcmp(this->getCharacter()->getCString(),"Tsunade")==0 && this->_skillChangeBuffValue ){
			isGainable=false;
		}
		if(strcmp(attacker->getCharacter()->getCString(),"Hinata")==0 &&  attacker->_skillUPBuffValue){
			isGainable=false;
		}

		if(_level>=2 && !_isControled && isGainable){
				if(45000-atof(this->getCKR()->getCString())>=boundValue){
					float newValue=atof(this->getCKR()->getCString())+boundValue;
					this->setCKR(CCString::createWithFormat("%f",newValue));
				}else{
					this->setCKR(CCString::create("45000"));
			
				}	

				if(atof(this->getCKR()->getCString())>=15000){
					_isCanOugis1=true;
				
				}

				if(strcmp(_role->getCString(),"Player")==0){
					_delegate->setCKRLose(false);
				}


			


		}

		if(_level>=4 && !_isControled && isGainable){

				if(50000-atof(this->getCKR2()->getCString())>=boundValue){
					float newValue=atof(this->getCKR2()->getCString())+boundValue;
					this->setCKR2(CCString::createWithFormat("%f",newValue));

				}else{
					this->setCKR2(CCString::create("50000"));
					
					
				}	

				if(atof(this->getCKR2()->getCString())>=25000){
					_isCanOugis2=true;
					
				}

				if(strcmp(_role->getCString(),"Player")==0){
					_delegate->setCKRLose(true);
				}

		}

	}
	//忍具查克拉攻击获取



	if(strcmp(_role->getCString(),"Player")==0 || strcmp(_role->getCString(),"Com")==0){
			float gainValue=0;

			if(strcmp(attacker->getCharacter()->getCString(),"Kisame")==0 && attacker->_skillChangeBuffValue){
				if(currentAttacker->isAttackGainCKR){
					gainValue=realValue*80/100;
				}else{
					gainValue=realValue*65/100;
				}			
			}else if(currentAttacker->isAttackGainCKR){
				gainValue=realValue*15/100;
			}

			if(gainValue!=0){

			
				if(currentAttacker->_level>=2 && !currentAttacker->_isControled){

					if(45000-atof(currentAttacker->getCKR()->getCString())>=gainValue){
						float newValue=atof(currentAttacker->getCKR()->getCString())+gainValue;
						currentAttacker->setCKR(CCString::createWithFormat("%f",newValue));

					}else{
						currentAttacker->setCKR(CCString::create("45000"));
					}	

					if(atof(currentAttacker->getCKR()->getCString())>=15000){
						currentAttacker->_isCanOugis1=true;

					}

					if(strcmp(currentAttacker->getRole()->getCString(),"Player")==0){
						_delegate->setCKRLose(false);
					}
				}

				if(currentAttacker->_level>=4 && !currentAttacker->_isControled){

					if(50000-atof(currentAttacker->getCKR2()->getCString())>=gainValue){
						float newValue=atof(currentAttacker->getCKR2()->getCString())+gainValue;
						currentAttacker->setCKR2(CCString::createWithFormat("%f",newValue));

					}else{
						currentAttacker->setCKR2(CCString::create("50000"));

					}	

					if(atof(currentAttacker->getCKR2()->getCString())>=25000){
						currentAttacker->_isCanOugis2=true;

					}

					if(strcmp(currentAttacker->getRole()->getCString(),"Player")==0){
						_delegate->setCKRLose(true);
					}

				}
			}
		
			

	}
	
	


	if(strcmp(_role->getCString(),"Player")==0 || ( strcmp(_role->getCString(),"Tower")!=0 &&
		abs(ccpSub(this->getPosition(),_delegate->currentPlayer->getPosition()).x)<winSize.width/2)
		){

			
			//create damage value display

			bool _isDisplay=false;

			if(strcmp(attacker->_role->getCString(),"Player")==0 || strcmp(_role->getCString(),"Player")==0){
				_isDisplay=true;
			}
			if(attacker->getMaster()){
				if(strcmp(attacker->getMaster()->_role->getCString(),"Player")==0 )
					_isDisplay=true;
			}



			if(_isDisplay){

				if(criticalValue<=20){
					this->setDamgeDisplay(realValue,"white");
				}else if(criticalValue<=40){
					this->setDamgeDisplay(realValue,"yellow");
				}else{
					this->setDamgeDisplay(realValue,"red");
				} 

			}

			//create damage effect

			if(strcmp(this->_role->getCString(),"Flog")==0 && strcmp(attacker->_role->getCString(),"Flog")!=0 ){
				if(strcmp(effectType->getCString(),"a_hit")==0){
					this->setDamgeEffect(CCString::create("a_hit"));
				}
			}else if(strcmp(attacker->_role->getCString(),"Flog")!=0){
				this->setDamgeEffect(effectType);
			}



	}
	

}

void ActionManager::setCoinDisplay(int num){
	CCSprite* coinDisplay=CCSprite::create();

	CCSprite* coinSprite=CCSprite::createWithSpriteFrameName("coin.png");
	coinSprite->setPosition(ccp(14,0));
	coinDisplay->addChild(coinSprite);

	CCString* label=CCString::createWithFormat("+%d",num);
	CCLabelBMFont* rewardLabel=CCLabelBMFont::create(label->getCString(),"Fonts/yellow.fnt");
	rewardLabel->setPosition(ccp(0,0));
	rewardLabel->setScale(0.3f);
	coinDisplay->addChild(rewardLabel);

	coinDisplay->setPosition(ccp(this->getPositionX(),this->getPositionY()+this->getContentSize().height/2));
	_delegate->addChild(coinDisplay,5000);
	
	CCActionInterval*  mv=CCMoveBy::create(0.5f,ccp(0,12));
	CCActionInterval* fadeOut=CCFadeOut::create(0.8f);
	CCFiniteTimeAction *call=CCCallFuncND::create(coinDisplay,callfuncND_selector(ActionManager::removeCoinDisplay),NULL);
	CCActionInterval* sp=CCSpawn::create(fadeOut,mv,NULL);
	CCArray* seqArray=CCArray::create();
	seqArray->addObject(sp);
	seqArray->addObject(call);
	CCAction* seq=CCSequence::create(seqArray);
	coinDisplay->runAction(seq);

}

void ActionManager::removeCoinDisplay(CCNode* sender,void* date){
	sender->removeFromParent();
	sender=NULL;
}




void ActionManager::setDamgeDisplay(unsigned int value,const char* type){

	if(_damageArray->count()<6 ){

	CCLabelBMFont* damageFont=CCLabelBMFont::create(CCString::createWithFormat("%d",value)->getCString(),
		CCString::createWithFormat("Fonts/%s.fnt",type)->getCString());
	damageFont->setAnchorPoint(ccp(0.5,0.5));
	
	if(strcmp(this->_role->getCString(),"Flog")==0){
		damageFont->setScale(0.6f);
		damageFont->setPosition(ccp(this->getPositionX()+rand()%16,this->getPositionY()+this->getHeight()+rand()%4));
	}else {
		damageFont->setScale(0.8f);
		damageFont->setPosition(ccp(this->getPositionX()+rand()%16,this->getPositionY()+this->getHeight()+rand()%16));
	}
	
	_delegate->addChild(damageFont,currentNumberTag);	
	_damageArray->addObject(damageFont);

	CCActionInterval*  sd=CCScaleBy::create(0.2f,0.5f);
	CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(ActionManager::removeDamageDisplay));

	CCActionInterval*  mv=CCMoveBy::create(0.4f,ccp(0,12));
	CCActionInterval* fadeOut=CCFadeOut::create(0.4f);
	CCActionInterval* sp=CCSpawn::create(fadeOut,mv,NULL);

	CCArray* seqArray=CCArray::create();
	seqArray->addObject(sd);
	seqArray->addObject(sp);
	seqArray->addObject(call);


	CCAction* seq=CCSequence::create(seqArray);

	damageFont->runAction(seq);

	}

};


void ActionManager::removeDamageDisplay(){
	if(_damageArray && _damageArray->count()>0){
		CCObject* pObject=_damageArray->objectAtIndex(0);
		CCLabelBMFont* damageFont=(CCLabelBMFont*)pObject;
		damageFont->removeFromParent();
		_damageArray->removeObjectAtIndex(0);
		damageFont=NULL;
	}
	
}

void ActionManager::setDamgeEffect(CCString* type){
	CCString* str=type;
	if(strcmp(_role->getCString(),"Player")==0 || abs(ccpSub(this->getPosition(),_delegate->currentPlayer->getPosition()).x)<winSize.width/2){

			if (damageEffectCount<2){

				if(strcmp(_role->getCString(),"Flog")!=0){

					Effect* ef=Effect::create(str->getCString(),this);
					_delegate->damageEffectBatch->addChild(ef,5000);

				}else{
					Effect* ef=Effect::create(str->getCString(),this);
					_delegate->damageEffectBatch->addChild(ef);
				}

				damageEffectCount++;

			}
		
	}

}

void ActionManager::setSkillEffect(CCNode* sender,void* date){

	CCDictionary* file=(CCDictionary*) date;
	CCString* str = (CCString*)(file->objectForKey(1));

	if(strcmp(_role->getCString(),"Player")==0 || 
		abs(ccpSub(this->getPosition(),_delegate->currentPlayer->getPosition()).x)<winSize.width/2){

			Effect* ef=Effect::create(str->getCString(),this);
			if(strcmp(str->getCString(),"Bagua")==0 ||
				strcmp(str->getCString(),"Kujiyose")==0 
				){
				_delegate->addChild(ef,-500);
			}else if(strcmp(str->getCString(),"DarkFlame")==0){
				_delegate->addChild(ef,-ef->getPositionY());
			}else{
				_delegate->skillEffectBatch->addChild(ef);
			}

	}
};



void ActionManager::setItem(abType type){

	if(_isControled){
		return;
	}

	if((strcmp(this->getCharacter()->getCString(),"Kankuro")==0 || 
		strcmp(this->getCharacter()->getCString(),"Chiyo")==0 || 
		strcmp(this->getCharacter()->getCString(),"Kiba")==0 || 
		strcmp(this->getCharacter()->getCString(),"Kakuzu")==0
		) && this->getMonsterArray() && getMonsterArray()->count()>0){
		CCObject* pObject;
		CCARRAY_FOREACH(this->getMonsterArray(),pObject){
			Monster* mo=(Monster*) pObject;
			if(strcmp(mo->getCharacter()->getCString(),"Traps")!=0){
				mo->setItem(Item1);
			}
			
		};
	}
	_isCanItem1=false;
	if(strcmp(this->getRole()->getCString(),"Player")==0 ){
		if(this->_isAI){
			_delegate->getHudLayer()->offCoin(CCString::createWithFormat("%d",50)->getCString());

		}
		
	}else{
		this->minusCoin(50);
		
	}
	this->scheduleOnce(schedule_selector(Hero::enableItem1),5.0f);

	

	if(_hpBar){
		
		int hpRestore=3000+gearRecoverValue;
		if(atoi(_maxHP->getCString())-atoi(_hp->getCString())<=hpRestore){
			this->setHP(CCString::create(this->getMaxHP()->getCString()));
			if(_hpBar){
				_hpBar->loseHP(this->getHpPercent());
			}
			
		}else{
			this->setHP(CCString::createWithFormat("%d",atoi(_hp->getCString())+hpRestore)) ;
			if(_hpBar){
			_hpBar->loseHP(this->getHpPercent());
			}
		}

		if(!_isHealling && !_healItemEffect){
			_healItemEffect=Effect::create("hp_restore",this);
			_healItemEffect->setPosition(ccp(_isFlipped?this->getContentSize().width/2+16:this->getContentSize().width/2-16,
				this->_height));
			this->addChild(_healItemEffect);
			//_isHealling=true;
		}
	}

}

bool ActionManager::setGear(gearType type){

	int gearCost=0;
	if(type==gear00 || type==gear03 || type==gear06){
		gearCost=500;
	}else{
		gearCost=1000;
	}
	
	if( this->getGearArray()->count()<=2 && atoi(this->getCoin()->getCString())>=gearCost){
		CCString* gearItem=CCString::createWithFormat("%d",gearType(type));
		this->getGearArray()->addObject(gearItem);
		
		if(strcmp(this->getRole()->getCString(),"Player")==0){
			_delegate->getHudLayer()->offCoin(CCString::createWithFormat("%d",gearCost)->getCString());
		}else{
			this->minusCoin(gearCost);
		}

		switch (type){
		case gear00:
			this->_isCanGear00=true;
			break;
		case gear01:
			this->gearCKRValue=25;
			break;
		case gear02:
			this->isAttackGainCKR=true;
			break;
		case gear03:
			this->_isCanGear03=true;
			break;
		case gear04:

			if(this->gettempAttackValue1()){
				this->settempAttackValue1(CCString::createWithFormat("%d",atoi(this->gettempAttackValue1()->getCString())+160));
			}
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())+160));
			this->isPofang=true;

			break;
		case gear05:

			
			this->isGearCD=true;
			
			this->_sattackcoldDown1-=5;
			this->_sattackcoldDown2-=5;
			this->_sattackcoldDown3-=5;

			if(strcmp(this->getRole()->getCString(),"Player")==0){
				this->_delegate->getHudLayer()->skill1Button->setCD(CCString::createWithFormat("%d",this->_sattackcoldDown1*1000));
				this->_delegate->getHudLayer()->skill2Button->setCD(CCString::createWithFormat("%d",this->_sattackcoldDown2*1000));
				this->_delegate->getHudLayer()->skill3Button->setCD(CCString::createWithFormat("%d",this->_sattackcoldDown3*1000));
				
				this->_delegate->getHudLayer()->skill1Button->_isColdChanged=true;
				this->_delegate->getHudLayer()->skill2Button->_isColdChanged=true;
				this->_delegate->getHudLayer()->skill3Button->_isColdChanged=true;
			}
				
			break;
		case gear06:
			this->_isCanGear06=true;
			break;
		case gear07:
			gearRecoverValue=3000;
			this->_delegate->getHudLayer()->item1Button->setCD(CCString::createWithFormat("%d",3000));
			this->_delegate->getHudLayer()->item1Button->_isColdChanged=true;
			break;
		case gear08:
			int tempMaxHP=atoi(this->getMaxHP()->getCString());
			tempMaxHP+=6000;
			this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));
			if(_hpBar){
				_hpBar->loseHP(this->getHpPercent());
			}
			this->isHujia=true;

			break;
		}

		return true;

	}else{
		return false;
	}

}

void ActionManager::useGear(gearType type){

	if(_isControled){
		return;
	}

	if(type==gear00){
		if(this->getActionState()==ACTION_STATE_ATTACK ||
			this->getActionState()==ACTION_STATE_WALK ||
			this->getActionState()==ACTION_STATE_IDLE
			){
				if(this->getWalkSpeed()==224){
					this->setWalkSpeed(320);


					_isCanGear00=false;

					_speedItemEffect=Effect::create("speedUp",this);
					this->addChild(_speedItemEffect);

					this->scheduleOnce(schedule_selector(ActionManager::enableGear00),15.0f);

					//隐身
					if(strcmp(_role->getCString(),"Player")==0 || strcmp(this->getGroup()->getCString(),_delegate->currentPlayer->getGroup()->getCString())==0){
						this->setOpacity(150);
					}else{
						this->setVisible(false);
					}
					if(_hpBar){
						_hpBar->setVisible(false);
					}
					if(_shadow){
						_shadow->setVisible(false);
					}
					this->_isVisable=false;

					CCDictionary* callValue2 = CCDictionary::create(); 
					callValue2->setObject(CCString::create("Audio/Effect/suzou_effect.mp3"),1);
					this->setSound(this,callValue2);


					this->schedule(schedule_selector(ActionManager::disableGear1),3.0f);

				}
		}
		

	}else if(type==gear03){
		_isCanGear03=false;

		CCDictionary* tmpValue = CCDictionary::create(); 
		tmpValue->setObject(CCString::create("Traps"), 1);
		this->setMon(this,(void*)tmpValue);
	

		this->scheduleOnce(schedule_selector(ActionManager::enableGear03),15.0f);
	}else if(type==gear06){
		_isCanGear06=false;
		this->scheduleOnce(schedule_selector(ActionManager::enableGear06),15.0f);

		
		if(!_isWudi && !_isBati){

			if(this->getActionState()==ACTION_STATE_IDLE || 
				this->getActionState()==ACTION_STATE_WALK ||
				this->getActionState()==ACTION_STATE_FLOAT||
				this->getActionState()==ACTION_STATE_AIRHURT ||
				this->getActionState()==ACTION_STATE_HURT ||
				this->getActionState()==ACTION_STATE_KOCKDOWN
				){

					if(this->_isSticking){
						this->_isSticking=false;
					}
					if(this->getActionState()==ACTION_STATE_FLOAT ||
						this->getActionState()==ACTION_STATE_AIRHURT){
							this->setPositionY(_originY);
							_originY=NULL;
							_delegate->reorderChild(this,-this->getPositionY());
					}

					this->idle();

					CCDictionary* callValue = CCDictionary::create(); 
					callValue->setObject(CCString::create("tishen"), 1);
					this->setSkillEffect(this,callValue);
					this->scheduleOnce(schedule_selector(ActionManager::disableGear2),1.0f);


					
					CCDictionary* callValue2 = CCDictionary::create(); 
					callValue2->setObject(CCString::create("Audio/Effect/poof2.mp3"),1);
					this->setSound(this,callValue2);


					if(strcmp(_role->getCString(),"Player")==0 || strcmp(this->getGroup()->getCString(),_delegate->currentPlayer->getGroup()->getCString())==0){
						this->setOpacity(150);
					}else{
						this->setVisible(false);
					}
					if(_hpBar){
						_hpBar->setVisible(false);
					}
					if(_shadow){
						_shadow->setVisible(false);
					}

					this->_isVisable=false;
			}

	
		}
		

	}
}

void ActionManager::disableGear1(float dt){

	if(!_isVisable && this->_actionState!=ACTION_STATE_HURT){ 

		this->setOpacity(255);
		this->setVisible(true);

		if(_hpBar){
			_hpBar->setVisible(true);
		}
		if(_shadow){
			_shadow->setVisible(true);
		}

		_isVisable=true;

	}else {
	
		this->unschedule(schedule_selector(ActionManager::disableGear1));	
		if(this->getWalkSpeed()==320){
			this->setWalkSpeed(224);
		}	
	}
	

}

void ActionManager::disableGear2(float dt){
	
	this->setOpacity(255);
	this->setVisible(true);
	

	if(_hpBar){
		_hpBar->setVisible(true);
	}

	if(_shadow){
		_shadow->setVisible(true);
	}

	_isVisable=true;
}


void ActionManager::disableGear3(float dt){


}

void ActionManager::enableGear00(float dt){
	_isCanGear00=true;

}

void ActionManager::enableGear03(float dt){
	_isCanGear03=true;
}
void ActionManager::enableGear06(float dt){
	_isCanGear06=true;
}



void ActionManager::addCoin(int num){
	this->setCoin(CCString::createWithFormat("%d",atoi(this->getCoin()->getCString())+num));
}

void ActionManager::minusCoin(int num){
	if( atoi(this->getCoin()->getCString()) > num){
		this->setCoin(CCString::createWithFormat("%d",atoi(this->getCoin()->getCString())-num));
	}else{
		this->setCoin(CCString::createWithFormat("%d",0));
	}
	
}

void ActionManager::setRestore(float dt){
	if(_hpBar){

		
		if(atoi(_maxHP->getCString())-atoi(_hp->getCString())<=800){
			this->setHP(CCString::create(this->getMaxHP()->getCString()));
			_hpBar->loseHP(this->getHpPercent());
		}else{
			this->setHP(CCString::createWithFormat("%d",atoi(_hp->getCString())+800));
			_hpBar->loseHP(this->getHpPercent());
		}

		_healItemEffect=Effect::create("hp_restore",this);
		_healItemEffect->setPosition(ccp(_isFlipped?this->getContentSize().width/2+16:this->getContentSize().width/2-16,
			this->_height));
		this->addChild(_healItemEffect);
	}


}

void ActionManager::setRestore2(float dt){
	
	if(_hpBar ){
		//八门耗血
		if(bamen>=8){
			if(atoi(_hp->getCString())-1000>0){
				this->setHP(CCString::createWithFormat("%d",atoi(_hp->getCString())-1000));
				_hpBar->loseHP(this->getHpPercent());
			}else{
				this->setHP(CCString::createWithFormat("%d",100));
				_hpBar->loseHP(this->getHpPercent());
			}
		}else if(bamen>=5){
			if(atoi(_hp->getCString())-200>0){
				this->setHP(CCString::createWithFormat("%d",atoi(_hp->getCString())-200));
				_hpBar->loseHP(this->getHpPercent());
			}else{
				this->setHP(CCString::createWithFormat("%d",100));
				_hpBar->loseHP(this->getHpPercent());
			}
		}else if(bamen>=4){
			if(atoi(_hp->getCString())-150>0){
				this->setHP(CCString::createWithFormat("%d",atoi(_hp->getCString())-150));
				_hpBar->loseHP(this->getHpPercent());
			}else{
				this->setHP(CCString::createWithFormat("%d",100));
				_hpBar->loseHP(this->getHpPercent());
			}
		}else if(bamen>=3){
			if(atoi(_hp->getCString())-100>0){
				this->setHP(CCString::createWithFormat("%d",atoi(_hp->getCString())-100));
				_hpBar->loseHP(this->getHpPercent());
			}else{
				this->setHP(CCString::createWithFormat("%d",100));
				_hpBar->loseHP(this->getHpPercent());
			}
		}

		
		bool isZone=false;
		if(strcmp("Akatsuki",_group->getCString())==0 && this->getPositionX()<=_delegate->currentMap->getTileSize().width*2 ){
			isZone=true;
		}else if (strcmp("Konoha",_group->getCString())==0 && this->getPositionX() >=(_delegate->currentMap->getMapSize().width-2)*_delegate->currentMap->getTileSize().width){
			isZone=true;
		}
		if(isZone){

			if(atoi(_hp->getCString())-1000>0){
				this->setHP(CCString::createWithFormat("%d",atoi(_hp->getCString())-1000));
				_hpBar->loseHP(this->getHpPercent());
			}else{
				this->setHP(CCString::createWithFormat("%d",100));
				_hpBar->loseHP(this->getHpPercent());
			}

		}


		if(this->getActionState()==ACTION_STATE_IDLE && this->getHpPercent()<1){
			if(atoi(_maxHP->getCString())-atoi(_hp->getCString())<=300){
				this->setHP(CCString::create(this->getMaxHP()->getCString()));
				_hpBar->loseHP(this->getHpPercent());
			}else{
				this->setHP(CCString::createWithFormat("%d",atoi(_hp->getCString())+300));
				_hpBar->loseHP(this->getHpPercent());
			}

		}
		

	}


}

void ActionManager::disableEffect(){
	if(_healItemEffect){
		_healItemEffect->removeFromParentAndCleanup(true);
		_healItemEffect=NULL;
	}

	if(_speedItemEffect){
		_speedItemEffect->removeFromParentAndCleanup(true);
		_speedItemEffect=NULL;
	}

	
}

void ActionManager::setSound(CCNode* sender,void* date){

	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isVoice")!=false){
		bool _isPlayable=false;
		if(strcmp(_role->getCString(),"Player")==0 || 
			abs(ccpSub(this->getPosition(),_delegate->currentPlayer->getPosition()).x)<winSize.width/2 
			){
				_isPlayable=true;
		}
		if(_delegate->controlChar){
			if(abs(ccpSub(this->getPosition(),_delegate->controlChar->getPosition()).x)<winSize.width/2 ){

			_isPlayable=true;
			}
		}

		if(_isPlayable){
				CCDictionary* file=(CCDictionary*) date;
				CCString* str = (CCString*)(file->objectForKey(1));
				//SimpleAudioEngine::sharedEngine()->preloadEffect(str->getCString());
				SimpleAudioEngine::sharedEngine()->playEffect(str->getCString());
		}
	}
};

void ActionManager::setDSound(CCNode* sender,void* date){

	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isVoice")!=false){
		bool _isPlayable=false;
		if(strcmp(_role->getCString(),"Player")==0 || 
			abs(ccpSub(this->getPosition(),_delegate->currentPlayer->getPosition()).x)<winSize.width/2 
			){
				_isPlayable=true;
		}
		if(_delegate->controlChar){
			if(abs(ccpSub(this->getPosition(),_delegate->controlChar->getPosition()).x)<winSize.width/2 ){
				_isPlayable=true;
			}
		}

		if(_isPlayable && this->_isHitOne){
			CCDictionary* file=(CCDictionary*) date;
			CCString* str = (CCString*)(file->objectForKey(1));
			//SimpleAudioEngine::sharedEngine()->preloadEffect(str->getCString());
			SimpleAudioEngine::sharedEngine()->playEffect(str->getCString());
		}
	}
};

void ActionManager::setAttackBox(CCNode* sender,void* date){
	CCDictionary* file=(CCDictionary*) date;
	CCString* str = (CCString*)(file->objectForKey(1));

	_effectType=str;

	//反伤

	if(_actionState==ACTION_STATE_HURT){

		if(strcmp(this->getCharacter()->getCString(),"Sasuke")==0 || 
			strcmp(this->getCharacter()->getCString(),"ImmortalSasuke")==0 || 
			strcmp(this->getCharacter()->getCString(),"DevaPath")==0 ){

				if(atoi(_maxHP->getCString())-atoi(_hp->getCString())<=260){
					this->setHP(CCString::create(this->getMaxHP()->getCString()));
					_hpBar->loseHP(this->getHpPercent());
				}else{
					this->setHP(CCString::createWithFormat("%d",atoi(_hp->getCString())+260));
					_hpBar->loseHP(this->getHpPercent());
				}

				if(_role && strcmp(_role->getCString(),"Player")==0){
					_delegate->setHPLose(this->getHpPercent());
				}

				_attackType=_spcattackType1;
				_attackValue=atoi(_spcattackValue1->getCString());
				_attackRangeX=_spcattackRangeX1;
				_attackRangeY=_spcattackRangeY1;

		}
	
	}
	

	CCNotificationCenter::sharedNotificationCenter()->postNotification("acceptAttack", this);

	if(strcmp(_role->getCString(),"Player")==0){

		if((_actionState==ACTION_STATE_OATTACK|| _actionState==ACTION_STATE_O2ATTACK ) && this->_isHitOne==true && !_delegate->_isShacking){
			_delegate->_isShacking=true;
			CCScene* f = CCDirector::sharedDirector()->getRunningScene();
			CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(ActionManager::disableShack));	
			f->runAction(CCSequence::createWithTwoActions(CCShake::create(0.05f,12),call));
		}
		if(_delegate->_isAttackButtonRelease && _actionState==ACTION_STATE_ATTACK && !_isOnlySkillLocked && !_isAI){
			this->idle();
			return;
		}
		
	}


};

void ActionManager::getSticker(float dt){

	CCObject* pObject;

	CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
		Hero* tempHero=(Hero*) pObject;
		ActionManager* tempSticker=NULL;
		if(tempHero->_sticker){
			tempSticker=(ActionManager*) tempHero->_sticker;
		}
		if( tempSticker && strcmp(tempSticker->getCharacter()->getCString(),this->getCharacter()->getCString())==0
			&& tempHero->_isSticking
			){
				return;
		}
	};

	this->unschedule(schedule_selector(ActionManager::getSticker));	
	this->dealloc();
	
}

void ActionManager::disableShack(){
	_delegate->_isShacking=false;
	if(strcmp(this->getRole()->getCString(),"Tower")==0){
		this->_isHitOne=false;
	}
}


void ActionManager::setMove(CCNode* sender,void* date){

	int moveLength;

	if(this->getKnockLength()){
		if(this->getKnockLength()==1){
			return;
		} 
		moveLength=this->getKnockLength();
	}else{
		moveLength=(int) date;
	}

	if( this->getPositionX()>_delegate->currentMap->getTileSize().width &&
		this->getPositionX()<(_delegate->currentMap->getMapSize().width-1)*_delegate->currentMap->getTileSize().width
		){

			CCActionInterval* mv;
			if(this->_actionState==ACTION_STATE_HURT) {
				if(!_knockDiretion){
					mv =CCMoveBy::create(0.1f,ccp(_hurtFromRight?-moveLength:moveLength,0));
				}else{
					
					mv =CCMoveBy::create(0.1f,ccp(_knockDiretion?-moveLength:moveLength,0));
				}
				this->runAction(mv);
			}else{
				mv=CCMoveBy::create(0.1f,ccp(_isFlipped?-moveLength:moveLength,0));
				this->runAction(mv);
			};
	}
	
};

void ActionManager::setJump(CCNode* sender,void* date){

	if(
		_actionState!=ACTION_STATE_FLOAT && 
		_actionState!=ACTION_STATE_AIRHURT &&
		_actionState!=ACTION_STATE_HURT && 
		_actionState!=ACTION_STATE_DEAD 
		){
		
			_actionState=ACTION_STATE_JUMP;

			bool jumpDirection=(bool) date;
			float posX=this->getPositionX();
			float posY=this->getPositionY();
			_originY=posY;
			
			if(!jumpDirection){
				_jumpUPAction=CCJumpTo::create(0.8f, ccp(posX+(_isFlipped?64:-64),posY),64,1);
			}else{
				_jumpUPAction=CCJumpTo::create(0.8f, ccp(posX+(_isFlipped?-64:64),posY),64,1);
			}
			
			this->runAction(_jumpUPAction);

			

	}
}


void ActionManager::setCharge(CCNode* sender,void* date){
	int moveLength=(int) date;
	if( (this->getPositionX()<_delegate->currentMap->getTileSize().width && _isFlipped) ||
		(this->getPositionX()>(_delegate->currentMap->getMapSize().width-1)*_delegate->currentMap->getTileSize().width && !_isFlipped)
		){
			return;
	}else{
		_moveAction=CCMoveBy::create(0.1f,ccp(_isFlipped?-moveLength*winSize.width/1280:moveLength*winSize.width/1280,0));
		this->runAction(_moveAction);
		
	}

};

// with out getCollider
void ActionManager::setChargeB(CCNode* sender,void* date){
	int moveLength=(int) date;
	float delay;
	if(_actionState==ACTION_STATE_OATTACK || _actionState==ACTION_STATE_O2ATTACK){
		delay=0.4f;
	}else{
		delay=0.1f;
	}


	if( (this->getPositionX()<_delegate->currentMap->getTileSize().width && _isFlipped) ||
		(this->getPositionX()>(_delegate->currentMap->getMapSize().width-1)*_delegate->currentMap->getTileSize().width && !_isFlipped)
		){
		return;
	}else{
			_moveAction=CCMoveBy::create(delay,ccp(_isFlipped?-moveLength*winSize.width/1280:moveLength*winSize.width/1280,0));
			this->runAction(_moveAction);
	}

};

void ActionManager::setCommand(CCNode* sender,void* date){

	CCDictionary* file=(CCDictionary*) date;
	CCString* str = (CCString*)(file->objectForKey(1));
	CCString* commandType=str;

	if(strcmp(commandType->getCString(),"addHP")==0){
		if(_hpBar){
			this->setHP(CCString::create(this->getMaxHP()->getCString()));
			_hpBar->loseHP(this->getHpPercent());
			_hpBar->setPositionY(this->getHeight());
		}
	}else if(strcmp(commandType->getCString(),"setInvincible")==0){
		this->_isWudi=true;
	}else if(strcmp(commandType->getCString(),"setGainCKR")==0){
		int boundValue=1500;
		if(_level>=2){
			if(45000-atof(this->getCKR()->getCString())>=boundValue){
				float newValue=atof(this->getCKR()->getCString())+boundValue;
				this->setCKR(CCString::createWithFormat("%f",newValue));
			}else{
				this->setCKR(CCString::create("45000"));

			}	

			if(atof(this->getCKR()->getCString())>=15000){
				_isCanOugis1=true;

			}

			if(strcmp(_role->getCString(),"Player")==0){
				_delegate->setCKRLose(false);
			}


		}

		if(_level>=4 && !_isControled ){

			if(50000-atof(this->getCKR2()->getCString())>=boundValue){
				float newValue=atof(this->getCKR2()->getCString())+boundValue;
				this->setCKR2(CCString::createWithFormat("%f",newValue));

			}else{
				this->setCKR2(CCString::create("50000"));


			}	

			if(atof(this->getCKR2()->getCString())>=25000){
				_isCanOugis2=true;

			}

			if(strcmp(_role->getCString(),"Player")==0){
				_delegate->setCKRLose(true);
			}


		}
	}else if(strcmp(commandType->getCString(),"reInvincible")==0){
		this->_isWudi=false;
	}else if(strcmp(commandType->getCString(),"setInvisible")==0){
		this->setVisible(false);
		this->_isVisable=false;
	}else if(strcmp(commandType->getCString(),"reInvisible")==0){
		this->setVisible(true);
		_isVisable=true;
	}else if(strcmp(commandType->getCString(),"setTransport2")==0){
		CCObject* pObject;
		int tsPosX=this->getPositionX();
		int tsPosY=this->getPositionY();

	

		if(this->getMonsterArray()  && this->_actionState!=ACTION_STATE_ATTACK){
			CCARRAY_FOREACH(this->getMonsterArray(),pObject){

				Monster* mo=(Monster*) pObject;
				if(strcmp(mo->getCharacter()->getCString(),"HiraishinMark")==0){
					tsPosX=mo->getPositionX();
					tsPosY=mo->getPositionY();
					mo->attack(NAttack);
				}

			};
		}

		this->setPosition(ccp(tsPosX,tsPosY));
		CCNotificationCenter::sharedNotificationCenter()->postNotification("updateMap", this);
		
		_delegate->reorderChild(this,-tsPosY);


	}else if(strcmp(commandType->getCString(),"setTransport")==0){
		CCObject* pObject;
		int tsPosX=this->getPositionX();
		int tsPosY=this->getPositionY();

		if(_mainTarget){

			if(_mainTarget->_isFlipped){
				this->setFlipX(true);
				this->_isFlipped=true;
			}else{
				this->setFlipX(false);
				this->_isFlipped=false;
			}
		}
		

		if(strcmp(this->getCharacter()->getCString(),"Sakura")==0){
			float posY=this->getPositionY();
			if(!_originY){
				if(posY==0){
					posY=0.1f;
				}
				_originY=posY;
			}
			this->setPosition(ccp(this->getPositionX(),this->getPositionY()+64));
			return;
		}else{
			if(_markPoint.x!=0){
			_startPoint=ccp(tsPosX,tsPosY);
			tsPosX=_markPoint.x;
			tsPosY=_markPoint.y;
			_markPoint=ccp(0,0);
			}else if(_startPoint.x!=0){
				tsPosX=_startPoint.x;
				tsPosY=_startPoint.y;
				_startPoint=ccp(0,0);
			}
		}

		this->setPosition(ccp(tsPosX,tsPosY));
		CCNotificationCenter::sharedNotificationCenter()->postNotification("updateMap", this);

		if(strcmp(this->getCharacter()->getCString(),"Yominuma")!=0){
			_delegate->reorderChild(this,-tsPosY);
		}
		
	}
	else if(strcmp(commandType->getCString(),"reTransport")==0){
		this->setPosition(ccp(this->getPositionX(),_originY));
		_originY=NULL;
	}else if(strcmp(commandType->getCString(),"setDead")==0){
		this->_isSuicide=true;
		this->dead();
	}else if(strcmp(commandType->getCString(),"findTarget")==0){

		if(!this->findEnemy("Hero",NULL)){
			if(!this->findEnemy("Flog",NULL) || strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 ||
				strcmp(this->getCharacter()->getCString(),"SageNaruto")==0
				){
					_mainTarget=NULL;
			}
		};
		

		if(_mainTarget){
			if(strcmp(this->getCharacter()->getCString(),"Dogs")==0 ||
				strcmp(this->getCharacter()->getCString(),"Yominuma")==0 ||
				strcmp(this->getCharacter()->getCString(),"SandBall")==0 ||	
				strcmp(this->getCharacter()->getCString(),"Sabaku")==0 ||
				strcmp(this->getCharacter()->getCString(),"Yataikuzu")==0 ||
					strcmp(this->getCharacter()->getCString(),"Lee")==0 ||
					strcmp(this->getCharacter()->getCString(),"RockLee")==0
				){
				_markPoint=ccp(_mainTarget->getPositionX(),_mainTarget->_originY?_mainTarget->_originY:_mainTarget->getPositionY());
			}else if(strcmp(this->getCharacter()->getCString(),"Tsukuyomi")==0 ){
				_markPoint=ccp(_mainTarget->getPositionX(),_mainTarget->_originY?_mainTarget->_originY:_mainTarget->getPositionY()+2);
			}else if(strcmp(this->getCharacter()->getCString(),"KageFeng")==0){
				
				_markPoint=ccp(_mainTarget->getPositionX(),_mainTarget->_originY?_mainTarget->_originY-6:_mainTarget->getPositionY()-6);

			}else{
				_markPoint=ccp(_mainTarget->_isFlipped?_mainTarget->getPositionX()+32:_mainTarget->getPositionX()-32,
					_mainTarget->_originY?_mainTarget->_originY:_mainTarget->getPositionY());
			}
	
		}

	}else if(strcmp(commandType->getCString(),"setRevive")==0){

		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			Hero* tempHero=(Hero*) pObject;
			if(strcmp(this->_group->getCString(),tempHero->_group->getCString())==0
				&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
				&& tempHero->_actionState==ACTION_STATE_DEAD
				&&  tempHero->rebornSprite
				){
					tempHero->unschedule(schedule_selector(Hero::reborn));
					tempHero->reborn(0.1f);

			}
		};
	}else if(strcmp(commandType->getCString(),"setTrade")==0){

		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			Hero* tempHero=(Hero*) pObject;
			if((strcmp(tempHero->_role->getCString(),"Player")==0 || 
				strcmp(tempHero->_role->getCString(),"Com")==0)
				&& tempHero->_actionState==ACTION_STATE_DEAD
				&&  tempHero->rebornSprite
				&& tempHero->hearts>0
				&& strcmp(tempHero->_character->getCString(),"Kakuzu")!=0 
				){
				
					CCPoint sp=ccpSub(tempHero->getPosition(),this->getPosition());
					if(abs(sp.x)<=48 && abs(sp.y)<=48){
						tempHero->hearts-=1;
						if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0){
						
							int tempMaxHP=atoi(this->getMaxHP()->getCString());
							tempMaxHP+=100;
							this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())+5));
							this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));

							if(_hpBar){
								_hpBar->loseHP(this->getHpPercent());
							}
						}
				

						if (strcmp(this->getRole()->getCString(),"Player")==0){
							if(_delegate->_isHardCoreGame){
								this->getDelegate()->setCoin(CCString::createWithFormat("%d",50+(tempHero->getLV()-1)*10)->getCString());
								this->setCoinDisplay(50+(tempHero->getLV()-1)*10);
								this->addCoin(50+(tempHero->getLV()-1)*10);
							}else{
								this->getDelegate()->setCoin("50");
								this->setCoinDisplay(50);
								this->addCoin(50);
							}
						}
						
					}


			}
		};


	}else if(strcmp(commandType->getCString(),"addExtern")==0){

		CCArray* tempArray= CCArray::create();

		int i=1;
		if(strcmp(this->getCharacter()->getCString(),"Tenten")==0){
			while (i<11)
			{
				CCString* path=CCString::createWithFormat("Tenten_Extern_0%d.png",i);
				CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(path->getCString());
				tempArray->addObject(frame);
				i+=1;
			}
		}
		


		CCAnimation* tempAnimation= CCAnimation::createWithSpriteFrames(tempArray, 0.1f);
		CCFiniteTimeAction *call = CCCallFuncN::create(this,callfuncN_selector(ActionManager::disableShadow));
		CCAction* tempAction=CCAnimate::create(tempAnimation);
		CCArray* list=CCArray::create();
		list->addObject(tempAction);
		list->addObject(call);
		CCAction* seq=CCSequence::create(list);

		CCSprite* tempChar=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_Extern_01.png",this->getCharacter()->getCString())->getCString());

		tempChar->setAnchorPoint(ccp(0.5f,0));
		tempChar->setPosition(this->getPosition());
		this->_delegate->addChild(tempChar,-this->_originY);
		
		tempChar->runAction(seq);


	}else if(strcmp(commandType->getCString(),"pauseJump")==0){
		this->getActionManager()->addAction(_jumpUPAction,this,false);
	}else if(strcmp(commandType->getCString(),"setCounter")==0){

		bool _isCounter=false;
		if(_monsterArray && _monsterArray->count()>0){
			CCObject* pObject;
			CCARRAY_FOREACH(this->_monsterArray,pObject){
				ActionManager* tempMonster=(ActionManager*) pObject;
				float distanceX=ccpSub(tempMonster->getPosition(),this->getPosition()).x;
				float distanceY=ccpSub(tempMonster->getPosition(),this->getPosition()).y;
				if(abs(distanceX)<40 && abs(distanceY)<15){
					_isCounter=true;
				}
			}
		}

		if(_isCounter){
			CCObject* pObject;
			CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
				Hero* tempHero=(Hero*) pObject;
				if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
					&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
					&& tempHero->_actionState!=ACTION_STATE_DEAD	
					){
						if(tempHero->_hpBar){

							tempHero->_slayer=this;
							if(atoi(tempHero->_hp->getCString())<=2000){		
								tempHero->setDamage(CCString::create("c_hit"),atoi(tempHero->_hp->getCString()),false);

							}else{
								tempHero->setDamage(CCString::create("c_hit"),2000,false);

							};

							tempHero->_hpBar->loseHP(tempHero->getHpPercent());

							if(strcmp(tempHero->_role->getCString(),"Player")==0){
								_delegate->setHPLose(tempHero->getHpPercent());
							}


						}

				}
			}
		}else{
			if(this->_hpBar){
				_slayer=this;
				if(atoi(this->_hp->getCString())<=2000){		
					this->setDamage(CCString::create("c_hit"),atoi(this->_hp->getCString()),false);
				}else{
					this->setDamage(CCString::create("c_hit"),2000,false);
				};
				this->_hpBar->loseHP(this->getHpPercent());

				if(strcmp(this->_role->getCString(),"Player")==0){
					_delegate->setHPLose(this->getHpPercent());
				}

			}
		}

		this->setActionResume();
		
	}


}



void ActionManager::setBuff(CCNode* sender,void* date){
	int buffValue=(int) date;
	float buffStayTime=_attackRangeY;

	if(strcmp(_attackType->getCString(),"hBuff")==0){
		_healBuffValue=buffValue;
		this->schedule(schedule_selector(ActionManager::healBuff),1);
		this->setBuffEffect("hBuff");

	}else if(strcmp(_attackType->getCString(),"sBuff")==0 ||
		strcmp(_attackType->getCString(),"rsBuff")==0||
		strcmp(_attackType->getCString(),"hsBuff")==0 ||
		strcmp(_attackType->getCString(),"dcBuff")==0 
		){

		_skillUPBuffValue=buffValue;
		this->scheduleOnce(schedule_selector(ActionManager::disableBuff),buffStayTime);
		this->setBuffEffect(_attackType->getCString());
		
		this->setsAttackValue1(CCString::createWithFormat("%d",atoi(this->_sattackValue1->getCString())+_skillUPBuffValue));
		this->setsAttackValue2(CCString::createWithFormat("%d",atoi(this->_sattackValue2->getCString())+_skillUPBuffValue));
		this->setsAttackValue3(CCString::createWithFormat("%d",atoi(this->_sattackValue3->getCString())+_skillUPBuffValue));
		

		if(strcmp(_attackType->getCString(),"hsBuff")==0 ){
			CCObject* pObject;
			CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
				ActionManager* tempHero=(ActionManager*) pObject;
				if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
					&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
					&& tempHero->_actionState!=ACTION_STATE_HURT
					&& tempHero->_actionState!=ACTION_STATE_DEAD
					){
						float distanceX=ccpSub(tempHero->getPosition(),this->getPosition()).x;
						if(distanceX<winSize.width/2){
							//取消隐身
							if(!tempHero->_isVisable){
								if(strcmp(tempHero->getCharacter()->getCString(),"Konan")==0 ||
									strcmp(tempHero->getCharacter()->getCString(),"Deidara")==0
									){
										tempHero->unschedule(schedule_selector(ActionManager::disableBuff));
								}


								tempHero->setOpacity(255);
								tempHero->setVisible(true);

								if(tempHero->_hpBar){
									tempHero->_hpBar->setVisible(true);
								}
								if(tempHero->_shadow){
									tempHero->_shadow->setVisible(true);
								}

								tempHero->_isVisable=true;
							}

						}

				}
			};
			if(strcmp(this->getCharacter()->getCString(),"Neji")==0){
				_isBati=true;

			}
			
		}



	}else if(strcmp(_attackType->getCString(),"cBuff")==0){

		_skillChangeBuffValue=buffValue;
		

		if(strcmp(this->_character->getCString(),"Shino")==0 ||
			strcmp(this->_character->getCString(),"Sai")==0 ||
			strcmp(this->_character->getCString(),"Deidara")==0
			){

			if(_skillChangeBuffValue==17){
				this->scheduleOnce(schedule_selector(ActionManager::resumeAction),buffStayTime);
			}else if(_skillChangeBuffValue==18){
				this->unschedule(schedule_selector(ActionManager::resumeAction));
				this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
				this->scheduleOnce(schedule_selector(ActionManager::resumeAction),buffStayTime);
			}

		}else if(strcmp(this->_character->getCString(),"Kiba")==0){
			if(_skillChangeBuffValue==18){
				this->scheduleOnce(schedule_selector(ActionManager::resumeAction),buffStayTime);
			}
		}else if( (strcmp(this->_character->getCString(),"ImmortalSasuke")==0 ||
			strcmp(this->_character->getCString(),"Sasuke")==0 )
			&& _skillChangeBuffValue==18){
			this->unschedule(schedule_selector(ActionManager::resumeAction));
			this->unschedule(schedule_selector(ActionManager::disableBuff));

			this->_isTaunt=false;
			this->setHurtAction(createAnimation(hurtArray,10.0f,false,true));
			this->disableBuff(0);

			this->scheduleOnce(schedule_selector(ActionManager::resumeAction),buffStayTime);
			
		}else if(strcmp(this->_character->getCString(),"Minato")==0){
			if(_skillChangeBuffValue==18){
				this->scheduleOnce(schedule_selector(ActionManager::resumeAction),buffStayTime);
			}
		}else{
			if(strcmp(this->_character->getCString(),"Kankuro")!=0 &&
				strcmp(this->_character->getCString(),"Chiyo")!=0 &&
				strcmp(this->_character->getCString(),"Roshi")!=0 &&
				strcmp(this->_character->getCString(),"Han")!=0 &&
				strcmp(this->_character->getCString(),"Hiruzen")!=0 &&
				strcmp(this->_character->getCString(),"Suigetsu")!=0 &&
				strcmp(this->_character->getCString(),"Jugo")!=0 && 	
				strcmp(this->_character->getCString(),"Kisame")!=0 &&
					strcmp(this->_character->getCString(),"Parents")!=0 &&
				strcmp(this->_character->getCString(),"Lee")!=0 && 
				strcmp(this->_character->getCString(),"RockLee")!=0
				){
				this->scheduleOnce(schedule_selector(ActionManager::resumeAction),buffStayTime);
			}
		}

		this->changeAction();
	
	}else if(strcmp(_attackType->getCString(),"tBuff")==0){

		_skillChangeBuffValue=buffValue;
		this->scheduleOnce(schedule_selector(ActionManager::resumeAction),buffStayTime);
		this->scheduleOnce(schedule_selector(ActionManager::disableBuff),buffStayTime);
		this->setBuffEffect(_attackType->getCString());

		this->changeAction();

	}else if(strcmp(_attackType->getCString(),"stBuff")==0){

		if(strcmp(_role->getCString(),"Player")==0 || strcmp(this->getGroup()->getCString(),_delegate->currentPlayer->getGroup()->getCString())==0){
			this->setOpacity(150);
		}else{
			this->setVisible(false);
		}
		if(_hpBar){
		_hpBar->setVisible(false);
		}
		if(_shadow){
			_shadow->setVisible(false);
		}
		this->_isVisable=false;
		this->scheduleOnce(schedule_selector(ActionManager::disableBuff),buffStayTime);

	}else if(strcmp(_attackType->getCString(),"GroupHeal")==0 ||
		strcmp(_attackType->getCString(),"GroupBuff")==0
		){
		if(this->_healBuffValue){
			_healBuffValue+=buffValue;
		}else{
			_healBuffValue=buffValue;
		}

		this->schedule(schedule_selector(ActionManager::healBuff),1);
		
		
	}
	if(strcmp(this->getRole()->getCString(),"Player")==0){

		this->_delegate->getHudLayer()->setBuffDisplay(_attackType->getCString(),buffStayTime);

	}


}


void ActionManager::setBuffEffect(const char* type){
	if(_skillBuffEffect){
		_skillBuffEffect->removeFromParent();
		_skillBuffEffect=NULL;
	}

	if(_healBuffEffect){
		_healBuffEffect->removeFromParent();
		_healBuffEffect=NULL;
	}

	if(strcmp(type,"hBuff")==0){
		_healBuffEffect=Effect::create(type,this);
		this->addChild(_healBuffEffect);
	}else if(strcmp(type,"hsBuff")==0 ){
		_skillBuffEffect=Effect::create(type,this);
		_skillBuffEffect->setPositionY(14);
		this->addChild(_skillBuffEffect);
	}else if(strcmp(type,"tBuff")==0 ||
		strcmp(type,"dcBuff")==0 ||
		strcmp(type,"jdBuff")==0 ||
		strcmp(type,"bmBuff")==0 
		){
		_skillBuffEffect=Effect::create(type,this);
		this->addChild(_skillBuffEffect);
	}else if(strcmp(type,"dhBuff")==0){
		_dehealBuffEffect=Effect::create(type,this);	
		this->addChild(_dehealBuffEffect);
	}
}

void ActionManager::removeBuffEffect(const char* type){
	if(strcmp(type,"hBuff")==0 && _healBuffEffect){
		_healBuffEffect->removeFromParent();
		_healBuffEffect=NULL;
	}else if(strcmp(type,"sBuff")==0  && _skillBuffEffect){
		_skillBuffEffect->removeFromParent();
		_skillBuffEffect=NULL;
	}else if(strcmp(type,"dhBuff")==0 && _dehealBuffEffect){
		_dehealBuffEffect->removeFromParent();
		_dehealBuffEffect=NULL;
	}
	
	else if(strcmp(type,"all")==0){
		if(_healBuffEffect){
			_healBuffEffect->removeFromParent();
			_healBuffEffect=NULL;
			_healBuffValue=NULL;
			_buffStartTime=NULL;
		}
		if(_powerBuffEffect){
			_powerBuffEffect->removeFromParent();
			_powerBuffEffect=NULL;
		}
		if(_skillBuffEffect){
			_skillBuffEffect->removeFromParent();
			_skillBuffEffect=NULL;
		}
		if(_dehealBuffEffect){
			_dehealBuffEffect->removeFromParent();
			_dehealBuffValue=NULL;
			_dehealBuffEffect=NULL;
			_debuffStartTime=NULL;

		}
	}
}

void ActionManager::disableBuff(float dt){
	if(_skillUPBuffValue){
		this->setsAttackValue1(CCString::createWithFormat("%d",atoi(this->_sattackValue1->getCString())-_skillUPBuffValue));
		this->setsAttackValue2(CCString::createWithFormat("%d",atoi(this->_sattackValue2->getCString())-_skillUPBuffValue));
		this->setsAttackValue3(CCString::createWithFormat("%d",atoi(this->_sattackValue3->getCString())-_skillUPBuffValue));
		_skillUPBuffValue=NULL;

		if(strcmp(this->getCharacter()->getCString(),"Neji")==0){
			_isBati=false;
		}
		this->removeBuffEffect("sBuff");
	}else if(_skillBuffEffect){
		this->removeBuffEffect("sBuff");
	}else if(!_isVisable && this->_actionState!=ACTION_STATE_HURT){ 
		//防止被困住的时候进行还原

		this->setOpacity(255);
		this->setVisible(true);
		
		if(_hpBar){
			_hpBar->setVisible(true);
		}
		if(_shadow){
			_shadow->setVisible(true);
		}

		_isVisable=true;
	}else if(_skillChangeBuffValue && strcmp(this->getCharacter()->getCString(),"Tobi")==0 ){
		this->setOpacity(255);
	}
}

void ActionManager::disableDebuff(float dt){

	if((strcmp(this->getCharacter()->getCString(),"ImmortalSasuke")==0 ||
		strcmp(this->getCharacter()->getCString(),"Itachi")==0 ) 
		&& _isBati
	){
		return;

	}

	if(this->getWalkSpeed()==112){
		this->setWalkSpeed(224);
	}
}

void ActionManager::healBuff(float dt){
	cc_timeval timeVal;
	CCTime::gettimeofdayCocos2d(&timeVal, 0);
	float curTime = timeVal.tv_sec * 1000 + timeVal.tv_usec / 1000;

	if(!_buffStartTime){
		_buffStartTime=curTime;	
	}
	int limitTime=10000;
	if(strcmp(_character->getCString(),"Tsunade")==0){
		 limitTime=15000;
	}

	if(_buffStartTime && curTime-_buffStartTime>=limitTime){
		this->unschedule(schedule_selector(ActionManager::healBuff));
		this->removeBuffEffect("hBuff");
		_healBuffValue=NULL;
		_buffStartTime=NULL;
		return;
	};
	//香磷群补
	if(strcmp(_character->getCString(),"Karin")==0){

		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			Hero* tempHero=(Hero*) pObject;
			if(strcmp(this->_group->getCString(),tempHero->_group->getCString())==0
				&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
				&& tempHero->_actionState!=ACTION_STATE_DEAD
				){
					float distanceX=ccpSub(tempHero->getPosition(),this->getPosition()).x;
					float tempRange1=128+this->getContentSize().width/2;
					if(abs(distanceX)<=tempRange1 &&
						abs(tempHero->getPositionY()-this->getPositionY())<=128){

							if(atoi(tempHero->getMaxHP()->getCString())-atoi(tempHero->getHP()->getCString())<=_healBuffValue){
								tempHero->setHP(CCString::create(tempHero->getMaxHP()->getCString()));
								if(tempHero->_hpBar){
									tempHero->_hpBar->loseHP(tempHero->getHpPercent());
								}

							}else{
								tempHero->setHP(CCString::createWithFormat("%d",atoi(tempHero->getHP()->getCString())+int(_healBuffValue)));
								if(tempHero->_hpBar){
									tempHero->_hpBar->loseHP(tempHero->getHpPercent());
								}
							};

							if(strcmp(tempHero->getRole()->getCString(),"Player")==0){
								_delegate->setHPLose(tempHero->getHpPercent());
							}

							//群补特效

							if(tempHero->_isVisable){
								Effect* tmpEffect=Effect::create("Kagura",tempHero);
								if(strcmp(tempHero->getRole()->getCString(),"Player")==0){
									tmpEffect->setOpacity(150);
								}
								tmpEffect->setPosition(ccp(tempHero->getContentSize().width/2,tempHero->getContentSize().height/2));
								tempHero->addChild(tmpEffect);
							}





					};

			}
		};


	}else if(strcmp(_character->getCString(),"Chiyo")==0){

		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			Hero* tempHero=(Hero*) pObject;
			if(strcmp(this->_group->getCString(),tempHero->_group->getCString())==0
				&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
				&& strcmp(tempHero->_character->getCString(),"Chiyo")!=0
				){
					CCPoint	sp=ccpSub(tempHero->getPosition(),this->getPosition());
					if(abs(sp.x)<=winSize.width/2){


						if(tempHero->_level>=2){
							if(45000-atof(tempHero->getCKR()->getCString())>=_healBuffValue){
								float newValue=atof(tempHero->getCKR()->getCString())+_healBuffValue;
								tempHero->setCKR(CCString::createWithFormat("%f",newValue));
							}else{
								tempHero->setCKR(CCString::create("45000"));

							}	

							if(atof(tempHero->getCKR()->getCString())>=15000){
								tempHero->_isCanOugis1=true;

							}

							if(strcmp(tempHero->_role->getCString(),"Player")==0){
								_delegate->setCKRLose(false);
							}


						}

						if(tempHero->_level>=4 ){

							if(50000-atof(tempHero->getCKR2()->getCString())>=_healBuffValue){
								float newValue=atof(tempHero->getCKR2()->getCString())+_healBuffValue;
								tempHero->setCKR2(CCString::createWithFormat("%f",newValue));

							}else{
								tempHero->setCKR2(CCString::create("50000"));

							}	

							if(atof(tempHero->getCKR2()->getCString())>=25000){
								tempHero->_isCanOugis2=true;

							}

							if(strcmp(tempHero->_role->getCString(),"Player")==0){
								tempHero->_delegate->setCKRLose(true);
							}

						}

						//群补特效

						if(tempHero->_isVisable){
							Effect* tmpEffect=Effect::create("Hupo",tempHero);
							if(strcmp(tempHero->getRole()->getCString(),"Player")==0){
								tmpEffect->setOpacity(150);
							}
							tmpEffect->setPosition(ccp(tempHero->getContentSize().width/2,tempHero->getContentSize().height/2+6));
							tempHero->addChild(tmpEffect);
						}

					}


			}
		};

	}else if(strcmp(_character->getCString(),"Slug")==0){

		CCObject* pObject;
		CCArray* list;

		if(strcmp("Akatsuki",_group->getCString())==0){
			list=_delegate->_AkatsukiFlogArray;
		}else{
			list=_delegate->_KonohaFlogArray;
		} 
		
		CCARRAY_FOREACH(list,pObject){
			ActionManager* tempHero=(ActionManager*) pObject;
			if(strcmp(this->_group->getCString(),tempHero->_group->getCString())==0
				&& tempHero->_actionState!=ACTION_STATE_DEAD
				){
					float distanceX=ccpSub(tempHero->getPosition(),this->getPosition()).x;
					float tempRange1=128+this->getContentSize().width/2;
					if(abs(distanceX)<=tempRange1 &&
						abs(tempHero->getPositionY()-this->getPositionY())<=128){

							if(atoi(tempHero->getMaxHP()->getCString())-atoi(tempHero->getHP()->getCString())<=_healBuffValue){
								tempHero->setHP(CCString::create(tempHero->getMaxHP()->getCString()));
								if(tempHero->_hpBar){
									tempHero->_hpBar->loseHP(tempHero->getHpPercent());
								}

							}else{
								tempHero->setHP(CCString::createWithFormat("%d",atoi(tempHero->getHP()->getCString())+int(_healBuffValue)));
								if(tempHero->_hpBar){
									tempHero->_hpBar->loseHP(tempHero->getHpPercent());
								}
							};

					};

			}




		}

	}else if(strcmp(_character->getCString(),"Sakura")==0 ||
		strcmp(_character->getCString(),"Tsunade")==0 
		){

		//小樱单补
		if(atoi(_maxHP->getCString())-atoi(_hp->getCString())<=_healBuffValue){
			this->setHP(CCString::create(_maxHP->getCString()));
			if(_hpBar){
				_hpBar->loseHP(this->getHpPercent());
			}


		}else{
			this->setHP(CCString::createWithFormat("%d",atoi(_hp->getCString())+int(_healBuffValue)));
			if(_hpBar){
				_hpBar->loseHP(this->getHpPercent());
			}
		};
		if(_role && strcmp(_role->getCString(),"Player")==0){
			_delegate->setHPLose(this->getHpPercent());
		}


	}



}

void ActionManager::dehealBuff(float dt){
	cc_timeval timeVal;
	CCTime::gettimeofdayCocos2d(&timeVal, 0);
	float curTime = timeVal.tv_sec * 1000 + timeVal.tv_usec / 1000;

	if(!_debuffStartTime)_debuffStartTime=curTime;	
	

	if(_debuffStartTime&& abs(_debuffStartTime-curTime)>10000){
		this->unschedule(schedule_selector(ActionManager::dehealBuff));
		this->setWalkSpeed(_originSpeed);
		this->removeBuffEffect("dhBuff");
		_dehealBuffValue=NULL;
		_debuffStartTime=NULL;
		return;
	};

	


	CCObject* pObject;
	CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
		Hero* tempHero=(Hero*) pObject;
		if(strcmp(tempHero->getCharacter()->getCString(),"Asuma")==0){
			_slayer=tempHero;
		}
	};
	if(atoi(_hp->getCString())<=_dehealBuffValue){		
		this->setDamage(CCString::create("c_hit"),_dehealBuffValue,false);
		
	}else{
		this->setDamage(CCString::create("c_hit"),_dehealBuffValue,false);

	};
	if(_hpBar){
		_hpBar->loseHP(this->getHpPercent());
	}
	
	if(strcmp(_role->getCString(),"Player")==0){
		_delegate->setHPLose(this->getHpPercent());
	}
}

void ActionManager::lostBlood(float dt){


	CCObject* pObject;
	CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
		Hero* tempHero=(Hero*) pObject;
		if(strcmp(tempHero->getCharacter()->getCString(),"Shikamaru")==0){
			_slayer=tempHero;
		}
	}

	if(atoi(_hp->getCString())<=lostBloodValue){		
		this->setDamage(CCString::create("c_hit"),lostBloodValue,false);

	}else{
		this->setDamage(CCString::create("c_hit"),lostBloodValue,false);

	};

	if(_hpBar){
		_hpBar->loseHP(this->getHpPercent());
	}

	if(strcmp(_role->getCString(),"Player")==0){
		_delegate->setHPLose(this->getHpPercent());
	}
}

void ActionManager::removeLostBlood(float dt){
	this->lostBloodValue=0;
	this->unschedule(schedule_selector(ActionManager::lostBlood));
}

void ActionManager::changeAction(){

	if(strcmp(this->_character->getCString(),"Tenten")==0 ||
		 strcmp(this->_character->getCString(),"Shino")==0
		){
			this->setNAttackAction(createAnimation(skillSPC1Array,10.0f,false,true));
		
	}else if(strcmp(this->_character->getCString(),"Choji")==0 ){
	
			_isBati=true;
			this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));
			this->setIdleAction(createAnimation(skillSPC4Array,5.0f,true,false));
			this->setWalkAction(createAnimation(skillSPC2Array,5.0f,true,false));
			
			_tempAttackType=_nattackType;
			_nattackType=_spcattackType3;
			
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())+460));
			_nattackRangeX=32;
			_nattackRangeY=48;
			this->_isOnlySkillLocked=true;

			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->setLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->setLock();
				}
			}
			this->_gardValue+=5000;

			if(_hpBar){
				_hpBar->setPositionY(108);
			}
		
	}else if(strcmp(this->_character->getCString(),"Sakura")==0 ){

		this->setNAttackAction(createAnimation(skillSPC1Array,10.0f,false,true));
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())+400));

	}else if(strcmp(this->_character->getCString(),"Kakuzu")==0 ){	

		this->setBuffEffect("jdBuff");		

	}else if(strcmp(this->_character->getCString(),"Sai")==0 ||
		strcmp(this->_character->getCString(),"Deidara")==0
		){

		if(_skillChangeBuffValue==17){
			this->setNAttackAction(createAnimation(skillSPC1Array,10.0f,false,true));
		}else if(_skillChangeBuffValue==18){

			this->_isAllAttackLocked=true;
			this->_isBati=true;

			
			this->setWalkSpeed(320);	
			_originSpeed=320;
			
			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->setLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->setLock();
				}
			}

			this->setIdleAction(createAnimation(skillSPC2Array,5.0f,true,false));
			this->setWalkAction(createAnimation(skillSPC3Array,5.0f,true,false));

			if(_hpBar){
				_hpBar->setPositionY(120);
			}
			this->schedule(schedule_selector(ActionManager::setMonPer),0.5f);
			
		}

	}else if(strcmp(this->_character->getCString(),"Naruto")==0){

		this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));
		this->setKnockDownAction(createAnimation(skillSPC4Array,10.0f,false,true));

		
		this->setWalkSpeed(320);

		_originSpeed=320;

		
		this->_isOnlySkillLocked=true;

		this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_nattackValue->getCString())));	
		this->setnAttackValue(CCString::createWithFormat("%d",960));
		
	
		_nattackRangeX=_spcattackRangeX3;
		_nattackRangeY=_spcattackRangeY3;
		_tempAttackType=_nattackType;
		_nattackType=_spcattackType3;

		this->_gardValue+=5000;
		_isBati=true;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->setLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->setLock();
			}
		}

		
	}else if(strcmp(this->_character->getCString(),"SageNaruto")==0 ||
		strcmp(this->_character->getCString(),"RikudoNaruto")==0
		){

		this->_gardValue+=5000;
		_isBati=true;
		this->isPofang=true;
		this->_isOnlySkillLocked=true;

		this->setIdleAction(createAnimation(skillSPC4Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));

		
			
		if(strcmp(this->_character->getCString(),"RikudoNaruto")==0){
			this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_nattackValue->getCString())));	
			this->setnAttackValue(CCString::createWithFormat("%d",560));
		}
		
		this->setWalkSpeed(320);
		_originSpeed=320;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->setLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->setLock();
			}
		}
	}else if(strcmp(this->_character->getCString(),"Konan")==0){

		this->_isAllAttackLocked=true;
		this->_isBati=true;

		_attackType=_spcattackType2;
		_attackValue=atoi(_spcattackValue2->getCString());
		_attackRangeX=_spcattackRangeX2;
		_attackRangeY=_spcattackRangeY2;

		
		this->setWalkSpeed(320);
		_originSpeed=320;

		this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		if(_hpBar){
		_hpBar->setPositionY(90);
		}
		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->setLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->setLock();
			}
		}


	}else if(strcmp(this->_character->getCString(),"Kiba")==0){
		if(_skillChangeBuffValue==17){
			_isBati=false;

			if(strcmp(this->getRole()->getCString(),"Player")==0){
				_delegate->getHudLayer()->skill1Button->setLock();
				_delegate->getHudLayer()->skill2Button->unLock();
				_delegate->getHudLayer()->skill3Button->unLock();
			}

			this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
			this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
			this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));
			if(_hpBar){
			_hpBar->setPositionY(65);
			}
			_skillChangeBuffValue=NULL;

		}else if(_skillChangeBuffValue==18){
			CCObject* pObject;
			CCARRAY_FOREACH(this->getMonsterArray(),pObject){
				Monster* mo=(Monster*) pObject;
				if(strcmp(mo->getCharacter()->getCString(),"Akamaru")==0){
					mo->attack(SKILL2);
				}
				
			};

			this->_powerUPBuffValue=360;
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())+_powerUPBuffValue));
			this->setNAttackAction(createAnimation(skillSPC4Array,10.0f,false,true));

		}

	}else if(strcmp(this->_character->getCString(),"Akamaru")==0){
		this->_powerUPBuffValue=360;
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())+_powerUPBuffValue));
		this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));

		if(this->getActionState()==ACTION_STATE_ATTACK){
			_actionState=ACTION_STATE_WALK;
			this->idle();
		}
		
	}else if(strcmp(this->_character->getCString(),"Sasuke")==0){

		if(_skillChangeBuffValue==17){
			this->_isTaunt=true;
			this->setHurtAction(createAnimation(skillSPC5Array,10.0f,false,true));

			CCObject* pObject;
			CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
				ActionManager* tempHero=(ActionManager*) pObject;
				if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
					&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
					&& tempHero->_actionState!=ACTION_STATE_HURT
					&& tempHero->_actionState!=ACTION_STATE_DEAD
					){
						float distanceX=ccpSub(tempHero->getPosition(),this->getPosition()).x;
						if(distanceX<winSize.width/2){
							//取消隐身
							if(!tempHero->_isVisable){
								if(strcmp(tempHero->getCharacter()->getCString(),"Konan")==0 ||
									strcmp(tempHero->getCharacter()->getCString(),"Deidara")==0
									){
										tempHero->unschedule(schedule_selector(ActionManager::disableBuff));
								}


								tempHero->setOpacity(255);
								tempHero->setVisible(true);

								if(tempHero->_hpBar){
									tempHero->_hpBar->setVisible(true);
								}
								if(tempHero->_shadow){
									tempHero->_shadow->setVisible(true);
								}

								tempHero->_isVisable=true;
							}

						}

				}
			};

		}else if(_skillChangeBuffValue==18){

			this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
			this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
			this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));
			this->setKnockDownAction(createAnimation(skillSPC4Array,10.0f,false,true));

			
			this->setWalkSpeed(320);
			_originSpeed=320;


			this->_isOnlySkillLocked=true;
			this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_nattackValue->getCString())));	
			this->setnAttackValue(CCString::createWithFormat("%d",560));
			

			_nattackRangeX=_spcattackRangeX3;
			_nattackRangeY=_spcattackRangeY3;
			_tempAttackType=_nattackType;
			_nattackType=_spcattackType3;

			this->_gardValue+=5000;
			_isBati=true;

			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->setLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->setLock();
				}
			}


		}
	
	}else if(strcmp(this->_character->getCString(),"ImmortalSasuke")==0){

		if(_skillChangeBuffValue==17){
			this->_isTaunt=true;
			this->setHurtAction(createAnimation(skillSPC1Array,10.0f,false,true));

			CCObject* pObject;
			CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
				ActionManager* tempHero=(ActionManager*) pObject;
				if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
					&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
					&& tempHero->_actionState!=ACTION_STATE_HURT
					&& tempHero->_actionState!=ACTION_STATE_DEAD
					){
						float distanceX=ccpSub(tempHero->getPosition(),this->getPosition()).x;
						if(distanceX<winSize.width/2){
							//取消隐身
							if(!tempHero->_isVisable){
								if(strcmp(tempHero->getCharacter()->getCString(),"Konan")==0 ||
									strcmp(tempHero->getCharacter()->getCString(),"Deidara")==0
									){
										tempHero->unschedule(schedule_selector(ActionManager::disableBuff));
								}


								tempHero->setOpacity(255);
								tempHero->setVisible(true);

								if(tempHero->_hpBar){
									tempHero->_hpBar->setVisible(true);
								}
								if(tempHero->_shadow){
									tempHero->_shadow->setVisible(true);
								}

								tempHero->_isVisable=true;
							}

						}

				}
			};

		}else if(_skillChangeBuffValue==18){
			this->setIdleAction(createAnimation(skillSPC4Array,5.0f,true,false));
			this->setWalkAction(createAnimation(skillSPC3Array,10.0f,true,false));
			this->setNAttackAction(createAnimation(skillSPC2Array,10.0f,false,true));
			this->setWalkSpeed(112);
			this->_originSpeed=112;
			
			this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_nattackValue->getCString())));	
			this->setnAttackValue(CCString::createWithFormat("%d",1160));
		
			_nattackRangeX=156;
			_nattackRangeY=64;

			this->_gardValue+=5000;
			this->_isBati=true;
			this->_isOnlySkillLocked=true;

			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->setLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->setLock();
				}
			}
		}



	}else if(strcmp(this->_character->getCString(),"Tobi")==0){
		
		this->setWalkAction(createAnimation(skillSPC1Array,10.0f,true,false));
		
		this->setWalkSpeed(320);

		_originSpeed=320;

		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			ActionManager* tempHero=(ActionManager*) pObject;
			if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
				&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
				&& tempHero->_actionState!=ACTION_STATE_HURT
				&& tempHero->_actionState!=ACTION_STATE_DEAD
				){
					float distanceX=ccpSub(tempHero->getPosition(),this->getPosition()).x;
					if(distanceX<winSize.width/2){
						//取消隐身
						if(!tempHero->_isVisable){
							if(strcmp(tempHero->getCharacter()->getCString(),"Konan")==0 ||
								strcmp(tempHero->getCharacter()->getCString(),"Deidara")==0
								){
									tempHero->unschedule(schedule_selector(ActionManager::disableBuff));
							}


							tempHero->setOpacity(255);
							tempHero->setVisible(true);

							if(tempHero->_hpBar){
								tempHero->_hpBar->setVisible(true);
							}
							if(tempHero->_shadow){
								tempHero->_shadow->setVisible(true);
							}

							tempHero->_isVisable=true;
						}

					}

			}
		};


	}else if(strcmp(this->_character->getCString(),"Gaara")==0){
		this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));
		
		this->_isOnlySkillLocked=true;

		this->_gardValue+=5000;
		_isBati=true;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->setLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->setLock();
			}
		}

		if(_hpBar){
			_hpBar->setPositionY(134);
		}

	}else if(strcmp(this->_character->getCString(),"Itachi")==0){

		this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));
		this->setKnockDownAction(createAnimation(skillSPC4Array,10.0f,false,true));
		this->setWalkSpeed(112);
		this->_originSpeed=112;

		this->_isOnlySkillLocked=true;

		this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_nattackValue->getCString())));	
		this->setnAttackValue(CCString::createWithFormat("%d",560));

		_nattackRangeX=128;
		_nattackRangeY=64;

		this->_gardValue+=5000;
		_isBati=true;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->setLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->setLock();
			}
		}

	
	}else if(strcmp(this->_character->getCString(),"Kakashi")==0){
		
		this->setSkill1Action(createAnimation(skillSPC1Array,10.0f,false,true));
		this->setSkill2Action(createAnimation(skillSPC2Array,10.0f,false,true));
		this->setIdleAction(createAnimation(skillSPC3Array,5.0f,true,false));
		this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_sattackValue1->getCString())));
		this->setsAttackValue1(_spcattackValue1);
		
		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			ActionManager* tempHero=(ActionManager*) pObject;
			if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
				&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
				&& tempHero->_actionState!=ACTION_STATE_HURT
				&& tempHero->_actionState!=ACTION_STATE_DEAD
				){
					float distanceX=ccpSub(tempHero->getPosition(),this->getPosition()).x;
					if(distanceX<winSize.width/2){
						//取消隐身
						if(!tempHero->_isVisable){
							if(strcmp(tempHero->getCharacter()->getCString(),"Konan")==0 ||
								strcmp(tempHero->getCharacter()->getCString(),"Deidara")==0
								){
									tempHero->unschedule(schedule_selector(ActionManager::disableBuff));
							}


							tempHero->setOpacity(255);
							tempHero->setVisible(true);

							if(tempHero->_hpBar){
								tempHero->_hpBar->setVisible(true);
							}
							if(tempHero->_shadow){
								tempHero->_shadow->setVisible(true);
							}

							tempHero->_isVisable=true;
						}

					}

			}
		};
		

		if(strcmp(this->_role->getCString(),"Player")==0){
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Kakashi_skill1_1.png"); 
			_delegate->getHudLayer()->skill1Button->setDisplayFrame(frame);
			frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Kakashi_skill2_1.png"); 
			_delegate->getHudLayer()->skill2Button->setDisplayFrame(frame);

		}
		
	}else if(strcmp(this->_character->getCString(),"Hiruzen")==0 ){
			_isBati=true;
			_nattackRangeX=16;
			_nattackRangeY=48;
			this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_nattackValue->getCString())));	
			this->setnAttackValue(CCString::createWithFormat("%d",560));
			
			this->_isOnlySkillLocked=true;


			this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
			this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
			this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));

			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->setLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->setLock();
				}
			}


	}else if(strcmp(this->_character->getCString(),"Suigetsu")==0 ){

		this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_nattackValue->getCString())));	
		this->setnAttackValue(CCString::createWithFormat("%d",1960));

		this->_isOnlySkillLocked=true;

		_nattackRangeX=16;
		_nattackRangeY=48;
		
		_isBati=true;

		this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->setLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->setLock();
			}
		}


	}else if(strcmp(this->_character->getCString(),"Kisame")==0){

		this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_nattackValue->getCString())));	
		this->setnAttackValue(CCString::createWithFormat("%d",660));

		this->_isOnlySkillLocked=true;

		_nattackRangeX=32;
		_nattackRangeY=48;

		this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));



		this->setWalkSpeed(112);
		_originSpeed=112;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->setLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->setLock();
			}
		}



	}else if(strcmp(this->_character->getCString(),"Jugo")==0){

		this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_nattackValue->getCString())));	
		this->setnAttackValue(CCString::createWithFormat("%d",1960));

		this->_isOnlySkillLocked=true;

		_nattackRangeX=16;
		_nattackRangeY=48;

		this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));


		
	    this->setWalkSpeed(320);
		_originSpeed=320;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->setLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->setLock();
			}
		}



	}else if(strcmp(this->_character->getCString(),"Parents")==0){

		this->settempAttackValue1(CCString::createWithFormat("%d",atoi(_nattackValue->getCString())));	
		this->setnAttackValue(CCString::createWithFormat("%d",2460));

		this->_isOnlySkillLocked=true;

		_nattackRangeX=16;
		_nattackRangeY=48;

		this->setWalkAction(createAnimation(skillSPC1Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC2Array,10.0f,false,true));


		if(strcmp(this->getMaster()->getRole()->getCString(),"Player")==0){
			if(this->_delegate->getHudLayer()->skill2Button){
				this->_delegate->getHudLayer()->skill2Button->setLock();
			}

		}
		this->setWalkSpeed(460);
		


	}else if(strcmp(this->_character->getCString(),"Kankuro")==0){

		if(strcmp(this->_role->getCString(),"Player")==0){	
			_delegate->getHudLayer()->skill1Button->setLock();
			_delegate->getHudLayer()->skill2Button->unLock();
		}
	}else if(strcmp(this->_character->getCString(),"Chiyo")==0){

		if(strcmp(this->_role->getCString(),"Player")==0){	
			_delegate->getHudLayer()->skill1Button->setLock();
			_delegate->getHudLayer()->skill2Button->unLock();
			_delegate->getHudLayer()->skill3Button->unLock();
		}
	}else if(strcmp(this->_character->getCString(),"Minato")==0){

		if(_skillChangeBuffValue==17){


			this->setSkill1Action(createAnimation(skillSPC1Array,10.0f,false,true));

			if(strcmp(this->_role->getCString(),"Player")==0){

				CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Minato_skill1_1.png"); 
				_delegate->getHudLayer()->skill1Button->setDisplayFrame(frame);
				if(_delegate->getHudLayer()->skill1Button->_clickNum<2){
					_delegate->getHudLayer()->skill1Button->_clickNum++;
				}
				
			}

		}else if(_skillChangeBuffValue==18){

			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())+200));

			_nattackRangeX=16;
			_nattackRangeY=48;

			this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));

		}

	}else if(strcmp(this->_character->getCString(),"Lee")==0||
		strcmp(this->_character->getCString(),"RockLee")==0
		){
		if(bamen==0 && !this->_heartEffect){
			_heartEffect=CCSprite::createWithSpriteFrameName("Bamen_Effect_00.png");
			_heartEffect->setPosition(ccp(this->getContentSize().width+40,60));
			this->addChild(_heartEffect);
		}
		if(bamen<5){
			bamen+=1;
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("Bamen_Effect_%02d.png",this->bamen-1)->getCString()); 
			this->_heartEffect->setDisplayFrame(frame);
		}else{
			return;
		}
		
		if(bamen ==1){
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())+30));
			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->unLock();
				}
			}
		}else if(bamen ==2){
			this->setsAttackValue2(CCString::createWithFormat("%d",atoi(this->_sattackValue2->getCString())+100));
		}else if(bamen==3){
			if(!_skillBuffEffect){
				this->setBuffEffect("bmBuff");
			}
			this->setTransform();
	

			if(strcmp(this->getRole()->getCString(),"Player")==0){
				_delegate->getHudLayer()->skill3Button->unLock();
			}

			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->unLock();
				}
			}
		}else if(bamen==4){
			this->setsAttackValue2(CCString::createWithFormat("%d",atoi(this->_sattackValue2->getCString())+100));
			this->setsAttackValue3(CCString::createWithFormat("%d",atoi(this->_sattackValue3->getCString())+100));
		}else if(bamen==5){
			this->setWalkAction(createAnimation(skillSPC1Array,10.0f,true,false));
			this->setWalkSpeed(320);
			_originSpeed=320;
			this->setsAttackValue2(CCString::createWithFormat("%d",atoi(this->_sattackValue2->getCString())+100));
			this->setsAttackValue3(CCString::createWithFormat("%d",atoi(this->_sattackValue3->getCString())+100));
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())+60));
		}


	}else if(strcmp(this->_character->getCString(),"Tsunade")==0){
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())+250));
		this->_isOnlySkillLocked=true;
		_nattackRangeX=32;
		_nattackRangeY=48;
		_tempAttackType=_nattackType;
		_nattackType=_spcattackType3;

		_isBati=true;
		_healBuffValue=3000;
		this->schedule(schedule_selector(ActionManager::healBuff),1);

		this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->setLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->setLock();
			}
		}

	}else if(strcmp(this->_character->getCString(),"Roshi")==0 ||
		strcmp(this->_character->getCString(),"Han")==0 
		){
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())+700));
		_nattackRangeX=0;
		_nattackRangeY=48;
		_tempAttackType=_nattackType;
		_nattackType=_spcattackType2;

		_isBati=true;
		isPofang=true;
		if(_hpBar){
		_hpBar->setPositionY(120);
		}
		this->setWalkAction(createAnimation(skillSPC1Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC2Array,10.0f,false,true));
		this->setIdleAction(createAnimation(skillSPC3Array,5.0f,true,false));

	}else if(strcmp(this->_character->getCString(),"Hidan")==0){
		
		_isBati=true;
		_isTaunt=true;
		this->_isOnlySkillLocked=true;
		this->setIdleAction(createAnimation(skillSPC1Array,5.0f,true,false));
		this->setWalkAction(createAnimation(skillSPC2Array,10.0f,true,false));
		this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->setLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->setLock();
			}
		}

	}
	
}
void ActionManager::changeAction2(){

	if(strcmp(this->_character->getCString(),"Minato")==0){

		_attackValue=atoi(_spcattackValue2->getCString());
		this->setAttackType(this->getspcAttack2Type());
		_attackRangeX=_spcattackRangeX2;
		_attackRangeY=_spcattackRangeY2;

		this->setSkill2Action(createAnimation(skillSPC2Array,10.0f,false,true));

	}

}

void ActionManager::reCatched(float dt){
	this->setVisible(true);
	this->_isVisable=true;

	if(_shadow){
		_shadow->setVisible(true);
	}
}

void ActionManager::resumeAction(float dt){

	if(strcmp(this->_character->getCString(),"Tenten")==0 ||
		strcmp(this->_character->getCString(),"Shino")==0 ){
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
	}else if(strcmp(this->_character->getCString(),"Kakuzu")==0 ){	
		this->removeBuffEffect("sBuff");		
	}else if(strcmp(this->_character->getCString(),"Choji")==0 ){

	
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())-460));
			_nattackRangeX=16;
			_nattackRangeY=48;
			_nattackType=_tempAttackType;
			_tempAttackType=NULL;

			this->_isOnlySkillLocked=false;
			_isBati=false;
			this->_gardValue-=5000;

			this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
			this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
			this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

			if(_actionState!=ACTION_STATE_DEAD){
				_actionState=ACTION_STATE_WALK;
				this->idle();
			}

			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->unLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->unLock();
				}
			}

			if(_hpBar){
				_hpBar->setPositionY(this->getHeight());
			}

		

	}else if(strcmp(this->_character->getCString(),"Sakura")==0){
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())-400));

	}else if(strcmp(this->_character->getCString(),"Sai")==0 ||
		strcmp(this->_character->getCString(),"Deidara")==0
		){


		if(_skillChangeBuffValue==17){
			this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
		}else if(_skillChangeBuffValue==18){

			this->_isBati=false;
			this->_isAllAttackLocked=false;
			_originSpeed=224;

			
			this->setWalkSpeed(224);
			
			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->unLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->unLock();
				}
			}

			this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
			this->setWalkAction(createAnimation(walkArray,10.0f,true,false));

			if(_actionState!=ACTION_STATE_DEAD){
				_actionState=ACTION_STATE_WALK;
				this->idle();
			}
			if(_hpBar){
			_hpBar->setPositionY(this->getHeight());
			}

			this->unschedule(schedule_selector(ActionManager::setMonPer));

		}

	}else if(strcmp(this->_character->getCString(),"Gaara")==0){
		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		this->_isOnlySkillLocked=false;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}
		_gardValue-=5000;
		_isBati=false;

		
		if(_actionState!=ACTION_STATE_DEAD){
			_actionState=ACTION_STATE_WALK;
			this->idle();
		}
		if(_hpBar){
			_hpBar->setPositionY(this->getHeight());
		}

	}else if(strcmp(this->_character->getCString(),"Konan")==0){
		
	
		_isAllAttackLocked=false;
		_isBati=false;

		_originSpeed=224;
		
		this->setWalkSpeed(224);
		

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}

		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));

		if(_actionState!=ACTION_STATE_DEAD){
			_actionState=ACTION_STATE_WALK;
			this->idle();
		}
		if(_hpBar){
		_hpBar->setPositionY(this->getHeight());
		}
	
	}else if(strcmp(this->_character->getCString(),"Naruto")==0){

		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		this->_isOnlySkillLocked=false;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}

		
		this->setWalkSpeed(224);
		
		_originSpeed=224;
		if(_tempAttackValue1){
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
				_tempAttackValue1=NULL;
		}
		isPofang=false;
	
		_nattackRangeX=16;
		_nattackRangeY=48;
		_nattackType=_tempAttackType;
		_gardValue-=5000;
		_isBati=false;

		if(_actionState!=ACTION_STATE_DEAD){
			_actionState=ACTION_STATE_WALK;
			this->knockDown();
		}

		this->setKnockDownAction(createAnimation(knockDownArray,10.0f,false,true));


	}else if(strcmp(this->_character->getCString(),"SageNaruto")==0 ||
		strcmp(this->_character->getCString(),"RikudoNaruto")==0
		){

		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		this->_isOnlySkillLocked=false;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}
	
		this->setWalkSpeed(224);
		
		_originSpeed=224;

		_gardValue-=5000;
		_isBati=false;
		isPofang=false;

		if(_actionState!=ACTION_STATE_DEAD){
			
			if(strcmp(this->_character->getCString(),"SageNaruto")==0 && this->getLV()==6){
				_actionState=ACTION_STATE_WALK;
				this->setKnockDownAction(createAnimation(skillSPC5Array,10.0f,false,true));
				this->knockDown();
				this->setKnockDownAction(createAnimation(knockDownArray,10.0f,false,true));
				_skillChangeBuffValue=NULL;
				return;
			}
			_actionState=ACTION_STATE_WALK;
			this->idle();
		}
		
		if(_tempAttackValue1){
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
			_tempAttackValue1=NULL;
		}


	}else if(strcmp(this->_character->getCString(),"Kakashi")==0){
		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setSkill1Action(createAnimation(skill1Array,10.0f,false,true));
		this->setSkill2Action(createAnimation(skill2Array,10.0f,false,true));
		
		this->setsAttackValue1(CCString::createWithFormat("%d",atoi(_tempAttackValue1->getCString())));


		if(strcmp(this->_role->getCString(),"Player")==0){
			
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Kakashi_skill1.png"); 
			_delegate->getHudLayer()->skill1Button->setDisplayFrame(frame);
			frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Kakashi_skill2.png"); 
			_delegate->getHudLayer()->skill2Button->setDisplayFrame(frame);

		}


	}else if(strcmp(this->_character->getCString(),"Itachi")==0){

		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		this->_isOnlySkillLocked=false;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}

		
		this->setWalkSpeed(224);
		
		_originSpeed=224;
		if(_tempAttackValue1){
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
		_tempAttackValue1=NULL;
		}
		_nattackRangeX=16;
		_nattackRangeY=48;
		_gardValue-=5000;
		_isBati=false;

		if(_actionState!=ACTION_STATE_DEAD){
			_actionState=ACTION_STATE_WALK;
			this->knockDown();
		}

		this->setKnockDownAction(createAnimation(knockDownArray,10.0f,false,true));

		if(this->getMonsterArray() && getMonsterArray()->count()>0){
			CCObject* pObject;
			CCARRAY_FOREACH(this->getMonsterArray(),pObject){
				Monster* mo=(Monster*) pObject;
				mo->removeFromParent();
			};
			this->getMonsterArray()->removeAllObjects();
			this->setMonsterArray(NULL);
		}


	}else if(strcmp(this->_character->getCString(),"Kiba")==0){

			if(_powerUPBuffValue){
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())-_powerUPBuffValue));
				this->setNAttackAction(createAnimation(skillSPC3Array,10.0f,false,true));
				_powerUPBuffValue=NULL;
			}

			if(_actionState==ACTION_STATE_IDLE||
				_actionState==ACTION_STATE_WALK ||
				_actionState==ACTION_STATE_ATTACK
				){
					_actionState=ACTION_STATE_WALK;
					this->idle();
			}
			
	}else if(strcmp(this->_character->getCString(),"Akamaru")==0){
	
		if(_powerUPBuffValue){
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())-_powerUPBuffValue));
			this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
			this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
			this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
			_powerUPBuffValue=NULL;

			if(_actionState==ACTION_STATE_IDLE||
				_actionState==ACTION_STATE_WALK ||
				_actionState==ACTION_STATE_ATTACK
				){
					_actionState=ACTION_STATE_WALK;
					this->idle();
			}
		}

	}else if(strcmp(this->_character->getCString(),"Minato")==0){

	
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())-200));
		_nattackRangeX=16;
		_nattackRangeY=48;
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		_markPoint=ccp(0,0);
		_startPoint=ccp(0,0);

	}else if((strcmp(this->_character->getCString(),"Sasuke")==0||
		strcmp(this->_character->getCString(),"ImmortalSasuke")==0) && this->_isTaunt){

			this->_isTaunt=false;
			this->setHurtAction(createAnimation(hurtArray,10.0f,false,true));		
	}else if(strcmp(this->_character->getCString(),"Sasuke")==0 && _skillChangeBuffValue==18){


		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		this->_isOnlySkillLocked=false;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}

		
		this->setWalkSpeed(224);
		
		_originSpeed=224;
		if(_tempAttackValue1){
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
		_tempAttackValue1=NULL;
		}
		_nattackRangeX=16;
		_nattackRangeY=48;
		_nattackType=_tempAttackType;
		_gardValue-=5000;
		_isBati=false;

		if(_actionState!=ACTION_STATE_DEAD){
			_actionState=ACTION_STATE_WALK;
			this->knockDown();
		}

		this->setKnockDownAction(createAnimation(knockDownArray,10.0f,false,true));

	}else if(strcmp(this->_character->getCString(),"ImmortalSasuke")==0 && _skillChangeBuffValue==18){

		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		this->_isOnlySkillLocked=false;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}

		

	
		this->setWalkSpeed(224);
		
		_originSpeed=224;
		if(_tempAttackValue1){
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
		_tempAttackValue1=NULL;
		}
		_gardValue-=5000;
		_isBati=false;

		_nattackRangeX=16;
		_nattackRangeY=48;

		if(this->getMonsterArray() && getMonsterArray()->count()>0){
			CCObject* pObject;
			CCARRAY_FOREACH(this->getMonsterArray(),pObject){
				Monster* mo=(Monster*) pObject;
				mo->removeFromParent();
			};
			this->getMonsterArray()->removeAllObjects();
			this->setMonsterArray(NULL);
		}

		if(this->_actionState!=ACTION_STATE_DEAD){
			this->_actionState=ACTION_STATE_WALK;
			this->idle();
		}
		
		
		
	}else if(strcmp(this->_character->getCString(),"Tobi")==0){

			this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
			
			if (this->getOpacity()!=255){
				this->setOpacity(255);
			}

			
			this->setWalkSpeed(224);
			
			_originSpeed=224;
			

			if(this->_actionState==ACTION_STATE_WALK){
				this->idle();
			}

	}else if(strcmp(this->_character->getCString(),"Tsunade")==0){
		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())-250));
		_nattackRangeX=16;
		_nattackRangeY=48;
		_nattackType=_tempAttackType;
		_tempAttackType=NULL;

		this->_isOnlySkillLocked=false;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}
		_isBati=false;

		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));

		if(_actionState!=ACTION_STATE_DEAD){
			_actionState=ACTION_STATE_WALK;
			this->idle();
		}
	}else if(strcmp(this->_character->getCString(),"Ino")==0 && _isBati){
		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			Hero* tempHero=(Hero*) pObject;
			if(tempHero->_isControled){
					tempHero->_isControled=false;
					tempHero->changeGroup();
					if(strcmp(tempHero->getRole()->getCString(),"Player")==0){
						tempHero->_isAI=false;
						tempHero->unschedule(schedule_selector(ActionManager::setAI));
						this->_delegate->getHudLayer()->_isAllButtonLocked=false;
					}
					if(strcmp(this->getRole()->getCString(),"Player")==0){
						this->_delegate->controlChar=NULL;
					}
					if(this->getActionState()!=ACTION_STATE_DEAD){
						this->idle();
					}
					tempHero->_controler=NULL;
			}
		};

		_isBati=false;

	}else if(strcmp(this->_character->getCString(),"Hidan")==0){

		_isBati=false;
		_isTaunt=false;
		this->_isOnlySkillLocked=false;
		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}

		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));

		if(this->getMonsterArray() && getMonsterArray()->count()>0){
			CCObject* pObject;
			CCARRAY_FOREACH(this->getMonsterArray(),pObject){
				ActionManager* mo=(ActionManager*) pObject;
				//清除角色表的monter
				int index=_delegate->_CharacterArray->indexOfObject(mo);
				if(index>=0){
					_delegate->_CharacterArray->removeObjectAtIndex(index);
				}
				mo->setActionState(ACTION_STATE_DEAD);
				CCNotificationCenter::sharedNotificationCenter()->removeObserver(mo,"acceptAttack");
				mo->removeFromParent();	
				mo=NULL;

			};

			this->getMonsterArray()->removeAllObjects();
			_monsterArray=NULL;			
		}	

	
		if(strcmp(this->getRole()->getCString(),"Player")==0 ){
			this->_delegate->getHudLayer()->skill1Button->unLock();
		}
		if(_actionState!=ACTION_STATE_DEAD){
			_actionState=ACTION_STATE_WALK;
			this->idle();
		}

	}

	_skillChangeBuffValue=NULL;

}
void ActionManager::setActionResume(){

	if(strcmp(this->_character->getCString(),"Suigetsu")==0){
	
		if(_skillChangeBuffValue){

			this->_isBati=false;
			if(_tempAttackValue1){
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
			_tempAttackValue1=NULL;
			}
			_isOnlySkillLocked=false;
			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->unLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->unLock();
				}
			}

			_nattackRangeX=16;
			_nattackRangeY=48;

			this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
			this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
			this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
			
			_skillChangeBuffValue=NULL;

		}
	



	}else if(strcmp(this->_character->getCString(),"Jugo")==0){

		if(_skillChangeBuffValue){

			
			if(_tempAttackValue1){
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
				_tempAttackValue1=NULL;
			}
			_isOnlySkillLocked=false;
			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->unLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->unLock();
				}
			}

			_nattackRangeX=16;
			_nattackRangeY=48;

			this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
			this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
			this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

			_skillChangeBuffValue=NULL;


			
			this->setWalkSpeed(224);
			
			_originSpeed=224;


		}


	}else if(strcmp(this->_character->getCString(),"Kisame")==0){

		if(_skillChangeBuffValue){


			if(_tempAttackValue1){
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
				_tempAttackValue1=NULL;
			}
			_isOnlySkillLocked=false;
			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->unLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->unLock();
				}
			}

			_nattackRangeX=16;
			_nattackRangeY=48;

			this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
			this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
			this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

			_skillChangeBuffValue=NULL;



			this->setWalkSpeed(224);

			_originSpeed=224;


		}


	}else if(strcmp(this->_character->getCString(),"Parents")==0){

		if(_skillChangeBuffValue){


			if(_tempAttackValue1){
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
				_tempAttackValue1=NULL;
			}
			_isOnlySkillLocked=false;
			

			_nattackRangeX=16;
			_nattackRangeY=48;

			this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
			this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

			_skillChangeBuffValue=NULL;

			this->setWalkSpeed(224);

			_originSpeed=224;

			if(strcmp(this->getMaster()->getRole()->getCString(),"Player")==0){
				if(this->_delegate->getHudLayer()->skill2Button){
					this->_delegate->getHudLayer()->skill2Button->unLock();
				}

			}
		

		}


	}else if(strcmp(this->_character->getCString(),"Kakuzu")==0 &&  _skillChangeBuffValue){	
		this->unschedule(schedule_selector(ActionManager::resumeAction));
		this->removeBuffEffect("sBuff");	

		_skillChangeBuffValue=NULL;

	}else if(strcmp(this->_character->getCString(),"Tobi")==0 && _skillChangeBuffValue){

		this->unschedule(schedule_selector(ActionManager::resumeAction));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));

		if (this->getOpacity()!=255){
			this->setOpacity(255);
		}

		
		this->setWalkSpeed(224);
		
		_originSpeed=224;

		_skillChangeBuffValue=NULL;

	}else if(strcmp(this->_character->getCString(),"Kiba")==0 ){

		if(_powerUPBuffValue){
			this->unschedule(schedule_selector(ActionManager::resumeAction));
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())-_powerUPBuffValue));
			_powerUPBuffValue=NULL;
		}
		_isBati=true;		
		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			_delegate->getHudLayer()->skill1Button->unLock();
			_delegate->getHudLayer()->skill2Button->setLock();
			_delegate->getHudLayer()->skill3Button->setLock();
		}
		if(_hpBar){
		_hpBar->setPositionY(this->getHeight());
		}

		if(_actionState==ACTION_STATE_IDLE||
			_actionState==ACTION_STATE_WALK ||
			_actionState==ACTION_STATE_ATTACK
			){
				_actionState=ACTION_STATE_WALK;
				this->idle();
		}


		_skillChangeBuffValue=NULL;

	}else if(strcmp(this->_character->getCString(),"Hiruzen")==0 && _skillChangeBuffValue){

		_isBati=false;
		_isOnlySkillLocked=false;
		if(_tempAttackValue1){
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
			_tempAttackValue1=NULL;
		}
		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}

		_skillChangeBuffValue=NULL;
		

	}else if(strcmp(this->_character->getCString(),"Kankuro")==0){
			
			if(strcmp(this->_role->getCString(),"Player")==0){				
				_delegate->getHudLayer()->skill1Button->unLock();
				_delegate->getHudLayer()->skill2Button->setLock();
			}
			_skillChangeBuffValue=NULL;

	}else if(strcmp(this->_character->getCString(),"Chiyo")==0){

		if(strcmp(this->_role->getCString(),"Player")==0){	
			_delegate->getHudLayer()->skill1Button->unLock();
			_delegate->getHudLayer()->skill2Button->setLock();
			_delegate->getHudLayer()->skill3Button->setLock();
		}
		_skillChangeBuffValue=NULL;
	}else if(strcmp(this->_character->getCString(),"Minato")==0){
		this->setSkill1Action(createAnimation(skill1Array,10.0f,false,true));
		_skillChangeBuffValue=NULL;
	}else if((strcmp(this->_character->getCString(),"Sasuke")==0||
		strcmp(this->_character->getCString(),"ImmortalSasuke")==0) && this->_isTaunt){

			this->unschedule(schedule_selector(ActionManager::resumeAction));
			this->_isTaunt=false;
			this->setHurtAction(createAnimation(hurtArray,10.0f,false,true));
			_skillChangeBuffValue=NULL;

	}else if(strcmp(this->_character->getCString(),"ImmortalSasuke")==0  &&  _skillChangeBuffValue ){
		if(_skillChangeBuffValue==18){

			this->unschedule(schedule_selector(ActionManager::resumeAction));

			this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
			this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
			this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

			this->_isOnlySkillLocked=false;
			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->unLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->unLock();
				}
			}

			
			this->setWalkSpeed(224);
			
			_originSpeed=224;
			if(_tempAttackValue1){
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));
				_tempAttackValue1=NULL;
			
			}	
		_gardValue-=5000;
			_isBati=false;

			_nattackRangeX=16;
			_nattackRangeY=48;

			_skillChangeBuffValue=NULL;
		}
		

	}else if(strcmp(this->_character->getCString(),"Itachi")==0 && _skillChangeBuffValue){

		if(_skillChangeBuffValue==17){

			this->unschedule(schedule_selector(ActionManager::resumeAction));

			this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
			this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
			this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
			this->setKnockDownAction(createAnimation(knockDownArray,10.0f,false,true));

			this->_isOnlySkillLocked=false;
			if(strcmp(this->getRole()->getCString(),"Player")==0){
				if(_delegate->getHudLayer()->skill4Button){
					_delegate->getHudLayer()->skill4Button->unLock();
				}
				if(_delegate->getHudLayer()->skill5Button){
					_delegate->getHudLayer()->skill5Button->unLock();
				}
			}
			
			this->setWalkSpeed(224);
			
			_originSpeed=224;
			if(_tempAttackValue1){
			this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_tempAttackValue1->getCString())));		
			_tempAttackValue1=NULL;
			}
			_nattackRangeX=16;
			_nattackRangeY=48;
			_gardValue-=5000;
			_isBati=false;

			_skillChangeBuffValue=NULL;

		}
		

	}else if(strcmp(this->_character->getCString(),"Choji")==0 && _skillChangeBuffValue){

		this->unschedule(schedule_selector(ActionManager::resumeAction));

		this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())-460));
		_nattackRangeX=16;
		_nattackRangeY=48;
		_nattackType=_tempAttackType;
		_tempAttackType=NULL;

		this->_isOnlySkillLocked=false;
		_isBati=false;
		this->_gardValue-=5000;

		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}

		if(_hpBar){
			_hpBar->setPositionY(this->getHeight());
		}

		_skillChangeBuffValue=NULL;


	}else if(strcmp(this->_character->getCString(),"Gaara")==0 && _skillChangeBuffValue){
		this->unschedule(schedule_selector(ActionManager::resumeAction));
		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));

		this->_isOnlySkillLocked=false;

		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}
		_gardValue-=5000;
		_isBati=false;
		_skillChangeBuffValue=NULL;

		if(_hpBar){
			_hpBar->setPositionY(this->getHeight());
		}

	}else if(strcmp(this->_character->getCString(),"Ino")==0){

		this->unschedule(schedule_selector(ActionManager::resumeAction));
		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			Hero* tempHero=(Hero*) pObject;
			if(tempHero->_isControled){
				tempHero->_isControled=false;
				tempHero->changeGroup();
				if(strcmp(tempHero->getRole()->getCString(),"Player")==0){
					tempHero->unschedule(schedule_selector(ActionManager::setAI));
					tempHero->_isAI=false;
					this->_delegate->getHudLayer()->_isAllButtonLocked=false;
				}
				if(strcmp(this->getRole()->getCString(),"Player")==0){
					this->_delegate->controlChar=NULL;
				}
				tempHero->_controler=NULL;
			}
		};

		_isBati=false;

	}else if(strcmp(this->_character->getCString(),"Hidan")==0 && _skillChangeBuffValue){

		this->unschedule(schedule_selector(ActionManager::resumeAction));
		_isBati=false;
		_isTaunt=false;
		this->_isOnlySkillLocked=false;
		if(strcmp(this->getRole()->getCString(),"Player")==0){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
			if(_delegate->getHudLayer()->skill5Button){
				_delegate->getHudLayer()->skill5Button->unLock();
			}
		}
		this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
		this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
		this->setWalkAction(createAnimation(walkArray,10.0f,true,false));

		if(this->getMonsterArray() && getMonsterArray()->count()>0){
			CCObject* pObject;
			CCARRAY_FOREACH(this->getMonsterArray(),pObject){
				ActionManager* mo=(ActionManager*) pObject;
				//清除角色表的monter
				int index=_delegate->_CharacterArray->indexOfObject(mo);
				if(index>=0){
					_delegate->_CharacterArray->removeObjectAtIndex(index);
				}
				mo->setActionState(ACTION_STATE_DEAD);
				CCNotificationCenter::sharedNotificationCenter()->removeObserver(mo,"acceptAttack");
				mo->removeFromParent();	
				mo=NULL;

			};
			this->getMonsterArray()->removeAllObjects();
			_monsterArray=NULL;
		}

		if(strcmp(this->getRole()->getCString(),"Player")==0 ){
			this->_delegate->getHudLayer()->skill1Button->unLock();
		}

		if(_actionState!=ACTION_STATE_DEAD){
			_actionState=ACTION_STATE_WALK;
			this->idle();
		}

		_skillChangeBuffValue=NULL;

	}else if(strcmp(this->_character->getCString(),"Deidara")==0 ||
		strcmp(this->_character->getCString(),"Sai")==0
		){

		if(_skillChangeBuffValue){
			this->unschedule(schedule_selector(ActionManager::resumeAction));

			if(_skillChangeBuffValue==17){
				this->setNAttackAction(createAnimation(nattackArray,10.0f,false,true));
			}else if(_skillChangeBuffValue==18){

				this->_isBati=false;
				this->_isAllAttackLocked=false;
				_originSpeed=224;

				
				this->setWalkSpeed(224);

				if(strcmp(this->getRole()->getCString(),"Player")==0){
					if(_delegate->getHudLayer()->skill4Button){
						_delegate->getHudLayer()->skill4Button->unLock();
					}
					if(_delegate->getHudLayer()->skill5Button){
						_delegate->getHudLayer()->skill5Button->unLock();
					}
				}

				this->setIdleAction(createAnimation(idleArray,5.0f,true,false));
				this->setWalkAction(createAnimation(walkArray,10.0f,true,false));

				if(_hpBar){
					_hpBar->setPositionY(this->getHeight());
				}
				this->unschedule(schedule_selector(ActionManager::setMonPer));
			}

			_skillChangeBuffValue=NULL;
		}
		
	}



}

void ActionManager::setActionResume2(){

	if(strcmp(this->_character->getCString(),"Minato")==0){
		this->setSkill2Action(createAnimation(skill2Array,10.0f,false,true));
	}
}


void ActionManager::getCollider(){
	this->schedule(schedule_selector(ActionManager::stopMove),0.0f);
	
}

void ActionManager::stopMove(float dt){

	if(this->getPositionX()<=_delegate->currentMap->getTileSize().width ||
		this->getPositionX()>=(_delegate->currentMap->getMapSize().width-1)*_delegate->currentMap->getTileSize().width){
			this->unschedule(schedule_selector(ActionManager::stopMove));
			this->getActionManager()->removeAction(_moveAction);
			return;
	};

	CCObject* pObject;
	CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
		Hero* tempHero=(Hero*) pObject;
		if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
			&& tempHero->_isVisable
			&& tempHero->_actionState!=ACTION_STATE_DEAD
			&& tempHero->_actionState!=ACTION_STATE_JUMP
			&& !tempHero->_isWudi
			){
			float distanceX=ccpSub(tempHero->getPosition(),this->getPosition()).x;
			float tempRange1=_attackRangeX+this->getContentSize().width/2;
			if(abs(distanceX)<=tempRange1 &&
				abs(tempHero->getPositionY()-this->getPositionY())<=this->_attackRangeY){
					this->unschedule(schedule_selector(ActionManager::stopMove));
					this->getActionManager()->removeAction(_moveAction);
					return;
			}

		}
	};
}

void ActionManager::stopJump(CCNode* sender,void* date){
	int stopTime=(int) date;

	if(_actionState==ACTION_STATE_JUMP){
		this->getActionManager()->pauseTarget(this);
		this->scheduleOnce(schedule_selector(ActionManager::resumePauseStuff),float(stopTime)/100);
	}
}

void ActionManager::setBullet(CCNode* sender,void* date){
	CCDictionary* file=(CCDictionary*) date;
	CCString* str = (CCString*)(file->objectForKey(1));
	CCString* bulletType=str;

	Bullet* bullet=Bullet::create();
	bullet->setDelegate(_delegate);
	bullet->setID(bulletType,CCString::create("Bullet"),this->_group);
	bullet->idle();
	if (_master){
		bullet->_master=this->_master;
	}else{
		bullet->_master=(Hero*) this;
	}
	
	if(this->_isFlipped){
		bullet->setFlipX(true);
		bullet->_isFlipped=true;
	}

	

	_delegate->addChild(bullet,-this->getPositionY());

	if(strcmp(bulletType->getCString(),"PaperSrk")==0){
			bullet->setScale(0.8f);
			bullet->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-32:32),
				this->getPositionY()+52));
			bullet->attack(NAttack);
			bullet->setMove(192,2.0f,false);
	}else if(strcmp(bulletType->getCString(),"PaperSpear")==0){
		bullet->setScale(0.8f);
		bullet->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-68:68),
			this->getPositionY()+42));
		bullet->attack(NAttack);
		bullet->setMove(192,2.0f,false);

	}else if(strcmp(bulletType->getCString(),"HugeSRK")==0){
		float rangeX=76;

		bullet->setScale(0.8f);
		bullet->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-rangeX:rangeX),
			this->getPositionY()+this->getHeight()/2));
		if(this->_skillUPBuffValue){
			bullet->setnAttackValue(CCString::createWithFormat("%d",atoi(bullet->_nattackValue->getCString())+this->_skillUPBuffValue));

		}

		bullet->scheduleOnce(schedule_selector(Bullet::setAttack),0.5f);
		this->scheduleOnce(schedule_selector(ActionManager::setBulletGroup),0.2f);
		bullet->setEaseIn(224,5.0f);
	}
	else if(strcmp(bulletType->getCString(),"FlyKnife")==0||
		strcmp(bulletType->getCString(),"TentenSRK")==0 
		){
		bullet->setScale(0.8f);
			bullet->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-32:32),
				this->getPositionY()+this->getHeight()/2));
		
		bullet->setEaseIn(224,2.0f);
		bullet->attack(NAttack);

	}else if(strcmp(bulletType->getCString(),"HiraishinKunai")==0 ||
		strcmp(bulletType->getCString(),"Shintenshin")==0
		){

		if(!_monsterArray){
			_monsterArray=CCArray::create();
			_monsterArray->retain();
		}
		if(strcmp(bulletType->getCString(),"HiraishinKunai")==0){
			bullet->setScale(0.8f);
			bullet->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-42:42),
				this->getPositionY()+this->getHeight()/2));
		}else{
			bullet->setAnchorPoint(ccp(0.5f,0));
			bullet->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-42:42),
				this->getPositionY()));
		}
		
		
		bullet->_originY=this->getPositionY();
		bullet->setEaseIn(196,2.0f);
		bullet->attack(NAttack);
		_monsterArray->addObject(bullet);
	}else{

		
		bullet->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-32:32),
			this->getPositionY()+this->getContentSize().height/2));
		
		bullet->attack(NAttack);
		bullet->setMove(192,2.0f,false);
			
		
	}

}

void ActionManager::setBulletGroup(float dt){
	for(int i=0;i<2;i++){
		Bullet* bullet=Bullet::create();
		bullet->setDelegate(_delegate);
		float rangeX=0;
		
		bullet->setID(CCString::create("HugeSRK"),CCString::create("Bullet"),this->_group);
		rangeX=76;
		
		bullet->_master=(Hero*) this;
		bullet->setScale(0.8f);
		
		if(this->_isFlipped){
			bullet->setFlipX(true);
			bullet->_isFlipped=true;
		}
		if(i==0){
			CCPoint location=ccp(this->getPositionX()+(_isFlipped?-rangeX:rangeX),this->getPositionY()+(this->getHeight()/2+23));
			bullet->setPosition(location);
		}else{
			CCPoint location=ccp(this->getPositionX()+(_isFlipped?-rangeX:rangeX),this->getPositionY()+(this->getHeight()/2-23));
			bullet->setPosition(location);
		}
		_delegate->addChild(bullet,currentSkillTag);
		bullet->idle();
		if(this->_skillUPBuffValue){
			bullet->setnAttackValue(CCString::createWithFormat("%d",atoi(bullet->_nattackValue->getCString())+this->_skillUPBuffValue));
		}

		bullet->scheduleOnce(schedule_selector(Bullet::setAttack),0.5f);
		bullet->setEaseIn(352,5.0f);
	}

}



void ActionManager::setClone(CCNode* sender,void* date){
	int cloneTime=(int) date;
	Hero* clone=Hero::create();
	
	if(this->_master){
		clone->setMaster((Hero*)this);
		clone->setSecMaster(this->_master);

	}else{
		clone->setMaster((Hero*)this);
	}
			
	clone->setDelegate(_delegate) ;
	clone->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-32:32),this->getPositionY()-1));
	if(strcmp(this->getCharacter()->getCString(),"Nagato")==0){

		clone->setID(CCString::create("DevaPath"),CCString::create("Clone"),this->_group);
		clone->_isBati=true;		
		if(strcmp(this->getRole()->getCString(),"Player")==0 ){
			if(this->_delegate->getHudLayer()->skill5Button){
				this->_delegate->getHudLayer()->skill5Button->setLock();
			}
			
		}

		_skillChangeBuffValue=100;

	}else if(strcmp(this->getCharacter()->getCString(),"Kakuzu")==0){
		if(!_monsterArray){
			_monsterArray=CCArray::create();
			_monsterArray->retain();
		}
		bool isRaidon=false;
		bool isFudon=false;
		bool isKadon=false;
		int countMon=0;
		if(getMonsterArray() && getMonsterArray()->count()>0){
			CCObject* pObject;
			CCARRAY_FOREACH(getMonsterArray(),pObject){
				Monster* mo=(Monster*) pObject;
				if (strcmp(mo->getCharacter()->getCString(),"MaskRaidon")==0){
					countMon++;
					isRaidon=true;
				}
				if (strcmp(mo->getCharacter()->getCString(),"MaskFudon")==0){
					countMon++;
					isFudon=true;
				}
				if (strcmp(mo->getCharacter()->getCString(),"MaskKadon")==0){
					countMon++;
					isKadon=true;
				}

			};
		}

		if(this->hearts>0 &&  (!isRaidon || !isKadon || !isFudon)){
			if(!isRaidon){
				clone->setID(CCString::create("MaskRaidon"),CCString::create("Kuilei"),this->_group);
			}else if(!isFudon){
				clone->setID(CCString::create("MaskFudon"),CCString::create("Kuilei"),this->_group);
			}else if(!isKadon){
				clone->setID(CCString::create("MaskKadon"),CCString::create("Kuilei"),this->_group);

			}	
			clone->_isBati=true;
			_monsterArray->addObject(clone);
			
			this->hearts-=1;
			if(this->_heartEffect){
				CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("Heart_Effect_%02d.png",this->hearts)->getCString()); 
				this->_heartEffect->setDisplayFrame(frame);
			}
			
			if(this->hearts<1 || countMon >=2){
				
				if(strcmp(this->getRole()->getCString(),"Player")==0){
					if(_delegate->getHudLayer()->skill4Button){
						_delegate->getHudLayer()->skill4Button->setLock();
					}
				}

			}

		}else{
			clone=NULL;
			return;
		}

	 }else if(strcmp(this->getCharacter()->getCString(),"Kankuro")==0){

		if(!_monsterArray){
			_monsterArray=CCArray::create();
			_monsterArray->retain();
		}
		if(cloneTime==0){
			clone->setID(CCString::create("Karasu"),CCString::create("Kuilei"),this->_group);
		}else if(cloneTime==1){
			clone->setID(CCString::create("Sanshouuo"),CCString::create("Kuilei"),this->_group);
			if(strcmp(this->getRole()->getCString(),"Player")==0 ){
				if(this->_delegate->getHudLayer()->skill4Button){
					this->_delegate->getHudLayer()->skill4Button->setLock();
				}
				
			}
		}else if(cloneTime==2){
			clone->setID(CCString::create("Saso"),CCString::create("Kuilei"),this->_group);
			if(strcmp(this->getRole()->getCString(),"Player")==0 ){
				if(this->_delegate->getHudLayer()->skill5Button){
				this->_delegate->getHudLayer()->skill5Button->setLock();
				}
			}
		}
		clone->_isBati=true;
		_monsterArray->addObject(clone);

	}else if(strcmp(this->getCharacter()->getCString(),"Chiyo")==0){

		if(!_monsterArray){
			_monsterArray=CCArray::create();
			_monsterArray->retain();
		}
	
		clone->setID(CCString::create("Parents"),CCString::create("Kuilei"),this->_group);
		clone->setPosition(ccp(this->getPositionX(),this->getPositionY()-3));
		clone->_isBati=true;
		_monsterArray->addObject(clone);

	 }else if(strcmp(this->getCharacter()->getCString(),"Kiba")==0){

		if(!_monsterArray){
			_monsterArray=CCArray::create();
			_monsterArray->retain();
		}

		clone->setID(CCString::create("Akamaru"),CCString::create("Clone"),this->_group);
		clone->_isBati=true;
		_monsterArray->addObject(clone);
	
	}else if(strcmp(this->getCharacter()->getCString(),"DevaPath")==0){
		if(!_monsterArray){
			_monsterArray=CCArray::create();
			_monsterArray->retain();
		}
		if(cloneTime==0){
			clone->setID(CCString::create("AnimalPath"),CCString::create("Summon"),this->_group);
		}else{
			clone->setID(CCString::create("AsuraPath"),CCString::create("Summon"),this->_group);
		}
		_monsterArray->addObject(clone);
		clone->_isBati=true;
	}else if(strcmp(this->getCharacter()->getCString(),"Tsunade")==0){
		clone->setID(CCString::create("Slug"),CCString::create("Summon"),this->_group);
		clone->_isBati=true;
	}else if(strcmp(this->getCharacter()->getCString(),"Kakashi")==0){
		clone->setID(CCString::create("DogWall"),CCString::create("Summon"),this->_group);
			clone->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-56:56),this->getPositionY()));
		clone->setAnchorPoint(ccp(0.5f,0.1f));
		clone->_isBati=true;
	}else if(strcmp(this->getCharacter()->getCString(),"Deidara")==0){
		clone->setID(CCString::create("Centipede"),CCString::create("Summon"),this->_group);
		clone->_isBati=true;
	}else if(strcmp(this->getCharacter()->getCString(),"Naruto")==0){
		clone->setID(this->getCharacter(),CCString::create("Clone"),this->_group);
		
	}else if(strcmp(this->getCharacter()->getCString(),"SageNaruto")==0||
		(strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 && cloneTime==10)
		){
		//鸣人
		clone->setID(this->getCharacter(),CCString::create("Clone"),this->_group);
		clone->setSkill1Action(clone->createAnimation(clone->skillSPC1Array,10.0f,false,true));	
		clone->_sattackValue1=_spcattackValue1;
		clone->_sattackType1=_spcattackType1;
		clone->_sattackcoldDown1=_spcattackcoldDown1;

	}else if(strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 && cloneTime==9){
		clone->setID(CCString::create("Kurama"),CCString::create("Clone"),this->_group);
		clone->_gardValue+=5000;
		clone->_isBati=true;	
		clone->setWalkSpeed(320);
		clone->_originSpeed=320;
		clone->isPofang=true;

	}


	if(strcmp(this->getCharacter()->getCString(),"SageNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"Naruto")==0||
		(strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 && cloneTime==10)
		){
		clone->setHP(CCString::create(this->getHP()->getCString()));
		
	}else{	
		clone->setHP(CCString::create(this->getMaxHP()->getCString()));
	}

	clone->setMaxHP(CCString::create(this->getMaxHP()->getCString()));
	clone->_exp=this->_exp;
	clone->setnAttackValue(CCString::createWithFormat("%d",atoi(this->getnAttackValue()->getCString())));
	clone->_gardValue=this->_gardValue;
	clone->_level=this->_level;
	clone->setHPbar();
	clone->_hpBar->getHPBAR()->setScaleX(clone->getHpPercent());
	
	if(strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 && cloneTime==9){
		if(clone->_hpBar){
			clone->_hpBar->setPositionY(120);
		}
		clone->setnAttackValue(CCString::createWithFormat("1060"));
	}else if(strcmp(this->getCharacter()->getCString(),"Kakashi")==0){
		clone->setnAttackValue(CCString::createWithFormat("1060"));
	}

	if(this->isPofang){
		clone->isPofang=true;
	}

	if(isHujia){
		clone->isHujia=true;
	}


	
	clone->setFlipX(this->_isFlipped);
	clone->_isFlipped=this->_isFlipped;
	CCDictionary* callValue = CCDictionary::create(); 
	callValue->setObject(CCString::create("smk"), 1);
	clone->setSkillEffect(clone,callValue);
	clone->idle();
	_delegate->_CharacterArray->addObject(clone);
	_delegate->addChild(clone,-clone->getPositionY());
	clone->doAI();
	


	if(strcmp(this->getCharacter()->getCString(),"Naruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"SageNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"Kakashi")==0 ||
		strcmp(this->getCharacter()->getCString(),"RikudoNaruto")==0 ||
		strcmp(this->getCharacter()->getCString(),"Tsunade")==0 ||
		strcmp(this->getCharacter()->getCString(),"Deidara")==0
		){
		clone->scheduleOnce(schedule_selector(Hero::removeClone),float(cloneTime));	
	}
	
}

void ActionManager::removeClone(float dt){
	this->dead();
}


void ActionManager::setMon(CCNode* sender,void* date){


	CCDictionary* file=(CCDictionary*) date;
	CCString* str = (CCString*)(file->objectForKey(1));
	CCString* monsterType=str;



	float monsterStayTime=_attackRangeY;
	
	if(!_monsterArray){
		_monsterArray=CCArray::create();
		_monsterArray->retain();
	}


	Monster* monster=Monster::create();
	monster->setDelegate(_delegate);


	monster->setID(monsterType,CCString::create("Mon"),this->_group);
	

	if(this->getMaster()){
		if(this->getSecMaster() ){
			monster->setMaster((Hero*)this);
			monster->setSecMaster(this->getSecMaster());
		}else{
			monster->setMaster(this->getMaster());
			monster->setSecMaster((ActionManager*)this);
		}
		
	}else{
		monster->setMaster((Hero*)this);
	}

	monster->idle();
	monster->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-32:32),this->_originY?this->_originY:this->getPositionY()));
	monster->setFlipX(_isFlipped);
	monster->_isFlipped=_isFlipped;

	
	

	if(strcmp(monsterType->getCString(),"FakeDeidara")==0 ||
		strcmp(monsterType->getCString(),"FakeKisame")==0 ||
		strcmp(monsterType->getCString(),"DeidaraBom")==0 ||
		strcmp(monsterType->getCString(),"ChuiDi")==0 ||
		strcmp(monsterType->getCString(),"SakuraBom")==0 ||
		strcmp(monsterType->getCString(),"Shoryu")==0 ||
		strcmp(monsterType->getCString(),"Stream")==0 ||		
		strcmp(monsterType->getCString(),"FakeMinato")==0
		){
	
			monster->setPosition(ccp(this->getPositionX(),this->_originY?_originY:this->getPositionY()));
			_monsterArray->addObject(monster);
			monster->attack(NAttack);

	}else if(	strcmp(monsterType->getCString(),"LeeBom")==0 ){
		//monster->setAnchorPoint(ccp(0.5,0.5f));
		monster->setPosition(ccp(this->getPositionX(),this->getPositionY()));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);

	}else if(strcmp(monsterType->getCString(),"FakeItachi")==0){
		monster->setPosition(ccp(this->getPositionX(),this->_originY?_originY:this->getPositionY()-4));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);
		
	}else if(strcmp(monsterType->getCString(),"Tenmu")==0 ){
		monster->setPosition(ccp(this->getPositionX(),this->_originY));
		monster->setAnchorPoint(ccp(0.5,-0.1f));
		monster->attack(NAttack);

	}else if(strcmp(monsterType->getCString(),"Kaiten")==0 ){

		monster->setPosition(ccp(this->getPositionX(),this->getPositionY()));
		monster->setAnchorPoint(ccp(0.5,0.25f));
		monster->attack(NAttack);

	}else if(strcmp(monsterType->getCString(),"Crash")==0 ||
		strcmp(monsterType->getCString(),"Crash2")==0
		){
		monster->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-32:32),this->_originY?this->_originY:this->getPositionY()));
		monster->setAnchorPoint(ccp(0.5,0.25f));
		monster->attack(NAttack);

	}else if(strcmp(monsterType->getCString(),"SansyoRed")==0){
		
		monster->setPosition(ccp(_isFlipped?this->getPositionX()-240:this->getPositionX()+240,this->getPositionY()-32));
		monster->attack(NAttack);
	
	}else if(strcmp(monsterType->getCString(),"SansyoGreen")==0){
		
		monster->setPosition(ccp(_isFlipped?this->getPositionX()-144:this->getPositionX()+144,this->getPositionY()-32+1));
		monster->attack(NAttack);

	}else if(strcmp(monsterType->getCString(),"SansyoBlue")==0){

		monster->setPosition(ccp(_isFlipped?this->getPositionX()-48:this->getPositionX()+48,this->getPositionY()-32+2));
		monster->attack(NAttack);

	}else if(strcmp(monsterType->getCString(),"SmallSlug")==0){

		if(_monsterArray && _monsterArray->count()<3){
			CCDictionary* callValue = CCDictionary::create(); 
			callValue->setObject(CCString::create("smk"), 1);
			monster->setSkillEffect(monster,callValue);
			_monsterArray->addObject(monster);
			monster->doAI();
		}else{
			monster=NULL;
			return;
		}

	}else if(strcmp(monsterType->getCString(),"Kuroari")==0){
		CCDictionary* callValue = CCDictionary::create(); 
		callValue->setObject(CCString::create("smk"), 1);
		monster->setSkillEffect(monster,callValue);
		_monsterArray->addObject(monster);
		monster->doAI();
	}else if (strcmp(monsterType->getCString(),"PaperRain")==0 ||
		strcmp(monsterType->getCString(),"Steam")==0 ){
		monster->setPosition(ccp(_isFlipped?this->getPositionX()-16:this->getPositionX()+16,this->_originY));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);
	}else if (strcmp(monsterType->getCString(),"FireRain")==0 
		){
		monster->setPosition(ccp(_isFlipped?this->getPositionX()-75:this->getPositionX()+75,this->_originY-1));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);
	}
	else if(strcmp(monsterType->getCString(),"Tuji")==0||
		strcmp(monsterType->getCString(),"Tuji2")==0 ||
		strcmp(monsterType->getCString(),"Suiji")==0 
		){
		monster->setPositionY(this->getPositionY()-24);
		monster->setPositionX(this->getPositionX()+(_isFlipped?-64:64));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);
	}else if(strcmp(monsterType->getCString(),"ThunderWave")==0){
		monster->setPosition(ccp(this->getPositionX(),this->getPositionY()-1));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);
	}else if(strcmp(monsterType->getCString(),"Jibaku")==0||
		strcmp(monsterType->getCString(),"JibakuEX")==0||
		strcmp(monsterType->getCString(),"Shenwei")==0 
		){
	    monster->setPosition(ccp(this->getPositionX()+(_isFlipped?-96:96),this->getPositionY()));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);

	}else if(strcmp(monsterType->getCString(),"Bikyu")==0){
		monster->setFlipX(_isFlipped);
		monster->isPofang=true;
		monster->setPosition(ccp(this->getPositionX()+(_isFlipped?-(16+this->getContentSize().width):
		(16+this->getContentSize().width)),this->getPositionY()-32));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);
	}else if( strcmp(monsterType->getCString(),"Qilin")==0){
		monster->setPosition(ccp(this->getPositionX()+(_isFlipped?-4:4),this->getPositionY()-6));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);
	}else if(strcmp(monsterType->getCString(),"SuiRyuDan")==0 ||
		strcmp(monsterType->getCString(),"TodonPillar")==0 	||
		strcmp(monsterType->getCString(),"Yataikuzu")==0  ||
		strcmp(monsterType->getCString(),"Yominuma")==0	||	
		strcmp(monsterType->getCString(),"Dogs")==0 ||
		strcmp(monsterType->getCString(),"SandHand")==0 ||
		strcmp(monsterType->getCString(),"KageFeng")==0||
		strcmp(monsterType->getCString(),"Sanbao")==0||
		strcmp(monsterType->getCString(),"SandBall")==0 ||
		strcmp(monsterType->getCString(),"Sabaku")==0 ||
		strcmp(monsterType->getCString(),"SandWave")==0 ||
		strcmp(monsterType->getCString(),"Tsukuyomi")==0 ||
		strcmp(monsterType->getCString(),"Shark")==0 
		){
			monster->setPosition(ccp(this->getPositionX()+(this->_isFlipped==true?-48:48),this->getPositionY()-4));
			monster->attack(NAttack);

	}else if (strcmp(monsterType->getCString(),"Suijin")==0||
		strcmp(monsterType->getCString(),"BugPillar")==0 ){
		monster->setPosition(ccp(this->getPositionX()+(this->_isFlipped==true?-64:64),this->getPositionY()+1));
		monster->attack(NAttack);
	}else if ( strcmp(monsterType->getCString(),"Mine")==0 ){
		CCDictionary* callValue = CCDictionary::create(); 
		callValue->setObject(CCString::create("smk"), 1);
		monster->setSkillEffect(monster,callValue);
		_monsterArray->addObject(monster);
		monster->doAI();
		if(strcmp(this->getGroup()->getCString(),_delegate->currentPlayer->getGroup()->getCString())!=0){
			monster->setVisible(false);
		}
	}else if( strcmp(monsterType->getCString(),"Kage")==0){
		this->_isCatchOne=true;
		monster->setPosition(ccp(this->getPositionX()+(_isFlipped?-this->getContentSize().width/2+4:
			this->getContentSize().width/2-4),this->getPositionY()));
		if(_isFlipped){
			monster->setAnchorPoint(ccp(1,0));
		}else{
			monster->setAnchorPoint(ccp(0,0));
		}
		
		this->stopAllActions();
		_monsterArray->addObject(monster);
		monster->attack(NAttack);
		monster->doAI();
		
	}else if( strcmp(monsterType->getCString(),"KageHand")==0){
		CCPoint dir=CCPointMake(_isFlipped?this->getPositionX()- this->getContentSize().width:this->getPositionX()+ this->getContentSize().width,this->getPositionY());
		monster->setPosition(dir);
		this->stopAllActions();
		
		if(this->getMaster()){
			_master->_monsterArray->addObject(monster);
		}
		monster->attack(NAttack);
	}else if(strcmp(monsterType->getCString(),"KageHands")==0){

		if(this->getMaster()){
			_master->_monsterArray->addObject(monster);
		}

		monster->setPosition(ccp(this->getPositionX(),this->getPositionY()));
		monster->setAnchorPoint(ccp(0.5f,0.15f));
		monster->attack(NAttack);

	}else if (strcmp(monsterType->getCString(),"QuanRen")==0 ){
		monster->setPosition(ccp(_isFlipped?this->getPositionX()-64:this->getPositionX()+64,this->_originY));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);
	}else if (strcmp(monsterType->getCString(),"ItachiSusano")==0 ||
		strcmp(monsterType->getCString(),"SasukeSusano")==0
		){
		_monsterArray->addObject(monster);
	}else if(strcmp(monsterType->getCString(),"HiraishinMark")==0){
		_monsterArray->addObject(monster);
		this->_isCanSkill1=true;

	}else if(strcmp(monsterType->getCString(),"CircleMark")==0){
		monster->setPosition(ccp(this->getPositionX(),this->getPositionY()));
		monster->setAnchorPoint(ccp(0.5f,0.5f));
		_monsterArray->addObject(monster);
		monster->attack(NAttack);

		if(strcmp(this->getRole()->getCString(),"Player")==0 ){
			this->_delegate->getHudLayer()->skill1Button->setLock();
		}
	}else if(strcmp(monsterType->getCString(),"InkDragon")==0 ){
		monster->setPosition(ccp(_isFlipped?this->getPositionX()-128:this->getPositionX()+128,this->getPositionY()));
		monster->attack(NAttack);
		monster->setDirectMove(156,2.0f,false);
	}else if(strcmp(monsterType->getCString(),"BugTomado")==0 ){
		monster->attack(NAttack);
		monster->setDirectMove(128,2.0f,false);
	}else if(strcmp(monsterType->getCString(),"FudonSRK2")==0 ||
		strcmp(monsterType->getCString(),"FudonSRK")==0 
		){
		monster->setPosition(ccp(this->getPositionX()+(this->_isFlipped==true?-48:48),this->getPositionY()));
	
		monster->attack(NAttack);	
		bool isFollow=false;
		CCPoint moveDirection;
		if(_mainTarget){

			if(_mainTarget->getPositionX()>this->getPositionX()&& !_isFlipped){
				isFollow=true;
			}else if(_mainTarget->getPositionX()<=this->getPositionX() && _isFlipped){
				isFollow=true;
			}
			
		}

		if(isFollow){
			monster->_mainTarget=this->_mainTarget;
			monster->doAI();

		}else{
			if(this->_isFlipped){
				moveDirection =ccpNormalize(ccp(-1,0));
			}else{
				moveDirection =ccpNormalize(ccp(1,0));
			}
			monster->setActionState(ACTION_STATE_WALK);
			monster->walk(moveDirection);

		}

		
	}else if(strcmp(monsterType->getCString(),"Kubi")==0
		){
			monster->attack(NAttack);
			monster->setDirectMove(128,0.8f,true);
	}else if(strcmp(monsterType->getCString(),"Shark2")==0
		){
			monster->attack(NAttack);
			monster->setEaseIn(224,3.0f);
	}else if(strcmp(monsterType->getCString(),"WaterBullet")==0 ||
		strcmp(monsterType->getCString(),"BoneBullet")==0 ||
		strcmp(monsterType->getCString(),"WaterBom")==0 
		){
		
			monster->attack(NAttack);
			monster->setEaseIn(224,1.0f);
		
	}else if(strcmp(monsterType->getCString(),"Hasan")==0){
		monster->attack(NAttack);
		monster->setAnchorPoint(ccp(0.5f,0.28f));
		monster->setPosition(ccp(this->getPositionX()+(this->_isFlipped==true?-24:24),this->getPositionY()));
			monster->setEaseIn(224,1.0f);

	}else if(strcmp(monsterType->getCString(),"Wave")==0){
		monster->attack(NAttack);
		monster->setAnchorPoint(ccp(0.5f,0.1f));
		monster->setPosition(ccp(this->getPositionX()+(this->_isFlipped==true?-24:24),this->getPositionY()));
		monster->setEaseIn(224,1.0f);

	}else if(strcmp(monsterType->getCString(),"InkBird")==0 ||
		strcmp(monsterType->getCString(),"FakeTobirama")==0||
		strcmp(monsterType->getCString(),"TamaBomb")==0  ||
		strcmp(monsterType->getCString(),"Shenwei2")==0 
		){
		_monsterArray->addObject(monster);
		monster->attack(NAttack);
	}else{
		_monsterArray->addObject(monster);
		monster->doAI();
	}


	if (strcmp(monsterType->getCString(),"ItachiSusano")==0){
		 monster->setFlipX(_isFlipped);
		monster->setAnchorPoint(ccp(0.5f,0));
		monster->setPosition(ccp(146/2-10,-40));
		this->addChild(monster,-1000);

	}else if( strcmp(monsterType->getCString(),"SasukeSusano")==0 ){
		monster->setFlipX(_isFlipped);
		monster->setAnchorPoint(ccp(0.5f,0));
		monster->setPosition(ccp(141/2,-6));
		this->addChild(monster,-1000);
	}else if( strcmp(monsterType->getCString(),"CircleMark")==0 ||
		strcmp(monsterType->getCString(),"Yominuma")==0
		){
		this->_delegate->addChild(monster,-5000);
	}else{
		this->_delegate->addChild(monster,-monster->getPositionY());

	}
	

}

void ActionManager::setMonPer(float dt){



	if(!_monsterArray){
		_monsterArray=CCArray::create();
		_monsterArray->retain();
	}


	Monster* monster=Monster::create();
	monster->setDelegate(_delegate);

	if(strcmp(this->getCharacter()->getCString(),"Deidara")==0){
		monster->setID(CCString::create("Spider"),CCString::create("Mon"),this->_group);
	}else if(strcmp(this->getCharacter()->getCString(),"Sai")==0){
		monster->setID(CCString::create("Mouse"),CCString::create("Mon"),this->_group);
		CCDictionary* callValue2 = CCDictionary::create(); 
		callValue2->setObject(CCString::create("Audio/Sai/ink_mouse.mp3"),1);
		this->setSound(this,callValue2); 
	}
	
	monster->setMaster((Hero*)this);
	

	monster->idle();
	monster->setPosition(ccp(this->getPositionX()+(this->_isFlipped?-32:32),this->_originY?this->_originY:this->getPositionY()));
	monster->setFlipX(_isFlipped);
	monster->_isFlipped=_isFlipped;

	
	_monsterArray->addObject(monster);
	monster->doAI();

	this->_delegate->addChild(monster,-monster->getPositionY());

}

void ActionManager::setTrap(CCNode* sender,void* date){
	
	CCDictionary* file=(CCDictionary*) date;
	CCString* str = (CCString*)(file->objectForKey(1));
	CCString* trapType=str;
	if(strcmp(trapType->getCString(),"Amaterasu")==0  ){

		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			ActionManager* tempHero=(ActionManager*) pObject;
			if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
				&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
				&& tempHero->_actionState!=ACTION_STATE_HURT
				&& tempHero->_actionState!=ACTION_STATE_DEAD
				){
					float distanceX=ccpSub(tempHero->getPosition(),this->getPosition()).x;
					if(distanceX<winSize.width/2){
						//取消隐身
						if(!tempHero->_isVisable){
							if(strcmp(tempHero->getCharacter()->getCString(),"Konan")==0 ||
								strcmp(tempHero->getCharacter()->getCString(),"Deidara")==0
								){
									tempHero->unschedule(schedule_selector(ActionManager::disableBuff));
							}


							tempHero->setOpacity(255);
							tempHero->setVisible(true);

							if(tempHero->_hpBar){
								tempHero->_hpBar->setVisible(true);
							}
							if(tempHero->_shadow){
								tempHero->_shadow->setVisible(true);
							}

							tempHero->_isVisable=true;
						}

					}

			}
		};


		if(strcmp(this->getCharacter()->getCString(),"ImmortalSasuke")==0){
			CCPoint targetPoint;
			if(_mainTarget){
				targetPoint=_mainTarget->getPosition();
			}else{
				targetPoint=this->getPosition();
			}

			for(int z=0;z<3;z++){
				if(z==0){
					
					Bullet* trap=Bullet::create();
					trap->setDelegate(_delegate);
					trap->_master=(Hero*)this;
					trap->setID(trapType,CCString::create("Mon"),_group);
					trap->setAnchorPoint(ccp(0.5,0));
					trap->setPosition(ccp(targetPoint.x,targetPoint.y+32));
					trap->idle();
					trap->attack(NAttack);
					trap->scheduleOnce(schedule_selector(Bullet::removeSelf),4.0f);
					this->_delegate->addChild(trap,-trap->getPositionY());

				}else if(z==1){
					for(int i=0;i<3;i++){
					Bullet* trap=Bullet::create();
					trap->setDelegate(_delegate);
					trap->_master=(Hero*)this;
					trap->setID(trapType,CCString::create("Mon"),_group);
					trap->setAnchorPoint(ccp(0.5,0));
					trap->setPosition(ccp(targetPoint.x+(i-1)*60,targetPoint.y));
					trap->idle();
					trap->attack(NAttack);
					trap->scheduleOnce(schedule_selector(Bullet::removeSelf),4.0f);
					this->_delegate->addChild(trap,-trap->getPositionY());
					}

				}else if(z==2){
				
					Bullet* trap=Bullet::create();
					trap->setDelegate(_delegate);
					trap->_master=(Hero*)this;
					trap->setID(trapType,CCString::create("Mon"),_group);
					trap->setAnchorPoint(ccp(0.5,0));
					trap->setPosition(ccp(targetPoint.x,targetPoint.y-32));
					trap->idle();
					trap->attack(NAttack);
					trap->scheduleOnce(schedule_selector(Bullet::removeSelf),4.0f);
					this->_delegate->addChild(trap,-trap->getPositionY());
				}
			}
			return;

		}
		
		for (int z=0;z<3;z++){
			if(z==0){
				for(int i=0;i<3;i++){
					Bullet* trap=Bullet::create();
					trap->setDelegate(_delegate);
					trap->_master=(Hero*)this;
					trap->setID(trapType,CCString::create("Mon"),_group);

					trap->setPosition(ccp(this->getPositionX()+(_isFlipped?-112:112),this->getPositionY()+(48-i*24)));
					trap->idle();
					trap->attack(NAttack);
					trap->scheduleOnce(schedule_selector(Bullet::removeSelf),2.5f);
					this->_delegate->addChild(trap,-trap->getPositionY());
				}


			}else if(z==1){

				for(int i=0;i<2;i++){
					Bullet* trap=Bullet::create();
					trap->setDelegate(_delegate);
					trap->_master=(Hero*)this;
					trap->setID(trapType,CCString::create("Mon"),_group);
					trap->setPosition(ccp(this->getPositionX()+(_isFlipped?-80:80),this->getPositionY()+(32-i*24)));
					trap->idle();
					trap->attack(NAttack);
					trap->scheduleOnce(schedule_selector(Bullet::removeSelf),2.5f);
					this->_delegate->addChild(trap,-trap->getPositionY());
				}

			}else{
				Bullet* trap=Bullet::create();
				trap->setDelegate(_delegate);
				trap->_master=(Hero*)this;
				trap->setID(trapType,CCString::create("Mon"),_group);
				trap->setPosition(ccp(this->getPositionX()+(_isFlipped?-48:48),this->getPositionY()+22));
				trap->idle();
				trap->attack(NAttack);
				trap->scheduleOnce(schedule_selector(Bullet::removeSelf),2.5f);
				this->_delegate->addChild(trap,-trap->getPositionY());

			}
			
		}

		
		
		

	}else if( strcmp(trapType->getCString(),"Kusuri")==0 ){
		for(int i=0;i<3;i++){
			Bullet* trap=Bullet::create();
			trap->setDelegate(_delegate);
			trap->setAnchorPoint(ccp(0.5f,0));
			trap->_master=(Hero*)this;
			trap->setID(trapType,CCString::create("Mon"),_group);

			if(i==0){
				trap->setPosition(ccp(this->getPositionX()+(_isFlipped?-24:
					24),this->getPositionY()-24));
			}else if(i==1){

				trap->setPosition(ccp(this->getPositionX()+(_isFlipped?24:
					-24),this->getPositionY()-24));
			}else if(i==2){
				trap->setPosition(ccp(this->getPositionX(),this->getPositionY()+24));
			}

			trap->attack(NAttack);
			this->_delegate->addChild(trap,-trap->getPositionY());

		}

	}else if(strcmp(trapType->getCString(),"KageBom")==0){

		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			Hero* tempHero=(Hero*) pObject;
			if(strcmp(this->_group->getCString(),tempHero->_group->getCString())!=0
				&& (strcmp(tempHero->_role->getCString(),"Player")==0 || strcmp(tempHero->_role->getCString(),"Com")==0)
				&& tempHero->_actionState!=ACTION_STATE_DEAD
				&& tempHero->_isVisable
				&& !tempHero->_isSticking
				){
					float distanceX=ccpSub(tempHero->getPosition(),this->getPosition()).x;
					float tempRange1=winSize.width/2;
					if(abs(distanceX)<=tempRange1){
						Monster* trap=Monster::create();
						trap->setDelegate(_delegate);
						trap->_master=(Hero*)this;
						trap->setID(trapType,CCString::create("Mon"),_group);
						trap->setPosition(ccp(tempHero->getPositionX(),tempHero->getPositionY()));
						trap->idle();
						trap->attack(NAttack);
						this->_delegate->addChild(trap,-trap->getPositionY());

					}
			}
		};


	}
};

void ActionManager::removeSelf(float dt){
	this->dealloc();
}

void ActionManager::setMonAttack(CCNode* sender,void* date){
	int skillNum=(int) date;
	if(this->getMonsterArray()){
		CCObject* pObject;
		CCARRAY_FOREACH(this->getMonsterArray(),pObject){
			Monster* mo=(Monster*) pObject;
			if(strcmp(mo->getCharacter()->getCString(),"Traps")!=0){

					if(strcmp(this->getCharacter()->getCString(),"Kiba")==0){
					mo->attack(SKILL1);
					}else if (strcmp(this->getCharacter()->getCString(),"Kankuro")==0){

						if (strcmp(mo->getCharacter()->getCString(),"Karasu")==0){
							if (skillNum==1){
								//mo->attack(SKILL1);
							}else if(skillNum==2){				
								mo->attack(SKILL2);
							}

						}

					}else if (strcmp(this->getCharacter()->getCString(),"Chiyo")==0){

						if (strcmp(mo->getCharacter()->getCString(),"Parents")==0){
							if (skillNum==1 && !mo->_skillChangeBuffValue){
								mo->attack(SKILL1);
							}else if(skillNum==2){				
								mo->attack(SKILL2);
							}

						}

					}else if(strcmp(this->getCharacter()->getCString(),"Itachi")==0||
						strcmp(this->getCharacter()->getCString(),"ImmortalSasuke")==0
						){
							if(this->_actionState==ACTION_STATE_ATTACK){
									mo->attack(NAttack);
							}

					}
			}
		};

	}else{
		return;
	}


};

void ActionManager::setTransform(){

	CCNotificationCenter::sharedNotificationCenter()->removeObserver(this,"acceptAttack");
	this->unschedule(schedule_selector(ActionManager::dehealBuff));

	if(strcmp(this->_character->getCString(),"Lee")==0 ||
		strcmp(this->_character->getCString(),"RockLee")==0
		){

			this->removeBuffEffect("dhBuff");

	}else{

		if(_skillUPBuffValue){
			this->unschedule(schedule_selector(ActionManager::disableBuff));
			this->disableBuff(0.1f);
		}

		this->removeBuffEffect("all");

	}
	

	int tempMaxHP=atoi(this->getMaxHP()->getCString());
	
	int tempHP=atoi(this->getHP()->getCString());
	CCString* tempAttackValue=CCString::createWithFormat("%s",this->getnAttackValue()->getCString());
	const char* charName;
	if(strcmp(_character->getCString(),"Naruto")==0){
		this->setID(CCString::create("SageNaruto"),_role,_group);
		charName="SageNaruto";
	}else if(strcmp(_character->getCString(),"SageNaruto")==0){
		this->setID(CCString::create("RikudoNaruto"),_role,_group);
		charName="RikudoNaruto";
	}else if(strcmp(_character->getCString(),"Jiraiya")==0){
		this->setID(CCString::create("SageJiraiya"),_role,_group);
		charName="SageJiraiya";
	}else if(strcmp(_character->getCString(),"Sasuke")==0){
		this->setID(CCString::create("ImmortalSasuke"),_role,_group);
		charName="ImmortalSasuke";
	}else if(strcmp(_character->getCString(),"Lee")==0){
		this->setID(CCString::create("RockLee"),_role,_group);
		charName="Lee";
	}else if(strcmp(_character->getCString(),"RockLee")==0){
		this->setID(CCString::create("Lee"),_role,_group);
		charName="Lee";
	}

	//还原
	this->setMaxHP(CCString::createWithFormat("%d",tempMaxHP));
	this->setHP(CCString::createWithFormat("%d",tempHP));
	if(_hpBar){
	_hpBar->setPositionY(this->getHeight());
	_hpBar->loseHP(this->getHpPercent());
	}
	
	if(isGearCD){
		this->_sattackcoldDown1-=5;
		this->_sattackcoldDown2-=5;
		this->_sattackcoldDown3-=5;
	}

	if(_role && strcmp(_role->getCString(),"Player")==0){
		_delegate->setHPLose(this->getHpPercent());
	}
	
	this->setnAttackValue(tempAttackValue);


	if(strcmp(this->_role->getCString(),"Player")==0 && 
		strcmp(this->_character->getCString(),"RockLee")!=0 &&
		strcmp(this->_character->getCString(),"Lee")!=0
		){
		_delegate->getHudLayer()->skill1Button->setCD(CCString::createWithFormat("%d",_sattackcoldDown1*1000));
		_delegate->getHudLayer()->skill2Button->setCD(CCString::createWithFormat("%d",_sattackcoldDown2*1000));
		_delegate->getHudLayer()->skill3Button->setCD(CCString::createWithFormat("%d",_sattackcoldDown3*1000));

		this->_delegate->getHudLayer()->skill1Button->_isColdChanged=true;
		this->_delegate->getHudLayer()->skill2Button->_isColdChanged=true;
		this->_delegate->getHudLayer()->skill3Button->_isColdChanged=true;


		CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s_skill1.png",charName)->getCString()); 
		_delegate->getHudLayer()->skill1Button->setDisplayFrame(frame);
		frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s_skill2.png",charName)->getCString()); 
		_delegate->getHudLayer()->skill2Button->setDisplayFrame(frame);
	
		

		frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s_skill3.png",charName)->getCString()); 
		_delegate->getHudLayer()->skill3Button->setDisplayFrame(frame);


		frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s_skill4.png",charName)->getCString()); 
		if(_delegate->getHudLayer()->skill4Button){
			_delegate->getHudLayer()->skill4Button->setDisplayFrame(frame);
		}



		frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s_skill5.png",charName)->getCString()); 
		if(_delegate->getHudLayer()->skill5Button){
			_delegate->getHudLayer()->skill5Button->setDisplayFrame(frame);
		}
		

		//替换头像
		this->_delegate->getHudLayer()->initGearButton();

		

	}


}

float ActionManager::getHpPercent(){

	float p=float(atoi(_hp->getCString()))/float(atoi(_maxHP->getCString()));
	return  p;
}


void ActionManager::attack(abType type){
	//防止普通攻击刷新 技能类型导致可以攻击塔

	if(strcmp(_role->getCString(),"Player")==0 && type==NAttack){
		if(!_delegate->getSkillFinish() && !_isOnlySkillLocked){
			return;
		};
	}

	switch(type){
	case NAttack:
		_attackValue=atoi(this->getnAttackValue()->getCString());
		_attackType=_nattackType;
		_attackRangeX=_nattackRangeX;
		_attackRangeY=_nattackRangeY;
		this->nAttack();
		break;

	case SKILL1:
		
		if(strcmp(_role->getCString(),"Player")==0){
			if(_isControled)
				_delegate->getHudLayer()->skill1Button->click();	
		}
		_attackValue=atoi(_sattackValue1->getCString());
		_attackType=_sattackType1;
		_attackRangeX=_sattackRangeX1;
		_attackRangeY=_sattackRangeY1;
		this->sAttack(SKILL1);

		break;

	case SKILL2:
	
		if(strcmp(_role->getCString(),"Player")==0){
			if(_isControled)
			_delegate->getHudLayer()->skill2Button->click();	
		}
		_attackValue=atoi(_sattackValue2->getCString());
		_attackType=_sattackType2;
		_attackRangeX=_sattackRangeX2;
		_attackRangeY=_sattackRangeY2;
		this->sAttack(SKILL2);

		break;

	case SKILL3:
		if(strcmp(_role->getCString(),"Player")==0){
			if(_isControled)
				_delegate->getHudLayer()->skill3Button->click();	
		}
		_attackValue=atoi(_sattackValue3->getCString());
		_attackType=_sattackType3;
		_attackRangeX=_sattackRangeX3;
		_attackRangeY=_sattackRangeY3;
		this->sAttack(SKILL3);

		break;

	case OUGIS1:
		if(strcmp(_role->getCString(),"Player")!=0 || this->_isAI){
			float newValue=atof(this->getCKR()->getCString())-15000;;
			this->setCKR(CCString::createWithFormat("%f",newValue));
			if(atof(this->getCKR()->getCString()) <15000){
				_isCanOugis1=false;
			}	
		}

		_attackValue=atoi(_sattackValue4->getCString());
		_attackType=_sattackType4;
		_attackRangeX=_sattackRangeX4;
		_attackRangeY=_sattackRangeY4;
		this->oAttack(OUGIS1);
		break;

	case OUGIS2:

		if(strcmp(_role->getCString(),"Player")!=0 || this->_isAI){
			float newValue=atof(this->getCKR2()->getCString())-25000;
			this->setCKR2(CCString::createWithFormat("%f",newValue));
			if(atof(this->getCKR2()->getCString()) <25000){
				_isCanOugis2=false;
			}	
		}

		_attackValue=atoi(_sattackValue5->getCString());
		_attackType=_sattackType5;
		_attackRangeX=_sattackRangeX5;
		_attackRangeY=_sattackRangeY5;
		this->oAttack(OUGIS2);
		break;
	};

};

void ActionManager::nAttack(){
	if(_actionState ==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK){
		
		if(!_isAllAttackLocked || _isOnlySkillLocked ){
			if(strcmp(_role->getCString(),"Player")==0){
				_delegate->setSkillFinish(false);
			};
			if(strcmp(_role->getCString(),"Bullet")!=0){
				this->stopAllActions();
			};
			_actionState = ACTION_STATE_ATTACK;
			this->runAction(_nattackAction);

		}
	}
};


void ActionManager::sAttack(abType type){
	if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
		
	
		//攻击取消隐身
		if(!_isVisable){
			if(strcmp(this->getCharacter()->getCString(),"Konan")==0 ||
				strcmp(this->getCharacter()->getCString(),"Deidara")==0
				){
				this->unschedule(schedule_selector(ActionManager::disableBuff));
			}
			
			
			this->setOpacity(255);
			this->setVisible(true);

			if(_hpBar){
				_hpBar->setVisible(true);
			}
			if(_shadow){
				_shadow->setVisible(true);
			}

			_isVisable=true;
		}

		
		this->stopAllActions();
		
			switch(type){
			case SKILL1:
				//if(_isCanSkill1){
					_actionState = ACTION_STATE_SATTACK;
					if(strcmp(_role->getCString(),"Player")==0){
						_delegate->setSkillFinish(false);
					};	
					this->runAction(_skill1Action);
				//}
				_isCanSkill1=false;
				
				this->scheduleOnce(schedule_selector(Hero::enableSkill1),_sattackcoldDown1);
				break;
			case SKILL2:
				if(_isCanSkill2){
					_actionState = ACTION_STATE_SATTACK;
				if(strcmp(_role->getCString(),"Player")==0){
					_delegate->setSkillFinish(false);
				};	
				this->runAction(_skill2Action);
				}
				
				_isCanSkill2=false;
				
				this->scheduleOnce(schedule_selector(Hero::enableSkill2),_sattackcoldDown2);

				break;
			case SKILL3:
				if(_isCanSkill3){
					_actionState = ACTION_STATE_SATTACK;
				if(strcmp(_role->getCString(),"Player")==0){
					_delegate->setSkillFinish(false);
				};	
				this->runAction(_skill3Action);
				}
				_isCanSkill3=false;
				
				this->scheduleOnce(schedule_selector(Hero::enableSkill3),_sattackcoldDown3);
				break;

			}
			
	}
};


void ActionManager::oAttack(abType type){
	if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

		if(strcmp(_role->getCString(),"Player")==0){
			_delegate->setSkillFinish(false);
		};	
		
		//攻击取消隐身
		if(!_isVisable){
			if(strcmp(this->getCharacter()->getCString(),"Konan")==0 ||
				strcmp(this->getCharacter()->getCString(),"Deidara")==0
				){
					this->unschedule(schedule_selector(ActionManager::disableBuff));
			}

			
			this->setOpacity(255);
			this->setVisible(true);
			

			if(_hpBar){
				_hpBar->setVisible(true);
			}

			if(_shadow){
				_shadow->setVisible(true);
			}
			_isVisable=true;
		}

		this->stopAllActions();
		switch(type){
		case OUGIS1:
			_actionState = ACTION_STATE_OATTACK;
			this->runAction(_skill4Action);
			break;
		case OUGIS2:
			_actionState = ACTION_STATE_O2ATTACK;
			this->runAction(_skill5Action);
			break;

		}
	
	
	}

}

void ActionManager::idle(){

	if(_actionState!=ACTION_STATE_IDLE && _actionState!=ACTION_STATE_DEAD){

		
		_actionState=ACTION_STATE_IDLE;
		this->stopAllActions();
		_backY=NULL;
		_hurtFromLeft=false;
		_hurtFromRight=false;
		_isHitOne=false;
		_isCatchOne=false;
		_isSticking=false;
		_knockLength=NULL;
		_originY=NULL;
		_sticker=NULL;
		_knockDiretion=NULL;

		this->unschedule(schedule_selector(ActionManager::stopMove));

		if(strcmp(_role->getCString(),"Player")==0 ){
			if(!_isAllAttackLocked &&!_isOnlySkillLocked ){
				_delegate->setSkillFinish(true);
			}
		};

		if(_delegate->_isAttackButtonRelease==false && 
			strcmp(_role->getCString(),"Player")==0 && 
			_attackType && !_isAllAttackLocked
			){
			_delegate->setSkillFinish(true);
			this->attack(NAttack);
		}else{
			this->runAction(_idleAction);
		};

	}


};


void ActionManager::walk(CCPoint direction){
	if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || ( _actionState==ACTION_STATE_ATTACK && strcmp(this->getRole()->getCString(),"Player")!=0) ){
		
		isHurtingTower=false;

		if(_actionState==ACTION_STATE_ATTACK && 
			(strcmp(this->getCharacter()->getCString(),"Suigetsu")==0 ||
			strcmp(this->getCharacter()->getCString(),"Jugo")==0 ||
			strcmp(this->getCharacter()->getCString(),"Hiruzen")==0  ||
			strcmp(this->getCharacter()->getCString(),"Kisame")==0
			) && _isOnlySkillLocked){
				if(strcmp(this->getRole()->getCString(),"Player")!=0){
					return;
				}
		}else if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_ATTACK ){
			this->stopAllActions();
			this->runAction(_walkAction);
		};

		
		_actionState=ACTION_STATE_WALK;
		
		_isFlipped=direction.x>0?false:true;
		this->setFlipX(_isFlipped);
		if(_healBuffEffect){
			_healBuffEffect->setFlipX(_isFlipped);
		} 

		
		
		if(strcmp(this->_character->getCString(),"Itachi")==0 ||
			strcmp(this->_character->getCString(),"ImmortalSasuke")==0 ||
			strcmp(this->_character->getCString(),"Chiyo")==0
			){
			if(this->getMonsterArray() && getMonsterArray()->count()>0){
				CCObject* pObject;
				CCARRAY_FOREACH(this->getMonsterArray(),pObject){
					Monster* mo=(Monster*) pObject;
					if(strcmp(mo->getCharacter()->getCString(),"ItachiSusano")==0||
						strcmp(mo->getCharacter()->getCString(),"SasukeSusano")==0){
						mo->setFlipX(_isFlipped);
					}else if(strcmp(mo->getCharacter()->getCString(),"Parents")==0){
						if (mo->_actionState==ACTION_STATE_IDLE){
							mo->setFlipX(_isFlipped);
							mo->_isFlipped=_isFlipped;
						}

					}
					
				};
			}
		}
		
		
		
		_velocity = ccp(direction.x * _walkSpeed*winSize.width/1280, direction.y * _walkSpeed*winSize.width/1280);
		
	};
};

bool ActionManager::hurt(){
	if(_actionState!=ACTION_STATE_SATTACK 
		&& _actionState!=ACTION_STATE_JUMP 
		&& _actionState!=ACTION_STATE_OATTACK
		&& _actionState!=ACTION_STATE_O2ATTACK
		&& _actionState!=ACTION_STATE_FLOAT
		&& _actionState!=ACTION_STATE_DEAD
		&& _actionState!=ACTION_STATE_KOCKDOWN
		&& _actionState!=ACTION_STATE_AIRHURT
		&& !_isSticking 
		&& !_isCatchOne
		&& !_isBati
		){

		//千代buff
		CCObject* pObject;
		CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
			Hero* tempHero=(Hero*) pObject;
			if(strcmp(this->_group->getCString(),tempHero->_group->getCString())==0 &&
				strcmp(tempHero->_character->getCString(),"Chiyo")==0 &&
				tempHero->_actionState!=ACTION_STATE_DEAD &&
				tempHero->_buffStartTime
				){

				CCPoint	sp=ccpSub(tempHero->getPosition(),this->getPosition());
				if(abs(sp.x)<=winSize.width/2){
					return false;
				}		
			}
		}
		if(strcmp(this->_character->getCString(),"Chiyo")==0){
			CCObject* pObject;
			CCARRAY_FOREACH(this->getMonsterArray(),pObject){
				Monster* mo=(Monster*) pObject;
				if(strcmp(mo->getCharacter()->getCString(),"Parents")==0 && !mo->_skillChangeBuffValue && mo->getActionState()!=ACTION_STATE_SATTACK  && mo->getActionState()!=ACTION_STATE_DEAD){
					CCPoint	sp=ccpSub(mo->getPosition(),this->getPosition());
					if(sp.x<=48){
					
						return false;
					}
				}
			}

		}

		if(strcmp(_role->getCString(),"Player")==0){
			_delegate->setSkillFinish(false);
		}
		
		_actionState=ACTION_STATE_HURT;
		this->stopAllActions();
		if(_hurtAction){

			CCArray* list=CCArray::create();
			list->addObject(_hurtAction);
			CCFiniteTimeAction *call = CCCallFunc::create(this,callfunc_selector(ActionManager::idle));
			list->addObject(call);
			CCAction* seq=CCSequence::create(list);
			this->runAction(seq);

		}
		return true;
	}
	return false;
};
//硬直攻击
bool ActionManager::hardHurt(int delayTime,bool isHurtAction,bool isCatch,bool isStick,bool isStun){

	if(  (_actionState!=ACTION_STATE_JUMP  || isStick)
		&& _actionState!=ACTION_STATE_O2ATTACK
		&& (_actionState!=ACTION_STATE_FLOAT || isStick)
		&& _actionState!=ACTION_STATE_DEAD
		&& (_actionState!=ACTION_STATE_KOCKDOWN || isStick)
		&& _actionState!=ACTION_STATE_AIRHURT
		&& !_isSticking
		&& !_isCatchOne
		&& !_isBati
		){
			if(this->getActionState()==ACTION_STATE_FLOAT ||
				this->getActionState()==ACTION_STATE_AIRHURT||
				this->getActionState()==ACTION_STATE_JUMP 
				){
					this->setPositionY(_originY);
					_originY=NULL;
					_delegate->reorderChild(this,-this->getPositionY());
			}

			//千代buff
			CCObject* pObject;
			CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
				Hero* tempHero=(Hero*) pObject;
				if(strcmp(this->_group->getCString(),tempHero->_group->getCString())==0&&
					strcmp(tempHero->_character->getCString(),"Chiyo")==0 &&
					tempHero->_actionState!=ACTION_STATE_DEAD &&
					tempHero->_buffStartTime
					){
						CCPoint	sp=ccpSub(tempHero->getPosition(),this->getPosition());
						if(abs(sp.x)<=winSize.width/2){
							return false;
						}

				}
			}

			if(strcmp(this->_character->getCString(),"Chiyo")==0){
				CCObject* pObject;
				CCARRAY_FOREACH(this->getMonsterArray(),pObject){
					Monster* mo=(Monster*) pObject;
					if(strcmp(mo->getCharacter()->getCString(),"Parents")==0 && !mo->_skillChangeBuffValue && mo->getActionState()!=ACTION_STATE_SATTACK  && mo->getActionState()!=ACTION_STATE_DEAD){
						CCPoint	sp=ccpSub(mo->getPosition(),this->getPosition());
						if(sp.x<=48){
							if(mo->_isCanSkill3){						
								mo->attack(SKILL3);
							}
							return false;
						}
					}
				}

			}

			if(strcmp(_role->getCString(),"Player")==0){
				_delegate->setSkillFinish(false);
			}
			if(isStick){
				_sticker=_slayer;
			}

			if(isCatch){
				this->setVisible(false);
				this->_isVisable=false;

				if(_shadow){
					_shadow->setVisible(false);
				}
			}

			
			_actionState=ACTION_STATE_HURT;
			this->stopAllActions();
			CCArray* list=CCArray::create();
			
			if(isHurtAction){
			list->addObject(_hurtAction);
			}else{
				_isSticking=true;
				ActionManager* attacker=(ActionManager *) _slayer;
					CCString* path;
				if(strcmp(attacker->getCharacter()->getCString(),"Kakuzu")==0){
					path=CCString::createWithFormat("%s_AirHurt_02.png",this->getCharacter()->getCString());
				}else{
					path=CCString::createWithFormat("%s_Hurt_02.png",this->getCharacter()->getCString());
				}
				
				CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(path->getCString());
				CCArray* tempArray= CCArray::create();
				tempArray->addObject(frame);
				CCAnimation* tempAnimation= CCAnimation::createWithSpriteFrames(tempArray, 0.1f);
				CCAction* tempAction=CCAnimate::create(tempAnimation);
				list->addObject(tempAction);
			}
			
			if(isStun){
				CCDictionary* callValue = CCDictionary::create(); 
				callValue->setObject(CCString::create("stun"), 1);
				callValue->retain();
				CCFiniteTimeAction *call = CCCallFuncND::create(this,callfuncND_selector(ActionManager::setSkillEffect),(void*)callValue);
				list->addObject(call);

			}

			CCAction* delay=CCDelayTime::create(delayTime/1000);
			list->addObject(delay);



			CCFiniteTimeAction *call = CCCallFunc::create(this,callfunc_selector(ActionManager::idle));
			list->addObject(call);

			CCAction* seq=CCSequence::create(list);
			this->runAction(seq);

		return true;	
	}

	return false;
}

void ActionManager::airHurt(){
	if(_actionState==ACTION_STATE_FLOAT || _actionState==ACTION_STATE_AIRHURT){

	if(strcmp(_role->getCString(),"Player")==0){
		_delegate->setSkillFinish(false);
	}

	if(_actionState==ACTION_STATE_AIRHURT){
		this->getActionManager()->removeAction(_airHurtAction);
		this->unschedule(schedule_selector(ActionManager::resumePauseStuff));
	}
	_actionState=ACTION_STATE_AIRHURT;
	this->runAction(_airHurtAction);
	this->getActionManager()->pauseTarget(this);
	this->scheduleOnce(schedule_selector(ActionManager::resumePauseStuff),0.2f);
			
	}

};


void ActionManager::resumePauseStuff(float dt){

	this->getActionManager()->resumeTarget(this);

}

void ActionManager::absorb(CCPoint position,bool isImmediate){
	if(_actionState==ACTION_STATE_IDLE ||
		_actionState==ACTION_STATE_WALK || 
		_actionState==ACTION_STATE_ATTACK 
		){

		if(_isBati || _isSticking){
			return;
		}

		if(strcmp(_role->getCString(),"Player")==0){
			_delegate->setSkillFinish(false);
		}
		_actionState=ACTION_STATE_HURT;
		
		CCActionInterval* mv;
	
		CCArray* list=CCArray::create();
		if(isImmediate){
			this->stopAllActions();
			mv=CCMoveTo::create(0.2f,position) ;
			list->addObject(_hurtAction);
			this->runAction(mv);

		}else{
			CCPoint direction=ccpSub(this->getPosition(),position);
			position.x=direction.x>0?this->getPositionX()-16:this->getPositionX()+16;
			position.y=direction.y>0?this->getPositionY()-8:this->getPositionY()+8;
			mv=CCMoveTo::create(0.2f,position) ;
			list->addObject(mv);
		}

		CCFiniteTimeAction *call = CCCallFunc::create(this,callfunc_selector(ActionManager::idle));
		list->addObject(call);
		CCAction* seq=CCSequence::create(list);
		this->runAction(seq);
	
	}
}

void ActionManager::floatUP(float floatHeight, bool isCancelSkill){

	if(_actionState==ACTION_STATE_SATTACK && !isCancelSkill){
		return;
	}

	if(_actionState!=ACTION_STATE_JUMP &&
		_actionState!=ACTION_STATE_FLOAT && 
		_actionState!=ACTION_STATE_O2ATTACK &&
		_actionState!=ACTION_STATE_OATTACK &&
		_actionState!=ACTION_STATE_AIRHURT &&
		_actionState!=ACTION_STATE_DEAD &&
		!_isSticking &&
		!_isCatchOne && 
		!_isBati
		){

			//千代buff
			CCObject* pObject;
			CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
				Hero* tempHero=(Hero*) pObject;
				if(strcmp(this->_group->getCString(),tempHero->_group->getCString())==0&&
					strcmp(tempHero->_character->getCString(),"Chiyo")==0 &&
					tempHero->_actionState!=ACTION_STATE_DEAD &&
					tempHero->_buffStartTime
					){
						CCPoint	sp=ccpSub(tempHero->getPosition(),this->getPosition());
						if(abs(sp.x)<=winSize.width/2){
							return ;
						}

				}
			}

			if(strcmp(this->_character->getCString(),"Chiyo")==0){
				CCObject* pObject;
				CCARRAY_FOREACH(this->getMonsterArray(),pObject){
					Monster* mo=(Monster*) pObject;
					if(strcmp(mo->getCharacter()->getCString(),"Parents")==0 && !mo->_skillChangeBuffValue && mo->getActionState()!=ACTION_STATE_SATTACK  && mo->getActionState()!=ACTION_STATE_DEAD){
						CCPoint	sp=ccpSub(mo->getPosition(),this->getPosition());
						if(sp.x<=48){
							if(mo->_isCanSkill3){						
								mo->attack(SKILL3);
							}
							return ;
						}
					}
				}

			}

		if(strcmp(_role->getCString(),"Player")==0){
			_delegate->setSkillFinish(false);
		}
		_actionState=ACTION_STATE_FLOAT;
		this->stopAllActions();

		float posX=this->getPositionX();
		float posY=this->getPositionY();
		_originY=posY;
		CCActionInterval* _floatAwayAction;

		if(floatHeight==64){
			_floatAwayAction=CCJumpTo::create(0.8f, ccp(posX+(_isFlipped?64:-64),posY),64,1);
		}else if(floatHeight==128){
			_floatAwayAction=CCJumpTo::create(1.0f, ccp(posX+(_isFlipped?128:-128),posY),64,1);
		}else {
			_floatAwayAction=CCJumpTo::create(0.3f, ccp(posX+(_isFlipped?8:-8),posY),16,1);
		}

		
		CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(ActionManager::knockDown));
		_floatUPAction=CCSequence::create(_floatAwayAction,call,NULL);

		this->runAction(_floatUPAction);
		this->runAction(_floatAction);


	}

}

void ActionManager::knockDown(){
	if(_actionState!=ACTION_STATE_KOCKDOWN && _actionState!=ACTION_STATE_DEAD){
		_actionState=ACTION_STATE_KOCKDOWN;
		this->stopAllActions();
		
		this->runAction(_knockDownAction);
	}

}

void ActionManager::dead(){


	CCNotificationCenter::sharedNotificationCenter()->removeObserver(this,"acceptAttack");

	_isHitOne=false;
	_isCatchOne=false;
	_isSticking=false;
	_isWudi=false;
	_startPoint=ccp(0,0);
	_markPoint=ccp(0,0);
	
	_sticker=NULL;
	

	this->setWalkSpeed(224);
	this->_originSpeed=224;
	
	this->unscheduleUpdate();


	if(_isControled){
		_isControled=false;
		this->changeGroup();
		if(strcmp(_controler->getRole()->getCString(),"Player")==0){
			this->_delegate->controlChar=NULL;
		}
		if(strcmp(this->getRole()->getCString(),"Player")==0){
			this->_isAI=false;
			this->_delegate->getHudLayer()->_isAllButtonLocked=false;
		}

		if(this->_controler->getActionState()!=ACTION_STATE_DEAD){
			this->_controler->unschedule(schedule_selector(ActionManager::resumeAction));
			this->_controler->idle();								
			this->_controler->_isBati=false;
		}
		
		this->_controler=NULL;
	}

	if(strcmp(this->getCharacter()->getCString(),"Minato")!=0){
		this->setActionResume();
	}else{
		this->setActionResume2();
	}
	
	this->removeLostBlood(0.1f);
	this->unschedule(schedule_selector(ActionManager::stopMove));
	this->unschedule(schedule_selector(ActionManager::setAI));
	this->unschedule(schedule_selector(ActionManager::disableHpBar));
	
    

	if(strcmp(_role->getCString(),"Player")==0){
		_delegate->setSkillFinish(false);
		_delegate->getHudLayer()->hpLabel->setString("0");
		_delegate->getHudLayer()->status_hpbar->setOpacity(0);
	}

	

	//kill all buffEffect

	if(strcmp(this->_role->getCString(),"Player")==0 ||  strcmp(this->_role->getCString(),"Com")==0){

		this->unschedule(schedule_selector(ActionManager::healBuff));
		this->_buffStartTime=NULL;
		this->unschedule(schedule_selector(ActionManager::dehealBuff));	
		if(strcmp(this->getCharacter()->getCString(),"RockLee")!=0 &&
			strcmp(this->getCharacter()->getCString(),"Lee")!=0
			){
			this->removeBuffEffect("all");
		}else{
			this->removeBuffEffect("dhBuff");
		}	
	

		if(_isSuicide){
			_isSuicide=false;
			rebornLabelTime=3;
		}else{	
			rebornLabelTime=0;
			_deadNum++;

			if(strcmp(this->_role->getCString(),"Player")==0){
				const char* dl=_delegate->getHudLayer()->deadLabel->getString();
				int deads=atoi(dl)+1;
				_delegate->getHudLayer()->deadLabel->setString(CCString::createWithFormat("%d",deads)->getCString());
			}
		}

		

		if(!_isVisable){

			
			this->setOpacity(255);
			
			this->setVisible(true);	
			if(_hpBar){
			_hpBar->setVisible(true);
			}

			if(_shadow){
				_shadow->setVisible(true);
			}
			_isVisable=true;
		};

		

	};
	if(_hpBar){
		_hpBar->removeFromParent();
		_hpBar=NULL;
	}
	
	
	
	if(hearts<1){
		hearts+=1;
	};

	if(strcmp(this->getCharacter()->getCString(),"Kakuzu") ==0){
		if(_heartEffect){
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("Heart_Effect_%02d.png",this->hearts)->getCString()); 
			this->_heartEffect->setDisplayFrame(frame);
		}

		if(strcmp(this->getRole()->getCString(),"Player")==0 && this->getLV()>=2){
			if(_delegate->getHudLayer()->skill4Button){
				_delegate->getHudLayer()->skill4Button->unLock();
			}
		}
	}

	if(bamen>0){

		if(strcmp(this->getCharacter()->getCString(),"Lee") ==0 ||
		strcmp(this->getCharacter()->getCString(),"RockLee") ==0
		){

			if(bamen==5){
				
				this->setWalkSpeed(224);
				_originSpeed=224;
				this->setWalkAction(createAnimation(walkArray,10.0f,true,false));
				this->setsAttackValue3(CCString::createWithFormat("%d",atoi(this->_sattackValue3->getCString())-100));
				this->setsAttackValue2(CCString::createWithFormat("%d",atoi(this->_sattackValue2->getCString())-100));
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())-60));
			}else if(bamen==4){
				this->setsAttackValue3(CCString::createWithFormat("%d",atoi(this->_sattackValue3->getCString())-100));
				this->setsAttackValue2(CCString::createWithFormat("%d",atoi(this->_sattackValue2->getCString())-100));
			}else if(bamen==3){
				this->setTransform();

				if(strcmp(this->getRole()->getCString(),"Player")==0 ){
					if(_delegate->getHudLayer()->skill3Button){
						_delegate->getHudLayer()->skill3Button->setLock();
					}
				}

				if(_skillBuffEffect){
					_skillBuffEffect->removeFromParent();
					_skillBuffEffect=NULL;
				}

			}else if(bamen==2){
				this->setsAttackValue2(CCString::createWithFormat("%d",atoi(this->_sattackValue2->getCString())-100));
			}else if(bamen==1){
				if(strcmp(this->getRole()->getCString(),"Player")==0){
					if(_delegate->getHudLayer()->skill4Button){
						_delegate->getHudLayer()->skill4Button->setLock();
					}
				}
				this->setnAttackValue(CCString::createWithFormat("%d",atoi(this->_nattackValue->getCString())-30));
			}
			bamen-=1;
			if(bamen==0){
				this->_heartEffect->removeFromParent();
				this->_heartEffect=NULL;
			}else {
				CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("Bamen_Effect_%02d.png",this->bamen-1)->getCString()); 
				this->_heartEffect->setDisplayFrame(frame);
			}

		}

	}

	
	if(_actionState==ACTION_STATE_FLOAT || _actionState==ACTION_STATE_AIRHURT){
		_actionState=ACTION_STATE_DEAD;	
		this->unschedule(schedule_selector(ActionManager::removeClone));
		this->schedule(schedule_selector(ActionManager::checkActionFinish),0.0f);
		return;
		
	}else if(_actionState==ACTION_STATE_JUMP){
		this->setPositionY(_originY);
		_originY=NULL;
		_delegate->reorderChild(this,-this->getPositionY());
	}
	

	
	this->stopAllActions();
	_actionState=ACTION_STATE_DEAD;	

	if(strcmp(this->_role->getCString(),"Player")==0 ||  strcmp(this->_role->getCString(),"Com")==0){
		CCNotificationCenter::sharedNotificationCenter()->postNotification("updateMap", this);
	}


	if(strcmp(_role->getCString(),"Clone")!=0 &&  
		strcmp(_role->getCString(),"Summon")!=0){

		CCActionInterval* fadeOut=CCFadeOut::create(0.5);
		CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(ActionManager::dealloc));
		CCArray* seqArray=CCArray::create();
		seqArray->addObject(_deadAction);

		if(strcmp(_role->getCString(),"Flog")==0){
			seqArray->addObject(fadeOut);
		}
		seqArray->addObject(call);
		CCAction* seq=CCSequence::create(seqArray);
		this->runAction(seq);
	
	}else{
		this->unschedule(schedule_selector(ActionManager::removeClone));
		CCDictionary* callValue = CCDictionary::create(); 
		callValue->setObject(CCString::create("smk"), 1);	
		this->setSkillEffect(this,callValue);
		this->dealloc();
	}

};


void ActionManager::checkActionFinish(float dt){

	if(this->getActionManager()->numberOfRunningActionsInTarget(this)==0){
		this->unschedule(schedule_selector(ActionManager::checkActionFinish));
		this->stopAllActions();
		CCActionInterval* fadeOut=CCFadeOut::create(0.5);
		CCFiniteTimeAction *call=CCCallFunc::create(this,callfunc_selector(ActionManager::dealloc));
		CCArray* seqArray=CCArray::create();
		if(_deadAction){
			seqArray->addObject(_deadAction);
		}
		if(strcmp(_role->getCString(),"Flog")==0){
			seqArray->addObject(fadeOut);
		}
		seqArray->addObject(call);
		CCAction* seq=CCSequence::create(seqArray);
		this->runAction(seq);
	};


}

void ActionManager::dealloc(){
	
}

void ActionManager::reborn(float dt){

}


void ActionManager::setAI(float dt){

}

void ActionManager::doAI(){
	this->_isAI=true;
	this->schedule(schedule_selector(ActionManager::setAI),0.1f);
	
}

bool ActionManager::findEnemy(const char* type,int searchRange,bool masterRange){

	CCArray* list;
	if(strcmp("Hero",type)==0){
		list=_delegate->_CharacterArray;
	}else if(strcmp("Flog",type)==0){
		if(strcmp("Akatsuki",_group->getCString())==0){
			list=_delegate->_KonohaFlogArray;
		}else{
			list=_delegate->_AkatsukiFlogArray;
		} 
	}else if(strcmp("Tower",type)==0){
		list=_delegate->_TowerArray;
	}

	CCObject* pObject;
	float distance;
	float curDistance=NULL ;
	CCPoint sp;
	bool findSome=false;
	CCARRAY_FOREACH(list,pObject){
		ActionManager* target=(ActionManager*) pObject;

		if(target->_actionState==ACTION_STATE_DEAD || 
			target->_isVisable==false ||	
			target->_isWudi ||
			strcmp(target->_role->getCString(),"Kuilei")==0){
				continue;
		}

		//奥义定位技能跳过召唤物
		if((this->getActionState()==ACTION_STATE_OATTACK || 
			this->getActionState()==ACTION_STATE_O2ATTACK) ||
			(this->getMaster() && (
			this->getMaster()->getActionState()==ACTION_STATE_OATTACK ||
			this->getActionState()==ACTION_STATE_O2ATTACK
			))
			){
				if(strcmp(target->_role->getCString(),"Clone")==0||
					strcmp(target->_role->getCString(),"Summon")==0||
					strcmp(target->_role->getCString(),"Monster")==0){
						continue;
				}
		}

		if(strcmp(this->_group->getCString(),target->_group->getCString())!=0 ){

						if(masterRange && this->getMaster()){
							distance=ccpDistance(target->getPosition(),this->getMaster()->getPosition());
							sp=ccpSub(target->getPosition(),this->getMaster()->getPosition());
						}else{
							distance=ccpDistance(target->getPosition(),this->getPosition());
							sp=ccpSub(target->getPosition(),this->getPosition());
						}

						if(abs(sp.x)<(searchRange?searchRange:winSize.width/2)){
							if(target->_isTaunt){
								_mainTarget=target;
								return true;
							}
							if(curDistance && abs(curDistance)>abs(distance)){
								_mainTarget=target;
								curDistance=distance;
							}else if(!curDistance){
								findSome=true;
								curDistance=distance;
								_mainTarget=target;
							};
						}

				
		}

	};
	if(findSome){
		return true;
	}else {
		return false;
	}
	

};



bool ActionManager::findEnemy2(const char* type){
	
	CCArray* list;
	if(strcmp("Hero",type)==0){
		list=_delegate->_CharacterArray;
	}else if(strcmp("Flog",type)==0){
		if(strcmp("Akatsuki",_group->getCString())==0){
			list=_delegate->_KonohaFlogArray;
		}else{
			list=_delegate->_AkatsukiFlogArray;
		} 
	}else if(strcmp("Tower",type)==0){
		list=_delegate->_TowerArray;
	}
	
	CCObject* pObject;
	float distance;
	float curDistance=NULL ;
	CCPoint sp;
	bool findSome=false;
	
	enemyCombatPoint=0;
	friendCombatPoint=0;


	CCARRAY_FOREACH(list,pObject){
		ActionManager* target=(ActionManager*) pObject;

		if(target->_actionState==ACTION_STATE_DEAD || 
			target->_isVisable==false ||	
			strcmp(target->_role->getCString(),"Kuilei")==0 ){
			continue;
		}

		distance=ccpDistance(target->getPosition(),this->getPosition());
		sp=ccpSub(target->getPosition(),this->getPosition());

		//计算combatpoint
		if(abs(sp.x)<winSize.width/2){
			if(strcmp(target->_role->getCString(),"Clone")!=0 &&
				strcmp(target->_role->getCString(),"Summon")!=0 
				){
					int baseSkillCombatPoint=0;

					if(target->_isCanSkill1){
						baseSkillCombatPoint+=_sattackCombatPoint1;
					}
					if(target->_isCanSkill2){
						baseSkillCombatPoint+=_sattackCombatPoint2;
					}
					if(target->_isCanSkill2){
						baseSkillCombatPoint+=_sattackCombatPoint3;
					}

					if(strcmp(this->_group->getCString(),target->_group->getCString())==0){
						if(abs(sp.x)<_delegate->currentMap->getTileSize().width*3){

							if(strcmp(target->_character->getCString(),"Roshi")!=0
								&& strcmp(target->_character->getCString(),"Han")!=0){

									friendCombatPoint+=baseSkillCombatPoint+ atoi(target->getHP()->getCString())+
										(atof(target->getCKR()->getCString())/15000)*target->_sattackCombatPoint4+ (atof(target->getCKR2()->getCString())/25000)*target->_sattackCombatPoint5;

							}

						}
			
					}else{


						if(strcmp(target->_character->getCString(),"Roshi")!=0
							&& strcmp(target->_character->getCString(),"Han")!=0){
						enemyCombatPoint+=baseSkillCombatPoint+atoi(target->getHP()->getCString())
							+(atof(target->getCKR()->getCString())/15000)*target->_sattackCombatPoint4+ (atof(target->getCKR2()->getCString())/25000)*target->_sattackCombatPoint5;				
						}

						if(!target->_isWudi && (target->getPositionX()>=_delegate->currentMap->getTileSize().width*3 &&target->getPositionX()<=(_delegate->currentMap->getMapSize().width-3)*_delegate->currentMap->getTileSize().width) ){

							if(curDistance && curDistance>distance){
								_mainTarget=target;
								curDistance=distance;
							}else if(!curDistance){
								findSome=true;
								curDistance=distance;
								_mainTarget=target;
							};

						}

					}
				}
			
		}

	}

	if(findSome){
		return true;
	}else {
		return false;
	}

};

bool ActionManager::checkBase(){

	CCArray* list=_delegate->_CharacterArray;
	CCObject* pObject;

	CCARRAY_FOREACH(list,pObject){
		ActionManager* target=(ActionManager*) pObject;
		if(target->_actionState==ACTION_STATE_DEAD){
				continue;
		}
		if(strcmp(this->_group->getCString(),target->_group->getCString())!=0){
			if( strcmp(this->_group->getCString(),"Konoha")==0){
				if(target->getPositionX()<=11*32){
					_mainTarget=target;
					return true;
				}
			}else {
				if(target->getPositionX()>=85*32){
					_mainTarget=target;
					return true;
				}
			}
		}
	}

	if(strcmp("Akatsuki",_group->getCString())==0){
		list=_delegate->_KonohaFlogArray;
	}else{
		list=_delegate->_AkatsukiFlogArray;
	} 

	CCARRAY_FOREACH(list,pObject){
		ActionManager* target=(ActionManager*) pObject;
		if(target->_actionState==ACTION_STATE_DEAD){
				continue;
		}
		if(strcmp(this->_group->getCString(),target->_group->getCString())!=0){
			if( strcmp(this->_group->getCString(),"Konoha")==0){
				if(target->getPositionX()<=11*32){
					_mainTarget=target;
					return true;
				}
			}else {
				if(target->getPositionX()>=85*32){
					_mainTarget=target;
					return true;
				}
			}
		}
	}


	return false;

}




bool ActionManager::findTargetEnemy(const char* type,bool isTowerDected){

	CCArray* list;
	if(strcmp("Hero",type)==0){
		list=_delegate->_CharacterArray;
	}else if(strcmp("Flog",type)==0){
		if(strcmp("Akatsuki",_group->getCString())==0){
			list=_delegate->_KonohaFlogArray;
		}else{
			list=_delegate->_AkatsukiFlogArray;
		} 
	}

	CCObject* pObject;

	float curDistance=NULL ;
	CCPoint sp;
	bool findSome=false;


	CCARRAY_FOREACH(list,pObject){
		ActionManager* target=(ActionManager*) pObject;

		if(strcmp(this->_group->getCString(),target->_group->getCString())!=0  &&
			strcmp(target->_role->getCString(),"Kuilei")!=0 &&
			target->_actionState!=ACTION_STATE_DEAD  &&
			target->_isVisable
			&& !target->_isWudi
			){
				float gardZone;
				if(this->getDelegate()->zhenying>0){
					if(target->getPositionX()>=81*32){
						findSome=true;

						if(target->isHurtingTower){
							if(strcmp(target->getCharacter()->getCString(),"Choji")==0||
								strcmp(target->getCharacter()->getCString(),"Sakura")==0){
									_mainTarget=target;
									return true;
							}
							_mainTarget=target;
						}

						if(!isTowerDected){
							_mainTarget=target;
						}

					}
				}else{
					if(target->getPositionX()<=14*32){
						findSome=true;

						if(target->isHurtingTower){
							if(strcmp(target->getCharacter()->getCString(),"Choji")==0||
								strcmp(target->getCharacter()->getCString(),"Sakura")==0){
									_mainTarget=target;
									return true;
							}
							_mainTarget=target;
						}

						if(!isTowerDected){
							_mainTarget=target;
						}

					}
				}
				

		}
	};
	if(!isTowerDected){
		if(findSome==true){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}


};

void ActionManager::stepOn(){
	
	CCPoint moveDirection;

	if(strcmp("Konoha",_group->getCString())==0){
		 moveDirection =ccpNormalize(ccp(1,0));
	}else{
		 moveDirection =ccpNormalize(ccp(-1,0));
	};

	this->walk(moveDirection);

}
bool ActionManager::checkRetri(){
	if(_isCanItem1 &&atoi(this->getCoin()->getCString())>=50){
		if(_delegate->_isHardCoreGame){
			if(battleCondiction>=0){
				if(!_isHealling){
					if(atoi(this->getMaxHP()->getCString())- atoi(this->getHP()->getCString())>=3000+gearRecoverValue  && this->getGearArray()->count()>1){
						this->setItem(Item1);					
					}else if(atoi(this->getHP()->getCString())<5000 && this->getGearArray()->count()>0){
						this->setItem(Item1);					
					}else if(atoi(this->getHP()->getCString())<1500){
						this->setItem(Item1);
					}
				}
			}else{	
				if(atoi(this->getMaxHP()->getCString())- atoi(this->getHP()->getCString())>=3000+gearRecoverValue && !_isHealling && this->getGearArray()->count()>0){
					this->setItem(Item1);					
				}else if(atoi(this->getHP()->getCString())<3000){
					this->setItem(Item1);	
				}
			}
		}else{
			if(atoi(this->getHP()->getCString())<1500 && strcmp(this->getGroup()->getCString(),"Konoha")==0){
				this->setItem(Item1);
			}
			if(atoi(this->getHP()->getCString())<500 && strcmp(this->getGroup()->getCString(),"Akatsuki")==0){
				this->setItem(Item1);
			}

		}
	}
	
	
	if(battleCondiction>=0){
		if(strcmp("Konoha",_group->getCString())==0){
			if(this->getPositionX()>=_delegate->currentMap->getTileSize().width*60){
				return false;
			}
		}else{
			if(this->getPositionX()<=_delegate->currentMap->getTileSize().width*36){
				return false;
			}

		}
	}
	
	if(atoi(this->getHP()->getCString())<1500 && !_isControled ){
		return true;
	}
	return false;
	
}

bool ActionManager::stepBack(){
	if(_isControled){
		return false;
	}
	CCPoint moveDirection;
	
	if(strcmp("Konoha",_group->getCString())==0){
		 moveDirection =ccpNormalize(ccp(-1,0));
	}else{
		 moveDirection =ccpNormalize(ccp(1,0));
	};

	if(this->getPositionX()>=_delegate->currentMap->getTileSize().width*2 &&
		this->getPositionX()<=(_delegate->currentMap->getMapSize().width-2)*_delegate->currentMap->getTileSize().width
		){
			this->walk(moveDirection);
			return true;
	}else{
		return false;
	};
}

bool ActionManager::stepBack2(){
	if(_isControled){
		return false;
	}
	CCPoint moveDirection;
	
	srand((int)time(0));
	int randomDirection=random(10);

	if(!_backY){
		
		if(randomDirection>5){
			
			if(this->getPositionY()+96<_delegate->currentMap->getTileSize().height*5.5){
				_DiretionY=1;
				_backY=this->getPositionY()+96;
			}else{
				_DiretionY=-1;
				_backY=this->getPositionY()-96;
			}

		}else {
		
			if(this->getPositionY()-96>16){
				_DiretionY=-1;
				_backY=this->getPositionY()-96;
			}else{
				_DiretionY=1;
				_backY=this->getPositionY()+96;
			}
		}
		
	}else{

		if(randomDirection>5){
			if(_DiretionY==1 &&  (this->getPositionY()>=_backY || this->getPositionY()> _delegate->currentMap->getTileSize().height*5) ){
				_DiretionY=-1;
				_backY=this->getPositionY()-96;
			}else if(_DiretionY==-1 && (this->getPositionY()<=_backY|| this->getPositionY()<16 )){
				_DiretionY=1;
				_backY=this->getPositionY()+96;
			}
		}else {

			if(_DiretionY==1  && this->getPositionY()<= _delegate->currentMap->getTileSize().height*5 ){
				_DiretionY=1;
				_backY=_delegate->currentMap->getTileSize().height*5;
			}else if(this->getPositionY()>16){
				_DiretionY=-1;
				_backY=16;
			}

		}
		
	} 
	
	if(strcmp("Konoha",_group->getCString())==0 && this->getPositionX()>=_delegate->currentMap->getTileSize().width*2 ){
		moveDirection =CCPoint(ccp(-1,_DiretionY));
		this->walk(moveDirection);
		return true;
	}else if (strcmp("Akatsuki",_group->getCString())==0 && this->getPositionX() <=(_delegate->currentMap->getMapSize().width-2)*_delegate->currentMap->getTileSize().width){
		moveDirection =CCPoint(ccp(1,_DiretionY));
		this->walk(moveDirection);
		return true;
	}else {
		return false;
	}


}


void ActionManager::changeSide(CCPoint sp){
	if(sp.x>0){
		this->setFlipX(false);
		this->_isFlipped=false;
	}else{
		this->setFlipX(true);
		this->_isFlipped=true;
	}

	if(strcmp(this->_character->getCString(),"Itachi")==0 ||
		strcmp(this->_character->getCString(),"ImmortalSasuke")==0
		){
			if(this->getMonsterArray() && getMonsterArray()->count()>0){
				CCObject* pObject;
				CCARRAY_FOREACH(this->getMonsterArray(),pObject){
					Monster* mo=(Monster*) pObject;
					if(strcmp(mo->getCharacter()->getCString(),"ItachiSusano")==0 ||
						strcmp(mo->getCharacter()->getCString(),"SasukeSusano")==0 
						) 
						
						mo->_isFlipped=_isFlipped;
						mo->setFlipX(_isFlipped);
				};
			}
	}

}

void ActionManager::changeGroup(){
	
	if(strcmp(this->getGroup()->getCString(),"Konoha")==0){
		this->setGroup(CCString::create("Akatsuki"));
	}else{
		this->setGroup(CCString::create("Konoha"));
	}

	if(this->_hpBar && strcmp(this->getRole()->getCString(),"Player")!=0){
		if(strcmp(getGroup()->getCString(),_delegate->currentPlayer->getGroup()->getCString())!=0){
			this->_hpBar->changeBar("hp_bar_r.png");
		} else if(strcmp(getRole()->getCString(),"Com")==0){
			this->_hpBar->changeBar("hp_bar_b.png");
		} 
	}

	if(strcmp(this->getRole()->getCString(),"Player")==0){

		for(int i=0;i<4;i++){
			CCArray* list;

			if(i==0){
				list=_delegate->_CharacterArray;
			}else if(i==1){
				list=_delegate->_TowerArray;
			}else if(i==2){
				list=_delegate->_AkatsukiFlogArray;
			}else if(i==3){
				list=_delegate->_KonohaFlogArray;
			}

			CCObject* pObject;
			CCARRAY_FOREACH(list,pObject){
				ActionManager* target=(ActionManager*) pObject;
				if(target->_hpBar){
					if(strcmp(this->_group->getCString(),target->_group->getCString())!=0){

						if(strcmp(target->getRole()->getCString(),"Flog")==0){
							target->_hpBar->changeBar("flog_bar_r.png");
						}else{
							target->_hpBar->changeBar("hp_bar_r.png");
						}

					}else{

						if(strcmp(target->getRole()->getCString(),"Flog")==0){
							target->_hpBar->changeBar("flog_bar.png");
						}else if(strcmp(target->getRole()->getCString(),"Tower")==0){
							target->_hpBar->changeBar("hp_bar.png");
						}else {

							if(strcmp(target->getRole()->getCString(),"Player")!=0){
								target->_hpBar->changeBar("hp_bar_b.png");
							}
							
						}

					}
				}
			}
		}

	};
	
	

}


void ActionManager::enableItem1(float dt){
	_isCanItem1=true;
}

void ActionManager::enableSkill1(float dt){
	_isCanSkill1=true;
}
void ActionManager::enableSkill2(float dt){
	_isCanSkill2=true;

}
void ActionManager::enableSkill3(float dt){
	_isCanSkill3=true;
}




