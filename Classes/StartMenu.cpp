#include "StartMenu.h"
using namespace CocosDenshion;
USING_NS_CC_EXT;


int Cheats=0;
int MemberID=NULL;
int GroupID=NULL;
std::string PWord="";
std::string CValue="999999";
bool isFirst=false;
bool isPlayed=true;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)   
#include <jni.h>   
#include "../cocos2dx/platform/android/jni/JniHelper.h"   

extern "C"  
{  
	void Java_net_zakume_game_NarutoSenki_onBannerInit( JNIEnv *env,jobject thiz,jint points)
	{
		adResult=points;
		
	}
}  
#endif  


/*----------------------
init MenuButton ;
----------------------*/
MenuButton::MenuButton(void)
{
	_isTop=false;
	_isBottom=false;
}


MenuButton::~MenuButton(void)
{
	
}


bool MenuButton::init(const char *szImage){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCSprite::init());
		this->initWithSpriteFrameName(szImage);
		this->setAnchorPoint(ccp(0.5,0));

		bRet=true;

	}while(0);

	return bRet;

}

void MenuButton::onEnter(){
	CCSprite::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,10,true);
	
#if CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID

	JniMethodInfo minfo;

	bool isHave = JniHelper::getStaticMethodInfo(minfo,"net/zakume/game/NarutoSenki","showBanner", "()V"); 
	if (isHave) { 	
		minfo.env -> CallStaticVoidMethod(minfo.classID,minfo.methodID);
	} 

#endif  


}
void MenuButton::onExit(){
	CCSprite::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

CCRect MenuButton::getRect(){
	CCSize size=this->getContentSize();
	return CCRect(0,0, size.width, size.height);

}
bool MenuButton::containsTouchLocation(CCTouch *touch){

	return getRect().containsPoint(convertTouchToNodeSpace(touch));
}


void MenuButton::setBtnType(btnType type){
	_btnType=type;
}

btnType	MenuButton::getBtnType(){
	return _btnType;
}

bool MenuButton::ccTouchBegan(CCTouch* touch,CCEvent* event){
	// touch area 
	if (!this->containsTouchLocation(touch))
		return false;

	//click();
 
	prePosY=NULL;

	return true;

}

void MenuButton::ccTouchMoved(CCTouch* touch,CCEvent* event){
	// touch area 
	if(prePosY==NULL){
		prePosY=touch->getLocation().y;

	}else{
		if(this->getBtnType()!=HardCore){

			if(abs(touch->getLocation().y-prePosY)>16){
				if(touch->getLocation().y<prePosY){
					_delegate->isClockwise=true;
				}else{
					_delegate->isClockwise=false;
				}
				_delegate->isDrag=true;
			}


		}
		
	}
	


}

void MenuButton::ccTouchEnded(CCTouch* touch,CCEvent* event){
	if(_isTop && !_delegate->isDrag){
	
		switch(_btnType){
		case Training:
				SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/confirm.ogg");
			_delegate->onTrainingCallBack();
			break;
		case Credits:
				SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/confirm.ogg");
			_delegate->onCreditsCallBack();
			break;
		case Exit:
				SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/confirm.ogg");
			_delegate->onExitCallBack();
			break;
		case Network:
			SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/confirm.ogg");
			_delegate->onHardCoreCallBack();
			break;;
		case HardCore:
			/*SimpleAudioEngine::sharedEngine()->playEffect(SELECT_SOUND);
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("menu05_text.png"); 
			_delegate->menuText->setDisplayFrame(frame);

			if( CCUserDefault::sharedUserDefault()->getBoolForKey("isHardCore")==true){		
			CCUserDefault::sharedUserDefault()->setBoolForKey("isHardCore",false);
			if(_delegate->hardCore_btn){
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("menu02_2.png"); 
			_delegate->hardCore_btn->setDisplayFrame(frame);
			}
			}else{
			_delegate->onHardLayerCallBack();
			}*/


			break;
		}
	}else{
		SimpleAudioEngine::sharedEngine()->playEffect(SELECT_SOUND);
		prePosY=NULL;
		_delegate->scrollMenu(this->getPositionY());
		_delegate->isDrag=false;
	}

};



void MenuButton::playSound(){

	SimpleAudioEngine::sharedEngine()->stopAllEffects();

	switch(_btnType){
	case Training:
		SimpleAudioEngine::sharedEngine()->playEffect(TRAINING_SOUND);
		/*if(this->getBtnType()==Training){
		_delegate->hardCore_btn->setVisible(true);
		}*/
		break;
	case Network:
		SimpleAudioEngine::sharedEngine()->playEffect(NETWORK_SOUND);
		break;
	case Credits:
		SimpleAudioEngine::sharedEngine()->playEffect(CREDITS_SOUND);
		break;
	case Exit:
		SimpleAudioEngine::sharedEngine()->playEffect(EXIT_SOUND);
		break;
	}
	
}

MenuButton* MenuButton::create( const char *szImage ){
	MenuButton* mb=new MenuButton();
	if (mb && mb->init(szImage))
	{
		mb->autorelease();
		return mb;
	}
	else
	{
		delete mb;
		return NULL;
	}
}



/*----------------------
init StartMenu layer;
----------------------*/

StartMenu::StartMenu(void)
{
	_menu_array=NULL;
	isClockwise=false;
	isDrag=false;
	isNewAviable=false;
	hardCore_btn=NULL;
	hardCoreLayer=NULL;
	isBondAviable=false;
	isTasking=false;
	isPosting=false;
	input_layer=NULL;
	notice_layer=NULL;
	profile_layer=NULL;
	refreshBtn=NULL;
	noticeLabel=NULL;
	task_btn=NULL;
	login_btn=NULL;
	group_layer=NULL;
	leaderID=0;
	maxGroupNum=5;
	totalGroupNum=NULL;
	lock_btn=NULL;
	 isLock=false;
	notice_label=NULL;
	_screwLayer1=NULL;
}


StartMenu::~StartMenu(void)
{
	
}

bool StartMenu::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		
		

		SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);

		//CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


		//CCSprite* bgSprite = CCSprite::create("red_bg.png");
		////pSprite->setPosition(ccp(winSize.width/2 + origin.x, winSize.height/2 + origin.y));
		//bgSprite->setAnchorPoint(ccp(0,0));
		//bgSprite->setPosition(ccp(0,0));
		//this->addChild(bgSprite, -5);


		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Menu.plist");
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Result.plist");	
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("NamePlate.plist");	
		//produce groud 

		CCSprite* gold_left=CCSprite::createWithSpriteFrameName("gold_left.png");
		gold_left->setAnchorPoint(ccp(0,0));
		gold_left->setPosition(ccp(0,20));
		this->addChild(gold_left,1);


		CCSprite* gold_right=CCSprite::createWithSpriteFrameName("gold_right.png");
		gold_right->setAnchorPoint(ccp(0,1));
		gold_right->setPosition(ccp(winSize.width-gold_right->getContentSize().width-20,winSize.height-20));
		this->addChild(gold_right,1);

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

	
		

		//produce the menu_bar
		CCSprite* menu_bar_b = CCSprite::create("menu_bar2.png");
		menu_bar_b->setAnchorPoint(ccp(0,0));
		this->addChild(menu_bar_b,2);


		CCSprite* menu_bar_t = CCSprite::create("menu_bar3.png");
		menu_bar_t->setAnchorPoint(ccp(0,0));
		menu_bar_t->setPosition(ccp(0,winSize.height-menu_bar_t->getContentSize().height));
		this->addChild(menu_bar_t,2);

		CCSprite* startmenu_title=CCSprite::createWithSpriteFrameName("startmenu_title.png");
		startmenu_title->setAnchorPoint(ccp(0,0));
		startmenu_title->setPosition(ccp(2,winSize.height-startmenu_title->getContentSize().height-2));
		this->addChild(startmenu_title,3);

		//produce the menu button

		this->setMenus(CCArray::createWithCapacity(3));

		MenuButton* network_btn=MenuButton::create("menu01.png");
		network_btn->setDelegate(this);
		network_btn->setBtnType(Network);
		network_btn->setScale(0.5f);
		network_btn->setPositionY(_pos03);
		_menu_array->addObject(network_btn);

		MenuButton* credits_btn=MenuButton::create("menu04.png");
		credits_btn->setDelegate(this);
		credits_btn->setBtnType(Credits);
		credits_btn->setScale(0.5f);
		credits_btn->setVisible(false);
		credits_btn->_isBottom=true;
		credits_btn->setPositionY(_pos02);
		_menu_array->addObject(credits_btn);


		MenuButton* training_btn=MenuButton::create("menu02.png");
		training_btn->setDelegate(this);
		training_btn->setBtnType(Training);
		training_btn->_isTop=true;
		training_btn->setPositionY(_pos02);
		_menu_array->addObject(training_btn);

		/*if(!CCUserDefault::sharedUserDefault()->getBoolForKey("isHardCore")){
			CCUserDefault::sharedUserDefault()->setBoolForKey("isHardCore", false);
			CCUserDefault::sharedUserDefault()->flush();
		}
		

		if(CCUserDefault::sharedUserDefault()->getBoolForKey("isHardCore")==true){
			hardCore_btn=MenuButton::create("menu02_1.png");
		}else{
			hardCore_btn=MenuButton::create("menu02_2.png");
		}

		hardCore_btn->setDelegate(this);
		hardCore_btn->setBtnType(HardCore);
		hardCore_btn->setPosition(ccp(146,_pos02-18));
		hardCore_btn->_isTop=true;
		this->addChild(hardCore_btn,10);*/




		MenuButton* exit_btn=MenuButton::create("menu03.png");
		exit_btn->setDelegate(this);
		exit_btn->setBtnType(Exit);
		exit_btn->setScale(0.5f);
		exit_btn->setPositionY(_pos01);
		_menu_array->addObject(exit_btn);
		
		
		

		menuText=CCSprite::createWithSpriteFrameName("menu02_text.png");
		menuText->setAnchorPoint(ccp(0,0));
		menuText->setPosition(ccp(10,2));
		this->addChild(menuText,5);

		CCObject* pObject=NULL;
		CCARRAY_FOREACH(_menu_array,pObject){
			MenuButton* menu=(MenuButton *)pObject;
			menu->setPositionX(105);
			this->addChild(menu,2);
		};


		//版本号
		CCLabelBMFont* versionLabel=CCLabelBMFont::create("1.23 EX Version","Fonts/1.fnt");
		versionLabel->setScale(0.3f);
		versionLabel->setPosition(winSize.width-60,10);
		this->addChild(versionLabel,5);

		CCSprite* avator=CCSprite::createWithSpriteFrameName("avator1.png");
		avator->setAnchorPoint(ccp(0,0));
		avator->setOpacity(0);
		avator->setPosition(ccp(winSize.width-avator->getContentSize().width,19));
		this->addChild(avator,1);


		CCArray* tempArray= CCArray::create();

		int i=1;
		
		CCArray* list=CCArray::create();
		while (i<5)
		{
			CCString* path=CCString::createWithFormat("avator%d.png",i);
			CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(path->getCString());
			tempArray->addObject(frame);
			CCAnimation* tempAnimation= CCAnimation::createWithSpriteFrames(tempArray, 0.1f);
			CCAction* tempAction=CCAnimate::create(tempAnimation);
			list->addObject(tempAction);
			CCActionInterval* fadeIn=CCFadeIn::create(0.8f);	
			CCDelayTime* delay=CCDelayTime::create(1.0f);
			CCActionInterval* fadeOut=CCFadeOut::create(0.5f);	
			list->addObject(fadeIn);
			list->addObject(delay);
			list->addObject(fadeOut);
			i+=1;
		}


		avator->runAction(CCRepeatForever::create(CCSequence::create(list)));

		//公告按钮
		CCMenuItem* news_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("news_btn.png"),NULL,NULL,this,menu_selector(StartMenu::onNewsBtn));
		CCMenu* menu =CCMenu::create(news_btn,NULL);
		news_btn->setAnchorPoint(ccp(0,0.5f));
		menu->setPosition(15,winSize.height-50);
		this->addChild(menu,5);


		this->setNotice();
		
		//积分墙公告
		if(MemberID){
			this->setGroup();
			this->setOfferWall();
			this->setProfile();
			this->scrollMenu(_pos03);
			
		}else{
			//登陆按钮
			login_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("login_btn.png"),NULL,NULL,this,menu_selector(StartMenu::onLoginBtn));
			CCMenu* menu2 =CCMenu::create(login_btn,NULL);
			login_btn->setAnchorPoint(ccp(1,0.5f));
			menu2->setPosition(winSize.width-15,winSize.height-50);
			this->addChild(menu2,5);
		}
	


		if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID){
			this->setKeypadEnabled(true);
		}

		this->scheduleUpdate();
		
		bRet=true;

	}while(0);

	return bRet;

}
void StartMenu::onEnter(){
	CCLayer::onEnter();
	SimpleAudioEngine::sharedEngine()->end();

	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isBGM")!=false){
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/Music/menu_music.mp3",true);
	}

	if(isPlayed){
		isPlayed=false;

#if CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID

		JniMethodInfo minfo;

		bool isHave = JniHelper::getStaticMethodInfo(minfo,"net/zakume/game/NarutoSenki","showSpotAd", "()V"); 
		if (isHave) { 	
			minfo.env -> CallStaticVoidMethod(minfo.classID,minfo.methodID);
		} 

#endif  
	}


}
void StartMenu::onExit(){
	CCLayer::onExit();
	
}

