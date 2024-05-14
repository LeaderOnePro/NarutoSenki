#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"




USING_NS_CC;


class GameLayer;
class PauseLayer : public CCLayer{

public:
	PauseLayer(void);
	~PauseLayer(void);

	bool	init(CCRenderTexture* snapshoot);
	static PauseLayer*	create(CCRenderTexture* snapshoot);
	CCMenu* pauseMenu;
	CCMenu* soundMenu;
	CCMenu* preMenu;
	CCLayer* exitLayer;
	CCMenuItem* bgm_btn;
	CCMenuItem* voice_btn;
	CCMenuItem* pre_btn;
private:
	void	onResume(CCObject* sender);
	void	onBackToMenu(CCObject* sender);
	void	onLeft(CCObject* sender);
	void	onCancel(CCObject* sender);
	void    onBGM(CCObject* sender);
	void    onPreload(CCObject* sender);
	void    onVoice(CCObject* sender);

	CC_SYNTHESIZE(GameLayer*,_delegate,Delegate);



};

