// RegisterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "RegisterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RegisterDlg dialog


RegisterDlg::RegisterDlg(CWnd* pParent /*=NULL*/, Database* dB)
	: CDialog(RegisterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(RegisterDlg)
	m_stu_num = _T("");
	m_name = _T("");
	m_rpwd = _T("");
	m_rrpwd = _T("");
	m_birth = _T("");
	m_sex = _T("");
	mydB = dB;
	repeat = false;
	//}}AFX_DATA_INIT
}


void RegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RegisterDlg)
	DDX_Text(pDX, IDC_EDIT_STUDENT_NUMBER, m_stu_num);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_REGISTER_PASSWORD, m_rpwd);
	DDX_Text(pDX, IDC_EDIT_REPEAT_PASSWORD, m_rrpwd);
	DDX_Text(pDX, IDC_EDIT_BIRTHDAY, m_birth);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RegisterDlg, CDialog)
	//{{AFX_MSG_MAP(RegisterDlg)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RegisterDlg message handlers

BOOL RegisterDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	cancelFlag = false;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void RegisterDlg::OnCancel() 
{
	// TODO: Add extra cleanup here

	cancelFlag = true;
	
	CDialog::OnCancel();
}

void RegisterDlg::OnButtonOk() 
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	if(m_stu_num.IsEmpty())
	{
		AfxMessageBox("学号不能为空！");
		return;
	}
	if(m_name.IsEmpty())
	{
		AfxMessageBox("姓名不能为空！");
		return;
	}
	if(m_rpwd.IsEmpty())
	{
		AfxMessageBox("密码不能为空！");
		return;
	}
	
	if(m_rrpwd.IsEmpty())
	{
		AfxMessageBox("重复密码不能为空！");
		return;
	}
	if(m_birth.IsEmpty())
	{
		AfxMessageBox("生日不能为空！");
		return;
	}

	if(m_stu_num.GetLength() != 3)
	{
		MessageBox("学号必须为3位！");
		m_stu_num = "";
		return;
	}

	int i;
	for (i = 0; i < m_stu_num.GetLength(); ++i)
	{
		if(m_stu_num[i] >= '0' && m_stu_num <= '9')
		{
			continue;
		}
		MessageBox("学号必须为数字！");
		m_stu_num = "";
		return;
	}

	if(m_rpwd != m_rrpwd)
	{
		MessageBox("两次密码不一致!");
		m_name = "";
		m_stu_num = "";
		m_rpwd = "";
		m_rrpwd = "";
		m_birth = "";
		UpdateData(FALSE);
		return;
	}
	
	if(m_birth.GetLength() != 10)
	{
		MessageBox("生日格式为yyyy-mm-dd！");
		m_birth = "";
		return;
	}
		
	for (i = 0; i < m_birth.GetLength(); ++i)
	{
		if(m_birth[i] >= '0' && m_birth <= '9')
		{
			continue;
		}
		else if((i == 4 || i == 7) && m_birth[i] == '-')
		{
			continue;
		}
		MessageBox("生日格式为yyyy-mm-dd！");
		m_birth = "";
		return;
	}

	int select = GetCheckedRadioButton(IDC_RADIO_BOY,IDC_RADIO_GIRL);
	if(select == 0)
	{
		MessageBox("请选择性别！");
		UpdateData(FALSE);
		return;
	}
	if(select == IDC_RADIO_BOY)
	{
		m_sex = "男";
	}
	else
	{
		m_sex = "女";
	}
	
	CString strSql = "select * from Student where stu_num='"+m_stu_num+"'";
	
	mydB->pRecordset = mydB->GetRecord(strSql);
	if(!mydB->pRecordset->adoEOF)
	{
		MessageBox("用户名已存在！");
		m_name = "";
		m_stu_num = "";
		m_rpwd = "";
		m_rrpwd = "";
		m_birth = "";
		UpdateData(FALSE);
		mydB->pRecordset->Close();
		return;
	}
	UpdateData(TRUE);

	try
	{
		mydB->pRecordset->AddNew();
		mydB->pRecordset->PutCollect("stu_num", _variant_t(m_stu_num));
		mydB->pRecordset->PutCollect("user_name", _variant_t(m_name));
		mydB->pRecordset->PutCollect("password", _variant_t(m_rpwd));
		mydB->pRecordset->PutCollect("birthday", _variant_t(m_birth));
		
		mydB->pRecordset->Update();
		mydB->pRecordset->Close();
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
		return;
	}

	OnOK();
	MessageBox("注册成功！");
}