void StartMenu::setOfferWall(){

	//if(MemberID && !task_btn){
	//	CCString* user_id=CCString::createWithFormat("%d",MemberID);
	//	const std::string user_string=user_id->getCString();
	//
	//	#if CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID
	//	JniMethodInfo minfo;

	//	bool isHave = JniHelper::getStaticMethodInfo(minfo,"net/zakume/game/NarutoSenki","setupTask", "(Ljava/lang/String;)V"); 
	//	if (isHave) { 	
	//		jstring user_arg = minfo.env->NewStringUTF(user_string.c_str());
	//		minfo.env -> CallStaticVoidMethod(minfo.classID,minfo.methodID,user_arg);
	//	} 
	//	#endif  

	//	//积分墙按钮
	//	task_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("tasks_btn.png"),NULL,NULL,this,menu_selector(StartMenu::onTasksBtn));
	//	CCMenu* menu3 =CCMenu::create(task_btn,NULL);
	//	task_btn->setAnchorPoint(ccp(1,0.5f));
	//	menu3->setPosition(winSize.width-20,winSize.height-110);
	//	this->addChild(menu3,5);

	//}

	


}
void StartMenu::setGroup(){

	

	//组织按钮
	CCMenuItemSprite* group_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("group_btn.png"),NULL,NULL,this,menu_selector(StartMenu::onGroupBtn));
	CCMenu* menu3 =CCMenu::create(group_btn,NULL);
	group_btn->setAnchorPoint(ccp(1,0.5f));
	menu3->setPosition(winSize.width-70,winSize.height-110);
	this->addChild(menu3,5);




}
void  StartMenu::onGroupBtn(CCObject* sender){

	if(!group_layer && !profile_layer){

		//刷新按钮
		if(!refreshBtn){
			refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
			refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
			CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
			refreshBtn->runAction(CCRepeatForever::create(rt));
			this->addChild(refreshBtn,1000);

		}
		group_layer=CCLayer::create();
		CCSprite* group_bg=CCSprite::createWithSpriteFrameName("group_bg.png");
		group_bg->setPosition(ccp(winSize.width/2,winSize.height/2));

		group_layer->addChild(group_bg);

		//关闭
		CCMenuItemSprite* close_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("profile_closeBtn.png"),NULL,NULL,this,menu_selector(StartMenu::onIterfaceClose));
		CCMenu* menu =CCMenu::create( close_btn,NULL);
		menu->setPosition(ccp(group_bg->getPositionX()+group_bg->getContentSize().width/2,group_bg->getPositionY()+group_bg->getContentSize().height/2-30));
		group_layer->addChild(menu);

		isPosting=true;


		if(GroupID){
			CCSprite* group_content=CCSprite::createWithSpriteFrameName("group_content2.png");
			group_content->setPosition(ccp(winSize.width/2,winSize.height/2-8));

			group_layer->addChild(group_content);

			//加载内容

			CCClippingNode* clipper = CCClippingNode::create();
			CCNode *stencil = CCSprite::createWithSpriteFrameName("groupMask2.png");
			stencil->setAnchorPoint(ccp(0,0));
			clipper->setStencil(stencil);


			_screwLayer1=CCScrewLayer::create();
			_screwLayer1->setAnchorPoint(ccp(0,0));
			_screwLayer1->setPositionY(116);
			_screwLayer1->minY=116;

			clipper->setPosition(ccp(group_bg->getPositionX()-group_bg->getContentSize().width/2,64));
			clipper->addChild(_screwLayer1,5);

			group_layer->addChild(clipper,20);
			
			this->addChild(group_layer,500);


			cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
			std::string code2=CCString::createWithFormat("%d",MemberID)->getCString();
			std::string code3=CCString::createWithFormat("%d",GroupID)->getCString();
			std::string code="code=500&MemberID="+code2+"&GroupID="+code3;
			std::string url=SERVER"nsk/group.php?"+code;
			request->setUrl(url.c_str());  
			request->setRequestType(CCHttpRequest::kHttpGet);  
			request->setResponseCallback(this, callfuncND_selector(StartMenu::onGroupManageRequestCompleted));  
			request->setTag("Post_My_Data");  
			cocos2d::extension::CCHttpClient::getInstance()->send(request);  
			request->release();  

		}else{
					
			CCSprite* group_content=CCSprite::createWithSpriteFrameName("group_content1.png");
			group_content->setPosition(ccp(winSize.width/2,winSize.height/2));

			group_layer->addChild(group_content);

			//加载内容

			CCClippingNode* clipper = CCClippingNode::create();
			CCNode *stencil = CCSprite::createWithSpriteFrameName("groupMask1.png");
			stencil->setAnchorPoint(ccp(0,0));
			clipper->setStencil(stencil);


			_screwLayer1=CCScrewLayer::create();
			_screwLayer1->setAnchorPoint(ccp(0,0));
			_screwLayer1->setPositionY(100);
			_screwLayer1->minY=100;

			clipper->setPosition(ccp(group_bg->getPositionX()-group_bg->getContentSize().width/2,62));
			clipper->addChild(_screwLayer1,5);

			group_layer->addChild(clipper,20);


			CCScale9Sprite * bg01=CCScale9Sprite::createWithSpriteFrameName("input_bg2.png");

			searchInput =CCEditBox::create(CCSizeMake(114, 20), bg01);
			CCDictionary *strings = CCDictionary::createWithContentsOfFile("Element/strings.xml");  
			const char *reply = ((CCString*)strings->objectForKey("SeachTips"))->m_sString.c_str();  
			searchInput->setPlaceHolder(reply);
			searchInput->setFontColor(ccc3(255,255,255));
			searchInput->setPosition(ccp(group_bg->getPositionX()-group_bg->getContentSize().width/2+74,43));
			searchInput->setInputMode(kEditBoxInputModeNumeric);
			searchInput->setReturnType(kKeyboardReturnTypeDefault);
			group_layer->addChild(searchInput,20);



			//查询按钮
			CCMenuItemSprite* search_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("search_btn.png"),CCSprite::createWithSpriteFrameName("search_btn2.png"),NULL,this,menu_selector(StartMenu::onSearchBtn));
			CCMenu* menu3 =CCMenu::create(search_btn,NULL);
			menu3->setPosition(ccp(group_bg->getPositionX()-group_bg->getContentSize().width/2+150,43));
			group_layer->addChild(menu3,20);

			if(atoi(CValue.c_str()) >= 50*30 +500){
				CCMenuItemSprite* create_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("createGroup_btn.png"),CCSprite::createWithSpriteFrameName("createGroup_btn2.png"),NULL,this,menu_selector(StartMenu::onCreateBtn));
				CCMenu* menu2 =CCMenu::create(create_btn,NULL);
				menu2->setPosition(ccp(group_bg->getPositionX()+group_bg->getContentSize().width/2-56,43));
				group_layer->addChild(menu2,20);

			}else{
				CCMenuItemSprite* create_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("createGroup_btn3.png"),NULL,NULL,this,menu_selector(StartMenu::onCreateBtn));
				CCMenu* menu2 =CCMenu::create(create_btn,NULL);
				menu2->setPosition(ccp(group_bg->getPositionX()+group_bg->getContentSize().width/2-56,43));
				group_layer->addChild(menu2,20);
			}
			this->addChild(group_layer,500);

			cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
			std::string code2=CCString::createWithFormat("%d",MemberID)->getCString();
			std::string code="code=100&MemberID="+code2;
			std::string url=SERVER"nsk/group.php?"+code;
			request->setUrl(url.c_str());  
			request->setRequestType(CCHttpRequest::kHttpGet);  
			request->setResponseCallback(this, callfuncND_selector(StartMenu::onGroupRequestCompleted));  
			request->setTag("Post_My_Data");  
			cocos2d::extension::CCHttpClient::getInstance()->send(request);  
			request->release();  
			
		}
	}

}
void StartMenu::onGroupManageRequestCompleted(CCNode *sender ,void *data){  

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



	Document doc;
	std::string buf(buffer->begin(),buffer->end()); 
	const char* json=(char*) buf.c_str();
	doc.Parse<kParseDefaultFlags>(json);
	Value &arr=doc;
	int countRow=0;
	
	if(arr.IsArray()){

		for (SizeType i = 0; i < arr.Size(); i++)  {
			if(i==0){


				Value & node=arr[i];
				Value & nameValue= node["group_name"];
				std::string nameString=nameValue.GetString();




				Value & leaderidValue= node["leader_id"];
				std::string leaderidString=leaderidValue.GetString();
				leaderID=atoi(leaderidString.c_str());

				Value & leadernameValue= node["leader_name"];
				std::string leadernameString=leadernameValue.GetString();

				Value & noticeValue= node["group_notice"];
				std::string noticeString=noticeValue.GetString();


				Value & maxValue= node["maxNum"];
				 maxGroupNum=maxValue.GetInt();

				 Value & pointValue= node["pointNO"];
				 int pointNO =pointValue.GetInt();
				
				 Value & battleValue= node["battleNO"];
				 int battleNO =battleValue.GetInt();

				 Value & pwValue= node["pw"];
				 std::string pwString=pwValue.GetString();
				
				
				
				 CCMenuItem*  notice_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("notice_btn.png"),NULL,NULL,this,menu_selector(StartMenu::onNoticeBtn));
				 notice_btn->setTag(leaderID);
				 CCMenu* menu2 =CCMenu::create( notice_btn,NULL);
				 menu2->setPosition(ccp(winSize.width/2+122,winSize.height/2+4));
				 group_layer->addChild(menu2);

				
				 notice_label=CCLabelTTF::create(noticeString.c_str(),FONT_TYPE,10);
				 
				 notice_label->setDimensions(CCSizeMake(70, 0)); 
				  notice_label->setAnchorPoint(ccp(0,1));
				 notice_label->setPosition(ccp(winSize.width/2+85,winSize.height/2+36));
				 group_layer->addChild( notice_label);


				 CCMenuItem*  quit_btn;
				 if(leaderID==MemberID){
					 quit_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("dissolve_btn.png"),CCSprite::createWithSpriteFrameName("dissolve_btn2.png"),NULL,this,menu_selector(StartMenu::onQuitBtn));
					
				 }else{
					 quit_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("quit_btn.png"),CCSprite::createWithSpriteFrameName("quit_btn2.png"),NULL,this,menu_selector(StartMenu::onQuitBtn));					 
				 }
				
				 quit_btn->setTag(leaderID);
				 CCMenu* menu3 =CCMenu::create(quit_btn,NULL);
				 menu3->setPosition(ccp(winSize.width/2+124,winSize.height/2-80));
				 group_layer->addChild(menu3);

				 lock_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("lock_btn2.png"),CCSprite::createWithSpriteFrameName("lock_btn.png"),NULL,this,menu_selector(StartMenu::onLockBtn));
				 lock_btn->setTag(leaderID);
				 CCMenu* menu =CCMenu::create(lock_btn,NULL);
				 menu->setPosition(ccp(winSize.width/2+140,winSize.height/2+84));
				 group_layer->addChild(menu);

				 if(strcmp(pwString.c_str(),"")!=0){
					 lock_btn->selected();
					  isLock=true;
				 }else{
					 lock_btn->unselected();
					  isLock=false;
				 }



				CCLabelTTF* group_name=CCLabelTTF::create(nameString.c_str(),FONT_TYPE,12);
				group_name->setPosition(ccp(winSize.width/2-2,winSize.height/2+84));
				group_layer->addChild(group_name);


				CCLabelTTF* group_id=CCLabelTTF::create(CCString::createWithFormat("%d",GroupID)->getCString(),FONT_TYPE,12);
				 group_id->setPosition(ccp(winSize.width/2-106,winSize.height/2+87));
				 group_layer->addChild(group_id);

			
				CCLabelTTF* leader_name=CCLabelTTF::create(leadernameString.c_str(),FONT_TYPE,12);
				leader_name->setPosition(ccp(winSize.width/2-79,winSize.height/2-115));
				group_layer->addChild(leader_name);

				CCLabelTTF* point_no=CCLabelTTF::create(CCString::createWithFormat("No.%d",pointNO)->getCString(),FONT_TYPE,12);
				point_no->setColor(ccc3(34,254,6));
				
				point_no->setPosition(ccp(winSize.width/2+40,winSize.height/2-115));
				group_layer->addChild(point_no);


				CCLabelTTF* battle_no=CCLabelTTF::create(CCString::createWithFormat("No.%d",battleNO)->getCString(),FONT_TYPE,12);
				battle_no->setColor(ccc3(0,246,255));
				battle_no->setPosition(ccp(winSize.width/2+134,winSize.height/2-115));
				group_layer->addChild(battle_no);

				

			}else{
				CCScrewItem* screwItem=CCScrewItem::create();

				Value & node=arr[i];


				Value & idValue= node["id"];
				std::string idString=idValue.GetString();
				int userID=atoi(idString.c_str());

				

				Value & nameValue= node["name"];
				std::string nameString=nameValue.GetString();

				Value & battleValue= node["battle_point"];
				std::string battleString=battleValue.GetString();
				int battlePoint=atof(battleString.c_str())*100;

				Value & pointValue= node["point"];
				std::string pointString=pointValue.GetString();
				int point=atoi(pointString.c_str());

				if(leaderID==MemberID){
					CCLabelTTF* user_name=CCLabelTTF::create(nameString.c_str(),FONT_TYPE,12);
					CCMenuItemLabel* item=CCMenuItemLabel::create(user_name, this, menu_selector(StartMenu::onSelectGroupBtn));
					item->setTag(userID); 
					CCMenu* pMenu = CCMenu::create(item, NULL);
					pMenu ->setPosition(ccp(61,5));
					item ->setAnchorPoint(ccp(0.5f,0));
					screwItem->addChild(pMenu);

				}else{
					CCLabelTTF* user_name=CCLabelTTF::create(nameString.c_str(),FONT_TYPE,12);
					
					user_name ->setPosition(ccp(61,5));
					user_name ->setAnchorPoint(ccp(0.5f,0));
					screwItem->addChild(user_name);
				}
				



				CCLabelTTF* user_point=CCLabelTTF::create(CCString::createWithFormat("%d", point)->getCString(),FONT_TYPE,10);	
				user_point->setPosition(ccp(134,5));
				user_point->setAnchorPoint(ccp(0.5f,0));
				screwItem->addChild(user_point);



				CCLabelTTF* battle_point=CCLabelTTF::create(CCString::createWithFormat("%d", battlePoint)->getCString(),FONT_TYPE,10);	
				battle_point->setPosition(ccp(184,5));
				battle_point->setAnchorPoint(ccp(0.5f,0));
				screwItem->addChild(battle_point);

				if(leaderID==MemberID  && MemberID!=userID){
					CCMenuItem* kick_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("kick_btn.png"),CCSprite::createWithSpriteFrameName("kick_btn2.png"),NULL,this,menu_selector(StartMenu::onKickBtn));
					
					kick_btn->setTag(userID);
					screwItem->linemenu=CCMenu::create(kick_btn,NULL);
					screwItem->linemenu->setPosition(ccp(230,12));
					screwItem->linemenu->setAnchorPoint(ccp(0.5f,0));
					screwItem->addChild(screwItem->linemenu);
					screwItem->linemenu->setVisible(false);
				}
			

				int row=i;
				screwItem->setPosition(ccp(0,-row*26+26));
				screwItem->setAnchorPoint(ccp(0,0));
				screwItem->setDelegate(_screwLayer1);
				_screwLayer1->addChild(screwItem,10);

				if(!_screwLayer1->getItemArray()){
					_screwLayer1->setItemArray(CCArray::create());
				}
				_screwLayer1->getItemArray()->addObject(screwItem);
				screwItem->setTag(userID); 
				countRow++;
			}

			
		}
		_screwLayer1->totalRow=countRow;

		totalGroupNum=CCLabelTTF::create(CCString::createWithFormat("%d/%d",countRow,maxGroupNum)->getCString(),FONT_TYPE,10);
		totalGroupNum->setPosition(ccp(winSize.width/2+54,winSize.height/2+52));
		group_layer->addChild(totalGroupNum);

	}else{
		CCTips *tip=CCTips::create("GroupNotExist");
		this->addChild(tip,5000);
		GroupID=0;
		this->onIterfaceClose(NULL);
		this->onInputBoxClose(NULL);
		
	}

} 
void StartMenu::onQuitBtn(CCObject* sender){

	CCMenuItem* item=(CCMenuItem*) sender;


	input_layer=CCLayer::create();

	CCSprite* confirm_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
	confirm_bg->setPosition(ccp(winSize.width/2,winSize.height/2));
	CCSprite* quit_title;
	
	if(MemberID==item->getTag()){
		quit_title=CCSprite::createWithSpriteFrameName("dissovle_title.png");
		CCSprite* pw_tip=CCSprite::createWithSpriteFrameName("coin_tips2.png");
		pw_tip->setPosition(ccp(winSize.width/2,winSize.height/2));
		input_layer->addChild(pw_tip,700);
	}else{
		quit_title=CCSprite::createWithSpriteFrameName("quit_title.png");
		
	}
	quit_title->setPosition(ccp(winSize.width/2,winSize.height/2+30));
	input_layer->addChild(quit_title,650);



	
	
	CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("yes_btn1.png"),CCSprite::createWithSpriteFrameName("yes_btn2.png"),this,menu_selector(StartMenu::onQuitComfirm));
	yes_btn->setTag(item->getTag());
	CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(StartMenu::onInputBoxClose));

	CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
	confirm_menu->alignItemsHorizontallyWithPadding(24);
	confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-30));

	input_layer->addChild(confirm_bg,600);
	input_layer->addChild(confirm_menu,650);
	

	this->addChild(input_layer,700);

}
void StartMenu::onQuitComfirm(CCObject* sender){

	CCMenuItem* item=(CCMenuItem*) sender;

		
	isPosting=true;

	cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
	std::string code2=CCString::createWithFormat("%d",MemberID)->getCString();
	std::string code;
	if(MemberID==item->getTag()){
		KTools* tool=KTools::create();
		CCString* cl=tool->readFromSQLite();
		std::string tempCost2="EFDDD";
		tool->decode(tempCost2);

		int tempCoin =cl->intValue()-atoi(tempCost2.c_str());
		if(tempCoin>=0){

			std::string code3=CCString::createWithFormat("%d",GroupID)->getCString();
			code="code=700&MemberID="+code2+"&GroupID="+code3+"&pw="+PWord;

		}else{
			CCTips *tip=CCTips::create("CoinError2");
			this->addChild(tip,5000);
			request->release();  
			return;
		}

		
	}else{
		code="code=600&MemberID="+code2+"&pw="+PWord;
	}
	


	std::string url=SERVER"nsk/group.php?"+code;
	request->setUrl(url.c_str());  
	request->setRequestType(CCHttpRequest::kHttpGet);  
	request->setResponseCallback(this, callfuncND_selector(StartMenu::onQuitGroupRequestCompleted));  
	request->setTag("Post_My_Data");  
	cocos2d::extension::CCHttpClient::getInstance()->send(request);  
	request->release();  
}


