#pragma once
#include "cocos2d.h"
#include "MyUtils/KTools.h"
#include "GameLayer.h"
#include "Defines.h"
#include "SimpleAudioEngine.h"
#include "Effect.h"


USING_NS_CC;


enum actionState{
	ACTION_STATE_DEAD,
	ACTION_STATE_IDLE,
	ACTION_STATE_WALK,
	ACTION_STATE_ATTACK,
	ACTION_STATE_SATTACK,
	ACTION_STATE_OATTACK,
	ACTION_STATE_O2ATTACK,
	ACTION_STATE_HURT,
	ACTION_STATE_ABHURT,
	ACTION_STATE_KOCKDOWN,
	ACTION_STATE_FLOAT,
	ACTION_STATE_JUMP,
	ACTION_STATE_AIRHURT
};



class HPBar;
class ActionManager :public CCSprite{
public:
	ActionManager(void);
	~ActionManager(void);

	virtual void		setID(CCString* character,CCString* role,CCString* group);
	virtual	void		setHPbar();
	virtual	void       changeHPbar();
	virtual	void		setShadows();
	unsigned int		_deadNum;
	unsigned int		_flogNum;
	CC_SYNTHESIZE_RETAIN(CCString*, _killNum,KillNum);
	



	CC_SYNTHESIZE_RETAIN(CCString*, _coin,Coin);


	CCObject*			_slayer;
	CCObject*			_sticker;

	

	ActionManager*		_mainTarget;

	bool				isHurtingTower;

	bool				_isFlipped;
	bool				_isHitOne;
	bool				_isCatchOne;
	bool				_isHealling;
	bool				_isVisable;
	//buff

	
	CC_SYNTHESIZE(unsigned int,_charNO,CharNO);

	unsigned int		_healBuffValue;
	unsigned int		_dehealBuffValue;
	unsigned int		_powerUPBuffValue;
	unsigned int		_skillUPBuffValue;
	unsigned int		_skillChangeBuffValue;

	

	CCSprite*			_heartEffect;	
	Effect*				_healBuffEffect;
	Effect*				_powerBuffEffect;
	Effect*				_skillBuffEffect;
	CCSprite*			_dehealBuffEffect;
	Effect*				_healItemEffect;
	Effect*				_speedItemEffect;
	float				_buffStartTime;
	float				_debuffStartTime;
	CC_SYNTHESIZE(int,_knockLength, KnockLength);
	CC_SYNTHESIZE(bool,_knockDiretion, KnockDiretion);
	bool				_isAllAttackLocked;
	bool				_isOnlySkillLocked;
	bool				_isWudi;
	bool				_isTaunt;
	bool				_isBati;
	bool				_isSuicide;

	bool				_isSticking;

	bool				_isPausing;

	CCPoint				_markPoint;
	CCPoint				_startPoint;

	bool				_isAI;
	bool				_isControled;

	CC_SYNTHESIZE_RETAIN(CCLabelTTF*,cpLabel,CPLabel);
	//attributes
	CC_SYNTHESIZE_RETAIN(CCString*, _role,Role);
	CC_SYNTHESIZE_RETAIN(CCString*, _group,Group);
	CC_SYNTHESIZE_RETAIN(CCString*, _character,Character);
	CC_SYNTHESIZE_RETAIN(CCArray*,_gearArray,GearArray);


	int rebornLabelTime;
	int battleCondiction;
	bool isBaseDanger;



	HPBar*				_hpBar;
	CCSprite*			_shadow;
	float				_originY;
	float				_backY;
	float				_DiretionY;

	int					lostBloodValue;
	int					gearCKRValue;
	int					gearRecoverValue;

	unsigned int		hearts;
	unsigned int		bamen;
	bool				isAttackGainCKR;
	bool				isPofang;
	bool				isHujia;
	bool				isGearCD;

	bool				_isCanGear00;
	bool				_isCanGear03;
	bool				_isCanGear06;

	CC_SYNTHESIZE(int, _walkSpeed, WalkSpeed);
	int _originSpeed;
	//CC_SYNTHESIZE(float,_maxHP,MaxHP);
	//CC_SYNTHESIZE(float,_hp,HP);

	CC_SYNTHESIZE_RETAIN(CCString*,_maxHP,MaxHP);
	CC_SYNTHESIZE_RETAIN(CCString*,_hp,HP);

