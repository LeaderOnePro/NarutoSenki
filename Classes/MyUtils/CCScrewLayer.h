#pragma once
#include "cocos2d.h"
USING_NS_CC;  

class CCScrewLayer : public CCLayer{

public:
	CCScrewLayer(void);
	~CCScrewLayer(void);

	float			prePosY;
	virtual	bool	init();
	CREATE_FUNC(CCScrewLayer);
	CC_SYNTHESIZE_RETAIN(CCArray*,itemArray, ItemArray);
	float minY;
	int totalRow;
	int line_height;

protected:

	virtual bool	ccTouchBegan(CCTouch* touch,CCEvent* event);
	virtual void    ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void	ccTouchEnded(CCTouch* touch,CCEvent* event);


	void onEnter();
	void onExit();

};


class CCScrewItem : public CCSprite, public CCTouchDelegate{

public:
	CCScrewItem(void);
	~CCScrewItem(void);
	virtual	bool	init();

	CREATE_FUNC(CCScrewItem);
	CCRect			getRect2();
	CCMenu*      linemenu;
	CC_SYNTHESIZE(CCScrewLayer*,_delegate,Delegate);
	CCSprite*	lockItem;
protected:

	virtual void	onEnter();
	virtual void	onExit();
	virtual bool	ccTouchBegan(CCTouch* touch,CCEvent* event);
	virtual void	ccTouchEnded(CCTouch* touch,CCEvent* event);


	bool			containsTouchLocation(CCTouch* touch);



};



