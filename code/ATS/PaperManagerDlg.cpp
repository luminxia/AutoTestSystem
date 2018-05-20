// PaperManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "PaperManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PaperManagerDlg dialog


PaperManagerDlg::PaperManagerDlg(CWnd* pParent /*=NULL*/, Question *newq, long id, long idMax, CString className/*,Database *dB = NULL*/)
	: CDialog(PaperManagerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(PaperManagerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PaperManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PaperManagerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PaperManagerDlg, CDialog)
	//{{AFX_MSG_MAP(PaperManagerDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PaperManagerDlg message handlers
