// PaperDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "PaperDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PaperDlg dialog


PaperDlg::PaperDlg(CWnd* pParent /*=NULL*/)
	: CDialog(PaperDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(PaperDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PaperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PaperDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PaperDlg, CDialog)
	//{{AFX_MSG_MAP(PaperDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PaperDlg message handlers
