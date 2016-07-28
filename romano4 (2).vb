Sub romano4()
                Dim centenas As Double
                Dim cifra As Double
                Dim decenas As Double
                Dim i As Double
                Dim letra As String
                Dim millar As Double
                Dim num As Double
                Dim numero As Double
                Dim unidades As Double
                num = InputBox("Introduce un numero")
                cifra = num
                Dim letras(3, 10) As String
                letras(1, 1) = ""
                letras(1, 2) = "I"
                letras(1, 3) = "II"
                letras(1, 4) = "III"
                letras(1, 5) = "IV"
                letras(1, 6) = "V"
                letras(1, 7) = "VI"
                letras(1, 8) = "VII"
                letras(1, 9) = "VIII"
                letras(1, 10) = "IX"
                letras(2, 1) = ""
                letras(2, 2) = "X"
                letras(2, 3) = "XX"
                letras(2, 4) = "XXX"
                letras(2, 5) = "XL"
                letras(2, 6) = "L"
                letras(2, 7) = "LX"
                letras(2, 8) = "LXX"
                letras(2, 9) = "LXXX"
                letras(2, 10) = "XC"
                letras(3, 1) = ""
                letras(3, 2) = "C"
                letras(3, 3) = "CC"
                letras(3, 4) = "CCC"
                letras(3, 5) = "CD"
                letras(3, 6) = "D"
                letras(3, 7) = "DC"
                letras(3, 8) = "DCC"
                letras(3, 9) = "DCCC"
                letras(3, 10) = "CM"
                If (num = 0) Then
                        MsgBox ("No puede ser 0")
                Else
                        If (num > 3500) Then
                                MsgBox ("No puede ser mayor a 3500")
                        Else
                                If (num < 0) Then
                                        MsgBox ("No puede ser negativo")
                                Else
                                        millar = Fix(num / 1000) Mod 10
                                        centenas = Fix(num / 100) Mod 10
                                        decenas = Fix(num / 10) Mod 10
                                        unidades = num Mod 10
                                        MsgBox ("millar " & millar)
                                        MsgBox ("centenas " & centenas)
                                        MsgBox ("decenas " & decenas)
                                        MsgBox ("unidades " & unidades)
                                        ' MILLAR
                                        ' si ((millar=1) y (millar<=2)) entonces
                                        ' letra=letra + "M"
                                        ' Sino
                                        ' si(millar=2 )Entonces
                                        ' letra= letra + "MM"
                                        ' FinSi
                                        ' si (millar=3) Entonces
                                        ' letra = letra + "MMM"
                                        ' FinSi
                                        ' FinSi
                                        '
                                        ' //CENTENAS D, C
                                        ' si ((centenas=4) y (millar<=5)) entonces
                                        ' letra=letra+ "ID"
                                        ' FinSi
                                        If (num / 1) = num Then
                                                ' millar = trunc(numero / 1000)
                                                For i = millar To 1 Step -1
                                                        letra = letra & "M"
                                                        numero = numero - 1000
                                                Next i
                                                ' letra=concatenar(letra,siglas[3,trunc(numero/100)+1])
                                                letra = letra & letras(3, (centenas) + 1)
                                                num = num - (((num / 100)) * 100)
                                                ' letra=concatenar(letra,siglas[2,trunc(numero/10)+1])
                                                letra = letra & letras(2, (decenas) + 1)
                                                num = num - (((numero / 10)) * 10)
                                                ' letra=concatenar(letra,siglas[1,trunc(numero/1)+1])
                                                letra = letra & letras(1, (unidades) + 1)
                                        End If
                                     MsgBox ("El numero romano es " & letra)
                                     Hoja1.Cells(2, 6) = letra
                                End If
                        End If
                End If
        End Sub