void StartMenu::onQuitGroupRequestCompleted(CCNode *sender ,void *data) {  
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


	Document doc;
	std::string buf(buffer->begin(),buffer->end()); 
	const char* result=(char*) buf.c_str();
	
	doc.Parse<kParseDefaultFlags>(result);
	Value &arr=doc;
	int countRow=0;

	if(arr.IsArray()){
	
		CCTips *tip=CCTips::create("KickSuccessed");
		this->addChild(tip,5000);

		this->onInputBoxClose(NULL);
		_screwLayer1->removeAllChildren();
		_screwLayer1->getItemArray()->removeAllObjects();
		_screwLayer1->setItemArray(NULL);
		_screwLayer1->setPositionY(_screwLayer1->minY);

		for (SizeType i = 0; i < arr.Size(); i++)  {

			CCScrewItem* screwItem=CCScrewItem::create();

			Value & node=arr[i];


			Value & idValue= node["id"];
			std::string idString=idValue.GetString();
			int userID=atoi(idString.c_str());



			Value & nameValue= node["name"];
			std::string nameString=nameValue.GetString();

			Value & battleValue= node["battle_point"];
			std::string battleString=battleValue.GetString();
			int battlePoint=atof(battleString.c_str())*100;

			Value & pointValue= node["point"];
			std::string pointString=pointValue.GetString();
			int point=atoi(pointString.c_str());

			if(leaderID==MemberID){
				CCLabelTTF* user_name=CCLabelTTF::create(nameString.c_str(),FONT_TYPE,12);
				CCMenuItemLabel* item=CCMenuItemLabel::create(user_name, this, menu_selector(StartMenu::onSelectGroupBtn));
				item->setTag(userID); 
				CCMenu* pMenu = CCMenu::create(item, NULL);
				pMenu ->setPosition(ccp(61,5));
				item ->setAnchorPoint(ccp(0.5f,0));
				screwItem->addChild(pMenu);

			}else{
				CCLabelTTF* user_name=CCLabelTTF::create(nameString.c_str(),FONT_TYPE,12);

				user_name ->setPosition(ccp(61,5));
				user_name ->setAnchorPoint(ccp(0.5f,0));
				screwItem->addChild(user_name);
			}




			CCLabelTTF* user_point=CCLabelTTF::create(CCString::createWithFormat("%d", point)->getCString(),FONT_TYPE,10);	
			user_point->setPosition(ccp(134,5));
			user_point->setAnchorPoint(ccp(0.5f,0));
			screwItem->addChild(user_point);



			CCLabelTTF* battle_point=CCLabelTTF::create(CCString::createWithFormat("%d", battlePoint)->getCString(),FONT_TYPE,10);	
			battle_point->setPosition(ccp(184,5));
			battle_point->setAnchorPoint(ccp(0.5f,0));
			screwItem->addChild(battle_point);

			if(leaderID==MemberID  && MemberID!=userID){
				CCMenuItem* kick_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("kick_btn.png"),CCSprite::createWithSpriteFrameName("kick_btn2.png"),NULL,this,menu_selector(StartMenu::onKickBtn));

				kick_btn->setTag(userID);
				screwItem->linemenu=CCMenu::create(kick_btn,NULL);
				screwItem->linemenu->setPosition(ccp(230,12));
				screwItem->linemenu->setAnchorPoint(ccp(0.5f,0));
				screwItem->addChild(screwItem->linemenu);
				screwItem->linemenu->setVisible(false);
			}


			int row=i;
			screwItem->setPosition(ccp(0,-row*26));
			screwItem->setAnchorPoint(ccp(0,0));
			screwItem->setDelegate(_screwLayer1);
			_screwLayer1->addChild(screwItem,10);

			if(!_screwLayer1->getItemArray()){
				_screwLayer1->setItemArray(CCArray::create());
			}
			_screwLayer1->getItemArray()->addObject(screwItem);
			screwItem->setTag(userID); 
			countRow++;
		}
			

			_screwLayer1->totalRow=countRow;

			if(totalGroupNum){
				totalGroupNum->setString(CCString::createWithFormat("%d/%d",countRow,maxGroupNum)->getCString());

			}

		}else{
			if(strcmp(result,"QuitSuccessed")==0){
				CCTips *tip=CCTips::create("QuitSuccessed");
				this->addChild(tip,5000);

				this->onIterfaceClose(NULL);
				this->onInputBoxClose(NULL);
				GroupID=0;

			}else if (strcmp(result,"DissovleSuccessed")==0){
				CCTips *tip=CCTips::create("DissovleSuccessed");
				this->addChild(tip,5000);

				KTools* tool=KTools::create();
				CCString* cl=tool->readFromSQLite();
				std::string tempCost2="EFDDD";
				tool->decode(tempCost2);
				unsigned int tempCoin =cl->intValue()-atoi(tempCost2.c_str());	

				CCString* coin= CCString::createWithFormat("%d",tempCoin);
				tool->saveToSQLite("GameRecord","coin",coin->getCString(),true);


				this->onIterfaceClose(NULL);
				this->onInputBoxClose(NULL);
				GroupID=0;

				

			}else if (strcmp(result,"KickFailed")==0){
				CCTips *tip=CCTips::create("KickFailed");
				this->addChild(tip,5000);

			}else{
				CCTips *tip=CCTips::create("ManagementFailed");

				this->addChild(tip,5000);
			}
	}
	

}

void StartMenu::onNoticeBtn(CCObject* sender){
	if(leaderID==MemberID){

		if(!input_layer){
			input_layer=CCLayer::create();

			CCSprite* pw_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
			pw_bg->setPosition(ccp(winSize.width/2,winSize.height/2));


			

			gpwInput=NULL;
			CCScale9Sprite * bg01=CCScale9Sprite::createWithSpriteFrameName("input_bg.png");
			gpwInput =CCEditBox::create(CCSizeMake(115, 25), bg01);
			gpwInput->setFontColor(ccc3(255,255,255));
			gpwInput->setPosition(ccp(winSize.width/2,winSize.height/2+25));
			gpwInput->setInputMode(kEditBoxInputModeAny);
			gpwInput->setReturnType(kKeyboardReturnTypeDefault);
			input_layer->addChild(gpwInput,200);

			/*CCSprite* pw_tip=CCSprite::createWithSpriteFrameName("gpw_tip.png");
			pw_tip->setPosition(ccp(winSize.width/2,winSize.height/2));
			input_layer->addChild(pw_tip,200);*/

			CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("yes_btn1.png"),CCSprite::createWithSpriteFrameName("yes_btn2.png"),this,menu_selector(StartMenu::onNoticeComfirm));
			CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(StartMenu::onInputBoxClose));

			CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
			confirm_menu->alignItemsHorizontallyWithPadding(16);
			confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-35));
			input_layer->addChild(confirm_menu,500);

			input_layer->addChild(pw_bg,100);
			this->addChild(input_layer,500);
		}

	}
	
}
void StartMenu::onNoticeComfirm(CCObject* sender){

	std::string data1=gpwInput->getText();
	if(strcmp(data1.c_str(),"")==0){
		CCTips *tip=CCTips::create("InputEmpty");
		this->addChild(tip,5000);
		return;
	}

	isPosting=true;
	//刷新按钮
	if(!refreshBtn){
		refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
		refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
		CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
		refreshBtn->runAction(CCRepeatForever::create(rt));
		this->addChild(refreshBtn,1000);

	}

	cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
	std::string code2=CCString::createWithFormat("%d",MemberID)->getCString();
	std::string code3=CCString::createWithFormat("%d",GroupID)->getCString();

	std::string code="code=1000&MemberID="+code2+"&GroupID="+code3+"&Notice="+data1+"&pw="+PWord;	
	std::string url=SERVER"nsk/group.php?"+code;
	request->setUrl(url.c_str());  
	request->setRequestType(CCHttpRequest::kHttpGet);  
	request->setResponseCallback(this, callfuncND_selector(StartMenu::onNoticeRequestCompleted));  
	request->setTag("Post_My_Data");  
	cocos2d::extension::CCHttpClient::getInstance()->send(request);  
	request->release();  
}

void StartMenu::onLockBtn(CCObject* sender){

	
	if(MemberID==leaderID){
		if(isLock){
			isPosting=true;
			//刷新按钮
			if(!refreshBtn){
				refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
				refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
				CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
				refreshBtn->runAction(CCRepeatForever::create(rt));
				this->addChild(refreshBtn,1000);

			}

			cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
			std::string code2=CCString::createWithFormat("%d",MemberID)->getCString();
			std::string code3=CCString::createWithFormat("%d",GroupID)->getCString();
			std::string code="code=900&MemberID="+code2+"&GroupID="+code3+"&pw="+PWord ;	
			std::string url=SERVER"nsk/group.php?"+code;
			request->setUrl(url.c_str());  
			request->setRequestType(CCHttpRequest::kHttpGet);  
			request->setResponseCallback(this, callfuncND_selector(StartMenu::onGPWRequestCompleted));  
			request->setTag("Post_My_Data");  
			cocos2d::extension::CCHttpClient::getInstance()->send(request);  
			request->release();  


		}else{

			if(!input_layer){
				input_layer=CCLayer::create();

				CCSprite* pw_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
				pw_bg->setPosition(ccp(winSize.width/2,winSize.height/2));


				CCSprite* gpwInputTitle=CCSprite::createWithSpriteFrameName("pwInput_title.png");
				gpwInputTitle->setPosition(ccp(winSize.width/2-62,winSize.height/2+25));
				input_layer->addChild(gpwInputTitle,200);
				
				gpwInput=NULL;
				CCScale9Sprite * bg01=CCScale9Sprite::createWithSpriteFrameName("input_bg.png");
				gpwInput =CCEditBox::create(CCSizeMake(115, 25), bg01);
				gpwInput->setFontColor(ccc3(255,255,255));
				gpwInput->setPosition(ccp(winSize.width/2+16,winSize.height/2+25));
				gpwInput->setInputMode(kEditBoxInputModeNumeric);
				gpwInput->setReturnType(kKeyboardReturnTypeDefault);
				input_layer->addChild(gpwInput,200);

				CCSprite* pw_tip=CCSprite::createWithSpriteFrameName("gpw_tip.png");
				pw_tip->setPosition(ccp(winSize.width/2,winSize.height/2));
				input_layer->addChild(pw_tip,200);

				CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("yes_btn1.png"),CCSprite::createWithSpriteFrameName("yes_btn2.png"),this,menu_selector(StartMenu::onGPWComfirm));
				CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(StartMenu::onInputBoxClose));

				CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
				confirm_menu->alignItemsHorizontallyWithPadding(16);
				confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-35));
				input_layer->addChild(confirm_menu,500);

				input_layer->addChild(pw_bg,100);
				this->addChild(input_layer,500);
			}
		}
		
	}
}
void StartMenu::onGPWComfirm(CCObject* sender){

	std::string data1=gpwInput->getText();
	if(strcmp(data1.c_str(),"")==0){
		CCTips *tip=CCTips::create("InputEmpty");
		this->addChild(tip,5000);
		return;

	}

	isPosting=true;
	//刷新按钮
	if(!refreshBtn){
		refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
		refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
		CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
		refreshBtn->runAction(CCRepeatForever::create(rt));
		this->addChild(refreshBtn,1000);

	}

	cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
	std::string code2=CCString::createWithFormat("%d",MemberID)->getCString();
	std::string code3=CCString::createWithFormat("%d",GroupID)->getCString();
	std::string code4=CCString::createWithFormat("%s", data1.c_str())->getCString();

	

	std::string code="code=900&MemberID="+code2+"&GroupID="+code3+"&gpw="+code4+"&pw="+PWord;	
	std::string url=SERVER"nsk/group.php?"+code;
	request->setUrl(url.c_str());  
	request->setRequestType(CCHttpRequest::kHttpGet);  
	request->setResponseCallback(this, callfuncND_selector(StartMenu::onGPWRequestCompleted));  
	request->setTag("Post_My_Data");  
	cocos2d::extension::CCHttpClient::getInstance()->send(request);  
	request->release();  
}


