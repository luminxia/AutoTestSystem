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
	ON_BN_CLICKED(IDC_BUTTON_SM_OK, OnButtonSmOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SelectManagerDlg message handlers

void SelectManagerDlg::OnButtonSmOk() 
{
	// TODO: Add your control notification handler code here
	int s = GetCheckedRadioButton(IDC_RADIO_STUDENT_MANAGER, IDC_RADIO_PAPER);
	if(s == 0)
	{
		MessageBox("请选择管理对象！");
		return;
	}
	else
	{
		if(s == IDC_RADIO_STUDENT_MANAGER)
		{
			managerSelect = 1;
		}
		else
		{
			managerSelect = 2;
		}
	}
	CDialog::OnOK();
}
