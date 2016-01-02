
// calculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "Cmath"
#define PI 3.1415926

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg 对话框




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
	, m_m(_T(""))
	, m_year(0)
	, m_month(0)
	, m_day(0)
	, m_hour(0)
	, m_min(0)
	, m_sec(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	fs="";
	ss=L"0";
	charm=L"M";
	m_str=fs+L"\r\n"+ss;
	x=0;
	y=0;
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Text(pDX, IDC_M, m_m);
	DDX_Text(pDX, IDC_EDIT2, m_year);
	DDX_Text(pDX, IDC_EDIT3, m_month);
	DDX_Text(pDX, IDC_EDIT4, m_day);
	DDX_Text(pDX, IDC_EDIT5, m_hour);
	DDX_Text(pDX, IDC_EDIT6, m_min);
	DDX_Text(pDX, IDC_EDIT7, m_sec);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_DOT, &CcalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_COUNT, &CcalculatorDlg::OnBnClickedCount)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_MINUS, &CcalculatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MULIT, &CcalculatorDlg::OnBnClickedMulit)
	ON_BN_CLICKED(IDC_DIVIS, &CcalculatorDlg::OnBnClickedDivis)
	ON_BN_CLICKED(IDC_C, &CcalculatorDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_backspace, &CcalculatorDlg::OnBnClickedbackspace)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_sqrt, &CcalculatorDlg::OnBnClickedsqrt)
	ON_BN_CLICKED(IDC_percent, &CcalculatorDlg::OnBnClickedpercent)
	ON_BN_CLICKED(IDC_fraction, &CcalculatorDlg::OnBnClickedfraction)
	ON_BN_CLICKED(IDC_negate, &CcalculatorDlg::OnBnClickednegate)
	ON_BN_CLICKED(IDC_mc, &CcalculatorDlg::OnBnClickedmc)
	ON_BN_CLICKED(IDC_mr, &CcalculatorDlg::OnBnClickedmr)
	ON_BN_CLICKED(IDC_ms, &CcalculatorDlg::OnBnClickedms)
	ON_BN_CLICKED(IDC_madd, &CcalculatorDlg::OnBnClickedmadd)
	ON_BN_CLICKED(IDC_mminus, &CcalculatorDlg::OnBnClickedmminus)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,10,NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CcalculatorDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedC();
		UpdateData(false);
		flag2=0;
	}
	ss=ss+L"0";
	if(ss.Find(L".")<0&&ss.Left(1)=="0")
		ss="0";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedC();
		UpdateData(false);
		flag2=0;
	}
	ss=ss+L"1";
	if(ss.Find(L".")<0&&ss.Left(1)=="0")
		ss="1";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedC();
		UpdateData(false);
		flag2=0;
	}
	ss=ss+L"2";
	if(ss.Find(L".")<0&&ss.Left(1)=="0")
		ss="2";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedC();
		UpdateData(false);
		flag2=0;
	}
	ss=ss+L"3";
	if(ss.Find(L".")<0&&ss.Left(1)=="0")
		ss="3";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedC();
		UpdateData(false);
		flag2=0;
	}
	ss=ss+L"4";
	if(ss.Find(L".")<0&&ss.Left(1)=="0")
		ss="4";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedC();
		UpdateData(false);
		flag2=0;
	}
	ss=ss+L"5";
	if(ss.Find(L".")<0&&ss.Left(1)=="0")
		ss="5";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedC();
		UpdateData(false);
		flag2=0;
	}
	ss=ss+L"6";
	if(ss.Find(L".")<0&&ss.Left(1)=="0")
		ss="6";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedC();
		UpdateData(false);
		flag2=0;
	}
	ss=ss+L"7";
	if(ss.Find(L".")<0&&ss.Left(1)=="0")
		ss="7";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedC();
		UpdateData(false);
		flag2=0;
	}
	ss=ss+L"8";
	if(ss.Find(L".")<0&&ss.Left(1)=="0")
		ss="8";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedC();
		UpdateData(false);
		flag2=0;
	}
	ss=ss+L"9";
	if(ss.Find(L".")<0&&ss.Left(1)=="0")
		ss="9";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDot()
{
	// TODO: 在此添加控件通知处理程序代码
	if(ss.GetLength()==0)
		ss="0";
	if(ss.Find(L".")==-1)
		ss=ss+L".";
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);
}
void CcalculatorDlg::inspect(CString &ss)
{
	while(ss.Right(1)=="0"&&ss.Find(L".")>=0)
	{
		ss.Delete(ss.GetLength()-1,1);
	}
	if(ss.Right(1)==".")
	{
		ss.Delete(ss.GetLength()-1,1);
	}
}


