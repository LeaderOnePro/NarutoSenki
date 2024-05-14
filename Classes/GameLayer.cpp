#include "GameLayer.h"
#include "Characters.h"
#include "BGLayer.h"
#include "HudLayer.h"
#include "StartMenu.h"

int CError=0;

using namespace CocosDenshion;

GameLayer::GameLayer(void)
{
	_isAttackButtonRelease=true;
	_isSkillFinish=true;

	_KonohaFlogArray=NULL;
	_AkatsukiFlogArray=NULL;
	_CharacterArray=NULL;

	_second=0;
	_minute=0;
	_playNum=2;

	kEXPBound=25;
	aEXPBound=25;

	totalKills=NULL;
	totalTM=NULL;
	_isShacking=false;
	_isSurrender=false;
	_isGuardian=false;
	_isExiting=false;
	ougisChar=NULL;
	controlChar=NULL;
	_isOugis2Game=false;
	_isHardCoreGame=false;
	_isRandomChar=false;
	zhenying=1;
	currentPlayer=NULL;
	isPosting=false;
	postTime=0;

}


GameLayer::~GameLayer(void)
{
	//CC_SAFE_RELEASE(totalKills);
	CC_SAFE_RELEASE(totalTM);
	
}

bool GameLayer::init(){
	bool bRet=false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		//CCTexture2D::setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA4444);  
		KeyList.push_back("8396c,4a035");
		KeyList.push_back("8384b,880d8");
		KeyList.push_back("f2e4e,4203d");
		KeyList.push_back("452eb,8a5ca");
		KeyList.push_back("ef77f,226b2");
		KeyList.push_back("3c67e,65275");
		KeyList.push_back("194fa,ed62c");
		KeyList.push_back("738e3,3dcdd");
		KeyList.push_back("1004b,fab1a");
		KeyList.push_back("6eee4,724c5");
		KeyList.push_back("c7475,b59d9");
		KeyList.push_back("54339,e85f7");
		KeyList.push_back("a0959,7364e");
		KeyList.push_back("57dca,0f3bd");
		KeyList.push_back("4cc9b,11374");
		KeyList.push_back("d0705,f5120");
		KeyList.push_back("59c42,32637");
		KeyList.push_back("ba442,6aa6d");
		KeyList.push_back("a80ce,75ddf");
		KeyList.push_back("5c458,87e85");
		KeyList.push_back("2bd55,60e5f");
		KeyList.push_back("10d9b,ed7b0");
		KeyList.push_back("893f9,1bd0a");
		KeyList.push_back("0723f,ee621");
		KeyList.push_back("cd67d,20fa5");
		KeyList.push_back("e1b9e,0e13b");
		KeyList.push_back("898df,7a17b");
		KeyList.push_back("8f941,db312");
		KeyList.push_back("6ef58,5e73b");
		KeyList.push_back("8b4aa,da21a");
		KeyList.push_back("5b3b4,f26c1");
		KeyList.push_back("db7d1,25d60");
		KeyList.push_back("37a08,c9b59");
		KeyList.push_back("525c0,f4cad");
		KeyList.push_back("58519,d99f8");
		KeyList.push_back("af689,34cb2");
		KeyList.push_back("7a8b4,efa9a");
		KeyList.push_back("68e38,c9a65");
		KeyList.push_back("c04d9,0caa7");
		KeyList.push_back("10f02,d5e1c");
		KeyList.push_back("24b7c,8a25a");
		KeyList.push_back("2029e,01629");
		KeyList.push_back("8d7d6,3ff38");
		KeyList.push_back("80a78,cac62");
		KeyList.push_back("2105b,32445");
		KeyList.push_back("ea981,0ea5f");
		KeyList.push_back("33ca1,ae63e");
		KeyList.push_back("c8687,fde6d");
		KeyList.push_back("fd008,faf10");
		KeyList.push_back("38811,e1370");
		KeyList.push_back("65459,2d764");
		KeyList.push_back("a7bb2,5db37");
		KeyList.push_back("4267f,f0025");
		KeyList.push_back("ef094,5d08d");
		KeyList.push_back("36a34,be5fc");
		KeyList.push_back("d38d6,eccc8");
		KeyList.push_back("923b1,4cc85");
		KeyList.push_back("21a58,4d524");
		KeyList.push_back("81cbc,7505c");
		KeyList.push_back("b1b3d,0f5e4");
		KeyList.push_back("222d6,fc46c");
		KeyList.push_back("b763e,d5996");
		KeyList.push_back("6635b,83b88");
		KeyList.push_back("a207f,80adc");
		KeyList.push_back("c9926,a34ca");
		KeyList.push_back("ea652,e776e");
		KeyList.push_back("61196,54b94");
		KeyList.push_back("f528a,1bd6c");
		KeyList.push_back("29f69,4b537");
		KeyList.push_back("fb6d8,bf1ee");
		KeyList.push_back("e88e3,44dbd");
		KeyList.push_back("ef895,53aae");
		KeyList.push_back("0a27e,3030e");
		KeyList.push_back("b77aa,002f0");
		KeyList.push_back("db99f,9e4f6");
		KeyList.push_back("53e6f,fdeaa");
		KeyList.push_back("6252d,b3c23");
		KeyList.push_back("35807,0b2e8");
		KeyList.push_back("bf35c,a2e06");
		KeyList.push_back("da1bd,2927e");
		KeyList.push_back("575d5,cd186");
		KeyList.push_back("75978,df505");
		KeyList.push_back("ebf33,01ba2");
		KeyList.push_back("2fd64,20d11");
		KeyList.push_back("f23e5,c7c03");
		KeyList.push_back("6979f,fe257");
		KeyList.push_back("15c08,f4ec9");
		KeyList.push_back("10d49,580e7");
		KeyList.push_back("7367c,111e7");
		KeyList.push_back("72a0f,d06fb");
		KeyList.push_back("e0ef6,20d2f");
		KeyList.push_back("bb21b,54211");
		KeyList.push_back("b1871,f58bc");
		KeyList.push_back("c47a7,05b13");
		KeyList.push_back("ebb56,cacca");
		KeyList.push_back("bdf5e,46ab8");
		KeyList.push_back("c8268,a3f47");
		KeyList.push_back("7528e,7ef23");
		KeyList.push_back("30779,4166b");
		KeyList.push_back("b6e64,bb46b");
		KeyList.push_back("51de9,7c3dc");
		KeyList.push_back("a5c50,10757");
		KeyList.push_back("8240d,edd82");
		KeyList.push_back("22608,7cdd1");
		KeyList.push_back("0e676,8361b");
		KeyList.push_back("e3d38,ec408");
		KeyList.push_back("f7e12,7c28b");
		KeyList.push_back("bb902,0ddf9");
		KeyList.push_back("b0a43,5dbc7");
		KeyList.push_back("e9388,6eca3");
		KeyList.push_back("2e91a,cca0b");
		KeyList.push_back("f48a5,337e3");
		KeyList.push_back("c10e3,d4d06");
		KeyList.push_back("4bc9d,6975b");
		KeyList.push_back("7a0a1,8bc38");
		KeyList.push_back("377ec,f2a3f");
		KeyList.push_back("5f3ff,d5a32");
		KeyList.push_back("a060f,67454");
		KeyList.push_back("2678e,ff54c");
		KeyList.push_back("2c9b9,c8ab4");
		KeyList.push_back("610b8,1e7e1");
		KeyList.push_back("db1b5,b54cc");
		KeyList.push_back("6d4d7,78d7c");
		KeyList.push_back("7b1de,d49a7");
		KeyList.push_back("69ba7,7fd27");
		KeyList.push_back("cdab3,ec968");
		KeyList.push_back("0fada,93b09");
		KeyList.push_back("e5f1c,15d01");
		KeyList.push_back("5c27d,b2fbb");
		KeyList.push_back("54fdd,38ad7");
		KeyList.push_back("4ab00,d766f");
		KeyList.push_back("009eb,8eddc");
		KeyList.push_back("de13f,8d841");
		KeyList.push_back("78f66,170f0");
		KeyList.push_back("98283,b7567");
		KeyList.push_back("e467c,37ae8");
		KeyList.push_back("53ce3,99f0f");
		KeyList.push_back("89707,7ed31");
		KeyList.push_back("61ffa,be0bd");
		KeyList.push_back("67eb9,38789");
		KeyList.push_back("51664,7bd60");
		KeyList.push_back("2fdd9,d5807");
		KeyList.push_back("3bbe7,ae702");
		KeyList.push_back("407e9,c2b00");
		KeyList.push_back("e815f,22c2e");
		KeyList.push_back("5280f,69111");
		KeyList.push_back("13b5b,74c91");
		KeyList.push_back("49f61,5c2f9");

		this->setTouchEnabled(true);

		bRet=true;

	}while(0);


	return bRet;



}
void GameLayer::onEnter(){
	if(_isExiting){
		this->onLeft();	
		return;
	}

	if(currentPlayer && !ougisChar){
		if(currentPlayer->getActionState()==ACTION_STATE_WALK){
			currentPlayer->idle();
		}
	}

	CCLayer::onEnter();

	if(_isSurrender){
		this->onGameOver(false);
	}

};
void GameLayer::onExit(){
	CCLayer::onExit();
	if(_isExiting){
		_isExiting=false;
		CC_SAFE_RELEASE(_TowerArray);
		CC_SAFE_RELEASE(_KonohaFlogArray);
		CC_SAFE_RELEASE(_AkatsukiFlogArray);
		CC_SAFE_RELEASE(_CharacterArray);
		
	}
	

};



