object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 502
  ClientWidth = 685
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ComboBox1: TComboBox
    Left = 24
    Top = 24
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    OnChange = ComboBox1Change
  end
  object ListBox1: TListBox
    Left = 24
    Top = 115
    Width = 145
    Height = 25
    ItemHeight = 13
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 499
    Top = 8
    Width = 178
    Height = 233
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object ComboBox2: TComboBox
    Left = 24
    Top = 64
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 3
    OnChange = ComboBox2Change
  end
  object Chart1: TChart
    Left = 24
    Top = 208
    Width = 449
    Height = 273
    Title.Text.Strings = (
      'TChart')
    TabOrder = 4
  end
  object Button1: TButton
    Left = 24
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 5
    OnClick = Button1Click
  end
end