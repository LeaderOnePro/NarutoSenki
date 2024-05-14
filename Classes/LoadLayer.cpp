#include "LoadLayer.h"


#include<time.h>
#include <fstream>

#ifdef _WIN32
#include <direct.h>
#endif


USING_NS_CC_EXT;
using namespace std;
using namespace CocosDenshion;

LoadLayer::LoadLayer(void)
{
	tempHeros=NULL;
	loadNum=0;
	_hudLayer=NULL;
	_bgLayer=NULL;
	_hudLayer=NULL;
	_isHardCoreMode=false;
	_isRandomChar=false;
	isPosting=false;
	DLCArray=NULL;
}


LoadLayer::~LoadLayer(void)
{

	CC_SAFE_RELEASE(tempHeros);

}

bool LoadLayer::init(){

	bool bRet=false;
	do{
		CC_BREAK_IF(!CCLayer::init());


	
		//produce the menu_bar
		CCSprite* menu_bar_b = CCSprite::create("menu_bar2.png");
		menu_bar_b->setAnchorPoint(ccp(0,0));
		this->addChild(menu_bar_b,2);


		CCSprite* menu_bar_t = CCSprite::create("menu_bar3.png");
		menu_bar_t->setAnchorPoint(ccp(0,0));
		menu_bar_t->setPosition(ccp(0,winSize.height-menu_bar_t->getContentSize().height));
		this->addChild(menu_bar_t,2);

		CCSprite* loading_title=CCSprite::createWithSpriteFrameName("loading_title.png");
		loading_title->setAnchorPoint(ccp(0,0));
		loading_title->setPosition(ccp(2,winSize.height-loading_title->getContentSize().height-2));
		this->addChild(loading_title,3);


		//produce the cloud
		CCSprite* cloud_left=CCSprite::createWithSpriteFrameName("cloud.png");	
		cloud_left->setPosition(ccp(0,15));
		cloud_left->setFlipX(true);
		cloud_left->setFlipY(true);
		cloud_left->setAnchorPoint(ccp(0,0));
		this->addChild(cloud_left,1);

		CCActionInterval* cmv1=CCMoveBy::create(1,ccp(-15,0));
		CCAction* cseq1=CCRepeatForever::create(CCSequence::create(cmv1,cmv1->reverse(),NULL));
		cloud_left->runAction(cseq1);

		CCSprite* cloud_right=CCSprite::createWithSpriteFrameName("cloud.png");	
		cloud_right->setPosition(ccp(winSize.width-cloud_right->getContentSize().width,
			winSize.height-(cloud_right->getContentSize().height+15)));
		cloud_right->setAnchorPoint(ccp(0,0));
		this->addChild(cloud_right,1);

		CCActionInterval* cmv2=CCMoveBy::create(1,ccp(15,0));
		CCAction* cseq2=CCRepeatForever::create(CCSequence::create(cmv2,cmv2->reverse(),NULL));
		cloud_right->runAction(cseq2);


		bRet=true;
	}while(0);

	return bRet;

};