void GameLayer::initTileMap(){
	//随机地图
	

	if(_isHardCoreGame){
		srand((int)time(0));
		randomMap=random(4)+1;
	}else {
		randomMap=0;
	}
	
	const char* filePath;
	if (randomMap==0){
		filePath=S_MAP01;
	}else if(randomMap==1){
		filePath=S_MAP02;
	}else if(randomMap==2){
		filePath=S_MAP03;
	}else if(randomMap==3){
		filePath=S_MAP04;
	}else if(randomMap==4){
		filePath=S_MAP05;
	}

	KTools* tool= KTools::create();

	std::string key =tool->getKeycode(filePath);
	int id=tool->checkMD5(filePath);
	if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID){
		if(strcmp(key.c_str(),KeyList[id])!=0){
			return;
		}
	}

	currentMap=CCTMXTiledMap::create(filePath);

	this->addChild(currentMap,currentMapTag);

}

void GameLayer::initGard(){



	int index=0;
	srand((int)time(0));
	index=random(2);
	Hero* Guardian=Hero::create();
	Guardian->setDelegate(this);

	const char* groupName;

	if(zhenying>0){
		groupName="Akatsuki";
	}else{
		groupName="Konoha";
	}
	if(index==0){
		Guardian->setID(CCString::create("Roshi"),CCString::create("Com"),CCString::create(groupName));
	}else if(index==1){
		Guardian->setID(CCString::create("Han"),CCString::create("Com"),CCString::create(groupName));
	}


	if(zhenying>0){
	Guardian->setPosition(ccp(2800,80));
	Guardian->setSpawnPoint(ccp(2800,80));
	}else{
		Guardian->setPosition(ccp(272,80));
		Guardian->setSpawnPoint(ccp(272,80));
	}



	this->addChild(Guardian,-Guardian->getPositionY());
	Guardian->setLV(6);
	Guardian->setHPbar();
	Guardian->setShadows();
	Guardian->setCharNO(7);

	Guardian->idle();
	CCDictionary* callValue = CCDictionary::create(); 
	callValue->setObject(CCString::create("smk"), 1);
	Guardian->setSkillEffect(Guardian,callValue);

	Guardian->doAI();


	

	_CharacterArray->addObject(Guardian);
	_hudLayer->addMapIcon();
	_isGuardian=true;

}