void StartMenu::onGPWRequestCompleted(CCNode *sender ,void *data) {  




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


	Document doc;
	std::string buf(buffer->begin(),buffer->end()); 
	const char* result=(char*) buf.c_str();

	if(strcmp(result,"EmptyGPW")==0){
		CCTips *tip=CCTips::create("EmptyGPW");
		this->addChild(tip,5000);
		lock_btn->unselected();
		isLock=false;
	}else if (strcmp(result,"UpdateGPW")==0){
		lock_btn->selected();
		isLock=true;
		this->onInputBoxClose(NULL);
		CCTips *tip=CCTips::create("UpdateGPW");
		this->addChild(tip,5000);
	}else{
		if(isLock){
			if(lock_btn){
				lock_btn->selected();
			}
		}else{
			if(lock_btn){
				lock_btn->unselected();
			}
		}
		CCTips *tip=CCTips::create("ManagementFailed");
		this->addChild(tip,5000);
	}

}

void StartMenu::onKickBtn(CCObject* sender){

	CCMenuItem* item=(CCMenuItem*) sender;

	if(!input_layer){

		input_layer=CCLayer::create();

		CCSprite* confirm_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
		confirm_bg->setPosition(ccp(winSize.width/2,winSize.height/2));
		CCSprite* quit_title=CCSprite::createWithSpriteFrameName("kick_title.png");
		quit_title->setPosition(ccp(winSize.width/2,winSize.height/2+30));
		input_layer->addChild(quit_title,650);

		CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("yes_btn1.png"),CCSprite::createWithSpriteFrameName("yes_btn2.png"),this,menu_selector(StartMenu::onKickComfirm));
		yes_btn->setTag(item->getTag());
		CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(StartMenu::onInputBoxClose));

		CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
		confirm_menu->alignItemsHorizontallyWithPadding(24);
		confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-30));

		input_layer->addChild(confirm_bg,600);
		input_layer->addChild(confirm_menu,650);


		this->addChild(input_layer,700);

	}
	
	
	

}

void StartMenu::onKickComfirm(CCObject* sender){

	CCMenuItem* item=(CCMenuItem*) sender;

	isPosting=true;
	//刷新按钮
	if(!refreshBtn){
		refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
		refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
		CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
		refreshBtn->runAction(CCRepeatForever::create(rt));
		this->addChild(refreshBtn,1000);

	}

	cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
	std::string code2=CCString::createWithFormat("%d",MemberID)->getCString();
	std::string code3=CCString::createWithFormat("%d",GroupID)->getCString();
	std::string code4=CCString::createWithFormat("%d",item->getTag())->getCString();
	std::string code="code=800&MemberID="+code2+"&GroupID="+code3+"&KickID="+code4+"&pw="+PWord;	
	std::string url=SERVER"nsk/group.php?"+code;
	request->setUrl(url.c_str());  
	request->setRequestType(CCHttpRequest::kHttpGet);  
	request->setResponseCallback(this, callfuncND_selector(StartMenu::onQuitGroupRequestCompleted));  
	request->setTag("Post_My_Data");  
	cocos2d::extension::CCHttpClient::getInstance()->send(request);  
	request->release();  
};

void StartMenu::onGroupRequestCompleted(CCNode *sender ,void *data){  

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


	


	Document doc;
	std::string buf(buffer->begin(),buffer->end()); 
	const char* json=(char*) buf.c_str();
	doc.Parse<kParseDefaultFlags>(json);
	Value &arr=doc;
	int countRow=0;
	if(arr.IsArray()){

		
		for (SizeType i = 0; i < arr.Size(); i++)  {
			CCScrewItem* screwItem=CCScrewItem::create();
		
			Value & node=arr[i];


			Value & idValue= node["group_id"];
			std::string idString=idValue.GetString();
			int groupID=atoi(idString.c_str());

			//解析name
			Value & nameValue= node["group_name"];
			std::string nameString=nameValue.GetString();


			Value & currentValue= node["currentNum"];
			std::string currentString=currentValue.GetString();
			int currentNum=atoi(currentString.c_str());


			

			Value & maxValue= node["maxNum"];
			
			int maxNum=maxValue.GetInt();

			
			Value & pwValue= node["pw"];
			std::string pwString=pwValue.GetString();
			

			CCLabelTTF* group_name=CCLabelTTF::create(nameString.c_str(),FONT_TYPE,12);
			CCMenuItemLabel* item=CCMenuItemLabel::create(group_name, this, menu_selector(StartMenu::onSelectGroupBtn));
			item->setTag(groupID); 
			CCMenu* pMenu = CCMenu::create(item, NULL);
			pMenu ->setPosition(ccp(78,5));
			item ->setAnchorPoint(ccp(0.5f,0));
			screwItem->addChild(pMenu);
		


			CCLabelTTF* group_id=CCLabelTTF::create(CCString::createWithFormat("%d", groupID)->getCString(),FONT_TYPE,10);	
			group_id->setPosition(ccp(160,5));
			group_id->setAnchorPoint(ccp(0.5f,0));
			screwItem->addChild(group_id);

			

			CCLabelTTF* memberNum=CCLabelTTF::create(CCString::createWithFormat("%d/%d", currentNum,maxNum)->getCString(),FONT_TYPE,10);
			memberNum->setPosition(ccp(218,5));
			memberNum->setAnchorPoint(ccp(0.5f,0));
			screwItem->addChild(memberNum);

			if(strcmp(pwString.c_str(),"")!=0){
				screwItem->lockItem=CCSprite::createWithSpriteFrameName("lock_icon.png");
				screwItem->lockItem->setPosition(ccp(234,7));
				screwItem->lockItem->setAnchorPoint(ccp(0.5f,0));
				screwItem->addChild(screwItem->lockItem);
			}

			CCMenuItem* join_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("join_btn.png"),CCSprite::createWithSpriteFrameName("join_btn2.png"),NULL,this,menu_selector(StartMenu::onJoinGroup));
			join_btn->setTag(groupID);
			screwItem->linemenu =CCMenu::create(join_btn,NULL);
			screwItem->linemenu->setPosition(ccp(274,14));
			screwItem->linemenu->setAnchorPoint(ccp(0.5f,0));
			screwItem->addChild(screwItem->linemenu);
			screwItem->linemenu->setVisible(false);

			int row=i;
			screwItem->setPosition(ccp(0,-row*26+26));
			screwItem->setAnchorPoint(ccp(0,0));
			screwItem->setDelegate(_screwLayer1);
			_screwLayer1->addChild(screwItem,10);

			if(!_screwLayer1->getItemArray()){
				_screwLayer1->setItemArray(CCArray::create());
			}
			_screwLayer1->getItemArray()->addObject(screwItem);
			screwItem->setTag(groupID); 
			countRow++;
		}
		_screwLayer1->totalRow=countRow;

	}

}  



void StartMenu::onJoinGroup(CCObject* sender){
	CCMenuItem* item=(CCMenuItem*) sender;

	CCObject* pObject;
	CCARRAY_FOREACH(_screwLayer1->getItemArray(),pObject){
		CCScrewItem* screwItem=(CCScrewItem*) pObject;
		if(screwItem->getTag()==item->getTag()){
			if(screwItem->lockItem){
				
				if(!input_layer){
					input_layer=CCLayer::create();

					CCSprite* pw_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
					pw_bg->setPosition(ccp(winSize.width/2,winSize.height/2));


					CCSprite* gpwInputTitle=CCSprite::createWithSpriteFrameName("pwInput_title.png");
					gpwInputTitle->setPosition(ccp(winSize.width/2-62,winSize.height/2+25));
					input_layer->addChild(gpwInputTitle,200);

					CCScale9Sprite * bg01=CCScale9Sprite::createWithSpriteFrameName("input_bg.png");
					gpwInput =CCEditBox::create(CCSizeMake(115, 25), bg01);
					gpwInput->setFontColor(ccc3(255,255,255));
					gpwInput->setPosition(ccp(winSize.width/2+16,winSize.height/2+25));
					gpwInput->setInputMode(kEditBoxInputModeNumeric);
					gpwInput->setReturnType(kKeyboardReturnTypeDefault);
					input_layer->addChild(gpwInput,200);

					CCSprite* pw_tip=CCSprite::createWithSpriteFrameName("gpw_tip.png");
					pw_tip->setPosition(ccp(winSize.width/2,winSize.height/2));
					input_layer->addChild(pw_tip,200);

					CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("yes_btn1.png"),CCSprite::createWithSpriteFrameName("yes_btn2.png"),this,menu_selector(StartMenu::onJoinComfirm));
					yes_btn->setTag(item->getTag());
					CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(StartMenu::onInputBoxClose));

					CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
					confirm_menu->alignItemsHorizontallyWithPadding(16);
					confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-35));
					input_layer->addChild(confirm_menu,500);

					input_layer->addChild(pw_bg,100);
					this->addChild(input_layer,500);
				}

			}else{

				isPosting=true;
				
				cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
				std::string code3=CCString::createWithFormat("%d",MemberID)->getCString();
				std::string code4=CCString::createWithFormat("%d",item->getTag())->getCString();
				std::string code="code=300&MemberID="+code3+"&gpw="+"&GroupID="+code4+"&pw="+PWord;
				std::string url=SERVER"nsk/group.php?"+code;
				request->setUrl(url.c_str());  
				request->setRequestType(CCHttpRequest::kHttpGet);  
				request->setResponseCallback(this, callfuncND_selector(StartMenu::onJoinRequestCompleted));  
				request->setTag("Post_My_Data");  
				cocos2d::extension::CCHttpClient::getInstance()->send(request);  
				request->release();  

				//刷新按钮
				if(!refreshBtn){
					refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
					refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
					CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
					refreshBtn->runAction(CCRepeatForever::create(rt));
					this->addChild(refreshBtn,1000);

				}
			}


		}
	}

}
void StartMenu::onJoinComfirm(CCObject* sender){
	CCMenuItemLabel* item=(CCMenuItemLabel*) sender;
	

	std::string data1=gpwInput->getText();
	if(strcmp(data1.c_str(),"")==0){
		CCTips *tip=CCTips::create("InputEmpty");
		this->addChild(tip,5000);
		return;

	}
	isPosting=true;

	cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
	std::string code2=CCString::createWithFormat("%s",data1.c_str())->getCString();
	std::string code3=CCString::createWithFormat("%d",MemberID)->getCString();
	std::string code4=CCString::createWithFormat("%d",item->getTag())->getCString();
	std::string code="code=300&gpw="+code2+"&MemberID="+code3+"&GroupID="+code4+"&pw="+PWord;
	std::string url=SERVER"nsk/group.php?"+code;
	request->setUrl(url.c_str());  
	request->setRequestType(CCHttpRequest::kHttpGet);  
	request->setResponseCallback(this, callfuncND_selector(StartMenu::onJoinRequestCompleted));  
	request->setTag("Post_My_Data");  
	cocos2d::extension::CCHttpClient::getInstance()->send(request);  
	request->release();  

	//刷新按钮
	if(!refreshBtn){
		refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
		refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
		CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
		refreshBtn->runAction(CCRepeatForever::create(rt));
		this->addChild(refreshBtn,1000);

	}

}


void StartMenu::onJoinRequestCompleted(CCNode *sender ,void *data) {  
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


	Document doc;
	std::string buf(buffer->begin(),buffer->end()); 
	const char* result=(char*) buf.c_str();

	if(strcmp(result,"GroupFull")==0){
		CCTips *tip=CCTips::create("GroupFull");
		this->addChild(tip,5000);

	}else if (strcmp(result,"GPWError")==0){
		CCTips *tip=CCTips::create("GPWError");
		this->addChild(tip,5000);
	}else{

		GroupID=atoi(result);
		CCTips *tip=CCTips::create("GroupAccess");
		this->addChild(tip,5000);

		this->onIterfaceClose(NULL);
		this->onInputBoxClose(NULL);
	}

}


