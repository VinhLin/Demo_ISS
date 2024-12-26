object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 674
  ClientWidth = 763
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object TMSFNCMaps1: TTMSFNCMaps
    Left = 0
    Top = 136
    Width = 763
    Height = 538
    Align = alBottom
    ParentDoubleBuffered = False
    DoubleBuffered = True
    TabOrder = 0
    Polylines = <>
    Polygons = <>
    Circles = <>
    Rectangles = <>
    Markers = <>
    ElementContainers = <>
    Labels = <>
    HeadLinks = <>
    Options.DefaultLatitude = 40.689247000000000000
    Options.DefaultLongitude = -74.044501999999990000
    Options.DefaultZoomLevel = 12.000000000000000000
    Service = msOpenLayers
  end
  object FindISSButton: TButton
    Left = 24
    Top = 24
    Width = 145
    Height = 41
    Caption = 'FindISSButton'
    TabOrder = 1
    OnClick = FindISSButtonClick
  end
  object ListBox1: TListBox
    Left = 248
    Top = 8
    Width = 241
    Height = 73
    ItemHeight = 15
    TabOrder = 2
  end
  object RESTClient1: TRESTClient
    Accept = 'application/json, text/plain; q=0.9, text/html;q=0.8,'
    AcceptCharset = 'utf-8, *;q=0.8'
    BaseURL = 'http://api.open-notify.org/iss-now.json'
    Params = <>
    SynchronizedEvents = False
    Left = 24
    Top = 80
  end
  object RESTRequest1: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient1
    Params = <>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 104
    Top = 80
  end
  object RESTResponse1: TRESTResponse
    ContentType = 'application/json'
    Left = 192
    Top = 80
  end
end
