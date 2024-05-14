#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Defines.h"

USING_NS_CC;

class GameLayer;
class Hero;
class ScrewLayer;


enum gearbtnType{
	buyType,
	sellType
};

class GearLayer : public CCLayer{

public:
	GearLayer(void);
	~GearLayer(void);

	bool	init(CCRenderTexture* snapshoot);
	static GearLayer*	create(CCRenderTexture* snapshoot);
	
	CCLayer* gears_layer;
	CCLayer* currentGear_layer;
	CCLabelBMFont* coinLabel;

	CCSprite* gearDetail;
	CCSprite* gears_bg;

	gearType currentGear;
	void	updatePlayerGear();
	void	updateGearList();

	ScrewLayer* _screwLayer;

private:
	void	onResume(CCObject* sender);
	void	onGearBuy(CCObject* sender);
	
	CC_SYNTHESIZE(GameLayer*,_delegate,Delegate);
	

};





class GearButton : public CCSprite, public CCTouchDelegate{

public:
	GearButton(void);
	~GearButton(void);

	gearType				_gearType;
	gearbtnType  			_btnType;

	virtual bool		init(const char *szImage);
	static GearButton*	create(const char *szImage);

	CCRect				getRect();
	void				setBtnType(gearType type,gearbtnType type2,bool isBuyed);
	gearType 			getBtnType();
	void				playSound();

	bool				_isBuyed;

	CC_SYNTHESIZE(GearLayer*,_delegate,Delegate);

	CCSprite* soIcon;

protected:

	virtual void	onEnter();
	virtual void	onExit();
	virtual bool	ccTouchBegan(CCTouch* touch,CCEvent* event);
	virtual void    ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void	ccTouchEnded(CCTouch* touch,CCEvent* event);

	bool			containsTouchLocation(CCTouch* touch);



};



class ScrewLayer : public CCLayer{

public:
	ScrewLayer(void);
	~ScrewLayer(void);

	float			prePosY;
	virtual	bool	init();
	CREATE_FUNC(ScrewLayer);

	CC_SYNTHESIZE(GearLayer*,_delegate,Delegate);

	CCSprite* screwBar;

	int totalRow;
	int gearNum;
	CC_SYNTHESIZE_RETAIN(CCArray*,_gearArray,GearArray);

protected:

	virtual bool	ccTouchBegan(CCTouch* touch,CCEvent* event);
	virtual void    ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void	ccTouchEnded(CCTouch* touch,CCEvent* event);


	void onEnter();
	void onExit();


};