void StartMenu::onSearchBtn(CCObject* sender){
	if(!isPosting){
		isPosting=true;
		std::string data1=searchInput->getText();

		cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
		std::string code2=CCString::createWithFormat("%s",data1.c_str())->getCString();
		std::string code="code=200&GroupID="+code2;
		std::string url=SERVER"nsk/group.php?"+code;
		request->setUrl(url.c_str());  
		request->setRequestType(CCHttpRequest::kHttpGet);  
		request->setResponseCallback(this, callfuncND_selector(StartMenu::onSeachRequestCompleted));  
		request->setTag("Post_My_Data");  
		cocos2d::extension::CCHttpClient::getInstance()->send(request);  
		request->release();

		
		if(!refreshBtn){
			refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
			refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
			CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
			refreshBtn->runAction(CCRepeatForever::create(rt));
			this->addChild(refreshBtn,1000);

		}

	}
}



void StartMenu::onSeachRequestCompleted(CCNode *sender ,void *data) {  

	isPosting=false;
	//刷新按钮
	if(refreshBtn){
		refreshBtn->stopAllActions();
		refreshBtn->removeFromParent();
		refreshBtn=NULL;
	}

	searchInput->setText("");

	_screwLayer1->removeAllChildren();
	_screwLayer1->setPositionY(_screwLayer1->minY);
	_screwLayer1->setItemArray(NULL);

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


	Document doc;
	std::string buf(buffer->begin(),buffer->end()); 
	const char* json=(char*) buf.c_str();
	doc.Parse<kParseDefaultFlags>(json);
	Value &arr=doc;
	int countRow=0;
	if(arr.IsArray()){
		for (SizeType i = 0; i < arr.Size(); i++)  {
			CCScrewItem* screwItem=CCScrewItem::create();

			Value & node=arr[i];


			Value & idValue= node["group_id"];
			std::string idString=idValue.GetString();
			int groupID=atoi(idString.c_str());

			
			Value & nameValue= node["group_name"];
			std::string nameString=nameValue.GetString();


			Value & currentValue= node["currentNum"];
			std::string currentString=currentValue.GetString();
			int currentNum=atoi(currentString.c_str());


			Value & maxValue= node["maxNum"];

			int maxNum=maxValue.GetInt();

			Value & pwValue= node["pw"];
			std::string pwString=pwValue.GetString();


			CCLabelTTF* group_name=CCLabelTTF::create(nameString.c_str(),FONT_TYPE,12);
			CCMenuItemLabel* item=CCMenuItemLabel::create(group_name, this, menu_selector(StartMenu::onSelectGroupBtn));
			item->setTag(groupID); 
			CCMenu* pMenu = CCMenu::create(item, NULL);
			pMenu ->setPosition(ccp(78,5));
			item ->setAnchorPoint(ccp(0.5f,0));
			screwItem->addChild(pMenu);



			CCLabelTTF* group_id=CCLabelTTF::create(CCString::createWithFormat("%d", groupID)->getCString(),FONT_TYPE,10);	
			group_id->setPosition(ccp(160,5));
			group_id->setAnchorPoint(ccp(0.5f,0));
			screwItem->addChild(group_id);



			CCLabelTTF* memberNum=CCLabelTTF::create(CCString::createWithFormat("%d/%d", currentNum,maxNum)->getCString(),FONT_TYPE,10);
			memberNum->setPosition(ccp(218,5));
			memberNum->setAnchorPoint(ccp(0.5f,0));
			screwItem->addChild(memberNum);

			if(strcmp(pwString.c_str(),"")!=0){
				screwItem->lockItem=CCSprite::createWithSpriteFrameName("lock_icon.png");
				screwItem->lockItem->setPosition(ccp(234,7));
				screwItem->lockItem->setAnchorPoint(ccp(0.5f,0));
				screwItem->addChild(screwItem->lockItem);
			}

			CCMenuItem* join_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("join_btn.png"),CCSprite::createWithSpriteFrameName("join_btn2.png"),NULL,this,menu_selector(StartMenu::onJoinGroup));
			join_btn->setTag(groupID);
			screwItem->linemenu =CCMenu::create(join_btn,NULL);
			screwItem->linemenu->setPosition(ccp(274,14));
			screwItem->linemenu->setAnchorPoint(ccp(0.5f,0));
			screwItem->addChild(screwItem->linemenu);
			screwItem->linemenu->setVisible(false);

			int row=i;
			screwItem->setPosition(ccp(0,-row*26+26));
			screwItem->setAnchorPoint(ccp(0,0));
			screwItem->setDelegate(_screwLayer1);
			_screwLayer1->addChild(screwItem,10);

			if(!_screwLayer1->getItemArray()){
				_screwLayer1->setItemArray(CCArray::create());
			}
			_screwLayer1->getItemArray()->addObject(screwItem);
			screwItem->setTag(groupID); 
			countRow++;
		}
		_screwLayer1->totalRow=countRow;

	}

}  



void  StartMenu::onCreateBtn(CCObject* sender){
	if(atoi(CValue.c_str())>=50*30+500){

		if(!input_layer){
			input_layer=CCLayer::create();

			CCSprite* create_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
			create_bg->setPosition(ccp(winSize.width/2,winSize.height/2));


			CCSprite* nameInputTitle=CCSprite::createWithSpriteFrameName("nameInput_title.png");
			nameInputTitle->setPosition(ccp(winSize.width/2-62,winSize.height/2+25));
			input_layer->addChild(nameInputTitle,200);

			CCScale9Sprite * bg01=CCScale9Sprite::createWithSpriteFrameName("input_bg.png");
			nameInput =CCEditBox::create(CCSizeMake(115, 25), bg01);
			nameInput->setFontColor(ccc3(255,255,255));
			nameInput->setPosition(ccp(winSize.width/2+16,winSize.height/2+25));
			nameInput->setInputMode(kEditBoxInputModeSingleLine);
			nameInput->setReturnType(kKeyboardReturnTypeDefault);
			input_layer->addChild(nameInput,200);

			CCSprite* create_tip=CCSprite::createWithSpriteFrameName("createGroup_tip.png");
			create_tip->setPosition(ccp(winSize.width/2,winSize.height/2));
			input_layer->addChild(create_tip,200);

			CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("yes_btn1.png"),CCSprite::createWithSpriteFrameName("yes_btn2.png"),this,menu_selector(StartMenu::onCreateComfirm));
			CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(StartMenu::onInputBoxClose));

			CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
			confirm_menu->alignItemsHorizontallyWithPadding(16);
			confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-35));
			input_layer->addChild(confirm_menu,500);

			input_layer->addChild(create_bg,100);
			this->addChild(input_layer,500);
		}


	}else{
		CCTips *tip=CCTips::create("CPError1");
		this->addChild(tip,5000);
		return;
	}
}

void StartMenu::onCreateComfirm(CCObject* sender){

	
	std::string data1=nameInput->getText();
	if(strcmp(data1.c_str(),"")==0){
		CCTips *tip=CCTips::create("InputEmpty");
		this->addChild(tip,5000);
		return;



	}


	for (size_t i=0;i<data1.size();++i)
	{
		if (data1[i] == ' ' )
		{
			CCTips *tip=CCTips::create("GroupNameError");
			this->addChild(tip,5000);
			return;
		}
	}


	KTools* tool=KTools::create();
	CCString* cl=tool->readFromSQLite();
	std::string tempCost2="EFDDD";
	tool->decode(tempCost2);

	int tempCoin =cl->intValue()-atoi(tempCost2.c_str());
	if(tempCoin>=0){

		isPosting=true;

		cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
		std::string code2=CCString::createWithFormat("%s",data1.c_str())->getCString();
		std::string code3=CCString::createWithFormat("%d",MemberID)->getCString();
		std::string code="code=400&MemberID="+code3+"&GroupName="+code2+"&pw="+PWord;;
		std::string url=SERVER"nsk/group.php?"+code;
		request->setUrl(url.c_str());  
		request->setRequestType(CCHttpRequest::kHttpGet);  
		request->setResponseCallback(this, callfuncND_selector(StartMenu::onCreateRequestCompleted));  
		request->setTag("Post_My_Data");  
		cocos2d::extension::CCHttpClient::getInstance()->send(request);  
		request->release();  

		if(!refreshBtn){
			refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
			refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
			CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
			refreshBtn->runAction(CCRepeatForever::create(rt));
			this->addChild(refreshBtn,1000);

		}

	}else{
		CCTips *tip=CCTips::create("CoinError2");
		this->addChild(tip,5000);
	}


	
}


void StartMenu::onCreateRequestCompleted(CCNode *sender ,void *data) {  
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


	Document doc;
	std::string buf(buffer->begin(),buffer->end()); 
	const char* result=(char*) buf.c_str();
	
	if(strcmp(result,"GroupDuplicate")==0){
		CCTips *tip=CCTips::create("GroupDuplicate");
		this->addChild(tip,5000);

	}else if (strcmp(result,"GroupNameLength")==0){
		CCTips *tip=CCTips::create("GroupNameLength");
		this->addChild(tip,5000);
	}else if (strcmp(result,"GroupNameError")==0){
		CCTips *tip=CCTips::create("GroupNameError");
		this->addChild(tip,5000);
	}else if (strcmp(result,"CPError1")==0){
		CCTips *tip=CCTips::create("CPError1");
		this->addChild(tip,5000);
	}else{
		GroupID=atoi(result);
		CCTips *tip=CCTips::create("GroupSuccessed");
		this->addChild(tip,5000);

		KTools* tool=KTools::create();
		CCString* cl=tool->readFromSQLite();
		std::string tempCost2="EFDDD";
		tool->decode(tempCost2);
		unsigned int tempCoin =cl->intValue()-atoi(tempCost2.c_str());	

		CCString* coin= CCString::createWithFormat("%d",tempCoin);
		tool->saveToSQLite("GameRecord","coin",coin->getCString(),true);


		this->onIterfaceClose(NULL);
		this->onInputBoxClose(NULL);
	}

}


void StartMenu::onSelectGroupBtn(CCObject* sender){

	CCMenuItemLabel* item=(CCMenuItemLabel*) sender;

	CCObject* pObject;
	CCARRAY_FOREACH(_screwLayer1->getItemArray(),pObject){
		CCScrewItem* screwItem=(CCScrewItem*) pObject;
		if(screwItem->getTag()==item->getTag()){
			if(screwItem->linemenu){
				screwItem->linemenu->setVisible(true);
			}
			

		}else{
			if(screwItem->linemenu){
				screwItem->linemenu->setVisible(false);
			}
			

		}
	}
}


void StartMenu::setProfile(){

	
	
	//档案按钮
	CCMenuItemSprite* profile_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("profile_btn.png"),NULL,NULL,this,menu_selector(StartMenu::onProfileBtn));
	CCMenu* menu3 =CCMenu::create(profile_btn,NULL);
	profile_btn->setAnchorPoint(ccp(1,0.5f));
	menu3->setPosition(winSize.width-20,winSize.height-50);
	this->addChild(menu3,5);
	

	

}




void  StartMenu::onProfileBtn(CCObject* sender){

	if(!group_layer && !profile_layer){
		isPosting=true;
		profile_layer=CCLayer::create();
		CCSprite* profile_bg=CCSprite::createWithSpriteFrameName("profile_bg.png");
		profile_bg->setPosition(ccp(winSize.width/2,winSize.height/2));

		profile_layer->addChild(profile_bg);

		//关闭
		CCMenuItemSprite* close_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("profile_closeBtn.png"),NULL,NULL,this,menu_selector(StartMenu::onIterfaceClose));
		CCMenu* menu =CCMenu::create( close_btn,NULL);
		menu->setPosition(ccp(profile_bg->getPositionX()+profile_bg->getContentSize().width/2-15,profile_bg->getPositionY()+profile_bg->getContentSize().height/2-12));
		profile_layer->addChild(menu);

		this->addChild(profile_layer,500);


		
		cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
		std::string code2=CCString::createWithFormat("%d",MemberID)->getCString();
		std::string code="code=20&id="+code2;
		std::string url=SERVER"nsk/rank.php?"+code+"&pw="+PWord;
		request->setUrl(url.c_str());  
		request->setRequestType(CCHttpRequest::kHttpGet);  
		request->setResponseCallback(this, callfuncND_selector(StartMenu::onProfileRequestCompleted));  
		request->setTag("Post_My_Data");  
		cocos2d::extension::CCHttpClient::getInstance()->send(request);  
		request->release();

		//刷新按钮
		if(!refreshBtn){
			refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
			refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
			CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
			refreshBtn->runAction(CCRepeatForever::create(rt));
			this->addChild(refreshBtn,1000);

		}
	}


}



void StartMenu::onProfileRequestCompleted(CCNode *sender ,void *data) {  
	
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


	Document doc;
	std::string buf(buffer->begin(),buffer->end()); 
	const char* json=(char*) buf.c_str();
	doc.Parse<kParseDefaultFlags>(json);
	Value &arr=doc;

	if(arr.IsArray()){
		for (SizeType i = 0; i < arr.Size(); i++)  {

			Value & node=arr[i];
					
			
			Value & nameValue= node["name"];
			std::string nameString=nameValue.GetString();

			Value & battleValue= node["battle_point"];
			std::string battleString=battleValue.GetString();
			int battlePoint=atof(battleString.c_str())*100;

			Value & pointValue= node["point"];
			std::string pointString=pointValue.GetString();
			int point=atoi(pointString.c_str());
			CValue=CCString::createWithFormat("%d",point)->getCString();


			Value & npValue= node["np_id"];
			std::string npString=npValue.GetString();

		 
			Value & groupnameValue= node["group_name"];
			if(!groupnameValue.IsNull()){
				std::string groupName=groupnameValue.GetString();
				CCLabelTTF* group_name=CCLabelTTF::create(groupName.c_str(),FONT_TYPE,12);
				group_name->setPosition(ccp(winSize.width/2+45,182));
				profile_layer->addChild(group_name);
			}
			

			CCLabelTTF* user_name=CCLabelTTF::create(nameString.c_str(),FONT_TYPE,12);
			user_name->setPosition(ccp(winSize.width/2+45,210));
			profile_layer->addChild(user_name);

			


			CCLabelTTF* user_battle=CCLabelTTF::create(CCString::createWithFormat("%d", battlePoint)->getCString(),FONT_TYPE,10);	
			user_battle->setPosition(ccp(winSize.width/2-35,150));
			//user_battle->enableStroke(ccc3(0,0,0),1);
			profile_layer->addChild(user_battle);
			
			CCLabelTTF* user_point=CCLabelTTF::create(CCString::createWithFormat("%d", point)->getCString(),FONT_TYPE,10);
			user_point->setPosition(ccp(winSize.width/2+72,150));
			//user_point->enableStroke(ccc3(0,0,0),1);
			profile_layer->addChild(user_point);
			const char* path;
	
			if(strcmp(npString.c_str(),"")==0){
				path="shinobiCard_null.png";
			}else{
				path=CCString::createWithFormat("%s.png",npString.c_str())->getCString();
			}
			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(path),NULL,NULL,this,menu_selector(StartMenu::onNamePlate));
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0.5f,0));
			menu->setPosition(ccp(winSize.width/2+16,100));
			profile_layer->addChild(menu);


		}
		

	}

}  

