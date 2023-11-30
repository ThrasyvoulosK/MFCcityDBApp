#pragma once


// DeleteTab dialog

class DeleteTab : public CPropertyPage
{
	DECLARE_DYNAMIC(DeleteTab)

public:
	DeleteTab();
	virtual ~DeleteTab();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DeleteTab };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
