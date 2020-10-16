
// MFCPractice4RegistrationDlg.h: 헤더 파일
//

#pragma once


// CMFCPractice4RegistrationDlg 대화 상자
class CMFCPractice4RegistrationDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCPractice4RegistrationDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPRACTICE4REGISTRATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strAge;
	CString m_strJob;
	afx_msg void OnRadioMale();
	afx_msg void OnRadioFemale();
	bool m_bMale;
	afx_msg void OnClickedButtonJoin();
//	afx_msg void OnSelchangeListMember();
	CListBox m_listMember;
	int m_nMemberCnt;
	afx_msg void OnClickedButtonWithdraw();
	afx_msg void OnClickedCheckLocker();
	bool m_bLocker;
	CComboBox m_comboWithdraw;
	afx_msg void OnClickedButtonRejoin();
};