	CC_SYNTHESIZE_RETAIN(CCString*,_ckr,CKR);
	CC_SYNTHESIZE_RETAIN(CCString*,_ckr2,CKR2);
	CC_SYNTHESIZE(float,_gardValue,GP);
	CC_SYNTHESIZE(float,_exp,EXP);
	CC_SYNTHESIZE(unsigned int,_level,LV);
	CC_SYNTHESIZE(int,_height,Height);
	CC_SYNTHESIZE(unsigned int,_rebornTime,RebornTime);


	CC_SYNTHESIZE(CCPoint,_spawnPoint,SpawnPoint);
		
	
	CC_SYNTHESIZE(Hero*,_master,Master);
	CC_SYNTHESIZE(ActionManager*,_controler,Controler);
	CC_SYNTHESIZE(ActionManager*,_secmaster,SecMaster);

	CC_SYNTHESIZE_RETAIN(CCString*,_nattackValue,nAttackValue);
	//unsigned int   _nattackValue ;
	CC_SYNTHESIZE(CCString*, _nattackType,nAttackType);
	int				_nattackRangeX;
	int				_nattackRangeY;

	

	CC_SYNTHESIZE_RETAIN(CCString*, _sattackValue1,sAttackValue1);
	//unsigned int    _sattackValue1;
	CC_SYNTHESIZE(CCString*, _sattackType1,sAttack1Type);
	int				_sattackRangeX1;
	int				_sattackRangeY1;
	unsigned int	_sattackcoldDown1;
	bool			_sattack1isDouble;
	int				_sattackCombatPoint1;

	
	unsigned int	 _attackValue;
	CC_SYNTHESIZE(CCString*, _attackType,AttackType);
	int				_attackRangeX;
	int				_attackRangeY;

	CC_SYNTHESIZE_RETAIN(CCString*, _sattackValue2,sAttackValue2);
	//unsigned int    _sattackValue2;
	CC_SYNTHESIZE(CCString*, _sattackType2,sAttack2Type);
	int				_sattackRangeX2;
	int				_sattackRangeY2;
	unsigned int	_sattackcoldDown2;
	bool			_sattack2isDouble;
	int				_sattackCombatPoint2;

	CC_SYNTHESIZE_RETAIN(CCString*, _sattackValue3,sAttackValue3);
	//unsigned int    _sattackValue3;
	CC_SYNTHESIZE(CCString*, _sattackType3,sAttack3Type);
	int				_sattackRangeX3;
	int				_sattackRangeY3;
	unsigned int	_sattackcoldDown3;
	bool			_sattack3isDouble;
	int				_sattackCombatPoint3;

	CC_SYNTHESIZE_RETAIN(CCString*, _sattackValue4,sAttackValue4);
	//unsigned int    _sattackValue4;
	CC_SYNTHESIZE(CCString*, _sattackType4,sAttack4Type);
	int				_sattackRangeX4;
	int				_sattackRangeY4;
	unsigned int	_sattackcoldDown4;
	bool			_sattack4isDouble;
	int				_sattackCombatPoint4;

	CC_SYNTHESIZE_RETAIN(CCString*, _sattackValue5,sAttackValue5);
	//unsigned int    _sattackValue5;
	CC_SYNTHESIZE(CCString*, _sattackType5,sAttack5Type);
	int				_sattackRangeX5;
	int				_sattackRangeY5;
	unsigned int	_sattackcoldDown5;
	int				_sattackCombatPoint5;

	//int totalCombatPoint;
	int enemyCombatPoint;
	int friendCombatPoint;

	CC_SYNTHESIZE_RETAIN(CCString*, _spcattackValue1,spcAttackValue1);
	//unsigned int    _spcattackValue1;
	CC_SYNTHESIZE(CCString*, _spcattackType1,spcAttack1Type);
	int				_spcattackRangeX1;
	int				_spcattackRangeY1;
	unsigned int				_spcattackcoldDown1;



	CC_SYNTHESIZE_RETAIN(CCString*, _spcattackValue2,spcAttackValue2);
	//unsigned int    _spcattackValue2;
	CC_SYNTHESIZE(CCString*, _spcattackType2,spcAttack2Type);
	int				_spcattackRangeX2;
	int				_spcattackRangeY2;
	unsigned int				_spcattackcoldDown2;

