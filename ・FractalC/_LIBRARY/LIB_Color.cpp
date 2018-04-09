#pragma hdrstop
#include "LIB_Color.h"
#pragma package(smart_init)
//############################################################################## ■

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【レコード】

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TByteRGBA

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

TByteRGBA::TByteRGBA( const uint8_t L_, const uint8_t A_ )
{
	R = L_;
	G = L_;
	B = L_;
	A = 0xFF;
}

TByteRGBA::TByteRGBA( const uint8_t R_, const uint8_t G_, const uint8_t B_, const uint8_t A_ )
{
	R = R_;
	G = G_;
	B = B_;
	A = A_;
}

///////////////////////////////////////////////////////////////////////// 演算子

TByteRGBA operator+( const TByteRGBA& A_ )
{
	TByteRGBA Result;

	Result.R = +A_.R;
	Result.G = +A_.G;
	Result.B = +A_.B;
	Result.A = +A_.A;

	return Result;
}

TByteRGBA operator+( const TByteRGBA& A_, const TByteRGBA& B_ )
{
	TByteRGBA Result;

	Result.R = A_.R + B_.R;
	Result.G = A_.G + B_.G;
	Result.B = A_.B + B_.B;
	Result.A = A_.A + B_.A;

	return Result;
}

TByteRGBA operator-( const TByteRGBA& A_, const TByteRGBA& B_ )
{
	TByteRGBA Result;

	Result.R = A_.R - B_.R;
	Result.G = A_.G - B_.G;
	Result.B = A_.B - B_.B;
	Result.A = A_.A - B_.A;

	return Result;
}

TByteRGBA operator*( const TByteRGBA& A_, const uint8_t& B_ )
{
	TByteRGBA Result;

	Result.R = A_.R * B_;
	Result.G = A_.G * B_;
	Result.B = A_.B * B_;
	Result.A = A_.A * B_;

	return Result;
}

TByteRGBA operator/( const TByteRGBA& A_, const uint8_t& B_ )
{
	TByteRGBA Result;

	Result.R = A_.R / B_;
	Result.G = A_.G / B_;
	Result.B = A_.B / B_;
	Result.A = A_.A / B_;

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

TSingleRGBA::TSingleRGBA( const float L_, const float A_ )
{
	R = L_;
	G = L_;
	B = L_;
	A = A_;
}

TSingleRGBA::TSingleRGBA( const float R_, const float G_, const float B_, const float A_ )
{
	R = R_;
	G = G_;
	B = B_;
	A = A_;
}

///////////////////////////////////////////////////////////////////////// 演算子

TSingleRGBA operator+( const TSingleRGBA& A_ )
{
	TSingleRGBA Result;

	Result.R = +A_.R;
	Result.G = +A_.G;
	Result.B = +A_.B;
	Result.A = +A_.A;

	return Result;
}

TSingleRGBA operator-( const TSingleRGBA& A_ )
{
	TSingleRGBA Result;

	Result.R = -A_.R;
	Result.G = -A_.G;
	Result.B = -A_.B;
	Result.A = -A_.A;

	return Result;
}

TSingleRGBA operator+( const TSingleRGBA& A_, const TSingleRGBA& B_ )
{
	TSingleRGBA Result;

	Result.R = A_.R + B_.R;
	Result.G = A_.G + B_.G;
	Result.B = A_.B + B_.B;
	Result.A = A_.A + B_.A;

	return Result;
}

TSingleRGBA operator-( const TSingleRGBA& A_, const TSingleRGBA& B_ )
{
	TSingleRGBA Result;

	Result.R = A_.R - B_.R;
	Result.G = A_.G - B_.G;
	Result.B = A_.B - B_.B;
	Result.A = A_.A - B_.A;

	return Result;
}

TSingleRGBA operator*( const TSingleRGBA& A_, const float& B_ )
{
	TSingleRGBA Result;

	Result.R = A_.R * B_;
	Result.G = A_.G * B_;
	Result.B = A_.B * B_;
	Result.A = A_.A * B_;

	return Result;
}

TSingleRGBA operator/( const TSingleRGBA& A_, const float& B_ )
{
	TSingleRGBA Result;

	Result.R = A_.R / B_;
	Result.G = A_.G / B_;
	Result.B = A_.B / B_;
	Result.A = A_.A / B_;

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
