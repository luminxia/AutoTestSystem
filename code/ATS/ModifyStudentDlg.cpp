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


ModifyStudentDlg::ModifyStudentDlg(CWnd* pParent /*=NULL*/, CString snum)
	: CDialog(ModifyStudentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ModifyStudentDlg)
	stu_num = snum;
	m_birthday = _T("");
	m_composition_principle = _T("");
	m_operating_system = _T("");
	m_password = _T("");
	m_student_number = _T("");
	m_user_name = _T("");
	//}}AFX_DATA_INIT
}


void ModifyStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ModifyStudentDlg)
	DDX_Text(pDX, IDC_EDIT_BIRTHDAY, m_birthday);
	DDX_Text(pDX, IDC_EDIT_COMPOSITION_PRINCIPLE, m_composition_principle);
	DDX_Text(pDX, IDC_EDIT_OPERATING_SYSTEM, m_operating_system);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDX_Text(pDX, IDC_EDIT_STUDENT_NUMBER, m_student_number);
	DDX_Text(pDX, IDC_EDIT_USER_NAME, m_user_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ModifyStudentDlg, CDialog)
	//{{AFX_MSG_MAP(ModifyStudentDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ModifyStudentDlg message handlers

BOOL ModifyStudentDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	CString sql;
	sql.Format("select stu_num,user_name,password,birthday from Student where stu_num='" + stu_num + "'");
	dB.OnInitADOConn();
	dB.GetRecord(sql);
	
	int vi;
	CString num;
	vi = (long)(_variant_t)(dB.pRecordset->GetCollect("stu_num"));
	num.Format("%d",vi);
	m_student_number = num;
	m_user_name = (char*)(_bstr_t)dB.pRecordset->GetCollect("user_name");
	m_password = (char*)(_bstr_t)dB.pRecordset->GetCollect("password");
	m_birthday = (char*)(_bstr_t)dB.pRecordset->GetCollect("birthday");
	
	sql.Format("select score,course_name from Score where stu_num='" + stu_num + "'");
	
	dB.GetRecord(sql);
	long i = 0;
	int count = 0, score = 0;
	CString course_name;
	while(!dB.pRecordset->adoEOF)
	{
		count++;
		dB.pRecordset->MoveNext();
	}
	if(count == 0)
	{
		m_operating_system = "";
		m_composition_principle = "";
	}
	if(count == 1)
	{
		dB.pRecordset->MoveFirst();
		course_name = (char*)(_bstr_t)dB.pRecordset->GetCollect("course_name");
		score = (long)(_variant_t)(dB.pRecordset->GetCollect("score"));
		if(course_name.Compare("计算机组成原理") == 0)
			m_composition_principle.Format("%d", score);
		else
			m_operating_system.Format("%d", score);
	}
	if(count == 2)
	{
		dB.pRecordset->MoveFirst();
		int score1;
		course_name = (char*)(_bstr_t)dB.pRecordset->GetCollect("course_name");
		score = (long)(_variant_t)(dB.pRecordset->GetCollect("score"));
		dB.pRecordset->MoveNext();
		score1 = (long)(_variant_t)(dB.pRecordset->GetCollect("score"));
		if(course_name.Compare("计算机组成原理") == 0)
		{
			m_composition_principle.Format("%d", score);
			m_operating_system.Format("%d", score1);
		}	
		else
		{
			m_operating_system.Format("%d", score);
			m_composition_principle.Format("%d", score1);
		}	
	}
	
	dB.pRecordset->Close();
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
