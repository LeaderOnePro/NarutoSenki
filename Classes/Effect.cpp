#include "Effect.h"
#include "ActionManager.h"
using namespace CocosDenshion;

Effect::Effect(void)
{
}


Effect::~Effect(void)
{
}


bool Effect::init(const char *szImage,CCObject* Attacker){
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCSprite::init());

		at=(ActionManager*) Attacker;

		if(strcmp(szImage,"n_hit")==0 || 
			strcmp(szImage,"b_hit")==0 ){
				this->initWithSpriteFrameName("red_damge_01.png");
				this->setAnchorPoint(ccp(0.5f,0));
				this->setScale(0.6f);
				float randomY=rand()%16;
				float randomX=rand()%4;
				this->setPosition(ccp(at->getPositionX()+randomX,at->getPositionY()+randomY));
				CCAction* effectAction=this->createEffectAnimation("red_damge_",4,14,false);
				this->runAction(effectAction);
		}else if(strcmp(szImage,"l_hit")==0 || 
			strcmp(szImage,"f_hit")==0 || 
			strcmp(szImage,"f2_hit")==0 || 
			strcmp(szImage,"c_hit")==0 || 
			strcmp(szImage,"o_hit")==0 || 
			strcmp(szImage,"o2_hit")==0 ||
			strcmp(szImage,"ob_hit")==0 ||
			strcmp(szImage,"ab_hit")==0 || 
			strcmp(szImage,"ac_hit")==0 ||
			strcmp(szImage,"ct_hit")==0 ||
			strcmp(szImage,"ts_hit")==0 ||
			strcmp(szImage,"s_hit")==0 
			){
				this->setScale(0.8f);
				this->initWithSpriteFrameName("red_damge_01.png");
				this->setAnchorPoint(ccp(0.5f,0));
				this->setPosition(ccp(at->getPositionX(),at->getPositionY()));
				CCAction* effectAction=this->createEffectAnimation("red_damge_",4,14,false);
				this->runAction(effectAction);
		}else if(strcmp(szImage,"bl_hit")==0 || 
			strcmp(szImage,"bc_hit")==0 || 
			strcmp(szImage,"bf_hit")==0 ||
			strcmp(szImage,"sl_hit")==0
			){
				this->initWithSpriteFrameName("blue_damge_01.png");
				//this->setAnchorPoint(ccp(0.5f,0));
				this->setScale(0.6f);
				int randomInt=rand()%30+10;
				this->setRotation(randomInt);
				this->setPosition(ccp(at->getPositionX(),at->getPositionY()+at->getContentSize().height/2));
				CCAction* effectAction=this->createEffectAnimation("blue_damge_",4,14,false);
				this->runAction(effectAction);
		}else if(strcmp(szImage,"a_hit")==0){
			this->initWithSpriteFrameName("bottom_damage_01.png");
			this->setAnchorPoint(ccp(0.5f,0));
			this->setPosition(ccp(at->getPositionX()+16,at->getPositionY()));
			CCAction* effectAction=this->createEffectAnimation("bottom_damage_",6,20,false);
			this->runAction(effectAction);
		}
		//技能特效
		else if(strcmp(szImage,"Kagura")==0){
			this->initWithSpriteFrameName("Kagura_01.png");
			CCAction* effectAction=this->createEffectAnimation("Kagura_",9,10,false);
			this->setAnchorPoint(ccp(0.5f,0.5f));
			this->runAction(effectAction);

		}else if(strcmp(szImage,"Hupo")==0){
			this->initWithSpriteFrameName("Hupo_01.png");
			CCAction* effectAction=this->createEffectAnimation("Hupo_",7,10,false);
			this->setAnchorPoint(ccp(0.5f,0.5f));
			this->runAction(effectAction);

		}else if(strcmp(szImage,"hp_restore")==0 ||
			strcmp(szImage,"speedUp")==0
			){
			this->initWithSpriteFrameName(CCString::createWithFormat("%s_01.png",szImage)->getCString());
			CCAction* effectAction=this->createEffectAnimation(CCString::createWithFormat("%s_",szImage)->getCString(),5,5,false);
			CCFiniteTimeAction* call=CCCallFunc::create(at,callfunc_selector(ActionManager::disableEffect));
			CCArray* seqArray=CCArray::create();
			seqArray->addObject(effectAction);
			seqArray->addObject(call);
			CCAction* seq=CCSequence::create(seqArray);	
			this->runAction(seq);
		}else if(strcmp(szImage,"smk")==0){
			this->initWithSpriteFrameName("smk_01.png");
			this->setAnchorPoint(ccp(0.5f,0));
			this->setPosition(at->getPosition());
			CCAction* effectAction=this->createEffectAnimation("smk_",5,10,false);
			this->runAction(effectAction);
			if(CCUserDefault::sharedUserDefault()->getBoolForKey("isVoice")!=false){
				SimpleAudioEngine::sharedEngine()->playEffect("Audio/Effect/poof.mp3");
			}
		}else if(strcmp(szImage,"tishen")==0){
			this->initWithSpriteFrameName("tishen_01.png");
			this->setAnchorPoint(ccp(0.5f,0));
			this->setPosition(at->getPosition());
			CCAction* effectAction=this->createEffectAnimation("tishen_",6,10,false);
			this->runAction(effectAction);
		}
		else if(strcmp(szImage,"stun")==0){

			this->initWithSpriteFrameName("smk_01.png");
			this->setAnchorPoint(ccp(0.5f,0));
			this->setPosition(ccp(at->getPositionX(),at->getPositionY()+at->getContentSize().height-2));
			CCAction* effectAction=this->createEffectAnimation("stun_",5,5,false);
			this->runAction(effectAction);

		}else if(strcmp(szImage,"DarkFlame")==0 ){

			this->initWithSpriteFrameName("DarkFlame_Effect_01.png");
			this->setAnchorPoint(ccp(0.5f,0));
			this->setPosition(ccp(at->getPositionX(),at->getPositionY()));
			CCAction* effectAction=this->createEffectAnimation("DarkFlame_Effect_",5,10,true);
			this->runAction(effectAction);

			CCDelayTime* delay=CCDelayTime::create(2.8f);
			CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Effect::removeEffect));
			CCAction* seq=CCSequence::create(delay,call,NULL);	
			this->runAction(seq);

		}
		else if(strcmp(szImage,"Bagua")==0){
			this->initWithSpriteFrameName(CCString::createWithFormat("Bagua_01.png",szImage)->getCString());
			CCAction* effectAction=this->createEffectAnimation(CCString::createWithFormat("Bagua_",szImage)->getCString(),24,10,false);
			this->setAnchorPoint(ccp(0.5f,0));
			this->setPosition(ccp(at->getPositionX()+2,at->getPositionY()-52));
			this->runAction(effectAction);

		}else if(strcmp(szImage,"Kujiyose")==0){
			this->initWithSpriteFrameName(CCString::createWithFormat(("%s.png"),szImage)->getCString());
			this->setAnchorPoint(ccp(0.5f,0));
			this->setPosition(ccp(at->getPositionX(),at->getPositionY()-this->getContentSize().height/2));
			CCDelayTime* delay=CCDelayTime::create(0.3f);
			CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Effect::removeEffect));
			CCAction* seq=CCSequence::create(delay,call,NULL);	
			this->runAction(seq);

		}else if(strcmp(szImage,"kazi")==0){
			this->initWithSpriteFrameName("kazi.png");
			this->setAnchorPoint(ccp(0.5f,0));
			this->setPosition(ccp(at->getPositionX()+(at->_isFlipped?-32:32),
				at->getPositionY()+at->getContentSize().height/2));
			CCActionInterval* su=CCScaleBy::create(0.1f,1.2f);
			CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Effect::removeEffect));
			CCAction* seq=CCSequence::create(su,su->reverse(),call,NULL);	
			this->runAction(seq);
		}else if(strcmp(szImage,"sharingan")==0 ||
			strcmp(szImage,"sharingan2")==0 ||
			strcmp(szImage,"sharingan3")==0 ||
			strcmp(szImage,"sharingan4")==0  
			){
			this->initWithSpriteFrameName(CCString::createWithFormat(("%s.png"),szImage)->getCString());
			this->setPosition(ccp(at->getPositionX()+(at->_isFlipped?-32:32),
				at->getPositionY()+at->getContentSize().height));
			CCActionInterval* rt=CCRotateBy::create(0.3f,180,180);
			CCActionInterval* su=CCScaleBy::create(0.2f,1.6f);
			CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Effect::removeEffect));
			CCAction* seq=CCSequence::create(rt,su,call,NULL);	
			this->runAction(seq);
		}else if(strcmp(szImage,"Hiraishin")==0||
			strcmp(szImage,"Hiraishin2")==0){
			this->initWithSpriteFrameName(CCString::createWithFormat("%sEffect_01.png",szImage)->getCString());
			this->setAnchorPoint(ccp(0.5f,0));
			this->setPosition(at->getPosition());
			CCAction* effectAction=this->createEffectAnimation(CCString::createWithFormat("%sEffect_",szImage)->getCString(),4,10,false);
			this->runAction(effectAction);
		}
		//buff特效
		else if(strcmp(szImage,"hBuff")==0 ){
			this->initWithSpriteFrameName(CCString::createWithFormat("%s_Effect_01.png",szImage)->getCString());
			this->setAnchorPoint(ccp(0.5f,0));
			CCAction* effectAction=this->createEffectAnimation(CCString::createWithFormat("%s_Effect_",szImage)->getCString(),4,5,true);
			this->runAction(effectAction);
		}
		else if(strcmp(szImage,"hsBuff")==0||
			strcmp(szImage,"tBuff")==0
			){
			this->initWithSpriteFrameName(CCString::createWithFormat("%s_Effect_01.png",szImage)->getCString());
			this->setAnchorPoint(ccp(0.5f,0));
			CCAction* effectAction=this->createEffectAnimation(CCString::createWithFormat("%s_Effect_",szImage)->getCString(),13,10,true);
			this->runAction(effectAction);
		}else if(strcmp(szImage,"dcBuff")==0 
			){
				this->initWithSpriteFrameName(CCString::createWithFormat("%s_Effect_01.png",szImage)->getCString());
				this->setAnchorPoint(ccp(0.5f,0));
				CCAction* effectAction=this->createEffectAnimation(CCString::createWithFormat("%s_Effect_",szImage)->getCString(),11,10,true);
				this->runAction(effectAction);
		}else if(strcmp(szImage,"jdBuff")==0 ||
			strcmp(szImage,"bmBuff")==0
			){
				this->initWithSpriteFrameName(CCString::createWithFormat("%s_Effect_01.png",szImage)->getCString());
				this->setAnchorPoint(ccp(0.5f,0));
				CCAction* effectAction=this->createEffectAnimation(CCString::createWithFormat("%s_Effect_",szImage)->getCString(),9,10,true);
				this->runAction(effectAction);
		}
		else if(strcmp(szImage,"dhBuff")==0){
			
			for(int i=0;i<3;i++){
				CCSprite* ef=CCSprite::createWithSpriteFrameName("FireEffect_01.png");
				ef->setAnchorPoint(ccp(0.5f,0));	
				if(i==0){
					ef->setPosition(ccp(10,0));
				}else if(i==1){
					ef->setPosition(ccp(-10,18));
				}else{
					ef->setPosition(ccp(10,34));
				}	
				CCAction* effectAction=this->createEffectAnimation("FireEffect_",5,10,true);
				ef->runAction(effectAction);	
				this->addChild(ef);
			}	
		}

		bRet=true;

	}while(0);

	return bRet;

}

