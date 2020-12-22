
// test20201223Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test20201223.h"
#include "test20201223Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest20201223Dlg �Ի���




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


// Ctest20201223Dlg ��Ϣ�������

BOOL Ctest20201223Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctest20201223Dlg::OnPaint()
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
HCURSOR Ctest20201223Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest20201223Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	CString FilePathName;

	BOOL isOpen = TRUE;
	//CString defaultDir = _T("E:\\DSuanLiangTest\\export\\ddll\\���̿�");
	CString filter = _T("�ļ�(*.pmdb)|*.pmdb||");

	CFileDialog dlg(isOpen,											//TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
					NULL,											//ָ��Ĭ���ļ�����չ��
					NULL,											//Ĭ���ļ���
					OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,			//�������ͣ���ʱ��֪��������
					filter,											//ָ���޶����ļ���ʽ����
					NULL);											//������ָ��

	dlg.GetOFN().lpstrInitialDir = _T("E:\\DSuanLiangTest\\export\\ddll\\���̿�");	//ָ���򿪵�Ĭ��·��

	if(dlg.DoModal()==IDOK)											//�����������
	{
		FilePathName=dlg.GetPathName(); //�ļ�����������FilePathName��
	}
	else
	{
		return;
	}
}
