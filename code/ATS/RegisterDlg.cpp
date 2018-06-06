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
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RegisterDlg message handlers
