#include "GameOver.h"
#include "GameLayer.h"
#include "Characters.h"

USING_NS_CC_EXT;
using namespace CocosDenshion;
#include <fstream>

GameOver::GameOver(void)
{
	exitLayer=NULL;
	cheatLayer=NULL;
	isPosting=false;
	refreshBtn=NULL;
}


GameOver::~GameOver(void)
{
	CCAnimationCache::purgeSharedAnimationCache();
	CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
	CCTextureCache::sharedTextureCache()->removeUnusedTextures();

}

bool GameOver::init(CCRenderTexture* snapshoot){

	bool bRet=false;
	do{
		CC_BREAK_IF(!CCLayer::init());

		SimpleAudioEngine::sharedEngine()->stopAllEffects();
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();

	
		

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

		CCSprite* result_title=CCSprite::createWithSpriteFrameName("result_title.png");
		result_title->setAnchorPoint(ccp(0,0));
		result_title->setPosition(ccp(2,winSize.height-result_title->getContentSize().height-2));
		this->addChild(result_title,3);

		result_bg=CCSprite::createWithSpriteFrameName("gameover_bg.png");
		result_bg->setAnchorPoint(ccp(0.5f,0.5f));
		result_bg->setScale(0.5f);
		result_bg->setPosition(ccp(winSize.width/2,winSize.height/2-6));
		this->addChild(result_bg,4);

		CCScaleTo* su=CCScaleTo::create(0.2f,1.0);
		CCAction* seq=CCSequence::create(su,CCCallFunc::create(this,callfunc_selector(GameOver::listResult)),NULL);
		result_bg->runAction(seq);

		

		bRet=true;
	}while(0);

	return bRet;

}

