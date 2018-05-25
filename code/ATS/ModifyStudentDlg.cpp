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
	ON_BN_CLICKED(IDC_BUTTON_STUDENT_NUMBER, OnButtonStudentNumber)
	ON_BN_CLICKED(IDC_BUTTON_USER_NAME, OnButtonUserName)
	ON_BN_CLICKED(IDC_BUTTON_BIRTHDAY, OnButtonBirthday)
	ON_BN_CLICKED(IDC_BUTTON_OPERATING_SYSTEM, OnButtonOperatingSystem)
	ON_BN_CLICKED(IDC_BUTTON_PASSWORD, OnButtonPassword)
	ON_BN_CLICKED(IDC_BUTTON_COMPOSITION_PRINCIPLE, OnButtonCompositionPrinciple)
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

bool flagsnum = false;
void ModifyStudentDlg::OnButtonStudentNumber() 
{
	// TODO: Add your control notification handler code here
	if(!flagsnum)
	{
		CEdit* edit =(CEdit*)GetDlgItem(IDC_EDIT_STUDENT_NUMBER);
		edit->SetReadOnly(FALSE);
		CButton* button=(CButton*)GetDlgItem(IDC_BUTTON_STUDENT_NUMBER);
		button->SetWindowText("确认修改");
		flagsnum = true;
	}
	else
	{
		CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT_STUDENT_NUMBER);
		edit->SetReadOnly(TRUE);
		CButton* button = (CButton*)GetDlgItem(IDC_BUTTON_STUDENT_NUMBER);
		button->SetWindowText("修改");
		UpdateData(TRUE);
		flagsnum = false;
	}
	return;
}

bool flaguname = false;
void ModifyStudentDlg::OnButtonUserName() 
{
	// TODO: Add your control notification handler code here
	if(!flaguname)
	{
		CEdit* edit =(CEdit*)GetDlgItem(IDC_EDIT_USER_NAME);
		edit->SetReadOnly(FALSE);
		CButton* button=(CButton*)GetDlgItem(IDC_BUTTON_USER_NAME);
		button->SetWindowText("确认修改");
		flaguname = true;
	}
	else
	{
		CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT_USER_NAME);
		edit->SetReadOnly(TRUE);
		CButton* button = (CButton*)GetDlgItem(IDC_BUTTON_USER_NAME);
		button->SetWindowText("修改");
		UpdateData(TRUE);
		flaguname = false;
	}
	return;
}

bool flagbirth = false;
void ModifyStudentDlg::OnButtonBirthday() 
{
	// TODO: Add your control notification handler code here
	if(!flagbirth)
	{
		CEdit* edit =(CEdit*)GetDlgItem(IDC_EDIT_BIRTHDAY);
		edit->SetReadOnly(FALSE);
		CButton* button=(CButton*)GetDlgItem(IDC_BUTTON_BIRTHDAY);
		button->SetWindowText("确认修改");
		flagbirth = true;
	}
	else
	{
		CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT_BIRTHDAY);
		edit->SetReadOnly(TRUE);
		CButton* button = (CButton*)GetDlgItem(IDC_BUTTON_BIRTHDAY);
		button->SetWindowText("修改");
		UpdateData(TRUE);
		flagbirth = false;
	}
	return;
}

bool flagpwd = false;
void ModifyStudentDlg::OnButtonPassword() 
{
	// TODO: Add your control notification handler code here
	if(!flagpwd)
	{
		CEdit* edit =(CEdit*)GetDlgItem(IDC_EDIT_PASSWORD);
		edit->SetReadOnly(FALSE);
		CButton* button=(CButton*)GetDlgItem(IDC_BUTTON_PASSWORD);
		button->SetWindowText("确认修改");
		flagpwd = true;
	}
	else
	{
		CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT_PASSWORD);
		edit->SetReadOnly(TRUE);
		CButton* button = (CButton*)GetDlgItem(IDC_BUTTON_PASSWORD);
		button->SetWindowText("修改");
		UpdateData(TRUE);
		flagpwd = false;
	}
	return;
}

bool flagosystem = false;
void ModifyStudentDlg::OnButtonOperatingSystem() 
{
	// TODO: Add your control notification handler code here
	if(!flagosystem)
	{
		CEdit* edit =(CEdit*)GetDlgItem(IDC_EDIT_OPERATING_SYSTEM);
		edit->SetReadOnly(FALSE);
		CButton* button=(CButton*)GetDlgItem(IDC_BUTTON_OPERATING_SYSTEM);
		button->SetWindowText("确认修改");
		flagosystem = true;
	}
	else
	{
		CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT_OPERATING_SYSTEM);
		edit->SetReadOnly(TRUE);
		CButton* button = (CButton*)GetDlgItem(IDC_BUTTON_OPERATING_SYSTEM);
		button->SetWindowText("修改");
		UpdateData(TRUE);
		flagosystem = false;
	}
	return;
}

bool flagcprinciple = false;
void ModifyStudentDlg::OnButtonCompositionPrinciple() 
{
	// TODO: Add your control notification handler code here
	if(!flagcprinciple)
	{
		CEdit* edit =(CEdit*)GetDlgItem(IDC_EDIT_COMPOSITION_PRINCIPLE);
		edit->SetReadOnly(FALSE);
		CButton* button=(CButton*)GetDlgItem(IDC_BUTTON_COMPOSITION_PRINCIPLE);
		button->SetWindowText("确认修改");
		flagcprinciple = true;
	}
	else
	{
		CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT_COMPOSITION_PRINCIPLE);
		edit->SetReadOnly(TRUE);
		CButton* button = (CButton*)GetDlgItem(IDC_BUTTON_COMPOSITION_PRINCIPLE);
		button->SetWindowText("修改");
		UpdateData(TRUE);
		flagcprinciple = false;
	}
	return;
}
