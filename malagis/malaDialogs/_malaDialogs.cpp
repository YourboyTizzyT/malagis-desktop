#include "stdafx.h"
#include "_malaDialogs.h"
#include "DialogPointInput.h"
#include "DialogNewPointFile.h"
#include "DialogFilePro.h"
#include "DialogNewLineFile.h"
#include "DialogLineInput.h"
#include "DialogNewPolyFile.h"
#include "DialogPolyInput.h"
#include "DialogNewLabel.h"
#include "DialogInputLabel.h"

/*
* 输入点的对话框实现
*/
bool maladialogsdll dlgInputPoint(malaPointPro& paramPointPro)
{
	CDialogPointInput dlg;
	if (IDOK==dlg.DoModal())
	{
		paramPointPro.pointStyle = dlg.mPointStyle;
		paramPointPro.pointRadio = dlg.mPointRadio;
		paramPointPro.pointColor = dlg.mPointColor;
		return true;
	}
	return false;
}
/*
* 新建工程对话框实现
*/
bool maladialogsdll dlgNewPrj(CString &paramPrjPath, CString&prjName, CString&prjExt)
{
	CFileDialog prjDlg(FALSE, L"mpj", L"我的工程.mpj", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"工程文件(*.mpj)|*mpj||");
	prjDlg.m_ofn.lpstrTitle = L"设置工程名称";
	if (IDOK == prjDlg.DoModal())
	{
		paramPrjPath = prjDlg.GetPathName();
		prjName = prjDlg.GetFileName();
		prjExt = prjDlg.GetFileExt();
		return true;
	}
	else
	{
		paramPrjPath = L"";
		prjName = L"";
		prjExt = L"";
		return false;
	}
}

/*
* 打开工程对话框实现
*/
bool maladialogsdll dlgOpenPrj(CString &paramPrjPath)
{
	CFileDialog prjDlg(TRUE, L"mpj", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"工程文件(*.mpj)|*mpj||");
	prjDlg.m_ofn.lpstrTitle = L"打开工程文件";
	if (IDOK == prjDlg.DoModal())
	{
		paramPrjPath = prjDlg.GetPathName();
		return true;
	}
	else
	{
		paramPrjPath = L"";
		return false;
	}
}

/*
* 新建点文件对话框实现
*/
bool maladialogsdll dlgNewPointFile(CString &pointName)
{
	CDialogNewPointFile dlg;
	if (IDOK == dlg.DoModal())
	{
		pointName = dlg.mPointFileName;
		return true;
	}
	return false;
}

/*
* 文件属性对话框实现
*/
void maladialogsdll dlgGraphFilePro(malaTree fileNode)
{
	CDialogFilePro dlg;
	dlg.mFileName = fileNode.itemnode;
	dlg.mFilePath = fileNode.filePath;
	
	CFile file;
	CFileStatus fileStatus;
	file.GetStatus(fileNode.filePath, fileStatus);
	
	dlg.mFileSize.Format(L"%f KB", (float)fileStatus.m_size/1024.0);
	dlg.mCreateTime = fileStatus.m_ctime.Format(L"%Y-%m-%d %H:%M:%S");
	dlg.mModifyTime = fileStatus.m_mtime.Format(L"%Y-%m-%d %H:%M:%S");
	//fileStatus.m_ctime //创建日期
	//fileStatus.m_mtime //最后编辑日期
	//fileStatus.m_size //文件大小

	dlg.DoModal();
}

/*
* 载入文件对话框实现
*/
bool maladialogsdll dlgLoadGraphFile(malaTree & tmpTree)
{
	CFileDialog loadDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"图形数据文件 (*.mpt;*.mle;*.mpn;*.mll)|*.mpt;*.mle;*.mpn;*.mll|All files (*.*)|*.*||");
	loadDlg.m_ofn.lpstrTitle = L"打开麻辣GIS图形数据文件";
	
	if (IDOK == loadDlg.DoModal())
	{
		tmpTree.filePath = loadDlg.GetPathName();
		tmpTree.fileType = loadDlg.GetFileExt();
		tmpTree.isActive = false;
		tmpTree.isOpen = false;
		tmpTree.itemnode = loadDlg.GetFileName();
		return true;
	}
	else
		return false;
}

/*
* 修改点属性对话框实现
*/
bool maladialogsdll dlgModifyPointPro(malaPointPro& pro)
{
	CDialogPointInput dlg;
	dlg.mPointStyle = pro.pointStyle;
	dlg.mPointRadio = pro.pointRadio;
	dlg.mPointColor = pro.pointColor;
	if (IDOK == dlg.DoModal())
	{
		pro.pointStyle = dlg.mPointStyle;
		pro.pointRadio = dlg.mPointRadio;
		pro.pointColor = dlg.mPointColor;
		return true;
	}
	return false;
}
/*
* 新建线文件对话框
*/
bool maladialogsdll dlgNewLineFile(CString &lineName)
{
	CDialogNewLineFile dlg;
	if (IDOK == dlg.DoModal())
	{
		lineName = dlg.mLineFileName;
		return true;
	}
	return false;
}
/*
*输入线的对话框
*/
bool maladialogsdll dlgInputLine(malaLinePro& paramPro)
{
	CDialogLineInput dlg;
	if (IDOK == dlg.DoModal())
	{
		paramPro.lineStyle = dlg.mLineStyle;
		paramPro.lineWidth = dlg.mLineWidth;
		paramPro.lineColor = dlg.mLineColor;
		return true;
	}
	return false;
}