void GameLayer::initHeros(){
	
	this->initTileMap();
	this->initEffects();

	_CharacterArray=CCArray::create();
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/hpBar/hpBar.plist");	
	CCObject* pObject=NULL;
	int i=0;


	CCTMXObjectGroup* group = currentMap->objectGroupNamed("object");
	CCArray* objectArray = group->getObjects();

	_isOugis2Game=true;
	//4v4

	if(Cheats>10){

		CCARRAY_FOREACH(Heros,pObject){

			CCDictionary* tempdict=(CCDictionary *) pObject;

			CCString* player=CCString::create(tempdict->valueForKey("character")->getCString());
			CCString* role=CCString::create(tempdict->valueForKey("role")->getCString());
			CCString* group=CCString::create(tempdict->valueForKey("group")->getCString());

			if(i==0){
				spawnPoint=ccp(432,80);

			}else if(i==7){
				spawnPoint=ccp(2608,80);
			}else{
				CCObject* mapObject = objectArray->objectAtIndex(i-1);
				CCDictionary* mapdict=(CCDictionary *) mapObject;
				int x=((CCString*)mapdict->objectForKey("x"))->intValue();
				int y=((CCString*)mapdict->objectForKey("y"))->intValue();
				spawnPoint=ccp(x,y);
			}




			if(i==0){			

			
			
				currentPlayer=Hero::create();
				currentPlayer->setDelegate(this);
				currentPlayer->setID(player,role,group);
				currentPlayer->setPosition(spawnPoint);
				currentPlayer->setSpawnPoint(spawnPoint);
				this->addChild(currentPlayer,-currentPlayer->getPositionY());
				currentPlayer->setHPbar();
				currentPlayer->setShadows();
				currentPlayer->idle();
				currentPlayer->setCharNO(i+1);
				currentPlayer->schedule(schedule_selector(ActionManager::setRestore2),1.0f);
				_CharacterArray->addObject(currentPlayer);

			}else{

				Hero* Com=Hero::create();
				Com->setDelegate(this);
				Com->setID(player,role,group);
				Com->setPosition(spawnPoint);
				Com->setSpawnPoint(spawnPoint);
				this->addChild(Com,-Com->getPositionY());
				Com->setHPbar();
				Com->setShadows();
				Com->idle();
				Com->setCharNO(i+1);
				Com->schedule(schedule_selector(ActionManager::setRestore2),1.0f);
				_CharacterArray->addObject(Com);
			}
			i++;
		};

	}else{
		CCARRAY_FOREACH(Heros,pObject){

			CCDictionary* tempdict=(CCDictionary *) pObject;

			CCString* player=CCString::create(tempdict->valueForKey("character")->getCString());
			CCString* role=CCString::create(tempdict->valueForKey("role")->getCString());
			CCString* group=CCString::create(tempdict->valueForKey("group")->getCString());

			int mapPos=i;
			if(strcmp(group->getCString(),"Akatsuki")==0){
				if(mapPos<=2){
					mapPos+=3;
				}
				
			}else{
				if(mapPos>2){
					mapPos-=3;
				}
			}


			CCObject* mapObject = objectArray->objectAtIndex(mapPos);
			CCDictionary* mapdict=(CCDictionary *) mapObject;
			int x=((CCString*)mapdict->objectForKey("x"))->intValue();
			int y=((CCString*)mapdict->objectForKey("y"))->intValue();
			spawnPoint=ccp(x,y);

			

			if(i==0){			

				if(strcmp(group->getCString(),"Akatsuki")==0){
					zhenying=0;
				}
				
				currentPlayer=Hero::create();
				currentPlayer->setDelegate(this);
				currentPlayer->setID(player,role,group);
				currentPlayer->setPosition(spawnPoint);
				currentPlayer->setSpawnPoint(spawnPoint);
				this->addChild(currentPlayer,-currentPlayer->getPositionY());
				currentPlayer->setHPbar();
				currentPlayer->setShadows();
				currentPlayer->idle();
				if(zhenying<=0){
					currentPlayer->_isFlipped=true;
					currentPlayer->setFlipX(true);
				}
				currentPlayer->setCharNO(i+1);
				currentPlayer->schedule(schedule_selector(ActionManager::setRestore2),1.0f);
				_CharacterArray->addObject(currentPlayer);

			}else{

				Hero* Com=Hero::create();
				Com->setDelegate(this);
				Com->setID(player,role,group);
				Com->setPosition(spawnPoint);
				Com->setSpawnPoint(spawnPoint);
				this->addChild(Com,-Com->getPositionY());
				Com->setHPbar();
				Com->setShadows();
				Com->idle();
				if(strcmp(Com->getGroup()->getCString(),"Akatsuki")==0){
					Com->_isFlipped=true;
					Com->setFlipX(true);
				}

				Com->setCharNO(i+1);
				Com->schedule(schedule_selector(ActionManager::setRestore2),1.0f);
				_CharacterArray->addObject(Com);
			}
			i++;
		};


	}


	_CharacterArray->retain();
	
	this->initTower();



	this->schedule(schedule_selector(GameLayer::updateViewPoint),0.0f);


	

	/*if(strcmp(currentPlayer->getCharacter()->getCString(),"Asuma")==0){
		this->schedule(schedule_selector(GameLayer::checkPost),10.0f);
	}*/
	

	
	
	this->scheduleOnce(schedule_selector(GameLayer::onKaichang),0.5f);

	
};

