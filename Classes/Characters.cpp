#include "Characters.h"
USING_NS_CC;


bool Hero::init(){
	bool bRet = false;
	do {

		CC_BREAK_IF(!HeroElement::init());
		this->setAnchorPoint(ccp(0.5,0));		
		
		//this->schedule(schedule_selector(Hero::neicun),0.5f);
		bRet=true;
	}while(0);

	return bRet;

};

void Hero::setAI(float dt){

	if(strcmp(getCharacter()->getCString(),"Sakura")==0){
		AI_Sakura();
	}else if(strcmp(getCharacter()->getCString(),"Pain")==0){
		AI_Pain();
	}else if(strcmp(getCharacter()->getCString(),"MaskRaidon")==0){
		AI_Mask();
	}else if(strcmp(getCharacter()->getCString(),"MaskFudon")==0){
		AI_Mask();
	}else if(strcmp(getCharacter()->getCString(),"MaskKadon")==0){
		AI_Mask();
	}else if(strcmp(getCharacter()->getCString(),"Slug")==0){
		AI_Slug();
	}else if(strcmp(getCharacter()->getCString(),"Centipede")==0){
		AI_Centipede();
	}else if(strcmp(getCharacter()->getCString(),"Nagato")==0){
		AI_Nagato();
	}else if(strcmp(getCharacter()->getCString(),"Asuma")==0){
		AI_Asuma();
	}else if(strcmp(getCharacter()->getCString(),"DevaPath")==0){
		AI_DevaPath();
	}else if(strcmp(getCharacter()->getCString(),"AsuraPath")==0){
		AI_AsuraPath();
	}else if(strcmp(getCharacter()->getCString(),"AnimalPath")==0){
		AI_AnimalPath();
	}else if(strcmp(getCharacter()->getCString(),"Sai")==0){
		AI_Sai();
	}else if(strcmp(getCharacter()->getCString(),"Tenten")==0){
		AI_Tenten();
	}else if(strcmp(getCharacter()->getCString(),"Suigetsu")==0){
		AI_Suigetsu();
	}else if(strcmp(getCharacter()->getCString(),"Konan")==0){
		AI_Konan();
	}else if(strcmp(getCharacter()->getCString(),"Jiraiya")==0){
		AI_Jiraiya();
	}else if(strcmp(getCharacter()->getCString(),"Shikamaru")==0){
		AI_Shikamaru();
	}else if(strcmp(getCharacter()->getCString(),"Sasuke")==0){
		AI_Sasuke();
	}else if(strcmp(getCharacter()->getCString(),"ImmortalSasuke")==0){
		AI_ImmortalSasuke();
	}else if(strcmp(getCharacter()->getCString(),"Deidara")==0){
		AI_Deidara();
	}else if(strcmp(getCharacter()->getCString(),"Minato")==0){
		AI_Minato();
	}else if(strcmp(getCharacter()->getCString(),"DogWall")==0){
		AI_DogWall();
	}else if(strcmp(getCharacter()->getCString(),"Kakashi")==0){
		AI_Kakashi();
	}else if(strcmp(getCharacter()->getCString(),"Tobi")==0){
		AI_Tobi();
	}else if(strcmp(getCharacter()->getCString(),"Hinata")==0){
		AI_Hinata();
	}else if(strcmp(getCharacter()->getCString(),"Neji")==0){
		AI_Neji();
	}else if(strcmp(getCharacter()->getCString(),"Choji")==0){
		AI_Choji();
	}else if(strcmp(getCharacter()->getCString(),"Itachi")==0){
		AI_Itachi();
	}else if(strcmp(getCharacter()->getCString(),"Orochimaru")==0){
		AI_Orochimaru();
	}else if(strcmp(getCharacter()->getCString(),"Naruto")==0 &&
		strcmp(getRole()->getCString(),"Clone")==0 
		){
			AI_NarutoClone();
	}else if(strcmp(getCharacter()->getCString(),"Naruto")==0){
		AI_Naruto();
	}else if(strcmp(getCharacter()->getCString(),"Kurama")==0){
		AI_Kurama();
	}else if(strcmp(getCharacter()->getCString(),"SageNaruto")==0 &&
		strcmp(getRole()->getCString(),"Clone")==0 
		){
			AI_SageNarutoClone();
	}else if(strcmp(getCharacter()->getCString(),"RikudoNaruto")==0 &&
		strcmp(getRole()->getCString(),"Clone")==0 
		){
			AI_RikudoNarutoClone();
	}else if(strcmp(getCharacter()->getCString(),"SageNaruto")==0
		){
			AI_SageNaruto();
	}else if(strcmp(getCharacter()->getCString(),"RikudoNaruto")==0){
		AI_RikudoNaruto();
	}else if(strcmp(getCharacter()->getCString(),"Gaara")==0){
		AI_Gaara();
	}else if(strcmp(getCharacter()->getCString(),"Tobirama")==0){
		AI_Tobirama();
	}else if(strcmp(getCharacter()->getCString(),"Akamaru")==0){
		AI_Akamaru();
	}else if(strcmp(getCharacter()->getCString(),"Karasu")==0){
		AI_Karasu();
	}else if(strcmp(getCharacter()->getCString(),"Saso")==0){
		AI_Saso();
	}else if(strcmp(getCharacter()->getCString(),"Parents")==0){
		AI_Parents();
	}else if(strcmp(getCharacter()->getCString(),"Sanshouuo")==0){
		AI_Sanshouuo();
	}else if(strcmp(getCharacter()->getCString(),"Kankuro")==0){
		AI_Kankuro();
	}else if(strcmp(getCharacter()->getCString(),"Chiyo")==0){
		AI_Chiyo();
	}else if(strcmp(getCharacter()->getCString(),"Kiba")==0){
		AI_Kiba();
	}else if(strcmp(getCharacter()->getCString(),"SageJiraiya")==0){
		AI_SageJiraiya();
	}else if(strcmp(getCharacter()->getCString(),"Karin")==0){
		AI_Karin();
	}else if(strcmp(getCharacter()->getCString(),"Lee")==0){
		AI_Lee();
	}else if(strcmp(getCharacter()->getCString(),"RockLee")==0){
		AI_RockLee();
	}else if(strcmp(getCharacter()->getCString(),"Tsunade")==0){
		AI_Tsunade();
	}else if(strcmp(getCharacter()->getCString(),"Jugo")==0){
		AI_Jugo();
	}else if(strcmp(getCharacter()->getCString(),"Kisame")==0){
		AI_Kisame();
	}else if(strcmp(getCharacter()->getCString(),"Ino")==0){
		AI_Ino();
	}else if(strcmp(getCharacter()->getCString(),"Hidan")==0){
		AI_Hidan();
	}else if(strcmp(getCharacter()->getCString(),"Shino")==0){
		AI_Shino();
	}else if(strcmp(getCharacter()->getCString(),"Hiruzen")==0){
		AI_Hiruzen();
	}else if(strcmp(getCharacter()->getCString(),"Kakuzu")==0){
		AI_Kakuzu();
	}else if(strcmp(getCharacter()->getCString(),"Roshi")==0 ||
		strcmp(getCharacter()->getCString(),"Han")==0){
		AI_Guardian();
	}

}

void Hero::AI_DevaPath(){

	if(!this->findEnemy("Hero",NULL)){
		if(!this->findEnemy("Flog",NULL)){
			if(!this->findEnemy("Tower",NULL)){
				_mainTarget=NULL;

			};
		}
	};

	if(_mainTarget){
			CCPoint moveDirection;
			CCPoint sp=ccpSub(_mainTarget->getPosition(),this->getPosition());

			if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0||
				strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){


					if(abs(sp.x)> 32 || abs(sp.y)>32){

						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);

					}else{
						if( this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
							this->changeSide(sp);
							this->attack(NAttack);
						}
					}
					return;


			}else {

				if(abs(sp.x)> 256  || abs(sp.y)> 16 ){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;

				}else if(abs(sp.x)> 32 || abs(sp.y)>32){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK ){

					bool isHaveKuilei1=false;
					bool isHaveKuilei2=false;

					if(getMonsterArray() && getMonsterArray()->count()>0){
						CCObject* pObject;
						CCARRAY_FOREACH(getMonsterArray(),pObject){
							Monster* mo=(Monster*) pObject;
							if (strcmp(mo->getCharacter()->getCString(),"AnimalPath")==0){
								isHaveKuilei1=true;
							}

							if (strcmp(mo->getCharacter()->getCString(),"AsuraPath")==0){
								isHaveKuilei2=true;
							}

						};
					}


					if(_isCanSkill1 && !isHaveKuilei1){

						this->attack(SKILL1);
						this->scheduleOnce(schedule_selector(Hero::enableSkill1),_sattackcoldDown1);

					}else if(_isCanSkill2 && !isHaveKuilei2){

						this->changeSide(sp);
						this->attack(SKILL2);
						this->scheduleOnce(schedule_selector(Hero::enableSkill2),_sattackcoldDown2);

					}else{

						this->changeSide(sp);
						this->attack(NAttack);
					}


				}
				return;

			}

	};

	this->stepOn();
}


void Hero::AI_AsuraPath(){


	if(!this->findEnemy("Hero",NULL)){
		if(!this->findEnemy("Flog",NULL)){
			if(!this->findEnemy("Tower",NULL)){
				_mainTarget=NULL;

			};
		}
	};

	if(_mainTarget){
			CCPoint moveDirection;
			CCPoint sp=ccpSub(_mainTarget->getPosition(),this->getPosition());

			if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0||
				strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){


					if(abs(sp.x)> 32 || abs(sp.y)>32){

						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);

					}else{
						if( this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
							this->changeSide(sp);
							this->attack(NAttack);
						}
					}
					return;


			}else {

				if(abs(sp.x)> 256  || abs(sp.y)> 32 ){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;

				}else if((abs(sp.x)> 32 || abs(sp.y)>32) && !_isCanSkill1  ){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK ){

					//后撤动作
					if(_isCanSkill1){

						if(abs(sp.x)<64 && this->getPositionX()>64 &&
							this->getPositionX()<(95*32-64)){
								if(this->stepBack())
									return;
						}
					}

					if(_isCanSkill1){
						this->changeSide(sp);
					
						this->attack(SKILL1);
						this->scheduleOnce(schedule_selector(Hero::enableSkill1),_sattackcoldDown1);

					}else{

						this->changeSide(sp);
						this->attack(NAttack);
					}


				}
				return;

			}

	};

	this->stepOn();
}

void Hero::AI_AnimalPath(){

	if(!this->findEnemy("Flog",NULL)){
		if(!this->findEnemy("Tower",NULL)){
			if(!this->findEnemy("Hero",NULL)){
				_mainTarget=NULL;

			};
		}
	};

	if(_mainTarget){
			CCPoint moveDirection;
			CCPoint sp=ccpSub(_mainTarget->getPosition(),this->getPosition());

			if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0||
				strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){


					if(abs(sp.x)> 32 || abs(sp.y)>32){

						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);

					}else{
						if( this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){

							if(_isCanSkill1 && strcmp(_mainTarget->getRole()->getCString(),"Tower")!=0 ){
							
								this->attack(SKILL1);
								this->scheduleOnce(schedule_selector(Hero::enableSkill1),_sattackcoldDown1);

							}else{
								this->changeSide(sp);
								this->attack(NAttack);
							}
							
						}
					}
					return;


			}else {

				if(abs(sp.x)> 256  || abs(sp.y)> 32 ){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;

				}else if(abs(sp.x)> 32 || abs(sp.y)>32){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){

					if(_isCanSkill1){
					
						this->attack(SKILL1);
						this->scheduleOnce(schedule_selector(Hero::enableSkill1),10.0f);

					}else{

						this->changeSide(sp);
						this->attack(NAttack);
					}


				}
				return;

			}

	};

	this->stepOn();
}




