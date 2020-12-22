
// test20201223Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test20201223.h"
#include "test20201223Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest20201223Dlg 对话框




Ctest20201223Dlg::Ctest20201223Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest20201223Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest20201223Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest20201223Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest20201223Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Ctest20201223Dlg 消息处理程序

BOOL Ctest20201223Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest20201223Dlg::OnPaint()
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
HCURSOR Ctest20201223Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest20201223Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	CString FilePathName;

	BOOL isOpen = TRUE;
	//CString defaultDir = _T("E:\\DSuanLiangTest\\export\\ddll\\工程库");
	CString filter = _T("文件(*.pmdb)|*.pmdb||");

	CFileDialog dlg(isOpen,											//TRUE为OPEN对话框，FALSE为SAVE AS对话框
					NULL,											//指定默认文件的扩展名
					NULL,											//默认文件名
					OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,			//窗口类型，暂时不知道更多了
					filter,											//指定限定的文件格式类型
					NULL);											//父窗口指针

	dlg.GetOFN().lpstrInitialDir = _T("E:\\DSuanLiangTest\\export\\ddll\\工程库");	//指定打开的默认路径

	if(dlg.DoModal()==IDOK)											//如果返回正常
	{
		FilePathName=dlg.GetPathName(); //文件名保存在了FilePathName里
	}
	else
	{
		return;
	}
}
