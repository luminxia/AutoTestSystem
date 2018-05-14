// StudentManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "StudentManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// StudentManagerDlg dialog


StudentManagerDlg::StudentManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(StudentManagerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(StudentManagerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void StudentManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(StudentManagerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(StudentManagerDlg, CDialog)
	//{{AFX_MSG_MAP(StudentManagerDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// StudentManagerDlg message handlers