void LoadLayer::preloadIMG(){

	CCObject* pObject=NULL;
	int i=0;
	const char* path;
	KTools* tool=KTools::create();

	CCARRAY_FOREACH(tempHeros,pObject){

		CCDictionary* tempdict=(CCDictionary *) pObject;

		CCString* player=CCString::create(tempdict->valueForKey("character")->getCString());

		
		//加载技能图包
		CCTexture2D::PVRImagesHavePremultipliedAlpha(true); 

		if (strcmp(player->getCString(),"Kiba")!=0 &&
			strcmp(player->getCString(),"Kakuzu")!=0 
			){

				path=CCString::createWithFormat("Element/Skills/%s_Skill.plist",player->getCString())->getCString();
				CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(path);
		}

		//预加载音效
		tool->prepareFileOGG(player->getCString());

	

		/*	if(strcmp(player->getCString(),"Chiyo")==0 ||
		strcmp(player->getCString(),"Shikamaru")==0 ||
		strcmp(player->getCString(),"Kisame")==0
		){

		std::string filePath=CCFileUtils::sharedFileUtils()->getWritablePath()+CCString::createWithFormat("/DLC/%s.xml",player->getCString())->getCString();
		bool isExisted=CCFileUtils::sharedFileUtils()->isFileExist(filePath);

		if(!isExisted){
		if(!DLCArray){
		DLCArray=CCArray::create();
		DLCArray->retain();
		}
		CCDictionary* dic=CCDictionary::create();
		dic->setObject(player,"character");
		DLCArray->addObject(dic);
		}

		}*/

		path=CCString::createWithFormat("Element/%s/%s.plist",player->getCString(),player->getCString())->getCString();
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(path);



		//加载额外角色
		if(strcmp(player->getCString(),"Jiraiya")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/SageJiraiya/SageJiraiya.plist");
			tool->prepareFileOGG("SageJiraiya");
		}else if(strcmp(player->getCString(),"Kankuro")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Karasu/Karasu.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Sanshouuo/Sanshouuo.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Saso/Saso.plist");
		}else if(strcmp(player->getCString(),"Chiyo")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Parents/Parents.plist");	
		}else if(strcmp(player->getCString(),"Kakuzu")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/MaskRaidon/MaskRaidon.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/MaskFudon/MaskFudon.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/MaskKadon/MaskKadon.plist");
		}else if(strcmp(player->getCString(),"Naruto")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/RikudoNaruto/RikudoNaruto.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/SageNaruto/SageNaruto.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Kurama/Kurama.plist");
			tool->prepareFileOGG("SageNaruto");
			tool->prepareFileOGG("RikudoNaruto");
		}else if(strcmp(player->getCString(),"Lee")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/RockLee/RockLee.plist");
		}else if(strcmp(player->getCString(),"Tsunade")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Slug/Slug.plist");
		}else if(strcmp(player->getCString(),"Kakashi")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/DogWall/DogWall.plist");
		}else if(strcmp(player->getCString(),"Deidara")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Centipede/Centipede.plist");
		}else if(strcmp(player->getCString(),"Pain")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/DevaPath/DevaPath.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/AsuraPath/AsuraPath.plist");
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/AnimalPath/AnimalPath.plist");
		}else if(strcmp(player->getCString(),"Sasuke")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/ImmortalSasuke/ImmortalSasuke.plist");
			tool->prepareFileOGG("ImmortalSasuke");
		}else if(strcmp(player->getCString(),"Kiba")==0){
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Akamaru/Akamaru.plist");
		}

		
		if(i==0 ||( (i==1 || i==2 ) && _isHardCoreMode) ){
			
			CCSprite* loadingAvator=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_Walk_01.png",player->getCString())->getCString());
			loadingAvator->setFlipX(true);
			loadingAvator->setPosition(ccp(winSize.width-100+i*16,30));
			loadingAvator->setAnchorPoint(ccp(0,0));

			CCArray* animeFrames = CCArray::create();
			CCString* str;
			
			const char* file=CCString::createWithFormat("%s_Walk_",player->getCString())->getCString();
			int frameCount;
			if(strcmp(player->getCString(),"Konan")==0){
				frameCount=1;
			}else {
				frameCount=7;
			}

			for(int i = 1; i < frameCount; i++){	
				str=CCString::createWithFormat("%s%02d.png",file,i);
				CCSpriteFrame *frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString());
				animeFrames->addObject(frame);
			}

			CCAnimation* tempAnimation=CCAnimation::createWithSpriteFrames(animeFrames, float(1.0 / 10.0));
			CCAction* tempAction=CCAnimate::create(tempAnimation);
			CCArray* seqArray=CCArray::createWithObject(tempAction);
			CCAction* seq;
            seq=CCRepeatForever::create(CCSequence::create(seqArray));

			this->addChild(loadingAvator);
			loadingAvator->runAction(seq);


			
		}

		i++;

	};

	tempHeros->retain();


	//加载守护忍
	if(_isHardCoreMode){
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Roshi/Roshi.plist");
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Han/Han.plist");
		tool->prepareFileOGG("Roshi");
		tool->prepareFileOGG("Han");
	}
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Flog/KotetsuFlog.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Flog/FemalePainFlog.plist");


	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Flog/IzumoFlog.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Flog/KakashiFlog.plist");

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Flog/PainFlog.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Element/Flog/ObitoFlog.plist");
	
	tool->prepareFileOGG("Effect");
	tool->prepareFileOGG("Ougis");

	
	try{
		srand((int)time(0));
		int num=rand()%3+1;	
		CCSprite* tips=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("tip%d.png",num)->getCString());	
		tips->setPosition(ccp(winSize.width/2,winSize.height/2));
		this->addChild(tips);

	}catch(...){
		CCLOG("error");
		return;
	}


	CCSprite* loading=CCSprite::createWithSpriteFrameName("loading_font.png");

	loading->setPosition(ccp(winSize.width-120,45));
	CCActionInterval* fade=CCFadeOut::create(1.0f);
	CCAction* fadeseq=CCRepeatForever::create(CCSequence::create(fade,fade->reverse(),NULL));
	this->addChild(loading);
	loading->runAction(fadeseq);

	this->scheduleOnce(schedule_selector(LoadLayer::playBGM),1.0f);



	if(!DLCArray){
		this->scheduleOnce(schedule_selector(LoadLayer::onLoadFinish),3.0f);
	}else{
		CCObject* tmpObject;
		int i=0;
		CCARRAY_FOREACH(DLCArray,tmpObject){
			CCDictionary* tempdict=(CCDictionary *) tmpObject;
			CCString* heroString=CCString::create(tempdict->valueForKey("character")->getCString());
			isPosting=true;
			cocos2d::extension::CCHttpRequest* request = new  cocos2d::extension::CCHttpRequest(); 
			std::string codeFinal;
			std::string code1=CCString::createWithFormat("code=300&id=%d",MemberID)->getCString();
			std::string code2=CCString::createWithFormat("&version=%d",CURRENT_VERSION)->getCString();
			std::string code3=CCString::createWithFormat("&char=%s",heroString->getCString())->getCString();
			std::string url=SERVER"nsk/list.php?"+code1+code2+"&pw="+PWord+code3;

			request->setUrl(url.c_str());  
			request->setRequestType(CCHttpRequest::kHttpGet);  
			request->setResponseCallback(this, callfuncND_selector(LoadLayer::onHttpRequestCompleted));  
			request->setTag(heroString->getCString());  
			cocos2d::extension::CCHttpClient::getInstance()->send(request);  
			request->release();  
			i++;
		}
	}
	


}

