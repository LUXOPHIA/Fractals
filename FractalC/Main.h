//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ExtCtrls.hpp>
#include <LIB.h>
#include <LIB_Complex.h>
#include <LIB_Color.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TImage *Image1;
	TPanel *Panel1;
	TGroupBox *GroupBoxI;
	TLabel *LabelW;
	TEdit *EditW;
	TLabel *LabelH;
	TEdit *EditH;
	TLabel *LabelA;
	TPopupBox *PopupBoxA;
	TLabel *LabelN;
	TEdit *EditN;
	TGroupBox *GroupBoxR;
	TButton *ButtonP;
	TButton *ButtonB;
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall ButtonPClick(TObject *Sender);
	void __fastcall ButtonBClick(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	int          _SizeW;
	int          _SizeH;
	int          _FuncN;
	TDoubleAreaC _AreaC;
	/////
	__fastcall TForm1(TComponent* Owner);
	/////
	TDoubleC ScreenComplex( const int X_, const int Y_ );
	TSingleRGBA ComplexColor( const TDoubleC C_ );
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
