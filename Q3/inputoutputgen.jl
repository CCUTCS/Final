srand(3)

for cnt in 1:5

    inputio = open("input$cnt", "w")
    outputio = open("output$cnt", "w")
    
    ops = rand(1:4, 50)
    numbers = rand(0:1005, 50, 2)
    for i in 1 : 50
        ans = 0
        op = ' '
        x = numbers[i,1]
        y = numbers[i, 2]
        if ops[i] == 1
            op = '+'
            ans = x + y
        end
        if ops[i] == 2
            op = '-'
            ans = x - y
        end
        if ops[i] == 3
            op = '*'
            ans = trunc(Int, x * y)
        end
        if ops[i] == 4
            op = '/'
            ans = trunc(Int, x / y)
        end
        println(inputio, "$op $x $y")
        println(outputio, ans)
    end
    close(inputio)
    close(outputio)
end
