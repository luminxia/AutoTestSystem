// ModifyStudentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "ModifyStudentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ModifyStudentDlg dialog


ModifyStudentDlg::ModifyStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ModifyStudentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ModifyStudentDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ModifyStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ModifyStudentDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ModifyStudentDlg, CDialog)
	//{{AFX_MSG_MAP(ModifyStudentDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ModifyStudentDlg message handlers