void LoadLayer::playBGM(float dt){
   SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/Music/loading_music.mp3",false);
}


void LoadLayer::onHttpRequestCompleted(CCNode *sender ,void *data) {  
	/*AllocConsole();  
	freopen("CONIN$", "r", stdin);  
	freopen("CONOUT$", "w", stdout);  
	freopen("CONOUT$", "w", stderr);*/
	isPosting=false;
	
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
	
	if (!response->isSucceed())  
	{  
		CCLog("response failed");  
		CCLog("error buffer:%s" ,response->getErrorBuffer());
		CCTips *tip=CCTips::create("ServerError");
		this->addChild(tip,5000);
		return;
	}  

	


	std::vector<char> *buffer = response->getResponseData();  
	std::string buf(buffer->begin(),buffer->end()); 
	
	/*for (unsigned int i = 0; i < buffer->size(); i ++)  
	{  
	printf("%c" ,(*buffer)[i]);
	}  */
	
	std::string foldName=CCFileUtils::sharedFileUtils()->getWritablePath()+"DLC";

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	mkdir(foldName.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
#else
	_mkdir(foldName.c_str());
#endif


	std::string fileName = CCString::createWithFormat("%s.xml",response->getHttpRequest()->getTag())->getCString();
	//std::string filePath = CCFileUtils::sharedFileUtils()->getWritablePath()+"DLC" + fileName;
	
	const char* filePath;
	
	filePath =CCString::createWithFormat("%s/DLC/%s.xml",CCFileUtils::sharedFileUtils()->getWritablePath().c_str(),response->getHttpRequest()->getTag())->getCString();
	
	std::ofstream fos(filePath);//创建打开文件
	if(!fos)cerr<<"error";//校验文件
	fos<<buf;//输出
	fos.close();
	//std::remove(filePath.c_str());
	

	CCObject* tmpObject;
	int i=0;
	CCARRAY_FOREACH(DLCArray,tmpObject){
		CCDictionary* tempdict=(CCDictionary *) tmpObject;
		CCString* heroString=CCString::create(tempdict->valueForKey("character")->getCString());
		if(strcmp(heroString->getCString(),response->getHttpRequest()->getTag())==0){
			DLCArray->removeObject(tmpObject);
		}
		
	}
	
	if(DLCArray->count()<=0){
		this->scheduleOnce(schedule_selector(LoadLayer::onLoadFinish),3.0f);
	}

}  

void LoadLayer::preloadAudio(){
	
	char* bg_src;
	if(_isHardCoreMode){
		bg_src="blue_bg.png";
	}else{
		bg_src="red_bg.png";
	}
	CCSprite* bgSprite = CCSprite::create(bg_src);
	
	bgSprite->setAnchorPoint(ccp(0,0));
	bgSprite->setPosition(ccp(0,0));
	this->addChild(bgSprite, -5);

	KTools* tool=KTools::create();
	tool->prepareFileMD5();
	std::string str2="fkhfnPG8";
	tool->decode(str2);
	std::string filePath=CCFileUtils::sharedFileUtils()->getWritablePath()+CCString::createWithFormat("%s.xml",str2.c_str())->getCString();
	std::string strFileMD5 =CMD5Checksum::GetMD5(filePath);
	remove(filePath.c_str());
	CCString* code1=CCString::createWithFormat("%s%s",strFileMD5.substr(16,5).c_str(),strFileMD5.substr(6,5).c_str());
	if(strcmp(code1->getCString(),"e0213bffe1")!=0){
	const char* soundpath="Audio";
	//return;
	//tool->dfsFolder(soundpath,0,1);
	}

	this->preloadIMG();
}

void LoadLayer::onLoadFinish(float dt){

	

	CCScene* gameScene=CCScene::create();

	_gameLayer=GameLayer::create();
	_gameLayer->Heros=tempHeros;
	_gameLayer->_isHardCoreGame=_isHardCoreMode;
	_gameLayer->_isRandomChar=_isRandomChar;
	_gameLayer->initHeros();

	_bgLayer=BGLayer::create();
	_bgLayer->setDelegate(_gameLayer);

	_hudLayer=HudLayer::create();
	_hudLayer->setDelegate(_gameLayer);
	//_hudLayer->initHeroInterface();

	_gameLayer->setHudLayer(_hudLayer);
	_gameLayer->setTotalKills(CCString::create("0"));
	_gameLayer->setTotalTM(CCString::create("0"));

	gameScene->addChild(_gameLayer,GlTag);
	gameScene->addChild(_bgLayer,BgTag);
	gameScene->addChild(_hudLayer,HudTag);

	KTools* tool= KTools::create();
	
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f,gameScene));

}

void LoadLayer::preloadPlist(CCObject* obj){

	CCTexture2D* texture=(CCTexture2D*)obj; //传入的obj即是异步生成的纹理  
	
	CCObject* pObject=tempHeros->objectAtIndex(loadNum);
	CCDictionary* tempdict=(CCDictionary *) pObject;
	CCString* player=CCString::create(tempdict->valueForKey("character")->getCString());
	const char* name=player->getCString();

    const char* path=CCString::createWithFormat("Element/%s/%s.plist",name,name)->getCString();
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(path,texture);//通过纹理和.plist文件加入CCSpriteFrameCache  

	loadNum++;

	if(loadNum<6){
	this->preloadIMG();
	}else{
		this->onLoadFinish(0.2f);
	}


}

void LoadLayer::onEnter(){
	CCLayer::onEnter();

}

void LoadLayer::onExit(){
	CCLayer::onExit();
}