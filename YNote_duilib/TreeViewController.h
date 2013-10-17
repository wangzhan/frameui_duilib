#pragma once

namespace DuiLib
{
    class CTreeViewUI;
}


class CTreeViewController
{
public:
    CTreeViewController(CTreeViewUI *pTreeViewUI);
    ~CTreeViewController(void);

public:
    bool OnInit(void *pParam);
    bool OnNotify(void *pParam);
    bool OnEvent(void *pParam);

private:
    CTreeViewUI *m_pTreeViewUI;
};
