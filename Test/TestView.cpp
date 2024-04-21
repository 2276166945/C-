
// TestView.cpp : CTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Test.h"
#endif

#include "TestDoc.h"
#include "TestView.h"
#include "math.h"//包含数学头文件
#define  PI 3.1415926//PI的宏定义
#define Round(d) int(floor(d+0.5))//四舍五入宏定义

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DRAWPIC, &CTestView::OnDrawpic)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_TLEFT, &CTestView::OnTleft)
	ON_COMMAND(ID_TRIGHT, &CTestView::OnTright)
	ON_COMMAND(ID_TUP, &CTestView::OnTup)
	ON_COMMAND(ID_TDOWN, &CTestView::OnTdown)
	ON_COMMAND(ID_SINCREASE, &CTestView::OnSincrease)
	ON_COMMAND(ID_SDECREASE, &CTestView::OnSdecrease)
	ON_COMMAND(ID_RCLOCKWISE, &CTestView::OnRclockwise)
	ON_COMMAND(ID_RCOUNTERCLOCKWISE, &CTestView::OnRcounterclockwise)
	ON_COMMAND(ID_RXAXIS, &CTestView::OnRxaxis)
	ON_COMMAND(ID_RYAXIS, &CTestView::OnRyaxis)
	ON_COMMAND(ID_RORG, &CTestView::OnRorg)
	ON_COMMAND(ID_SXDIRECTIONNEG, &CTestView::OnSxdirectionneg)
	ON_COMMAND(ID_SXDIRECTIONPLUS, &CTestView::OnSxdirectionplus)
	ON_COMMAND(ID_SYDIRECTIONNEG, &CTestView::OnSydirectionneg)
	ON_COMMAND(ID_SYDIRECTIONPLUS, &CTestView::OnSydirectionplus)
//	ON_COMMAND(ID_RESET, &CTestView::OnReset)
ON_COMMAND(ID_M_RESET, &CTestView::OnReset)
END_MESSAGE_MAP()

// CTestView 构造/析构

CTestView::CTestView()
{
	// TODO: 在此处添加构造代码

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTestView 绘制

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	DoubleBuffer(pDC);
}


// CTestView 打印

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTestView 诊断

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestView 消息处理程序


void CTestView::OnDrawpic() 
{
	// TODO: Add your command handler code here
	MessageBox(CString("请使用图标按钮进行二维几何变换"),CString("提示"),MB_OK);
}

void CTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnLButtonDown(nFlags, point);
}


void CTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnLButtonUp(nFlags, point);
}
void CTestView::DoubleBuffer(CDC *pDC)//双缓冲
{
	GetClientRect(&rect);//获得客户区的大小
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC自定义坐标系
	pDC->SetWindowExt(rect.Width(),rect.Height());//设置窗口范围
	pDC->SetViewportExt(rect.Width(),-rect.Height());//设置视区范围,x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//客户区中心为原点
	CDC memDC;//内存DC
	CBitmap NewBitmap,*pOldBitmap;//内存中承载的临时位图
	memDC.CreateCompatibleDC(pDC);//创建一个与显示pDC兼容的内存memDC 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//创建兼容位图 
	pOldBitmap=memDC.SelectObject(&NewBitmap);//将兼容位图选入memDC 
	memDC.FillSolidRect(rect,pDC->GetBkColor());//按原来背景填充客户区，否则是黑色
	memDC.SetMapMode(MM_ANISOTROPIC);//memDC自定义坐标系
	memDC.SetWindowExt(rect.Width(),rect.Height());
	memDC.SetViewportExt(rect.Width(),-rect.Height());
	memDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	DrawObject(&memDC);//向memDC绘制图形
	pDC->BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);//将内存memDC中的位图拷贝到显示pDC中
	memDC.SelectObject(pOldBitmap);//恢复位图
	NewBitmap.DeleteObject();//删除位图
}

void CTestView::ReadPoint()//点表
{
	P[0].x=-100;P[0].y=-50;
	P[1].x=100; P[1].y=-50;
	P[2].x=100; P[2].y=50;
	P[3].x=-100;P[3].y=50;
}

