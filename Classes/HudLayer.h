#pragma once
#include "cocos2d.h"
#include "Defines.h"
#include "JoyStick.h"
#include "GameLayer.h"
#include "Characters.h"
#include "Defines.h"
#include "ActionButton.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class GameLayer;


class MiniIcon: public CCSprite{
public: 
	MiniIcon(void);
	~MiniIcon();

	CC_SYNTHESIZE(unsigned int,_charNO,CharNO);
	static MiniIcon*	create(const char *szImage,bool isNotification);
	void	updateMap(CCObject* sender);
	void	updateState();

	void	updatePosition(CCPoint location);
	virtual bool init(const char *szImage,bool isNotification );

	CCLayer*	_delegate;

};





class HudLayer : public CCLayer{
public:
	HudLayer(void);
	~HudLayer(void);


	void			updateSQL(float dt);
	bool			isOpenSQL;

	CCSprite*			status_bar;
	CCSprite*			status_hpbar;
	CCSprite*			status_hpMark;
	CCProgressTimer*	status_expbar;
	
	ActionButton*		nAttackButton;
	ActionButton*		skill1Button;
    ActionButton*		skill2Button;
	ActionButton*		skill3Button;
	ActionButton*		skill4Button;
	ActionButton*		skill5Button;

	
	ActionButton*		item1Button;
		CC_SYNTHESIZE_RETAIN(ActionButton*,item2Button,Item2Button );
		CC_SYNTHESIZE_RETAIN(ActionButton*,item3Button,Item3Button );
		CC_SYNTHESIZE_RETAIN(ActionButton*,item4Button,Item4Button );
		/*ActionButton*		item2Button;
		ActionButton*		item3Button;
		ActionButton*		item4Button;*/
	ActionButton*		gear1Button;
	ActionButton*		gear2Button;
	ActionButton*		gear3Button;
	CCSprite*			reportSPCSprite;

	CCSprite* reportSprite;
	

	CC_SYNTHESIZE(CCArray*,_reportListArray ,ReportListArray);
	int _buffCount;

	CCLabelBMFont*		hpLabel;
	CCLabelBMFont*		expLabel;


	CCLabelBMFont*		coinLabel;
	CCLabelBMFont*		killLabel;
	CCLabelBMFont*		deadLabel;

	CCLabelBMFont*		KonoLabel;
	CCLabelBMFont*		AkaLabel;


    CCLabelBMFont*		gameClock;
	CCMenu*				pauseNenu;
	CCMenu*				gearMenu;
	CC_SYNTHESIZE(CCArray*,_towerIconArray,TowerIconArray);

	GameLayer*			_delegate;
	CCLayer*			miniLayer;
	JoyStick*			_joyStick;

	CCTexture2D* 		texUI;
	CCSpriteBatchNode*	uiBatch;

	void	setHPLose(float percent);
	void	setCKRLose(bool isCRK2);
	void	setEXPLose(float percent);

	void	setDelegate(GameLayer* layer);
	void	initHeroInterface();
	void	attackButtonClick(abType type);
	void	gearButtonClick(gearType type);
	void	attackButtonRelease();
	void	pauseButtonClick(CCObject* sender);
	void	gearButtonClick(CCObject* sender);
	void	setReport(const char* name1, const char* name2,CCString* killNum);
	void	setReportCache();
	void    setBuffDisplay(const char* buffName,float buffStayTime);
	void	clearSPCReport();
	void	clearBuffDisplay(CCNode* sender);
	
	void	updateBuffDisplay(float dt);
	void	updateBuffDisplay2(float dt);
	void	stopSPCReport();
	void	updateSPCReprot(float dt);
	void	setTowerState(unsigned int charNO);
	void	onKaichang();

	CCLabelBMFont* bcdLabel1;
	CCLabelBMFont* bcdLabel2;
	
	void JoyStickRelease();
	void JoyStickUpdate(CCPoint direction);
	CCSprite* Kaichang;

	CCSprite* createReport(const char* name1, const char* name2,float &length);
	CCSprite* createSPCReport(const char* killNum,int num);

	

	virtual bool	getSkillFinish();
	virtual bool    getOugisEnable(bool isCKR2);
	
	CCLayer* ougisLayer;
	void setOugis(CCString* character,CCString* group);
	void removeOugis(CCNode* sender);

	bool	_isAllButtonLocked;
	
	void addMapIcon();

	void   costCKR(int value,bool isCKR2);
	void   setCoin(const char* value);
	bool   offCoin(const char* value);

	
	virtual bool init();
	
	CREATE_FUNC(HudLayer);

	void updateGears();
	void initGearButton();

protected:
	virtual void	onEnter();
	virtual void	onExit();
  
};

