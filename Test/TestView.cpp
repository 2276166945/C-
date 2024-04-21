
// TestView.cpp : CTestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Test.h"
#endif

#include "TestDoc.h"
#include "TestView.h"
#include "math.h"//������ѧͷ�ļ�
#define  PI 3.1415926//PI�ĺ궨��
#define Round(d) int(floor(d+0.5))//��������궨��

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	// ��׼��ӡ����
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

// CTestView ����/����

CTestView::CTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTestView ����

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	DoubleBuffer(pDC);
}


// CTestView ��ӡ

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CTestView ���

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestView ��Ϣ�������


void CTestView::OnDrawpic() 
{
	// TODO: Add your command handler code here
	MessageBox(CString("��ʹ��ͼ�갴ť���ж�ά���α任"),CString("��ʾ"),MB_OK);
}

void CTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CView::OnLButtonDown(nFlags, point);
}


void CTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CView::OnLButtonUp(nFlags, point);
}
void CTestView::DoubleBuffer(CDC *pDC)//˫����
{
	GetClientRect(&rect);//��ÿͻ����Ĵ�С
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC�Զ�������ϵ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô��ڷ�Χ
	pDC->SetViewportExt(rect.Width(),-rect.Height());//����������Χ,x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//�ͻ�������Ϊԭ��
	CDC memDC;//�ڴ�DC
	CBitmap NewBitmap,*pOldBitmap;//�ڴ��г��ص���ʱλͼ
	memDC.CreateCompatibleDC(pDC);//����һ������ʾpDC���ݵ��ڴ�memDC 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//��������λͼ 
	pOldBitmap=memDC.SelectObject(&NewBitmap);//������λͼѡ��memDC 
	memDC.FillSolidRect(rect,pDC->GetBkColor());//��ԭ���������ͻ����������Ǻ�ɫ
	memDC.SetMapMode(MM_ANISOTROPIC);//memDC�Զ�������ϵ
	memDC.SetWindowExt(rect.Width(),rect.Height());
	memDC.SetViewportExt(rect.Width(),-rect.Height());
	memDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	DrawObject(&memDC);//��memDC����ͼ��
	pDC->BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);//���ڴ�memDC�е�λͼ��������ʾpDC��
	memDC.SelectObject(pOldBitmap);//�ָ�λͼ
	NewBitmap.DeleteObject();//ɾ��λͼ
}

void CTestView::ReadPoint()//���
{
	P[0].x=-100;P[0].y=-50;
	P[1].x=100; P[1].y=-50;
	P[2].x=100; P[2].y=50;
	P[3].x=-100;P[3].y=50;
}

void CTestView::DrawObject(CDC *pDC)//����ͼ��
{
	CLine *line=new CLine;//��������ϵ
	line->MoveTo(pDC,0,-rect.Height()/2);//����x��
	line->LineTo(pDC,0,rect.Height()/2);
	line->MoveTo(pDC,-rect.Width()/2,0);//����y��
	line->LineTo(pDC,rect.Width()/2,0);
	DrawPolygon(pDC);
	delete line;
}

void CTestView::DrawPolygon(CDC *pDC)//���ƶ�����߿�ģ��
{
	CLine *line=new CLine;
	CP2 t;
	for(int i=0;i<4;i++)//���ƶ����
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
	line->LineTo(pDC,t);//�պ϶����
	delete line;
}

void CTestView::OnTleft()
{
	// TODO: �ڴ���������������
	trans.Translate(-10,0);
	Invalidate(FALSE);
}


void CTestView::OnTright()
{
	// TODO: �ڴ���������������
	CDC *pDC=GetDC();
	trans.Translate(10,0);
	DoubleBuffer(pDC);
	ReleaseDC(pDC);
}


void CTestView::OnTup()
{
	// TODO: �ڴ���������������
	trans.Translate(0,10);
	Invalidate(FALSE);	
}


void CTestView::OnTdown()
{
	// TODO: �ڴ���������������
	trans.Translate(0,-10);
	Invalidate(FALSE);	
}


void CTestView::OnSincrease()
{
	// TODO: �ڴ���������������
	trans.Scale(2,2);
	Invalidate(FALSE);	
}


void CTestView::OnSdecrease()
{
	// TODO: �ڴ���������������
	trans.Scale(0.5,0.5);
	Invalidate(FALSE);	
}


void CTestView::OnRclockwise()
{
	// TODO: �ڴ���������������
	CP2 p=(P[0]+P[2])/2;
	trans.Rotate(30,p);
	Invalidate(FALSE);
}


void CTestView::OnRcounterclockwise()
{
	// TODO: �ڴ���������������
	CP2 p=(P[0]+P[2])/2;
    trans.Rotate(-30,p);
	Invalidate(FALSE);	
}


void CTestView::OnRxaxis()
{
	// TODO: �ڴ���������������
	trans.ReflectX();
	Invalidate(FALSE);	
}


void CTestView::OnRyaxis()
{
	// TODO: �ڴ���������������
	trans.ReflectY();
	Invalidate(FALSE);	
}


void CTestView::OnRorg()
{
	// TODO: �ڴ���������������
	trans.ReflectOrg();
	Invalidate(FALSE);	
}


void CTestView::OnSxdirectionneg()
{
	// TODO: �ڴ���������������
	trans.Shear(0,-1);
	Invalidate(FALSE);	
}


void CTestView::OnSxdirectionplus()
{
	// TODO: �ڴ���������������
	trans.Shear(0,1);
	Invalidate(FALSE);	
}


void CTestView::OnSydirectionneg()
{
	// TODO: �ڴ���������������
	trans.Shear(-1,0);
	Invalidate(FALSE);	
}


void CTestView::OnSydirectionplus()
{
	// TODO: �ڴ���������������
	trans.Shear(1,0);
	Invalidate(FALSE);	
}


//void CTestView::OnReset()
//{
//	// TODO: �ڴ���������������
//	ReadPoint();
//	Invalidate(FALSE);	
//}


void CTestView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	ReadPoint();
	trans.SetMat(P,4);
}


void CTestView::OnReset()
{
	// TODO: �ڴ���������������
	ReadPoint();
	Invalidate(FALSE);	
}
