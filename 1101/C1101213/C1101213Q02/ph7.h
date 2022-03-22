#ifndef _PH7_H_
#define _PH7_H_
#include <stdarg.h>
#define PH7_VERSION "2.1.4"
#define PH7_VERSION_NUMBER 2001004
#define PH7_SIG "PH7/2.1.4"
#define PH7_IDENT "ph7:c193f4d8a6b90ee60f9afad11840f1010054fdf9"
#define PH7_COPYRIGHT "Copyright (C) Symisc Systems 2011-2012, http:
#ifdef __cplusplus
extern "C" { 
#endif
typedef struct ph7_io_stream ph7_io_stream;
typedef struct ph7_context ph7_context;
typedef struct ph7_value ph7_value;
typedef struct ph7_vfs ph7_vfs;
typedef struct ph7_vm ph7_vm;
typedef struct ph7 ph7;
#if !defined(SYMISC_STANDARD_DEFS)
#define SYMISC_STANDARD_DEFS
#if defined (_WIN32) || defined (WIN32) || defined(__MINGW32__) || defined (_MSC_VER) || defined (_WIN32_WCE)
#if !defined(__WINNT__)
#define __WINNT__
#endif 
#else
#if !defined(OS_OTHER)
#if !defined(__UNIXES__)
#define __UNIXES__
#endif
#else
#endif
#endif
#if defined(_MSC_VER) || defined(__BORLANDC__)
typedef signed __int64     sxi64;
typedef unsigned __int64   sxu64;
#else
typedef signed long long int   sxi64;
typedef unsigned long long int sxu64;
#endif
typedef int (*ProcConsumer)(const void *,unsigned int,void *);
typedef struct SyMutexMethods SyMutexMethods;
typedef struct SyMemMethods SyMemMethods;
typedef struct SyString SyString;
typedef struct syiovec syiovec;
typedef struct SyMutex SyMutex;
typedef struct Sytm Sytm;
struct syiovec
{
#if defined (__WINNT__)
	unsigned long nLen;
	char *pBase;
#else
	void *pBase;
	unsigned long nLen;
#endif
};
struct SyString
{
	const char *zString; 
	unsigned int nByte;  
};
struct Sytm
{
  int tm_sec;    
  int tm_min;    
  int tm_hour;   
  int tm_mday;   
  int tm_mon;    
  int tm_year;   
  int tm_wday;   
  int tm_yday;   
  int tm_isdst;  
  char *tm_zone; 
  long tm_gmtoff;
};
#define STRUCT_TM_TO_SYTM(pTM,pSYTM) \
	(pSYTM)->tm_hour = (pTM)->tm_hour;\
	(pSYTM)->tm_min	 = (pTM)->tm_min;\
	(pSYTM)->tm_sec	 = (pTM)->tm_sec;\
	(pSYTM)->tm_mon	 = (pTM)->tm_mon;\
	(pSYTM)->tm_mday = (pTM)->tm_mday;\
	(pSYTM)->tm_year = (pTM)->tm_year + 1900;\
	(pSYTM)->tm_yday = (pTM)->tm_yday;\
	(pSYTM)->tm_wday = (pTM)->tm_wday;\
	(pSYTM)->tm_isdst = (pTM)->tm_isdst;\
	(pSYTM)->tm_gmtoff = 0;\
	(pSYTM)->tm_zone = 0;

#define SYSTEMTIME_TO_SYTM(pSYSTIME,pSYTM) \
	 (pSYTM)->tm_hour = (pSYSTIME)->wHour;\
	 (pSYTM)->tm_min  = (pSYSTIME)->wMinute;\
	 (pSYTM)->tm_sec  = (pSYSTIME)->wSecond;\
	 (pSYTM)->tm_mon  = (pSYSTIME)->wMonth - 1;\
	 (pSYTM)->tm_mday = (pSYSTIME)->wDay;\
	 (pSYTM)->tm_year = (pSYSTIME)->wYear;\
	 (pSYTM)->tm_yday = 0;\
	 (pSYTM)->tm_wday = (pSYSTIME)->wDayOfWeek;\
	 (pSYTM)->tm_gmtoff = 0;\
	 (pSYTM)->tm_isdst = -1;\
	 (pSYTM)->tm_zone = 0;

struct SyMemMethods 
{
	void * (*xAlloc)(unsigned int);         
	void * (*xRealloc)(void *,unsigned int);
	void   (*xFree)(void *);                
	unsigned int  (*xChunkSize)(void *);    
	int    (*xInit)(void *);                
	void   (*xRelease)(void *);             
	void  *pUserData;                       
};
typedef int (*ProcMemError)(void *);
struct SyMutexMethods 
{
	int (*xGlobalInit)(void);	
	void  (*xGlobalRelease)(void);
	SyMutex * (*xNew)(int);	       
	void  (*xRelease)(SyMutex *);
	void  (*xEnter)(SyMutex *);	   
	int (*xTryEnter)(SyMutex *);   
	void  (*xLeave)(SyMutex *);	   
};
#if defined (_MSC_VER) || defined (__MINGW32__) ||  defined (__GNUC__) && defined (__declspec)
#define SX_APIIMPORT	__declspec(dllimport)
#define SX_APIEXPORT	__declspec(dllexport)
#else
#define	SX_APIIMPORT
#define	SX_APIEXPORT
#endif
#define SXRET_OK       0     	
#define SXERR_MEM      (-1)  
#define SXERR_IO       (-2)  
#define SXERR_EMPTY    (-3)  
#define SXERR_LOCKED   (-4)  
#define SXERR_ORANGE   (-5)  
#define SXERR_NOTFOUND (-6)  
#define SXERR_LIMIT    (-7)  
#define SXERR_MORE     (-8)  
#define SXERR_INVALID  (-9)  
#define SXERR_ABORT    (-10) 
#define SXERR_EXISTS   (-11) 
#define SXERR_SYNTAX   (-12) 
#define SXERR_UNKNOWN  (-13) 
#define SXERR_BUSY     (-14) 
#define SXERR_OVERFLOW (-15) 
#define SXERR_WILLBLOCK (-16)
#define SXERR_NOTIMPLEMENTED  (-17)
#define SXERR_EOF      (-18)
#define SXERR_PERM     (-19)
#define SXERR_NOOP     (-20)	
#define SXERR_FORMAT   (-21)
#define SXERR_NEXT     (-22)
#define SXERR_OS       (-23)
#define SXERR_CORRUPT  (-24)
#define SXERR_CONTINUE (-25)
#define SXERR_NOMATCH  (-26)
#define SXERR_RESET    (-27)
#define SXERR_DONE     (-28)
#define SXERR_SHORT    (-29)
#define SXERR_PATH     (-30)
#define SXERR_TIMEOUT  (-31)
#define SXERR_BIG      (-32)
#define SXERR_RETRY    (-33)
#define SXERR_IGNORE   (-63)
#endif
#define PH7_OK      SXRET_OK     
#define PH7_NOMEM   SXERR_MEM    
#define PH7_ABORT   SXERR_ABORT  
#define PH7_IO_ERR  SXERR_IO     
#define PH7_CORRUPT SXERR_CORRUPT
#define PH7_LOOKED  SXERR_LOCKED  
#define PH7_COMPILE_ERR (-70)    
#define PH7_VM_ERR      (-71)    
#ifdef PH7_OMIT_FLOATING_POINT
typedef sxi64 ph7_real;
#else
typedef double ph7_real;
#endif
typedef sxi64 ph7_int64;
#define PH7_APIEXPORT SX_APIEXPORT
#define PH7_CONFIG_ERR_OUTPUT    1 
#define PH7_CONFIG_ERR_ABORT     2 
#define PH7_CONFIG_ERR_LOG       3 
#define PH7_VM_CONFIG_OUTPUT           1 
#define PH7_VM_CONFIG_IMPORT_PATH      3 
#define PH7_VM_CONFIG_ERR_REPORT       4 
#define PH7_VM_CONFIG_RECURSION_DEPTH  5 
#define PH7_VM_OUTPUT_LENGTH           6 
#define PH7_VM_CONFIG_CREATE_SUPER     7 
#define PH7_VM_CONFIG_CREATE_VAR       8 
#define PH7_VM_CONFIG_HTTP_REQUEST     9 
#define PH7_VM_CONFIG_SERVER_ATTR     10 
#define PH7_VM_CONFIG_ENV_ATTR        11 
#define PH7_VM_CONFIG_SESSION_ATTR    12 
#define PH7_VM_CONFIG_POST_ATTR       13 
#define PH7_VM_CONFIG_GET_ATTR        14 
#define PH7_VM_CONFIG_COOKIE_ATTR     15 
#define PH7_VM_CONFIG_HEADER_ATTR     16 
#define PH7_VM_CONFIG_EXEC_VALUE      17 
#define PH7_VM_CONFIG_IO_STREAM       18 
#define PH7_VM_CONFIG_ARGV_ENTRY      19 
#define PH7_VM_CONFIG_EXTRACT_OUTPUT  20 
#define PH7_VM_CONFIG_ERR_LOG_HANDLER 21 
#define PH7_LIB_CONFIG_USER_MALLOC            1 
#define PH7_LIB_CONFIG_MEM_ERR_CALLBACK       2
#define PH7_LIB_CONFIG_USER_MUTEX             3 
#define PH7_LIB_CONFIG_THREAD_LEVEL_SINGLE    4 
#define PH7_LIB_CONFIG_THREAD_LEVEL_MULTI     5 
#define PH7_LIB_CONFIG_VFS                    6
#define PH7_PHP_ONLY 0x01
#define PH7_PHP_EXPR 0x02
#define PH7_CTX_ERR      1
#define PH7_CTX_WARNING  2
#define PH7_CTX_NOTICE   3
#define PH7_VFS_VERSION 2 
struct ph7_vfs
{
	const char *zName; 
	int iVersion;      
	int (*xChdir)(const char *);                    
	int (*xChroot)(const char *);                   
	int (*xGetcwd)(ph7_context *);                  
	int (*xMkdir)(const char *,int,int);            
	int (*xRmdir)(const char *);                    
	int (*xIsdir)(const char *);                    
	int (*xRename)(const char *,const char *);      
	int (*xRealpath)(const char *,ph7_context *);   
	int (*xSleep)(unsigned int);                    
	int (*xUnlink)(const char *);                   
	int (*xFileExists)(const char *);               
	int (*xChmod)(const char *,int);                
	int (*xChown)(const char *,const char *);       
	int (*xChgrp)(const char *,const char *);       
	ph7_int64 (*xFreeSpace)(const char *);          
	ph7_int64 (*xTotalSpace)(const char *);         
	ph7_int64 (*xFileSize)(const char *);           
	ph7_int64 (*xFileAtime)(const char *);          
	ph7_int64 (*xFileMtime)(const char *);          
	ph7_int64 (*xFileCtime)(const char *);          
	int (*xStat)(const char *,ph7_value *,ph7_value *);  
	int (*xlStat)(const char *,ph7_value *,ph7_value *); 
	int (*xIsfile)(const char *);                   
	int (*xIslink)(const char *);                   
	int (*xReadable)(const char *);                 
	int (*xWritable)(const char *);                 
	int (*xExecutable)(const char *);               
	int (*xFiletype)(const char *,ph7_context *);   
	int (*xGetenv)(const char *,ph7_context *);     
	int (*xSetenv)(const char *,const char *);      
	int (*xTouch)(const char *,ph7_int64,ph7_int64);
	int (*xMmap)(const char *,void **,ph7_int64 *); 
	void (*xUnmap)(void *,ph7_int64);               
	int (*xLink)(const char *,const char *,int);    
	int (*xUmask)(int);                             
	void (*xTempDir)(ph7_context *);                
	unsigned int (*xProcessId)(void);               
	int (*xUid)(void);                              
	int (*xGid)(void);                              
	void (*xUsername)(ph7_context *);               
	int (*xExec)(const char *,ph7_context *);       
};
#define PH7_IO_STREAM_VERSION 1 
#define PH7_IO_OPEN_RDONLY   0x001 
#define PH7_IO_OPEN_WRONLY   0x002 
#define PH7_IO_OPEN_RDWR     0x004 
#define PH7_IO_OPEN_CREATE   0x008 
#define PH7_IO_OPEN_TRUNC    0x010 
#define PH7_IO_OPEN_APPEND   0x020 
#define PH7_IO_OPEN_EXCL     0x040 
#define PH7_IO_OPEN_BINARY   0x080 
#define PH7_IO_OPEN_TEMP     0x100 
#define PH7_IO_OPEN_TEXT     0x200 
struct ph7_io_stream
{
	const char *zName;                                    
	int iVersion;                                         
	int  (*xOpen)(const char *,int,ph7_value *,void **);  
	int  (*xOpenDir)(const char *,ph7_value *,void **);   
	void (*xClose)(void *);                               
	void (*xCloseDir)(void *);                            
	ph7_int64 (*xRead)(void *,void *,ph7_int64);                   
	int (*xReadDir)(void *,ph7_context *);                
	ph7_int64 (*xWrite)(void *,const void *,ph7_int64);   
	int (*xSeek)(void *,ph7_int64,int);                   
	int (*xLock)(void *,int);                             
	void (*xRewindDir)(void *);                           
	ph7_int64 (*xTell)(void *);                           
	int (*xTrunc)(void *,ph7_int64);                      
	int (*xSync)(void *);                                 
	int (*xStat)(void *,ph7_value *,ph7_value *);         
};
PH7_APIEXPORT int ph7_init(ph7 **ppEngine);
PH7_APIEXPORT int ph7_config(ph7 *pEngine,int nConfigOp,...);
PH7_APIEXPORT int ph7_release(ph7 *pEngine);
PH7_APIEXPORT int ph7_compile(ph7 *pEngine,const char *zSource,int nLen,ph7_vm **ppOutVm);
PH7_APIEXPORT int ph7_compile_v2(ph7 *pEngine,const char *zSource,int nLen,ph7_vm **ppOutVm,int iFlags);
PH7_APIEXPORT int ph7_compile_file(ph7 *pEngine,const char *zFilePath,ph7_vm **ppOutVm,int iFlags);
PH7_APIEXPORT int ph7_vm_config(ph7_vm *pVm,int iConfigOp,...);
PH7_APIEXPORT int ph7_vm_exec(ph7_vm *pVm,int *pExitStatus);
PH7_APIEXPORT int ph7_vm_reset(ph7_vm *pVm);
PH7_APIEXPORT int ph7_vm_release(ph7_vm *pVm);
PH7_APIEXPORT int ph7_vm_dump_v2(ph7_vm *pVm,int (*xConsumer)(const void *,unsigned int,void *),void *pUserData);
PH7_APIEXPORT int ph7_create_function(ph7_vm *pVm,const char *zName,int (*xFunc)(ph7_context *,int,ph7_value **),void *pUserData);
PH7_APIEXPORT int ph7_delete_function(ph7_vm *pVm,const char *zName);
PH7_APIEXPORT int ph7_create_constant(ph7_vm *pVm,const char *zName,void (*xExpand)(ph7_value *,void *),void *pUserData);
PH7_APIEXPORT int ph7_delete_constant(ph7_vm *pVm,const char *zName);
PH7_APIEXPORT int ph7_value_to_int(ph7_value *pValue);
PH7_APIEXPORT int ph7_value_to_bool(ph7_value *pValue);
PH7_APIEXPORT ph7_int64 ph7_value_to_int64(ph7_value *pValue);
PH7_APIEXPORT double ph7_value_to_double(ph7_value *pValue);
PH7_APIEXPORT const char * ph7_value_to_string(ph7_value *pValue,int *pLen);
PH7_APIEXPORT void * ph7_value_to_resource(ph7_value *pValue);
PH7_APIEXPORT int ph7_value_compare(ph7_value *pLeft,ph7_value *pRight,int bStrict);
PH7_APIEXPORT int ph7_result_int(ph7_context *pCtx,int iValue);
PH7_APIEXPORT int ph7_result_int64(ph7_context *pCtx,ph7_int64 iValue);
PH7_APIEXPORT int ph7_result_bool(ph7_context *pCtx,int iBool);
PH7_APIEXPORT int ph7_result_double(ph7_context *pCtx,double Value);
PH7_APIEXPORT int ph7_result_null(ph7_context *pCtx);
PH7_APIEXPORT int ph7_result_string(ph7_context *pCtx,const char *zString,int nLen);
PH7_APIEXPORT int ph7_result_string_format(ph7_context *pCtx,const char *zFormat,...);
PH7_APIEXPORT int ph7_result_value(ph7_context *pCtx,ph7_value *pValue);
PH7_APIEXPORT int ph7_result_resource(ph7_context *pCtx,void *pUserData);
PH7_APIEXPORT int ph7_context_output(ph7_context *pCtx,const char *zString,int nLen);
PH7_APIEXPORT int ph7_context_output_format(ph7_context *pCtx,const char *zFormat,...);
PH7_APIEXPORT int ph7_context_throw_error(ph7_context *pCtx,int iErr,const char *zErr);
PH7_APIEXPORT int ph7_context_throw_error_format(ph7_context *pCtx,int iErr,const char *zFormat,...);
PH7_APIEXPORT unsigned int ph7_context_random_num(ph7_context *pCtx);
PH7_APIEXPORT int ph7_context_random_string(ph7_context *pCtx,char *zBuf,int nBuflen);
PH7_APIEXPORT void * ph7_context_user_data(ph7_context *pCtx);
PH7_APIEXPORT int    ph7_context_push_aux_data(ph7_context *pCtx,void *pUserData);
PH7_APIEXPORT void * ph7_context_peek_aux_data(ph7_context *pCtx);
PH7_APIEXPORT void * ph7_context_pop_aux_data(ph7_context *pCtx);
PH7_APIEXPORT unsigned int ph7_context_result_buf_length(ph7_context *pCtx);
PH7_APIEXPORT const char * ph7_function_name(ph7_context *pCtx);
PH7_APIEXPORT void * ph7_context_alloc_chunk(ph7_context *pCtx,unsigned int nByte,int ZeroChunk,int AutoRelease);
PH7_APIEXPORT void * ph7_context_realloc_chunk(ph7_context *pCtx,void *pChunk,unsigned int nByte);
PH7_APIEXPORT void ph7_context_free_chunk(ph7_context *pCtx,void *pChunk);
PH7_APIEXPORT ph7_value * ph7_new_scalar(ph7_vm *pVm);
PH7_APIEXPORT ph7_value * ph7_new_array(ph7_vm *pVm);
PH7_APIEXPORT int ph7_release_value(ph7_vm *pVm,ph7_value *pValue);
PH7_APIEXPORT ph7_value * ph7_context_new_scalar(ph7_context *pCtx);
PH7_APIEXPORT ph7_value * ph7_context_new_array(ph7_context *pCtx);
PH7_APIEXPORT void ph7_context_release_value(ph7_context *pCtx,ph7_value *pValue);
PH7_APIEXPORT int ph7_value_int(ph7_value *pVal,int iValue);
PH7_APIEXPORT int ph7_value_int64(ph7_value *pVal,ph7_int64 iValue);
PH7_APIEXPORT int ph7_value_bool(ph7_value *pVal,int iBool);
PH7_APIEXPORT int ph7_value_null(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_double(ph7_value *pVal,double Value);
PH7_APIEXPORT int ph7_value_string(ph7_value *pVal,const char *zString,int nLen);
PH7_APIEXPORT int ph7_value_string_format(ph7_value *pVal,const char *zFormat,...);
PH7_APIEXPORT int ph7_value_reset_string_cursor(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_resource(ph7_value *pVal,void *pUserData);
PH7_APIEXPORT int ph7_value_release(ph7_value *pVal);
PH7_APIEXPORT ph7_value * ph7_array_fetch(ph7_value *pArray,const char *zKey,int nByte);
PH7_APIEXPORT int ph7_array_walk(ph7_value *pArray,int (*xWalk)(ph7_value *,ph7_value *,void *),void *pUserData);
PH7_APIEXPORT int ph7_array_add_elem(ph7_value *pArray,ph7_value *pKey,ph7_value *pValue);
PH7_APIEXPORT int ph7_array_add_strkey_elem(ph7_value *pArray,const char *zKey,ph7_value *pValue);
PH7_APIEXPORT int ph7_array_add_intkey_elem(ph7_value *pArray,int iKey,ph7_value *pValue);
PH7_APIEXPORT unsigned int ph7_array_count(ph7_value *pArray);
PH7_APIEXPORT int ph7_object_walk(ph7_value *pObject,int (*xWalk)(const char *,ph7_value *,void *),void *pUserData);
PH7_APIEXPORT ph7_value * ph7_object_fetch_attr(ph7_value *pObject,const char *zAttr);
PH7_APIEXPORT const char * ph7_object_get_class_name(ph7_value *pObject,int *pLength);
PH7_APIEXPORT int ph7_value_is_int(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_float(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_bool(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_string(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_null(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_numeric(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_callable(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_scalar(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_array(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_object(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_resource(ph7_value *pVal);
PH7_APIEXPORT int ph7_value_is_empty(ph7_value *pVal);
PH7_APIEXPORT int ph7_lib_init(void);
PH7_APIEXPORT int ph7_lib_config(int nConfigOp,...);
PH7_APIEXPORT int ph7_lib_shutdown(void);
PH7_APIEXPORT int ph7_lib_is_threadsafe(void);
PH7_APIEXPORT const char * ph7_lib_version(void);
PH7_APIEXPORT const char * ph7_lib_signature(void);
PH7_APIEXPORT const char * ph7_lib_ident(void);
PH7_APIEXPORT const char * ph7_lib_copyright(void);
#ifdef __cplusplus
}
#endif
#endif