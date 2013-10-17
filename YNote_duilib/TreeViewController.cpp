#include "stdafx.h"
#include "TreeViewController.h"


CTreeViewController::CTreeViewController(CTreeViewUI *pTreeViewUI)
    : m_pTreeViewUI(pTreeViewUI)
{
    ASSERT(m_pTreeViewUI);
}


CTreeViewController::~CTreeViewController(void)
{
}

bool CTreeViewController::OnInit(void *pParam)
{
    CTreeNodeUI *pControlUI = static_cast<CTreeNodeUI*>(pParam);
    return true;
}

bool CTreeViewController::OnNotify(void *pParam)
{
    TNotifyUI *pNotifyUI = static_cast<TNotifyUI*>(pParam);
    if (pNotifyUI->sType = DUI_MSGTYPE_SELECTCHANGED)
    {
        int i = 10;
    }
    return true;
}

bool CTreeViewController::OnEvent(void *pParam)
{
    TEventUI *pEventUI = static_cast<TEventUI*>(pParam);
    if (pEventUI->Type == UIEVENT_KEYDOWN)
    {
        if (pEventUI->chKey == VK_DELETE)
        {
            CTreeNodeUI *pControlSel = static_cast<CTreeNodeUI*>(m_pTreeViewUI->GetItemAt(m_pTreeViewUI->GetCurSel()));
            m_pTreeViewUI->Remove(pControlSel);
            return false;
        }
    }
    return true;
}
