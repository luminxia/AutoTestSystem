// Question.h: interface for the Question class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUESTION_H__AD3D7A96_9377_46B6_8961_3B1D0141E3F9__INCLUDED_)
#define AFX_QUESTION_H__AD3D7A96_9377_46B6_8961_3B1D0141E3F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Question  
{
public:
	// 题号
	int questionId;
	// 问题
	CString question;
	// 选项A
	CString choice_a;
	// 选项B
	CString choice_b;
	// 选项C
	CString choice_c;
	// 选项D
	CString choice_d;
	// 各选项的分数
	long score[4];

	// 问题结构体
	Question()
	{
		questionId = 1;
		question = "Question";
		choice_a = "";
		choice_b = "";
		choice_c = "";
		choice_d = "";
		score[0] = 0;
		score[1] = 0;
		score[2] = 0;
		score[3] = 0;	
	}

	virtual ~Question()
	{
		
	}
};

#endif // !defined(AFX_QUESTION_H__AD3D7A96_9377_46B6_8961_3B1D0141E3F9__INCLUDED_)
