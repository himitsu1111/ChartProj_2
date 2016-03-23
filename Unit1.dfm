object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 502
  ClientWidth = 780
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object ComboBox1: TComboBox
    Left = 176
    Top = 24
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    OnChange = ComboBox1Change
  end
  object ListBox1: TListBox
    Left = 176
    Top = 115
    Width = 145
    Height = 25
    ItemHeight = 13
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 574
    Top = 8
    Width = 198
    Height = 473
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object ComboBox2: TComboBox
    Left = 176
    Top = 64
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 3
    OnChange = ComboBox2Change
  end
  object Button1: TButton
    Left = 176
    Top = 160
    Width = 57
    Height = 25
    Caption = 'Button1'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 377
    Top = 160
    Width = 48
    Height = 25
    Caption = 'Button2'
    TabOrder = 5
  end
  object ComboBox3: TComboBox
    Left = 344
    Top = 87
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 6
    Text = #1057#1042#1057
    OnChange = ComboBox3Change
    Items.Strings = (
      #1057#1042#1057
      #1057#1042#1059
      #1057#1054)
  end
  object RadioGroup1: TRadioGroup
    Left = 344
    Top = 8
    Width = 225
    Height = 57
    Caption = #1050#1072#1085#1072#1083
    Columns = 5
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5')
    TabOrder = 7
    OnClick = RadioGroup1Click
  end
  object Button3: TButton
    Left = 280
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 8
    OnClick = Button3Click
  end
  object ComboBox4: TComboBox
    Left = 344
    Top = 114
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 9
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
  object GroupBox1: TGroupBox
    Left = 176
    Top = 207
    Width = 179
    Height = 202
    Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1095#1077#1089#1082#1080#1077' '#1087#1088#1080#1079#1085#1072#1082#1080'  ('#1043#1094')'
    TabOrder = 10
    object Edit1: TEdit
      Left = 64
      Top = 40
      Width = 97
      Height = 21
      TabOrder = 0
      OnKeyPress = Edit1KeyPress
    end
    object Edit2: TEdit
      Left = 64
      Top = 88
      Width = 97
      Height = 21
      TabOrder = 1
      OnKeyPress = Edit2KeyPress
    end
    object Edit3: TEdit
      Left = 64
      Top = 136
      Width = 97
      Height = 21
      TabOrder = 2
      OnKeyPress = Edit3KeyPress
    end
    object StaticText1: TStaticText
      Left = 15
      Top = 40
      Width = 31
      Height = 17
      Caption = 'fx1 ='
      TabOrder = 3
    end
    object StaticText2: TStaticText
      Left = 15
      Top = 88
      Width = 31
      Height = 17
      Caption = 'fx2 ='
      TabOrder = 4
    end
    object StaticText3: TStaticText
      Left = 15
      Top = 136
      Width = 31
      Height = 17
      Caption = 'fx3 ='
      TabOrder = 5
    end
  end
  object GroupBox2: TGroupBox
    Left = 361
    Top = 207
    Width = 176
    Height = 202
    Caption = #1044#1086#1087#1091#1089#1090#1080#1084#1099#1077' '#1091#1088#1086#1074#1085#1080
    TabOrder = 11
    object Edit4: TEdit
      Left = 106
      Top = 40
      Width = 55
      Height = 21
      TabOrder = 0
    end
    object Edit5: TEdit
      Left = 106
      Top = 88
      Width = 55
      Height = 21
      TabOrder = 1
    end
    object StaticText4: TStaticText
      Left = 7
      Top = 40
      Width = 93
      Height = 17
      Caption = #1055#1088#1077#1076#1091#1087#1088#1077#1078#1076#1077#1085#1080#1077
      TabOrder = 2
    end
    object StaticText5: TStaticText
      Left = 7
      Top = 88
      Width = 41
      Height = 17
      Caption = #1040#1074#1072#1088#1080#1103
      TabOrder = 3
    end
  end
end
