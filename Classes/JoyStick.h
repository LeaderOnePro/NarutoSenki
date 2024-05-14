#pragma once
#include "cocos2d.h"
#include "Defines.h"


USING_NS_CC;

class HudLayer;

class JoyStick : public CCSprite ,public CCTouchDelegate{
public:
	JoyStick(void);
	~JoyStick(void);


	CCPoint		    _direction;
	CCSprite*		_joyStickControl;
	CCPoint			 _defaultPotion;
	
	virtual	bool	init();
	virtual void	onEnter();
	virtual void	onExit();


	void			keyUpdate(float direction);
	void			keyEnded(float direction);

	CREATE_FUNC(JoyStick);
	CC_SYNTHESIZE(HudLayer*,_delegate,Delegate);


protected:



	virtual bool	ccTouchBegan(CCTouch* touch,CCEvent* event);
	virtual void    ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void	ccTouchEnded(CCTouch* touch,CCEvent* event);

	void updateDirectionForTouchLocation(CCTouch* touch);
	void updateJoyStick(float distance,CCPoint direction);
	
};

