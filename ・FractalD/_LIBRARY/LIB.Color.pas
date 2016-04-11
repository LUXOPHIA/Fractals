unit LIB.Color;

interface //#################################################################### Å°

uses System.UITypes,
     LIB;

type //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$Åyå^Åz

     //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉåÉRÅ[ÉhÅz

     //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TByteRGBA

     TByteRGBA = packed record
     private
     public
       B :Byte;
       G :Byte;
       R :Byte;
       A :Byte;
       /////
       constructor Create( const R_,G_,B_:Byte; const A_:Byte = $FF );
       ///// ÉvÉçÉpÉeÉB
       ///// ââéZéq
       ///// å^ïœä∑
       class operator Implicit( const L_:Byte ) :TByteRGBA;
       class operator Implicit( const C_:TByteRGBA ) :TAlphaColor;
     end;

     //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TSingleRGBA

     TSingleRGBA = packed record
     private
     public
       R :Single;
       G :Single;
       B :Single;
       A :Single;
       /////
       constructor Create( const R_,G_,B_:Single; const A_:Single = 1 );
       ///// ÉvÉçÉpÉeÉB
       ///// ââéZéq
       class operator Negative( const V_:TSingleRGBA ) :TSingleRGBA;
       class operator Positive( const V_:TSingleRGBA ) :TSingleRGBA;
       class operator Add( const A_,B_:TSingleRGBA ) :TSingleRGBA;
       class operator Subtract( const A_,B_:TSingleRGBA ) :TSingleRGBA;
       class operator Multiply( const A_:Single; const B_:TSingleRGBA ): TSingleRGBA;
       class operator Multiply( const A_:TSingleRGBA; const B_:Single ): TSingleRGBA;
       class operator Divide( const A_:TSingleRGBA; const B_:Single ): TSingleRGBA;
       ///// å^ïœä∑
       class operator Implicit( const L_:Single ) :TSingleRGBA;
       class operator Implicit( const C_:TSingleRGBA ) :TByteRGBA;
     end;

     //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉNÉâÉXÅz

//const //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyíËêîÅz

//var //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyïœêîÅz

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉãÅ[É`ÉìÅz

implementation //############################################################### Å°

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉåÉRÅ[ÉhÅz

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TByteRGBA

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

constructor TByteRGBA.Create( const R_,G_,B_:Byte; const A_:Byte );
begin
     R := R_;
     G := G_;
     B := B_;
     A := A_;
end;

///////////////////////////////////////////////////////////////////////// ââéZéq

///////////////////////////////////////////////////////////////////////// å^ïœä∑

class operator TByteRGBA.Implicit( const L_:Byte ) :TByteRGBA;
begin
     with Result do
     begin
          R := L_;
          G := L_;
          B := L_;
          A := $FF;
     end;
end;

class operator TByteRGBA.Implicit( const C_:TByteRGBA ) :TAlphaColor;
begin
     Result := PAlphaColor( @C_ )^;
end;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TSingleRGBA

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

constructor TSingleRGBA.Create( const R_,G_,B_:Single; const A_:Single = 1 );
begin
     R := R_;
     G := G_;
     B := B_;
     A := A_;
end;

///////////////////////////////////////////////////////////////////////// ââéZéq

class operator TSingleRGBA.Negative( const V_:TSingleRGBA ) :TSingleRGBA;
begin
     with Result do
     begin
          R := -V_.R;
          G := -V_.G;
          B := -V_.B;
          A := -V_.A;
     end;
end;

class operator TSingleRGBA.Positive( const V_:TSingleRGBA ) :TSingleRGBA;
begin
     with Result do
     begin
          R := +V_.R;
          G := +V_.G;
          B := +V_.B;
          A := +V_.A;
     end;
end;

class operator TSingleRGBA.Add( const A_,B_:TSingleRGBA ) :TSingleRGBA;
begin
     with Result do
     begin
          R := A_.R + B_.R;
          G := A_.G + B_.G;
          B := A_.B + B_.B;
          A := A_.A + B_.A;
     end;
end;

class operator TSingleRGBA.Subtract( const A_,B_:TSingleRGBA ) :TSingleRGBA;
begin
     with Result do
     begin
          R := A_.R - B_.R;
          G := A_.G - B_.G;
          B := A_.B - B_.B;
          A := A_.A - B_.A;
     end;
end;

class operator TSingleRGBA.Multiply( const A_:Single; const B_:TSingleRGBA ): TSingleRGBA;
begin
     with Result do
     begin
          R := A_ * B_.R;
          G := A_ * B_.G;
          B := A_ * B_.B;
          A := A_ * B_.A;
     end;
end;

class operator TSingleRGBA.Multiply( const A_:TSingleRGBA; const B_:Single ): TSingleRGBA;
begin
     with Result do
     begin
          R := A_.R * B_;
          G := A_.G * B_;
          B := A_.B * B_;
          A := A_.A * B_;
     end;
end;

class operator TSingleRGBA.Divide( const A_:TSingleRGBA; const B_:Single ): TSingleRGBA;
begin
     with Result do
     begin
          R := A_.R / B_;
          G := A_.G / B_;
          B := A_.B / B_;
          A := A_.A / B_;
     end;
end;

///////////////////////////////////////////////////////////////////////// å^ïœä∑

class operator TSingleRGBA.Implicit( const L_:Single ) :TSingleRGBA;
begin
     with Result do
     begin
          R := L_;
          G := L_;
          B := L_;
          A := 1;
     end;
end;

class operator TSingleRGBA.Implicit( const C_:TSingleRGBA ) :TByteRGBA;
begin
     with Result do
     begin
          R := ClipRange( Round( 255 * C_.R ), 0, 255 );
          G := ClipRange( Round( 255 * C_.G ), 0, 255 );
          B := ClipRange( Round( 255 * C_.B ), 0, 255 );
          A := ClipRange( Round( 255 * C_.A ), 0, 255 );
     end;
end;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉNÉâÉXÅz

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉãÅ[É`ÉìÅz

//############################################################################## Å†

initialization //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ èâä˙âª

finalization //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ ç≈èIâª

end. //######################################################################### Å°