CCAction* Effect::createEffectAnimation(const char* file,int frameCount,float fps,bool isRepeat){
	CCArray* animeFrames = CCArray::create();
	CCString* str;

	for(int i = 1; i < frameCount; i++){	
		str=CCString::createWithFormat("%s%02d.png",file,i);
		CCSpriteFrame *frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString());
		animeFrames->addObject(frame);
	}

	CCAnimation* tempAnimation=CCAnimation::createWithSpriteFrames(animeFrames, float(1.0 / fps));
	CCAction* tempAction=CCAnimate::create(tempAnimation);
	CCArray* seqArray=CCArray::createWithObject(tempAction);
	CCAction* seq;
	if(isRepeat){
		seq=CCRepeatForever::create(CCSequence::create(seqArray));
	}else{

		CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Effect::removeEffect));
		seqArray->addObject(call);
		seq=CCSequence::create(seqArray);

	}

	return seq;


};
CCAction* Effect::createFontAnimation(){

	CCDelayTime* delay=CCDelayTime::create(0.3f);
	CCFiniteTimeAction* call=CCCallFunc::create(this,callfunc_selector(Effect::removeFontEffect));
	CCAction* seq=CCSequence::create(delay,call,NULL);

	return seq;
}

void Effect::removeEffect(){
	if(at->damageEffectCount>0){
		at->damageEffectCount--;
	}
	this->stopAllActions();
	this->removeFromParentAndCleanup(true);

}

void Effect::removeFontEffect(){
	this->stopAllActions();
	this->removeFromParentAndCleanup(true);

}

Effect*  Effect::create(const char *szImage,CCObject* Attacker){
	Effect* ef=new  Effect();
	if (ef && ef->init(szImage,Attacker))
	{
		ef->autorelease();
		return ef;
	}
	else
	{
		delete ef;
		return NULL;
	}
}