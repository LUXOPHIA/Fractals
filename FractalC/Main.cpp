//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

TDoubleC TForm1::ScreenComplex( const int X_, const int Y_ )
{
	TDoubleC Result;

	Result.R = _AreaC.Min.R + _AreaC.SizeR / _SizeW * ( X_ + 0.5 );
	Result.I = _AreaC.Max.I - _AreaC.SizeI / _SizeH * ( Y_ + 0.5 );

	return Result;
}

TSingleRGBA TForm1::ComplexColor( const TDoubleC C_ )
{
	TSingleRGBA C0 { 0, 0, 0, 1 };
	TSingleRGBA C1 { 1, 1, 1, 1 };

	TDoubleC Z = 0;

	for ( int N = 1; N <= _FuncN; ++N )
	{
		Z = Pow2( Z ) + C_;

		if ( Z.Abso > 2 ) return ( C1 - C0 ) * float( N / _FuncN ) + C0;
	}

	return C1;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	 CanClose = ButtonP->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonPClick(TObject *Sender)
{
	ButtonP->Enabled = false;
	ButtonB->Enabled = true;

	_SizeW = StrToInt( EditW->Text );
	_SizeH = StrToInt( EditH->Text );

	_FuncN  = StrToInt( EditN->Text );

	switch ( PopupBoxA->ItemIndex )
	{
		case 0: _AreaC = TDoubleAreaC( -2.00000, -2.00000, +2.00000, +2.00000 );  break;
		case 1: _AreaC = TDoubleAreaC( -0.97217, -0.25280, -0.96717, -0.24780 );  break;
		case 2: _AreaC = TDoubleAreaC( +0.26220, -0.00250, +0.26270, -0.00200 );  break;
		case 3: _AreaC = TDoubleAreaC( -1.25500, +0.02520, -1.25450, +0.02570 );  break;
		case 4: _AreaC = TDoubleAreaC( -0.33800, -0.61500, -0.33700, -0.61400 );  break;
		case 5: _AreaC = TDoubleAreaC( -1.25500, +0.02370, -1.25300, +0.02570 );  break;
		case 6: _AreaC = TDoubleAreaC( +0.26000, -0.00300, +0.26200, -0.00100 );  break;
	};

	Image1->Bitmap->SetSize( _SizeW, _SizeH );

	Image1->Bitmap->Clear( TAlphaColors::Black );

	for ( int Y = 0; Y < _SizeH; ++Y )
	{
		TBitmapData B;
		Image1->Bitmap->Map( Fmx::Graphics::TMapAccess::Write, B );

		for ( int X = 0; X < _SizeW; ++X )
		{
			TDoubleC C = ScreenComplex( X, Y );

			B.SetPixel( X, Y, TAlphaColor( ComplexColor( C ) ) );
		}

		Image1->Bitmap->Unmap( B );

		Application->ProcessMessages();

		if ( !ButtonB->Enabled ) break;
	}

	if ( ButtonB->Enabled ) Image1->Bitmap->SaveToFile( "Image.png" );

	ButtonP->Enabled = true;
	ButtonB->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonBClick(TObject *Sender)
{
	ButtonB->Enabled = false;
}
//---------------------------------------------------------------------------
