#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "LoadLayer.h"
#include "SkillLayer.h"

USING_NS_CC;



class SelectLayer : public CCLayer{

public:
	SelectLayer(void);
	~SelectLayer(void);

	virtual bool		init();
	static SelectLayer*	create();
	void    setSelected(CCObject* sender);

	const char* _selectHero;
	const char* _playerSelect;
	
	
	CCArray* selectArray;

	bool isStart;
	bool SaveError;
	bool _isHardCoreMode;
	int num2;
	CC_SYNTHESIZE_RETAIN(CCSprite*,_heroHalf,HeroHalf);
	CC_SYNTHESIZE_RETAIN(CCSprite*,_heroName,HeroName);
	CC_SYNTHESIZE_RETAIN(CCSprite*,_selectImg,SelectImg);

	virtual void keyBackClicked();

private:
	void	onGameStart(CCObject* sender);
	void    onSkillMenu(CCObject* sender);
	void	onError(CCObject* sender);
	void	onBackToMenu(CCObject* sender);
};