void  StartMenu::onNamePlate(CCObject* sender){
	if(atoi(CValue.c_str())<2*1200+600){
		CCTips *tip=CCTips::create("CPError2");
		this->addChild(tip,5000);
		return;
	}
	CCSprite* nameplate_bg=CCSprite::createWithSpriteFrameName("shinobiCard_bg.png");
	nameplate_bg->setAnchorPoint(ccp(0.5f,0));
	nameplate_bg->setPosition(ccp(winSize.width/2,92));
	profile_layer->addChild(nameplate_bg);

	CCClippingNode* clipper = CCClippingNode::create();
	CCNode *stencil = CCSprite::createWithSpriteFrameName("shinobiCard_mask.png");
	stencil->setAnchorPoint(ccp(0,0));
	clipper->setStencil(stencil);


	_screwLayer1=CCScrewLayer::create();
	_screwLayer1->setAnchorPoint(ccp(0,0));
	_screwLayer1->setPositionY(4);
	_screwLayer1->minY=4;
	_screwLayer1->line_height=30;

	clipper->setPosition(ccp(nameplate_bg->getPositionX()-nameplate_bg->getContentSize().width/2,92));
	clipper->addChild(_screwLayer1,5);

	
	profile_layer->addChild(clipper,20);
	int coutRow=0;
	int np100=15;
	int np200=17;
	int np300=14;
	int np400=11;
	int np500=5;
	int np600=2;
	int np700=1;
	int np800=2;
	int np900=1;
	int np1000=1;
	int row=1;

	if(atoi(CValue.c_str())>=48000){
		for(int i=0;i<np1000;i++){
			CCScrewItem* screwItem=CCScrewItem::create();

			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(CCString::createWithFormat("np10%02d.png",i)->getCString()),NULL,NULL,this,menu_selector(StartMenu::onNamePlateClick));
			np_btn->setTag(1000+i);
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0,0));
			menu->setPosition(ccp(48,8));
			screwItem->addChild(menu);


			screwItem->setPosition(ccp(0,-row*30+26));
			screwItem->setAnchorPoint(ccp(0,0));
			_screwLayer1->addChild(screwItem,10);
			row++;
		}
	}
	
	if(atoi(CValue.c_str())>=36000){
		for(int i=0;i<np900;i++){
			CCScrewItem* screwItem=CCScrewItem::create();

			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(CCString::createWithFormat("np9%02d.png",i)->getCString()),NULL,NULL,this,menu_selector(StartMenu::onNamePlateClick));
			np_btn->setTag(900+i);
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0,0));
			menu->setPosition(ccp(48,8));
			screwItem->addChild(menu);


			screwItem->setPosition(ccp(0,-row*30+26));
			screwItem->setAnchorPoint(ccp(0,0));
			_screwLayer1->addChild(screwItem,10);
			row++;
		}
	}
	if(atoi(CValue.c_str())>=30000){
		for(int i=0;i<np800;i++){
			CCScrewItem* screwItem=CCScrewItem::create();

			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(CCString::createWithFormat("np8%02d.png",i)->getCString()),NULL,NULL,this,menu_selector(StartMenu::onNamePlateClick));
			np_btn->setTag(800+i);
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0,0));
			menu->setPosition(ccp(48,8));
			screwItem->addChild(menu);


			screwItem->setPosition(ccp(0,-row*30+26));
			screwItem->setAnchorPoint(ccp(0,0));
			_screwLayer1->addChild(screwItem,10);
			row++;
		}
	}



	if(atoi(CValue.c_str())>=24000){
		for(int i=0;i<np700;i++){
			CCScrewItem* screwItem=CCScrewItem::create();

			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(CCString::createWithFormat("np7%02d.png",i)->getCString()),NULL,NULL,this,menu_selector(StartMenu::onNamePlateClick));
			np_btn->setTag(700+i);
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0,0));
			menu->setPosition(ccp(48,8));
			screwItem->addChild(menu);


			screwItem->setPosition(ccp(0,-row*30+26));
			screwItem->setAnchorPoint(ccp(0,0));
			_screwLayer1->addChild(screwItem,10);
			row++;
		}
	}
	if(atoi(CValue.c_str())>=20000){
		for(int i=0;i<np600;i++){
			CCScrewItem* screwItem=CCScrewItem::create();

			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(CCString::createWithFormat("np6%02d.png",i)->getCString()),NULL,NULL,this,menu_selector(StartMenu::onNamePlateClick));
			np_btn->setTag(600+i);
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0,0));
			menu->setPosition(ccp(48,8));
			screwItem->addChild(menu);


			screwItem->setPosition(ccp(0,-row*30+26));
			screwItem->setAnchorPoint(ccp(0,0));
			_screwLayer1->addChild(screwItem,10);
			row++;
		}
	}

	if(atoi(CValue.c_str())>=16000){
		for(int i=0;i<np500;i++){
			CCScrewItem* screwItem=CCScrewItem::create();
		
			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(CCString::createWithFormat("np5%02d.png",i)->getCString()),NULL,NULL,this,menu_selector(StartMenu::onNamePlateClick));
			np_btn->setTag(500+i);
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0,0));
			menu->setPosition(ccp(48,8));
			screwItem->addChild(menu);

			
			screwItem->setPosition(ccp(0,-row*30+26));
			screwItem->setAnchorPoint(ccp(0,0));
			_screwLayer1->addChild(screwItem,10);
			row++;
		}
	}
	if(atoi(CValue.c_str())>=12000){
		for(int i=0;i<np400;i++){
			CCScrewItem* screwItem=CCScrewItem::create();

			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(CCString::createWithFormat("np4%02d.png",i)->getCString()),NULL,NULL,this,menu_selector(StartMenu::onNamePlateClick));
			np_btn->setTag(400+i);
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0,0));
			menu->setPosition(ccp(48,8));
			screwItem->addChild(menu);


			screwItem->setPosition(ccp(0,-row*30+26));
			screwItem->setAnchorPoint(ccp(0,0));
			_screwLayer1->addChild(screwItem,10);
			row++;
		}
	}

	if(atoi(CValue.c_str())>=9000){
		for(int i=0;i<np300;i++){
			CCScrewItem* screwItem=CCScrewItem::create();

			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(CCString::createWithFormat("np3%02d.png",i)->getCString()),NULL,NULL,this,menu_selector(StartMenu::onNamePlateClick));
			np_btn->setTag(300+i);
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0,0));
			menu->setPosition(ccp(48,8));
			screwItem->addChild(menu);


			screwItem->setPosition(ccp(0,-row*30+26));
			screwItem->setAnchorPoint(ccp(0,0));
			_screwLayer1->addChild(screwItem,10);
			row++;
		}
	}

	if(atoi(CValue.c_str())>=6000){

		for(int i=0;i<np200;i++){
			CCScrewItem* screwItem=CCScrewItem::create();

			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(CCString::createWithFormat("np2%02d.png",i)->getCString()),NULL,NULL,this,menu_selector(StartMenu::onNamePlateClick));
			np_btn->setTag(200+i);
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0,0));
			menu->setPosition(ccp(48,8));
			screwItem->addChild(menu);


			screwItem->setPosition(ccp(0,-row*30+26));
			screwItem->setAnchorPoint(ccp(0,0));
			_screwLayer1->addChild(screwItem,10);
			row++;
		}
	}
	if(atoi(CValue.c_str())>=3000){
		for(int i=0;i<np100;i++){
			CCScrewItem* screwItem=CCScrewItem::create();

			CCMenuItem* np_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(CCString::createWithFormat("np1%02d.png",i)->getCString()),NULL,NULL,this,menu_selector(StartMenu::onNamePlateClick));
			np_btn->setTag(100+i);
			CCMenu* menu =CCMenu::create(np_btn,NULL);
			np_btn->setAnchorPoint(ccp(0,0));
			menu->setPosition(ccp(48,8));
			screwItem->addChild(menu);


			screwItem->setPosition(ccp(0,-row*30+26));
			screwItem->setAnchorPoint(ccp(0,0));
			_screwLayer1->addChild(screwItem,10);
			row++;
		}
	}
	


	_screwLayer1->totalRow=row;

}

void  StartMenu::onNamePlateClick(CCObject* sender){
	CCMenuItem* item=(CCMenuItem*) sender;
		if(!input_layer){
			input_layer=CCLayer::create();

			CCSprite* pw_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
			pw_bg->setPosition(ccp(winSize.width/2,winSize.height/2));
			

			
			CCSprite* quit_title=CCSprite::createWithSpriteFrameName("nameplate_title.png");

			quit_title->setPosition(ccp(winSize.width/2,winSize.height/2+30));
			input_layer->addChild(quit_title,650);
			
			CCSprite* pw_tip=CCSprite::createWithSpriteFrameName("coin_tips2.png");
			pw_tip->setPosition(ccp(winSize.width/2,winSize.height/2));
			input_layer->addChild(pw_tip,200);

			CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("yes_btn1.png"),CCSprite::createWithSpriteFrameName("yes_btn2.png"),this,menu_selector(StartMenu::onNamePlateComfrim));
			yes_btn->setTag(item->getTag());
			CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(StartMenu::onInputBoxClose));

			CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
			confirm_menu->alignItemsHorizontallyWithPadding(16);
			confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-35));
			input_layer->addChild(confirm_menu,500);

			input_layer->addChild(pw_bg,100);
			this->addChild(input_layer,500);
		}
	
	
	
}

void  StartMenu::onNamePlateComfrim(CCObject* sender){

	CCMenuItem* item=(CCMenuItem*) sender;
	KTools* tool=KTools::create();
	CCString* cl=tool->readFromSQLite();
	std::string tempCost2="EFDDD";
	tool->decode(tempCost2);

	int tempCoin =cl->intValue()-atoi(tempCost2.c_str());
	if(tempCoin>=0){

	isPosting=true;
	cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
	std::string code2=CCString::createWithFormat("&np_id=np%d",item->getTag())->getCString();
	std::string code3=CCString::createWithFormat("id=%d",MemberID)->getCString();
	std::string code="code=50&"+code3+code2;
	std::string url=SERVER"nsk/rank.php?"+code+"&pw="+PWord;
	request->setUrl(url.c_str());  
	request->setRequestType(CCHttpRequest::kHttpGet);  
	request->setResponseCallback(this, callfuncND_selector(StartMenu::onNamePlateRequestCompleted));  
	request->setTag("Post_My_Data");  
	cocos2d::extension::CCHttpClient::getInstance()->send(request);  
	request->release();

	if(!refreshBtn){
		refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
		refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
		CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
		refreshBtn->runAction(CCRepeatForever::create(rt));
		this->addChild(refreshBtn,1000);

	}



	}else{
		CCTips *tip=CCTips::create("CoinError2");
		this->addChild(tip,5000);
	}
	

	
}



void StartMenu::onNamePlateRequestCompleted(CCNode *sender ,void *data) {  
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


	Document doc;
	std::string buf(buffer->begin(),buffer->end()); 
	const char* result=(char*) buf.c_str();

	if(strcmp(result,"UpdateNamePlate")==0){
		CCTips *tip=CCTips::create("ManagementSuccessed");
		this->addChild(tip,5000);

		KTools* tool=KTools::create();
		CCString* cl=tool->readFromSQLite();
		std::string tempCost2="EFDDD";
		tool->decode(tempCost2);
		unsigned int tempCoin =cl->intValue()-atoi(tempCost2.c_str());	

		CCString* coin= CCString::createWithFormat("%d",tempCoin);
		tool->saveToSQLite("GameRecord","coin",coin->getCString(),true);

		this->onIterfaceClose(NULL);
		this->onInputBoxClose(NULL);

	}else{
		CCTips *tip=CCTips::create("ManagementFailed");
		this->addChild(tip,5000);
	}

}



void  StartMenu::onTasksBtn(CCObject* sender){

#if CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID

	JniMethodInfo minfo;

	bool isHave = JniHelper::getStaticMethodInfo(minfo,"net/zakume/game/NarutoSenki","showOffWall", "()V"); 
	if (isHave) { 	
		minfo.env -> CallStaticVoidMethod(minfo.classID,minfo.methodID);
	} 

#endif  

}

