// ScoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "ScoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ScoreDlg dialog


ScoreDlg::ScoreDlg(CWnd* pParent /*=NULL*/, CString stu_num, CString theClass, int score)
	: CDialog(ScoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ScoreDlg)
	m_class = theClass ;
	m_stu_num = stu_num;
	m_score = score;
	//}}AFX_DATA_INIT	
}


void ScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ScoreDlg)
	DDX_Text(pDX, IDC_EDIT_CLASS, m_class);
	DDX_Text(pDX, IDC_EDIT_STUDENT_NUMBER, m_stu_num);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_score);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ScoreDlg, CDialog)
	//{{AFX_MSG_MAP(ScoreDlg)
	ON_BN_CLICKED(IDC_BUTTON_S_OK, OnButtonSOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ScoreDlg message handlers

BOOL ScoreDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ScoreDlg::OnButtonSOk() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
