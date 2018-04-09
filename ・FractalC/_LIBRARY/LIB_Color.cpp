#pragma hdrstop
#include "LIB_Color.h"
#pragma package(smart_init)
//############################################################################## ■

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【レコード】

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TByteRGBA

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

TByteRGBA::TByteRGBA( const uint8_t R_, const uint8_t G_, const uint8_t B_, const uint8_t A_ )
{
	R = R_;
	G = G_;
	B = B_;
	A = A_;
}

TByteRGBA::TByteRGBA( const uint8_t L_ )
{
	R = L_;
	G = L_;
	B = L_;
	A = 0xFF;
}

///////////////////////////////////////////////////////////////////////// 演算子

TByteRGBA operator+( const TByteRGBA A, const TByteRGBA B )
{
	TByteRGBA Result;

	Result.R = A.R + B.R;
	Result.G = A.G + B.G;
	Result.B = A.B + B.B;
	Result.A = A.A + B.A;

	return Result;
}

TByteRGBA operator-( const TByteRGBA A, const TByteRGBA B )
{
	TByteRGBA Result;

	Result.R = A.R - B.R;
	Result.G = A.G - B.G;
	Result.B = A.B - B.B;
	Result.A = A.A - B.A;

	return Result;
}

TByteRGBA operator*( const TByteRGBA A, const float B )
{
	TByteRGBA Result;

	Result.R = A.R * B;
	Result.G = A.G * B;
	Result.B = A.B * B;
	Result.A = A.A * B;

	return Result;
}

TByteRGBA operator/( const TByteRGBA A, const int B )
{
	TByteRGBA Result;

	Result.R = A.R / B;
	Result.G = A.G / B;
	Result.B = A.B / B;
	Result.A = A.A / B;

	return Result;
}

///////////////////////////////////////////////////////////////////////// 型変換

TByteRGBA::operator TAlphaColor() const
{
	return *PAlphaColor( this );
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TSingleRGBA

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

TSingleRGBA::TSingleRGBA( const float R_, const float G_, const float B_, const float A_ )
{
	R = R_;
	G = G_;
	B = B_;
	A = A_;
}

TSingleRGBA::TSingleRGBA( const float L_ )
{
	R = L_;
	G = L_;
	B = L_;
	A = 1 ;
}

///////////////////////////////////////////////////////////////////////// 演算子

TSingleRGBA operator+( const TSingleRGBA A, const TSingleRGBA B )
{
	TSingleRGBA Result;

	Result.R = A.R + B.R;
	Result.G = A.G + B.G;
	Result.B = A.B + B.B;
	Result.A = A.A + B.A;

	return Result;
}

TSingleRGBA operator-( const TSingleRGBA A, const TSingleRGBA B )
{
	TSingleRGBA Result;

	Result.R = A.R - B.R;
	Result.G = A.G - B.G;
	Result.B = A.B - B.B;
	Result.A = A.A - B.A;

	return Result;
}

TSingleRGBA operator*( const TSingleRGBA A, const float B )
{
	TSingleRGBA Result;

	Result.R = A.R * B;
	Result.G = A.G * B;
	Result.B = A.B * B;
	Result.A = A.A * B;

	return Result;
}

TSingleRGBA operator/( const TSingleRGBA A, const float B )
{
	TSingleRGBA Result;

	Result.R = A.R / B;
	Result.G = A.G / B;
	Result.B = A.B / B;
	Result.A = A.A / B;

	return Result;
}

///////////////////////////////////////////////////////////////////////// 型変換

TSingleRGBA::operator TByteRGBA() const
{
	TByteRGBA Result;

	Result.R = round( 255 * Clamp( R, 0.0f, 1.0f ) );
	Result.G = round( 255 * Clamp( G, 0.0f, 1.0f ) );
	Result.B = round( 255 * Clamp( B, 0.0f, 1.0f ) );
	Result.A = round( 255 * Clamp( A, 0.0f, 1.0f ) );

	return Result;
}

TSingleRGBA::operator TAlphaColor() const
{
	return this->operator TByteRGBA();
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【クラス】

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【ルーチン】

//############################################################################## ■
