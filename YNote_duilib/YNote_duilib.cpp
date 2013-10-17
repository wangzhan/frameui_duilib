// YNote_duilib.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "YNote_duilib.h"
#include <comdef.h>
#include "MainFrame.h"

#undef GetNextSibling
#undef GetFirstChild
#include "cef_app.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;								// 当前实例
int Run(HINSTANCE hInstance);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	return Run(hInstance);
}

int Run(HINSTANCE hInstance)
{
    HRESULT Hr = ::CoInitialize(NULL);
    if( FAILED(Hr) ) return 0;
     
    // Initialize CEF.
    CefSettings settings;
    CefRefPtr<CefApp> app;
    settings.multi_threaded_message_loop = true;
    CefInitialize(settings, app);
      
    CPaintManagerUI::SetInstance(hInstance);
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin"));

    CMainFrame* pFrame = new CMainFrame();
    if( pFrame == NULL ) return 0;
    pFrame->Create(NULL, _T("有道云笔记"), UI_WNDSTYLE_FRAME, 0L, 0, 0, 800, 572);
    pFrame->CenterWindow();
    ::ShowWindow(*pFrame, SW_SHOW);

    CPaintManagerUI::MessageLoop();

    // Shut down CEF.
    CefShutdown();

    ::CoUninitialize();
    return 0;
}
