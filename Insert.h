#pragma once


// Insert dialog

class Insert : public CDialogEx
{
	DECLARE_DYNAMIC(Insert)

public:
	Insert(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Insert();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio2();
};
