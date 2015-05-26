#ifndef __wilc_SOCKET_H__
#define __wilc_SOCKET_H__

/*!  
*  @file		wilc_Socket.h
*  @brief		Socket Connection functionality
*  @author		remil
*  @sa			wilc_OSWrapper.h top level OS wrapper file
*  @date		19 Oct 2010
*  @version		1.0
*/

#ifndef CONFIG_wilc_SOCKET_FEATURE
#error the feature CONFIG_wilc_SOCKET_FEATURE must be supported to include this file
#endif


/*!
*	Maximum length of IP address
*/
#define MAX_IP_LENGTH 16

/*============================================================================*/
/*!
*  @struct 		tpfwilc_TcpReceptionCB
*  @brief		
*  @author		remil
*  @date		19 Oct 2010
*  @version		1.0
*/
/*============================================================================*/
typedef void (*tpfwilc_TcpReceptionCB)(wilc_Uint8* pu8Buffer,
									  wilc_Uint32 u32ReceivedDataLength,
									  void* vpUserData);
/*============================================================================*/
/*!
*  @struct 		tstrTcpConnection
*  @brief		
*  @author		remil
*  @date		19 Oct 2010
*  @version		1.0
*/
/*============================================================================*/
typedef struct _tstrTcpConnection
{
	wilc_Uint32 u32SocketFd;
	wilc_Sint32 s32Port;
	wilc_Char cpIPAddress[MAX_IP_LENGTH];
	tpfwilc_TcpReceptionCB fpTcpReceptionCB;
	wilc_ThreadHandle strThreadHandle;
	tstrwilc_ThreadAttrs strThreadAttrs;
	void* vpUserData;

}tstrTcpConnection;


/*============================================================================*/
/*!
*  @brief		
*  @return		
*  @note		
*  @author		remil
*  @date		19 Oct 2010
*  @version		1.0
*/
/*============================================================================*/
wilc_ErrNo wilc_TcpConnect(tstrTcpConnection* pstrTcpConnection);

/*============================================================================*/
/*!
*  @brief		
*  @return		
*  @note		
*  @author		remil
*  @date		19 Oct 2010
*  @version		1.0
*/
/*============================================================================*/
void wilc_TcpDisconnect(tstrTcpConnection* pstrTcpConnection);

/*============================================================================*/
/*!
*  @brief		
*  @return		
*  @note		
*  @author		remil
*  @date		19 Oct 2010
*  @version		1.0
*/
/*============================================================================*/
wilc_ErrNo wilc_TcpSend(tstrTcpConnection* pstrTcpConnection,
				  wilc_Uint8* u8Buf,
				  wilc_Uint32 u32DataSize);

#endif
