Sub ConversorSueldo()

Dim billetes500 As Integer
Dim billetes200 As Integer
Dim billetes100 As Integer
Dim billetes50 As Integer
Dim billetes20 As Integer
Dim billetes10 As Integer
Dim billetes5 As Integer
Dim res As Integer
Dim sueldo As Integer
Dim monedas As Integer
Dim monedas2 As Integer
Dim max As Integer
billetes500 = 0
billetes200 = 0
billetes100 = 0
billetes50 = 0
billetes20 = 0
billetes10 = 0
billetes5 = 0
monedas = 0
monedas2 = 0

sueldo = 1248
max = 200

        If (max = 500) Then
' Dividimos por 500
        billetes500 = Fix(sueldo / 500)
        'calculo el resto
        sueldo = sueldo - (500 * billetes500)
        MsgBox ("el numero de billetes de 500€: " & billetes500)
        MsgBox ("el resto: " & sueldo)
        max = 200
        End If
        If (max = 200) Then
        ' Dividimos por 200
        billetes200 = Fix(sueldo / 200)
         'calculo el resto
        sueldo = sueldo - (200 * billetes200)
        MsgBox ("el numero de billetes de 200€: " & billetes200)
        MsgBox ("el resto: " & sueldo)
        max = 100
        End If
        If (max = 100) Then
         ' Dividimos por 100
        billetes100 = Fix(sueldo / 100)
         'calculo el resto
        sueldo = sueldo - (100 * billetes100)
        MsgBox ("el numero de billetes de 100€: " & billetes100)
        MsgBox ("el resto: " & sueldo)
        max = 50
        End If
        If (max = 50) Then
         ' Dividimos por 50
        billetes50 = Fix(sueldo / 50)
         'calculo el resto
        sueldo = sueldo - (50 * billetes50)
        MsgBox ("el numero de billetes de 50€: " & billetes50)
        MsgBox ("el resto: " & sueldo)
        max = 20
        End If
         ' Dividimos por 20
            If (max = 20) Then
        billetes20 = Fix(sueldo / 20)
         'calculo el resto
        sueldo = sueldo - (20 * billetes20)
        MsgBox ("el numero de billetes de 20€: " & billetes20)
        MsgBox ("el resto: " & sueldo)
        max = 10
        End If
         If (max = 10) Then
          ' Dividimos por 10
        billetes10 = Fix(sueldo / 10)
         'calculo el resto
        sueldo = sueldo - (10 * billetes10)
        MsgBox ("el numero de billetes de 10€: " & billetes10)
        MsgBox ("el resto: " & sueldo)
        max = 5
        End If
        If (max = 5) Then
          ' Dividimos por 5
        billetes5 = Fix(sueldo / 5)
         'calculo el resto
        sueldo = sueldo - (5 * billetes5)
        MsgBox ("el numero de billetes de 5€: " & billetes5)
        MsgBox ("el resto: " & sueldo)
        max = 2
        End If
         If (max = 2) Then
          ' Dividimos por 5
        monedas2 = Fix(sueldo / 2)
         'calculo el resto
        sueldo = sueldo - (2 * monedas2)
        MsgBox ("el numero de monedas de 2€: " & monedas2)
        MsgBox ("el resto: " & sueldo)
        End If
        
        ' el resto ya serian monedas de 1 euro
        monedas = sueldo
        MsgBox ("el numero de monedas de 1 €: " & monedas)
End Sub
