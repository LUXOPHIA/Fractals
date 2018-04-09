#ifndef LIB_ColorH
#define LIB_ColorH
//############################################################################## ■

#include <System.UITypes.hpp>
#include <LIB.h>

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【型】

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【レコード】

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TByteRGBA

struct TByteRGBA
{
private:
public:
	uint8_t B;
	uint8_t G;
	uint8_t R;
	uint8_t A;
	/////
	TByteRGBA(){};
	TByteRGBA( const uint8_t R_, const uint8_t G_, const uint8_t B_, const uint8_t A_ = 0xFF );
	TByteRGBA( const uint8_t L_ );
	///// プロパティ
	///// 演算子
	friend TByteRGBA operator+( const TByteRGBA A, const TByteRGBA B );
	friend TByteRGBA operator-( const TByteRGBA A, const TByteRGBA B );
	friend TByteRGBA operator*( const TByteRGBA A, const float B );
	friend TByteRGBA operator/( const TByteRGBA A, const float B );
	///// 型変換
	operator TAlphaColor() const;
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TSingleRGBA

struct TSingleRGBA
{
private:
public:
	float B;
	float G;
	float R;
	float A;
	/////
	TSingleRGBA(){};
	TSingleRGBA( const float R_, const float G_, const float B_, const float A_ = 1 );
	TSingleRGBA( const float L_ );
	///// プロパティ
	///// 演算子
	friend TSingleRGBA operator+( const TSingleRGBA A, const TSingleRGBA B );
	friend TSingleRGBA operator-( const TSingleRGBA A, const TSingleRGBA B );
	friend TSingleRGBA operator*( const TSingleRGBA A, const float B );
	friend TSingleRGBA operator/( const TSingleRGBA A, const float B );
	///// 型変換
	operator TByteRGBA() const;
	operator TAlphaColor() const;
};

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【クラス】

///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【定数】

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【変数】

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【ルーチン】

//############################################################################## ■
#endif
