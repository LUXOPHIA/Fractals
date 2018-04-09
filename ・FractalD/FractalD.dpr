program FractalD;

uses
  System.StartUpCopy,
  FMX.Forms,
  Main in 'Main.pas' {Form1},
  LIB.Complex in '_LIBRARY\LIB.Complex.pas',
  LIB in '_LIBRARY\LIB.pas',
  LIB.Color in '_LIBRARY\LIB.Color.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
