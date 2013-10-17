#pragma once
#include <exdisp.h>
#include "ControlEx.h"

class ClientHandler;
class CTreeViewController;

class CMainFrame : public CWindowWnd, public INotifyUI
{
public:
    CMainFrame();

    LPCTSTR GetWindowClassName() const;
    UINT GetClassStyle() const;
    void OnFinalMessage(HWND /*hWnd*/);

    void Init();
    void OnPrepare();
    
    bool OnCefWndSize(void *pParam);
    
    void Notify(TNotifyUI& msg);
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

public:
    CPaintManagerUI m_pm;
    
private:
    CButtonUI* m_pCloseBtn;
    CButtonUI* m_pMaxBtn;
    CButtonUI* m_pRestoreBtn;
    CButtonUI* m_pMinBtn;
    CHorizontalLayoutUI* m_pEditLayout;

    ClientHandler *m_pClientHandler;
    CTreeViewController *m_pTreeViewController;
};
