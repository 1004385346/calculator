
// asdDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "asd.h"
#include "asdDlg.h"
#include "afxdialogex.h"
#include "cmath"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CasdDlg �Ի���




CasdDlg::CasdDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CasdDlg::IDD, pParent)
	, m_hour(0)
	, m_min(0)
	, m_sec(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	x=0;
	y=0;

}

void CasdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_hour);
	DDX_Text(pDX, IDC_EDIT2, m_min);
	DDX_Text(pDX, IDC_EDIT3, m_sec);
}

BEGIN_MESSAGE_MAP(CasdDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_draw, &CasdDlg::OnBnClickeddraw)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CasdDlg ��Ϣ�������

BOOL CasdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(1,1000,NULL);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CasdDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CasdDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CasdDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CasdDlg::OnBnClickeddraw()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CClientDC dc(this);
	dc.SetWindowOrg(-150,-150);
	CPen *oldpen;
	CPen pen(PS_SOLID,3,RGB(0,0,255));
	oldpen=dc.SelectObject(&pen);
    dc.Ellipse(-100,100,100,-100); 
	dc.Ellipse(-3,-3,3,3);
	for(int i=0;i<12;i++)
	{
		double l=96,ag=i*PI/6;
		double a=l*sin(ag)+1,b=-l*cos(ag)+1,c=l*sin(ag)-1,d=-l*cos(ag)-1;
	    dc.Ellipse(a,b,c,d); 
	}
	dc.TextOutW(-8,-90,L"12");
	dc.TextOutW(80,-8,L"3");
	dc.TextOutW(-4,76,L"6");
	dc.TextOutW(-86,-8,L"9");
}


void CasdDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TRACE("X=%d,Y=%d\n",point.x,point.y);

	CDialogEx::OnMouseMove(nFlags, point);
}


void CasdDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int L1=70,L2=65,L3=60;
	CTime t = CTime::GetCurrentTime();
	m_hour=t.GetHour();
	m_min=t.GetMinute();
	m_sec=t.GetSecond();
	UpdateData(false);
	CClientDC dc(this);
	dc.SetWindowOrg(-150,-150);
	CPen *oldpen;
	CPen whitepen(PS_SOLID,4,RGB(255,255,255));
	CPen pen(PS_SOLID,3,RGB(0,0,0));
	oldpen=dc.SelectObject(&pen);
    dc.Ellipse(-100,100,100,-100); 
    CPen ppen(PS_SOLID,8,RGB(0,0,0));
	oldpen=dc.SelectObject(&ppen);
	for(int i=0;i<12;i++)
	{
		double l=96,ag=i*PI/6;
		double a=l*sin(ag)+1,b=-l*cos(ag)+1,c=l*sin(ag)-1,d=-l*cos(ag)-1;
	    dc.Ellipse(a,b,c,d); 
	}
	dc.TextOutW(-8,-90,L"12");
	dc.TextOutW(80,-8,L"3");
	dc.TextOutW(-4,76,L"6");
	dc.TextOutW(-86,-8,L"9");
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
	    hourag=-PI/21600;
	

	CDialogEx::OnTimer(nIDEvent);
}
