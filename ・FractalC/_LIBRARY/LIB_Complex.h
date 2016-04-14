#ifndef LIB_ComplexH
#define LIB_ComplexH
//############################################################################## ��

#include <LIB.h>

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$�y�^�z

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$�y���R�[�h�z

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TDoubleC

struct TDoubleC
{
private:
  ///// �A�N�Z�T
  double GetAbs2();
  double GetAbso();
public:
  double R;
  double I;
  /////
  TDoubleC(){};
  TDoubleC( const double R_ );
  TDoubleC( const double R_, const double I_ );
  ///// �v���p�e�B
  __property double Abs2 = { read = GetAbs2 };
  __property double Abso = { read = GetAbso };
  ///// ���Z�q
  friend TDoubleC operator+( const TDoubleC& A_, const TDoubleC& B_ );
  friend TDoubleC operator*( const TDoubleC& A_, const TDoubleC& B_ );
  ///// �^�ϊ�
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TDoubleAreaC

struct TDoubleAreaC
{
private:
  ///// �A�N�Z�T
  double GetSizeR();
  double GetSizeI();
public:
  TDoubleC Min;
  TDoubleC Max;
  /////
  TDoubleAreaC(){};
  TDoubleAreaC( const double MinR_, const double MinI_, const double MaxR_, const double MaxI_ );
  ///// �v���p�e�B
  __property double SizeR = { read = GetSizeR };
  __property double SizeI = { read = GetSizeI };
  ///// ���Z�q
  ///// �^�ϊ�
};

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$�y�N���X�z

///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$�y�萔�z

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$�y�ϐ��z

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$�y���[�`���z

TDoubleC Pow2( const TDoubleC X_ );

//############################################################################## ��
#endif