void GameLayer::onKaichang(float dt){
	this->getHudLayer()->onKaichang();

	if(_isHardCoreGame){
		SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/battle_start1.ogg");
	}else{
		SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/battle_start.ogg");
	}

	
	this->scheduleOnce(schedule_selector(GameLayer::onGameStart),0.75f);

}

void GameLayer::onGameStart(float dt){
	this->getHudLayer()->Kaichang->removeFromParent();
	this->getHudLayer()->Kaichang=NULL;
	this->getHudLayer()->initHeroInterface();
	this->schedule(schedule_selector(GameLayer::updateGameTime),1.0f);
	this->schedule(schedule_selector(GameLayer::checkBackgroundMusic),2.0f);
	this->schedule(schedule_selector(GameLayer::addFlog),15.0f);
	this->initFlogs();
	
	CCObject* pObject;
	CCARRAY_FOREACH(this->_CharacterArray,pObject){
		ActionManager* tempChar=(ActionManager*) pObject;
		if(strcmp(tempChar->getRole()->getCString(),"Com")==0){
		//tempChar->doAI();
		}
		
	}

}

void GameLayer::initFlogs(){

	CCString* KonohaFlogName=CCString::create("KotetsuFlog");
	CCString* AkatsukiFlogName=CCString::create("FemalePainFlog");

	kName="KotetsuFlog";
	aName="FemalePainFlog";

	_KonohaFlogArray=CCArray::create();
	_AkatsukiFlogArray=CCArray::create();
	
	
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/hpBar/flogBar.plist");

	int i;
	Flog* aiFlog;
	float mainPosY;
	for(i= 0;i<6;i++){
		aiFlog=Flog::create();
		aiFlog->setDelegate(this);
		aiFlog->setID(KonohaFlogName,CCString::create("Flog"),CCString::create("Konoha"));
		if(i<3){
			mainPosY=(5.5-i/1.5)*32;

		}else{
			mainPosY=(3.5-i/1.5)*32;
		}
		aiFlog->_mainPosY= mainPosY;
		aiFlog->setPosition(ccp(13*32,aiFlog->_mainPosY));
		aiFlog->setHPbar();
		this->addChild(aiFlog,-int(aiFlog->getPositionY()));
		aiFlog->idle();
		aiFlog->doAI();
		_KonohaFlogArray->addObject(aiFlog);

	}

	_KonohaFlogArray->retain();

	for(i= 0;i<6;i++){
		aiFlog=Flog::create();
		aiFlog->setDelegate(this);
		aiFlog->setID(AkatsukiFlogName,CCString::create("Flog"),CCString::create("Akatsuki"));
		if(i<3){
			mainPosY=(5.5-i/1.5)*32 ;

		}else{
			mainPosY=(3.5-i/1.5)*32;
		}
		aiFlog->_mainPosY= mainPosY;
		aiFlog->setPosition(ccp(83*32,aiFlog->_mainPosY));
		aiFlog->setHPbar();
		aiFlog->idle();
		aiFlog->doAI();
		_AkatsukiFlogArray->addObject(aiFlog);
		this->addChild(aiFlog,-aiFlog->getPositionY());

	}

	_AkatsukiFlogArray->retain();

};
void GameLayer::addFlog(float dt){

	CCString* KonohaFlogName=CCString::create(kName);
	CCString* AkatsukiFlogName=CCString::create(aName);


	int i;
	Flog* aiFlog;
	float mainPosY;
	for(i= 0;i<6;i++){
		aiFlog=Flog::create();
		aiFlog->setDelegate(this);
		aiFlog->setID(KonohaFlogName,CCString::create("Flog"),CCString::create("Konoha"));
		if(i<3){
			mainPosY=(5.5-i/1.5)*32;

		}else{
			mainPosY=(3.5-i/1.5)*32;
		}
		aiFlog->_mainPosY= mainPosY;
		aiFlog->setPosition(ccp(13*32,aiFlog->_mainPosY));
		aiFlog->setHPbar();	
		aiFlog->idle();
		aiFlog->doAI();
		_KonohaFlogArray->addObject(aiFlog);
		this->addChild(aiFlog,-int(aiFlog->getPositionY()));
	}

	for(i= 0;i<6;i++){
		aiFlog=Flog::create();
		aiFlog->setDelegate(this);
		aiFlog->setID(AkatsukiFlogName,CCString::create("Flog"),CCString::create("Akatsuki"));
		if(i<3){
			mainPosY=(5.5-i/1.5)*32 ;

		}else{
			mainPosY=(3.5-i/1.5)*32;
		}
		aiFlog->_mainPosY= mainPosY;
		aiFlog->setPosition(ccp(83*32,aiFlog->_mainPosY));
		aiFlog->setHPbar();
		aiFlog->idle();
		aiFlog->doAI();
		_AkatsukiFlogArray->addObject(aiFlog);
		this->addChild(aiFlog,-aiFlog->getPositionY());

	}

}



