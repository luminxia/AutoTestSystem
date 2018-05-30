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
	m_id = id;
	m_choice_a = _T("");
	m_choice_b = _T("");
	m_choice_c = _T("");
	m_choice_d = _T("");
	m_question = _T("");
	myclassName = className;
	myidMax = idMax ;
	//}}AFX_DATA_INIT

	if(id == 0)
	{
		m_id = id;
		m_question = "";
		m_choice_a = "";
		m_choice_b = "";
		m_choice_c = "";
		m_choice_d = "";
		
		for(int i = 0; i < 4; i++)
		{
			score[i]=0;	
		}
	}
	else
	{
		m_id = id;
		m_question = newq->question;
		m_choice_a = newq->choice_a;
		m_choice_b = newq->choice_b;
		m_choice_c = newq->choice_c;
		m_choice_d = newq->choice_d;
		
		for(int i = 0; i < 4; i++)
		{
			score[i] = newq->score[i];
		}
	}
}


void PaperManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PaperManagerDlg)
	DDX_Control(pDX, IDC_COMBO_D, m_cb_d);
	DDX_Control(pDX, IDC_COMBO_C, m_cb_c);
	DDX_Control(pDX, IDC_COMBO_B, m_cb_b);
	DDX_Control(pDX, IDC_COMBO_A, m_cb_a);
	DDX_Text(pDX, IDC_EDIT_PAGE, m_id);
	DDX_Text(pDX, IDC_EDIT_A, m_choice_a);
	DDX_Text(pDX, IDC_EDIT_B, m_choice_b);
	DDX_Text(pDX, IDC_EDIT_C, m_choice_c);
	DDX_Text(pDX, IDC_EDIT_D, m_choice_d);
	DDX_Text(pDX, IDC_EDIT_QUESTION, m_question);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PaperManagerDlg, CDialog)
	//{{AFX_MSG_MAP(PaperManagerDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PaperManagerDlg message handlers

BOOL PaperManagerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	m_cb_a.SetCurSel(score[0]);
	m_cb_b.SetCurSel(score[1]);
	m_cb_c.SetCurSel(score[2]);
	m_cb_d.SetCurSel(score[3]);
	UpdateData(FALSE);

	dB.OnInitADOConn();
	addFlag = false;
	strSql = "select * from Paper where course_name ='"+myclassName+"'";

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
