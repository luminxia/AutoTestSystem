// Database.h: interface for the Database class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASE_H__0ACB303E_B935_49D3_91B3_B9940B41F716__INCLUDED_)
#define AFX_DATABASE_H__0ACB303E_B935_49D3_91B3_B9940B41F716__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Question.h"

class Database  
{
public:
	Database();
	virtual ~Database();

	// ��ʼ�����ݿ�����
	void OnInitADOConn();
	// ��ü�¼
	_RecordsetPtr GetRecord(CString strSql);
	// �˳�����
	void ExitConnect();
	// ����
	void MyCommand(CString strSql);
	// ��ȡ��¼����
	int GetRecordNum(CString fromTable);
	// ��ȡ����
	Question* GetQuestion(long questionId);

	// ����ָ��
	_ConnectionPtr pConnection;
	// ��¼����ָ��
	_RecordsetPtr pRecordset;
	// �����
	_variant_t var;
	// ������
	Question theQuestion;
};

#endif // !defined(AFX_DATABASE_H__0ACB303E_B935_49D3_91B3_B9940B41F716__INCLUDED_)