void Hero::AI_Akamaru(){

	if(!this->findEnemy("Hero",winSize.width/2 -32,true)){
		if(!this->findEnemy("Flog",winSize.width/2 -32,true)){
			if(!this->findEnemy("Tower",winSize.width/2 -32,true)){
				this->_mainTarget=NULL;
			}
		}
	};


	CCPoint moveDirection;

	if(abs(ccpSub(_master->getPosition(),this->getPosition()).x) >winSize.width/2 -48){
		if( this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
			moveDirection =ccpNormalize(ccpSub(_master->getPosition(),this->getPosition()));	
			this->walk(moveDirection);
			return;
		}
	}

	if(_mainTarget){
		
		CCPoint sp;
		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){

			if(abs(sp.x)> 48 || abs(sp.y)> 32 ){		
				moveDirection =ccpNormalize(sp);
				this->walk(moveDirection);
			
			}else{	
				if(this->getActionState()==ACTION_STATE_IDLE || this->getActionState()==ACTION_STATE_WALK  || _actionState==ACTION_STATE_ATTACK){
					this->changeSide(sp);
					this->attack(NAttack);
				}
						
			}
			return;


		}else {

			if(abs(sp.x)>  48  || abs(sp.y)> 32 ){
			 
				moveDirection =ccpNormalize(sp);
				this->walk(moveDirection);
				return;
				
			}else{
				if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
					
					if(_master->_isCanSkill2 && _mainTarget->getGP()<5000 && (_master->_isControled || _master->_isAI==true) && 
						(_master->getActionState()==ACTION_STATE_IDLE ||  _master->getActionState()==ACTION_STATE_WALK ||_master->getActionState()==ACTION_STATE_ATTACK)
						){
							this->changeSide(sp);
							if(strcmp(_master->getRole()->getCString(),"Player")!=0){
								_master->attack(SKILL2);
							}else if(strcmp(_master->getRole()->getCString(),"Player")==0){
								_master->attack(SKILL2);
							}

							
					}else{
						this->changeSide(sp);
						this->attack(NAttack);

					}

				}


			}

			return;

		}

	};

	if(abs(ccpSub(_master->getPosition(),this->getPosition()).x) >winSize.width/2 -64){

		CCPoint moveDirection =ccpNormalize(ccpSub(_master->getPosition(),this->getPosition()));	
		this->walk(moveDirection);
		return;
	}else{
		
		this->stepOn();
	}


};

void Hero::AI_Karasu(){

	

	if(!this->findEnemy("Hero",winSize.width/2 -32,true)){
		if(!this->findEnemy("Flog",winSize.width/2 -32,true)){
				this->_mainTarget=NULL;
		}
	};

	
	if(_mainTarget){
			CCPoint moveDirection;
			if(abs(ccpSub(_master->getPosition(),this->getPosition()).x) >winSize.width/2 -48){
			    if( this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
				moveDirection =ccpNormalize(ccpSub(_master->getPosition(),this->getPosition()));	
				this->walk(moveDirection);
				return;
				}
			}
			CCPoint sp;
			if(_mainTarget->_originY){
				sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
			}else{
				sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
			}

			

			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){

					if(abs(sp.x)> 32 || abs(sp.y)>32 ){
						if(this->_master->getActionState()== ACTION_STATE_IDLE ||
							this->_master->getActionState()== ACTION_STATE_WALK|| 
							this->_master->getActionState()== ACTION_STATE_ATTACK ||
							this->_master->getActionState()== ACTION_STATE_SATTACK ||
							this->_master->getActionState()== ACTION_STATE_OATTACK||
							this->_master->getActionState()== ACTION_STATE_O2ATTACK
							){
					
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
						}

					}else{
						if( this->getActionState()==ACTION_STATE_IDLE ||  
							this->getActionState()==ACTION_STATE_WALK || 
							this->getActionState()==ACTION_STATE_ATTACK){
							this->changeSide(sp);
							this->attack(NAttack);
						}
					}
					return;


			}else {

				if(abs(sp.x)> 32  || abs(sp.y)> 16 ){
					if(this->_master->getActionState()== ACTION_STATE_IDLE ||
						this->_master->getActionState()== ACTION_STATE_WALK || 
						this->_master->getActionState()== ACTION_STATE_ATTACK ||
						this->_master->getActionState()== ACTION_STATE_SATTACK ||
						this->_master->getActionState()== ACTION_STATE_OATTACK||
						this->_master->getActionState()== ACTION_STATE_O2ATTACK
						){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
					}
				}else if(this->getActionState()==ACTION_STATE_IDLE ||  
					this->getActionState()==ACTION_STATE_WALK || 
					this->getActionState()==ACTION_STATE_ATTACK){

					if(_master->getActionState()==ACTION_STATE_IDLE ||  
						_master->getActionState()==ACTION_STATE_WALK ||
						_master->getActionState()==ACTION_STATE_ATTACK){


						if(_master->_isCanSkill2  && _mainTarget->getGP()<5000 && (_master->_isControled || _master->_isAI==true)){

							this->changeSide(sp);
						
							if(strcmp(_master->getRole()->getCString(),"Player")!=0){
								_master->attack(SKILL2);
							}else if(strcmp(_master->getRole()->getCString(),"Player")==0){
								_master->attack(SKILL2);
							}

						}else{

							this->changeSide(sp);
							this->attack(NAttack);
						}

					}
					


				}
				return;

			}

	};

	if(abs(ccpSub(_master->getPosition(),this->getPosition()).x) >winSize.width/2 -64){
		CCPoint moveDirection =ccpNormalize(ccpSub(_master->getPosition(),this->getPosition()));	
		this->walk(moveDirection);
		return;
	}else{
		if(
			this->_master->getActionState()== ACTION_STATE_WALK  || 
			this->_master->getActionState()== ACTION_STATE_ATTACK ||
			this->_master->getActionState()== ACTION_STATE_SATTACK ||
			this->_master->getActionState()== ACTION_STATE_OATTACK
			){
			this->stepOn();
		}else{
			if (this->_actionState==ACTION_STATE_WALK || 
				this->_actionState==ACTION_STATE_ATTACK){
				this->idle();
			}
			
		}
	}
	

};

void Hero::AI_Saso(){



	if(!this->findEnemy("Hero",winSize.width/2 -32,true)){
		if(!this->findEnemy("Flog",winSize.width/2 -32,true)){
			this->_mainTarget=NULL;
		}
	};

	CCPoint moveDirection;
	if(abs(ccpSub(_master->getPosition(),this->getPosition()).x) >64){
		if( this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
			moveDirection =ccpNormalize(ccpSub(_master->getPosition(),this->getPosition()));	
			this->walk(moveDirection);
			return;
		}
	}

	if(_mainTarget){
			

			CCPoint sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY?_mainTarget->_originY:_mainTarget->getPositionY()),
			ccp(this->getPositionX(),_originY?_originY:this->getPositionY()));

			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){

				if(abs(sp.x)> 48 || abs(sp.y)> 16 ){
					if(this->_master->getActionState()== ACTION_STATE_IDLE ||
						this->_master->getActionState()== ACTION_STATE_WALK|| 
						this->_master->getActionState()== ACTION_STATE_ATTACK ||
						this->_master->getActionState()== ACTION_STATE_SATTACK ||
						this->_master->getActionState()== ACTION_STATE_OATTACK||
						this->_master->getActionState()== ACTION_STATE_O2ATTACK
						){

							moveDirection =ccpNormalize(sp);
							this->walk(moveDirection);

					}

				}else{
					if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
						this->changeSide(sp);
						this->attack(NAttack);
					}
				}
				return;


			}else {

				if((abs(sp.x)> 48 || abs(sp.y)> 16)){
					if(this->_master->getActionState()== ACTION_STATE_IDLE ||
						this->_master->getActionState()== ACTION_STATE_WALK || 
						this->_master->getActionState()== ACTION_STATE_ATTACK ||
						this->_master->getActionState()== ACTION_STATE_SATTACK ||
						this->_master->getActionState()== ACTION_STATE_OATTACK||
						this->_master->getActionState()== ACTION_STATE_O2ATTACK
						){
							moveDirection =ccpNormalize(sp);
							this->walk(moveDirection);
							return;
					}
				}else if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){

					if(_isCanSkill1  && _mainTarget->getGP()<5000){
						this->changeSide(sp);
					
						this->attack(SKILL1);
						this->scheduleOnce(schedule_selector(Hero::enableSkill1),this->_sattackcoldDown1);

					}else{

						this->changeSide(sp);
						this->attack(NAttack);
					}


				}
				return;

			}

	};

	if(abs(ccpSub(_master->getPosition(),this->getPosition()).x) >winSize.width/2 -64){
		CCPoint moveDirection =ccpNormalize(ccpSub(_master->getPosition(),this->getPosition()));	
		this->walk(moveDirection);
		return;
	}else{
		
			if (this->_actionState==ACTION_STATE_WALK || 
				this->_actionState==ACTION_STATE_ATTACK){
				this->idle();
			}

	}


};

void Hero::AI_Parents(){



	if(!this->findEnemy("Hero",winSize.width/2 -32,true)){

		if(!this->findEnemy("Flog",48,true)){
			if(!this->findEnemy("Tower",48,true)){
			this->_mainTarget=NULL;
			}
		}
	};
	
	CCPoint moveDirection;
	
	if(abs(ccpSub(_master->getPosition(),this->getPosition()).x) >9 && !_skillChangeBuffValue){
		if( this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
			moveDirection =ccpNormalize(ccpSub(_master->getPosition(),this->getPosition()));	
			this->walk(moveDirection);
			return;
		}
	}
	if(_mainTarget){


		CCPoint sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY?_mainTarget->_originY:_mainTarget->getPositionY()),
			ccp(this->getPositionX(),_originY?_originY:this->getPositionY()));

		if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 || strcmp(_mainTarget->getRole()->getCString(),"Tower")==0 ){

			
			if(abs(sp.x)> 48 || abs(sp.y)> 32 ){
			
			}else{
				if((this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK )  && !_skillChangeBuffValue){
					this->changeSide(sp);
					this->attack(NAttack);
				}
			}
			return;


		}else {
			if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK ){
				if(_master->getActionState()==ACTION_STATE_IDLE ||  
					_master->getActionState()==ACTION_STATE_WALK ||
					_master->getActionState()==ACTION_STATE_ATTACK){

					if(_master->_isCanSkill3  && _mainTarget->getGP()<5000 && (_master->_isControled || _master->_isAI==true) && !_skillChangeBuffValue){

							this->changeSide(sp);

							_master->attack(SKILL3);
							

					}else if(abs(sp.x)> 48 || abs(sp.y)> 32  ){
						if(_skillChangeBuffValue &&  this->getActionState()!=ACTION_STATE_ATTACK){
							moveDirection =ccpNormalize(sp);
							this->walk(moveDirection);
							return;
						}
					}else{
					
						if(_master->_isCanSkill2  && _mainTarget->getGP()<5000 && (_master->_isControled || _master->_isAI==true) && !_skillChangeBuffValue){

							this->changeSide(sp);				
							_master->attack(SKILL2);
						
						}else{

							this->changeSide(sp);
							this->attack(NAttack);
						}


					}
				}
			}
			
			return;

		}

	};

	if(abs(ccpSub(_master->getPosition(),this->getPosition()).x) >9){
		 if( this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK ){
			moveDirection =ccpNormalize(ccpSub(_master->getPosition(),this->getPosition()));	
			this->walk(moveDirection);
			return;
		}
	}
	
	if (this->_actionState==ACTION_STATE_WALK ){
			this->idle();
	}


};

