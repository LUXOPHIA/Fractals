unit Main;

interface //#################################################################### Å°

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs,
  FMX.StdCtrls, FMX.ExtCtrls, FMX.Edit, FMX.Controls.Presentation, FMX.Objects,
  LIB, LIB.Complex, LIB.Color;

type
  TForm1 = class(TForm)
    Image1: TImage;
    GroupBoxI: TGroupBox;
    LabelW: TLabel;
    EditW: TEdit;
    LabelH: TLabel;
    EditH: TEdit;
    LabelA: TLabel;
    PopupBoxA: TPopupBox;
    LabelN: TLabel;
    EditN: TEdit;
    GroupBoxR: TGroupBox;
    ButtonP: TButton;
    ButtonB: TButton;
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure ButtonPClick(Sender: TObject);
    procedure ButtonBClick(Sender: TObject);
  private
    { private êÈåæ }
  public
    { public êÈåæ }
    _SizeW :Integer;
    _SizeH :Integer;
    _FuncN :Integer;
    _AreaC :TDoubleAreaC;
    /////
    function ScreenToComplex( const X_,Y_:Integer ) :TDoubleC;
    function ComplexToColor( const C_:TDoubleC ) :TByteRGBA;
  end;

var
  Form1: TForm1;

implementation //############################################################### Å°

{$R *.fmx}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& private

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& public

function TForm1.ScreenToComplex( const X_,Y_:Integer ) :TDoubleC;
begin
     with _AreaC do
     begin
          Result.R := Min.R + SizeR / _SizeW * ( X_ + 0.5 );
          Result.I := Max.I - SizeI / _SizeH * ( Y_ + 0.5 );
     end;
end;

function TForm1.ComplexToColor( const C_:TDoubleC ) :TByteRGBA;
var
   Z :TDoubleC;
   N :Integer;
begin
     Z := 0;

     for N := 1 to _FuncN do
     begin
          Z := Pow2( Z ) + C_;

          if Z.Abso > 2 then
          begin
               with Result do
               begin
                    R := ( N +   0 ) mod 256;
                    G := ( N +  85 ) mod 256;
                    B := ( N + 170 ) mod 256;
                    A := $FF;
               end;

               Exit;
          end;
     end;

     Result := 0;
end;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

procedure TForm1.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
     CanClose := ButtonP.Enabled;
end;

////////////////////////////////////////////////////////////////////////////////

procedure TForm1.ButtonPClick(Sender: TObject);
var
   X, Y :Integer;
   B :TBitmapData;
   C :TDoubleC;
begin
     ButtonP.Enabled := False;
     ButtonB.Enabled := True;

     _SizeW := StrToInt( EditW.Text );
     _SizeH := StrToInt( EditH.Text );

     _FuncN := StrToInt( EditN.Text );

     case PopupBoxA.ItemIndex of
       0: _AreaC := TDoubleAreaC.Create( -2.00000, -2.00000, +2.00000, +2.00000 );
       1: _AreaC := TDoubleAreaC.Create( -0.97217, -0.25280, -0.96717, -0.24780 );
       2: _AreaC := TDoubleAreaC.Create( +0.26220, -0.00250, +0.26270, -0.00200 );
       3: _AreaC := TDoubleAreaC.Create( -1.25500, +0.02520, -1.25450, +0.02570 );
       4: _AreaC := TDoubleAreaC.Create( -0.33800, -0.61500, -0.33700, -0.61400 );
       5: _AreaC := TDoubleAreaC.Create( -1.25500, +0.02370, -1.25300, +0.02570 );
       6: _AreaC := TDoubleAreaC.Create( +0.26000, -0.00300, +0.26200, -0.00100 );
     end;

     with Image1.Bitmap do
     begin
          SetSize( _SizeW, _SizeH );

          Clear( TAlphaColors.Black );

          for Y := 0 to _SizeH-1 do
          begin
               Map( TMapAccess.Write, B );

               for X := 0 to _SizeW-1 do
               begin
                    C := ScreenToComplex( X, Y );

                    B.Color[ X, Y ] := ComplexToColor( C );
               end;

               Unmap( B );

               Application.ProcessMessages;

               if not ButtonB.Enabled then Break;
          end;

          if ButtonB.Enabled then SaveToFile( 'Image.png' );
     end;

     ButtonP.Enabled := True;
     ButtonB.Enabled := False;
end;

procedure TForm1.ButtonBClick(Sender: TObject);
begin
     ButtonB.Enabled := False;
end;

end. //######################################################################### Å°
