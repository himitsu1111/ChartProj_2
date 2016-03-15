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
    Left = 479
    Top = 8
    Width = 198
    Height = 457
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
    Width = 57
    Height = 25
    Caption = 'Button1'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 87
    Top = 160
    Width = 48
    Height = 25
    Caption = 'Button2'
    TabOrder = 6
    OnClick = Button2Click
  end
  object ComboBox3: TComboBox
    Left = 192
    Top = 87
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 7
    Text = #1057#1042#1057
    OnChange = ComboBox3Change
    Items.Strings = (
      #1057#1042#1057
      #1057#1042#1059
      #1057#1054)
  end
  object RadioGroup1: TRadioGroup
    Left = 192
    Top = 24
    Width = 225
    Height = 57
    Caption = 'RadioGroup1'
    Columns = 5
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5')
    TabOrder = 8
    OnClick = RadioGroup1Click
  end
  object Button3: TButton
    Left = 176
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 9
    OnClick = Button3Click
  end
  object ComboBox4: TComboBox
    Left = 192
    Top = 114
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 10
    Text = #1052#1091#1092#1090#1072
    OnChange = ComboBox4Change
    Items.Strings = (
      #1055#1086#1076#1096#1080#1087#1085#1080#1082' '#1082#1072#1095#1077#1085#1080#1103
      #1047#1091#1073#1095#1072#1090#1072#1103' '#1087#1077#1088#1077#1076#1072#1095#1072
      #1056#1077#1084#1077#1085#1085#1072#1103' '#1087#1077#1088#1077#1076#1072#1095#1072
      #1052#1091#1092#1090#1072
      #1042#1072#1083', '#1096#1087#1080#1085#1076#1077#1083#1100
      #1069#1083#1077#1082#1090#1088#1086#1076#1074#1080#1075#1072#1090#1077#1083#1100)
  end
end