void Hero::AI_Sanshouuo(){


	if(!this->findEnemy("Hero",winSize.width/2 -32,true)){
		if(!this->findEnemy("Flog",winSize.width/2 -32,true)){
			this->_mainTarget=NULL;
		}
	};

	if(_mainTarget){
			CCPoint moveDirection;
			if(abs(ccpSub(_master->getPosition(),this->getPosition()).x) >winSize.width/2 -64){
				if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
				moveDirection =ccpNormalize(ccpSub(_master->getPosition(),this->getPosition()));	
				this->walk(moveDirection);
				return;
				}
			}

			CCPoint sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY?_mainTarget->_originY:_mainTarget->getPositionY()),
				ccp(this->getPositionX(),_originY?_originY:this->getPositionY()));
					

			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){


					if(abs(sp.x)> 32 || abs(sp.y)>32 ){
						 if(this->_master->getActionState()== ACTION_STATE_IDLE ||
							 this->_master->getActionState()== ACTION_STATE_WALK|| 
							this->_master->getActionState()== ACTION_STATE_ATTACK ||
							this->_master->getActionState()== ACTION_STATE_SATTACK ||
							this->_master->getActionState()== ACTION_STATE_OATTACK||
							this->_master->getActionState()== ACTION_STATE_O2ATTACK
							){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						}

					}else{
						if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
							this->changeSide(sp);
							this->attack(NAttack);
						}
					}
					return;


			}else {

				if(abs(sp.x)> 96  || abs(sp.y)> 32 ){
					if(this->_master->getActionState()== ACTION_STATE_IDLE ||
						this->_master->getActionState()== ACTION_STATE_WALK  || 
						this->_master->getActionState()== ACTION_STATE_ATTACK ||
						this->_master->getActionState()== ACTION_STATE_SATTACK ||
						this->_master->getActionState()== ACTION_STATE_OATTACK||
						this->_master->getActionState()== ACTION_STATE_O2ATTACK
						){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
					}
				}else if((abs(sp.x)> 32 || abs(sp.y)>32) && !_isCanSkill1 ){
					if(this->_master->getActionState()== ACTION_STATE_WALK || 
						this->_master->getActionState()== ACTION_STATE_ATTACK ||
						this->_master->getActionState()== ACTION_STATE_SATTACK ||
						this->_master->getActionState()== ACTION_STATE_OATTACK||
						this->_master->getActionState()== ACTION_STATE_O2ATTACK
						){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
					}
				}else if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){

					if(_isCanSkill1  && _mainTarget->getGP()<5000){
						this->changeSide(sp);
					
						this->attack(SKILL1);
						this->scheduleOnce(schedule_selector(Hero::enableSkill1),_sattackcoldDown1);
					}else{
						this->changeSide(sp);
						this->attack(NAttack);
					}

				}
				return;

			}

	};

	if(abs(ccpSub(_master->getPosition(),this->getPosition()).x) >winSize.width/2 -64){
		CCPoint moveDirection =ccpNormalize(ccpSub(_master->getPosition(),this->getPosition()));	
		this->walk(moveDirection);
		return;
	}else{
		if(this->_master->getActionState()== ACTION_STATE_WALK  || 
			this->_master->getActionState()== ACTION_STATE_ATTACK ||
			this->_master->getActionState()== ACTION_STATE_SATTACK ||
			this->_master->getActionState()== ACTION_STATE_OATTACK
			){
			this->stepOn();
		}else{
			if (this->_actionState==ACTION_STATE_WALK || this->_actionState==ACTION_STATE_ATTACK){
				this->idle();
			}
			
		}
	}
	

};


void Hero::AI_NarutoClone(){

	
	if(!this->findEnemy("Flog",NULL)){
		if(!this->findEnemy("Hero",NULL)){
			if(!this->findEnemy("Tower",NULL)){
				_mainTarget=NULL;
			};

		}
	};

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;
		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){

			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);

		}else{
			if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}

	this->stepOn();


};

void Hero::AI_Kurama(){



	if(!this->findEnemy("Hero",NULL)){		
		if(!this->findEnemy("Flog",NULL)){
			if(!this->findEnemy("Tower",NULL)){
				_mainTarget=NULL;
			};
		}			
	};

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;
		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 156 || abs(sp.y)> 48 ){

			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);

		}else{
			if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}

	this->stepOn();


};

void Hero::AI_SageNarutoClone(){

	if(!this->findEnemy("Hero",NULL)){
		if(!this->findEnemy("Flog",NULL)){
			if(!this->findEnemy("Tower",NULL)){
				_mainTarget=NULL;
			};
		}
	};

	if(_mainTarget){
			CCPoint moveDirection;
			CCPoint sp;
			if(_mainTarget->_originY){
				sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
			}else{
				sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
			}

			if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0||
				strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){

					if(abs(sp.x)> 32 || abs(sp.y)>32){

						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);

					}else{
						if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
						
							this->changeSide(sp);
							this->attack(NAttack);
						}
					}
					return;
			}else {

				if(abs(sp.x)> 128 || abs(sp.y)> 16 ){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;

				}else if((abs(sp.x)> 48  || abs(sp.y)> 8) && !_isCanSkill1 ){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){

					//后撤动作
					if(_isCanSkill1 && abs(sp.x)<32){
						this->stepBack();
						return;
					}

					if(_isCanSkill1  && _mainTarget->getGP()<5000){
						this->changeSide(sp);
						this->attack(SKILL1);
					}else{
						this->changeSide(sp);
						this->attack(NAttack);
					}
				}
				return;

			}

	};

	this->stepOn();


};


void Hero::AI_RikudoNarutoClone(){

	if(!this->findEnemy("Hero",NULL)){
		if(!this->findEnemy("Flog",NULL)){
			if(!this->findEnemy("Tower",NULL)){
				_mainTarget=NULL;
			};
		}
	};

	if(_mainTarget){
		CCPoint moveDirection;
		CCPoint sp;
		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0||
			strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){

				if(abs(sp.x)> 32 || abs(sp.y)>32){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);

				}else{
					if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){

						this->changeSide(sp);
						this->attack(NAttack);
					}
				}
				return;
		}else {

			if(abs(sp.x)> 128 || abs(sp.y)> 16 ){

				moveDirection =ccpNormalize(sp);
				this->walk(moveDirection);
				return;

			}else if((abs(sp.x)> 48  || abs(sp.y)> 8) && !_isCanSkill1 ){

				moveDirection =ccpNormalize(sp);
				this->walk(moveDirection);
				return;
			}else if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){


				if(_isCanSkill1  && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL1);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}
			}
			return;

		}

	};

	this->stepOn();


};


void Hero::AI_Mask(){

	if(strcmp(this->getCharacter()->getCString(),"MaskRaidon")==0){

		if(!this->findEnemy("Flog",NULL)){
			if(!this->findEnemy("Hero",NULL)){
				if(!this->findEnemy("Tower",NULL)){
					_mainTarget=NULL;
				};
			}
		};
	}else{

		
		if(!this->findEnemy("Hero",NULL)){
			if(!this->findEnemy("Flog",NULL)){
				if(!this->findEnemy("Tower",NULL)){
					_mainTarget=NULL;
				};
			}
		};
	}
	

	if(_mainTarget){
		CCPoint moveDirection;
		CCPoint sp;
		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0){

				if(abs(sp.x)> 32 || abs(sp.y)>32){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);

				}else{
					if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){

						this->changeSide(sp);
						this->attack(NAttack);
					}
				}
				return;
		}else {

			if(abs(sp.x)> 96 || abs(sp.y)> 16 ){

				moveDirection =ccpNormalize(sp);
				this->walk(moveDirection);
				return;

			}else if((abs(sp.x)> 48  || abs(sp.y)> 16) && !_isCanSkill1 ){

				moveDirection =ccpNormalize(sp);
				this->walk(moveDirection);
				return;
			}else if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
		
				if(_isCanSkill1  && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL1);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}
			}
			return;

		}

	};

	this->stepOn();


};



void Hero::AI_Slug(){

	
	if(!this->findEnemy("Flog",NULL)){
		if(!this->findEnemy("Tower",NULL)){
			_mainTarget=NULL;
		};
	};
	

	if(_mainTarget){
			CCPoint moveDirection;
			CCPoint sp=ccpSub(_mainTarget->getPosition(),this->getPosition());

			if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0||
				strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){


					if(abs(sp.x)> 32 || abs(sp.y)>32){

						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);

					}else{
						if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){

							if(_isCanSkill1){
							
								this->attack(SKILL1);
								this->scheduleOnce(schedule_selector(Hero::enableSkill1),_sattackcoldDown1);

							}else if(_isCanSkill2){
								
								this->attack(SKILL2);
								this->scheduleOnce(schedule_selector(Hero::enableSkill2),_sattackcoldDown2);

							}else{
								this->changeSide(sp);
								this->attack(NAttack);
							}
						

						}
					}

					return;


			}
	};

	this->stepOn();


};


void Hero::AI_Centipede(){


	if(!this->findEnemy("Flog",NULL)){
		if(!this->findEnemy("Tower",NULL)){
			_mainTarget=NULL;
		};
	};


	if(_mainTarget){
		CCPoint moveDirection;
		CCPoint sp=ccpSub(_mainTarget->getPosition(),this->getPosition());

		if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0||
			strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){


				if(abs(sp.x)> 32 || abs(sp.y)>32){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);

				}else{

					this->changeSide(sp);
					this->attack(NAttack);
					
				}

				return;
		}
	};

	this->stepOn();


};


void Hero::AI_DogWall(){
	
	this->attack(NAttack);

};

void Hero::AI_Naruto(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear03);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear07);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}
	

	if(this->checkRetri()){

		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			
			if(this->stepBack()){
				return;
			};
		}
	};
	
	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			
			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game  &&  !_isBati){
				this->changeSide(sp);
				this->attack(OUGIS2);
				return;
			}else if(_isCanSkill2 && !_isBati){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isBati && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;
				}
			}else if(abs(sp.x)<128){

				//交战策略
				if(abs(sp.x)> 96 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(abs(sp.x)<32 && ( _isCanSkill1 || _isCanOugis1 || _isCanSkill3) ){
					this->stepBack();
					return;
				}

				if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 && !_isBati){
					this->changeSide(sp);
					this->attack(OUGIS1);
				}else if(_isCanGear03){
					this->useGear(gear03);
				}else if(_isCanSkill3 && !_isBati && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL3);
				}else if(_isCanSkill1 && !_isBati && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL1);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
			
		}
			

	}
	//无玩家情况
	
	_mainTarget=NULL;
	if(!this->findEnemy2("Flog")){
		this->findEnemy2("Tower");
	}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && !_isBati){
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else {
				this->changeSide(sp);
				this->attack(NAttack);
			}	
		}

		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}
	
}

void Hero::AI_SageNaruto(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear03);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear07);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}


	if(this->checkRetri()){
			if(_mainTarget!=NULL){
				if(this->stepBack2()){
					return;
				};
			}else{
				
				if(this->stepBack()){
					return;
				};
			}
	};
	
	
	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}


	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game &&  !_isBati){
				this->changeSide(sp);
				this->attack(OUGIS2);
				return;
			}else if(_isCanSkill2 && !_isBati){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(_isCanSkill3 && !_isBati && _mainTarget->getGP()<5000){	
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isBati && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;
				}
			}else if(abs(sp.x)<128){

				//交战策略
				if(abs(sp.x)> 96 || abs(sp.y)> 32){				
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(abs(sp.x)<32 && _isCanSkill1){
					this->stepBack();
					return;
				}
				if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 && !_isBati){
					this->changeSide(sp);
					this->attack(OUGIS1);
				}else if(_isCanGear03){
					this->useGear(gear03);
				}else if(_isCanSkill1 && !_isBati && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL1);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && !_isBati){
				this->changeSide(sp);
				this->attack(SKILL2);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}

			
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}




}


