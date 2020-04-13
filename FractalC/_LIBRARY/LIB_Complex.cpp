#pragma hdrstop
#include "LIB_Complex.h"
#pragma package(smart_init)
//############################################################################## ■

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【レコード】

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TDoubleC

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

/////////////////////////////////////////////////////////////////////// アクセス

double TDoubleC::GetAbs2() const
{
	return R*R + I*I;
}

double TDoubleC::GetAbso() const
{
	return std::sqrt( GetAbs2() );
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

TDoubleC::TDoubleC( const double R_ )
{
	R = R_;
	I = 0.0;
}

TDoubleC::TDoubleC( const double R_, const double I_ )
{
	R = R_;
	I = I_;
}

///////////////////////////////////////////////////////////////////////// 演算子

TDoubleC operator+( const TDoubleC& A_ )
{
	TDoubleC Result;

	Result.R = +A_.R;
	Result.I = +A_.I;

	return Result;
}

TDoubleC operator-( const TDoubleC& A_ )
{
	TDoubleC Result;

	Result.R = -A_.R;
	Result.I = -A_.I;

	return Result;
}

TDoubleC operator+( const TDoubleC& A_, const TDoubleC& B_ )
{
	TDoubleC Result;

	Result.R = A_.R + B_.R;
	Result.I = A_.I + B_.I;

	return Result;
}

TDoubleC operator-( const TDoubleC& A_, const TDoubleC& B_ )
{
	TDoubleC Result;

	Result.R = A_.R - B_.R;
	Result.I = A_.I - B_.I;

	return Result;
}

TDoubleC operator*( const TDoubleC& A_, const TDoubleC& B_ )
{
	TDoubleC Result;

	Result.R = A_.R * B_.R - A_.I * B_.I;
	Result.I = A_.I * B_.R + A_.R * B_.I;

	return Result;
}

TDoubleC operator*( const TDoubleC& A_, const double& B_ )
{
	TDoubleC Result;

	Result.R = A_.R * B_;
	Result.I = A_.I * B_;

	return Result;
}

TDoubleC operator*( const double& A_, const TDoubleC& B_ )
{
	TDoubleC Result;

	Result.R = A_ * B_.R;
	Result.I = A_ * B_.I;

	return Result;
}

TDoubleC operator/( const TDoubleC& A_, const TDoubleC& B_ )
{
	TDoubleC Result;

	double C = B_.Abs2;

	Result.R = ( A_.R * B_.R + A_.I * B_.I ) / C;
	Result.I = ( A_.I * B_.R - A_.R * B_.I ) / C;

	return Result;
}

TDoubleC operator/( const TDoubleC& A_, const double& B_ )
{
	TDoubleC Result;

	Result.R = A_.R / B_;
	Result.I = A_.I / B_;

	return Result;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TDoubleAreaC

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

/////////////////////////////////////////////////////////////////////// アクセス

double TDoubleAreaC::GetSizeR() const
{
	return Max.R - Min.R;
}

double TDoubleAreaC::GetSizeI() const
{
	return Max.I - Min.I;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

TDoubleAreaC::TDoubleAreaC( const double MinR_, const double MinI_, const double MaxR_, const double MaxI_ )
{
	Min.R = MinR_;
	Min.I = MinI_;
	Max.R = MaxR_;
	Max.I = MaxI_;
}

///////////////////////////////////////////////////////////////////////// 演算子

///////////////////////////////////////////////////////////////////////// 型変換

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【クラス】

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【ルーチン】

TDoubleC Pow2( const TDoubleC X_ )
{
	return X_ * X_;
}

//############################################################################## ■