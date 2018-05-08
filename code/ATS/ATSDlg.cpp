// ATSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "ATSDlg.h"
#include "RegisterDlg.h"
#include "SelectClassDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CATSDlg dialog

CATSDlg::CATSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CATSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CATSDlg)
	m_user_name = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CATSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CATSDlg)
	DDX_Text(pDX, IDC_EDIT_USER_NAME, m_user_name);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CATSDlg, CDialog)
	//{{AFX_MSG_MAP(CATSDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, OnButtonRegister)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, OnButtonLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CATSDlg message handlers

BOOL CATSDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CATSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CATSDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CATSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CATSDlg::OnButtonRegister() 
{
	// TODO: Add your control notification handler code here
	RegisterDlg  dlg(NULL);
	dlg.DoModal();
}

void CATSDlg::OnButtonLogin() 
{
	// TODO: Add your control notification handler code here
	if(! Login())
	{
		/*theDB.ExitConnect();
		return ;*/
	}
}

bool CATSDlg::Login()
{
	UpdateData(TRUE);
	if(m_user_name.IsEmpty())
	{
		AfxMessageBox("用户名不能为空");
		return false;
	}
	/*if(m_pwd.IsEmpty())
	{
		AfxMessageBox("密码不能为空");
		return  FALSE;
	}
	int selec=GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO2);
	if(selec==0)
	{	MessageBox("选择登陆方式！");
	return FALSE;
	}
	else if(selec==IDC_RADIO1)
		selctid = Stu_;
	else
		selctid = Adm_;
	
	
	
	CString sqlstr;
	if (selctid == Stu_)
		sqlstr="select * from Stu where num="+m_name+" and pwd= '"+m_pwd+"'";
	else 
		sqlstr="select * from Adm where name='"+m_name+"' and pwd= '"+m_pwd+"'";
	
	theDB.m_pRecordset=theDB.GetRecord(sqlstr);
	if(theDB.m_pRecordset->adoEOF)
	{
		MessageBox("用户名不存在!");
		return FALSE;
	}*/
	
    return true;
}
