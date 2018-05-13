// ATSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATS.h"
#include "ATSDlg.h"
#include "RegisterDlg.h"
#include "SelectClassDlg.h"
#include "Question.h"

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
	m_password = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CATSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CATSDlg)
	DDX_Text(pDX, IDC_EDIT_USER_NAME, m_user_name);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
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

	scoreSum = 0;

	dB.OnInitADOConn();

	font.CreatePointFont(200, _T("宋体"));
    GetDlgItem(IDC_STATIC_ATUO_TEST_SYSTEM)->SetFont(&font);

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

// 登录
void CATSDlg::OnButtonLogin() 
{
	// TODO: Add your control notification handler code here
	if(! Login())
	{
		dB.ExitConnect();
		return;
	}

	// 身份判断
	if(selectId == Student)
	{
		SelectClassDlg dlg;
		dlg.DoModal();
		if(dlg.selectClass == 1)
		{
			className = "英语";
		}
		else
		{
			className = "计算机";
		}
		
		dB.pRecordset.CreateInstance(__uuidof(Recordset));
		CString strSql = "select * from Score where course_name ='"+className+"'and stu_num="+m_user_name+" ";
		dB.MyCommand(strSql);

		if (!dB.pRecordset->adoEOF)
		{
			MessageBox("该科成绩已存在");
			return;
		}
		
		dB.pRecordset->Close();

		// Paper
		if(!CreatePaper())
		{
			MessageBox("CreaePaper Failed !");
			return;
		}
		else 
		{
			// 写入成绩
			dB.pRecordset.CreateInstance(__uuidof(Recordset));
			CString sqlstr="select * from Score";
			dB.GetRecord(sqlstr);
			
			try
			{
				dB.pRecordset->AddNew();
				dB.pRecordset->PutCollect("course_name", _variant_t(className));
				dB.pRecordset->PutCollect("score", scoreSum);
				dB.pRecordset->PutCollect("stu_num", atol(m_user_name));
				dB.pRecordset->Update();
				
				AfxMessageBox("插入成功!");
			}
			catch(_com_error *e)
			{
				AfxMessageBox(e->ErrorMessage());
			}
		}
		
		// 成绩
		
		/*Finish  fdlg(NULL,m_name,myclassname,mainscoresum);
		fdlg.DoModal();
		
	}*/
	/*else 
	{
		MessageBox("管理员!");
		SelectMana  managedlg;
		managedlg.DoModal();
		if (managedlg.managesel==1)
		{
			//－－－－－学生信息管理－－－－－
			if(!StuManageFace())
				MessageBox("学生信息管理报错!!!");
			Invalidate(TRUE);
			return ;
		}
		else 
		{
			//－－－－－试卷信息管理－－－－－
			if(!PaperManageFace())
				MessageBox("试卷信息管理报错!!!");
			return ;
		}*/
	}
	
	dB.ExitConnect();
	Invalidate(TRUE);

}

// 判断是否登录成功
bool CATSDlg::Login()
{
	UpdateData(TRUE);
	if(m_user_name.IsEmpty())
	{
		AfxMessageBox("用户名不能为空");
		return false;
	}

	if(m_password.IsEmpty())
	{
		AfxMessageBox("密码不能为空");
		return false;
	}

	int select = GetCheckedRadioButton(IDC_RADIO_STUDENT, IDC_RADIO_ADMINISTRATOR);
	if(select == 0)
	{
		MessageBox("选择登陆方式");
		return false;
	}
	else if(select == IDC_RADIO_STUDENT) selectId = Student;
	else selectId = Administrator;
	
	CString sqlStr;
	if (selectId == Student)
		sqlStr = "select * from Student where stu_num=" + m_user_name + " and password= '" + m_password + "'";
	else
		sqlStr = "select * from Administrator where adm_name=" + m_user_name + " and password= '" + m_password + "'";
	
	dB.pRecordset = dB.GetRecord(sqlStr);
	if(dB.pRecordset->adoEOF)
	{
		MessageBox("用户名不存在!");
		return false;
	}
	
    return true;
}

// 判断是否创建试卷
bool CATSDlg::CreatePaper()
{
	SetTimer(1, 1000, NULL);
	SetTimer(2, 540000, NULL);
	SetTimer(3, 600000, NULL);
	
	CString strSql = "select * from Paper where course_name ='"+className+"'";
	
	dB.MyCommand(strSql);
	
	int questionCount =0 ;
	
	_variant_t var;
	Question q;
	
	while(!dB.pRecordset->adoEOF)
	{
		var = dB.pRecordset->GetCollect("question");
		if(var.vt != VT_NULL)
			q.question= (LPCSTR)_bstr_t(var);
		
		var = dB.pRecordset->GetCollect("choice_a");
		if(var.vt != VT_NULL)
			q.choice_a = (LPCSTR)_bstr_t(var);
		var = dB.pRecordset->GetCollect("choice_b");
		if(var.vt != VT_NULL)
			q.choice_b = (LPCSTR)_bstr_t(var);
		var = dB.pRecordset->GetCollect("choice_c");
		if(var.vt != VT_NULL)
			q.choice_c = (LPCSTR)_bstr_t(var);
		var = dB.pRecordset->GetCollect("choice_d");
		if(var.vt != VT_NULL)
			q.choice_d = (LPCSTR)_bstr_t(var);
		
		_variant_t var;
		var = dB.pRecordset->GetCollect("score_a");
		if(var.vt != VT_NULL)
			q.score[0] = (long)var;
		var = dB.pRecordset->GetCollect("score_b");
		if(var.vt != VT_NULL)
			q.score[1] = var.lVal;
		var = dB.pRecordset->GetCollect("score_c");
		if(var.vt != VT_NULL)
			q.score[2] = var.lVal;
		var = dB.pRecordset->GetCollect("score_d");
		if(var.vt != VT_NULL)
			q.score[3] = var.lVal;
		
		PaperDlg paper(NULL, &q);
		paper.DoModal();
		
		// finish分数
		scoreSum += paper.scoreSum;
		dB.pRecordset->MoveNext();
		questionCount++;
	}
	dB.pRecordset->Close();
	return true;
}
