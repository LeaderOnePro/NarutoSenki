#pragma once
#include "support/tinyxml2/tinyxml2.h"
#include "cocos2d.h"
#include "platform/CCFileUtils.h"
#include "MyUtils/CMD5Checksum.h"
#include "MyUtils/sqlite3.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

class CMD5Checksum;
class SelectLayer;
class NetworkLayer;
class KTools : public CCObject{
public:
	KTools(void);
	~KTools(void);

	bool init();
	CREATE_FUNC(KTools);

	void prepareFileMD5();
	void prepareFileSHA();

	bool readXMLToArray(const char* filePath,CCArray* &array);
	void	initTableInDB();
	void	initColumeInDB();

	sqlite3* prepareTableInDB();


	
	bool checkData();
	void updateData();
	bool	saveToSQLite(const char* table="GameRecord",const char* column=NULL,const char* value=NULL,bool isBuy=false);
	CCString*  readFromSQLite(const char* table="GameRecord",const char* column=NULL,const char* value=NULL);
	
	void encode(std::string &str,int randomKey);
	void decode(std::string &str);
	int checkMD5(std::string findPath ="");
	

	void dfsFolder(std::string folderPath, int depth = 0,int type=0);

	bool checkPackage();
	void prepareFileOGG(const char* listName,int type=0);

	std::string getKeycode(std::string path);
	

	CCString*  readSQLite(const char* table,const char* column,const char* value,const char* targetColumn);
	void saveSQLite(const char* table,const char* relatedColumn,const char* value,const char* targetColumn,char* targetValue,bool isPlus);


	CC_SYNTHESIZE(SelectLayer*,_delegate,Delegate);
	CC_SYNTHESIZE(NetworkLayer*,_delegate2,Delegate2);


	std::string encodeData(std::string data);
};

class CCTips : public CCSprite{
public:
	CCTips(void);
	~CCTips(void);

	virtual bool			init(const char *tips);
	static CCTips*	create(const char *tips);


protected:

	void onDestroy();


};

