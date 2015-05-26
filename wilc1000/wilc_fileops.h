#ifndef __wilc_FILEOPS_H__
#define __wilc_FILEOPS_H__

/*!  
*  @file	FileOps.h
*  @brief	File Operations OS wrapper functionality
*  @author	syounan
*  @sa		wilc_OSWrapper.h top level OS wrapper file
*  @date	31 Aug 2010
*  @version	1.0
*/

#ifndef CONFIG_wilc_FILE_OPERATIONS_FEATURE
#error the feature CONFIG_wilc_FILE_OPS_FEATURE must be supported to include this file
#endif


typedef enum{
	wilc_FILE_READ_ONLY,
	wilc_FILE_READ_WRITE_EXISTING,
	wilc_FILE_READ_WRITE_NEW
}tenuwilc_AccessMode;

typedef enum{
	wilc_SEEK_FROM_START,
	wilc_SEEK_FROM_END,
	wilc_SEEK_FROM_CURRENT
}tenuwilc_SeekOrigin;

/*!
*  @struct 		tstrwilc_FileOpsAttrs
*  @brief		Message Queue API options
*  @author		syounan
*  @date		30 Aug 2010
*  @version		1.0
*/
typedef struct
{
	/*!< access mode of the file, default is READ_WRITE_EXISTING */
	tenuwilc_AccessMode enuAccess;
	
	/*!< origin for seeking operations, default is wilc_FILE_SEEK_CUR */
	tenuwilc_SeekOrigin enuSeekOrigin;
	
}tstrwilc_FileOpsAttrs;

/*!
*  @brief		Fills the MsgQueueAttrs with default parameters
*  @param[out]	pstrAttrs structure to be filled
*  @sa			wilc_TimerAttrs
*  @author		syounan
*  @date		30 Aug 2010
*  @version		1.0
*/
static void wilc_FileOpsFillDefault(tstrwilc_FileOpsAttrs* pstrAttrs)
{
	pstrAttrs->enuAccess = wilc_FILE_READ_WRITE_EXISTING;
	pstrAttrs->enuSeekOrigin = wilc_SEEK_FROM_CURRENT;
}


