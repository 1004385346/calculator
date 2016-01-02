
// calculatorDlg.h : 头文件
//

#pragma once


// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedCount();
	CString m_str;
	CString mm;
	CString charm;
	CString ss;
	CString fs;
	double temp;
	double temp2;
	int flag;
	int flag2;
	void CcalculatorDlg::inspect(CString &ss);
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMulit();
	afx_msg void OnBnClickedDivis();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedbackspace();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedsqrt();
	afx_msg void OnBnClickedpercent();
	afx_msg void OnBnClickedfraction();
	afx_msg void OnBnClickednegate();
	CString m_m;
	afx_msg void OnBnClickedmc();
	afx_msg void OnBnClickedmr();
	afx_msg void OnBnClickedms();
	afx_msg void OnBnClickedmadd();
	afx_msg void OnBnClickedmminus();
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_min;
	int m_sec;
	double hourag,minag,secag;
	double x,y;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