void Hero::AI_RikudoNaruto(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear03);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear07);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}


	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(_isCanGear00){
				this->useGear(gear00);
			};
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}


	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game &&  !_isBati){
				this->changeSide(sp);
				this->attack(OUGIS2);
				return;
			}else if(_isCanSkill2 && !_isBati){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(_isCanSkill3 && !_isBati  && _mainTarget->getGP()<5000){
				this->changeSide(sp);
				this->attack(SKILL3);
				return;

			}else if(_isCanSkill1 && !_isBati && _mainTarget->getGP()<5000){
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if(_isCanGear03){
				this->useGear(gear03);
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isBati && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;
				}
			}else if(abs(sp.x)<128){

				//交战策略
				if(abs(sp.x)> 32 || abs(sp.y)> 32){	
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 && !_isBati){
					this->changeSide(sp);
					this->attack(OUGIS1);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill1  && !_isBati && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else if(_isCanSkill2 && !_isBati){
				this->changeSide(sp);
				this->attack(SKILL2);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}


		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}




}


void Hero::AI_Asuma(){
	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear05);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			
			if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){
				this->changeSide(sp);
				this->attack(OUGIS1);
				return;
			}else if(_isCanSkill3 && _mainTarget->getGP()<5000){
				//先手无视战斗力
				if((abs(sp.x)> 96 || abs(sp.y)> 32) ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(_isCanSkill2 && _mainTarget->getGP()<5000){
				//先手无视战斗力
				if((abs(sp.x)> 96 || abs(sp.y)> 32) ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else{
					this->idle();
					return;
				}
			}else if(abs(sp.x)<128){

				//交战策略
				if(abs(sp.x)> 96 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if((abs(sp.x)> 32 || abs(sp.y)>32) && !_isCanSkill2 ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
					&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
					){
						this->changeSide(sp);
						this->attack(OUGIS2);
				}else if(_isCanSkill1 && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL1);

				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}


	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else if(_isCanSkill1 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 ){
				this->changeSide(sp);
				this->attack(SKILL1);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}


void Hero::AI_Kakashi(){
	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear05);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}
	
	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};
	
	
	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			
			if(_isCanSkill3){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(_isCanSkill2 && _mainTarget->getGP()<5000){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {				
					this->idle();
					return;				
				}
			}else if(abs(sp.x)<128){
	
				//交战策略
				if((abs(sp.x)> 64 || abs(sp.y)> 32 ) ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				
				 if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
					 && _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
					 && _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
					 && !_mainTarget->_isSticking){
						 this->changeSide(sp);						
						 this->attack(OUGIS2);
				 }else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){
					 this->changeSide(sp);
					 this->attack(OUGIS1);
				 }else if(_isCanSkill1 && _mainTarget->getGP()<5000){
					 this->changeSide(sp);
					 this->attack(SKILL1);
				 }else{
					 this->changeSide(sp);
					 this->attack(NAttack);
				 }
				
				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
	if(!this->findEnemy2("Flog")){
		this->findEnemy2("Tower");
	}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill3 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL3);
				
			}else if(_isCanSkill1 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 ){
				this->changeSide(sp);
				this->attack(SKILL1);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}



void Hero::AI_Konan(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear03);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear05);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}

	
	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};
	
	
	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){
			
			if(_isCanSkill1 && !_isBati){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking
				&& !_isBati
				){
					if((abs(sp.x)> 48 || abs(sp.y)> 16)){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					this->changeSide(sp);
					this->attack(OUGIS2);
					return;

			 }else if(_mainTarget->getGP()<5000 && !_isVisable && !_isBati
				&& (_isCanSkill3 || _isCanSkill2)  &&
				_mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				){
				//先手无视战斗力
			
				if((abs(sp.x)> 128 || abs(sp.y)> 16)){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(abs(sp.x) < 96){
					this->stepBack();
					return;
				}
			
				if(_isCanSkill3){
					this->changeSide(sp);
					this->attack(SKILL3);				
				}else if(_isCanSkill2){
					this->changeSide(sp);
					this->attack(SKILL2);					
				}

				return;
		
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {		
					this->idle();
					return;		
				}
			}else if(abs(sp.x)<128){

				//交战策略
				if((abs(sp.x)> 8 || abs(sp.y)> 8) && _isBati){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if((abs(sp.x)> 48 || abs(sp.y)>32 )){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(abs(sp.x)<32 && !_isBati){
					this->stepBack();
					return;
				}

				
			    if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 && !_isBati){
					this->changeSide(sp);
					this->attack(OUGIS1);
				}else if(_isCanSkill2 && !_isBati  && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL2);
				}else{
					if(_isCanGear03){
						this->useGear(gear03);
					}
					if(!_isBati){
						this->changeSide(sp);
						this->attack(NAttack);
					}
				
				}
			
				return;
			}
		}
	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	
	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if((abs(sp.x)> 8 || abs(sp.y)> 8) && _isBati){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}else if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			if(_isCanGear03){
				this->useGear(gear03);
			}
			//技能清兵
			if(_isCanOugis1  && !_isControled && !_isBati 
				&& strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				
				this->attack(OUGIS1);
			}else if(_isCanSkill2 && !_isBati
				&& strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);
			}else if(!_isBati){
			this->changeSide(sp);
			this->attack(NAttack);
			}
		}
		return;

	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}



}

void Hero::AI_Deidara(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear05);
		}
	}



	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				if(_isCanGear00 && !_isBati){
					this->useGear(gear00);
				};
				return;
			};
		}else{

			if(this->stepBack()){
				return;
			};
		}
	};
	
	
	
	if(_mainTarget && (battleCondiction>=0 || _isCanSkill3 ||  _isCanOugis1 || _isBati)){
	
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			if(_isCanOugis2 && !_isControled 
			&& _delegate->_isOugis2Game 
			&& _mainTarget->getGP()<5000  
			&&!_isBati){
				if(abs(sp.x)> 48  || abs(sp.y)> 16){
					if(_isCanGear00){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;

				}else{
					this->changeSide(sp);
					this->attack(OUGIS2);
				}
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 &&!_isBati){
				this->changeSide(sp);
				this->attack(OUGIS1);
				return;
			}else if(_isCanSkill3 && _mainTarget->getGP()<5000  &&!_isBati){
				//先手无视战斗力
				if(abs(sp.x)> 64  || abs(sp.y)> 16){
					if(_isCanGear00){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				this->changeSide(sp);
				this->attack(SKILL3);	
				return;
			}else if(_isCanSkill2  && !_isBati){
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160 ){
					this->stepBack2();
					return;
				}else {
					if(_skillChangeBuffValue){
						if(!_isBati){
							this->changeSide(sp);
							this->attack(NAttack);
						}	
					}
					this->idle();
					return;
				
				}

			}else if(_isCanSkill1 &&!_isBati){
				this->changeSide(sp);
				this->attack(SKILL1);
				return;

			}else if(abs(sp.x)<128){

				//交战策略
				if( (abs(sp.x)> 8  || abs(sp.y)> 8) && _isBati){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if((abs(sp.x)> 32 || abs(sp.y)>32) && !_isCanSkill1 && !_skillChangeBuffValue){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				
					
				if(!_isBati){
					this->changeSide(sp);
					this->attack(NAttack);
				}		
			
				return;
			}
		}

	}
	
	//无玩家情况
	if(battleCondiction>=0){
		_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	}else {
		_mainTarget=NULL;
		this->findEnemy2("Tower");
	}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0 &&
				_isCanOugis2 &&
				!_isControled && _delegate->_isOugis2Game 
				 && !_isBati && isBaseDanger){

				this->changeSide(sp);
				this->attack(OUGIS2);

			}else if(_isCanSkill1 && !_isBati && strcmp(_mainTarget->getRole()->getCString(),"Tower")==0  ){
				this->changeSide(sp);
				this->attack(SKILL1);

			}else if(_isCanSkill2  &&!_isBati){
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(!_isBati){
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanGear00 && !_isBati){
			this->useGear(gear00);
		};
		this->stepOn();
	}

}


void Hero::AI_Ino(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	if(_skillChangeBuffValue){
		return;
	}

	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear05);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear01);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};



	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(atoi(this->getMaxHP()->getCString())- atoi(this->getHP()->getCString())>=3000 && 
		atoi(this->getCoin()->getCString())>=50 && !_isHealling && _isCanItem1 && _isBati){
			this->setItem(Item1);

	}
	

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game){
				if(abs(sp.x)> 96 || abs(sp.y)> 16){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{
					this->changeSide(sp);		
					this->attack(OUGIS2);
				}

				return;
			}else if( _mainTarget->getGP()<5000 
				&& (_isCanSkill3 || _isCanSkill2) ){
				//先手无视战斗力

				if(abs(sp.x)> 96  || abs(sp.y)> 16){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanSkill2){
					this->changeSide(sp);
					this->attack(SKILL2);	
				}else if(_isCanSkill3){
					this->changeSide(sp);
					this->attack(SKILL3);	
				}		

				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;
				}
			}else if(abs(sp.x)<128){

				//交战策略
			    if(abs(sp.x)> 32  || abs(sp.y)> 32 ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanOugis1  
					&& !_isControled  
					&& _mainTarget->getGP()<5000){
					this->changeSide(sp);	
					this->attack(OUGIS1);
				}else if(_isCanSkill1){
					this->changeSide(sp);
					this->attack(SKILL1);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill1 ){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}
	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}

void Hero::AI_Sai(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear05);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear01);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};
	

	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			
			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game &&!_isBati 
			&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
			&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
			&& !_mainTarget->_isSticking
			){
				if(abs(sp.x)> 48 || abs(sp.y)> 16){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{
					this->changeSide(sp);

					this->attack(OUGIS2);
				}
				return;
			}else if(_isCanSkill3 && _mainTarget->getGP()<5000  &&!_isBati){
				//先手无视战斗力
		
				if(abs(sp.x)> 64  || abs(sp.y)> 16){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{
				
					this->changeSide(sp);
					this->attack(SKILL3);
				
				} 
				return;

			}else if(_isCanSkill2  && _mainTarget->getGP()<5000 &&!_isBati){
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 &&!_isBati){

				this->changeSide(sp);
				this->attack(OUGIS1);
				return;

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					if(_skillChangeBuffValue){
						if(!_isBati){
							this->changeSide(sp);
							this->attack(NAttack);
						}	
					}
					this->idle();
					return;
					
				}
	
			}else if(_isCanSkill1 &&!_isBati){
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if(abs(sp.x) <128){

				//交战策略			
				if( (abs(sp.x)> 8  || abs(sp.y)> 8) && _isBati){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if((abs(sp.x)> 32  || abs(sp.y)> 32 )  && !_isCanSkill1 && !_skillChangeBuffValue){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
			
				if(!_isBati){
					this->changeSide(sp);
					this->attack(NAttack);
				}
				
				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill1 && !_isBati){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else if(_isCanSkill2  && _mainTarget->getGP()<5000 &&!_isBati
				 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);
			}else if(!_isBati){
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}
	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}



void Hero::AI_Sakura(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear04);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear08);
		}
	}

	
	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(_isCanGear00){
				this->useGear(gear00);
			};
			if(this->stepBack()){
				return;
			};
		}
	};

	if(_mainTarget && (battleCondiction>=0 || _isCanOugis1 || _isCanOugis2)){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game && !_skillChangeBuffValue
			&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
			&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
			&& !_mainTarget->_isSticking 
			){
				if(abs(sp.x)> 48 || abs(sp.y)> 16){
					if(_isCanGear00){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				this->changeSide(sp);
				this->attack(OUGIS2);
				return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 && !_skillChangeBuffValue){
				if(abs(sp.x)> 48 || abs(sp.y)> 16){
					if(_isCanGear00){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				
				this->changeSide(sp);
				this->attack(OUGIS1);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160 ){
					this->stepBack2();
					return;
				}else {	
					this->idle();
					return;
				}
			}else if(this->getHpPercent()<0.9 && _isCanSkill1){
				//先手无视战斗力
				this->attack(SKILL1);
				return;
			}else if(abs(sp.x) <128){

				//交战策略
				if((abs(sp.x)> 64 || abs(sp.y)> 32) && (!_isCanSkill2 ||  _mainTarget->getGP()<5000) ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(abs(sp.x)> 32 || abs(sp.y)>32 ){			
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
			
				 if(_isCanSkill2 && !_skillChangeBuffValue  && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL2);		
				}else if(_isCanSkill3 && !_skillChangeBuffValue && this->getHpPercent()>0.5){
					this->changeSide(sp);
					this->attack(SKILL3);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}
				return;
			}
			
		}

	}
	//无玩家情况
	if(battleCondiction>=0){
		_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	}else {
		_mainTarget=NULL;
		this->findEnemy2("Tower");
	}

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			
			if(_isCanSkill1 && this->getHpPercent()<0.9){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill2 ){
				this->changeSide(sp);
				this->attack(SKILL2);
			}else if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0  && _isCanSkill3 && !_skillChangeBuffValue){
				this->changeSide(sp);
				this->attack(SKILL3);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}

		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanGear00){
			this->useGear(gear00);
		};
		this->stepOn();
	}

	
}

