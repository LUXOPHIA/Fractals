#pragma hdrstop
#include "LIB.h"
#pragma package(smart_init)
//############################################################################## ¡

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$yƒŒƒR[ƒhz

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$yƒNƒ‰ƒXz

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$yƒ‹[ƒ`ƒ“z

float Pow2( const float X_ )
{
	 return X_ * X_;
}

double Pow2( const double X_ )
{
	 return X_ * X_;
}

////////////////////////////////////////////////////////////////////////////////

float Roo2( const float X_ )
{
	 return Sqrt( X_ );
}

double Roo2( const double X_ )
{
	 return Sqrt( X_ );
}

////////////////////////////////////////////////////////////////////////////////

int ClipRange( const int X_, const int Min_, const int Max_ )
{
	 if ( X_ < Min_ ) return Min_;
				 else
	 if ( X_ > Max_ ) return Max_;
				 else return X_;
}

float ClipRange( const float X_, const float Min_, const float Max_ )
{
	 if ( X_ < Min_ ) return Min_;
				 else
	 if ( X_ > Max_ ) return Max_;
				 else return X_;
}

double ClipRange( const double X_, const double Min_, const double Max_ )
{
	 if ( X_ < Min_ ) return Min_;
				 else
	 if ( X_ > Max_ ) return Max_;
				 else return X_;
}

//############################################################################## ¡