void CTestView::DrawObject(CDC *pDC)//绘制图形
{
	CLine *line=new CLine;//绘制坐标系
	line->MoveTo(pDC,0,-rect.Height()/2);//绘制x轴
	line->LineTo(pDC,0,rect.Height()/2);
	line->MoveTo(pDC,-rect.Width()/2,0);//绘制y轴
	line->LineTo(pDC,rect.Width()/2,0);
	DrawPolygon(pDC);
	delete line;
}

void CTestView::DrawPolygon(CDC *pDC)//绘制多边形线框模型
{
	CLine *line=new CLine;
	CP2 t;
	for(int i=0;i<4;i++)//绘制多边形
	{
		if(i==0)
		{
			line->MoveTo(pDC,P[i]);
			t=P[i];
		}
		else
		{
			line->LineTo(pDC,P[i]);
		}		
	}
	line->LineTo(pDC,t);//闭合多边形
	delete line;
}

void CTestView::OnTleft()
{
	// TODO: 在此添加命令处理程序代码
	trans.Translate(-10,0);
	Invalidate(FALSE);
}


void CTestView::OnTright()
{
	// TODO: 在此添加命令处理程序代码
	CDC *pDC=GetDC();
	trans.Translate(10,0);
	DoubleBuffer(pDC);
	ReleaseDC(pDC);
}


void CTestView::OnTup()
{
	// TODO: 在此添加命令处理程序代码
	trans.Translate(0,10);
	Invalidate(FALSE);	
}


void CTestView::OnTdown()
{
	// TODO: 在此添加命令处理程序代码
	trans.Translate(0,-10);
	Invalidate(FALSE);	
}


void CTestView::OnSincrease()
{
	// TODO: 在此添加命令处理程序代码
	trans.Scale(2,2);
	Invalidate(FALSE);	
}


void CTestView::OnSdecrease()
{
	// TODO: 在此添加命令处理程序代码
	trans.Scale(0.5,0.5);
	Invalidate(FALSE);	
}


void CTestView::OnRclockwise()
{
	// TODO: 在此添加命令处理程序代码
	CP2 p=(P[0]+P[2])/2;
	trans.Rotate(30,p);
	Invalidate(FALSE);
}


void CTestView::OnRcounterclockwise()
{
	// TODO: 在此添加命令处理程序代码
	CP2 p=(P[0]+P[2])/2;
    trans.Rotate(-30,p);
	Invalidate(FALSE);	
}


void CTestView::OnRxaxis()
{
	// TODO: 在此添加命令处理程序代码
	trans.ReflectX();
	Invalidate(FALSE);	
}


void CTestView::OnRyaxis()
{
	// TODO: 在此添加命令处理程序代码
	trans.ReflectY();
	Invalidate(FALSE);	
}


void CTestView::OnRorg()
{
	// TODO: 在此添加命令处理程序代码
	trans.ReflectOrg();
	Invalidate(FALSE);	
}


void CTestView::OnSxdirectionneg()
{
	// TODO: 在此添加命令处理程序代码
	trans.Shear(0,-1);
	Invalidate(FALSE);	
}


void CTestView::OnSxdirectionplus()
{
	// TODO: 在此添加命令处理程序代码
	trans.Shear(0,1);
	Invalidate(FALSE);	
}


void CTestView::OnSydirectionneg()
{
	// TODO: 在此添加命令处理程序代码
	trans.Shear(-1,0);
	Invalidate(FALSE);	
}


void CTestView::OnSydirectionplus()
{
	// TODO: 在此添加命令处理程序代码
	trans.Shear(1,0);
	Invalidate(FALSE);	
}


//void CTestView::OnReset()
//{
//	// TODO: 在此添加命令处理程序代码
//	ReadPoint();
//	Invalidate(FALSE);	
//}


void CTestView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	ReadPoint();
	trans.SetMat(P,4);
}


void CTestView::OnReset()
{
	// TODO: 在此添加命令处理程序代码
	ReadPoint();
	Invalidate(FALSE);	
}