void CcalculatorDlg::OnBnClickedCount()
{
	// TODO: 在此添加控件通知处理程序代码
	inspect(ss);
	if(flag==1)
	{
	    temp=temp+_ttof(ss);
		if(_ttof(ss)<0)
			fs=fs+L"("+ss+L")";
		else
			fs=fs+ss;
	}else
	{
		if(flag==2)
		{
			temp=temp-_ttof(ss);
			if(_ttof(ss)<0)
				fs=fs+L"("+ss+L")";
			else
				fs=fs+ss;
		}
		else
		{
			if(flag==3)
			{
				temp=temp*_ttof(ss);
				if(_ttof(ss)<0)
					fs=fs+L"("+ss+L")";	
				else
					fs=fs+ss;
			}
			else
			{
				if(flag==4)
				{
					temp=temp/_ttof(ss);
					if(_ttof(ss)<0)	
					{
						fs=fs+L"("+ss+L")";
					}
					else
					{
						fs=fs+ss;		
					}	
					if(_ttof(ss)==0)
					{
						OnBnClickedC();
						MessageBox(L"真蠢！！不能以0作为除数");
					}
				}
				else
				{
					MessageBox(L"哈哈，傻货！这都出错！");
				}
			}
		}
	}
	ss.Format(L"%lf",temp);
	inspect(ss);
	m_str=fs+"\r\n\n"+ss;
	UpdateData(false);
	flag=0;
	flag2=1;
}


void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag==1||flag==2||flag==3||flag==4)
			OnBnClickedCount();
	if(flag2==1)
	{
		
		flag=1;
		fs=ss+L"+";
		temp=_ttof(ss);
		ss="";
	    m_str=fs+L"\n";
		UpdateData(false);
		flag2=0;
	}else
	{
	    inspect(ss);
	    flag=1;
	    fs=ss+L"+";
	    temp=_ttof(ss);
	    ss="";
	    m_str=fs+L"\n";
	    UpdateData(false);
	}
}



void CcalculatorDlg::OnBnClickedMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag==1||flag==2||flag==3||flag==4)
			OnBnClickedCount();
	if(flag2==1)
	{
		
		flag=2;
		fs=ss+L"-";
		temp=_ttof(ss);
		ss="";
	    m_str=fs+L"\n";
		UpdateData(false);
		flag2=0;
	}else
	{
		inspect(ss);
	    flag=2;
	    fs=ss+L"-";
	    temp=_ttof(ss);
	    ss=" ";
	    m_str=fs+L"\n";
	    UpdateData(false);
	}
}


void CcalculatorDlg::OnBnClickedMulit()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag==1||flag==2||flag==3||flag==4)
			OnBnClickedCount();
	if(flag2==1)
	{
		
		flag=3;
		fs=ss+L"*";
		temp=_ttof(ss);
		ss="";
	    m_str=fs+L"\n";
		UpdateData(false);
		flag2=0;
	}else
	{
		inspect(ss);
	    flag=3;
	    fs=ss+L"*";
	    temp=_ttof(ss);
	    ss=" ";
	    m_str=fs+L"\n";
	    UpdateData(false);
	}
}


void CcalculatorDlg::OnBnClickedDivis()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag==1||flag==2||flag==3||flag==4)
			OnBnClickedCount();
	if(flag2==1)
	{
		
		flag=4;
		fs=ss+L"/";
		temp=_ttof(ss);
		ss="";
	    m_str=fs+L"\n";
		UpdateData(false);
		flag2=0;
	}else
	{
		inspect(ss);
	    flag=4;
	    fs=ss+L"/";
	    temp=_ttof(ss);
	    ss=" ";
	    m_str=fs+L"\n";
	    UpdateData(false);
	}
}


