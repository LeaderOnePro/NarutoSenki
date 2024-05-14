#include "RankingLayer.h"
#include "NetworkLayer.h"
USING_NS_CC_EXT;
using namespace CocosDenshion;


/*----------------------
init RankCharButton
----------------------*/
RankCharButton::RankCharButton(void)
{
	_btnType=NULL;
}


RankCharButton::~RankCharButton(void)
{
	
}


bool RankCharButton::init(const char *szImage){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCSprite::init());
		if(strcmp(szImage,"")!=0)
			this->initWithSpriteFrameName(szImage);
			

		this->setAnchorPoint(ccp(0,0));

		bRet=true;

	}while(0);

	return bRet;

}

void RankCharButton::onEnter(){
	CCSprite::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-1,true);
}
void RankCharButton::onExit(){
	CCSprite::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

CCRect RankCharButton::getRect(){
	CCSize size=this->getContentSize();
	return CCRect(0,0, size.width, size.height);

}
bool  RankCharButton::containsTouchLocation(CCTouch *touch){

	return getRect().containsPoint(convertTouchToNodeSpace(touch));
}


void RankCharButton::setBtnType(CCString* buttonChar){
	_btnType=buttonChar;
	_btnType->retain();
}

	
	


bool RankCharButton::ccTouchBegan(CCTouch* touch,CCEvent* event){
	// touch area 
	if (!this->containsTouchLocation(touch)){
		return false;
	}else{
		return true;
	}


}

void RankCharButton::ccTouchMoved(CCTouch* touch,CCEvent* event){
	// touch area 

}

void RankCharButton::ccTouchEnded(CCTouch* touch,CCEvent* event){
	if(_delegate->_screwLayer1){
		_delegate->_screwLayer1->removeAllChildren();
		_delegate->_screwLayer1->setPositionY(154);
	}
	if(_delegate->day_btn){
		_delegate->day_btn->unselected();
	}
	if(_delegate->week_btn){
		_delegate->week_btn->unselected();
	}
	if(_delegate->month_btn){
		_delegate->month_btn->selected();
	}
	

	_delegate->postRequest(300,_btnType);
};



RankCharButton* RankCharButton::create( const char *szImage ){
	RankCharButton* mb=new RankCharButton();
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













RakingLayer::RakingLayer(void)
{
	_screwLayer1=NULL;
	isPosting=false;
	refreshBtn=NULL;
	ranking_layer=NULL;
	order_menu=NULL;
	postingCode=0;
	rankingDetail=NULL;
	side0_btn=NULL;
	isMemberSelect=false;
	isGroupSelect=false;
}


RakingLayer::~RakingLayer(void)
{

}

bool RakingLayer::init(){

	bool bRet=false;
	do{
		CC_BREAK_IF(!CCLayer::init());
	
		//加载序列集
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ranking.plist");

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
		this->addChild(cloud_left,2);

		CCActionInterval* cmv1=CCMoveBy::create(1,ccp(-15,0));
		CCAction* cseq1=CCRepeatForever::create(CCSequence::create(cmv1,cmv1->reverse(),NULL));
		cloud_left->runAction(cseq1);

		CCSprite* cloud_right=CCSprite::createWithSpriteFrameName("cloud.png");	
		cloud_right->setPosition(ccp(winSize.width-cloud_right->getContentSize().width,15));
		cloud_right->setFlipY(true);
		cloud_right->setAnchorPoint(ccp(0,0));
		this->addChild(cloud_right,2);

		CCActionInterval* cmv2=CCMoveBy::create(1,ccp(15,0));
		CCAction* cseq2=CCRepeatForever::create(CCSequence::create(cmv2,cmv2->reverse(),NULL));
		cloud_right->runAction(cseq2);

		CCSprite* cloud_top=CCSprite::createWithSpriteFrameName("cloud_top.png");
		cloud_top->setPosition(ccp(winSize.width/2,winSize.height-(cloud_top->getContentSize().height+12)));
		cloud_top->setAnchorPoint(ccp(0.5f,0));
		this->addChild(cloud_top,1);



		if(CCUserDefault::sharedUserDefault()->getBoolForKey("isBGM")!=false){
			SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/Music/ranking_music.mp3",true);
		}


		//produce the menu_bar
		CCSprite* menu_bar_b = CCSprite::create("menu_bar2.png");
		menu_bar_b->setAnchorPoint(ccp(0,0));
		this->addChild(menu_bar_b,2);


		CCSprite* menu_bar_t = CCSprite::create("menu_bar3.png");
		menu_bar_t->setAnchorPoint(ccp(0,0));
		menu_bar_t->setPosition(ccp(0,winSize.height-menu_bar_t->getContentSize().height));
		this->addChild(menu_bar_t,2);

		CCSprite* record_title=CCSprite::createWithSpriteFrameName("record_title.png");
		record_title->setAnchorPoint(ccp(0,0));
		record_title->setPosition(ccp(2,winSize.height-record_title->getContentSize().height-2));
		this->addChild(record_title,3);



		CCMenuItem* start_bt=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("return_btn.png"),NULL,NULL,this,menu_selector(RakingLayer::onCancel));
		CCMenu* menu =CCMenu::create(start_bt,NULL);
		menu->setPosition(winSize.width-38,86);
		//menu->setPosition(winSize.width/2+skillSprite->getContentSize().width/2-10,winSize.height/2+skillSprite->getContentSize().height/2-12);
		this->addChild(menu,5);





		//加载排行榜界面


		CCClippingNode* clipper = CCClippingNode::create();
		CCNode *stencil = CCSprite::createWithSpriteFrameName("screwMask2.png");
		stencil->setAnchorPoint(ccp(0,0));
		clipper->setStencil(stencil);

		ranking_layer=CCLayer::create();

		ranking_bg=CCSprite::createWithSpriteFrameName("ranking_bg.png");
		ranking_bg->setAnchorPoint(ccp(0.5f,0.5f));
		ranking_bg->setPosition(ccp(winSize.width/2,winSize.height/2-15));
		ranking_layer->addChild(ranking_bg,10);


		CCSprite* ranking_logo=CCSprite::createWithSpriteFrameName("ranking_logo.png");
		ranking_logo->setAnchorPoint(ccp(0.5f,0.5f));
		ranking_logo->setPosition(ccp(ranking_bg->getPositionX(),ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2+16));
		ranking_layer->addChild(ranking_logo,11);


		ranking_title=CCSprite::createWithSpriteFrameName("ranking_title1.png");
		ranking_title->setAnchorPoint(ccp(0,0));
		ranking_title->setPosition(ccp(ranking_bg->getPositionX()-62,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-16));
		ranking_layer->addChild(ranking_title,15);

		_screwLayer1=CCScrewLayer::create();
		_screwLayer1->setAnchorPoint(ccp(0,0));
		_screwLayer1->setPositionY(154);
		_screwLayer1->line_height=26;
		_screwLayer1->minY=154;

		clipper->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2,58));
		clipper->addChild(_screwLayer1,5);

		ranking_layer->addChild(clipper,20);

		


		//边栏
		//CCMenu* side_menu0 ;
		//if(GroupID){
		//	side0_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("sidebar0_off.png"),CCSprite::createWithSpriteFrameName("sidebar0_on.png"),this,menu_selector(RakingLayer::onSideBar0));
		//	side0_btn->setAnchorPoint(ccp(0,0));
		// side_menu0 = CCMenu::create(side0_btn,NULL);
		//	side_menu0->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2-40,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-35));
		//	ranking_layer->addChild(side_menu0,6);
		//	side0_btn->selected();
		//}


		//side1_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("sidebar1_off.png"),CCSprite::createWithSpriteFrameName("sidebar1_on.png"),this,menu_selector(RakingLayer::onSideBar1));
		//side1_btn->setAnchorPoint(ccp(0,0));
		//CCMenu* side_menu1 = CCMenu::create(side1_btn,NULL);
		//if(side0_btn){
		//	side_menu1->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2-40,side_menu0->getPositionY()-35));
		//	
		//}else{
		//	side_menu1->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2-40,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-35));
		//	side1_btn->selected();
		//}
		//
		//ranking_layer->addChild(side_menu1,6);
		

		side2_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("sidebar2_off.png"),CCSprite::createWithSpriteFrameName("sidebar2_on.png"),this,menu_selector(RakingLayer::onSideBar2));
		side2_btn->setAnchorPoint(ccp(0,0));
		CCMenu* side_menu2 = CCMenu::create(side2_btn,NULL);
		side_menu2->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2-40,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-35));
		ranking_layer->addChild(side_menu2,5);


		/*side3_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("sidebar3_off.png"),CCSprite::createWithSpriteFrameName("sidebar3_on.png"),this,menu_selector(RakingLayer::onSideBar3));
		side3_btn->setAnchorPoint(ccp(0,0));
		CCMenu* side_menu3 = CCMenu::create(side3_btn,NULL);
		side_menu3->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2-40,side_menu2->getPositionY()-35));
		ranking_layer->addChild(side_menu3,4);
*/


		this->addChild(ranking_layer,100);
		if(GroupID){
				this->produceRanking(0);
		}else{
			this->produceRanking(2);
		}
		


		bRet=true;

	}while(0);

	return bRet;

}
void RakingLayer::onSideBar0(CCObject* sender){
	this->produceRanking(0);
}
void RakingLayer::onSideBar1(CCObject* sender){
	this->produceRanking(1);
}
void RakingLayer::onSideBar2(CCObject* sender){
	this->produceRanking(2);
}
void RakingLayer::onSideBar3(CCObject* sender){
	this->produceRanking(3);
}