void GameOver::listResult(){
	
	isPlayed=true;
	if(_delegate->_isHardCoreGame){
		SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/battle_over1.ogg");

	}else{
		SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/battle_over.ogg");
	}
	
	CCString* path=CCString::createWithFormat("%s_half.png",_delegate->currentPlayer->getCharacter()->getCString());
	CCSprite* half=CCSprite::createWithSpriteFrameName(path->getCString());

	if(strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Konan")==0||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Karin")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Suigetsu")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Hidan")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Tobirama")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Tsunade")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Kankuro")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"SageJiraiya")==0||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Minato")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Tobi")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Lee")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"RockLee")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Hinata")==0||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Asuma")==0 ||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Chiyo")==0||
	strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"Kisame")==0
		){
		half->setFlipX(true);
	}

	half->setAnchorPoint(ccp(0,0));
	half->setPosition(ccp(winSize.width/2+result_bg->getContentSize().width/2-half->getContentSize().width,result_bg->getPositionY()-result_bg->getContentSize().height/2+9));
	this->addChild(half,5);


	CCSprite* list_bg=CCSprite::createWithSpriteFrameName("list_bg.png");
	list_bg->setAnchorPoint(ccp(0,0));
	list_bg->setPosition(ccp(winSize.width/2-result_bg->getContentSize().width/2+2,result_bg->getPositionY()-result_bg->getContentSize().height/2+26));
	this->addChild(list_bg,5);

	
	

	int _hour=_delegate->_minute/60;
	int _minute=_delegate->_minute%60;


	CCSprite* timeBG=CCSprite::createWithSpriteFrameName("time_bg.png");
	timeBG->setAnchorPoint(ccp(0,0));
	timeBG->setPosition(ccp(winSize.width/2+result_bg->getContentSize().width/2-11-timeBG->getContentSize().width,result_bg->getPositionY()-result_bg->getContentSize().height/2+46));
	this->addChild(timeBG,6);


	CCString* tempTime=CCString::createWithFormat("%02d:%02d:%02d",_hour,_minute,_delegate->_second);
	

	CCLabelBMFont* gameClock=CCLabelBMFont::create(tempTime->getCString(),"Fonts/1.fnt");
	gameClock->setAnchorPoint(ccp(0.5f,0));
    gameClock->setPosition(ccp(timeBG->getPositionX()+timeBG->getContentSize().width/2,timeBG->getPositionY()+3));
	gameClock->setScale(0.48f);
	this->addChild(gameClock,7);

	

	float _totalSecond=_delegate->_minute*60+_delegate->_second;
	float resultScore=0;
	int killDead=atoi(_delegate->currentPlayer->getKillNum()->getCString())-_delegate->currentPlayer->_deadNum;
	
	
	if(_totalSecond != atoi(_delegate->getTotalTM()->getCString())){
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		CCDirector::sharedDirector()->end();
		return;

	}
	
	if(_delegate->_isHardCoreGame){
		if(_totalSecond>900.0){
			resultScore=float((killDead/float(_totalSecond/60))/3)*100;
		}else{
			resultScore=float((killDead-((_totalSecond/60-15)*3))/45)*100;
		}
		
	}else{
		if(_totalSecond>600.0){
			resultScore=float((killDead/float(_totalSecond/60))/4)*100;
		}else{
			resultScore=float((killDead-((_totalSecond/60-10)*4))/40) *100;
		}
	}

	KTools* tool= KTools::create();
	
	if(_totalSecond <2*30+5 && _isWin ){
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		CCDirector::sharedDirector()->end();
		return;
	}




	CCObject* pObject;
	int i=0;
	int konohaKill=0;
	int akatsukiKill=0;

	

	CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){

		
		Hero* hero=(Hero*)pObject;
		if(strcmp(hero->getRole()->getCString(),"Clone")==0 || 
			strcmp(hero->getRole()->getCString(),"Summon")==0|| 
			strcmp(hero->getRole()->getCString(),"Kuilei")==0 || 
			strcmp(hero->getCharacter()->getCString(),"Han")==0 ||
			strcmp(hero->getCharacter()->getCString(),"Roshi")==0 
			){
				continue;
		}

		//4v4
		if(Cheats>10){
			if(strcmp(hero->getRole()->getCString(),"Player")!=0){
				continue;
			}
		}

		if(hero->_isControled){
			hero->_isControled=false;
			hero->changeGroup();
		}

		CCString* path=CCString::createWithFormat(("%s_small.png"),hero->getCharacter()->getCString());
		CCSprite* avator_small=CCSprite::createWithSpriteFrameName(path->getCString());
		avator_small->setAnchorPoint(ccp(0,0));



		int realKillNum=atoi(hero->getKillNum()->getCString());

		if(strcmp(hero->getGroup()->getCString(),"Konoha")==0){
			konohaKill+=realKillNum;
		}else{
			akatsukiKill+=realKillNum;
		}

		CCString* knum=CCString::createWithFormat("%d",realKillNum);
		CCLabelBMFont* killNum=CCLabelBMFont::create(knum->getCString(),"Fonts/1.fnt");
		killNum->setScale(0.3f);

		CCString* dnum=CCString::createWithFormat("%d",hero->_deadNum);
		CCLabelBMFont* deadNum=CCLabelBMFont::create(dnum->getCString(),"Fonts/1.fnt");
		deadNum->setScale(0.3f);

		CCString* fnum=CCString::createWithFormat("%d",hero->_flogNum);
		CCLabelBMFont* flogNum=CCLabelBMFont::create(fnum->getCString(),"Fonts/1.fnt");
		flogNum->setScale(0.3f);



		float posX=winSize.width/2-result_bg->getContentSize().width/2+2;

		if(strcmp(hero->getGroup()->getCString(),"Konoha")==0){
			avator_small->setPosition(ccp(posX,result_bg->getPositionY()-result_bg->getContentSize().height/2+152-(i*25)));
			killNum->setPosition(ccp(posX+44,avator_small->getPositionY()+avator_small->getContentSize().height/2));
			deadNum->setPosition(ccp(posX+68,avator_small->getPositionY()+avator_small->getContentSize().height/2));
			flogNum->setPosition(ccp(posX+94,avator_small->getPositionY()+avator_small->getContentSize().height/2));



		}else{
			avator_small->setPosition(ccp(posX,result_bg->getPositionY()-result_bg->getContentSize().height/2+76-((i-3)*25)));
			killNum->setPosition(ccp(posX+44,avator_small->getPositionY()+avator_small->getContentSize().height/2));
			deadNum->setPosition(ccp(posX+68,avator_small->getPositionY()+avator_small->getContentSize().height/2));
			flogNum->setPosition(ccp(posX+94,avator_small->getPositionY()+avator_small->getContentSize().height/2));

		}

		if(hero->getGearArray() && hero->getGearArray()->count()>0){

			CCObject* pObject;
			int i=0;
			CCARRAY_FOREACH(hero->getGearArray(),pObject){
				CCString* tmpGear=(CCString*) pObject;
				CCSprite* gearIcon=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("gear_%02d.png",atoi(tmpGear->getCString()))->getCString());
				gearIcon->setPosition(ccp(flogNum->getPositionX()+22+i*19,flogNum->getPositionY()-1));
				gearIcon->setScale(0.5f);
				this->addChild(gearIcon,7);
				i++;
			}
		}

		this->addChild(avator_small,7);
		this->addChild(killNum,7);
		this->addChild(deadNum,7);
		this->addChild(flogNum,7);

		i++;

	}

	bool isTKO=false;
	if(_totalSecond>900 && _delegate->_isSurrender){
		if(strcmp(_delegate->currentPlayer->getGroup()->getCString(),"Konoha")==0){
			if(konohaKill>akatsukiKill){
			 _isWin=true;
			  isTKO=true;
			}
		}else{
			if(akatsukiKill>konohaKill){
				_isWin=true;
				 isTKO=true;
			}
		}
	}
	
	if(Cheats<=10){

		if(akatsukiKill+konohaKill !=atoi(_delegate->getTotalKills()->getCString())){
			SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
			CCDirector::sharedDirector()->end();
			return;
		}

	int realKillNum=atoi(_delegate->currentPlayer->getKillNum()->getCString());
	
	std::string tempReward="";
	if(_delegate->_isHardCoreGame){
		tempReward="FDDD";
	}else{
		tempReward="ONNN";
	}

	tool->decode(tempReward);

	CCString* cl=tool->readFromSQLite();
	int rewardNum;
	if(_isWin){
		rewardNum=realKillNum*75+atoi(tempReward.c_str());
	}else{
		rewardNum=realKillNum*50;
	}

	

	CCSprite* coinBG=CCSprite::createWithSpriteFrameName("coin_bg.png");
	coinBG->setAnchorPoint(ccp(0,0));
	coinBG->setPosition(ccp(winSize.width/2+result_bg->getContentSize().width/2-coinBG->getContentSize().width -11,result_bg->getPositionY()-result_bg->getContentSize().height/2+12));
	this->addChild(coinBG,6);

	CCSprite* adExtra=CCSprite::createWithSpriteFrameName("adExtra.png");
	adExtra->setAnchorPoint(ccp(0.5f,0));
	adExtra->setPosition(ccp(coinBG->getPositionX()+70,coinBG->getPositionY()+22));
	this->addChild(adExtra,7);

	CCString* extraCoin;
	int tempCoin;
	if(adResult==1 && _isWin ){
		std::string tempEtra="idd4";
		tool->decode(tempEtra);
		tempCoin=rewardNum+atoi(cl->getCString())+atoi(tempEtra.c_str());
		extraCoin=CCString::createWithFormat("+%d",500);
	}else{	
		tempCoin=rewardNum+atoi(cl->getCString());
		extraCoin=CCString::createWithFormat("+%d",0);	
	}

	CCString* realCoin=CCString::createWithFormat("%d",tempCoin);
	tool->saveToSQLite("GameRecord","coin",realCoin->getCString(),false);


	CCLabelBMFont* extraLabel=CCLabelBMFont::create(extraCoin->getCString(),"Fonts/yellow.fnt");
	extraLabel->setScale(0.5f);
	extraLabel->setAnchorPoint(ccp(0.5f,0));
	extraLabel->setPosition(ccp(coinBG->getPositionX()+68,coinBG->getPositionY()+3));
	this->addChild(extraLabel,7);	


	CCString* rewardCoin=CCString::createWithFormat("%d",rewardNum);
	CCLabelBMFont* rewardLabel=CCLabelBMFont::create(rewardCoin->getCString(),"Fonts/yellow.fnt");	
	rewardLabel->setAnchorPoint(ccp(0.5f,0));
	rewardLabel->setPosition(ccp(coinBG->getPositionX()+28,coinBG->getPositionY()+3));
	rewardLabel->setScale(0.55f);
	this->addChild(rewardLabel,7);

	}
	
	char* imgSrc="";

	
	if(_isWin && adResult==1){
		if(resultScore>=140 && _delegate->_isHardCoreGame && _delegate->_isRandomChar){
			imgSrc="result_SSSR.png";
		}else if(resultScore>=120 && _delegate->_isHardCoreGame && _delegate->_isRandomChar){
			imgSrc="result_SSR.png";
		}else if(resultScore>=100 && _delegate->_isHardCoreGame && _delegate->_isRandomChar){
			imgSrc="result_SR.png";
		}else if(resultScore>=140){
			imgSrc="result_SSS.png";
		}else if(resultScore>=120){
			imgSrc="result_SS.png";
		}else if(resultScore>=100){
			imgSrc="result_S.png";
		}else if(resultScore>=80){
			imgSrc="result_A.png";
		}else if(resultScore>=60){
			imgSrc="result_B.png";
		}else{
			imgSrc="result_C.png";
		}
	}else if(!_isWin){
		imgSrc="result_Defeat.png";
	}

	if(strcmp(imgSrc,"")!=0){
		CCSprite* recordSprite=CCSprite::createWithSpriteFrameName(imgSrc);
		recordSprite->setAnchorPoint(ccp(0,0));
		recordSprite->setPosition(ccp(winSize.width/2+result_bg->getContentSize().width/2-recordSprite->getContentSize().width-12,result_bg->getPositionY()-result_bg->getContentSize().height/2+88));
		this->addChild(recordSprite,7);
		/*CCSprite* koSprite=NULL;
		if(isTKO && resultScore<120){
			koSprite=CCSprite::createWithSpriteFrameName("twin.png");
		}else if(_isWin && resultScore<120){
			koSprite=CCSprite::createWithSpriteFrameName("dwin.png");
		}
		if(koSprite){
			koSprite->setAnchorPoint(ccp(0.5f,0.5f));
			koSprite->setPosition(ccp(recordSprite->getPositionX()+recordSprite->getContentSize().width/2,recordSprite->getPositionY()+8));
			this->addChild(koSprite,8);
		}*/

		if(_isWin && adResult==1 &&_delegate->_isHardCoreGame){

			finnalScore=resultScore+float(_delegate->currentPlayer->_flogNum)/100;
			CCString* recordString=CCString::createWithFormat("%0.2fPts",finnalScore);

			CCLabelBMFont* recordScore=CCLabelBMFont::create(recordString->getCString(),"Fonts/1.fnt");
			recordScore->setAnchorPoint(ccp(1,0.5f));
			recordScore->setPosition(ccp(recordSprite->getPositionX()+recordSprite->getContentSize().width,recordSprite->getPositionY()-7));
			recordScore->setScale(0.35f);
			this->addChild(recordScore,10);

			upload_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("upload_btn.png"),CCSprite::createWithSpriteFrameName("upload_btn.png"),NULL,this,menu_selector(GameOver::onUPloadBtn));
			CCMenu* upMenu=CCMenu::create(upload_btn,NULL);
			upload_btn->setAnchorPoint(ccp(1.0,0));
			upMenu->setPosition(ccp(winSize.width/2+result_bg->getContentSize().width/2-14,winSize.height/2+result_bg->getContentSize().height/2-62));
			this->addChild(upMenu,7);


			detailRecord=CCString::createWithFormat("%02d:%02d,%s,%d,%d",_minute,_delegate->_second,_delegate->currentPlayer->getKillNum()->getCString(),_delegate->currentPlayer->_deadNum,_delegate->currentPlayer->_flogNum)->getCString();

		}

		//记录 最速获胜时间
		if(Cheats<=10){

			resultChar=_delegate->currentPlayer->getCharacter();

			//觉醒必备
			if(strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"SageNaruto")==0){
				resultChar=CCString::create("Naruto");
			}else if(strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"RikudoNaruto")==0){
				resultChar=CCString::create("Naruto");
			}else if(strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"SageJiraiya")==0){
				resultChar=CCString::create("Jiraiya");
			}else if(strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"ImmortalSasuke")==0){
				resultChar=CCString::create("Sasuke");
			}else if(strcmp(_delegate->currentPlayer->getCharacter()->getCString(),"RockLee")==0){
				resultChar=CCString::create("Lee");
			}


			if(_isWin ){
				CCString* winNum=tool->readSQLite("CharRecord","name",resultChar->getCString(),"column1");
				int tempWin=0;
				
				if(resultScore>=140){
					tempWin=atoi(winNum->getCString())+3;
				}else if(resultScore>=120){
					tempWin=atoi(winNum->getCString())+2;
				}else{
					tempWin=atoi(winNum->getCString())+1;
				}
				
				CCString* realWin=CCString::createWithFormat("%d",tempWin);
				if(CError!=1){
					tool->saveSQLite("CharRecord","name",resultChar->getCString(),"column1",(char*) realWin->getCString(),false);
				}
				//
				if(_delegate->_isRandomChar && resultScore>=120 ){
					CCObject* pObject;

					if(_delegate->currentPlayer->_isControled){
						_delegate->currentPlayer->_isControled=false;
						_delegate->currentPlayer->changeGroup();
					}


					CCARRAY_FOREACH(_delegate->_CharacterArray,pObject){

						Hero* hero=(Hero*)pObject;
						if(strcmp(hero->getRole()->getCString(),"Clone")==0 || 
							strcmp(hero->getRole()->getCString(),"Player")==0 ||
							strcmp(hero->getRole()->getCString(),"Summon")==0|| 
							strcmp(hero->getRole()->getCString(),"Kuilei")==0 || 
							strcmp(hero->getCharacter()->getCString(),"Han")==0 ||
							strcmp(hero->getCharacter()->getCString(),"Roshi")==0 
							){
								continue;
						}

						if(hero->_isControled){
							hero->_isControled=false;
							hero->changeGroup();
						}

						
						if(strcmp(hero->getGroup()->getCString(),_delegate->currentPlayer->getGroup()->getCString())==0){

							CCString* winNum=tool->readSQLite("CharRecord","name",hero->getCharacter()->getCString(),"column1");
							int tempWin=0;
							if(resultScore>=140){
								tempWin=atoi(winNum->getCString())+2;
							}else{
								tempWin=atoi(winNum->getCString())+1;
							}

							CCString* realWin=CCString::createWithFormat("%d",tempWin);
							if(CError!=1){
								tool->saveSQLite("CharRecord","name",hero->getCharacter()->getCString(),"column1",(char*) realWin->getCString(),false);
							}

						}

					}


				}

				//最速记录
				CCString* recordTime=tool->readSQLite("CharRecord","name",resultChar->getCString(),"column3");
				if(recordTime->length()==0){
					if(CError!=1){
						tool->saveSQLite("CharRecord","name",resultChar->getCString(),"column3",(char*) tempTime->getCString(),false);
					}
				}else{
					std::string bestTime=(std::string) recordTime->getCString();
					std::string recordHour=bestTime.substr(0,2);
					std::string recordMinute=bestTime.substr(3,2);
					std::string recordSecond=bestTime.substr(6,2);
					bool isNewRecord=false;
					if(atoi(recordHour.c_str())>_hour){
						isNewRecord=true;
					}else if(atoi(recordHour.c_str())==_hour){

						if(atoi(recordMinute.c_str())>_minute){
							isNewRecord=true;
						}else if(atoi(recordMinute.c_str())==_minute){
							if(atoi(recordSecond.c_str())>_delegate->_second){
								isNewRecord=true;
							}else{
								isNewRecord=false;
							}
						}else {

							isNewRecord=false;	
						}

					}else{
						isNewRecord=false;
					}

					if(isNewRecord){
						if(CError!=1){
							tool->saveSQLite("CharRecord","name",resultChar->getCString(),"column3",(char*) tempTime->getCString(),false);
						}
					}



				}
				}

			}/*else{

			 CCString* loseNum=tool->readSQLite("Achievement","name",resultChar->getCString(),"column2"); 
			 int tempLose=atoi(loseNum->getCString())+1;
			 CCString* realLose=CCString::createWithFormat("%d",tempLose);
			 if(CError!=1){
			 tool->saveSQLite("Achievement","name",resultChar->getCString(),"column2",(char*) realLose->getCString(),false);
			 }
			 }	*/



			
		
	}
	

	

	if(Cheats<=10){
		CCLabelBMFont* version=CCLabelBMFont::create("The Last Fixed","Fonts/1.fnt");
		version->setPosition(ccp(winSize.width/2+94,result_bg->getPositionY()-result_bg->getContentSize().height/2+6));
		version->setScale(0.3f);
		this->addChild(version,5);

	}else{

		CCLabelBMFont* version=CCLabelBMFont::create("The Carnival","Fonts/1.fnt");
		version->setPosition(ccp(winSize.width/2+94,result_bg->getPositionY()-result_bg->getContentSize().height/2+6));
		version->setScale(0.3f);
		this->addChild(version,5);
	}

	
	CCMenuItem* btm_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("close_btn1.png"),CCSprite::createWithSpriteFrameName("close_btn2.png"),NULL,this,menu_selector(GameOver::onBackToMenu));
	CCMenu* overMenu=CCMenu::create(btm_btn,NULL);
	overMenu->setPosition(ccp(winSize.width/2+result_bg->getContentSize().width/2-12,winSize.height/2+result_bg->getContentSize().height/2-18));
	this->addChild(overMenu,7);
	
	_delegate->_isSurrender=false;

}
void GameOver::onUPloadBtn(CCObject* sender){

	CCTips *tip=CCTips::create("ServerMainten");
	this->addChild(tip,5000);

	return;
	if(!isPosting && strcmp(PWord.c_str(),"")!=0){
		isPosting=true;
		//刷新按钮
		if(!refreshBtn){
			refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
			refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
			CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
			refreshBtn->runAction(CCRepeatForever::create(rt));
			this->addChild(refreshBtn,1000);

		}
		KTools* tool=KTools::create();

		tool->prepareFileSHA();
		std::string filePath=CCFileUtils::sharedFileUtils()->getWritablePath()+"SHA.xml";
		std::string strFileMD5 =CMD5Checksum::GetMD5(filePath);
		remove(filePath.c_str());
		

		cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
		
		std::string code="code=1000";
		std::string mem=tool->encodeData(CCString::createWithFormat("%d",MemberID)->getCString());
		std::string code2=CCString::createWithFormat("&version=%d",CURRENT_VERSION)->getCString();
		std::string code3=CCString::createWithFormat("&score=%0.2f",finnalScore)->getCString();
		std::string code4=CCString::createWithFormat("&use_char=%s",this->_delegate->currentPlayer->getCharacter()->getCString())->getCString();
		std::string code5=CCString::createWithFormat("%s%s",strFileMD5.substr(16,5).c_str(),strFileMD5.substr(6,5).c_str())->getCString();

		
		std::string codeFinal=code+"&member_id="+mem+"&pw="+PWord+code2+code3+code4+"&detail="+detailRecord+"&path="+code5;
		std::string url=SERVER"nsk/record.php?"+codeFinal;
		request->setUrl(url.c_str());  
		request->setRequestType(CCHttpRequest::kHttpGet);  
		request->setResponseCallback(this, callfuncND_selector(GameOver::onHttpRequestCompleted));  
		request->setTag("Post_My_Data");  
		cocos2d::extension::CCHttpClient::getInstance()->send(request);  
		request->release(); 

	}

}