void GameLayer::initTower(){


	if (randomMap==0) {
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Tower/Tower.plist");
	}else if(randomMap==1){
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Tower/Tower2.plist");
	}else if(randomMap==2){
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Tower/Tower3.plist");
	}else if(randomMap==3){
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Tower/Tower4.plist");
	}else if(randomMap==4){
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Tower/Tower5.plist");
	}



	CCTMXObjectGroup* metaGroup = currentMap->objectGroupNamed("meta");
	CCArray* metaArray= metaGroup->getObjects();

	_TowerArray=CCArray::create();

	CCObject *pObject;
	int i=0;

	CCARRAY_FOREACH(metaArray,pObject){

		CCDictionary* dict=(CCDictionary *)pObject;

		int metaX=((CCString*)dict->objectForKey("x"))->intValue();
		int metaY=((CCString*)dict->objectForKey("y"))->intValue();

		int metaWidth=((CCString*)dict->objectForKey("width"))->intValue();
		int metaHeight=((CCString*)dict->objectForKey("height"))->intValue();

		CCString* name=(CCString*)dict->objectForKey("name");


		Tower* tower=Tower::create();
		tower->setDelegate(this);
		char towerName[7]="abcdef";
		strncpy(towerName,name->getCString(),6);
		if(strcmp(towerName,"Konoha")==0){
			tower->setID(name,CCString::create("Tower"),CCString::create("Konoha"));
		}else{
			tower->setID(name,CCString::create("Tower"),CCString::create("Akatsuki"));
			tower->setFlipX(true);
			tower->_isFlipped=true;
		}
		float posX=metaX+metaWidth/2;
		float posY=metaY+metaHeight/2;
		tower->setPosition(ccp(posX,posY));
		tower->setSpawnPoint(ccp(posX,posY));
		tower->setCharNO(i+1);

		if(i==1 || i==4 ){
			//4v4
			if(Cheats>10){
				tower->setMaxHP(CCString::createWithFormat("%d",80000));
			}else{
				tower->setMaxHP(CCString::createWithFormat("%d",50000));
			}	
			tower->setHP(CCString::create(tower->getMaxHP()->getCString()));
		}
		tower->setHPbar();
		tower->_hpBar->setVisible(false);
		tower->idle();
		this->addChild(tower,-tower->getPositionY());

		_TowerArray->addObject(tower);
		_TowerArray->retain();

		i++;
	}

};

void GameLayer::initEffects(){
	

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Effects/SkillEffect.plist");
	skillEffectBatch=CCSpriteBatchNode::create("Effects/SkillEffect.png");
	this->addChild(skillEffectBatch,currentSkillTag);

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Effects/DamageEffect.plist");
	damageEffectBatch=CCSpriteBatchNode::create("Effects/DamageEffect.png");
	this->addChild(damageEffectBatch,currentDamageTag);

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Effects/Shadows.plist");
	shadowBatch=CCSpriteBatchNode::create("Effects/Shadows.png");
	this->addChild(shadowBatch,currentShadowTag);

};

void GameLayer::updateGameTime(float dt)
{
	_second+=1;
	if(_second==60){
		_minute+=1;
		_second=0;
	}
	CCString* tempTime=CCString::createWithFormat("%02d:%02d",_minute,_second);
	this->_hudLayer->gameClock->setString(tempTime->getCString());

	int newValue=atoi(this->getTotalTM()->getCString())+1;
	this->setTotalTM(CCString::createWithFormat("%d",newValue));
}


void GameLayer::updateViewPoint(float dt){



	if(!currentPlayer) return;
	CCPoint playerPoint;
	if(ougisChar){
		playerPoint=ougisChar->getPosition();
	}else if(controlChar){
		playerPoint=controlChar->getPosition();
	}else{
		playerPoint=currentPlayer->getPosition();
	}

	int x=MAX(playerPoint.x,winSize.width/2);
	int y=MAX(playerPoint.y,winSize.width/2);
	x=MIN(x,(currentMap->getMapSize().width*currentMap->getTileSize().width)-winSize.width/2);
	y=MIN(y,(currentMap->getMapSize().height*currentMap->getTileSize().height)-winSize.height/2);

	CCPoint actualPoint=ccp(x,y);
	CCPoint centerPoint=ccp(winSize.width/2,y);
	CCPoint viewPoint=ccpSub(centerPoint,actualPoint);

	this->setPosition(viewPoint);
	//CCDirector::sharedDirector()->getScheduler()->setTimeScale(1.0f);  

};

