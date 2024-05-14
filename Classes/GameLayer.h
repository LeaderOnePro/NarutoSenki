#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Defines.h"
#include "cocos-ext.h"
#include "PauseLayer.h"
#include "GearLayer.h"
#include "GameOver.h"

#include <vector>


#if (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID) 
#include "../cocos2dx/platform/android/jni/JniHelper.h"  
#endif  

USING_NS_CC;




class Hero;
class BGLayer;
class HudLayer;

class GameLayer :public CCLayer{
public:
	GameLayer(void);
	~GameLayer(void);

	CCTMXTiledMap*		currentMap;
	Hero*				currentPlayer;
	CCPoint				spawnPoint;
	
	unsigned int _second;
	unsigned int _minute;
	int randomMap;

	const char* kName;
	const char* aName;
    int kEXPBound;
	int aEXPBound;

	CCArray* Heros;
	bool	_isAttackButtonRelease;
	bool	_isGuardian;
	CCArray* _KonohaFlogArray;
	CCArray* _AkatsukiFlogArray;
	CCArray* _TowerArray;
	CCArray* _CharacterArray;

	
	bool _isShacking;

	int _playNum;
	void checkBackgroundMusic(float dt);


	CC_SYNTHESIZE(HudLayer*,_hudLayer,HudLayer);

	CC_SYNTHESIZE_RETAIN(CCString*,totalKills,TotalKills);
	CC_SYNTHESIZE_RETAIN(CCString*,totalTM,TotalTM);

	CCSpriteBatchNode* skillEffectBatch;
	CCSpriteBatchNode* damageEffectBatch;
	CCSpriteBatchNode* bulletBatch;
	CCSpriteBatchNode* shadowBatch;

	bool isPosting;
	int postTime;

	
		
	bool init();
	void initTileMap();
	void initHeros();
	void initFlogs();
	void initTower();
	void initGard();
	void initEffects();

	//void update(float dt);
	void updateViewPoint(float dt);
	void updateGameTime(float dt);

	void addFlog(float dt);
	void onStart();
	
	void attackButtonClick(abType type);
	void gearButtonClick(gearType type);	
	void attackButtonRelease();
	

	void JoyStickRelease();
	void JoyStickUpdate(CCPoint direction);

	CC_SYNTHESIZE(bool,_isSkillFinish,SkillFinish);
	void checkPost(float dt);
	void checkTower();
	void checkBackgroundMusic();

	void onPause();
	void onGear();
	void onKaichang(float dt);
	void onGameStart(float dt);
	void onGameOver(bool isWin);

	void setHPLose(float percent);
	void setCKRLose(bool isCRK2);

	void setReport(const char* name1, const char* name2,CCString* killNum);
	void clearDoubleClick();
	void resetStatusBar();
	void setCoin(const char* value);
	void removeOugisMark(int type);
	void setOugis(CCNode* sender);
	void removeOugis();
	CCNode* ougisChar;

	CCNode* controlChar;
	
	CCLayer* blend;

	void onLeft();


	bool _isSurrender;

	bool _isOugis2Game;
	bool _isHardCoreGame;
	bool _isRandomChar;


	int zhenying;
	bool _isExiting;

	CREATE_FUNC(GameLayer);
	std::vector<char*> KeyList;
protected:
	void onHttpRequestCompleted(CCNode *sender ,void *data);
	virtual void	onEnter();
	virtual void	onExit();

};

