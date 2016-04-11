unit LIB;

interface //#################################################################### ■

uses System.UITypes,
     FMX.Graphics;

type //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【型】

     //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【レコード】

     //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【クラス】

     //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% HBitmapData

     HBitmapData = record helper for TBitmapData
     private
       ///// アクセス
       function GetColor( const X_,Y_:Integer ) :TAlphaColor; inline;
       procedure SetColor( const X_,Y_:Integer; const Color_:TAlphaColor ); inline;
     public
       ///// プロパティ
       property Color[ const X_,Y_:Integer ] :TAlphaColor read GetColor write SetColor;
     end;

const //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【定数】

      Pi2 = 2 * Pi;
      Pi3 = 3 * Pi;
      Pi4 = 4 * Pi;

      P2i = Pi / 2;
      P3i = Pi / 3;
      P4i = Pi / 4;

//var //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【変数】

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【ルーチン】

function Pow2( const X_:Single ) :Single; inline; overload;
function Pow2( const X_:Double ) :Double; inline; overload;

function Roo2( const X_:Single ) :Single; inline; overload;
function Roo2( const X_:Double ) :Double; inline; overload;

function ClipRange( const X_,Min_,Max_:Integer ) :Integer; inline; overload;
function ClipRange( const X_,Min_,Max_:Single ) :Single; inline; overload;
function ClipRange( const X_,Min_,Max_:Double ) :Double; inline; overload;

implementation //############################################################### ■

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【レコード】

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【クラス】

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% HBitmapData

function HBitmapData.GetColor( const X_,Y_:Integer ) :TAlphaColor;
begin
     Result := GetPixel( X_, Y_ );
end;

procedure HBitmapData.SetColor( const X_,Y_:Integer; const Color_:TAlphaColor );
begin
     SetPixel( X_, Y_, Color_ );
end;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$【ルーチン】

function Pow2( const X_:Single ) :Single;
begin
     Result := Sqr( X_ );
end;

function Pow2( const X_:Double ) :Double;
begin
     Result := Sqr( X_ );
end;

////////////////////////////////////////////////////////////////////////////////

function Roo2( const X_:Single ) :Single;
begin
     Result := Sqrt( X_ );
end;

function Roo2( const X_:Double ) :Double;
begin
     Result := Sqrt( X_ );
end;

////////////////////////////////////////////////////////////////////////////////

function ClipRange( const X_,Min_,Max_:Integer ) :Integer;
begin
     if X_ < Min_ then Result := Min_
                  else
     if X_ > Max_ then Result := Max_
                  else Result := X_;
end;

function ClipRange( const X_,Min_,Max_:Single ) :Single;
begin
     if X_ < Min_ then Result := Min_
                  else
     if X_ > Max_ then Result := Max_
                  else Result := X_;
end;

function ClipRange( const X_,Min_,Max_:Double ) :Double;
begin
     if X_ < Min_ then Result := Min_
                  else
     if X_ > Max_ then Result := Max_
                  else Result := X_;
end;

//############################################################################## □

initialization //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 初期化

     Randomize;

finalization //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 最終化

end. //######################################################################### ■
