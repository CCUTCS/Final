srand(4)

for cnt in 1:5
    inputio = open("input$cnt", "w")
    outputio = open("output$cnt", "w")

    numbers = rand(0:1005, rand(50:100))

    for i in numbers
        println(inputio, i)
    end
    numbers = sort(numbers, rev=true)

    for i in 1:5
        println(outputio, numbers[i])
    end

    close(inputio)
    close(outputio)
end