void GameOver::onHttpRequestCompleted(CCNode *sender ,void *data) {  

	isPosting=false;
	//刷新按钮
	if(refreshBtn){
		refreshBtn->stopAllActions();
		refreshBtn->removeFromParent();
		refreshBtn=NULL;
	}
	cocos2d::extension::CCHttpResponse *response = (cocos2d::extension::CCHttpResponse*)data;    
	if (!response)    
	{  
		return;    
	}   
	if (0 != strlen(response->getHttpRequest()->getTag()))   
	{  
	CCLog("%s completed", response->getHttpRequest()->getTag());  
	}  
	int statusCode = response->getResponseCode();  
	char statusString[64] = {};  
	sprintf(statusString ,"Http status code:%d ,tag = %s" ,statusCode ,response->getHttpRequest()->getTag());  
	CCLog("response code:%d" ,statusCode);  
	if (!response->isSucceed())  
	{  
	CCLog("response failed");  
	CCLog("error buffer:%s" ,response->getErrorBuffer()); 
	CCTips *tip=CCTips::create("ServerError");
	this->addChild(tip,5000);
	return;
	}  
	std::vector<char> *buffer = response->getResponseData();  
	printf("Http response,dump data:");  
	
	std::string buf(buffer->begin(),buffer->end()); 
	
	if(strcmp(buf.c_str(),"true")==0){
		if(upload_btn){
			upload_btn->removeFromParent();
			upload_btn=NULL;
		}

		CCTips *tip=CCTips::create("UploadSuccess");
		this->addChild(tip,5000);
		
	}else{
		CCTips *tip=CCTips::create(buf.c_str());
		this->addChild(tip,5000);
			
	}

		
	
}  


