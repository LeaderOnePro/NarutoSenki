    //  
    //  CMD5Checksum.h  
      
    //  
      
    #ifndef __CMD5Checksum__  
    #define __CMD5Checksum__  
      
    #include "cocos2d.h"  
    USING_NS_CC;  
    /***************************************************************************************** 
      
      
     *****************************************************************************************/  
    typedef unsigned long DWORD;  
    typedef unsigned char BYTE;  
    typedef unsigned long ULONG;  
    typedef unsigned long ULONG;  
    typedef unsigned int UINT;  
    typedef unsigned char UCHAR;  
      
    #define ASSERT CC_ASSERT  
    #ifndef TRUE  
        #define TRUE true  
    #endif  
    #ifndef FALSE  
        #define FALSE false  
    #endif  
    class CMD5Checksum  
    {  
    public:  
        static std::string GetMD5OfString(std::string strString);  
        //interface functions for the RSA MD5 calculation  
        static std::string GetMD5(const std::string& strFilePath);  
          
    protected:  
        //constructor/destructor  
        CMD5Checksum();  
        virtual ~CMD5Checksum() {};  
          
        //RSA MD5 implementation  
        void Transform(BYTE Block[64]);  
        void Update(BYTE* Input, ULONG nInputLen);  
        std::string Final();  
        inline DWORD RotateLeft(DWORD x, int n);  
        inline void FF( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);  
        inline void GG( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);  
        inline void HH( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);  
        inline void II( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);  
          
        //utility functions  
        inline void DWordToByte(BYTE* Output, DWORD* Input, UINT nLength);  
        inline void ByteToDWord(DWORD* Output, BYTE* Input, UINT nLength);  
          
    private:  
        BYTE  m_lpszBuffer[64];  //input buffer  
        ULONG m_nCount[2];   //number of bits, modulo 2^64 (lsb first)  
        ULONG m_lMD5[4];   //MD5 checksum  
    };  
      
    #endif /* defined(__CMD5Checksum__) */  