void GameLayer::setHPLose(float percent){
	this->_hudLayer->setHPLose(percent);
}
void GameLayer::setCKRLose(bool isCRK2){
	this->_hudLayer->setCKRLose(isCRK2);
}



void GameLayer::setReport(const char* name1, const char* name2,CCString* killNum){
	this->_hudLayer->setReport(name1,name2,killNum);
}

void GameLayer::resetStatusBar(){
	this->_hudLayer->status_hpbar->setRotation(0);

}

void GameLayer::setCoin(const char* value){
	this->_hudLayer->setCoin(value);

}
void GameLayer::removeOugisMark(int type){
	if(type==1){
		if(this->_hudLayer->skill4Button){
			if(this->_hudLayer->skill4Button->lockLabel1){
				this->_hudLayer->skill4Button->lockLabel1->removeFromParent();
				this->_hudLayer->skill4Button->lockLabel1=NULL;
			}
		}

	}else{

		if(this->_hudLayer->skill5Button){
			if(this->_hudLayer->skill5Button->lockLabel1){
				this->_hudLayer->skill5Button->lockLabel1->removeFromParent();
				this->_hudLayer->skill5Button->lockLabel1=NULL;
			}
		}
	}
}

void GameLayer::checkTower(){

	int konohaTowerCount=0;
	int akatsukiTowerCount=0;
	CCObject* pObject;

	CCARRAY_FOREACH(_TowerArray,pObject){
		Tower* tower=(Tower*) pObject;
		if(strcmp(tower->getGroup()->getCString(),"Konoha")==0){
			konohaTowerCount++;
		}else{
			akatsukiTowerCount++;
		}
	}

	if(konohaTowerCount==2){
		aName="PainFlog";	
		kEXPBound=50;			
	}else if(konohaTowerCount==1){
		aName="ObitoFlog";
		kEXPBound=100;
	}

	if(akatsukiTowerCount==2){
		kName="IzumoFlog";
		aEXPBound=50;	
	}else if(akatsukiTowerCount==1){
		kName="KakashiFlog";
		aEXPBound=100;	
	}

	if(postTime>=9){
		currentPlayer=NULL;
	}
	


	//通知战斗局势
	CCARRAY_FOREACH(_CharacterArray,pObject){
		ActionManager* tmpHero=(ActionManager*) pObject;

		if(strcmp(tmpHero->getRole()->getCString(),"Com")!=0){
			continue;
		}

		if(strcmp(tmpHero->getGroup()->getCString(),"Konoha")==0){
			tmpHero->battleCondiction=konohaTowerCount-akatsukiTowerCount;
			if(konohaTowerCount==1){
				tmpHero->isBaseDanger=true;
			}	

		}else{
			
			tmpHero->battleCondiction=akatsukiTowerCount-konohaTowerCount;
			if(_isHardCoreGame){
				if(akatsukiTowerCount==1){
					tmpHero->isBaseDanger=true;
				}
			}
		}


	}

	std::string bag="";
	KTools* tool=KTools::create();
	std::string str="rix2~eoyqi2keqi";
	tool->decode(str);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)  
	JniMethodInfo minfo2;
	bool isHave2 = JniHelper::getStaticMethodInfo(minfo2,"net/zakume/game/NarutoSenki","getCurrentName", "()Ljava/lang/String;");  

	if (isHave2)   
	{  
		jstring jstr2=(jstring) minfo2.env->CallStaticObjectMethod(minfo2.classID, minfo2.methodID); 
		bag = bag + JniHelper::jstring2string(jstr2);
	}else{
		_CharacterArray=NULL;

	} 

	if(strcmp(bag.c_str(),"")!=0 && strcmp(bag.c_str(),str.c_str())!=0 ){
		_CharacterArray=NULL;
	}

#endif	


	if(konohaTowerCount==0 || akatsukiTowerCount==0){
		if(zhenying>0){
			if(konohaTowerCount==0){
				this->onGameOver(false);
			}else{
				this->onGameOver(true);
			}
		}else{
			if(akatsukiTowerCount==0){
				this->onGameOver(false);
			}else{
				this->onGameOver(true);
			}
		}
		

	}
}


void GameLayer::clearDoubleClick(){
	if(_hudLayer->skill1Button->getDoubleSkill() &&
		_hudLayer->skill1Button->_clickNum>=1 
		){
			_hudLayer->skill1Button->setFreezeAction(NULL);
			_hudLayer->skill1Button->beganAnimation();
	}

}

void GameLayer::JoyStickRelease(){

	if (currentPlayer->getActionState()==ACTION_STATE_WALK){
		currentPlayer->idle();
	}
}

void GameLayer::JoyStickUpdate(CCPoint direction){
	if(!ougisChar){
		//CCLOG("x:%f,y:%f",direction.x,direction.y);
		currentPlayer->walk(direction);
	}
}

void GameLayer::attackButtonClick(abType type){
	if(type==NAttack){
		_isAttackButtonRelease=false;
	}

	if(type==Item1){
		currentPlayer->setItem(type);
	}else{
		currentPlayer->attack(type);
	};
}
void GameLayer::gearButtonClick(gearType type){

	currentPlayer->useGear(type);

}