void RakingLayer::produceRanking(int type){
	if(isPosting){
		return;
	}

	if(_screwLayer1){
		_screwLayer1->removeAllChildren();
		_screwLayer1->setPositionY(154);
	}
	


	if(order_menu){
		order_menu->removeAllChildren();
		order_menu=NULL;
	}

	if(rankingDetail){
		rankingDetail->removeFromParent();
		rankingDetail=NULL;
	}


	switch (type){

	case 0:
		if(ranking_title){
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ranking_title1.png"); 
			ranking_title->setDisplayFrame(frame);
			ranking_title->setPosition(ccp(ranking_bg->getPositionX()-62,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-16));
		}
		if(side0_btn){
			side0_btn->selected();
		}
		side1_btn->unselected();
		side2_btn->unselected();
		side3_btn->unselected();

		isMemberSelect=true;
		isGroupSelect=false;

		day_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("order_day_off.png"),CCSprite::createWithSpriteFrameName("order_day_on.png"),this,menu_selector(RakingLayer::onDayBtn));
		week_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("order_week_off.png"),CCSprite::createWithSpriteFrameName("order_week_on.png"),this,menu_selector(RakingLayer::onWeekBtn));
		month_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("order_month_off.png"),CCSprite::createWithSpriteFrameName("order_month_on.png"),this,menu_selector(RakingLayer::onMonthBtn));
		order_menu = CCMenu::create(day_btn,week_btn,month_btn,NULL);
		order_menu->alignItemsHorizontallyWithPadding(20);
		order_menu->setPosition(ccp(ranking_bg->getPositionX()+100,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
		order_menu->setTouchPriority(-1);
		ranking_layer->addChild(order_menu,10);
		day_btn->selected();

		this->postRequest(110);
		break;
	case 1:

		if(ranking_title){
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ranking_title1.png"); 
			ranking_title->setDisplayFrame(frame);
			ranking_title->setPosition(ccp(ranking_bg->getPositionX()-62,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-16));
		}
		if(side0_btn){
			side0_btn->unselected();
		}
		side1_btn->selected();
		side2_btn->unselected();
		side3_btn->unselected();

		isMemberSelect=false;
		isGroupSelect=false;

		day_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("order_day_off.png"),CCSprite::createWithSpriteFrameName("order_day_on.png"),this,menu_selector(RakingLayer::onDayBtn));
		week_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("order_week_off.png"),CCSprite::createWithSpriteFrameName("order_week_on.png"),this,menu_selector(RakingLayer::onWeekBtn));
		month_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("order_month_off.png"),CCSprite::createWithSpriteFrameName("order_month_on.png"),this,menu_selector(RakingLayer::onMonthBtn));
		order_menu = CCMenu::create(day_btn,week_btn,month_btn,NULL);
		order_menu->alignItemsHorizontallyWithPadding(20);
		order_menu->setPosition(ccp(ranking_bg->getPositionX()+100,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
		order_menu->setTouchPriority(-1);
		ranking_layer->addChild(order_menu,10);
		day_btn->selected();

		this->postRequest(100);

		break;


	case 2:
		if(side0_btn){
			side0_btn->unselected();
		}
		side2_btn->selected();
		//side1_btn->unselected();
		//side3_btn->unselected();

		if(ranking_title){
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ranking_title2.png"); 
			ranking_title->setDisplayFrame(frame);
			ranking_title->setPosition(ccp(ranking_bg->getPositionX()-96,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-16));
		}

		isMemberSelect=false;
		isGroupSelect=false;

		JifenPoint_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("order_jifen_off.png"),CCSprite::createWithSpriteFrameName("order_jifen_on.png"),this,menu_selector(RakingLayer::onJifenBtn));
		battlePoint_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("order_battle_off.png"),CCSprite::createWithSpriteFrameName("order_battle_on.png"),this,menu_selector(RakingLayer::onBattleBtn));
		order_menu = CCMenu::create(JifenPoint_btn,battlePoint_btn,NULL);
		order_menu->alignItemsHorizontallyWithPadding(20);
		order_menu->setPosition(ccp(ranking_bg->getPositionX()+100,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
		ranking_layer->addChild(order_menu,10);
		JifenPoint_btn->selected();
		order_menu->setTouchPriority(-1);
		
		this->postRequest(400);

		break;

	case 3:
		if(side0_btn){
			side0_btn->unselected();
		}
		side3_btn->selected();
		side1_btn->unselected();
		side2_btn->unselected();
		if(ranking_title){
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ranking_title3.png"); 
			ranking_title->setDisplayFrame(frame);
			ranking_title->setPosition(ccp(ranking_bg->getPositionX()-106,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-16));
		}
		isMemberSelect=false;
		isGroupSelect=true;

		JifenPoint_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("order_jifen_off.png"),CCSprite::createWithSpriteFrameName("order_jifen_on.png"),this,menu_selector(RakingLayer::onJifenBtn));
		battlePoint_btn=CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("order_battle_off.png"),CCSprite::createWithSpriteFrameName("order_battle_on.png"),this,menu_selector(RakingLayer::onBattleBtn));
		order_menu = CCMenu::create(JifenPoint_btn,battlePoint_btn,NULL);
		order_menu->alignItemsHorizontallyWithPadding(20);
		order_menu->setPosition(ccp(ranking_bg->getPositionX()+100,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
		ranking_layer->addChild(order_menu,10);
		JifenPoint_btn->selected();
		
		this->postRequest(600);


		break;


	}
}