	CC_SYNTHESIZE_RETAIN(CCString*, _spcattackValue3,spcAttackValue3);
	//unsigned int    _spcattackValue3;
	CC_SYNTHESIZE(CCString*, _spcattackType3,spcAttack3Type);
	int				_spcattackRangeX3;
	int				_spcattackRangeY3;
	unsigned int				_spcattackcoldDown3;


	CC_SYNTHESIZE_RETAIN(CCString*, _tempAttackValue1,tempAttackValue1);
	int            _tempcoldDown1;
	

	CC_SYNTHESIZE(CCString*, _tempAttackType,TempAttackType);

	CC_SYNTHESIZE(CCString*,_effectType,EffectType);
	bool			_hurtFromLeft;
	bool			_hurtFromRight;



	CC_SYNTHESIZE(CCArray*,_damageArray,DamageArray);
	
	unsigned int damageEffectCount;
	CC_SYNTHESIZE(CCArray*,_monsterArray,MonsterArray);

	//movement
	CC_SYNTHESIZE(cocos2d::CCPoint, _velocity, Velocity);
	CC_SYNTHESIZE(cocos2d::CCPoint, _desiredPosition, DesiredPosition);

	CC_SYNTHESIZE(actionState, _actionState, ActionState);
	CC_SYNTHESIZE(GameLayer*, _delegate, Delegate);

			


	CC_SYNTHESIZE_RETAIN(CCAction*, _idleAction, IdleAction);
	CC_SYNTHESIZE_RETAIN(CCAction*, _nattackAction, NAttackAction);
	CC_SYNTHESIZE_RETAIN(CCAction*, _walkAction, WalkAction);
	CC_SYNTHESIZE_RETAIN(CCAction*, _hurtAction, HurtAction);
	CC_SYNTHESIZE_RETAIN(CCAction*, _knockDownAction, KnockDownAction);
	CC_SYNTHESIZE_RETAIN(CCAction*, _airHurtAction, AirHurtAction);
	CC_SYNTHESIZE_RETAIN(CCAction*, _floatAction, FloatAction);
    CC_SYNTHESIZE_RETAIN(CCAction*, _deadAction, DeadAction); 


	CC_SYNTHESIZE_RETAIN(CCAction*, _skill1Action, Skill1Action);
	CC_SYNTHESIZE_RETAIN(CCAction*, _skill2Action, Skill2Action);
	CC_SYNTHESIZE_RETAIN(CCAction*, _skill3Action, Skill3Action);
	CC_SYNTHESIZE_RETAIN(CCAction*, _skill4Action, Skill4Action);
	CC_SYNTHESIZE_RETAIN(CCAction*, _skill5Action, Skill5Action);
	

	CC_SYNTHESIZE_RETAIN(CCActionInterval* ,_moveAction,MoveAction);
	CC_SYNTHESIZE_RETAIN(CCAction* ,_floatUPAction,FloatUPAction);
	CC_SYNTHESIZE_RETAIN(CCActionInterval* ,_jumpUPAction,JumpUPAction);

	
	void				update(float dt);
	void				acceptAttack(CCObject* object);


	float				getHpPercent();
	

	void				idle();
	void				walk(CCPoint direction);
	void				attack(abType type);
	void				sAttack(abType type);
	void				nAttack();
	void				oAttack(abType type);
	bool				hurt();
	bool				hardHurt(int delayTime,bool isHurtAction,bool isCatch,bool isStick,bool isStun);
	void				absorb(CCPoint position,bool isImmediate);
	void				jump();
	void				knockDown();
	void				dead();
	void				floatUP(float floatHeight,bool isCancelSkill);
	void				airHurt();
	void				doAI();

	
	void				changeAction();
	void				changeAction2();
	void				changeGroup();

	void				resumeAction(float dt);
	void				setActionResume();
	void				setActionResume2();
	void				reCatched(float dt);
	
	void				setShadow(CCNode* sender,void* date);
	void				disableShadow(CCNode* sender);
	void				enableShadow(CCNode* sender);

	void				setItem(abType type);
	void				disableEffect();
	void				disableHpBar(float dt);

	void				disableShack();
	void				disableDebuff(float dt);