void Hero::AI_Guardian(){

	if(!this->findTargetEnemy("Hero",true)){
		if(!this->findTargetEnemy("Flog",true)){
			if(!this->findTargetEnemy("Flog",false)){
				if(!this->findTargetEnemy("Hero",false)){
					_mainTarget=NULL;
				}
			}
		}
	}
	

	if(_mainTarget){
		CCPoint moveDirection;
		CCPoint sp=ccpSub(_mainTarget->getPosition(),this->getPosition());



		if(abs(sp.x)> 128 || abs(sp.y)> 16 ){

			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;

		}else if( abs(sp.x)> 32 || abs(sp.y)>32 ){

			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;

		}else if(this->getActionState()==ACTION_STATE_IDLE ||  this->getActionState()==ACTION_STATE_WALK || this->getActionState()==ACTION_STATE_ATTACK){
			bool isTurn=false;

			CCObject* pObject;
			CCARRAY_FOREACH(_delegate->_TowerArray,pObject){
				ActionManager* target=(ActionManager*) pObject;
				const char* gardTower;
				if(this->getDelegate()->zhenying>0){
					gardTower="AkatsukiCenter";
				}else{
					gardTower="KonohaCenter";
				}
				if(strcmp(target->getCharacter()->getCString(),gardTower)==0 && target->getHpPercent()<0.5f){
					isTurn=true;

				}
			}



			if(_isCanSkill1 && !_skillChangeBuffValue && (this->getHpPercent()<0.5f || isTurn)){
				this->changeSide(sp);
				this->attack(SKILL1);
				this->scheduleOnce(schedule_selector(Hero::enableSkill1),_sattackcoldDown1);
			}else if(_isCanSkill2 && _skillChangeBuffValue){
				this->changeSide(sp);
				this->attack(SKILL2);
				this->scheduleOnce(schedule_selector(Hero::enableSkill2),_sattackcoldDown2);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;

		

	}else{
		CCPoint moveDirection;
		CCPoint sp=ccpSub(this->getSpawnPoint(),this->getPosition());
		if(abs(sp.x)> 32 || abs(sp.y)> 32){

			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}else{

			this->idle();
		}


	}

	
}

void Hero::AI_Tenten(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear05);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}


	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(_isCanGear00){
				this->useGear(gear00);
			};
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{

			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(_isCanGear00){
				this->useGear(gear00);
			};
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			if(_isCanSkill1){
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game && _mainTarget->getGP()<5000 && !_skillChangeBuffValue){
				if(abs(sp.x)> 48  || abs(sp.y)> 16 ){
					if(_isCanGear00){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				this->changeSide(sp);

				this->attack(OUGIS2);
				return;
			}else if(_isCanOugis1  && !_isControled   && !_mainTarget->_isBati && _mainTarget->getGP()<5000 && !_skillChangeBuffValue ){

				if(abs(sp.x)> 48  || abs(sp.y)> 16 ){
					if(_isCanGear00){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				this->changeSide(sp);
				this->attack(OUGIS1);
				
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_skillChangeBuffValue && !_isControled ){
				//保持距离
				if(abs(sp.x)<160 ){
					this->stepBack2();
					return;
				}else {
					
					this->idle();
					return;
					
				}
			}else if(abs(sp.x) <128){

				//交战策略

				if((abs(sp.x)> 96  || abs(sp.y)> 16) && !_skillChangeBuffValue  ) {
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanSkill2 && _mainTarget->getGP()<5000 ){
					this->changeSide(sp);
					this->attack(SKILL2);		
				}else if(_isCanSkill3 && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL3);
				
				}else{				
					
					if ((abs(sp.x)> 32  || abs(sp.y)> 32 )&& !_skillChangeBuffValue ){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}else{
						this->changeSide(sp);
						this->attack(NAttack);
					}
					
				}

				return;
			}
		}

	}
	//无玩家情况
		_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill1){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill3){
				this->changeSide(sp);
				this->attack(SKILL3);
			}else if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill2 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanGear00){
			this->useGear(gear00);
		};
		this->stepOn();
	}


}
void Hero::AI_Itachi(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear02);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear05);
		}
	}



	if(this->checkRetri()){

		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};

	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game  &&  !_isBati){
				
				if(abs(sp.x)> 48 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				this->changeSide(sp);
				
				this->attack(OUGIS2);

				return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000
				&& !_mainTarget->_isBati
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking
				&& !_isBati){

				this->changeSide(sp);
				
				this->attack(OUGIS1);

				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isBati && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128 || _isBati){

				//交战策略
				 if( abs(sp.x)> 196 || abs(sp.y)> 64){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if((abs(sp.x)> 56 || abs(sp.y)> 32) && !_isBati){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				 }

				if(_isCanSkill3 && !_isBati && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL3);
				}else if(_isCanSkill2 && !_isBati && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL2);
				}else if(_isCanSkill1 && !_isBati && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL1);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
	if(!this->findEnemy2("Flog")){
		this->findEnemy2("Tower");
	}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill3 && !_isBati 
				&& strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
					this->changeSide(sp);
					this->attack(SKILL3);
			}else if(_isCanSkill2 && !_isBati 
				&& strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
					this->changeSide(sp);
					this->attack(SKILL2);
			}else if(_isCanSkill1  && !_isBati 
				&& strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 ){
					this->changeSide(sp);
					this->attack(SKILL1);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}

		}

		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}



}
void Hero::AI_Jiraiya(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			
			
			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game ){
				//先手无视战斗力
				this->changeSide(sp);
			
				this->attack(OUGIS2);
				return;
			}else if(_isCanSkill2 && _mainTarget->getGP()<5000){
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128){

				//交战策略
				if(abs(sp.x)> 32 || abs(sp.y)>32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){
					this->changeSide(sp);		
					this->attack(OUGIS1);
				}else if(_isCanSkill3  && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL3);
				}else if(_isCanSkill1  && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL1);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill3 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL3);

			}else if(_isCanSkill1 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL1);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}


}
void Hero::AI_SageJiraiya(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){


			if(_isCanSkill2 && _mainTarget->getGP()<5000){
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;
				}
			}else if(abs(sp.x)<128){
				//交战策略	
				if(abs(sp.x)> 96 || abs(sp.y)> 32 ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if((abs(sp.x)> 32 || abs(sp.y)>32)  && !_isCanOugis2){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game  && _mainTarget->getGP()<5000){
					//先手无视战斗力
					this->changeSide(sp);	
					this->attack(OUGIS2);
					return;
				}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){

					this->changeSide(sp);
					
					this->attack(OUGIS1);

				}else if(_isCanSkill3  && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL3);

				}else if(_isCanSkill1  && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL1);

				}else{

					if(abs(sp.x)> 32 || abs(sp.y)>32){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}else{

						this->changeSide(sp);
						this->attack(NAttack);
					}

				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	
	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill3 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL3);

			}else if(_isCanSkill1 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL1);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}

void Hero::AI_Suigetsu(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");



	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear05);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear01);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				if(_isCanGear00){
					this->useGear(gear00);
				};
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){

			if(_isCanGear00){
				this->useGear(gear00);
			};

			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
	
			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&&!_isBati 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking
				){
					if(abs(sp.x)> 48 || abs(sp.y)> 16){
						if(_isCanGear00){
							this->useGear(gear00);
						};
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					this->changeSide(sp);
					this->attack(OUGIS2);
					return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 &&!_isBati){
				if(abs(sp.x)> 48 || abs(sp.y)> 16){
					if(_isCanGear00){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				
				this->changeSide(sp);
				this->attack(OUGIS1);
				return;

			}else if(_isCanSkill3 && _mainTarget->getGP()<5000 && !_isBati && !_skillChangeBuffValue){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128){

				//交战策略
				if(abs(sp.x)> 96  || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if((abs(sp.x)> 32 || abs(sp.y)>32) && !_isBati){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanSkill2 && _mainTarget->getGP()<5000 && !_isBati){
					this->changeSide(sp);
					this->attack(SKILL2);		
				}else if(_isCanSkill1  && _mainTarget->getGP()<5000 &&!_isBati){
					this->changeSide(sp);
					this->attack(SKILL1);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
					
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill1 && !_isBati){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else if(_isCanSkill2  && _mainTarget->getGP()<5000 &&!_isBati
				&& strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
					this->changeSide(sp);
					this->attack(SKILL2);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}
	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}

void Hero::AI_Tsunade(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear03);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear02);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear04);
		}
	}


	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){
			//先手无视战斗力
			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game && _mainTarget->getGP()<5000  &&!_isBati){

				if(abs(sp.x)> 64  || abs(sp.y)> 16){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;

				}else{
					this->changeSide(sp);
				
					this->attack(OUGIS2);
				}
				return;

			}else if(_isCanSkill3 && _mainTarget->getGP()<5000  &&!_isBati){

				this->changeSide(sp);
				this->attack(SKILL3);
				return;

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled && !_isBati){
				//保持距离
				if(abs(sp.x)<160 ){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128){


				//交战策略

				if( abs(sp.x)> 64  || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(abs(sp.x)> 32 || abs(sp.y)>32  && !_isCanSkill2  &&!_isBati && !_isCanOugis1){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				if(_isCanGear03){
					this->useGear(gear03);
				}
				if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 &&!_isBati){
					this->changeSide(sp);		
					this->attack(OUGIS1);
				}else if(_isCanSkill2  &&!_isBati){
					this->changeSide(sp);
					this->attack(SKILL2);
					return;
				}else if(_isCanSkill1 &&!_isBati){
					this->changeSide(sp);
					this->attack(SKILL1);

				}else{	
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			if(_isCanGear03){
				this->useGear(gear03);
			}
			//技能清兵
			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill1 && !_isBati && isBaseDanger ){
				this->changeSide(sp);
				this->attack(SKILL1);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}
}


void Hero::AI_Sasuke(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}


	if(this->checkRetri()){

		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			
			if(this->stepBack()){
				return;
			};
		}
	};

	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game  &&  !_isBati){
				this->changeSide(sp);	
				this->attack(OUGIS2);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isBati && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}
			}else if(_isCanSkill3 && !_isTaunt && !_isBati){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(abs(sp.x)<128){

				//交战策略

				if(abs(sp.x)> 96 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if((abs(sp.x)> 32 || abs(sp.y)>32) && !_isCanSkill1 && !_isCanSkill2){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 && !_isBati){			
					if(abs(sp.x)> 32 || abs(sp.y)>32){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}
					this->changeSide(sp);			
					this->attack(OUGIS1);

				}else if(_isCanSkill2 && !_isBati && _mainTarget->getGP()<5000){
					 this->changeSide(sp);
					 this->attack(SKILL2);

				 }else if(_isCanSkill1 && !_isBati && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL1);

				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill1  && !_isBati && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else if(_isCanSkill2  && isBaseDanger && !_isBati && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL2);
			}else if(_isCanSkill3  && !_isBati && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL3);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}

		}

		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}
void Hero::AI_ImmortalSasuke(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}


	if(this->checkRetri()){

		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{

			if(this->stepBack()){
				return;
			};
		}
	};

	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 && !_isBati){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(OUGIS1);
				return;

			}else if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game  &&  !_isBati){

				if(abs(sp.x)> 48 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}	

				this->changeSide(sp);
				this->attack(OUGIS2);
				return;
			} else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isBati && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(_isCanSkill3 && !_isBati && !_isTaunt){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(abs(sp.x)<128 || _isBati){

				
				//交战策略
				if( abs(sp.x)> 196 || abs(sp.y)> 64){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if((abs(sp.x)> 96 || abs(sp.y)> 32) && !_isBati ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if((abs(sp.x)> 32 || abs(sp.y)> 32) && !_isCanSkill1 && !_isCanSkill2 ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanSkill2 && !_isBati && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL2);

				}else if(_isCanSkill1 && !_isBati && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL1);

				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill1   && !_isBati && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else if(_isCanSkill2  && isBaseDanger && !_isBati && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL2);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}

		}

		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}
}

void Hero::AI_Kankuro(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear04);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear08);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 
		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	bool isFound1=false;
	bool isFound2=false;
	bool isFound3=false;

	if(getMonsterArray() && getMonsterArray()->count()>0){
		CCObject* pObject;
		CCARRAY_FOREACH(getMonsterArray(),pObject){
			Monster* mo=(Monster*) pObject;
			if (strcmp(mo->getCharacter()->getCString(),"Saso")==0){
				isFound3=true;
			};
			if (strcmp(mo->getCharacter()->getCString(),"Sanshouuo")==0){
				isFound2=true;
			}
			if (strcmp(mo->getCharacter()->getCString(),"Karasu")==0){
				isFound1=true;
			};
		}
	};
	

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){


			if(_isCanSkill3){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(_isCanSkill1 && ! isFound1 &&!_isControled){
				this->attack(SKILL1);
				return;
			}else if(_isCanOugis1  && !_isControled && ! isFound2){
				this->changeSide(sp);
				this->attack(OUGIS1);
				return;
			}else if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game && ! isFound3 ){
				this->changeSide(sp);	
				this->attack(OUGIS2);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>5000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;
				}

			}else if(abs(sp.x)<128){

				
				//交战策略

				if(abs(sp.x)> 32 || abs(sp.y)>32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{
					this->changeSide(sp);
					this->attack(NAttack);

				}
					
				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanOugis1  && !_isControled && !isFound2){
				this->changeSide(sp);	
				this->attack(OUGIS1);
			}else if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game  && !isFound3){
				this->changeSide(sp);			
				this->attack(OUGIS2);
			}else if(_isCanSkill1 && ! isFound1){
				this->attack(SKILL1);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}