void RakingLayer::postRequest(int code,CCString* useChar/* =NULL */){

	if(rankingDetail){
		rankingDetail->removeFromParent();
		rankingDetail=NULL;
	}
	postingCode= code;
	rapidjson::Document doc;
	unsigned long size;
	const char* data;
	if(postingCode==400){
		data=(const char*)CCFileUtils::sharedFileUtils()->getFileData("rank.json", "r",&size);
	}else {
		data=(const char*)CCFileUtils::sharedFileUtils()->getFileData("rank2.json", "r",&size);
	}

	std::string clearData(data);
	size_t pos = clearData.rfind("]");
	clearData = clearData.substr(0, pos+1);

	doc.Parse<kParseDefaultFlags>(clearData.c_str());

	
	Value &arr=doc;
	int countRow=0;

	if(arr.IsArray()){

		for (SizeType i = 0; i < arr.Size(); i++)  {


			Value & node=arr[i];

			if(i==0){
				//排位
				Value & sortValue= node["newid"];
				int sortNO=sortValue.GetInt();


				if(sortNO==0){

					CCDictionary *strings = CCDictionary::createWithContentsOfFile("Element/strings.xml");  
					const char *reply;
					if(postingCode==400){
						reply= ((CCString*)strings->objectForKey("RankingNull"))->m_sString.c_str();   
					}else{
						reply= ((CCString*)strings->objectForKey("RankingNull2"))->m_sString.c_str();   
					}
					
					rankingDetail=CCLabelTTF::create(CCString::createWithFormat("%s",reply)->getCString(),FONT_TYPE,12);
					rankingDetail->setAnchorPoint(ccp(0,0.5f));
					rankingDetail->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2 +20,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
					ranking_layer->addChild(rankingDetail,500);

				}else{
					CCDictionary *strings = CCDictionary::createWithContentsOfFile("Element/strings.xml");  
					const char *reply = ((CCString*)strings->objectForKey("RankingDetail"))->m_sString.c_str();  
					const char *reply2 = ((CCString*)strings->objectForKey("RankingDetail2"))->m_sString.c_str();  
					rankingDetail=CCLabelTTF::create(CCString::createWithFormat("%s %d %s",reply,sortNO,reply2)->getCString(),FONT_TYPE,12);
					rankingDetail->setAnchorPoint(ccp(0,0.5f));
					rankingDetail->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2 +20,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
					ranking_layer->addChild(rankingDetail,500);
				}

			}else{


				Value & idValue= node["id"];
				std::string idString=idValue.GetString();
				int memberID=atoi(idString.c_str());


				Value & nameValue= node["name"];
				std::string name=nameValue.GetString();

				Value & npValue= node["np_id"];
				std::string npString=npValue.GetString();

				Value & groupNameValue= node["group_name"];
				std::string groupName;
				int groupID=0;
				if(groupNameValue.IsNull()){
					groupName="";
				}else{
					groupName=groupNameValue.GetString();

					if(postingCode==400 || postingCode==500){
						Value & gidValue= node["group_id"];
						std::string groupString=gidValue.GetString();
						groupID=atoi(groupString.c_str());
					}


				}




				int score;
				Value & bpointValue= node["battle_point"];
				std::string bpointString=bpointValue.GetString();
				int bpoint=atof(bpointString.c_str())*100;

				Value & pointValue= node["point"];
				std::string pointString=pointValue.GetString();
				int point=atof(pointString.c_str());

				if(postingCode==500){
					score=bpoint;
				}else if(postingCode==400) {
					score=point;
				}else if(postingCode==600){
					score=point;
				}else if(postingCode==700){
					score=bpoint;
				}else if(postingCode==800){
					score=point;
				}else if(postingCode==900){
					score=bpoint;
				}


				CCScrewItem* screwItem=CCScrewItem::create();
				if(i%2!=0){
					CCSprite* line_bg=CCSprite::createWithSpriteFrameName("ranking_line.png");
					line_bg->setAnchorPoint(ccp(0,0));
					screwItem->addChild(line_bg);
				}

				if(i==1){
					CCSprite* num_icon;
					if(postingCode==500){
						num_icon=CCSprite::createWithSpriteFrameName("num_top3.png");
					}else if(postingCode==400) {
						num_icon=CCSprite::createWithSpriteFrameName("num_top2.png");
					}else{
						num_icon=CCSprite::createWithSpriteFrameName("num_top4.png");
					}
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else if(i==2){
					CCSprite* num_icon=CCSprite::createWithSpriteFrameName("num_2.png");
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else if(i==3){
					CCSprite* num_icon=CCSprite::createWithSpriteFrameName("num_3.png");
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else{
					CCLabelTTF* numLabel=CCLabelTTF::create(CCString::createWithFormat("%d",i)->getCString(),"微软雅黑",12);
					numLabel->setPosition(ccp(13,13));
					screwItem->addChild(numLabel);
				}

				if(strcmp(npString.c_str(),"")!=0){

					CCSprite* nameplate=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s.png",npString.c_str())->getCString());
					nameplate->setAnchorPoint(ccp(0.5f,0));
					nameplate->setPosition(ccp(106,0));
					screwItem->addChild(nameplate);

					CCStrokeLabel* user_nameStr;
					CCLabelTTF* user_name=CCLabelTTF::create(name.c_str(),FONT_TYPE,12);
					if(MemberID){
						if(MemberID==memberID){
							user_nameStr = CCStrokeLabel::create(user_name,ccc3(0,0,0),ccc3(236,162,8),1.0f);
						}else{
							user_nameStr = CCStrokeLabel::create(user_name,ccc3(0,0,0),ccc3(255,255,255),1.0f);
						}
					}else{
						user_nameStr = CCStrokeLabel::create(user_name,ccc3(0,0,0),ccc3(255,255,255),1.0f);
					}

					user_nameStr->setPosition(ccp(106,13));
					screwItem->addChild(user_nameStr);

					bool isBlink=false;
					const char* bannerPath;
					if(strcmp(npString.c_str(),"np000")==0 ||
						strcmp(npString.c_str(),"np001")==0 ||
						point>=99999){
							bannerPath="banner_black";
							isBlink=true;
					}else if(point>=48000){
						bannerPath="banner_blue";
						isBlink=true;
					}else if(point>=24000){
						bannerPath="banner_red";
						isBlink=true;
					}else if(point>=16000){
						bannerPath="banner_gold";
						isBlink=true;
					}else if(point>=12000){
						bannerPath="banner_gold";
					}else if(point>=6000){
						bannerPath="banner_silver";
					}else{
						bannerPath="banner_green";
					}

					CCSprite* nameBaner=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s.png",bannerPath)->getCString());
					nameBaner->setAnchorPoint(ccp(0.5f,0));
					nameBaner->setPosition(ccp(106,0));
					screwItem->addChild(nameBaner);

					if(isBlink){

						CCSprite* blink=CCSprite::createWithSpriteFrameName("banner_blink5.png");
						blink->setAnchorPoint(ccp(0.5f,0));
						blink->setPosition(ccp(106,0));

						screwItem->addChild(blink);


						CCArray* tempArray= CCArray::create();

						int i=1;

						CCArray* list=CCArray::create();
						while (i<7)
						{
							CCString* path=CCString::createWithFormat("banner_blink%d.png",i);
							CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(path->getCString());
							tempArray->addObject(frame);


							i+=1;
						}

						CCAnimation* tempAnimation= CCAnimation::createWithSpriteFrames(tempArray, 0.1f);
						CCAction* tempAction=CCAnimate::create(tempAnimation);
						list->addObject(tempAction);
						CCDelayTime* delay=CCDelayTime::create(1.0f);
						list->addObject(delay);

						blink->runAction(CCRepeatForever::create(CCSequence::create(list)));
					}

				}else{
					CCLabelTTF* user_name=CCLabelTTF::create(name.c_str(),FONT_TYPE,12);

					if(MemberID){
						if(MemberID==memberID){
							user_name->setColor(ccc3(236,162,8));
						}
					}

					user_name->setAnchorPoint(ccp(0.5f,0.5));
					user_name->setPosition(ccp(106,13));
					screwItem->addChild(user_name);

				}



				CCLabelTTF* user_score=CCLabelTTF::create(CCString::createWithFormat("%d",score)->getCString(),FONT_TYPE,12);

				user_score->setAnchorPoint(ccp(0.5f,0));
				user_score->setPosition(ccp(214,5));
				screwItem->addChild(user_score);


				if(groupID!=0){
					CCLabelTTF* group_Name=CCLabelTTF::create(CCString::createWithFormat("%s",groupName.c_str())->getCString(),FONT_TYPE,12);

					CCMenuItemLabel* item=CCMenuItemLabel::create(group_Name, this, menu_selector(RakingLayer::onSelectGroupBtn));

					CCMenu* pMenu = CCMenu::create(item, NULL);
					pMenu ->setPosition(ccp(304,5));
					item ->setAnchorPoint(ccp(0.5f,0));
					item->setTag(groupID);
					pMenu->setTouchPriority(1);
					screwItem->addChild(pMenu);
					screwItem->setTag(groupID); 

				}else if(strcmp(groupName.c_str(),"")!=0 ){
					CCLabelTTF* group_Name=CCLabelTTF::create(CCString::createWithFormat("%s",groupName.c_str())->getCString(),FONT_TYPE,12);

					group_Name->setAnchorPoint(ccp(0.5f,0));
					group_Name->setPosition(ccp(304,5));
					screwItem->addChild(group_Name);


				}

				int row=i;
				screwItem->setPosition(ccp(0,-row*26+26));
				screwItem->setAnchorPoint(ccp(0,0));

				_screwLayer1->addChild(screwItem,10);

				countRow++;

			}
		}
		_screwLayer1->totalRow=countRow;

	}


	//if(!isPosting){

	//	isPosting=true;
	//	postingCode=code;
	//	//刷新按钮
	//	if(!refreshBtn){
	//		refreshBtn=CCSprite::createWithSpriteFrameName("refresh_btn.png");
	//		refreshBtn->setPosition(ccp(winSize.width/2,winSize.height/2));
	//		CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
	//		refreshBtn->runAction(CCRepeatForever::create(rt));
	//		this->addChild(refreshBtn,1000);


	//	}
	//	cocos2d::extension::CCHttpRequest* request = new CCHttpRequest(); 
	//	std::string codeFinal;
	//	if(useChar){
	//		codeFinal=CCString::createWithFormat("code=%d&id=%d&char=%s",code,MemberID,useChar->getCString())->getCString();
	//	}else{
	//		codeFinal=CCString::createWithFormat("code=%d&id=%d&group_id=%d",code,MemberID,GroupID?GroupID:0)->getCString();
	//	}
	//
	//	std::string url=SERVER"nsk/rank.php?"+codeFinal;
	//	request->setUrl(url.c_str());  
	//	request->setRequestType(CCHttpRequest::kHttpGet);  
	//	if(code>510){
	//		request->setResponseCallback(this, callfuncND_selector(RakingLayer::onHttpRequestCompleted3));  
	//	}else if(code>310){
	//		request->setResponseCallback(this, callfuncND_selector(RakingLayer::onHttpRequestCompleted2));  
	//	}else {
	//		request->setResponseCallback(this, callfuncND_selector(RakingLayer::onHttpRequestCompleted));  
	//	}

	//	request->setTag("Post_My_Data");  
	//	cocos2d::extension::CCHttpClient::getInstance()->send(request);  
	//	request->release();  
	//}

}



void RakingLayer::onCancel(CCObject* sender){

	this->removeFromParent();
	SimpleAudioEngine::sharedEngine()->playEffect("Audio/Menu/cancel.ogg");
	
	CCDirector::sharedDirector()->popScene();
}

void  RakingLayer::onDayBtn(CCObject* sender){

	if(_screwLayer1){
		_screwLayer1->removeAllChildren();
		_screwLayer1->setPositionY(154);
	}
	
	if(isMemberSelect){
		this->postRequest(110);
	}else{
		this->postRequest(100);
	}
	


	day_btn->selected();
	week_btn->unselected();
	month_btn->unselected();
}

void  RakingLayer::onWeekBtn(CCObject* sender){
	if(_screwLayer1){
		_screwLayer1->removeAllChildren();
	}
	_screwLayer1->setPositionY(154);
	if(isMemberSelect){
		this->postRequest(210);
	}else{
		this->postRequest(200);
	}

	day_btn->unselected();
	month_btn->unselected();
	week_btn->selected();

}



void  RakingLayer::onMonthBtn(CCObject* sender){

	if(_screwLayer1){
		_screwLayer1->removeAllChildren();
		_screwLayer1->setPositionY(154);
	}
	
	if(isMemberSelect){
		this->postRequest(310);
	}else{
		this->makeCharList();
	}

	day_btn->unselected();
	week_btn->unselected();
	month_btn->selected();
}

void  RakingLayer::onJifenBtn(CCObject* sender){

	if(_screwLayer1){
		_screwLayer1->removeAllChildren();
		_screwLayer1->setPositionY(154);
	}
	
	if(isGroupSelect){
		if(ranking_title){
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ranking_title3.png"); 
			ranking_title->setDisplayFrame(frame);
			ranking_title->setPosition(ccp(ranking_bg->getPositionX()-106,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-16));
		}
		this->postRequest(600);
	}else{
		this->postRequest(400);
	}
	
	
	battlePoint_btn->unselected();
	JifenPoint_btn->selected();

}
void  RakingLayer::onBattleBtn(CCObject* sender){

	if(_screwLayer1){
		_screwLayer1->removeAllChildren();
		_screwLayer1->setPositionY(154);
	}
	
	if(isGroupSelect){
		if(ranking_title){
			CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ranking_title3.png"); 
			ranking_title->setDisplayFrame(frame);
			ranking_title->setPosition(ccp(ranking_bg->getPositionX()-106,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-16));
		}
		this->postRequest(700);
	}else{
	this->postRequest(500);
	}
	JifenPoint_btn->unselected();
	battlePoint_btn->selected();

}


void RakingLayer::makeCharList(){
	if(rankingDetail){
		rankingDetail->removeFromParent();
		rankingDetail=NULL;
	}
	char* heroList[]={"Naruto","Sakura","Sai","Kakashi",
		"Lee","Tenten","Neji",
		"Shikamaru","Ino","Choji","Asuma",
		"Shino","Hinata","Kiba",
		"Tobirama","Hiruzen","Minato",
		"Jiraiya","Tsunade","Gaara","Kankuro",
		"Chiyo",
		"Sasuke","Karin","Suigetsu","Jugo",
		"Deidara","Tobi","Hidan","Kakuzu",
		"Konan","Itachi","Kisame"
	};

	int num= sizeof(heroList)/sizeof(char*);

	for(int i=0;i<num;i++){

		const char* charName=heroList[i];
		CCString* path=CCString::createWithFormat("%s_small.png",charName);
		
	
		RankCharButton* char_btn=RankCharButton::create(path->getCString());
		char_btn->setDelegate(this);
		char_btn->setBtnType(CCString::createWithFormat("%s",charName));
		char_btn->setAnchorPoint(ccp(0,0));
		int row=int(floor(float(i)/8));
		int column=i-8*row;

		char_btn->setPosition(ccp(10+column*46,-10-row*46));
		_screwLayer1->line_height=56;
		_screwLayer1->addChild(char_btn);
		_screwLayer1->totalRow=row;
		
	};



}


void RakingLayer::onHttpRequestCompleted(CCNode *sender ,void *data) {  

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
	int countRow=0;
	if(arr.IsArray()){

		for (SizeType i = 0; i < arr.Size(); i++)  {
			

			Value & node=arr[i];

			if(i==0){
				//排位
				Value & sortValue= node["newid"];
				int sortNO=sortValue.GetInt();
				

				if(sortNO==0){
					CCDictionary *strings = CCDictionary::createWithContentsOfFile("Element/strings.xml");  
					const char *reply = ((CCString*)strings->objectForKey("RankingNull"))->m_sString.c_str();   
					rankingDetail=CCLabelTTF::create(CCString::createWithFormat("%s",reply)->getCString(),FONT_TYPE,12);
					rankingDetail->setAnchorPoint(ccp(0,0.5f));
					rankingDetail->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2 +20,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
					ranking_layer->addChild(rankingDetail,500);

				}else{
					CCDictionary *strings = CCDictionary::createWithContentsOfFile("Element/strings.xml");  
					const char *reply = ((CCString*)strings->objectForKey("RankingDetail"))->m_sString.c_str();  
					const char *reply2 = ((CCString*)strings->objectForKey("RankingDetail2"))->m_sString.c_str();  
					rankingDetail=CCLabelTTF::create(CCString::createWithFormat("%s %d %s",reply,sortNO,reply2)->getCString(),FONT_TYPE,12);
					rankingDetail->setAnchorPoint(ccp(0,0.5f));
					rankingDetail->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2 +20,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
					ranking_layer->addChild(rankingDetail,500);
				}

			}else{
				
				Value & idValue= node["member_id"];
				std::string idString=idValue.GetString();
				int memberID=atoi(idString.c_str());

				Value & nameValue= node["name"];
				std::string name=nameValue.GetString();

				
				Value & charValue= node["use_char"];
				std::string character=charValue.GetString();

				Value & scoreValue= node["score"];
				std::string scoreString=scoreValue.GetString();
				float score=atof(scoreString.c_str());

				Value & bondsValue= node["bonds"];
				std::string bondsString=bondsValue.GetString();
				int bonds=atoi(bondsString.c_str());

				Value & detailValue= node["detail"];
				std::string detailString=detailValue.GetString();

				Value & pointValue= node["point"];
				std::string pointString=pointValue.GetString();
				int point=atof(pointString.c_str());


				const char * split = ",";
				char * p; 
				char* str = new char[50];
				strcpy(str,detailString.c_str());
				p = strtok (str,split); 
				int x=1;
				char* clear_time=0;
				int kills=0;
				int deads=0;
				int frogs=0;

				while(p!=NULL) { 
					if(x==1){
						clear_time=p;
					}else if(x==2){
						kills=atoi(p);
					}else if(x==3){
						deads=atoi(p);
					}else if(x==4){
						frogs=atoi(p);
					}
					x++;
					p = strtok(NULL,split); 
				} 


			
				Value & dateValue= node["upload_time"];
				std::string upload_time=dateValue.GetString();
				CCScrewItem* screwItem=CCScrewItem::create();

				Value & npValue= node["np_id"];
				std::string npString=npValue.GetString();

				if(i%2!=0){
					CCSprite* line_bg=CCSprite::createWithSpriteFrameName("ranking_line.png");
					line_bg->setAnchorPoint(ccp(0,0));
					screwItem->addChild(line_bg);
				}

				if(i==1){
					CCSprite* num_icon=CCSprite::createWithSpriteFrameName("num_top1.png");
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else if(i==2){
					CCSprite* num_icon=CCSprite::createWithSpriteFrameName("num_2.png");
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else if(i==3){
					CCSprite* num_icon=CCSprite::createWithSpriteFrameName("num_3.png");
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else{
					CCLabelTTF* numLabel=CCLabelTTF::create(CCString::createWithFormat("%d",i)->getCString(),"微软雅黑",12);
					numLabel->setPosition(ccp(13,13));
					screwItem->addChild(numLabel);
				}
				CCString* path;
				if(strcmp(character.c_str(),"")==0){
					path=CCString::createWithFormat("error_small.png");
				}else{
					path=CCString::createWithFormat(("%s_small.png"),character.c_str());
				}
				if(isMemberSelect){
					CCSprite* avator_small=CCSprite::createWithSpriteFrameName(path->getCString());
					avator_small->setAnchorPoint(ccp(0,0));
					avator_small->setPosition(ccp(183,0));
					screwItem->addChild(avator_small);

				}else{
					RankCharButton* char_btn=RankCharButton::create(path->getCString());
					char_btn->setDelegate(this);
					char_btn->setBtnType(CCString::createWithFormat("%s",character.c_str()));
					char_btn->setAnchorPoint(ccp(0,0));
					char_btn->setPosition(ccp(183,0));
					screwItem->addChild(char_btn);
				}
				
				const char* path2;
				if(bonds>=300){
					path2="small_sss.png";
				}else if(bonds>=200){
					path2="small_ss.png";
				}else if(bonds>=100){
					path2="small_s.png";
				}else if(bonds>=50){
					path2="small_a.png";
				}else if(bonds>=25){
					path2="small_b.png";
				}else{
					path2="small_c.png";
				}

				CCSprite* bondsLevel=CCSprite::createWithSpriteFrameName(path2);
				bondsLevel->setAnchorPoint(ccp(0,0));
				bondsLevel->setPosition(ccp(174,16));
				screwItem->addChild(bondsLevel,500);


				if(strcmp(npString.c_str(),"")!=0){

					CCSprite* nameplate=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s.png",npString.c_str())->getCString());
					nameplate->setAnchorPoint(ccp(0.5f,0));
					nameplate->setPosition(ccp(106,0));
					screwItem->addChild(nameplate);

					CCStrokeLabel* user_nameStr;
					CCLabelTTF* user_name=CCLabelTTF::create(name.c_str(),FONT_TYPE,12);
					if(MemberID){
						if(MemberID==memberID){
							 user_nameStr = CCStrokeLabel::create(user_name,ccc3(0,0,0),ccc3(236,162,8),1.0f);
						}else{
							user_nameStr = CCStrokeLabel::create(user_name,ccc3(0,0,0),ccc3(255,255,255),1.0f);
						}
					}else{
						user_nameStr = CCStrokeLabel::create(user_name,ccc3(0,0,0),ccc3(255,255,255),1.0f);
					}

					user_nameStr->setPosition(ccp(106,13));
					screwItem->addChild(user_nameStr);

					bool isBlink=false;
					const char* bannerPath;
					if(strcmp(npString.c_str(),"np000")==0 ||
						strcmp(npString.c_str(),"np001")==0 ||
						point>=99999){
							bannerPath="banner_black";
							isBlink=true;
					}else if(point>=48000){
						bannerPath="banner_blue";
						isBlink=true;
					}else if(point>=24000){
						bannerPath="banner_red";
						isBlink=true;
					}else if(point>=16000){
						bannerPath="banner_gold";
						isBlink=true;
					}else if(point>=12000){
						bannerPath="banner_gold";
					}else if(point>=6000){
						bannerPath="banner_silver";
					}else{
						bannerPath="banner_green";
					}

					CCSprite* nameBaner=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s.png",bannerPath)->getCString());
					nameBaner->setAnchorPoint(ccp(0.5f,0));
					nameBaner->setPosition(ccp(106,0));
					screwItem->addChild(nameBaner);


					if(isBlink){

						CCSprite* blink=CCSprite::createWithSpriteFrameName("banner_blink5.png");
						blink->setAnchorPoint(ccp(0.5f,0));
						blink->setPosition(ccp(106,0));

						screwItem->addChild(blink);


						CCArray* tempArray= CCArray::create();

						int i=1;

						CCArray* list=CCArray::create();
						while (i<7)
						{
							CCString* path=CCString::createWithFormat("banner_blink%d.png",i);
							CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(path->getCString());
							tempArray->addObject(frame);


							i+=1;
						}

						CCAnimation* tempAnimation= CCAnimation::createWithSpriteFrames(tempArray, 0.1f);
						CCAction* tempAction=CCAnimate::create(tempAnimation);
						list->addObject(tempAction);
						CCDelayTime* delay=CCDelayTime::create(1.0f);
						list->addObject(delay);

						blink->runAction(CCRepeatForever::create(CCSequence::create(list)));
					}

				}else{
					CCLabelTTF* user_name=CCLabelTTF::create(name.c_str(),FONT_TYPE,12);

					if(MemberID){
						if(MemberID==memberID){
							user_name->setColor(ccc3(236,162,8));
						}
					}

					user_name->setAnchorPoint(ccp(0.5f,0.5));
					user_name->setPosition(ccp(106,13));
					screwItem->addChild(user_name);

				}

				


				CCLabelTTF* user_score=CCLabelTTF::create(CCString::createWithFormat("%.2f",score)->getCString(),FONT_TYPE,12);
				user_score->setAnchorPoint(ccp(0.5f,0));
				user_score->setPosition(ccp(240,5));
				screwItem->addChild(user_score);

				CCLabelTTF* user_time=CCLabelTTF::create(clear_time,FONT_TYPE,12);
				user_time->setAnchorPoint(ccp(0.5f,0));
				user_time->setPosition(ccp(284,5));
				screwItem->addChild(user_time);


				CCLabelTTF* user_detail=CCLabelTTF::create(CCString::createWithFormat("%d/%d/%d",kills,deads,frogs)->getCString(),FONT_TYPE,12);
				user_detail->setAnchorPoint(ccp(0.5f,0));
				user_detail->setPosition(ccp(335,5));
				screwItem->addChild(user_detail);


				int row=i;
				screwItem->setPosition(ccp(0,-row*26+26));
				screwItem->setAnchorPoint(ccp(0,0));

				_screwLayer1->addChild(screwItem,10);
				countRow++;
			}
			

		}

		_screwLayer1->totalRow=countRow;
	}

	//printf("%c" ,temp.c_str());
	//for (unsigned int i = 0; i < buffer->size(); i ++)  
	//{  
	////printf("%c" ,(*buffer)[i]);
	//}  

}  





void RakingLayer::onHttpRequestCompleted2(CCNode *sender ,void *data) {  

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
	int countRow=0;
	if(arr.IsArray()){

		for (SizeType i = 0; i < arr.Size(); i++)  {


			Value & node=arr[i];
			
			if(i==0){
				//排位
				Value & sortValue= node["newid"];
				int sortNO=sortValue.GetInt();


				if(sortNO==0){
					CCDictionary *strings = CCDictionary::createWithContentsOfFile("Element/strings.xml");  
					const char *reply = ((CCString*)strings->objectForKey("RankingNull"))->m_sString.c_str();   
					rankingDetail=CCLabelTTF::create(CCString::createWithFormat("%s",reply)->getCString(),FONT_TYPE,12);
					rankingDetail->setAnchorPoint(ccp(0,0.5f));
					rankingDetail->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2 +20,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
					ranking_layer->addChild(rankingDetail,500);

				}else{
					CCDictionary *strings = CCDictionary::createWithContentsOfFile("Element/strings.xml");  
					const char *reply = ((CCString*)strings->objectForKey("RankingDetail"))->m_sString.c_str();  
					const char *reply2 = ((CCString*)strings->objectForKey("RankingDetail2"))->m_sString.c_str();  
					rankingDetail=CCLabelTTF::create(CCString::createWithFormat("%s %d %s",reply,sortNO,reply2)->getCString(),FONT_TYPE,12);
					rankingDetail->setAnchorPoint(ccp(0,0.5f));
					rankingDetail->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2 +20,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
					ranking_layer->addChild(rankingDetail,500);
				}

			}else{

				
				Value & idValue= node["id"];
				std::string idString=idValue.GetString();
				int memberID=atoi(idString.c_str());

				
				Value & nameValue= node["name"];
				std::string name=nameValue.GetString();

				Value & npValue= node["np_id"];
				std::string npString=npValue.GetString();
				
				Value & groupNameValue= node["group_name"];
				std::string groupName;
				int groupID=0;
				if(groupNameValue.IsNull()){
					groupName="";
				}else{
					groupName=groupNameValue.GetString();

					if(postingCode==400 || postingCode==500){
						Value & gidValue= node["group_id"];
						std::string groupString=gidValue.GetString();
						groupID=atoi(groupString.c_str());
					}
					

				}
				
			
				
				
				int score;
				Value & bpointValue= node["battle_point"];
				std::string bpointString=bpointValue.GetString();
				int bpoint=atof(bpointString.c_str())*100;

				Value & pointValue= node["point"];
				std::string pointString=pointValue.GetString();
				int point=atof(pointString.c_str());

				if(postingCode==500){
					score=bpoint;
				}else if(postingCode==400) {
					score=point;
				}else if(postingCode==600){
					score=point;
				}else if(postingCode==700){
					score=bpoint;
				}else if(postingCode==800){
					score=point;
				}else if(postingCode==900){
					score=bpoint;
				}


				CCScrewItem* screwItem=CCScrewItem::create();
				if(i%2!=0){
					CCSprite* line_bg=CCSprite::createWithSpriteFrameName("ranking_line.png");
					line_bg->setAnchorPoint(ccp(0,0));
					screwItem->addChild(line_bg);
				}

				if(i==1){
					CCSprite* num_icon;
					if(postingCode==500){
						num_icon=CCSprite::createWithSpriteFrameName("num_top3.png");
					}else if(postingCode==400) {
						num_icon=CCSprite::createWithSpriteFrameName("num_top2.png");
					}else{
						num_icon=CCSprite::createWithSpriteFrameName("num_top4.png");
					}
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else if(i==2){
					CCSprite* num_icon=CCSprite::createWithSpriteFrameName("num_2.png");
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else if(i==3){
					CCSprite* num_icon=CCSprite::createWithSpriteFrameName("num_3.png");
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else{
					CCLabelTTF* numLabel=CCLabelTTF::create(CCString::createWithFormat("%d",i)->getCString(),"微软雅黑",12);
					numLabel->setPosition(ccp(13,13));
					screwItem->addChild(numLabel);
				}
		
				if(strcmp(npString.c_str(),"")!=0){

					CCSprite* nameplate=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s.png",npString.c_str())->getCString());
					nameplate->setAnchorPoint(ccp(0.5f,0));
					nameplate->setPosition(ccp(106,0));
					screwItem->addChild(nameplate);

					CCStrokeLabel* user_nameStr;
					CCLabelTTF* user_name=CCLabelTTF::create(name.c_str(),FONT_TYPE,12);
					if(MemberID){
						if(MemberID==memberID){
							user_nameStr = CCStrokeLabel::create(user_name,ccc3(0,0,0),ccc3(236,162,8),1.0f);
						}else{
							user_nameStr = CCStrokeLabel::create(user_name,ccc3(0,0,0),ccc3(255,255,255),1.0f);
						}
					}else{
						user_nameStr = CCStrokeLabel::create(user_name,ccc3(0,0,0),ccc3(255,255,255),1.0f);
					}

					user_nameStr->setPosition(ccp(106,13));
					screwItem->addChild(user_nameStr);

					bool isBlink=false;
					const char* bannerPath;
					if(strcmp(npString.c_str(),"np000")==0 ||
						strcmp(npString.c_str(),"np001")==0 ||
						point>=99999){
						bannerPath="banner_black";
						isBlink=true;
					}else if(point>=48000){
						bannerPath="banner_blue";
						isBlink=true;
					}else if(point>=24000){
						bannerPath="banner_red";
						isBlink=true;
					}else if(point>=16000){
						bannerPath="banner_gold";
						isBlink=true;
					}else if(point>=12000){
						bannerPath="banner_gold";
					}else if(point>=6000){
						bannerPath="banner_silver";
					}else{
						bannerPath="banner_green";
					}

					CCSprite* nameBaner=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s.png",bannerPath)->getCString());
					nameBaner->setAnchorPoint(ccp(0.5f,0));
					nameBaner->setPosition(ccp(106,0));
					screwItem->addChild(nameBaner);

					if(isBlink){

						CCSprite* blink=CCSprite::createWithSpriteFrameName("banner_blink5.png");
						blink->setAnchorPoint(ccp(0.5f,0));
						blink->setPosition(ccp(106,0));
						
						screwItem->addChild(blink);


						CCArray* tempArray= CCArray::create();

						int i=1;

						CCArray* list=CCArray::create();
						while (i<7)
						{
							CCString* path=CCString::createWithFormat("banner_blink%d.png",i);
							CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(path->getCString());
							tempArray->addObject(frame);
							
							
							i+=1;
						}

						CCAnimation* tempAnimation= CCAnimation::createWithSpriteFrames(tempArray, 0.1f);
						CCAction* tempAction=CCAnimate::create(tempAnimation);
						list->addObject(tempAction);
						CCDelayTime* delay=CCDelayTime::create(1.0f);
						list->addObject(delay);

						blink->runAction(CCRepeatForever::create(CCSequence::create(list)));
					}

				}else{
					CCLabelTTF* user_name=CCLabelTTF::create(name.c_str(),FONT_TYPE,12);

					if(MemberID){
						if(MemberID==memberID){
							user_name->setColor(ccc3(236,162,8));
						}
					}

					user_name->setAnchorPoint(ccp(0.5f,0.5));
					user_name->setPosition(ccp(106,13));
					screwItem->addChild(user_name);

				}



				CCLabelTTF* user_score=CCLabelTTF::create(CCString::createWithFormat("%d",score)->getCString(),FONT_TYPE,12);

				user_score->setAnchorPoint(ccp(0.5f,0));
				user_score->setPosition(ccp(214,5));
				screwItem->addChild(user_score);

				
				if(groupID!=0){
					CCLabelTTF* group_Name=CCLabelTTF::create(CCString::createWithFormat("%s",groupName.c_str())->getCString(),FONT_TYPE,12);

					CCMenuItemLabel* item=CCMenuItemLabel::create(group_Name, this, menu_selector(RakingLayer::onSelectGroupBtn));
					
					CCMenu* pMenu = CCMenu::create(item, NULL);
					pMenu ->setPosition(ccp(304,5));
					item ->setAnchorPoint(ccp(0.5f,0));
					item->setTag(groupID);
					pMenu->setTouchPriority(1);
					screwItem->addChild(pMenu);
					screwItem->setTag(groupID); 
					
				}else if(strcmp(groupName.c_str(),"")!=0 ){
					CCLabelTTF* group_Name=CCLabelTTF::create(CCString::createWithFormat("%s",groupName.c_str())->getCString(),FONT_TYPE,12);

					group_Name->setAnchorPoint(ccp(0.5f,0));
					group_Name->setPosition(ccp(304,5));
					screwItem->addChild(group_Name);


				}

				int row=i;
				screwItem->setPosition(ccp(0,-row*26+26));
				screwItem->setAnchorPoint(ccp(0,0));

				_screwLayer1->addChild(screwItem,10);

				countRow++;

			}
		}
		_screwLayer1->totalRow=countRow;

	}


}  


void RakingLayer::onHttpRequestCompleted3(CCNode *sender ,void *data) {  

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
	int countRow=0;
	if(arr.IsArray()){

		for (SizeType i = 0; i < arr.Size(); i++)  {


			Value & node=arr[i];

			if(i==0){
				//排位
				Value & sortValue= node["newid"];
				int sortNO=sortValue.GetInt();


				if(sortNO==0){
					CCDictionary *strings = CCDictionary::createWithContentsOfFile("Element/strings.xml");  
					const char *reply = ((CCString*)strings->objectForKey("GroupNull"))->m_sString.c_str();   
					rankingDetail=CCLabelTTF::create(CCString::createWithFormat("%s",reply)->getCString(),FONT_TYPE,12);
					rankingDetail->setAnchorPoint(ccp(0,0.5f));
					rankingDetail->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2 +20,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
					ranking_layer->addChild(rankingDetail,500);

				}else{
					CCDictionary *strings = CCDictionary::createWithContentsOfFile("Element/strings.xml");  
					const char *reply = ((CCString*)strings->objectForKey("GroupDetail"))->m_sString.c_str();  
					const char *reply2 = ((CCString*)strings->objectForKey("RankingDetail2"))->m_sString.c_str();  
					rankingDetail=CCLabelTTF::create(CCString::createWithFormat("%s %d %s",reply,sortNO,reply2)->getCString(),FONT_TYPE,12);
					rankingDetail->setAnchorPoint(ccp(0,0.5f));
					rankingDetail->setPosition(ccp(ranking_bg->getPositionX()-ranking_bg->getContentSize().width/2 +20,ranking_bg->getPositionY()-ranking_bg->getContentSize().height/2+14));
					ranking_layer->addChild(rankingDetail,500);
				}

			}else{


				Value & idValue= node["id"];
				std::string groupString=idValue.GetString();
				int groupID=atoi(groupString.c_str());


				Value & groupNameValue= node["group_name"];
				std::string groupName=groupNameValue.GetString();
				


				
				Value & pointValue= node["totalPoint"];
				std::string pointString=pointValue.GetString();
				int point;
				if(postingCode==700){
					point=atof(pointString.c_str())*100;
				}else{
					point=atof(pointString.c_str());
				}
				

				CCScrewItem* screwItem=CCScrewItem::create();
				if(i%2!=0){
					CCSprite* line_bg=CCSprite::createWithSpriteFrameName("ranking_line.png");
					line_bg->setAnchorPoint(ccp(0,0));
					screwItem->addChild(line_bg);
				}

				if(i==1){
					CCSprite* num_icon;
					
					num_icon=CCSprite::createWithSpriteFrameName("num_top5.png");
					
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else if(i==2){
					CCSprite* num_icon=CCSprite::createWithSpriteFrameName("num_2.png");
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else if(i==3){
					CCSprite* num_icon=CCSprite::createWithSpriteFrameName("num_3.png");
					num_icon->setAnchorPoint(ccp(0,0));
					num_icon->setPosition(ccp(1,1));
					screwItem->addChild(num_icon);
				}else{
					CCLabelTTF* numLabel=CCLabelTTF::create(CCString::createWithFormat("%d",i)->getCString(),"微软雅黑",12);
					numLabel->setPosition(ccp(13,13));
					screwItem->addChild(numLabel);
				}


				CCLabelTTF* group_name=CCLabelTTF::create(groupName.c_str(),FONT_TYPE,12);
				
				if(GroupID){
					if(GroupID==groupID){
						group_name->setColor(ccc3(236,162,8));
					}
				}
				CCMenuItemLabel* item=CCMenuItemLabel::create(group_name, this, menu_selector(RakingLayer::onSelectGroupBtn));
				item->setTag(groupID); 

				CCMenu* pMenu = CCMenu::create(item, NULL);
				
				pMenu ->setPosition(ccp(108,5));
				item ->setAnchorPoint(ccp(0.5f,0));
				screwItem->addChild(pMenu);
				

				
				CCLabelTTF* user_score=CCLabelTTF::create(CCString::createWithFormat("%d",point)->getCString(),FONT_TYPE,12);

				user_score->setAnchorPoint(ccp(0.5f,0));
				user_score->setPosition(ccp(242,5));
				screwItem->addChild(user_score);

				

				int row=i;
				screwItem->setPosition(ccp(0,-row*26+26));
				screwItem->setAnchorPoint(ccp(0,0));

				_screwLayer1->addChild(screwItem,10);

				countRow++;

			}
		}
		_screwLayer1->totalRow=countRow;

	}


}  

void RakingLayer::onSelectGroupBtn(CCObject* sender){
	return;
	CCMenuItemLabel* item=(CCMenuItemLabel*) sender;
	

	if(_screwLayer1){
		_screwLayer1->removeAllChildren();
		_screwLayer1->setPositionY(154);
	}


	if(rankingDetail){
		rankingDetail->removeFromParent();
		rankingDetail=NULL;
	}

	if(ranking_title){
		CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ranking_title2.png"); 
		ranking_title->setDisplayFrame(frame);
		ranking_title->setPosition(ccp(ranking_bg->getPositionX()-96,ranking_bg->getPositionY()+ranking_bg->getContentSize().height/2-16));
	}

	if(!isPosting){

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
		std::string codeFinal;
		if(postingCode==600 || postingCode==400){
			postingCode=800;
			codeFinal=CCString::createWithFormat("code=800&group_id=%d",item->getTag())->getCString();;
		}else if(postingCode==700 || postingCode==500){
			postingCode=900;
			codeFinal=CCString::createWithFormat("code=900&group_id=%d",item->getTag())->getCString();;

		}
		

		std::string url=SERVER"nsk/rank.php?"+codeFinal;
		request->setUrl(url.c_str());  
		request->setRequestType(CCHttpRequest::kHttpGet);  
		
		request->setResponseCallback(this, callfuncND_selector(RakingLayer::onHttpRequestCompleted2));  
		

		request->setTag("Post_My_Data");  
		cocos2d::extension::CCHttpClient::getInstance()->send(request);  
		request->release();  
	}

	
}
