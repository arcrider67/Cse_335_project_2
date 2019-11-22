// TreeDlg.cpp : implementation file
//

#include "pch.h"
#include "CanadianExperience.h"
#include "TreeDlg.h"
#include "afxdialogex.h"


// CTreeDlg dialog

IMPLEMENT_DYNAMIC(CTreeDlg, CDialog)

CTreeDlg::CTreeDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TREEDLG, pParent)
	, mHarvestFrame(0)
{

}

CTreeDlg::~CTreeDlg()
{
}

void CTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HARVEST, mHarvestFrame);
	DDV_MinMaxInt(pDX, mHarvestFrame, 0, 10000);
}


BEGIN_MESSAGE_MAP(CTreeDlg, CDialog)
END_MESSAGE_MAP()


// CTreeDlg message handlers