	void				enableSkill1(float dt);
	void				enableSkill2(float dt);
	void				enableSkill3(float dt);
	void				enableItem1(float dt);


	void				enableGear00(float dt);
	void				enableGear03(float dt);
	void				enableGear06(float dt);

	void				disableGear1(float dt);
	void				disableGear2(float dt);
	void				disableGear3(float dt);

	bool				setGear(gearType type);
	void				useGear(gearType type);

	void				setCoinDisplay(int num);
	void				addCoin(int num);
	void				minusCoin(int num);

	bool				_isCanSkill1;
	bool				_isCanSkill2;
	bool				_isCanSkill3;
	bool				_isCanItem1;
	bool				_isCanOugis1;
	bool				_isCanOugis2;

	CCArray*			idleArray;
	CCArray*			walkArray;
	CCArray*			hurtArray;
	CCArray*			airHurtArray;
	CCArray*			knockDownArray;
	CCArray*			floatArray;
	CCArray*			deadArray;
	CCArray*			nattackArray;
	CCArray*			skill1Array;
	CCArray*			skill2Array;
	CCArray*			skill3Array;
	CCArray*			skill4Array;
	CCArray*			skill5Array;

	CCArray*			skillSPC1Array;
	CCArray*			skillSPC2Array;
	CCArray*			skillSPC3Array;
	CCArray*			skillSPC4Array;
	CCArray*			skillSPC5Array;


	virtual void	    dealloc();
	virtual void		reborn(float dt);


	void				resumePauseStuff(float dt);

	void				lostBlood(float dt);
	void				removeLostBlood(float dt);
	
	virtual void		setAI(float dt);
	void				setSkillEffect(CCNode* sender,void* date);
	void				setRestore2(float dt);




protected:

	
	
	void				readDate(CCArray* tmpDate,CCString* &attackType,CCString* &attackValue,int &attackRangeX,int &attackRangeY,unsigned int &coldDown,int &combatPoint);

	CCAction*			createAnimation(CCArray* ationArray,float fps,bool isRepeat,bool isReturn);

	CCDictionary*		callValue;
	
	void				setSound(CCNode* sender,void* date);
	void				setDSound(CCNode* sender,void* date);
	void				setMove(CCNode* sender,void* date);
	void				setCharge(CCNode* sender,void* date);
	void				setChargeB(CCNode* sender,void* date);
	void				getCollider();
	void				getSticker(float dt);
	void				stopMove(float dt);
	void				stopJump(CCNode* sender,void* date);
	void				setAttackBox(CCNode* sender,void* date);
	void				setDamage(CCString* effectType,unsigned int attackValue,bool isFlipped);
	void				setDamgeDisplay(unsigned int value,const char* type);
	
	void				setItemEffect(CCNode* sender,void* date);
	void				setDamgeEffect(CCString* type);
	void				setMonAttack(CCNode* sender,void* date);
	void				setTransform();
	void				setOugis(CCNode* sender);

	void				setCharFlip();

	
	
	void				setClone(CCNode* sender,void* date);
	void				setMon(CCNode* sender,void* date);
	void				setMonPer(float dt);
	void				setBullet(CCNode* sender,void* date);
	void				setBulletGroup(float dt);

	void				setTrap(CCNode* sender,void* date);

	

	void				setBuff(CCNode* sender,void* date);
	void				setCommand(CCNode* sender,void* date);
	void				setBuffEffect(const char* type);
	void				removeBuffEffect(const char* type);
	void				disableBuff(float dt);
	void				healBuff(float dt);
	void				dehealBuff(float dt);

	void				removeClone(float dt);
	void				removeSelf(float dt);
	void				setJump(CCNode* sender,void* date);

	
	void				removeCoinDisplay(CCNode* sender,void* date);

	CCRect				setHalfBox();
	CCRect				setHitBox();

	void				checkActionFinish(float dt);

	void				setRestore(float dt);
	
	
	
	bool				findEnemy(const char* type,int searchRange,bool masterRange = false);
	bool				findEnemy2(const char* type);
	bool				findTargetEnemy(const char* type,bool isTowerDected);
	bool				checkBase();

	bool				stepBack();
	bool				stepBack2();
	bool				checkRetri();
	void				stepOn();
	void				changeSide(CCPoint sp);

	

	void				removeDamageDisplay();

	void				onEnter();
	void				onExit();

};