void Hero::AI_Chiyo(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear07);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear04);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 
		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	bool isFound1=false;

	if(getMonsterArray() && getMonsterArray()->count()>0){
		CCObject* pObject;
		CCARRAY_FOREACH(getMonsterArray(),pObject){
			Monster* mo=(Monster*) pObject;
			if (strcmp(mo->getCharacter()->getCString(),"Parents")==0){
				isFound1=true;
			};
		}
	};


	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){
			if(_isCanOugis1 && !_isControled && !_buffStartTime){
				
				CCObject* pObject;
				int countNum=0;
				CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
					Hero* tempHero=(Hero*) pObject;
					if(strcmp(this->getGroup()->getCString(),tempHero->getGroup()->getCString())==0
						&& (strcmp(tempHero->getRole()->getCString(),"Player")==0 || strcmp(tempHero->getRole()->getCString(),"Com")==0)
						&& tempHero->_actionState!=ACTION_STATE_DEAD
						&& strcmp(tempHero->getCharacter()->getCString(),"Chiyo")!=0
						){
							CCPoint	sp=ccpSub(tempHero->getPosition(),this->getPosition());
							if(sp.x<=winSize.width/2){
								countNum++;
							}

					}
					
				}
				if(countNum>=1){
					this->attack(OUGIS1);
					return;
				}

			}
			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking){

					if(abs(sp.x)> 96 || abs(sp.y)>32){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}else if(abs(sp.x)<48){
						this->stepBack();
						return;
					}	
				this->changeSide(sp);	
				this->attack(OUGIS2);
				
			}else if(_isCanSkill1 && ! isFound1 &&!_isControled){
				this->attack(SKILL1);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>5000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;
				}

			}else if(abs(sp.x)<128){


				//交战策略

				if(abs(sp.x)> 32 || abs(sp.y)>32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{
					this->changeSide(sp);
					this->attack(NAttack);

				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
	if(!this->findEnemy2("Flog")){
		this->findEnemy2("Tower");
	}


	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill1 && ! isFound1){
				this->attack(SKILL1);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}

void Hero::AI_Kakuzu(){

	_mainTarget=NULL;
	if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

		if(this->getHpPercent()>0.3f && !_isControled && _isCanSkill1){
			CCObject* pObject;
			float distance;
			float curDistance=NULL ;
			CCPoint sp;
	
			CCARRAY_FOREACH(this->getDelegate()->_CharacterArray,pObject){
				ActionManager* target=(ActionManager*) pObject;
				if((strcmp(target->getRole()->getCString(),"Player")==0 ||
					strcmp(target->getRole()->getCString(),"Com")==0) &&
					target->getActionState()==ACTION_STATE_DEAD
					){
						distance=ccpDistance(target->getPosition(),this->getPosition());
						sp=ccpSub(target->getPosition(),this->getPosition());

						if(abs(sp.x)<(winSize.width/2)){
							if(target->_isTaunt){
								_mainTarget=target;
						
							}
							if(curDistance && abs(curDistance)>abs(distance)){
								_mainTarget=target;
								curDistance=distance;
							}else if(!curDistance){
								curDistance=distance;
								_mainTarget=target;
							
							};

						}
				}
			}

			if(_mainTarget){
				CCPoint moveDirection;
				if(_mainTarget->_originY){
					sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
				}else{
					sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
				}

				if(abs(sp.x)> 32 || abs(sp.y)>32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{
					this->changeSide(sp);
					this->attack(SKILL1);		
				}

				return;
			}

		}
	
	}


	this->findEnemy2("Hero");

	
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear03);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear08);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear04);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 
		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	bool isSummonAble=false;

	if((getMonsterArray() && getMonsterArray()->count()<3 || !_monsterArray ) && hearts>0){
		isSummonAble=true;
	}


	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){
	

			if(_isCanSkill3){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(_isCanOugis1  && !_isControled  && isSummonAble ){
				this->attack(OUGIS1);
				return;
			}else if(_isCanSkill2){

				if(abs(sp.x)> 96 || abs(sp.y)> 32 ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanGear03){
					this->useGear(gear03);
				}

				this->changeSide(sp);
				this->attack(SKILL2);		
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>5000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;
				}

			}else if(abs(sp.x)<128){

				
				//交战策略	
				if(abs(sp.x)> 32 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{

					this->changeSide(sp);
					this->attack(NAttack);
						
				}

				return;
			}
		}

	}
	//无玩家情况
	
	if(!this->findEnemy2("Flog")){
		this->findEnemy2("Tower");
	}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanOugis1  && !_isControled && !isSummonAble){
				this->changeSide(sp);
				this->attack(OUGIS1);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}


void Hero::AI_Shikamaru(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");



	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear07);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear08);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){

			if(this->stepBack2()){
				return;
			};
		}else{
			if(_isCanGear00 ){
				this->useGear(gear00);
			};
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK  ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& !_mainTarget->_isSticking){

					this->changeSide(sp);
					this->attack(OUGIS2);
					return;
			}else if(_isCanSkill2 && _mainTarget->getGP()<5000){
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){

				if(abs(sp.x)> 48 || abs(sp.y)> 32 ){
					if(_isCanGear00 ){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				this->changeSide(sp);
				this->attack(OUGIS1);
				return;

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(this->getLV()>=2 && _isCanSkill1){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL1);
				return;

			}else if(_isCanSkill3 && _mainTarget->getGP()<5000 && !_mainTarget->_isBati  && !_mainTarget->_isSticking){

				if(abs(sp.x)> 156 || abs(sp.y)> 32 ){
					if(_isCanGear00 ){
						this->useGear(gear00);
					};

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if( abs(sp.x)<32){
					this->stepBack();
					return;
				}


				this->changeSide(sp);
				this->attack(SKILL3);
				return;

			}else if(abs(sp.x)<128){


				//交战策略
				if(abs(sp.x)> 32 || abs(sp.y)>32 ){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
	if(!this->findEnemy2("Flog")){
		this->findEnemy2("Tower");
	}


	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanGear00 ){
			this->useGear(gear00);
		};
		this->stepOn();
	}

}
void Hero::AI_Gaara(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear02);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear05);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game &&!_isBati 
				&& _mainTarget->getGP()<5000 ){		
					this->changeSide(sp);		
					this->attack(OUGIS2);
					return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 &&!_isBati){
				this->changeSide(sp);	
				this->attack(OUGIS1);
				return;
			}else if(_isCanSkill3 && _mainTarget->getGP()<5000  &&!_isBati){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(_isCanSkill2  && _mainTarget->getGP()<5000 &&!_isBati){
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled &&!_isBati){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;
				}
			}else if(abs(sp.x)< 128){ 

				//交战策略
				if(abs(sp.x)> 32 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				
				if(_isCanSkill1 &&!_isBati){
					 this->changeSide(sp);
					 this->attack(SKILL1);
				 }else{
					this->changeSide(sp);
					this->attack(NAttack);
				}
				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill1 && !_isBati){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}
	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}
}
void Hero::AI_Tobirama(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear07);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			
			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000){
					//先手无视战斗力
					this->changeSide(sp);	
					this->attack(OUGIS2);
			}else if(_isCanSkill1 && !_mainTarget->_isBati &&(
				 _mainTarget->getActionState()==ACTION_STATE_IDLE ||
				_mainTarget->getActionState()==ACTION_STATE_WALK ||
				_mainTarget->getActionState()==ACTION_STATE_ATTACK
				)
				){	
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if(_isCanSkill2 && _mainTarget->getGP()<5000){

				if((abs(sp.x)> 64 || abs(sp.y)> 16) ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				this->changeSide(sp);
				this->attack(SKILL2);			
				return;

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128){ 

				//交战策略

				if(abs(sp.x)> 48 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){
					this->changeSide(sp);	
					this->attack(OUGIS1);

				}else if(_isCanSkill3){
					this->changeSide(sp);
					this->attack(SKILL3);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
		_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill3 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL3);

			}else if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}

}

void Hero::AI_Orochimaru(){
}

void Hero::AI_Choji(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear04);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){

			if(_isCanSkill1 && !_isBati){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if(_isCanSkill3 && _mainTarget->getGP()<5000 && !_isBati){

				if(abs(sp.x)> 96 || abs(sp.y)> 16){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				this->changeSide(sp);
				this->attack(SKILL3);
				return;

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled && !_isBati){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128){ 

				//交战策略
				if(abs(sp.x)> 32 || abs(sp.y)>32){				
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 && !_isBati){
					this->changeSide(sp);
					this->attack(OUGIS1);

				}else if(_isCanSkill2 && _mainTarget->getGP()<5000 && !_isBati && _skillUPBuffValue){
					this->changeSide(sp);
					this->attack(SKILL2);
				}else if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
					&& _mainTarget->getGP()<5000 
					&& !_isBati
					){
						this->changeSide(sp);
						this->attack(OUGIS2);

				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	
	//无玩家情况
	if(battleCondiction>=0){
		_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	}else{
		_mainTarget=NULL;
		this->findEnemy2("Tower");
	}

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && !_isBati &&  strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL2);
			}else if(_isCanOugis1  && !_isControled && isBaseDanger && !_isBati &&  strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(OUGIS1);
			}else if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& strcmp(_mainTarget->getRole()->getCString(),"Tower")==0
				&& !_isBati
				){
					this->changeSide(sp);
					this->attack(OUGIS2);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}
}


