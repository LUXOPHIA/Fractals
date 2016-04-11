unit LIB.Complex;

interface //#################################################################### Å°

uses LIB;

type //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$Åyå^Åz

     //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉåÉRÅ[ÉhÅz

     //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TDoubleC

     TDoubleC = record
     private
       ///// ÉAÉNÉZÉT
       function GetAbs2 :Double;
       function GetAbso :Double;
     public
       R :Double;
       I :Double;
       /////
       constructor Create( const R_,I_:Double );
       ///// ÉvÉçÉpÉeÉB
       property Abs2 :Double read GetAbs2;
       property Abso :Double read GetAbso;
       ///// ââéZéq
       class operator Add( const A_,B_:TDoubleC ) :TDoubleC;
       class operator Multiply( const A_,B_:TDoubleC ) :TDoubleC;
       ///// å^ïœä∑
       class operator Implicit( const V_:Double ) :TDoubleC;
     end;

     //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TDoubleAreaC

     TDoubleAreaC = record
     private
       ///// ÉAÉNÉZÉT
       function GetSizeR :Double;
       function GetSizeI :Double;
     public
       Min :TDoubleC;
       Max :TDoubleC;
       /////
       constructor Create( const MinR_,MinI_,MaxR_,MaxI_:Double );
       ///// ÉvÉçÉpÉeÉB
       property SizeR :Double read GetSizeR;
       property SizeI :Double read GetSizeI;
       ///// ââéZéq
       ///// å^ïœä∑
     end;

     //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉNÉâÉXÅz

//const //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyíËêîÅz

//var //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyïœêîÅz

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉãÅ[É`ÉìÅz

function Pow2( const X_:TDoubleC ) :TDoubleC; inline; overload;

implementation //############################################################### Å°

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉåÉRÅ[ÉhÅz

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TDoubleC

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

function TDoubleC.GetAbs2 :Double;
begin
     Result := Pow2( R ) + Pow2( I );
end;

function TDoubleC.GetAbso :Double;
begin
     Result := Roo2( GetAbs2 );
end;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

constructor TDoubleC.Create( const R_,I_:Double );
begin
     R := R_;
     I := I_;
end;

///////////////////////////////////////////////////////////////////////// ââéZéq

class operator TDoubleC.Add( const A_,B_:TDoubleC ) :TDoubleC;
begin
     with Result do
     begin
          R := A_.R + B_.R;
          I := A_.I + B_.I;
     end;
end;

class operator TDoubleC.Multiply( const A_,B_:TDoubleC ) :TDoubleC;
begin
     with Result do
     begin
          R := A_.R * B_.R - A_.I * B_.I;
          I := A_.R * B_.I + A_.I * B_.R;
     end;
end;

///////////////////////////////////////////////////////////////////////// å^ïœä∑

class operator TDoubleC.Implicit( const V_:Double ) :TDoubleC;
begin
     with Result do
     begin
          R := V_;
          I := 0;
     end;
end;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% TDoubleAreaC

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

function TDoubleAreaC.GetSizeR :Double;
begin
     Result := Max.R - Min.R;
end;

function TDoubleAreaC.GetSizeI :Double;
begin
     Result := Max.I - Min.I;
end;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

constructor TDoubleAreaC.Create( const MinR_,MinI_,MaxR_,MaxI_:Double );
begin
     with Min do
     begin
          R := MinR_;
          I := MinI_;
     end;

     with Max do
     begin
          R := MaxR_;
          I := MaxI_;
     end;
end;

///////////////////////////////////////////////////////////////////////// ââéZéq

///////////////////////////////////////////////////////////////////////// å^ïœä∑

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉNÉâÉXÅz

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ÅyÉãÅ[É`ÉìÅz

function Pow2( const X_:TDoubleC ) :TDoubleC;
begin
     Result := X_ * X_;
end;

//############################################################################## Å†

initialization //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ èâä˙âª

finalization //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ ç≈èIâª

end. //######################################################################### Å°