/*
* 修改线属性对话框
*/
bool maladialogsdll dlgModifyLinePro(malaLinePro& paramPro)
{
	CDialogLineInput dlg;
	dlg.mLineColor = paramPro.lineColor;
	dlg.mLineStyle = paramPro.lineStyle;
	dlg.mLineWidth = paramPro.lineWidth;
	if (IDOK == dlg.DoModal())
	{
		paramPro.lineStyle = dlg.mLineStyle;
		paramPro.lineWidth = dlg.mLineWidth;
		paramPro.lineColor = dlg.mLineColor;
		return true;
	}
	return false;
}
/*
* 新建区文件对话框
*/
bool maladialogsdll dlgNewPolyFile(CString &polyName)
{
	CDialogNewPolyFile dlg;
	if (IDOK == dlg.DoModal())
	{
		polyName = dlg.mPolyFileName;
		return true;
	}
	return false;
}
/*
* 输入区对话框实现
*/
bool maladialogsdll dlgInputPoly(malaPolyPro &paramPro)
{
	CDialogPolyInput dlg;
	if (IDOK == dlg.DoModal())
	{
		paramPro.polyStyle = dlg.mPolyType;
		paramPro.borderStyle = dlg.mBorderType;
		paramPro.borderColor = dlg.mBorderColor;
		paramPro.fillColor = dlg.mFillColor;
		paramPro.fillStyle = dlg.mFillType;
		paramPro.borderWidth = dlg.mBorderWidth;
		return true;
	}
	return false;
}

/*
* 修改区属性对话框实现
*/
bool maladialogsdll dlgModifyPolyPro(malaPolyPro &paramPro)
{
	CDialogPolyInput dlg;
	dlg.mPolyType = paramPro.polyStyle;
	dlg.mBorderType = paramPro.borderStyle;
	dlg.mBorderWidth = paramPro.borderWidth;
	dlg.mBorderColor = paramPro.borderColor;
	dlg.mFillType = paramPro.fillStyle;
	dlg.mFillColor = paramPro.fillColor;
	if (IDOK == dlg.DoModal())
	{
		paramPro.polyStyle = dlg.mPolyType;
		paramPro.borderStyle = dlg.mBorderType;
		paramPro.borderWidth = dlg.mBorderWidth;
		paramPro.borderColor = dlg.mBorderColor;
		paramPro.fillStyle = dlg.mFillType;
		paramPro.fillColor = dlg.mFillColor;
		return true;
	}
	return false;
}
/*
* 新建注释文件对话框
*/
bool maladialogsdll dlgNewLabelFile(CString &labelName)
{
	CDialogNewLabel dlg;
	if (IDOK == dlg.DoModal())
	{
		labelName = dlg.mLabelName;
		return true;
	}
	return false;
}

/*
* 输入注释对话框
*/
bool maladialogsdll dlgInputLabel(malaLabelPro &paramPro)
{
	CDialogInputLabel dlg;
	if (IDOK == dlg.DoModal())
	{
		paramPro.labelHeight = dlg.mLabelHeight;
		paramPro.labelWidth = dlg.mLabelWidth;
		paramPro.labelAngle = dlg.mLabelAngle;
		paramPro.textColor = dlg.mTextColor;
		paramPro.textAngle = dlg.mTextAngle;
		paramPro.textFont = dlg.mTextFont;
		paramPro.textOff = dlg.mTextOffset;
		paramPro.textStr = dlg.mTextStr;
		paramPro.fontWeight = dlg.mWeight;
		return true;
	}
	return false;
}
/*
* 修改注释属性对话框
*/
bool maladialogsdll dlgModifyLabelPro(malaLabelPro &paramPro)
{
	CDialogInputLabel dlg;
	
	dlg.mLabelHeight = paramPro.labelHeight;
	dlg.mLabelWidth = paramPro.labelWidth;
	dlg.mLabelAngle = paramPro.labelAngle;
	dlg.mTextColor = paramPro.textColor;
	dlg.mTextAngle = paramPro.textAngle;
	dlg.mTextFont = paramPro.textFont;
	dlg.mTextOffset = paramPro.textOff;
	dlg.mTextStr = paramPro.textStr;
	dlg.mWeight = paramPro.fontWeight;

	if (IDOK == dlg.DoModal())
	{
		paramPro.labelHeight = dlg.mLabelHeight;
		paramPro.labelWidth = dlg.mLabelWidth;
		paramPro.labelAngle = dlg.mLabelAngle;
		paramPro.textColor = dlg.mTextColor;
		paramPro.textAngle = dlg.mTextAngle;
		paramPro.textFont = dlg.mTextFont;
		paramPro.textOff = dlg.mTextOffset;
		paramPro.textStr = dlg.mTextStr;
		paramPro.fontWeight = dlg.mWeight;
		return true;
	}
	return false;
}