void Hero::AI_Karin(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear07);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking 
				){
					if(abs(sp.x)> 96 || abs(sp.y)> 16){

						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}
					this->changeSide(sp);
					this->attack(OUGIS2);
					return;

			}else if(this->getHpPercent()<0.9 && _isCanOugis1 && !_isControled && !_buffStartTime && !_isHealling){
				this->changeSide(sp);	
				this->attack(OUGIS1);
				return;
			}else if(_isCanSkill3 && _mainTarget->getGP()<5000){
				//先手无视战斗力
				if((abs(sp.x)> 128 || abs(sp.y)> 16) ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				this->changeSide(sp);
				this->attack(SKILL3);
				return;

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160 ){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;
				}

			}else if(abs(sp.x)<128){ 
				
				//交战策略

				if(abs(sp.x)> 96 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}	
				if(_isCanSkill2){
					this->changeSide(sp);
					this->attack(SKILL2);

				}else if(_isCanSkill1){
					this->changeSide(sp);
					this->attack(SKILL1);
				}else{

					if(abs(sp.x)> 32 || abs(sp.y)>32){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	
	if(!this->findEnemy2("Flog")){
		this->findEnemy2("Tower");
	}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill1 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 ){
				this->changeSide(sp);
				this->attack(SKILL1);

			}else if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}
}
void Hero::AI_Lee(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear07);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if((_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ) && abs(sp.x)<128  ){
			if(_isCanSkill1 && bamen<5){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128){ 

				//交战策略
				if(abs(sp.x)> 48 || abs(sp.y)> 32 ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 
					&& !_mainTarget->_isBati 
					&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
					&& !_mainTarget->_isSticking
					&& bamen>=1
					){

						this->changeSide(sp);
						this->attack(OUGIS1);
				}else if(_isCanSkill2){
					this->changeSide(sp);
					this->attack(SKILL2);

				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 ){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}
}

void Hero::AI_RockLee(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear07);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			if(_isCanSkill1 && bamen<5){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking
				&& bamen>=3
				){

					this->changeSide(sp);
				
					this->attack(OUGIS2);

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128 || bamen>=5){ 

				
				//交战策略

				if(abs(sp.x)> 46 || abs(sp.y)> 32){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 
					&& !_mainTarget->_isBati 
					&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
					&& !_mainTarget->_isSticking
					&& bamen>=1
					){

						this->changeSide(sp);

						this->attack(OUGIS1);

				}else if(_isCanSkill2){
					this->changeSide(sp);
					this->attack(SKILL2);

				}else if(_isCanSkill3 && bamen>=3){
					this->changeSide(sp);
					this->attack(SKILL3);

				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
	if(!this->findEnemy2("Flog")){
		this->findEnemy2("Tower");
	}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 ){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else if(_isCanSkill3 && bamen>=3 && isBaseDanger && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 ){
				this->changeSide(sp);
				this->attack(SKILL3);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}
}

void Hero::AI_Nagato(){
}

void Hero::AI_Jugo(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			if(_isCanSkill3 && _mainTarget->getGP()<5000  && !_skillChangeBuffValue){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;

				}

			}else if(abs(sp.x)<128){ 

				//交战策略

				if(abs(sp.x)> 96  || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
					&& !_skillChangeBuffValue
					&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
					&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
					&& !_mainTarget->_isSticking
					){

						if(abs(sp.x)> 32 || abs(sp.y)>32){
							moveDirection =ccpNormalize(sp);
							this->walk(moveDirection);
							return;
						}
						this->changeSide(sp);
						this->attack(OUGIS2);

				}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000  && !_skillChangeBuffValue){

					if(abs(sp.x)> 32 || abs(sp.y)>32){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					this->changeSide(sp);
				
					this->attack(OUGIS1);

				}else if(_isCanSkill2 && _mainTarget->getGP()<5000  && !_skillChangeBuffValue ){

					this->changeSide(sp);
					this->attack(SKILL2);
					return;

				}else if(_isCanSkill1  && _mainTarget->getGP()<5000  && !_skillChangeBuffValue){
					this->changeSide(sp);
					this->attack(SKILL1);

				}else{

					if(abs(sp.x)> 48 || abs(sp.y)>32){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}else{

						this->changeSide(sp);
						this->attack(NAttack);
					}
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill1 && !_skillChangeBuffValue){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}
	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}


}


void Hero::AI_Kisame(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");



	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear05);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){

			if(this->stepBack2()){
				return;
			};
		}else{
			if(_isCanGear00 ){
				this->useGear(gear00);
			};
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if((_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ) && ( abs(sp.x)<128  || _isCanGear00) ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking && !_skillChangeBuffValue){

					if(abs(sp.x)> 48|| abs(sp.y)> 32 ){
						if(_isCanGear00 ){
							this->useGear(gear00);
						};
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					this->changeSide(sp);

					this->attack(OUGIS2);
					return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 && !_skillChangeBuffValue){

				if(abs(sp.x)> 48 || abs(sp.y)> 32 ){
					if(_isCanGear00 ){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				this->changeSide(sp);
				this->attack(OUGIS1);
				return;

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled && !_skillChangeBuffValue){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(_isCanSkill3 && !_skillChangeBuffValue){
				if(abs(sp.x)> 96 || abs(sp.y)> 32 ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(_isCanSkill2 && _mainTarget->getGP()<5000 && !_skillChangeBuffValue){

				if(abs(sp.x)> 96 || abs(sp.y)> 32 ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				this->changeSide(sp);
				this->attack(SKILL2);
				return;

			}else if(abs(sp.x)<128){


				//交战策略
				if(abs(sp.x)> 64 || abs(sp.y)>32 ){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanSkill1 && _mainTarget->getGP()<5000  && !_skillChangeBuffValue){
					this->changeSide(sp);
					this->attack(SKILL1);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
	if(!this->findEnemy2("Flog")){
		this->findEnemy2("Tower");
	}


	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else if(_isCanSkill1 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 ){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanGear00 ){
			this->useGear(gear00);
		};
		this->stepOn();
	}
}



void Hero::AI_Hidan(){

	_mainTarget=NULL;
	bool _isFound=false;
	if(getMonsterArray() && getMonsterArray()->count()>0){
		CCObject* pObject;
		CCARRAY_FOREACH(getMonsterArray(),pObject){
			Monster* mo=(Monster*) pObject;
			if (strcmp(mo->getCharacter()->getCString(),"CircleMark")==0){
				_mainTarget=mo;
				_isFound=true;
				CCPoint moveDirection;
				CCPoint sp;

				if(_mainTarget->_originY){
					sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
				}else{
					sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
				}
				if((abs(sp.x)> 8|| abs(sp.y)> 8)){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{
					if(_isBati){

						CCObject* pObject;
						CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){
							ActionManager* tempHero=(ActionManager*) pObject;
							if( strcmp(tempHero->getGroup()->getCString(),this->getGroup()->getCString())!=0
								&& atoi(tempHero->getHP()->getCString())<2000
								&& tempHero->getActionState()!=ACTION_STATE_DEAD
								&& (strcmp(tempHero->getRole()->getCString(),"Player")==0 ||
								strcmp(tempHero->getRole()->getCString(),"Com")==0
								)
								){
									this->attack(NAttack);
									return;
							}
						};

						this->idle();
						return;

					}
				}

			};
		};

	}

	

	if(!_isFound){
		this->findEnemy2("Hero");
	}


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear07);
		}
	}

	if(this->checkRetri() && !_isBati  && !_isFound){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled && !_isBati  && !_isFound){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game  && !_isBati){
				if(abs(sp.x)> 48 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				if(_isCanSkill1  && !_isBati && !_isFound){
					this->changeSide(sp);
					this->attack(SKILL1);
					return;
				}
				this->changeSide(sp);		
				this->attack(OUGIS2);
				return;
			}else if(_isCanSkill2 && _mainTarget->getGP()<5000 && !_isBati ){
				//先手无视战斗力
				
				if(abs(sp.x)> 56 || abs(sp.y)> 32){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				this->changeSide(sp);
				this->attack(SKILL2);
				return;

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled && !_isBati && !_isFound){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128){ 

				//交战策略
				if((abs(sp.x)> 48 || abs(sp.y)> 32) && !_isBati){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				if(_isCanOugis1 && !_isBati  && !_isControled  && _mainTarget->getGP()<5000){
					this->changeSide(sp);	
					this->attack(OUGIS1);
				}else if(_isCanSkill3 && !_isBati){
					this->changeSide(sp);
					this->attack(SKILL3);
				}else{			
					if(!_isBati){
						this->changeSide(sp);
						this->attack(NAttack);
					}else{
						this->idle();
					}		
				}

				return;
			}
		}

	}

	


	//无玩家情况
	if(!_mainTarget && !_isFound && !_isBati){
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Mon")!=0  && !_isBati ){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill3 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger && !_isBati){
				this->changeSide(sp);
				this->attack(SKILL3);

			}else if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger && !_isBati){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}
		}
		return;
	}
	if(!_isBati){
		if(_isHealling &&this->getHpPercent()<1){
			if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
				this->idle();
			}
		}else{
			this->stepOn();
		}
	}else{
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}
	
}

void Hero::AI_Tobi(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");



	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear03);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear02);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear05);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			
			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking){

					if(abs(sp.x)> 48 || abs(sp.y)> 16 ){

						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					this->changeSide(sp);
					this->attack(OUGIS2);
					return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){
				this->changeSide(sp);
				
				this->attack(OUGIS1);
				return;
			}else if(_isCanSkill3 && !_skillChangeBuffValue){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled && !_skillChangeBuffValue){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128){ 
				//交战策略

				if(abs(sp.x)> 64 || abs(sp.y)> 32 ){
					
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else if(abs(sp.x)<32 && (_isCanSkill2 && _mainTarget->getHpPercent()<0.5f) ){
					this->stepBack();
					return;
				}
				
				if(_isCanSkill2 && _mainTarget->getGP()<5000 && (_mainTarget->getHpPercent()<0.5f || !_skillChangeBuffValue) ){
					
					this->changeSide(sp);
					this->attack(SKILL2);
					
				}else if(_isCanSkill1 && _mainTarget->getGP()<5000  && (_mainTarget->getHpPercent()<0.5f ||  !_skillChangeBuffValue) ){
					this->changeSide(sp);
					this->attack(SKILL1);
					
				}else{

					if(abs(sp.x)> 32 || abs(sp.y)>32 ){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					if(_isCanGear03){
						this->useGear(gear03);
					}

					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else if(_isCanSkill1 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0){
				this->changeSide(sp);
				this->attack(SKILL1);

			}else{

				if(_isCanGear03){
					this->useGear(gear03);
				}
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		this->stepOn();
	}


}

void Hero::AI_Shino(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			
			if(this->stepBack2()){
				return;
			};
		}else{
			if(_isCanGear00 ){
				this->useGear(gear00);
			};
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(_isCanGear00 ){
				this->useGear(gear00);
			};
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK  ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking){

					if(abs(sp.x)> 64 || abs(sp.y)> 16 ){
						if(_isCanGear00 ){
							this->useGear(gear00);
						};
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					this->changeSide(sp);
					this->attack(OUGIS2);
					return;

			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){

				if(abs(sp.x)> 64 || abs(sp.y)> 16 ){
					if(_isCanGear00 ){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);

					return;
				}

				this->changeSide(sp);

				this->attack(OUGIS1);

			}else if(_isCanSkill2 && _mainTarget->getGP()<5000){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(_isCanSkill3 && _mainTarget->getGP()<5000){

				if(abs(sp.x)> 64  || abs(sp.y)> 16){

					if(_isCanGear00 ){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{

					this->changeSide(sp);
					this->attack(SKILL3);

				} 
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					if(_skillChangeBuffValue){
						this->changeSide(sp);
						this->attack(NAttack);
					}else{
						this->idle();
					}
					
					return;

				}

			}else if(_isCanSkill1){
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if(abs(sp.x)<128){ 
				if(atoi(this->getMaxHP()->getCString())- atoi(this->getHP()->getCString())>=3000 && 
					atoi(this->getCoin()->getCString())>=50 && !_isHealling && _isCanItem1){
						this->setItem(Item1);					
				}

				//交战策略
				if( (abs(sp.x)> 32 || abs(sp.y)>32 ) && !_skillChangeBuffValue){	
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				
				this->changeSide(sp);
				this->attack(NAttack);		

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill3 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL3);

			}else if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else if(_isCanSkill1 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 ){
				this->changeSide(sp);
				this->attack(SKILL1);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanGear00 ){
			this->useGear(gear00);
		};
		this->stepOn();
	}

}

void Hero::AI_Hiruzen(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");

	
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear02);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear08);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(_isCanGear00){
				this->useGear(gear00);
			};
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(_isCanGear00){
				this->useGear(gear00);
			};
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&&!_isBati 
				&& atoi(_mainTarget->getHP()->getCString())<10000
				&& !_mainTarget->_isCanGear06
				){
					if(abs(sp.x)<32){
						this->stepBack();
						return;
					}else if(abs(sp.x)> 96 || abs(sp.y)> 32){
						if(_isCanGear00){
							this->useGear(gear00);
						};
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					this->changeSide(sp);
					this->attack(OUGIS2);
					return;
			}else  if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 &&!_isBati){
				if(abs(sp.x)> 48 || abs(sp.y)> 16){
					if(_isCanGear00){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				this->changeSide(sp);
				
				this->attack(OUGIS1);
				return;

			}else if(_isCanSkill3 && _mainTarget->getGP()<5000 && !_isBati && !_skillChangeBuffValue){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {
					this->idle();
					return;

				}
			}else if(abs(sp.x)<128){ 

				//交战策略
				if(abs(sp.x)> 96  || abs(sp.y)> 32){		
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				
				if(_isCanSkill1  && _mainTarget->getGP()<5000 &&!_isBati){
					if((abs(sp.x)> 32 || abs(sp.y)>32)){
						
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}
					this->changeSide(sp);
					this->attack(SKILL1);
				}else if(_isCanSkill2 && _mainTarget->getGP()<5000 && !_isBati){
					if(abs(sp.x)<32){
						this->stepBack();
						return;
					}
					this->changeSide(sp);
					this->attack(SKILL2);
				}else{

					if(abs(sp.x)> 32 || abs(sp.y)>32){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}else{

						this->changeSide(sp);
						this->attack(NAttack);
					}
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && _isCanSkill1 && !_isBati){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else if(_isCanSkill2  && _mainTarget->getGP()<5000 &&!_isBati
				&& strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
					this->changeSide(sp);
					this->attack(SKILL2);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}
		}
		return;
	}
	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanGear00){
			this->useGear(gear00);
		};
		this->stepOn();
	}

}

void Hero::AI_Kiba(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear04);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear08);
		}
	}


	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(_isCanGear00){
				this->useGear(gear00);
			};
			if(this->stepBack()){
				return;
			};
		}
	};

	if(_mainTarget && (battleCondiction>=0 || _isCanOugis1 || _isCanOugis2)){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game && !_powerUPBuffValue
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking 
				){
					if(abs(sp.x)> 32 || abs(sp.y)>32){
						if(_isCanGear00){
							this->useGear(gear00);
						};
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					this->changeSide(sp);
				
					this->attack(OUGIS2);
					return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000 && !_powerUPBuffValue){
				this->changeSide(sp);		
				this->attack(OUGIS1);
				return;
			}else if(_isCanSkill1 && _isBati){
				//先手无视战斗力
				this->attack(SKILL1);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160 ){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;
				}

			}else if(abs(sp.x)<128){ 

				//交战策略

				if(abs(sp.x)> 32 || abs(sp.y)>32){
					if(_isCanGear00){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}


				if(_isCanSkill3 && !_powerUPBuffValue && !_isBati  && this->getHpPercent()>0.5){
					this->changeSide(sp);
					this->attack(SKILL3);

				}else{

					this->changeSide(sp);
					this->attack(NAttack);

				}
				return;
			}

		}

	}
	//无玩家情况
	if(battleCondiction>=0){
		_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	}else {
		_mainTarget=NULL;
		this->findEnemy2("Tower");
	}

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			if(_isCanSkill1 && _isBati){
				this->attack(SKILL1);
			}else if(strcmp(_mainTarget->getRole()->getCString(),"Tower")==0  && _isCanSkill3 && !_powerUPBuffValue && !_isBati ){
				this->changeSide(sp);
				this->attack(SKILL3);
			}else{
				this->changeSide(sp);
				this->attack(NAttack);
			}

		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanGear00){
			this->useGear(gear00);
		};
		this->stepOn();
	}



}


 

