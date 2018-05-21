// SelectClassDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "SelectClassDlg.h"
#include "PaperDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SelectClassDlg dialog


SelectClassDlg::SelectClassDlg(CWnd* pParent /*=NULL*/)
	: CDialog(SelectClassDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(SelectClassDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SelectClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SelectClassDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SelectClassDlg, CDialog)
	//{{AFX_MSG_MAP(SelectClassDlg)
	ON_BN_CLICKED(IDC_BUTTON_SC_OK, OnButtonScOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SelectClassDlg message handlers

void SelectClassDlg::OnButtonScOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    int s = GetCheckedRadioButton(IDC_RADIO_OPERATING_SYSTEM, IDC_RADIO_COMPOSITION_PRINCIPLE);
	
	if(s == 0)
	{
		MessageBox("ÇëÑ¡Ôñ¿¼ÊÔ¿ÆÄ¿£¡");
		return;
	}
	else
	{
		if(s == IDC_RADIO_OPERATING_SYSTEM)
			selectClass = 1;
		else
			selectClass = 2;
		UpdateData(TRUE);
	}
	
	OnOK();	
}
