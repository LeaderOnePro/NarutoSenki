#pragma once
#include "Defines.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "SelectLayer.h"
#include "NetworkLayer.h"
#include "CreditsLayer.h"

#include "cocos-ext.h"
#include "MyUtils/KTools.h"
#include "MyUtils/CCStrokeLabel.h"
#include "MyUtils/CCScrewLayer.h"


USING_NS_CC;
using namespace rapidjson; 


// declare menuButton 
enum btnType{
	Network,
	Training,
	Exit,
	Credits,
	HardCore
};

class StartMenu;

class MenuButton : public CCSprite, public CCTouchDelegate{

public:
	MenuButton(void);
	~MenuButton(void);

	bool				_isTop;
	bool				_isBottom;
	btnType				_btnType;

	virtual bool		init(const char *szImage);
	static MenuButton*	create(const char *szImage);
	
	CCRect				getRect();
	
	
	void				setBtnType(btnType type);
	btnType 			getBtnType();
	void				playSound();

	float			prePosY;
	


	CC_SYNTHESIZE(StartMenu*,_delegate,Delegate);



	
	
protected:

	virtual void	onEnter();
	virtual void	onExit();
	virtual bool	ccTouchBegan(CCTouch* touch,CCEvent* event);
	virtual void    ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void	ccTouchEnded(CCTouch* touch,CCEvent* event);

	bool			containsTouchLocation(CCTouch* touch);

};







class StartMenu : public CCLayer{

public:
	StartMenu(void);
	~StartMenu(void);



	bool				init();
	void				onTrainingCallBack();
	void				onHardCoreOn(CCObject* sender);
	void				onHardCoreOff(CCObject* sender);
	void				onHardLayerCallBack();
	void				onHardCoreCallBack();
	void				onNormalCallBack(CCObject* sender);
	void				onCreditsCallBack();
	void				onExitCallBack();
	void				onNewsBtn(CCObject* sender);
	void				onLoginBtn(CCObject* sender);
	void				onTasksBtn(CCObject* sender);
	void				onProfileBtn(CCObject* sender);

	void				onIterfaceClose(CCObject* sender);
	void				onInputBoxClose(CCObject* sender);


	void				onLoginOn(CCObject* sender);
	void				onLoginCancel(CCObject* sender);
	void				setOfferWall();
	void				setProfile();
	void				setGroup();
	
	void				onGroupBtn(CCObject* sender);
	void				onSearchBtn(CCObject* sender);
	void				onCreateBtn(CCObject* sender);
	void				onCreateComfirm(CCObject* sender);
	void				onSelectGroupBtn(CCObject* sender);
	void				onJoinGroup(CCObject* sender);
	void				onKickBtn(CCObject* sender);
	void				onQuitBtn(CCObject* sender);
	void				onJoinComfirm(CCObject* sender);
	void				onDissolveBtn(CCObject* sender);
	void				onQuitComfirm(CCObject* sender);
	void				onKickComfirm(CCObject* sender);

	void				onGPWComfirm(CCObject* sender);
	void				onLockBtn(CCObject* sender);
	void				onNoticeBtn(CCObject* sender);
	void				onNoticeComfirm(CCObject* sender);

	void				onNamePlate(CCObject* sender);
	void				onNamePlateClick(CCObject* sender);
	void				onNamePlateComfrim(CCObject* sender);
	void				scrollMenu(int posY);
	CCSprite*			menuText;

	MenuButton* hardCore_btn;

	CCLayer* hardCoreLayer;

	
	CCLayer* profile_layer;
	CCLayer* group_layer;
	
	CCLayer* input_layer;

	cocos2d::extension::CCEditBox* usernameInput;
	cocos2d::extension::CCEditBox* pwInput;
	cocos2d::extension::CCEditBox* searchInput;
	cocos2d::extension::CCEditBox* nameInput;
	cocos2d::extension::CCEditBox* gpwInput;

	static const int	_pos01=48;
	static const int	_pos02=92;
	static const int	_pos03=150;

	bool  isClockwise;
	bool  isDrag;
	bool  isNewAviable;
	bool  isBondAviable;	

	bool isTasking;
	bool isPosting;

	int leaderID;

	CCMenuItem*  lock_btn;
	bool isLock;
	 CCLabelTTF* notice_label;

	CCLabelTTF* totalGroupNum;
	int maxGroupNum;

	CCSprite* refreshBtn;
	CCMenuItem* task_btn;
	CCMenuItem* login_btn;
	void setNotice();

	CCLayer* notice_layer;
	void update(float dt);
	CCLabelTTF* noticeLabel;

	CCScrewLayer* _screwLayer1;


	virtual void   keyBackClicked();

	CC_SYNTHESIZE_RETAIN(CCArray*,_menu_array, Menus);
	CREATE_FUNC(StartMenu);

    
	void onLoginRequestCompleted(CCNode *sender ,void *data);
	void onGroupRequestCompleted(CCNode *sender ,void *data);
	void onGroupManageRequestCompleted(CCNode *sender ,void *data);
	void onJoinRequestCompleted(CCNode *sender ,void *data);
	void onSeachRequestCompleted(CCNode *sender ,void *data);
	void onCreateRequestCompleted(CCNode *sender ,void *data);
	void onQuitGroupRequestCompleted(CCNode *sender ,void *data);
	void onNoticeRequestCompleted(CCNode *sender ,void *data);
	void onProfileRequestCompleted(CCNode *sender ,void *data);
	void onGPWRequestCompleted(CCNode *sender ,void *data);
	void onNamePlateRequestCompleted(CCNode *sender ,void *data);

protected:
	void onEnter();
	void onExit();


};

