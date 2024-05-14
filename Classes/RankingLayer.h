#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Defines.h"
#include "cocos-ext.h"
#include "MyUtils/CCScrewLayer.h"
#include "MyUtils/CCStrokeLabel.h"

USING_NS_CC;

class NetworkLayer;
using namespace rapidjson; 

class RakingLayer : public CCLayer{

public:
	RakingLayer(void);
	~RakingLayer(void);

	bool	init();


	CREATE_FUNC(RakingLayer);

	CCMenuItem* day_btn;
	CCMenuItem* week_btn;
	CCMenuItem* month_btn;


	CCMenuItem* battlePoint_btn;
	CCMenuItem* JifenPoint_btn;

	CCMenuItem* side0_btn;
	CCMenuItem* side1_btn;
	CCMenuItem* side2_btn;
	CCMenuItem* side3_btn;

	CCMenu* order_menu;
	CCSprite* ranking_title;
	CCLabelTTF* rankingDetail;

	CCLayer* ranking_layer;
	CCSprite* ranking_bg;
	CCScrewLayer* _screwLayer1;


	CCSpriteBatchNode* rankingBatch;

	bool isPosting;
	

	CCSprite* refreshBtn;
	CC_SYNTHESIZE(NetworkLayer*,_delegate,Delegate);

	void postRequest(int code,CCString* useChar=NULL);

	bool				isMemberSelect;
	bool				isGroupSelect;
	int postingCode;

private:
	void onHttpRequestCompleted(CCNode *sender ,void *data);
	void onHttpRequestCompleted2(CCNode *sender ,void *data);
	void onHttpRequestCompleted3(CCNode *sender ,void *data);

	
	void produceRanking(int type);

	void				onDayBtn(CCObject* sender);
	void				onWeekBtn(CCObject* sender);
	void				onMonthBtn(CCObject* sender);

	void				onBattleBtn(CCObject* sender);
	void				onJifenBtn(CCObject* sender);
	void				onSelectGroupBtn(CCObject* sender);

	void				onSideBar1(CCObject* sender);
	void				onSideBar2(CCObject* sender);
	void				onSideBar3(CCObject* sender);
	void				onSideBar0(CCObject* sender);
	void				onCancel(CCObject* sender);

	
	void				makeCharList();

};



class RankCharButton : public CCSprite, public CCTouchDelegate{

public:
	RankCharButton(void);
	~RankCharButton(void);


	virtual bool		init(const char *szImage);
	static RankCharButton*	create(const char *szImage);

	CCRect				getRect();
	void				setBtnType(CCString* buttonChar);

	CC_SYNTHESIZE(CCString*,_btnType,btnType);

	CC_SYNTHESIZE(RakingLayer*,_delegate,Delegate);


protected:

	virtual void	onEnter();
	virtual void	onExit();
	virtual bool	ccTouchBegan(CCTouch* touch,CCEvent* event);
	virtual void    ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void	ccTouchEnded(CCTouch* touch,CCEvent* event);

	bool			containsTouchLocation(CCTouch* touch);


};