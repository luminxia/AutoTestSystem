// SelectManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "SelectManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SelectManagerDlg dialog


SelectManagerDlg::SelectManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(SelectManagerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(SelectManagerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SelectManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SelectManagerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SelectManagerDlg, CDialog)
	//{{AFX_MSG_MAP(SelectManagerDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SelectManagerDlg message handlers