void  StartMenu::onLoginBtn(CCObject* sender){
	
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Result.plist");	
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Record.plist");
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Record2.plist");		
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI.plist");
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Report.plist");
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ougis.plist");
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ougis2.plist");
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Map.plist");
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Gears.plist");
	//CCScene* pscene =CCScene::create();
	//RakingLayer* rakingLayer=RakingLayer::create();
	////rakingLayer->setDelegate(this);
	//pscene->addChild(rakingLayer);
	//CCDirector::sharedDirector()->pushScene(pscene);
	
	CCTips *tip=CCTips::create("ServerMainten");
	this->addChild(tip,5000);
	return;

	if(MemberID==NULL){
		if(!input_layer){
			input_layer=CCLayer::create();

			CCSprite* login_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
			login_bg->setPosition(ccp(winSize.width/2,winSize.height/2));


			CCSprite* userInputTitle=CCSprite::createWithSpriteFrameName("userInput_title.png");
			userInputTitle->setPosition(ccp(winSize.width/2-62,winSize.height/2+35));
			input_layer->addChild(userInputTitle,200);

			CCScale9Sprite * bg01=CCScale9Sprite::createWithSpriteFrameName("input_bg.png");
			usernameInput =CCEditBox::create(CCSizeMake(115, 25), bg01);
			usernameInput->setFontColor(ccc3(255,255,255));
			usernameInput->setPosition(ccp(winSize.width/2+16,winSize.height/2+35));
			usernameInput->setInputMode(kEditBoxInputModeSingleLine);
			usernameInput->setReturnType(kKeyboardReturnTypeDefault);
			input_layer->addChild(usernameInput,200);


			if(strcmp(CCUserDefault::sharedUserDefault()->getStringForKey("userName").c_str(),"")!=0){
				usernameInput->setText(CCUserDefault::sharedUserDefault()->getStringForKey("userName").c_str());
			}
			CCSprite* pwInputTitle=CCSprite::createWithSpriteFrameName("pwInput_title.png");
			pwInputTitle->setPosition(ccp(winSize.width/2-60,winSize.height/2));
			input_layer->addChild(pwInputTitle,200);
			CCScale9Sprite * bg02=CCScale9Sprite::createWithSpriteFrameName("input_bg.png");
			pwInput =CCEditBox::create(CCSizeMake(115, 25), bg02);		
			pwInput->setFontColor(ccc3(255,255,255));
			pwInput->setPosition(ccp(winSize.width/2+16,winSize.height/2));
			pwInput->setInputMode(kEditBoxInputModeSingleLine);
			pwInput->setInputFlag(kEditBoxInputFlagPassword);
			pwInput->setReturnType(kKeyboardReturnTypeDefault);
			input_layer->addChild(pwInput,200);


			if(strcmp(CCUserDefault::sharedUserDefault()->getStringForKey("password").c_str(),"")!=0){
				pwInput->setText(CCUserDefault::sharedUserDefault()->getStringForKey("password").c_str());
			}

			CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("login_btn2.png"),CCSprite::createWithSpriteFrameName("login_btn1.png"),this,menu_selector(StartMenu::onLoginOn));
			CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(StartMenu::onInputBoxClose));

			CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
			confirm_menu->alignItemsHorizontallyWithPadding(16);
			confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-35));
			input_layer->addChild(confirm_menu,500);

			input_layer->addChild(login_bg,100);
			this->addChild( input_layer,500);
		}
		

	}else{
		CCTips *tip=CCTips::create("LoginDuplicate");
		this->addChild(tip,5000);


	}
	



	
}

void  StartMenu::onLoginOn(CCObject* sender){
	
	if(!isPosting){
		isPosting=true;
		std::string data1=usernameInput->getText();
		CCUserDefault::sharedUserDefault()->setStringForKey("userName",data1);

		std::string data2 =pwInput->getText();
		std::string result;

		if(strcmp(CCUserDefault::sharedUserDefault()->getStringForKey("password").c_str(),data2.c_str())!=0){
			KTools *tool=new KTools();
			result=tool->encodeData(data2);
		}else{
			result=data2;
		}
		PWord=result;

		CCUserDefault::sharedUserDefault()->setStringForKey("password",result);

		cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  

	
		std::string Andriodstr="";

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)  
		JniMethodInfo minfo;
		bool isHave = JniHelper::getStaticMethodInfo(minfo,"net/zakume/game/NarutoSenki","getMacAdress", "()Ljava/lang/String;");  

		if (isHave)   
		{  
			jstring jstr=(jstring) minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID); 
			Andriodstr = Andriodstr + JniHelper::jstring2string(jstr);

		}  
#endif		
		std::string Imeistr="";

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)  
		JniMethodInfo minfo2;
		bool isHave2 = JniHelper::getStaticMethodInfo(minfo2,"net/zakume/game/NarutoSenki","getImei", "()Ljava/lang/String;");  

		if (isHave2)   
		{  
			jstring jstr2=(jstring) minfo2.env->CallStaticObjectMethod(minfo2.classID, minfo2.methodID); 
			Imeistr = Imeistr + JniHelper::jstring2string(jstr2);

		}  
#endif	
		std::string code2=CCString::createWithFormat("&version=%d",CURRENT_VERSION)->getCString();
		std::string code="name="+data1+"&pw="+result+"&androidID="+Andriodstr+"&Imei="+Imeistr;
		std::string url=SERVER"nsk/login.php?"+code+code2;
		request->setUrl(url.c_str());  
		request->setRequestType(CCHttpRequest::kHttpGet);  
		request->setResponseCallback(this, callfuncND_selector(StartMenu::onLoginRequestCompleted));  
		request->setTag("Post_My_Data");  
		cocos2d::extension::CCHttpClient::getInstance()->send(request);  
		request->release();  

		//刷新按钮
		if(!refreshBtn){
			refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
			refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
			CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
			refreshBtn->runAction(CCRepeatForever::create(rt));
			this->addChild(refreshBtn,1000);


		}
		

	}


}

void StartMenu::update(float dt){

	if(!noticeLabel){
		return;
	}

	float currentX = noticeLabel->getPositionX();
	//float contentX = getContentSize().width;
	float lableX = noticeLabel->getContentSize().width;


	if(noticeLabel->getPositionX()>=-lableX){
		noticeLabel->setPositionX(noticeLabel->getPositionX()-0.6f);
	}	
	else{
		noticeLabel->setPositionX(190);
	}



}

void StartMenu::setNotice(){

	if(!notice_layer){
		notice_layer=CCLayer::create();
		CCSprite* notice_bg=CCSprite::createWithSpriteFrameName("notice_bg.png");
		notice_bg->setAnchorPoint(ccp(0,0));
		notice_bg->setPosition(ccp(15,228));
		notice_layer->addChild(notice_bg);


		CCClippingNode* clipper = CCClippingNode::create();
		CCNode *stencil = CCSprite::createWithSpriteFrameName("notice_mask.png");
		stencil->setAnchorPoint(ccp(0,0));
		clipper->setStencil(stencil);

		noticeLabel=CCLabelTTF::create("",FONT_TYPE,12);
		noticeLabel->setAnchorPoint(ccp(0,0));
		clipper->addChild(noticeLabel);
		noticeLabel->retain();
		clipper->setPosition(ccp(35,228));

		notice_layer->addChild(clipper);

		this->addChild(notice_layer);
		CCDictionary *strings = CCDictionary::createWithContentsOfFile("Element/strings.xml");  
		const char *reply = ((CCString*)strings->objectForKey("Notice"))->m_sString.c_str(); 
		
		noticeLabel->setString(reply);
		/*cocos2d::extension::CCHttpRequest* request = new CCHttpRequest();  
		std::string code2=CCString::createWithFormat("?version=%d",CURRENT_VERSION)->getCString();
		std::string url=SERVER"nsk/notice.php"+code2;
		request->setUrl(url.c_str());  
		request->setRequestType(CCHttpRequest::kHttpGet);  
		request->setResponseCallback(this, callfuncND_selector(StartMenu::onNoticeRequestCompleted));  
		request->setTag("Post_My_Data");  
		cocos2d::extension::CCHttpClient::getInstance()->send(request);  
		request->release();  */
		
	}
	

}
void StartMenu::onNoticeRequestCompleted(CCNode *sender ,void *data) {  
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

	
	Document doc;
	//把vector转换成std::string 
	std::string buf(buffer->begin(),buffer->end()); 
	//CCLog("%s",buf.c_str()); 
	const char* json=(char*) buf.c_str();
	doc.Parse<kParseDefaultFlags>(json);
	Value &arr=doc;
	std::string noticeString;
	if(arr.IsArray()){
		for (SizeType i = 0; i < arr.Size(); i++)  {

			Value & node=arr[i];
			
				Value & noticeValue= node["notice"];
				noticeString+= noticeValue.GetString();


		}
		if(noticeLabel){		
			noticeLabel->setString(noticeString.c_str());
		}
		
	}else{
		isPosting=false;
		//刷新按钮
		if(refreshBtn){
			refreshBtn->stopAllActions();
			refreshBtn->removeFromParent();
			refreshBtn=NULL;
		}


		CCTips *tip=CCTips::create("UpdateNotice");
		this->addChild(tip,5000);
		if(notice_label){
			notice_label->setString(json);
		}
		this->onInputBoxClose(NULL);
		
		
	}

	

	
}
void StartMenu::onLoginRequestCompleted(CCNode *sender ,void *data) {  
	//AllocConsole();  
	//freopen("CONIN$", "r", stdin);  
	//freopen("CONOUT$", "w", stdout);  
	//freopen("CONOUT$", "w", stderr);
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


	Document doc;
	//把vector转换成std::string 
	std::string buf(buffer->begin(),buffer->end()); 
	//CCLog("%s",buf.c_str()); 
	const char* json=(char*) buf.c_str();
	doc.Parse<kParseDefaultFlags>(json);
	Value &arr=doc;

	int gameVersion;
	if(arr.IsArray()){
		for (SizeType i = 0; i < arr.Size(); i++)  {

			Value & node=arr[i];
			
			//解析id
			Value & idValue= node["id"];
			std::string idString=idValue.GetString();
			MemberID=atoi(idString.c_str());

			Value & ptValue= node["point"];
			std::string ptString=ptValue.GetString();
			CValue=CCString::createWithFormat("%d",atoi(ptString.c_str()))->getCString();

			Value & groupValue= node["group_id"];
			std::string groupString=groupValue.GetString();
			if(atoi(groupString.c_str())!=0){
					GroupID=atoi(groupString.c_str());	
			}
	

		}
		
		CCTips *tip=CCTips::create("LoginSuccess");
		this->addChild(tip,5000);
		this->onInputBoxClose(NULL);
		if(login_btn){
			login_btn->removeFromParent();
			login_btn=NULL;
		}

			
		this->setOfferWall();
		//设置公告
		this->setNotice();	
		this->setProfile();
		this->setGroup();
		this->scrollMenu(_pos03);
		
	
	}else{
		
		PWord="";
		CCTips *tip=CCTips::create(buf.c_str());
		this->addChild(tip,5000);
		
		
	}
	
	
	
}  


void  StartMenu::onIterfaceClose(CCObject* sender){
	if(!isPosting){
		if(profile_layer){
			profile_layer->removeAllChildren();
			profile_layer->removeFromParent();
			profile_layer=NULL;
		}

		if(group_layer){
			group_layer->removeAllChildren();
			group_layer->removeFromParent();
			group_layer=NULL;
		}

	}

}


void  StartMenu::onInputBoxClose(CCObject* sender){
	if(input_layer){
	input_layer->removeAllChildren();
	input_layer->removeFromParent();
	input_layer=NULL;

	}
	


}




void  StartMenu::onNewsBtn(CCObject* sender){

#if CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID

	JniMethodInfo minfo;

	bool isHave = JniHelper::getStaticMethodInfo(minfo,"net/zakume/game/NarutoSenki","getInstance","()Lnet/zakume/game/NarutoSenki;"); 
	jobject jobj;//存对象  
	if (isHave) {  
		//这里的调用getInstance，返回Test类的对象。  
		jobj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);  

		isHave = JniHelper::getMethodInfo(minfo,"net/zakume/game/NarutoSenki","openWebview","()V");  
		if (isHave) {  
			//调用openWebview, 参数1：Test对象   参数2：方法ID  
			minfo.env->CallVoidMethod(jobj, minfo.methodID);  
		}  
	}  

#endif  
}

void StartMenu::onHardCoreOn(CCObject* sender){
	CCUserDefault::sharedUserDefault()->setBoolForKey("isHardCore",true);
	if(hardCore_btn){
		CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("menu02_1.png"); 
		hardCore_btn->setDisplayFrame(frame);
	}

	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/confirm.ogg");
	if(hardCoreLayer){
		hardCoreLayer->removeAllChildren();
		hardCoreLayer->removeFromParent();
		hardCoreLayer=NULL;
	}
}

void StartMenu::onHardCoreOff(CCObject* sender){

	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/cancel.ogg");
	if(hardCoreLayer){
		hardCoreLayer->removeAllChildren();
		hardCoreLayer->removeFromParent();
		hardCoreLayer=NULL;
	}

}

void StartMenu::onHardLayerCallBack(){





	if( CCUserDefault::sharedUserDefault()->getBoolForKey("isHardCore")==false){
		if(!hardCoreLayer){
	
		hardCoreLayer=CCLayer::create();

		CCSprite* confirm_bg=CCSprite::createWithSpriteFrameName("confirm_bg.png");
		confirm_bg->setPosition(ccp(winSize.width/2,winSize.height/2));

		CCSprite* hardcore_title=CCSprite::createWithSpriteFrameName("hardcore_title.png");
		hardcore_title->setPosition(ccp(winSize.width/2,winSize.height/2+38));

		CCSprite* hardcore_text=CCSprite::createWithSpriteFrameName("hardcore_text.png");
		hardcore_text->setPosition(ccp(winSize.width/2,winSize.height/2+8));

		CCMenuItem* yes_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("yes_btn1.png"),CCSprite::createWithSpriteFrameName("yes_btn2.png"),this,menu_selector(StartMenu::onHardCoreOn));
		CCMenuItem* no_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("no_btn1.png"),CCSprite::createWithSpriteFrameName("no_btn2.png"),this,menu_selector(StartMenu::onHardCoreOff));

		CCMenu* confirm_menu = CCMenu::create(yes_btn,no_btn,NULL);
		confirm_menu->alignItemsHorizontallyWithPadding(24);
		confirm_menu->setPosition(ccp(winSize.width/2,winSize.height/2-30));

		hardCoreLayer->addChild(confirm_bg,600);
		hardCoreLayer->addChild(confirm_menu,650);
		hardCoreLayer->addChild(hardcore_title,650);
		hardCoreLayer->addChild(hardcore_text,650);
		this->addChild(hardCoreLayer,700);

		}
	}
	
}

void StartMenu::onHardCoreCallBack(){

	
	/*if(MemberID){

		

		//加载序列集
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Select.plist");	
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Report.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ougis.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ougis2.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Map.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Gears.plist");

	CCScene* selectScene=CCScene::create();
	NetworkLayer* selectLayer=NetworkLayer::create();
	KTools* tool= KTools::create();


	selectScene->addChild(selectLayer);
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5f,selectScene));
	}*/
	CCTips *tip=CCTips::create("ServerMainten");
	this->addChild(tip,5000);

}

