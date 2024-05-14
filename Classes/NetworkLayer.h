#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
#include "LoadLayer.h"
#include "SkillLayer.h"
#include "RankingLayer.h"
USING_NS_CC;

class NetworkLayer : public CCLayer{

public:
	NetworkLayer(void);
	~NetworkLayer(void);

	virtual bool		init();
	static NetworkLayer*	create();
	void    setSelected(CCObject* sender);

	const char* _selectHero;
	const char* _playerSelect;
	const char* _com1Select;
	const char* _com2Select;

	bool isPosting;
	CCSprite* refreshBtn;
	
	
	CCLayer* _teamSelector;
	
	CC_SYNTHESIZE_RETAIN(CCSprite*,_comSelector1,ComSelector1);
	CC_SYNTHESIZE_RETAIN(CCSprite*,_comLabel1,ComLabel1);
	

	CC_SYNTHESIZE_RETAIN(CCSprite*,_comSelector2,ComSelector2);
	CC_SYNTHESIZE_RETAIN(CCSprite*,_comLabel2,ComLabel2);

	CCArray* selectArray;

	CC_SYNTHESIZE_RETAIN(CCLayer*,_pageLayer1,Page1);
	CC_SYNTHESIZE_RETAIN(CCLayer*,_pageLayer2,Page2);
	CC_SYNTHESIZE_RETAIN(CCLayer*,_pageLayer3,Page3);


	CCMenuItemSprite* page1_btn;
	CCMenuItemSprite* page2_btn;
	CCMenuItemSprite* page3_btn;

	void  onPage1Btn(CCObject* sender);
	void  onPage2Btn(CCObject* sender);
	void  onPage3Btn(CCObject* sender);

	CC_SYNTHESIZE_RETAIN(CCArray*,_selectList,SelectList);
	CCMenu*  page_menu;

	bool isStart;
	bool SaveError;
	bool _isHardCoreMode;
	bool _isRandomChar;
	

	CC_SYNTHESIZE_RETAIN(CCSprite*,_heroHalf,HeroHalf);
	CC_SYNTHESIZE_RETAIN(CCSprite*,_heroName,HeroName);
	CC_SYNTHESIZE_RETAIN(CCSprite*,_selectImg,SelectImg);

	virtual void keyBackClicked();

private:
	void	onRankingBtn(CCObject* sender);
	void	onQuestBtn(CCObject* sender);
	void	onGameStart(CCObject* sender);
	void    onSkillMenu(CCObject* sender);
	void	onError(CCObject* sender);
	void	onBackToMenu(CCObject* sender);
	void	onListRequestCompleted(CCNode *sender ,void *data);
	
};

