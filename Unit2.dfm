object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 524
  ClientWidth = 750
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Chart1: TChart
    Left = -1
    Top = 8
    Width = 754
    Height = 521
    Title.Text.Strings = (
      'TChart')
    OnBeforeDrawAxes = Chart1BeforeDrawAxes
    TabOrder = 0
  end
end