void Hero::AI_Minato(){

	_mainTarget=NULL;
	this->findEnemy2("Hero");


	if(_isCanGear06){
		if((this->getActionState()==ACTION_STATE_FLOAT||
			this->getActionState()==ACTION_STATE_AIRHURT ||
			this->getActionState()==ACTION_STATE_HURT ||
			this->getActionState()==ACTION_STATE_KOCKDOWN
			) && this->getHpPercent()<0.5 && !_isBati && !_isWudi){
				this->useGear(gear06);
		}
	}
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear06);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear05);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}
	if(this->getHpPercent()<0.3f){

		if(_isCanSkill1){

			CCObject* pObject;
			bool isMark=false;
			if(this->getMonsterArray() && this->getMonsterArray()->count()>0){
				CCARRAY_FOREACH(this->getMonsterArray(),pObject){
					Monster* mo=(Monster*) pObject;
					if(strcmp(mo->getCharacter()->getCString(),"HiraishinMark")==0){
						if(strcmp(this->getGroup()->getCString(),"Konoha")==0 && mo->getPositionX()<this->getPositionX()){
							isMark=true;
						}else if(strcmp(this->getGroup()->getCString(),"Akatsuki")==0 && mo->getPositionX()>this->getPositionX()){
							isMark=true;
						}
					};
				};
			};
			if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
				if(isMark){
					this->attack(SKILL1);
					return;
				};
			};

		};
	}
	

	if(this->checkRetri()){
		

		if(_mainTarget!=NULL){
			if(this->stepBack2()){
				return;
			};
		}else{
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){

			CCObject* pObject;
			bool isMark=false;
			if(this->getMonsterArray() && this->getMonsterArray()->count()>0){
				CCARRAY_FOREACH(this->getMonsterArray(),pObject){
					Monster* mo=(Monster*) pObject;
					if(strcmp(mo->getCharacter()->getCString(),"HiraishinMark")==0){
						isMark=true;
					}
				}
			};

			if(_isCanSkill1 && !isMark){
				this->changeSide(sp);
				this->attack(SKILL1);
			}else if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000){
					if(abs(sp.x)> 64  || abs(sp.y)> 16){
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;

					}
					this->changeSide(sp);
					
					this->attack(OUGIS2);

					return;

			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){
				if(abs(sp.x)> 64  || abs(sp.y)> 16){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;

				}
				this->changeSide(sp);		
				this->attack(OUGIS1);
				return;
			}else if(_isCanSkill2 && _mainTarget->getGP()<5000){
				//先手无视战斗力
				if(abs(sp.y)> 16){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				this->changeSide(sp);
				this->attack(SKILL2);
				return;
			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled && !_skillChangeBuffValue){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(_isCanSkill3){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL3);
				return;
			}else{ 

				//交战策略
				if(abs(sp.x)> 352  || abs(sp.y)> 128){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;

				}else if((abs(sp.x)> 32 || abs(sp.y)>32 ) && atoi(this->getnAttackValue()->getCString())<260){

					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill3 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 ){
				this->changeSide(sp);
				this->attack(SKILL3);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanSkill1){

			CCObject* pObject;
			bool isMark=false;
			if(this->getMonsterArray() && this->getMonsterArray()->count()>0){
				CCARRAY_FOREACH(this->getMonsterArray(),pObject){
					Monster* mo=(Monster*) pObject;
					if(strcmp(mo->getCharacter()->getCString(),"HiraishinMark")==0){
						
						if(strcmp(this->getGroup()->getCString(),"Konoha")==0 && mo->getPositionX()>this->getPositionX()){
							isMark=true;
						}else if(strcmp(this->getGroup()->getCString(),"Akatsuki")==0 && mo->getPositionX()<this->getPositionX()){
							isMark=true;
						}
						
					};
				};
			};
			if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
				if(isMark){
					this->attack(SKILL1);
					return;
				};
			};

		};

		this->stepOn();
	}

}



void Hero::AI_Hinata(){
	_mainTarget=NULL;
	this->findEnemy2("Hero");

	

	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear02);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			
			if(this->stepBack2()){
				return;
			};
		}else{

			if(_isCanGear00 ){
				this->useGear(gear00);
			};
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(_isCanGear00 ){
				this->useGear(gear00);
			};
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking){

					if(abs(sp.x)> 48 || abs(sp.y)> 32 ){
						if(_isCanGear00 ){
							this->useGear(gear00);
						};
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					this->changeSide(sp);

					this->attack(OUGIS2);
					return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){

				if(abs(sp.x)> 48 || abs(sp.y)> 32 ){
					if(_isCanGear00 ){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				this->changeSide(sp);
				this->attack(OUGIS1);
				return;
			}else if(_isCanSkill1){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if((_isCanSkill2 || _isCanSkill3 ) && _mainTarget->getGP()<5000  && _skillUPBuffValue){
				if(abs(sp.x)> 48 || abs(sp.y)> 32 ){
					if(_isCanGear00 ){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}
				if(_isCanSkill2){
					this->changeSide(sp);
					this->attack(SKILL2);
					return;
				}
				
				if(_isCanSkill3){
					this->changeSide(sp);
					this->attack(SKILL3);
					return;
				}
	

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(abs(sp.x)<128){

				

				//交战策略
				if(abs(sp.x)> 32 || abs(sp.y)>32 ){
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else if(_isCanSkill3 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL3);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanGear00 ){
			this->useGear(gear00);
		};
		this->stepOn();
	}

}

void Hero::AI_Neji(){
	
	_mainTarget=NULL;
	this->findEnemy2("Hero");


	
	//忍具购买
	if(atoi(this->getCoin()->getCString())>=500 && !_isControled && _delegate->_isHardCoreGame){
		if(this->getGearArray()->count()==0){
			this->setGear(gear00);
		}else if(this->getGearArray()->count()==1){
			this->setGear(gear01);
		}else if(this->getGearArray()->count()==2){
			this->setGear(gear07);
		}
	}

	if(this->checkRetri()){
		if(_mainTarget!=NULL){
			
			if(this->stepBack2()){
				return;
			};
		}else{
			if(_isCanGear00 ){
				this->useGear(gear00);
			};
			if(this->stepBack()){
				return;
			};
		}
	};


	// 检测基地
	if(isBaseDanger && this->checkBase() && !_isControled){
		bool needBack=false;
		if(strcmp("Akatsuki",this->getGroup()->getCString())==0){
			if(this->getPositionX()<85*32){
				needBack=true;
			}
		}else{
			if(this->getPositionX()>11*32){
				needBack=true;
			}
		} 

		if(needBack){
			if(this->stepBack2()){
				return;
			};
		}

	}

	if(_mainTarget && strcmp(_mainTarget->getRole()->getCString(),"Flog")!=0 ){
		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}
		if((_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK ) && ( abs(sp.x)<128  || _isCanGear00) ){

			if(_isCanOugis2 && !_isControled && _delegate->_isOugis2Game 
				&& _mainTarget->getGP()<5000 && !_mainTarget->_isBati 
				&& _mainTarget->getActionState()!=ACTION_STATE_KOCKDOWN
				&& !_mainTarget->_isSticking){

					if(abs(sp.x)> 48|| abs(sp.y)> 32 ){
						if(_isCanGear00 ){
							this->useGear(gear00);
						};
						moveDirection =ccpNormalize(sp);
						this->walk(moveDirection);
						return;
					}

					this->changeSide(sp);

					this->attack(OUGIS2);
					return;
			}else if(_isCanOugis1  && !_isControled  && _mainTarget->getGP()<5000){
				
				if(abs(sp.x)> 48 || abs(sp.y)> 32 ){
					if(_isCanGear00 ){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				this->changeSide(sp);
				this->attack(OUGIS1);
				return;

			}else if(enemyCombatPoint>friendCombatPoint && abs(enemyCombatPoint-friendCombatPoint)>3000 && !_isHealling && !_isControled){
				//保持距离
				if(abs(sp.x)<160){
					this->stepBack2();
					return;
				}else {

					this->idle();
					return;

				}

			}else if(_isCanSkill1){
				//先手无视战斗力
				this->changeSide(sp);
				this->attack(SKILL1);
				return;
			}else if(_isCanSkill3 && _mainTarget->getGP()<5000 && _isBati){

				if(abs(sp.x)> 48 || abs(sp.y)> 32 ){
					if(_isCanGear00 ){
						this->useGear(gear00);
					};
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				this->changeSide(sp);
				this->attack(SKILL3);
				return;

			}else if(abs(sp.x)<128){

				
				//交战策略
				if(abs(sp.x)> 32 || abs(sp.y)>32 ){
					
					moveDirection =ccpNormalize(sp);
					this->walk(moveDirection);
					return;
				}

				if(_isCanSkill2 && _mainTarget->getGP()<5000){
					this->changeSide(sp);
					this->attack(SKILL2);
				}else{
					this->changeSide(sp);
					this->attack(NAttack);
				}

				return;
			}
		}

	}
	//无玩家情况
	_mainTarget=NULL;
		if(!this->findEnemy2("Flog")){
			this->findEnemy2("Tower");
		}
	

	if(_mainTarget){

		CCPoint moveDirection;
		CCPoint sp;

		if(_mainTarget->_originY){
			sp=ccpSub(ccp(_mainTarget->getPositionX(),_mainTarget->_originY),this->getPosition());
		}else{
			sp=ccpSub(_mainTarget->getPosition(),this->getPosition());
		}

		if(abs(sp.x)> 32 || abs(sp.y)>32){
			moveDirection =ccpNormalize(sp);
			this->walk(moveDirection);
			return;
		}

		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			//技能清兵
			if(_isCanSkill2 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL2);

			}else if(_isCanSkill3 && strcmp(_mainTarget->getRole()->getCString(),"Flog")==0 && isBaseDanger){
				this->changeSide(sp);
				this->attack(SKILL3);

			}else{
				this->changeSide(sp);
				this->attack(NAttack);

			}	
		}
		return;
	}

	if(_isHealling &&this->getHpPercent()<1){
		if(_actionState==ACTION_STATE_IDLE || _actionState==ACTION_STATE_WALK || _actionState==ACTION_STATE_ATTACK){
			this->idle();
		}
	}else{
		if(_isCanGear00 ){
			this->useGear(gear00);
		};
		this->stepOn();
	}
}

void Hero::AI_Pain(){
}