/**
*  @brief 		Opens a file
*  @details 	Opens a file, possibly creating a new file if write enabled and
 				pstrAttrs->bCreate is set to true
*  @param[in,out] pHandle Handle to the opened file
*  @param[in] 	pcPath path to the File
*  @param[in] 	pstrAttrs Optional attributes, NULL for defaults. bCreate will 
				create the file if does not exit, enuAccess will control access 
				mode
*  @return 		Error code indicating success/failure
*  @note 		Original Standard Function: 
				FILE *fopen( const char *filename, const char *mode );
*  @author		syounan
*  @date		30 Aug 2010
*  @version		1.0
*/
wilc_ErrNo wilc_fopen(wilc_FileHandle* pHandle, const wilc_Char* pcPath, 
	tstrwilc_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Closes a file.
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pstrAttrs Optional attributes, NULL for default.
 * @return 		Error code indicating success/failure
 * @note 		Original Standard Function: int fclose( FILE *stream );
*  @author		syounan
*  @date		30 Aug 2010
*  @version		1.0 
 */
wilc_ErrNo wilc_fclose(wilc_FileHandle* pHandle, tstrwilc_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Reads data from a file.
 * @param[in] 	pHandle Handle to the file object
 * @param[out] 	pu8Buffer Storage location for data
 * @param[in] 	u32Size Number of bytes to be read
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 * @return 		Returns the number of bytes actually read, which may be less 
 				than count if an error occurs or if the end of the file is 
				encountered before reaching count.
				Use the wilc_feof function to distinguish a read error from an 
				end-of-file condition.
				If size or count is 0, wilc_fread returns 0 and the buffer 
				contents are unchanged.
 * @note 		Original Standard Function: 
 	size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0 
 */
wilc_Uint32 wilc_fread(wilc_FileHandle* pHandle, wilc_Uint8* pu8Buffer, 
				wilc_Uint32 u32Size, tstrwilc_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Writes data to a FILE.
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pu8Buffer Storage location for data
 * @param[in] 	u32Size Number of bytes to be write
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 * @return 		Returns the number of full items actually written, which may be
				less than count if an error occurs
				Also, if an error occurs, the file-position indicator cannot be 
				determined.
 * @note 		Original Standard Function: 
 	size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0  
 */
wilc_Uint32 wilc_fwrite(wilc_FileHandle* pHandle, wilc_Uint8* pu8Buffer, 
				wilc_Uint32 u32Size, tstrwilc_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Tests for end-of-file
 * @param[in] 	pHandle Handle to the file object
 * @retval		wilc_FALSE if the current position is not end of file
 * @retval		wilc_TRUE after the first read operation that attempts to read past
				the end of the file.
 * @note 		Original Standard Function: int feof( FILE *stream );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0
 */
wilc_Bool wilc_feof(wilc_FileHandle* pHandle);

/**
 * @brief 		Moves the file pointer to a specified location.
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	s32Offset Number of bytes to move, origin of seeking depends on
				pstrAttrs->enuSeekOrigin, if pstrAttrs is NULL then origin is the 
				current position at the file
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 				enuSeekOrigin defines the origin of seek operations 
 * @return 		Error code indicating success/failure
 * @note 		Original Standard Function:
				int fseek( FILE *stream, long offset, int origin );
 */
wilc_ErrNo wilc_fseek(wilc_FileHandle* pHandle, wilc_Sint32 s32Offset, 
		tstrwilc_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Gets the current position of a file pointer.
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pstrAttrs Optional attributes, NULL for default.
 * @return 		Returns the current file position. Or wilc_FAIL on error.
 * @note 		Original Standard Function: long ftell( FILE *stream );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0 
 */
wilc_Uint32 wilc_ftell(wilc_FileHandle* pHandle, tstrwilc_FileOpsAttrs* pstrAttrs);


/**
 * @brief 		Flushes the file, writing all data that may be in buffers
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 * @return 		Error code indicating success/failure
 * @note 		Original Standard Function: int fflush( FILE *stream );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0 
 */
wilc_ErrNo wilc_fflush(wilc_FileHandle* pHandle, tstrwilc_FileOpsAttrs* pstrAttrs);



/**
 * @brief 		Gets the size of the file.
 * @param[in] 	pHandle Handle to the file object
 * @param[out] 	pu32Size returned size of file in question
 * @param[in] 	pstrAttrs Optional attributes, NULL for default.
 * @return 		Error code indicating success/failure
 * @note 		
 * @author		remil
 * @date		25 Oct 2010
 * @version		2.0 
 */
wilc_ErrNo wilc_FileSize(wilc_FileHandle* pstrFileHandle, wilc_Uint32* pu32Size,
	tstrwilc_FileOpsAttrs* pstrAttrs);



#ifdef CONFIG_wilc_EXTENDED_FILE_OPERATIONS
/**
 * @brief 		Returns the character currently pointed by the internal file position
 *				indicator of the specified stream. 
 *				The internal file position indicator is then advanced by one 
 *				character to point to the next character.
 * @param[in] 	wilc_FileHandle* pHandle
 * @return 		Returns the character currently pointed by the internal file position
 * @note 		Original Standard Function: int getc
 * @author		remil
 * @date		31 Oct 2010
 * @version		1.0 
 */
wilc_Sint32 wilc_getc(wilc_FileHandle* pHandle);


/**
 * @brief 		pushes the byte specified by c (converted to an unsigned char)
 *				back onto the input stream pointed to by stream.
 * @param[in]	wilc_Sint32 c
 * @param[in] 	wilc_FileHandle* pHandle
 * @return 		 returns the byte pushed back after conversion. Otherwise it returns EOF.
 * @note 		Original Standard Function:  ungetc
 * @author		remil
 * @date		31 Oct 2010
 * @version		1.0 
 */
wilc_Sint32 wilc_ungetc(wilc_Sint32 c,
					  wilc_FileHandle* pHandle);



/**
 * @author		remil
 * @date		31 Oct 2010
 * @version		1.0
 */
wilc_ErrNo wilc_freopen(wilc_FileHandle* pHandle, const wilc_Char* pcPath, 
	tstrwilc_FileOpsAttrs* pstrAttrs);

/**
*  @brief 		Translates character file open mode to the appropriate Enum Value
*  @details 	
*  @param[in] 	const wilc_Char* cpMode
*  @return 		tenuwilc_AccessMode
*  @note 		
*  @author		remil
*  @date		3 Nov 2010
*  @version		1.0
*/
tenuwilc_AccessMode wilc_resolveFileMode(const wilc_Char* cpMode);


/**
 * @author		remil
 * @date		31 Oct 2010
 * @version		1.0
 */
wilc_ErrNo wilc_rename(const wilc_Char *old_filename, const wilc_Char *new_filename);

wilc_ErrNo wilc_setbuf(wilc_FileHandle *pHandle, wilc_Char* buffer);


wilc_ErrNo wilc_setvbuf(wilc_FileHandle *pHandle, 
					  wilc_Char* buffer, 
					  wilc_Sint32 mode, 
					  wilc_Uint32 size);

/*
*Creates a temporary file in binary update mode (wb+). 
*The tempfile is removed when the program terminates or the stream is closed.
*On success a pointer to a file stream is returned. On error a null pointer is returned.
*/
wilc_ErrNo wilc_tmpfile(wilc_FileHandle *pHandle);


/*
 * Reads a line from the specified stream and stores it into the string pointed to by str.
 * It stops when either (n-1) characters are read,
 * the newline character is read, or the end-of-file is reached,
 * whichever comes first. The newline character is copied to the string.
 * A null character is appended to the end of the string.
 * On success a pointer to the string is returned. On error a null pointer is returned.
 * If the end-of-file occurs before any characters have been read, the string remains unchanged.
*/

//wilc_Char* wilc_fgets(wilc_Char* str, wilc_Sint32 n, wilc_FileHandle stream);


/**
*  @brief 		Clears the end-of-file and error indicators for the given stream.  
*  @details 	As long as the error indicator is set, 
				all stream operations will return an error until wilc_clearerr is called.
*  @param[in] 	wilc_FileHandle* pHandle
*  @return 		N/A
*  @note 		
*  @author		remil
*  @date		3 Nov 2010
*  @version		1.0
*/
void wilc_clearerr(wilc_FileHandle* pHandle);


/**
*  @brief 		Tests the error indicator for the given stream. 
*  @details 	If the error indicator is set, then it returns wilc_FAIL.
				If the error indicator is not set, then it returns wilc_SUCCESS.
*  @param[in] 	wilc_FileHandle* pHandle
*  @return 		wilc_ErrNo
*  @note 		
*  @author		remil
*  @date		3 Nov 2010
*  @version		1.0
*/
wilc_ErrNo wilc_ferror(wilc_FileHandle* pHandle);

/**
*  @brief 		Generates and returns a valid temporary filename which does not exist.
*  @details 	If the argument str is a null pointer, then the function returns 
				a pointer to a valid filename. 
				If the argument str is a valid pointer to an array,
				then the filename is written to the array and a pointer to the same array 
				is returned.The filename may be up to L_tmpnam characters long.
*  @param[in] 	wilc_Char* str
*  @return 		wilc_Char* 
*  @note 		
*  @author		remil
*  @date		3 Nov 2010
*  @version		1.0
*/
wilc_Char* wilc_tmpnam(wilc_Char* str);


#endif


#ifdef CONFIG_wilc_FILE_OPERATIONS_STRING_API

/**
 * @brief 		Reads a line.
 * @param[in] 	pHandle Handle to the file object
 * @param[out] 	pcBuffer Storage location for data
 * @param[in] 	u32Maxsize Maximum number of data to be read including NULL terminator
 * @return 		Error code indicating success/failure
 * @retval 		wilc_FILE_EOF If the End-of-File is encountered, no characters 
 				have been read and the contents of buffer remain unchanged
 * @retval 		wilc_FAIL If an error occurs, no characters 
 				have been read and the contents of buffer remain unchanged
 * @note 		Original Standard Function: 
 				char *fgets(char *s,int n,FILE *stream);
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0
 */
wilc_ErrNo wilc_fgets(wilc_FileHandle* pHandle, wilc_Char* pcBuffer
				, wilc_Uint32 u32Maxsize);

/**
 * @brief 		Prints formatted data to a stream
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pcFormat Format-control string
 * @param[in]	... Optional arguments
 * @return 		Error code indicating success/failure
 * @note Original Standard Function: 
 				int fprintf( FILE *stream, const char *format, ... );
 */
wilc_ErrNo wilc_fprintf(wilc_FileHandle* pHandle, const wilc_Char* pcFormat, ...);

/**
 * @brief 		Writes formatted output using a pointer to a list of arguments
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pcFormat Format specification
 * @param[in] 	argptr Pointer to list of arguments
 * @return 		Error code indicating success/failure
 * @note 		riginal Standard Function: 
 			int vfprintf( FILE *stream, const char *format, va_list argptr );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0
 */
wilc_ErrNo wilc_vfprintf(wilc_FileHandle* pHandle, const wilc_Char* pcFormat, 
				va_list argptr);

#endif

#ifdef CONFIG_wilc_FILE_OPERATIONS_PATH_API

/**
 * @brief 		Renames/Moves a file or directory
 * @param[in] 	pcOldPath the old path
 * @param[in] 	pcNewPath the new path
 * @param[in] 	pstrAttrs Optional attributes, NULL for default.
 * @return 		Error code indicating success/failure
 * @note 		if there is a file or folder exsiting in the new path, the 
 *				operation fails
 * @author		syounan
 * @date		31 Oct 2010
 * @version		2.0 
 */
wilc_ErrNo wilc_PathMove(wilc_Char* pcOldPath, wilc_Char* pcNewPath,
	tstrwilc_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Checks for the path exsitance
 * @details		Checks for the path exsitance, the path could be either a file or
				a directory, to test differentiate between files/directories 
				send a non-null poiter to the argument pbIsDirectory
 * @param[in] 	pcPath path of the examined file/directory
 * @param[out] 	pbIsDirectory set to wilc_TRUE if the path is directory, optional
				and could be wilc_NULL
 * @param[in] 	pstrAttrs Optional attributes, NULL for default.
 * @return 		wilc_TRUE if path exsits, wilc_FALSE if does not exist
 * @note 		if there is a file or folder exsiting in the new path, the 
 *				operation fails
 * @author		syounan
 * @date		31 Oct 2010
 * @version		2.0 
 */
wilc_Bool wilc_PathExsits(wilc_Char* pcPath, wilc_Bool* pbIsDirectory,
	tstrwilc_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Deletes the given path
 * @details		Deletes the given path, wheather it is a file or a directory
 *				if it is a directory that contains other files and diretories, 
 *				they will be recusively deleted
 * @param[in] 	pcPath path to the File
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 * @return 		Error code indicating success/failure
 * @note 		if the path does not exist, the function returns an error
 * @author		mabubakr, syounan
 * @date		31 Oct 2010
 * @version		2.0 
 */
wilc_ErrNo wilc_PathDelete(wilc_Char* pcPath, tstrwilc_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		creates a new directory
 * @details		creates a new directory in the given path, if a file or directory
				already exsits in this path the operation fails
 * @param[in] 	pcPath path to be created
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 * @return 		Error code indicating success/failure
 * @author		syounan
 * @date		31 Oct 2010
 * @version		2.0 
 */
wilc_ErrNo wilc_DirectoryCreate(wilc_Char* pcPath, tstrwilc_FileOpsAttrs* pstrAttrs);

#endif

#endif
