Module Module1

    Sub main()
        Dim sueldo, x, sEnt, sDec As String
        Dim nEnt, nDec As Integer
        Dim valido As Boolean
        Dim i, j, k, posicion As Integer
        valido = False
        i = 1
        j = 1
        sueldo = ""
        sDec = ""
        sEnt = ""

        Do Until valido = True

            Console.WriteLine("Escribe un sueldo: ")
            sueldo = Console.ReadLine()
            Console.WriteLine("El sueldo introducido fue: " & sueldo)



            posicion = Len(sueldo) + 1
            valido = True

            'si el sueldo introducido es vacio vuelve a pedir
            If sueldo = "" Then
                valido = False
            End If

            'Validamos el sueldo: todo numeros y no mas de 2 decimales
            Do While (i <= Len(sueldo) And valido = True)

                x = Mid(sueldo, i, 1)

                If IsNumeric(x) = True Or x = "," Or x = "." Then
                    'Console.WriteLine(x & " Es valido.")
                    valido = True
                    If x = "," Or x = "." Then
                        posicion = i
                    End If

                    If i > (posicion + 2) Then
                        valido = False
                    End If

                Else
                    'Console.WriteLine(x & " No es valido.")
                    valido = False
                End If

                i = i + 1
            Loop

            If valido = True Then
                'Console.WriteLine("Sueldo Valido")
                'Console.WriteLine()

            ElseIf valido = False Then
                'Console.WriteLine("Sueldo invalido vuelve a introducir el sueldo.")
                'Console.WriteLine()
            End If

        Loop

        'parte entera

        Do While j < posicion
            sEnt = sEnt & Mid(sueldo, j, 1)
            j = j + 1
        Loop

        'parte decimal

        k = posicion + 1

        If sDec = "" And posicion = Len(sueldo) + 1 Then
            sDec = "00"
        End If

        Do While k <= (posicion + 2)

            If Mid(sueldo, k, 1) = "" Then
                sDec = sDec & "0"
            End If
            sDec = sDec & Mid(sueldo, k, 1)
            k = k + 1
        Loop

        'Console.WriteLine("La parte entera es: " & sEnt)
        'Console.WriteLine("La parte decimal es: " & sDec)

        'convertimos las partes del sueldo a numeros enteros
        nEnt = Int(sEnt)
        nDec = Int(sDec)

        'Console.ReadLine()

    End Sub
End Module
