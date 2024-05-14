#include "cocos2d.h"
#include "StartMenu.h"
#include "MyUtils/KTools.h"
#include "SimpleAudioEngine.h"
#include "Defines.h"
class GameScene :  public cocos2d::CCScene{
public:
	GameScene(void);
	~GameScene(void);
	
    virtual bool init();  

    CREATE_FUNC(GameScene);
	CCLayer* introLayer;

	CC_SYNTHESIZE(StartMenu*,_menuLayer,StartMenu);
	void onPlayEffect2();
	void onFinish();
	void onLogo();
	void onPush(CCObject* sender);

	CCMenu* logoMenu;
	CCMenu* pushMenu;
	void onLogoClick(CCObject* sender);

};

