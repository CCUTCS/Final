srand(10)

input_number = rand(0 : 10007, 100, 2)

#println(input_number)

#print(typeof(input_number))
for cnt in 1:5
    inputio = open("input$cnt", "w")
    outputio = open("output$cnt", "w")
    for i in 1:20
        x = input_number[muladd(20, cnt - 1, i), 1]
        y = input_number[muladd(20, cnt - 1, i), 2]

        #input
        println(inputio, x, ' ', y)

        #output
        println(outputio, "$(x + y)")
        println(outputio, "$(x - y)")
        println(outputio, "$(x ^ 2 - y ^ 2)")
        

    end
    close(inputio)
    close(outputio)
end