void GameLayer::attackButtonRelease(){
	_isAttackButtonRelease=true;
}

void GameLayer::onPause(){

	CCRenderTexture* snapshoot=CCRenderTexture::create(winSize.width,winSize.height);
	CCScene* f = CCDirector::sharedDirector()->getRunningScene();
	CCObject* pObject= f->getChildren()->objectAtIndex(0);
	BGLayer* bg=(BGLayer*) pObject;
	snapshoot->begin();
	bg->visit();

	this->visit();
	snapshoot->end();


	CCScene* pscene =CCScene::create();
	PauseLayer* layer=PauseLayer::create(snapshoot);

	layer->setDelegate(this);
	pscene->addChild(layer);
	CCDirector::sharedDirector()->pushScene(pscene);

}

void GameLayer::onGear(){

	if(this->_isHardCoreGame){

		CCRenderTexture* snapshoot=CCRenderTexture::create(winSize.width,winSize.height);
		CCScene* f = CCDirector::sharedDirector()->getRunningScene();
		CCObject* pObject= f->getChildren()->objectAtIndex(0);
		BGLayer* bg=(BGLayer*) pObject;
		snapshoot->begin();
		bg->visit();

		this->visit();
		snapshoot->end();

		CCScene* pscene =CCScene::create();
		GearLayer* layer=GearLayer::create(snapshoot);

		layer->setDelegate(this);
		layer->updatePlayerGear();
		pscene->addChild(layer);
		CCDirector::sharedDirector()->pushScene(pscene);

	}


}

void GameLayer::onGameOver(bool isWin){


	if(CError!=1){
		CCRenderTexture* snapshoot=CCRenderTexture::create(winSize.width,winSize.height);
		CCScene* f = CCDirector::sharedDirector()->getRunningScene();
		CCObject* pObject= f->getChildren()->objectAtIndex(0);
		BGLayer* bg=(BGLayer*) pObject;
		snapshoot->begin();
		bg->visit();
		this->visit();
		snapshoot->end();

		CCScene* pscene =CCScene::create();
		GameOver* layer=GameOver::create(snapshoot);
		layer->setWin(isWin);
		layer->setDelegate(this);	
		pscene->addChild(layer);
		CCDirector::sharedDirector()->pushScene(pscene);
	}


};

void GameLayer::onLeft(){

	CCArray* childArray=this->getChildren();
	CCObject* pObject;

	CCARRAY_FOREACH(childArray,pObject){		
		//清除侦听
		ActionManager* ac=(ActionManager*) pObject;
		CCNotificationCenter::sharedNotificationCenter()->removeObserver(ac,"acceptAttack");
	}

	//清除地图缓存

	if(randomMap==0) {
		CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/Tower/Tower.plist");	
	}else if(randomMap==1){
		CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/Tower/Tower2.plist");
	}else if (randomMap==2){
		CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/Tower/Tower3.plist");
	}else if (randomMap==3){
		CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/Tower/Tower4.plist");
	}else if (randomMap==4){
		CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/Tower/Tower5.plist");
	}

	KTools* tool=KTools::create();
	

	const char* path;
	CCARRAY_FOREACH(_CharacterArray,pObject){
		ActionManager* player=(ActionManager*) pObject;

		if(strcmp(player->getRole()->getCString(),"Clone")==0 ||
			strcmp(player->getRole()->getCString(),"Summon")==0){
				continue;
		}

		//删除人物缓存
		path=CCString::createWithFormat("Element/%s/%s.plist",player->getCharacter()->getCString(),player->getCharacter()->getCString())->getCString();
		CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile(path);

		//删除预加载音效
		if(strcmp(player->getRole()->getCString(),"Com")==0 ||
			strcmp(player->getRole()->getCString(),"Player")==0
			){
			tool->prepareFileOGG(player->getCharacter()->getCString(),1);
		}
		

		//删除额外角色
		if(strcmp(player->getCharacter()->getCString(),"Jiraiya")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/SageJiraiya/SageJiraiya.plist");
			tool->prepareFileOGG("SageJiraiya",1);
		}else if(strcmp(player->getCharacter()->getCString(),"Kankuro")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/Karasu/Karasu.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/Sanshouuo/Sanshouuo.plist");
		}else if(strcmp(player->getCharacter()->getCString(),"Kakuzu")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/MaskFudon/MaskFudon.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/MaskRaidon/MaskRaidon.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/MaskKadon/MaskKadon.plist");
		}else if(strcmp(player->getCharacter()->getCString(),"Naruto")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/SageNaruto/SageNaruto.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/RikudoNaruto/RikudoNaruto.plist");
			tool->prepareFileOGG("SageNaruto",1);
			tool->prepareFileOGG("RikudoNaruto",1);
		}else if(strcmp(player->getCharacter()->getCString(),"RockLee")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/Lee/Lee.plist");
		}else if(strcmp(player->getCharacter()->getCString(),"Lee")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/RockLee/RockLee.plist");
		}else if(strcmp(player->getCharacter()->getCString(),"Sasuke")==0){
			tool->prepareFileOGG("ImmortalSasuke",1);
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/ImmortalSasuke/ImmortalSasuke.plist");
		}
		player->removeFromParentAndCleanup(true);

	}

	//加载守护忍
	if(this->_isHardCoreGame){
		CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/Roshi/Roshi.plist");
		CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Element/Han/Han.plist");
		tool->prepareFileOGG("Roshi",1);
		tool->prepareFileOGG("Han",1);
	}

	tool->prepareFileOGG("Effect",1);
	tool->prepareFileOGG("Ougis",1);


	_CharacterArray->removeAllObjects();
	_CharacterArray=NULL;


	_TowerArray->removeAllObjects();
	_TowerArray=NULL;
	_KonohaFlogArray->removeAllObjects();
	_KonohaFlogArray=NULL;
	_AkatsukiFlogArray->removeAllObjects();
	_AkatsukiFlogArray=NULL;

	CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("UI.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("Map.plist");

	CCScene* menuScene =CCScene::create();
	StartMenu* menuLayer=StartMenu::create();

	menuScene->addChild(menuLayer);
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(2.0f,menuScene));



}

