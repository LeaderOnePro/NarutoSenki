#pragma once
#include "cocos2d.h"
#include "Element.h"


class Hero : public HeroElement {
public:
	
	CREATE_FUNC(Hero);
	bool	init();

	

protected: 

	void setAI(float dt);
	void   AI_NarutoClone();
	void   AI_Kurama();
	void   AI_Centipede();
	void   AI_Naruto();
	void   AI_Chiyo();
	void   AI_RikudoNaruto();
	void   AI_Hinata();
	void   AI_Neji();
	void   AI_Pain();
	void   AI_Sakura();
	void   AI_Sai();
	void   AI_Asuma();
	void   AI_Tenten();
	void   AI_Minato();
	void   AI_Konan();
	void   AI_Deidara();
	void   AI_Itachi();
	void   AI_Kakashi();
	void   AI_Jiraiya();
	void	AI_SageJiraiya();
	void   AI_Sasuke();
	void	AI_ImmortalSasuke();
	void	AI_Suigetsu();
	void	AI_Karasu();
	void	AI_Saso();
	void	AI_Parents();
	void	AI_Sanshouuo();
	void	AI_Kankuro();
	void	AI_SageNarutoClone();
	void	AI_RikudoNarutoClone();
	void	AI_SageNaruto();
	void	AI_Shikamaru();
	void	AI_Gaara();
	void	AI_Tobirama();
	void	AI_Orochimaru();
	void	AI_Choji();
	void	AI_Karin();
	void	AI_DevaPath();
	void	AI_AnimalPath();
	void	AI_AsuraPath();
	void	AI_Lee();
	void	AI_RockLee();
	void	AI_Nagato();
	void	AI_Slug();
	void	AI_DogWall();
	void	AI_Jugo();
	void	AI_Tsunade();
	void	AI_Kisame();
	void	AI_Ino();
	void	AI_Hidan();
	void	AI_Tobi();
	void	AI_Shino();
	void	AI_Guardian();
	void	AI_Hiruzen();
	void	AI_Akamaru();
	void	AI_Kiba();
	void	AI_Kakuzu();
	void    AI_Mask();
	
};

