object frmTabla: TfrmTabla
  Left = 259
  Top = 140
  Width = 289
  Height = 507
  Caption = 'Answer & Question Table'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object btnCHK: TSpeedButton
    Left = 192
    Top = 128
    Width = 89
    Height = 25
    Hint = 'Checksum|Add a checksum'
    Caption = '&Checksum'
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
      555555555555555555555555555555555555555555FF55555555555559055555
      55555555577FF5555555555599905555555555557777F5555555555599905555
      555555557777FF5555555559999905555555555777777F555555559999990555
      5555557777777FF5555557990599905555555777757777F55555790555599055
      55557775555777FF5555555555599905555555555557777F5555555555559905
      555555555555777FF5555555555559905555555555555777FF55555555555579
      05555555555555777FF5555555555557905555555555555777FF555555555555
      5990555555555555577755555555555555555555555555555555}
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    OnClick = btnCHKClick
  end
  object BitBtn2: TBitBtn
    Left = 192
    Top = 8
    Width = 89
    Height = 25
    TabOrder = 0
    OnClick = BitBtn2Click
    Kind = bkOK
  end
  object gridCMD: TStringGrid
    Left = 8
    Top = 8
    Width = 174
    Height = 441
    Hint = 
      'This table define questions to send for incoming packets(answers' +
      ')'
    BiDiMode = bdLeftToRight
    ColCount = 2
    DefaultColWidth = 75
    FixedCols = 0
    RowCount = 45
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing]
    ParentBiDiMode = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnSelectCell = gridCMDSelectCell
  end
  object BitBtn1: TBitBtn
    Left = 192
    Top = 48
    Width = 89
    Height = 25
    Hint = 'Cleat the whole table|Cleat the whole table'
    Caption = '&Clear Table'
    TabOrder = 2
    OnClick = BitBtn1Click
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00559999999995
      5555557777777775F5555559999999505555555777777757FFF5555555555550
      0955555555555FF7775F55555555995501955555555577557F75555555555555
      01995555555555557F5755555555555501905555555555557F57555555555555
      0F905555555555557FF75555555555500005555555555557777555555555550F
      F05555555555557F57F5555555555008F05555555555F775F755555555570000
      05555555555775577555555555700007555555555F755F775555555570000755
      55555555775F77555555555700075555555555F75F7755555555570007555555
      5555577F77555555555500075555555555557777555555555555}
    NumGlyphs = 2
  end
  object chkOnTop: TCheckBox
    Left = 192
    Top = 168
    Width = 73
    Height = 17
    Caption = 'On Top'
    TabOrder = 3
    OnClick = chkOnTopClick
  end
  object BitBtn3: TBitBtn
    Left = 193
    Top = 88
    Width = 88
    Height = 25
    Hint = 'Cleat the whole table|Cleat the whole table'
    Caption = '&Clear Buffer'
    TabOrder = 4
    OnClick = BitBtn3Click
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00559999999995
      5555557777777775F5555559999999505555555777777757FFF5555555555550
      0955555555555FF7775F55555555995501955555555577557F75555555555555
      01995555555555557F5755555555555501905555555555557F57555555555555
      0F905555555555557FF75555555555500005555555555557777555555555550F
      F05555555555557F57F5555555555008F05555555555F775F755555555570000
      05555555555775577555555555700007555555555F755F775555555570000755
      55555555775F77555555555700075555555555F75F7755555555570007555555
      5555577F77555555555500075555555555557777555555555555}
    NumGlyphs = 2
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 461
    Width = 281
    Height = 19
    Panels = <>
    SimplePanel = True
  end
end
