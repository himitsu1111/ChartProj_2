object Form1: TForm1
  Left = 123
  Top = 43
  BorderStyle = bsSingle
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1073#1098#1077#1082#1090#1072' '#1076#1080#1072#1075#1085#1086#1089#1090#1080#1082#1080
  ClientHeight = 416
  ClientWidth = 418
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox1: TListBox
    Left = 176
    Top = 123
    Width = 145
    Height = 25
    ItemHeight = 13
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 494
    Top = 8
    Width = 198
    Height = 473
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object GroupBox3: TGroupBox
    Left = -1
    Top = -1
    Width = 417
    Height = 416
    TabOrder = 2
    object ComboBox1: TComboBox
      Left = 17
      Top = 115
      Width = 192
      Height = 21
      ItemHeight = 13
      TabOrder = 0
      OnChange = ComboBox1Change
    end
    object ComboBox2: TComboBox
      Left = 17
      Top = 163
      Width = 192
      Height = 21
      ItemHeight = 13
      TabOrder = 1
      OnChange = ComboBox2Change
    end
    object Button1: TButton
      Left = 17
      Top = 372
      Width = 57
      Height = 25
      Caption = #1044#1077#1088#1077#1074#1086
      TabOrder = 2
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 298
      Top = 372
      Width = 104
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1088#1072#1089#1095#1077#1090
      TabOrder = 3
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 134
      Top = 324
      Width = 75
      Height = 28
      Caption = #1056#1072#1089#1095#1077#1090
      TabOrder = 4
      OnClick = Button3Click
    end
    object RadioGroup1: TRadioGroup
      Left = 17
      Top = 189
      Width = 192
      Height = 57
      Caption = #1050#1072#1085#1072#1083
      Columns = 5
      Items.Strings = (
        '1'
        '2'
        '3'
        '4'
        '5')
      TabOrder = 5
      OnClick = RadioGroup1Click
    end
    object ComboBox3: TComboBox
      Left = 64
      Top = 260
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
    object ComboBox4: TComboBox
      Left = 64
      Top = 287
      Width = 145
      Height = 21
      ItemHeight = 13
      TabOrder = 7
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
      Left = 223
      Top = 14
      Width = 179
      Height = 202
      Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1095#1077#1089#1082#1080#1077' '#1087#1088#1080#1079#1085#1072#1082#1080'  ('#1043#1094')'
      TabOrder = 8
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
      Left = 226
      Top = 236
      Width = 176
      Height = 125
      Caption = #1044#1086#1087#1091#1089#1090#1080#1084#1099#1077' '#1091#1088#1086#1074#1085#1080
      TabOrder = 9
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
    object StaticText6: TStaticText
      Left = 17
      Top = 90
      Width = 43
      Height = 17
      Caption = #1052#1086#1076#1077#1083#1100
      TabOrder = 10
    end
    object StaticText7: TStaticText
      Left = 17
      Top = 141
      Width = 73
      Height = 17
      Caption = #1048#1085#1074#1077#1085#1090#1072#1088#1085#1099#1081
      TabOrder = 11
    end
    object StaticText8: TStaticText
      Left = 17
      Top = 264
      Width = 41
      Height = 17
      Caption = #1057#1087#1077#1082#1090#1088
      TabOrder = 12
    end
    object StaticText9: TStaticText
      Left = 17
      Top = 289
      Width = 42
      Height = 17
      Caption = #1044#1077#1090#1072#1083#1100
      TabOrder = 13
    end
    object GroupBox4: TGroupBox
      Left = 82
      Top = 362
      Width = 211
      Height = 40
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1079#1072#1084#1077#1088#1072
      TabOrder = 14
      object Edit6: TEdit
        Left = 4
        Top = 13
        Width = 203
        Height = 21
        TabOrder = 0
      end
    end
    object ComboBox5: TComboBox
      Left = 17
      Top = 63
      Width = 192
      Height = 21
      ItemHeight = 13
      TabOrder = 15
      OnChange = ComboBox5Change
    end
    object StaticText10: TStaticText
      Left = 17
      Top = 40
      Width = 24
      Height = 17
      Caption = #1062#1077#1093
      TabOrder = 16
    end
    object StaticText11: TStaticText
      Left = 17
      Top = 14
      Width = 65
      Height = 17
      Caption = 'StaticText11'
      TabOrder = 17
      OnClick = StaticText11Click
    end
  end
  object ExcelApplication1: TExcelApplication
    AutoConnect = False
    ConnectKind = ckRunningOrNew
    Left = 48
    Top = 424
  end
  object SaveDialog1: TSaveDialog
    FileName = '1'
    Filter = 'Only 1'
    InitialDir = 'C:\'
    Left = 128
    Top = 424
  end
end
