#pragma once


// Actions dialog

class Actions : public CDialogEx
{
	DECLARE_DYNAMIC(Actions)

public:
	Actions(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Actions();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSelect();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLbnSelchangeList1();
};
