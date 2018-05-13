// Database.h: interface for the Database class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASE_H__0ACB303E_B935_49D3_91B3_B9940B41F716__INCLUDED_)
#define AFX_DATABASE_H__0ACB303E_B935_49D3_91B3_B9940B41F716__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Database  
{
public:
	Database();
	virtual ~Database();

	// 初始化数据库连接
	void OnInitADOConn();
	// 获得记录
	_RecordsetPtr GetRecord(CString strSql);
	// 退出连接
	void ExitConnect();
	// 命令
	void MyCommand(CString strSql);

	// 连接指针
	_ConnectionPtr pConnection;
	// 记录设置指针
	_RecordsetPtr pRecordset;
};

#endif // !defined(AFX_DATABASE_H__0ACB303E_B935_49D3_91B3_B9940B41F716__INCLUDED_)
