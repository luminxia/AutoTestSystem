// StudentManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "StudentManagerDlg.h"
#include "ModifyStudentDlg.h"

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
	m_smd_stu_num = _T("");
	//}}AFX_DATA_INIT
}


void StudentManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(StudentManagerDlg)
	DDX_Control(pDX, IDC_LIST_STUDENT, m_list);
	DDX_Text(pDX, IDC_EDIT_STUDENT_NUMBER, m_smd_stu_num);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(StudentManagerDlg, CDialog)
	//{{AFX_MSG_MAP(StudentManagerDlg)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// StudentManagerDlg message handlers

BOOL StudentManagerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE);
	m_list.InsertColumn(0, "学号", LVCFMT_CENTER, 100, 0);
	m_list.InsertColumn(1, "姓名", LVCFMT_CENTER, 100, 1);
	m_list.InsertColumn(2, "科目", LVCFMT_CENTER, 200, 2);
	m_list.InsertColumn(3, "分数", LVCFMT_CENTER, 100, 3);
	
	ShowStudentInfo();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// 显示学生信息
void StudentManagerDlg::ShowStudentInfo()
{
	CString sql = "select Student.stu_num, user_name, course_name, score from Student,Score where Student.stu_num = Score.stu_num";
	dB.OnInitADOConn();
	dB.GetRecord(sql);

	int i = 0;
	CString snum, score;
	while(dB.pRecordset->adoEOF == 0)
	{
		_variant_t _var;
		int vi;
		m_list.InsertItem(i, "");
		vi=(long)(_variant_t)(dB.pRecordset->GetCollect("stu_num"));
		snum.Format("%d", vi);
		
		vi=(long)(_variant_t)(dB.pRecordset->GetCollect("score"));
		score.Format("%d", vi);
		
		m_list.SetItemText(i, 0, snum);
		m_list.SetItemText(i, 1, (char*)(_bstr_t)dB.pRecordset->GetCollect("user_name"));
		m_list.SetItemText(i, 2, (char*)(_bstr_t)dB.pRecordset->GetCollect("course_name"));
		m_list.SetItemText(i, 3, score);
		i++;
		dB.pRecordset->MoveNext();
	}
	
	dB.pRecordset->Close();
}

void StudentManagerDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ModifyStudentDlg msDlg(NULL, m_smd_stu_num);
	msDlg.DoModal();
	m_list.DeleteAllItems( );
	ShowStudentInfo();
}