void GameLayer::checkPost(float dt){

	if(!isPosting && postTime<10){
		
		isPosting=true;
		postTime++;
		cocos2d::extension::CCHttpRequest* request = new  cocos2d::extension::CCHttpRequest(); 
		std::string codeFinal;
		
		
		std::string code2="&pw="+PWord;
		std::string code1=CCString::createWithFormat("code=50&id=%d",MemberID)->getCString();
		std::string code3=CCString::createWithFormat("&version=%d",CURRENT_VERSION)->getCString();
		std::string url=SERVER"nsk/list.php?"+code1+code2+code3;
		request->setUrl(url.c_str());  
		request->setRequestType( cocos2d::extension::CCHttpRequest::kHttpGet);  
		
		request->setResponseCallback(this, callfuncND_selector(GameLayer::onHttpRequestCompleted));  
		

		request->setTag("Post_My_Data");  
		cocos2d::extension::CCHttpClient::getInstance()->send(request);  
		request->release();  

	}else{
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		CCDirector::sharedDirector()->end();
		return;
	}

}

void GameLayer::onHttpRequestCompleted(CCNode *sender ,void *data) {  

	isPosting=false;
	
	cocos2d::extension::CCHttpResponse *response = (cocos2d::extension::CCHttpResponse*)data;    
	if (!response)    
	{  
		return;    
	}   
	
	int statusCode = response->getResponseCode();  
	char statusString[64] = {};  
	
	if (!response->isSucceed())  
	{  	
		return;
	}  
	std::vector<char> *buffer = response->getResponseData();  
	
	Document doc;
	
	std::string buf(buffer->begin(),buffer->end()); 

	if(strcmp(buf.c_str(),"postOK")==0){
		this->unschedule(schedule_selector(GameLayer::checkPost));
	}
}  



void GameLayer::checkBackgroundMusic(float dt){
	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isBGM")!=false){

		if(!SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
			if(!_isHardCoreGame){
				SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/Music/Battle1.mp3");
			}else{
				if(_playNum==0){
					SimpleAudioEngine::sharedEngine()->playBackgroundMusic(CCString::createWithFormat("Audio/Music/Battle%d.mp3",int(2+randomMap*3))->getCString(),false);
					_playNum++;
				}else if(_playNum==1){
					SimpleAudioEngine::sharedEngine()->playBackgroundMusic(CCString::createWithFormat("Audio/Music/Battle%d.mp3",int(3+randomMap*3))->getCString(),false);
					_playNum++;
				}else if(_playNum==2){
					SimpleAudioEngine::sharedEngine()->playBackgroundMusic(CCString::createWithFormat("Audio/Music/Battle%d.mp3",int(1+randomMap*3))->getCString(),false);
					_playNum=0;
				}
			}

			
		}
	}
}


void GameLayer::setOugis(CCNode* sender){

	if(!this->_hudLayer->ougisLayer){
		CCArray* childArray=this->getChildren();
		ougisChar=sender;
		ActionManager* Sender=(ActionManager*) sender;
		CCObject* pObject;
		CCARRAY_FOREACH(childArray,pObject){

			CCNode* object=(CCNode*) pObject;

			object->pauseSchedulerAndActions();

		}
		this->pauseSchedulerAndActions();

		this->updateViewPoint(0.0);

		blend=CCLayerColor::create(ccc4(0, 0, 0, 200),winSize.width,winSize.height);
		blend->setPosition(ccp(-this->getPositionX(),0));
		this->addChild(blend,1000);
		sender->setZOrder(2000);

		if(CCUserDefault::sharedUserDefault()->getBoolForKey("isVoice")!=false){
			SimpleAudioEngine::sharedEngine()->playEffect(CCString::createWithFormat("Audio/Ougis/%s_ougis.mp3",Sender->getCharacter()->getCString())->getCString());
		}

		_hudLayer->setOugis(Sender->getCharacter(),Sender->getGroup());
	}



}

void GameLayer::removeOugis(){
	ougisChar->setZOrder(-ougisChar->getPositionY());
	CCArray* childArray=this->getChildren();
	CCObject* pObject;
	CCARRAY_FOREACH(childArray,pObject){
		CCNode* object=(CCNode*) pObject;
		object->resumeSchedulerAndActions();
	}
	this->resumeSchedulerAndActions();

	blend->removeFromParent();
	ougisChar=NULL;
}
