#ifndef LIB_ComplexH
#define LIB_ComplexH
//############################################################################## ■

#include <LIB.h>

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【型】

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【レコード】

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TDoubleC

struct TDoubleC
{
private:
  ///// アクセサ
  double GetAbs2();
  double GetAbso();
public:
  double R;
  double I;
  /////
  TDoubleC(){};
  TDoubleC( const double R_ );
  TDoubleC( const double R_, const double I_ );
  ///// プロパティ
  __property double Abs2 = { read = GetAbs2 };
  __property double Abso = { read = GetAbso };
  ///// 演算子
  friend TDoubleC operator+( const TDoubleC& A_, const TDoubleC& B_ );
  friend TDoubleC operator*( const TDoubleC& A_, const TDoubleC& B_ );
  ///// 型変換
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TDoubleAreaC

struct TDoubleAreaC
{
private:
  ///// アクセサ
  double GetSizeR();
  double GetSizeI();
public:
  TDoubleC Min;
  TDoubleC Max;
  /////
  TDoubleAreaC(){};
  TDoubleAreaC( const double MinR_, const double MinI_, const double MaxR_, const double MaxI_ );
  ///// プロパティ
  __property double SizeR = { read = GetSizeR };
  __property double SizeI = { read = GetSizeI };
  ///// 演算子
  ///// 型変換
};

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【クラス】

///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【定数】

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【変数】

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【ルーチン】

TDoubleC Pow2( const TDoubleC X_ );

//############################################################################## ■
#endif
