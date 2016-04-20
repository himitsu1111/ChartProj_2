object Form3: TForm3
  Left = 0
  Top = 0
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1073#1098#1077#1082#1090#1072' '#1076#1080#1072#1075#1085#1086#1089#1090#1080#1082#1080
  ClientHeight = 471
  ClientWidth = 925
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 183
    Top = 8
    Width = 314
    Height = 459
    TabOrder = 0
    object GroupBox2: TGroupBox
      Left = 16
      Top = 71
      Width = 289
      Height = 122
      Caption = #1054#1087#1080#1089#1072#1085#1080#1077' '#1086#1073#1098#1077#1082#1090#1072
      TabOrder = 0
      object StaticText2: TStaticText
        Left = 16
        Top = 24
        Width = 178
        Height = 17
        Caption = #1058#1080#1087' '#1086#1073#1098#1077#1082#1090#1072'('#1087#1086#1076#1096#1080#1087#1085#1080#1082' '#1082#1072#1095#1077#1085#1080#1103')'
        TabOrder = 0
      end
      object StaticText3: TStaticText
        Left = 16
        Top = 56
        Width = 265
        Height = 17
        Caption = #1055#1088#1086#1094#1077#1089#1089' '#1086#1073#1088#1072#1073#1086#1090#1082#1080' ('#1085#1072#1088#1091#1096#1077#1085#1080#1077' '#1088#1077#1078#1080#1084#1086#1074' '#1080#1080#1083' '#1091#1076#1072#1088')'
        TabOrder = 1
      end
      object StaticText5: TStaticText
        Left = 16
        Top = 89
        Width = 135
        Height = 17
        Caption = #1054#1073#1097#1080#1081' '#1091#1088#1086#1074#1077#1085#1100' '#1074#1080#1073#1088#1072#1094#1080#1080
        TabOrder = 2
      end
    end
    object GroupBox3: TGroupBox
      Left = 16
      Top = 9
      Width = 289
      Height = 56
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      TabOrder = 1
      object StaticText1: TStaticText
        Left = 16
        Top = 24
        Width = 159
        Height = 17
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' (B7016C, '#1074#1072#1083' 3)'
        TabOrder = 0
      end
    end
    object GroupBox4: TGroupBox
      Left = 16
      Top = 199
      Width = 289
      Height = 59
      Caption = #1057#1087#1077#1082#1090#1088
      TabOrder = 2
      object StaticText4: TStaticText
        Left = 16
        Top = 24
        Width = 67
        Height = 17
        Caption = #1057#1042#1057'\'#1057#1042#1059'\'#1057#1054
        TabOrder = 0
      end
    end
    object GroupBox5: TGroupBox
      Left = 16
      Top = 264
      Width = 289
      Height = 65
      Caption = #1044#1086#1087#1091#1089#1090#1080#1084#1099#1077' '#1091#1088#1086#1074#1085#1080
      TabOrder = 3
      object StaticText6: TStaticText
        Left = 16
        Top = 32
        Width = 20
        Height = 17
        Caption = '0.1'
        TabOrder = 0
      end
      object StaticText7: TStaticText
        Left = 160
        Top = 32
        Width = 20
        Height = 17
        Caption = '0.1'
        TabOrder = 1
      end
    end
    object GroupBox6: TGroupBox
      Left = 16
      Top = 335
      Width = 289
      Height = 58
      Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1095#1077#1089#1082#1080#1077' '#1087#1088#1080#1079#1085#1072#1082#1080
      TabOrder = 4
      object StaticText8: TStaticText
        Left = 16
        Top = 32
        Width = 25
        Height = 17
        Caption = 'fx ='
        TabOrder = 0
      end
      object StaticText9: TStaticText
        Left = 112
        Top = 32
        Width = 25
        Height = 17
        Caption = 'fx ='
        TabOrder = 1
      end
      object StaticText10: TStaticText
        Left = 208
        Top = 32
        Width = 25
        Height = 17
        Caption = 'fx ='
        TabOrder = 2
      end
    end
  end
  object TreeView1: TTreeView
    Left = 0
    Top = 8
    Width = 177
    Height = 417
    Indent = 19
    TabOrder = 1
    OnMouseDown = TreeView1MouseDown
  end
  object Button1: TButton
    Left = 8
    Top = 438
    Width = 75
    Height = 25
    Caption = #1054#1073#1085#1086#1074#1080#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object Chart1: TChart
    Left = 503
    Top = 8
    Width = 414
    Height = 455
    OnBeforeDrawAxes = Chart1BeforeDrawAxes
    TabOrder = 3
    object Series1: TLineSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.Visible = False
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object Button2: TButton
    Left = 95
    Top = 438
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 4
    OnClick = Button2Click
  end
end