void CcalculatorDlg::OnBnClickedC()
{
	// TODO: 在此添加控件通知处理程序代码
	temp=0;
	fs=L"";
	ss=L"0";
	m_str=fs+"\r\n\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedbackspace()
{
	// TODO: 在此添加控件通知处理程序代码
	ss.Delete(ss.GetLength()-1,1);
	if(m_str.GetLength()!=0)
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}





void CcalculatorDlg::OnBnClickedButton7()//CE键写着急忘改ID了
{
	// TODO: 在此添加控件通知处理程序代码
	ss=L"0";
	m_str=fs+"\r\n"+ss;
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedsqrt()
{
	// TODO: 在此添加控件通知处理程序代码
	if(_ttof(ss)<0)
	{
		OnBnClickedC();
		MessageBox(L"笨蛋！！！负数是不可以开根号的！");
	}
	else
	{
		if(flag==1||flag==2||flag==3||flag==4)
		{
			inspect(ss);
			fs=fs+L"√"+ss;
			ss.Format(L"%lf",sqrt(_ttof(ss)));
			if(flag==1)
			{
				temp=temp+_ttof(ss);
			}
			else
			{
				if(flag==2)
				{
					temp=temp-_ttof(ss);
				}
				else
				{
					if(flag==3)
					{
						temp=temp*_ttof(ss);
					}
					else
					{		    
						if(_ttof(ss)!=0)
						{
							temp=temp/_ttof(ss);
						}
						else
						{
							OnBnClickedC();
							MessageBox(L"傻不傻！！！！！");
						}
					}
				}
			}
			ss.Format(L"%lf",temp);
			inspect(ss);
			m_str=fs+"\r\n"+ss;
			UpdateData(false);
			flag=0;
		}
		else
		{
			inspect(ss);
			fs=fs+L"√"+ss;
			temp=sqrt(_ttof(ss));
			ss.Format(L"%lf",temp);
			inspect(ss);
			m_str=fs+"\r\n"+ss;
			UpdateData(false);
			flag=0;
		}
	}
}

void CcalculatorDlg::OnBnClickedpercent()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag==1||flag==2||flag==3||flag==4)
	{
		inspect(ss);
		fs=fs+ss+L"%";
		ss.Format(L"%lf",temp*_ttof(ss)/100);
		inspect(ss);
		if(_ttof(ss)<0)
		{
			fs=fs+L"("+ss+L")";
		}
		else
		{
			fs=fs+ss;
		}
		if(flag==1)
		{
			temp=temp+_ttof(ss);
		}
		else
		{
			if(flag==2)
			{
				temp=temp-_ttof(ss);
			}
			else
			{
				if(flag==3)
				{
					temp=temp*_ttof(ss);
				}
				else
				{
					if(_ttof(ss)!=0)
					{
						temp=temp/_ttof(ss);
					}
					else
					{
						OnBnClickedC();
						MessageBox(L"你的傻无人能及！！！！");
					}
				}
			}
		}
		ss.Format(L"%lf",temp);
		inspect(ss);
		m_str=fs+"\r\n"+ss;
		UpdateData(false);
		flag=0;
	}
	else
	{
		inspect(ss);
		fs=fs+ss+L"%";
		temp=_ttof(ss)/100;
		ss.Format(L"%lf",temp);
		inspect(ss);
		m_str=fs+"\r\n"+ss;
		UpdateData(false);
		flag=0;
	}
}


void CcalculatorDlg::OnBnClickedfraction()
{
	// TODO: 在此添加控件通知处理程序代码
	if(_ttof(ss)==0)
	{
		OnBnClickedC();
		MessageBox(L"分母不能为0！！！傻不傻");
	}
	else
	{
		if(flag==1||flag==2||flag==3||flag==4)
		{
			inspect(ss);
			fs=fs+L"1/"+ss;
			ss.Format(L"%lf",1.0/_ttof(ss));
			inspect(ss);
			if(_ttof(ss)<0)
			{
				fs=fs+L"("+ss+L")";
			}
			else
			{
				fs=fs+ss;
			}
			if(flag==1)
			{
				temp=temp+_ttof(ss);
			}
			else
			{
				if(flag==2)
				{
					temp=temp-_ttof(ss);
				}
				else
				{
					if(flag==3)
					{
						temp=temp*_ttof(ss);
					}
					else
					{
						if(_ttof(ss)!=0)
						{
							temp=temp/_ttof(ss);
						}
						else
						{
							OnBnClickedC();
							MessageBox(L"天啊！！我还能说什么");
						}
					}
				}
			}
			ss.Format(L"%lf",temp);
			inspect(ss);
			m_str=fs+"\r\n"+ss;
			UpdateData(false);
			flag=0;
		}
		else
		{
			inspect(ss);
			fs=fs+L"1/"+ss;
			temp=1/_ttof(ss);
			ss.Format(L"%lf",temp);
			inspect(ss);
			m_str=fs+"\r\n"+ss;
			UpdateData(false);
			flag=0;
		}
	}
}


