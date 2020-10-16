
// MFCPractice4RegistrationDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCPractice4Registration.h"
#include "MFCPractice4RegistrationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCPractice4RegistrationDlg 대화 상자



CMFCPractice4RegistrationDlg::CMFCPractice4RegistrationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPRACTICE4REGISTRATION_DIALOG, pParent)
	, m_strName(_T(""))
	, m_strAge(_T(""))
	, m_strJob(_T(""))
	, m_bMale(false)
	, m_bLocker(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCPractice4RegistrationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_AGE, m_strAge);
	DDX_Text(pDX, IDC_EDIT_JOB, m_strJob);
	DDX_Control(pDX, IDC_LIST_MEMBER, m_listMember);
	DDX_Control(pDX, IDC_COMBO_WITHDRAW, m_comboWithdraw);
}

BEGIN_MESSAGE_MAP(CMFCPractice4RegistrationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO_MALE, &CMFCPractice4RegistrationDlg::OnRadioMale)
	ON_COMMAND(IDC_RADIO_FEMALE, &CMFCPractice4RegistrationDlg::OnRadioFemale)
	ON_BN_CLICKED(IDC_BUTTON_JOIN, &CMFCPractice4RegistrationDlg::OnClickedButtonJoin)
//	ON_LBN_SELCHANGE(IDC_LIST_MEMBER, &CMFCPractice4RegistrationDlg::OnSelchangeListMember)
ON_BN_CLICKED(IDC_BUTTON_WITHDRAW, &CMFCPractice4RegistrationDlg::OnClickedButtonWithdraw)
ON_BN_CLICKED(IDC_CHECK_LOCKER, &CMFCPractice4RegistrationDlg::OnClickedCheckLocker)
ON_BN_CLICKED(IDC_BUTTON_REJOIN, &CMFCPractice4RegistrationDlg::OnClickedButtonRejoin)
END_MESSAGE_MAP()


// CMFCPractice4RegistrationDlg 메시지 처리기

BOOL CMFCPractice4RegistrationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCPractice4RegistrationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCPractice4RegistrationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCPractice4RegistrationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCPractice4RegistrationDlg::OnRadioMale()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// AfxMessageBox(_T("라디오 남"));
	m_bMale = true;
}


void CMFCPractice4RegistrationDlg::OnRadioFemale()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// AfxMessageBox(_T("라디오 여"));
	m_bMale = false;
}


void CMFCPractice4RegistrationDlg::OnClickedButtonJoin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// AfxMessageBox(_T("가입 버튼"));

	UpdateData(TRUE);
	
	if (AfxMessageBox(_T("가입하시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES) 
	{
		// 회원 가입
		m_nMemberCnt++;
		CString strGender = (m_bMale) ? _T("남자") :  _T("여자");
		CString strLocker = (m_bLocker) ? _T("락커 대여") : _T("락커 미대여");
		CString strList;
		strList.Format(_T("%02d %5s %3s %2s %5s %8s"), m_nMemberCnt, m_strName, m_strAge, strGender, m_strJob, strLocker);
		m_listMember.AddString(strList);

		m_strName.Empty();
		m_strAge.Empty();
		m_strJob.Empty();
	}
	else
	{
		// 회원 가입 안함.
		AfxMessageBox(_T("회원 가입이 취소 되었습니다."));
		m_strName.Empty();
		m_strAge.Empty();
		m_strJob.Empty();
	}

	UpdateData(FALSE);
}


void CMFCPractice4RegistrationDlg::OnClickedButtonWithdraw()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfxMessageBox(_T("정말 탈퇴시키겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		// 탈퇴 진행
		int index = m_listMember.GetCurSel();   // 현재 선택되어있는 값을 index에 넣음
		if (index != LB_ERR)  // List Box Error
		{
			CString  strlist;
			m_listMember.GetText(index, strlist);
			m_listMember.DeleteString(index);
			m_comboWithdraw.AddString(strlist);
		}
	}
	else
	{
		// 탈퇴 안함.
	}

}


void CMFCPractice4RegistrationDlg::OnClickedCheckLocker()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bLocker)
	{
		m_bLocker = false;
	}
	else
	{
		m_bLocker = true;
	}
}


void CMFCPractice4RegistrationDlg::OnClickedButtonRejoin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfxMessageBox(_T("정말 재가입시키겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		int index = m_comboWithdraw.GetCurSel();
		if (index != CB_ERR)  // 선택되었을 경우
		{
			CString strcombo;
			m_comboWithdraw.GetWindowText(strcombo);
			m_comboWithdraw.DeleteString(index);
			m_listMember.AddString(strcombo);
		}
	}
}
