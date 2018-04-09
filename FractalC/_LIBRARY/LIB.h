#ifndef LIBH
#define LIBH
//############################################################################## ¡

#include<System.UITypes.hpp>
#include<FMX.Types.hpp>

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$yŒ^z

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$yƒŒƒR[ƒhz

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$yƒNƒ‰ƒXz

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$y’è”z

static const double Pi2 = 2.0 * M_PI;
static const double Pi3 = 3.0 * M_PI;
static const double Pi4 = 4.0 * M_PI;

static const double P2i = M_PI / 2.0;
static const double P3i = M_PI / 3.0;
static const double P4i = M_PI / 4.0;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$y•Ï”z

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$yƒ‹[ƒ`ƒ“z

float Pow2( const float X_ );
double Pow2( const double X_ );

float Roo2( const float X_ );
double Roo2( const double X_ );

int Clamp( const int X_, const int Min_, const int Max_ );
float Clamp( const float X_, const float Min_, const float Max_ );
double Clamp( const double X_, const double Min_, const double Max_ );

//############################################################################## ¡
#endif