void GameOver::onBackToMenu(CCObject* sender){

	if(!exitLayer){
		SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/select.mp3");
		exitLayer=CCLayer::create();

		CCSprite* exit_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
		exit_bg->setPosition(ccp(winSize.width/2,winSize.height/2));

		CCSprite* comfirm_title=CCSprite::createWithSpriteFrameName("confirm_title.png");
		comfirm_title->setPosition(ccp(winSize.width/2,winSize.height/2+38));

		CCSprite* btm_text=CCSprite::createWithSpriteFrameName("btm_text.png");
		btm_text->setPosition(ccp(winSize.width/2,winSize.height/2+8));

		CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("yes_btn1.png"),CCSprite::createWithSpriteFrameName("yes_btn2.png"),this,menu_selector(GameOver::onLeft));
		CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(GameOver::onCancel));

		CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
		confirm_menu->alignItemsHorizontallyWithPadding(24);
		confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-30));

		exitLayer->addChild(exit_bg,1);
		exitLayer->addChild(confirm_menu,2);
		exitLayer->addChild(comfirm_title,2);
		exitLayer->addChild(btm_text,2);
		this->addChild(exitLayer,500);
	}
	

};

void GameOver::onLeft(CCObject* sender){

	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/confirm.ogg");



	_delegate->_isExiting=true;
	CCDirector::sharedDirector()->popScene();

}

void GameOver::onCancel(CCObject* sender){

	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/cancel.ogg");
	exitLayer->removeFromParent();
	exitLayer=NULL;
}



GameOver*  GameOver::create(CCRenderTexture* snapshoot){
	GameOver* pl=new  GameOver();
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