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


PaperDlg::PaperDlg(CWnd* pParent /*=NULL*/, Question *q)
	: CDialog(PaperDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(PaperDlg)
		// NOTE: the ClassWizard will add member initialization here

	question = q->question;
	a = q->choice_a;
	b = q->choice_b;
	c = q->choice_c;
	d = q->choice_d;	
	scoreSum=0;

	//}}AFX_DATA_INIT

	for(int i = 0; i < 4; i++)
	{
		score[i]=q->score[i];
	}
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
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PaperDlg message handlers

BOOL PaperDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	SetDlgItemText(IDC_EDIT_QUESTION, question);
	SetDlgItemText(IDC_RADIO_A, a);
	SetDlgItemText(IDC_RADIO_B, b);
	SetDlgItemText(IDC_RADIO_C, c);
	SetDlgItemText(IDC_RADIO_D, d);
	
	UpdateData(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PaperDlg::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	int s = GetCheckedRadioButton(IDC_RADIO_A, IDC_RADIO_D);	
	if(s == 0)
	{
		MessageBox("«Î—°‘Ò£°");
	}
	else
	{
		switch(s)
		{
		case IDC_RADIO_A:
			scoreSum = scoreSum + score[0] * 10;
			break;
			
		case IDC_RADIO_B:
			scoreSum = scoreSum + score[1] * 10;
			break;
			
		case IDC_RADIO_C:
			scoreSum = scoreSum + score[2] * 10;
			break;
			
		case IDC_RADIO_D:
			scoreSum = scoreSum + score[3] * 10;
			break;
			
		default:
			break;		
		}
		OnOK();
	}
}
