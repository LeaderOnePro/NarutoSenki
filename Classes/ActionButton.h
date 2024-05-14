#pragma once

#include "cocos2d.h"
#include "Defines.h"

USING_NS_CC;

class HudLayer;

class ActionButton : public CCSprite,public CCTouchDelegate{
public:
	ActionButton(void);
	~ActionButton(void);

	int						_clickNum;
	float					_clickTime;
	CCProgressTimer*		markSprite;
	CCSprite*				ougismarkSprite;
	CCSprite*		proressmarkSprite;
	CCSprite*		proressblinkSprite ;
	CCSprite*		progressPointSprite;
	CCSprite*       proressblinkMask;
	const char*				_cost;
	CCClippingNode* clipper;
	bool					_isLock;

	bool					_isColdChanged;

	virtual bool			init(const char *szImage);
	static ActionButton*	create(const char *szImage);
	virtual bool			isCanClick();
	CCRect					getRect();

	void					click();
	void					setMarkSprite(const char* mark);
	void					setOugisMark();
	void					setProgressMark();
	void					updateProgressMark();

	CCSprite*		gearSign ;
	CCLabelBMFont*			cdLabel;

	CCLabelBMFont*			lockLabel1;
	CCLabelBMFont*			lockLabel2;

	bool					_isMarkVisable;

	CC_SYNTHESIZE(abType,_abType,ABType);
	gearType				_gearType;
	
	CC_SYNTHESIZE_RETAIN(CCString*,_coldDown,CD);
	CC_SYNTHESIZE(bool,_isDoubleSkill,DoubleSkill);
	CC_SYNTHESIZE_RETAIN(CCString*,_timeCout,TimeCout);
	

	void			setLock();
	void			unLock();
	void			clearOugisMark();
	void			setGearType(int tmpGearType);

	CC_SYNTHESIZE_RETAIN(CCAction*,_freezeAction,FreezeAction);
	//CC_SYNTHESIZE_RETAIN(CCProgressTimer*,markSprite,MarkSprite);
	CC_SYNTHESIZE(HudLayer*,_delegate,Delegate);
	virtual void	beganAnimation(bool isLock = false);

	

protected:
	

	void			updateCDLabel(float dt);

	virtual void	onEnter();
	virtual void	onExit();
	virtual bool	ccTouchBegan(CCTouch* touch,CCEvent* event);
	virtual void	ccTouchEnded(CCTouch* touch,CCEvent* event);

	
	void		    createFreezeAnimation();
	void			clearClick();


	bool			containsTouchLocation(CCTouch* touch);

	

};

