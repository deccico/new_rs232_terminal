object frmSetup: TfrmSetup
  Left = 221
  Top = 214
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Serial connection'
  ClientHeight = 118
  ClientWidth = 533
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox2: TGroupBox
    Left = 8
    Top = 4
    Width = 513
    Height = 105
    Caption = 'Connection'
    TabOrder = 0
    object Shape1: TShape
      Left = 32
      Top = 75
      Width = 433
      Height = 6
    end
    object Label5: TLabel
      Left = 146
      Top = 24
      Width = 19
      Height = 13
      Caption = 'Port'
    end
    object Label6: TLabel
      Left = 216
      Top = 24
      Width = 56
      Height = 13
      Caption = 'Baud Rates'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 290
      Top = 24
      Width = 43
      Height = 13
      Caption = 'Data Bits'
    end
    object Label13: TLabel
      Left = 354
      Top = 24
      Width = 26
      Height = 13
      Caption = 'Parity'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 426
      Top = 24
      Width = 39
      Height = 13
      Caption = 'StopBits'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cmbPort: TComboBox
      Left = 144
      Top = 40
      Width = 57
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 0
      Items.Strings = (
        'Com1'
        'Com2'
        'Com3'
        'Com4'
        'Com5'
        'Com6'
        'Com7'
        'Com8'
        'Com9'
        'Com10'
        'Com11'
        'Com12'
        'Com13'
        'Com14'
        'Com15'
        'Com16'
        'Com17'
        'Com18'
        'Com19'
        'Com20')
    end
    object cmbBaudios: TComboBox
      Left = 216
      Top = 40
      Width = 58
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 1
      Items.Strings = (
        '110'
        '300'
        '600'
        '1200'
        '2400'
        '4800'
        '9600'
        '19200 '
        '38400'
        '57600'
        '115200'
        '230400'
        '460800'
        '921600')
    end
    object cmbData: TComboBox
      Left = 290
      Top = 40
      Width = 45
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 2
      Items.Strings = (
        '5'
        '6'
        '7'
        '8')
    end
    object cmbParidad: TComboBox
      Left = 354
      Top = 40
      Width = 55
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 3
      Items.Strings = (
        'None'
        'Odd'
        'Even'
        'Mark'
        'Space')
    end
    object cmbStop: TComboBox
      Left = 426
      Top = 40
      Width = 55
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 4
      Items.Strings = (
        '1'
        '1.5'
        '2')
    end
  end
  object BitBtn1: TBitBtn
    Left = 32
    Top = 33
    Width = 105
    Height = 33
    Caption = '&Connect'
    TabOrder = 1
    OnClick = BitBtn1Click
    Kind = bkOK
  end
end