void CcalculatorDlg::OnBnClickednegate()
{
	// TODO: 在此添加控件通知处理程序代码
	if(ss.Left(1)==L"-")
	ss.Delete(0,1);
	else
	ss=L"-"+ss;    
	m_str=fs+L"\r\n"+ss;
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedmc()
{
	// TODO: 在此添加控件通知处理程序代码
	m_m="";
	mm=L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedmr()
{
	// TODO: 在此添加控件通知处理程序代码
	inspect(mm);
	ss=mm;
	m_str=fs+"\r\n"+ss;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedms()
{
	// TODO: 在此添加控件通知处理程序代码
	mm=ss;
	m_m="";
	m_m=m_m+L"\r\n"+charm;
}


void CcalculatorDlg::OnBnClickedmadd()
{
	// TODO: 在此添加控件通知处理程序代码
	temp2=_ttof(mm)+_ttof(ss);
	mm.Format(L"%lf",temp2);
	if(mm==L"0")
	{
		m_m="";
	}
	if(_ttof(mm)!=0)
	{
		m_m=" ";
		m_m=m_m+L"\r\n"+charm;
	}
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedmminus()
{
	// TODO: 在此添加控件通知处理程序代码
	temp2=_ttof(mm)-_ttof(ss);
	mm.Format(L"%lf",temp2);
	if(mm==L"0")
	{
		m_m="";
	}
	if(_ttof(mm)!=0)
	{
		m_m=" ";
		m_m=m_m+L"\r\n"+charm;
	}
	UpdateData(false);
}


void CcalculatorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TRACE("X=%d,Y=%d\n",point.x,point.y);

	CDialogEx::OnMouseMove(nFlags, point);
}


void CcalculatorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int L1=60,L2=50,L3=40;
	CTime t = CTime::GetCurrentTime();
	m_year=t.GetYear();
	m_month=t.GetMonth();
	m_day=t.GetDay();
	m_hour=t.GetHour();
	m_min=t.GetMinute();
	m_sec=t.GetSecond();
	UpdateData(false);
	CClientDC dc(this);
	dc.SetWindowOrg(-537,-225);
	CPen *oldpen;
	CPen whitepen(PS_SOLID,4,RGB(248,248,248));
	oldpen=dc.SelectObject(&whitepen);
	secag=m_sec*(PI/30);
	x=L1*sin(secag);
	y=-L1*cos(secag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);
	CPen secpen(PS_SOLID,2,RGB(150,150,150));  
	oldpen=dc.SelectObject(&secpen);
	secag=secag+PI/30;
	x=L1*sin(secag);
	y=-L1*cos(secag);
	dc.MoveTo(0,0); 
	dc.LineTo(x,y);
	if(secag>=6.2831852)
	    secag=-PI/30;
	oldpen=dc.SelectObject(&whitepen);  
	minag=m_min*(PI/30)+m_sec*(PI/1800);
	x=L2*sin(minag);
	y=-L2*cos(minag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);
	CPen minpen(PS_SOLID,2.5,RGB(90,90,90)); 
	oldpen=dc.SelectObject(&minpen);	                                          
    minag=minag+PI/1800;
	x=L2*sin(minag);
	y=-L2*cos(minag);
	dc.MoveTo(0,0); 
	dc.LineTo(x,y);
	if(minag>=6.2831852)
	    minag=-PI/1800;
	oldpen=dc.SelectObject(&whitepen);
	hourag=m_hour*(PI/6)+m_min*(PI/360)+m_sec*(PI/21600);
	x=L3*sin(hourag);
	y=-L3*cos(hourag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);
	CPen hourpen(PS_SOLID,3.5,RGB(50,50,50));
	oldpen=dc.SelectObject(&hourpen);	                                          
    hourag=hourag+PI/21600;
	x=L3*sin(hourag);
	y=-L3*cos(hourag);
	dc.MoveTo(0,0); 
	dc.LineTo(x,y);
	if(hourag>=6.2831852)
	    hourag=-PI/10800;

	CDialogEx::OnTimer(nIDEvent);
}