void StartMenu::onNormalCallBack(CCObject* sender){

	//加载序列集
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Select.plist");	
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Report.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ougis.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ougis2.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Map.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Gears.plist");

	CCScene* selectScene=CCScene::create();
	NetworkLayer* selectLayer=NetworkLayer::create();
	KTools* tool= KTools::create();


	selectScene->addChild(selectLayer);
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5f,selectScene));


	/*CCScene* selectScene=CCScene::create();
	SelectLayer* selectLayer=SelectLayer::create();
	selectScene->addChild(selectLayer);
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5f,selectScene));	*/
}

void StartMenu::onTrainingCallBack(){

	if(input_layer || profile_layer || group_layer) {
		return;
	}


	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Select.plist");	


	int i=1;

	if(adResult!=1){
	Cheats=0;
	}
	
	if(Cheats>10){
		i=2;
	}

	if(i==0){
		this->onNormalCallBack(NULL);	
	}else if(i==1){
	
	//加载序列集
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Report.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ougis.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ougis2.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Map.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Gears.plist");


	CCDictionary* dic=CCDictionary::create();


	char* heroList[]={"Lee","Shino","Kakashi","Kakuzu",
		"Asuma"};

	srand((int)time(0));
	CCString* tmpChar=CCString::create("Tsunade");
	CCString* tmpRole=CCString::create("Player");
	CCString* tmpGroup=CCString::create("Konoha");

	dic->setObject(tmpChar,"character");
	dic->setObject(tmpRole,"role");
	dic->setObject(tmpGroup,"group");

	CCArray* tempHeros=CCArray::createWithObject(dic);
	
	CCArray* realHero=CCArray::create();
	int num= sizeof(heroList)/sizeof(char*);
	for(int i=0;i<num;i++){
		if(strcmp(tmpChar->getCString(),heroList[i])==0){
			continue;
		}
		CCString* hero=CCString::create(heroList[i]);
		realHero->addObject(hero);
	}

	//特殊组队
	/*char* heroList2[]={"Naruto","Deidara","Konan"};

	CCArray* enemyHero=CCArray::create();
	int num2= sizeof(heroList2)/sizeof(char*);
	for(int x=0;x<num2;x++){
	if(strcmp(tmpChar->getCString(),heroList2[x])==0){
	continue;
	}
	CCString* hero=CCString::create(heroList2[x]);
	enemyHero->addObject(hero);
	}*/
	//--------------

	for(int i=0;i<5;i++){

		if(i<2){
			int length=realHero->count();
			srand((int)time(0));
			int index=random(length);
			if(index==(int)realHero->count()){
				
				index=realHero->count()-1;
			}


			CCObject* tempObject=realHero->objectAtIndex(index);
			CCString* hero=(CCString*) tempObject;

			dic=CCDictionary::create();
			tmpChar=CCString::create(hero->getCString());
			tmpRole=CCString::create("Com");
			tmpGroup=CCString::create("Konoha");

			dic->setObject(tmpChar,"character");
			dic->setObject(tmpRole,"role");
			dic->setObject(tmpGroup,"group");

			tempHeros->addObject(dic);
			realHero->removeObjectAtIndex(index);


		}else{

			int length=realHero->count();
			srand((int)time(0));
			int index=random(length);
			if(index==(int)realHero->count()){
				index=realHero->count()-1;
			}

			CCObject* tempObject=realHero->objectAtIndex(index);
			CCString* hero=(CCString*) tempObject;

			dic=CCDictionary::create();
			tmpChar=CCString::create(hero->getCString());
			tmpRole=CCString::create("Com");
			tmpGroup=CCString::create("Akatsuki");

			dic->setObject(tmpChar,"character");
			dic->setObject(tmpRole,"role");
			dic->setObject(tmpGroup,"group");

			tempHeros->addObject(dic);
			realHero->removeObjectAtIndex(index);


			////特殊组队
			//int length=enemyHero->count();
			//srand((int)time(0));
			//int index=random(length);
			//if(index==(int)enemyHero->count()){
			//	index=enemyHero->count()-1;
			//}

			//CCObject* tempObject=enemyHero->objectAtIndex(index);
			//CCString* hero=(CCString*) tempObject;

			//dic=CCDictionary::create();
			//tmpChar=CCString::create(hero->getCString());
			//tmpRole=CCString::create("Com");
			//tmpGroup=CCString::create("Akatsuki");


			//dic->setObject(tmpChar,"character");
			//dic->setObject(tmpRole,"role");
			//dic->setObject(tmpGroup,"group");

			//tempHeros->addObject(dic);
			//enemyHero->removeObjectAtIndex(index);

			////---------

		} 

	}


	CCScene* loadScene=CCScene::create();
	LoadLayer* loadLayer=LoadLayer::create();
	loadLayer->tempHeros=tempHeros;
	loadLayer->_isHardCoreMode=true;
	loadScene->addChild(loadLayer);
	loadLayer->preloadAudio();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5f,loadScene));

	}else if(i==2){

	//4v4

	//加载序列集
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Report.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ougis.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ougis2.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Map.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Gears.plist");


	CCDictionary* dic=CCDictionary::create();

	
	char* heroList1[]={"Konan","Sakura","Naruto","Sai","Deidara",
		"Kakashi","Itachi","Tenten","Jiraiya","Suigetsu",
		"Tsunade","Tobirama","Neji","Ino","Asuma","Gaara",
		"Karin","Sasuke","Hidan","Choji","Kankuro",
		"Shino","Minato","Tobi","Kakuzu","Hinata",
		"Shikamaru","Chiyo","Kisame",
		"Hiruzen","Kiba","Jugo","Lee"
	};

	srand((int)time(0));
	int index2=random(sizeof(heroList1)/sizeof(char*));
	CCString* tmpChar=CCString::create(heroList1[index2]);
	CCString* tmpRole=CCString::create("Player");
	CCString* tmpGroup=CCString::create("Konoha");

	dic->setObject(tmpChar,"character");
	dic->setObject(tmpRole,"role");
	dic->setObject(tmpGroup,"group");

	CCArray* tempHeros=CCArray::createWithObject(dic);
	
	CCArray* realHero=CCArray::create();
	int num= sizeof(heroList1)/sizeof(char*);
	for(int i=0;i<num;i++){
		if(strcmp(tmpChar->getCString(),heroList1[i])==0){
			continue;
		}
		CCString* hero=CCString::create(heroList1[i]);
		realHero->addObject(hero);
	}

	//特殊组队
	/*char* heroList2[]={"Naruto","Deidara","Konan"};

	CCArray* enemyHero=CCArray::create();
	int num2= sizeof(heroList2)/sizeof(char*);
	for(int x=0;x<num2;x++){
	if(strcmp(tmpChar->getCString(),heroList2[x])==0){
	continue;
	}
	CCString* hero=CCString::create(heroList2[x]);
	enemyHero->addObject(hero);
	}*/
	//--------------

	for(int i=0;i<7;i++){

		if(i<3){
			int length=realHero->count();
			srand((int)time(0));
			int index=random(length);
			if(index==(int)realHero->count()){
				
				index=realHero->count()-1;
			}


			CCObject* tempObject=realHero->objectAtIndex(index);
			CCString* hero=(CCString*) tempObject;

			dic=CCDictionary::create();
			tmpChar=CCString::create(hero->getCString());
			tmpRole=CCString::create("Com");
			tmpGroup=CCString::create("Konoha");

			dic->setObject(tmpChar,"character");
			dic->setObject(tmpRole,"role");
			dic->setObject(tmpGroup,"group");

			tempHeros->addObject(dic);
			realHero->removeObjectAtIndex(index);


		}else{

			int length=realHero->count();
			srand((int)time(0));
			int index=random(length);
			if(index==(int)realHero->count()){
				index=realHero->count()-1;
			}

			CCObject* tempObject=realHero->objectAtIndex(index);
			CCString* hero=(CCString*) tempObject;

			dic=CCDictionary::create();
			tmpChar=CCString::create(hero->getCString());
			tmpRole=CCString::create("Com");
			tmpGroup=CCString::create("Akatsuki");

			dic->setObject(tmpChar,"character");
			dic->setObject(tmpRole,"role");
			dic->setObject(tmpGroup,"group");

			tempHeros->addObject(dic);
			realHero->removeObjectAtIndex(index);

		} 

	}


	CCScene* loadScene=CCScene::create();
	LoadLayer* loadLayer=LoadLayer::create();
	loadLayer->tempHeros=tempHeros;
	loadScene->addChild(loadLayer);
	loadLayer->preloadAudio();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5f,loadScene));


	}


	








}

void StartMenu::onCreditsCallBack(){

	if(input_layer || profile_layer || group_layer) {

		return;
	}
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	CCScene* creditsScene=CCScene::create();
	CreditsLayer* creditsLayer=CreditsLayer::create();
	creditsScene->addChild(creditsLayer);
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5f,creditsScene));

}

void StartMenu::scrollMenu(int posY){
		CCObject* pObject=NULL;
		if(posY>_pos02 || (isDrag && isClockwise)){ //顺时针
			CCARRAY_FOREACH(_menu_array,pObject){
				MenuButton* menu=(MenuButton *)pObject;
				if(menu->getPositionY()==_pos01){
					CCActionInterval* spn=CCMoveTo::create(0.5,ccp(105,_pos02));
					this->reorderChild(menu,1);
					menu->_isBottom=true;
					CCFadeOut* fo=CCFadeOut::create(0.3f);
					CCSpawn* seq=CCSpawn::createWithTwoActions(spn,fo);
					menu->runAction(seq);

				}else if(menu->getPositionY()==_pos03){
					CCAction* spn=CCSpawn::create(
						CCMoveTo::create(0.5,ccp(105,_pos02)),
						CCScaleTo::create(0.5,1),
						NULL
						);
					this->reorderChild(menu,3);
					menu->_isTop=true;
				
					/*if(menu->getBtnType()!=Training){
						hardCore_btn->setVisible(false);
					}*/

					CCFiniteTimeAction *call = CCCallFunc::create(menu,callfunc_selector(MenuButton::playSound));
					CCArray* seqArray=CCArray::create();
					seqArray->addObject(spn);
					seqArray->addObject(call);
					CCActionInterval* seq=CCSequence::create(seqArray);
					menu->runAction(seq);

				}else if(menu->getPositionY()==_pos02 && menu->_isBottom){
				
					CCActionInterval* spn=CCMoveTo::create(0.5,ccp(105,_pos03));
					this->reorderChild(menu,1);
					menu->setVisible(true);
					CCFadeIn* fi=CCFadeIn::create(0.3f);
					CCSpawn* seq=CCSpawn::createWithTwoActions(spn,fi);
					menu->_isBottom=false;
					menu->runAction(seq);
				}else if(menu->getPositionY()==_pos02 && !menu->_isBottom){

					CCAction* spn=CCSpawn::create(
						CCMoveTo::create(0.5,ccp(105,_pos01)),
						CCScaleTo::create(0.5,0.5),
						NULL
						);
					this->reorderChild(menu,1);
					menu->_isTop=false;
					menu->runAction(spn);
				}

			};

		}else{ //逆时针
			CCARRAY_FOREACH(_menu_array,pObject){
				MenuButton* menu=(MenuButton *)pObject;
				if(menu->getPositionY()==_pos01){
					CCAction* spn=CCSpawn::create(
						CCMoveTo::create(0.5,ccp(105,_pos02)),
						CCScaleTo::create(0.5,1),
						NULL
						);
					this->reorderChild(menu,3);
					menu->_isTop=true;
				/*	if(menu->getBtnType()!=Training){
						hardCore_btn->setVisible(false);
					}*/
				
					CCFiniteTimeAction *call = CCCallFunc::create(menu,callfunc_selector(MenuButton::playSound));
					CCArray* seqArray=CCArray::create();
					seqArray->addObject(spn);
					seqArray->addObject(call);
					CCActionInterval* seq=CCSequence::create(seqArray);
					menu->runAction(seq);
				}else if(menu->getPositionY()==_pos03){
					CCActionInterval* spn=CCMoveTo::create(0.5,ccp(105,_pos02));
					this->reorderChild(menu,1);
					menu->_isBottom=true;
					CCFadeOut* fo=CCFadeOut::create(0.3f);
					CCSpawn* seq=CCSpawn::createWithTwoActions(spn,fo);
					menu->runAction(seq);

				}else if(menu->getPositionY()==_pos02 && menu->_isBottom){

					CCActionInterval* spn=CCMoveTo::create(0.5,ccp(105,_pos01));
					this->reorderChild(menu,2);
					menu->setVisible(true);
					CCFadeIn* fi=CCFadeIn::create(0.3f);
					CCSpawn* seq=CCSpawn::createWithTwoActions(spn,fi);
					menu->_isBottom=false;
					menu->runAction(seq);
				}
				
				else if(menu->getPositionY()==_pos02  && !menu->_isBottom){
					CCAction* spn=CCSpawn::create(
						CCMoveTo::create(0.5,ccp(105,_pos03)),
						CCScaleTo::create(0.5,0.5),
						NULL
						);
					this->reorderChild(menu,2);
					menu->_isTop=false;
					menu->runAction(spn);
				}
				
			};

		};
		std::string src="";
		CCARRAY_FOREACH(_menu_array,pObject){
			MenuButton* menu=(MenuButton *)pObject;
			
			if(menu->_isTop){
				switch(menu->getBtnType()){
				case Training:
					 src="menu02_text.png";
					break;
				case Network:
					 src="menu01_text.png";
					break;
				case Credits:
					 src="menu04_text.png";
					break;
				case Exit:
					 src="menu03_text.png";
					break;
				}

			}
		}

		CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(src.c_str()); 
		menuText->setDisplayFrame(frame);
	
}


void StartMenu::keyBackClicked(){


	#if CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID

	JniMethodInfo minfo;
	bool isHave = JniHelper::getStaticMethodInfo(minfo,"net/zakume/game/DialogUtils","showTipDialog", "(Ljava/lang/String;Ljava/lang/String;)V");  

	if (isHave)   
	{  

		jstring jTitle = minfo.env->NewStringUTF("Exit Game");
		jstring jMsg = minfo.env->NewStringUTF("Do you really want to exit?");
		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, jTitle, jMsg);
		minfo.env->DeleteLocalRef(jTitle);
		minfo.env->DeleteLocalRef(jMsg);
	}  

	#endif  

	
};

void StartMenu::onExitCallBack(){
	
	this->keyBackClicked();
}